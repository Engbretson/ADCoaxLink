/* Copyright Euresys 2015 */

#ifndef RGBCONVERTERIMPL_HEADER_FILE
#define RGBCONVERTERIMPL_HEADER_FILE

#include <deque>
#include <stdexcept>
#include <assert.h>
#include "internal/EuresysLocks.h"

#define RGBConverterImpl_EXPOSE(C) \
class C { \
public: \
    C(RGBConverterT& conv, uint8_t* imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize = 0) \
    : conv(conv), buffer(conv.impl.to##C(imgPtr, fmt, w, h, imgSize)) {} \
    C(RGBConverterT& conv, uint8_t* imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize = 0) \
    : conv(conv), buffer(conv.impl.to##C(imgPtr, conv.getGenTL().imageGetPixelFormat(fmt), w, h, imgSize)) {} \
    uint8_t* getBuffer() const { return buffer.getBuffer(); } \
    void saveToDisk(const std::string &filepath, int64_t index = -1, const GenICam::Client::Euresys::ImageSaveToDiskParams *params = 0) { \
        buffer.saveToDisk(conv.getGenTL(), filepath, index, params); \
    } \
private: \
    RGBConverterT& conv; \
    typename RGBConverterTImpl<BP>::PrivBuffer buffer; \
    C(const C &); \
    C &operator=(const C &); \
protected: \
    static void *operator new(size_t); \
    static void *operator new[](size_t); \
}; \
friend class C;

#define RGBConverterImpl_ALLOW_EXPOSE(C) \
friend class RGBConverterT<BP>::C;

namespace EURESYS_NAMESPACE {
namespace Internal {

class BufferPool {
public:
    BufferPool() {}
    ~BufferPool()
    {
        trimBuffers();
    }
    uint8_t *popBuffer(const size_t bufferSize)
    {
        AutoLock lock(mutex);
        std::deque<uint8_t *> &buffers(bufferMap[bufferSize]);
        if (!buffers.empty())
        {
            uint8_t *b = buffers.front();
            buffers.pop_front();
            return b;
        }
        return alloc(bufferSize);
    }
    void pushBuffer(uint8_t *buffer, const size_t bufferSize)
    {
        AutoLock lock(mutex);
        bufferMap[bufferSize].push_front(buffer);
    }
    void prepareBuffers(size_t bufferSize, size_t count)
    {
        for(size_t c = 0; c < count; ++c)
        {
            pushBuffer(alloc(bufferSize), bufferSize);
        }
    }
    void trimBuffers()
    {
        AutoLock lock(mutex);
        for (std::map<size_t, std::deque<uint8_t *> >::iterator it = bufferMap.begin(); it != bufferMap.end(); ++it)
        {
            std::deque<uint8_t *> buffers(it->second);
            trash(buffers);
        }
        bufferMap.clear();
    }
private:
    uint8_t * alloc(size_t bufferSize)
    {
        return new uint8_t[bufferSize];
    }
    static void trash(std::deque<uint8_t *> &buffers)
    {
        while (!buffers.empty())
        {
            uint8_t *b = buffers.front();
            buffers.pop_front();
            delete [] b;
        }
    }
    ConcurrencyLock mutex;
    std::map<size_t, std::deque<uint8_t *> > bufferMap;

    BufferPool(const BufferPool &);
    BufferPool &operator=(const BufferPool &);
};

// Forward declaration for the friend specifier allowing noAutoRelease() calls
template<typename BP> class RGBConverterT;

template <typename BP>
class RGBConverterTImpl {

public:
    struct BufferInfo {
        BP *pool;
        uint8_t* buffer;
        size_t bufferSize;
        std::string format;
        size_t width;
        size_t height;
        BufferInfo(uint8_t* imgPtr, const std::string &fmt, size_t w, size_t h, size_t bufferSize)
            : pool(0), buffer(imgPtr), bufferSize(bufferSize), format(fmt), width(w), height(h) {}
        BufferInfo(BP *pool, const std::string &fmt, size_t w, size_t h, size_t bufferSize)
            : pool(pool), buffer(pool->popBuffer(bufferSize)), bufferSize(bufferSize), format(fmt), width(w), height(h) {}
        BufferInfo()
            : pool(0), buffer(0), bufferSize(0), format(""), width(0), height(0) {}
    };

    class PrivBuffer {
    public:
        virtual ~PrivBuffer() { if (autoRelease) { releaseBuffer(); } }
    private:
        PrivBuffer(uint8_t* imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize)
            : autoRelease(false), info(imgPtr, fmt, w, h, imgSize) {}
        PrivBuffer(BP *pool, const std::string &fmt, size_t w, size_t h, size_t bufferSize)
            : autoRelease(true), info(pool, fmt, w, h, bufferSize) {}
        PrivBuffer(const PrivBuffer &p) : autoRelease(true), info(p.info) { assert(!p.autoRelease); }
        virtual void releaseBuffer() { if (info.pool) { info.pool->pushBuffer(info.buffer, info.bufferSize); } }
        uint8_t* getBuffer() const { return info.buffer; }
        size_t getBufferSize() const { return info.bufferSize; }
        void saveToDisk(EURESYS_NAMESPACE::GenTL &genTL, const std::string &filepath, int64_t index, const GenICam::Client::Euresys::ImageSaveToDiskParams *params) {
            GenICam::Client::Euresys::ImageConvertInput input = { (int)info.width,
                                                                  (int)info.height,
                                                                  info.buffer,
                                                                  info.format.c_str(),
                                                                  {((info.bufferSize) ? &info.bufferSize : 0), 0, 0, 0},
                                                                  {0, 0, 0, 0} };
            genTL.imageSaveToDisk(input, filepath, index, params);
        }
        PrivBuffer& noAutoRelease() { autoRelease = false; return *this; }
        bool autoRelease;
        BufferInfo info;
        // Allow PrivBuffer instance management to the following friend classes
        friend class RGBConverterTImpl;
        RGBConverterImpl_ALLOW_EXPOSE(BGR8);
        RGBConverterImpl_ALLOW_EXPOSE(RGB8);
        PrivBuffer &operator=(const PrivBuffer &);
    protected:
        static void *operator new(size_t);
        static void *operator new[](size_t);
    };

    RGBConverterTImpl(EURESYS_NAMESPACE::GenTL &genTL)
    : genTL(genTL) {}
    ~RGBConverterTImpl() {}
    void prepareBuffers(size_t bufferSize, size_t count)
    {
        imageBufferPool.prepareBuffers(bufferSize, count);
    }
    void trimBuffers()
    {
        imageBufferPool.trimBuffers();
    }
    PrivBuffer toRGB8(uint8_t* imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize)
    {
        return imageTo("RGB8", imageTo8Bit(PrivBuffer(imgPtr, fmt, w, h, imgSize).noAutoRelease()).noAutoRelease()).noAutoRelease();
    }
    PrivBuffer toBGR8(uint8_t* imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize)
    {
        return imageTo("BGR8", imageTo8Bit(PrivBuffer(imgPtr, fmt, w, h, imgSize).noAutoRelease()).noAutoRelease()).noAutoRelease();
    }
    PrivBuffer toInplace1x2yeReordering(uint8_t* imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize)
    {
        return imageInplace1X2YE(PrivBuffer(imgPtr, fmt, w, h, imgSize).noAutoRelease()).noAutoRelease();
    }
    EURESYS_NAMESPACE::GenTL &getGenTL()
    {
        return genTL;
    }

private:
    PrivBuffer imageTo8Bit(PrivBuffer &apBuf)
    {
        PrivBuffer pBuf(apBuf.noAutoRelease());
        std::string format8 = get8BitFormat(pBuf.info.format);
        bool isBayer = pBuf.info.format.find("Bayer") == 0;
        bool needs8bitConvert = isBayer && pBuf.info.format != format8;
        if (!needs8bitConvert)
        {
            return pBuf.noAutoRelease();
        }
        const size_t bufferSize = static_cast<size_t>(pBuf.info.width * pBuf.info.height);
        PrivBuffer pBufConv(&imageBufferPool, format8, pBuf.info.width, pBuf.info.height, bufferSize);
        size_t pBufSize = pBuf.getBufferSize();
        GenICam::Client::Euresys::ImageConvertInput input =
            { (int)pBuf.info.width, (int)pBuf.info.height, pBuf.getBuffer(), pBuf.info.format.c_str(),
              {((pBufSize) ? &pBufSize : 0), 0, 0, 0},
              {0, 0, 0, 0} };
        GenICam::Client::Euresys::ImageConvertOutput output =
            { (int)pBuf.info.width, (int)pBuf.info.height, pBufConv.getBuffer(), format8.c_str(),
              GenICam::Client::Euresys::IMAGE_CONVERT_OUTPUT_CONFIG_DEFAULT,
              GenICam::Client::Euresys::IMAGE_CONVERT_OUTPUT_OPERATION_COPY,
              {0, 0, 0, 0} };
        genTL.imageConvert(input, output, NULL);
        return pBufConv.noAutoRelease();
    }

    PrivBuffer imageTo(const std::string &fmt, PrivBuffer &apBuf)
    {
        PrivBuffer pBuf(apBuf.noAutoRelease());
        std::string format8 = get8BitFormat(pBuf.info.format);
        bool isBayer = pBuf.info.format.find("Bayer") == 0;
        bool needs8bitConvert = isBayer && pBuf.info.format != format8;
        std::string inputFormat = needs8bitConvert ? format8 : pBuf.info.format;
        if (inputFormat == fmt)
        {
            return pBuf.noAutoRelease();
        }
        const size_t bufferSize = static_cast<size_t>(pBuf.info.width * pBuf.info.height * 3);
        PrivBuffer pBufConv(&imageBufferPool, fmt, pBuf.info.width, pBuf.info.height, bufferSize);
        size_t pBufSize = pBuf.getBufferSize();
        GenICam::Client::Euresys::ImageConvertInput input =
            { (int)pBuf.info.width, (int)pBuf.info.height, pBuf.getBuffer(), inputFormat.c_str(),
              {((pBufSize) ? &pBufSize : 0), 0, 0, 0},
              {0, 0, 0, 0} };
        GenICam::Client::Euresys::ImageConvertOutput output =
            { (int)pBuf.info.width, (int)pBuf.info.height, pBufConv.getBuffer(), fmt.c_str(),
              GenICam::Client::Euresys::IMAGE_CONVERT_OUTPUT_CONFIG_DEFAULT,
              GenICam::Client::Euresys::IMAGE_CONVERT_OUTPUT_OPERATION_COPY,
              {0, 0, 0, 0} };
        genTL.imageConvert(input, output, NULL);
        return pBufConv.noAutoRelease();
    }

    PrivBuffer imageInplace1X2YE(PrivBuffer &apBuf)
    {
        PrivBuffer pBuf(apBuf.noAutoRelease());
        size_t pBufSize = pBuf.getBufferSize();
        GenICam::Client::Euresys::ImageConvertInput input =
            { (int)pBuf.info.width, (int)pBuf.info.height, pBuf.getBuffer(), pBuf.info.format.c_str(),
              {((pBufSize) ? &pBufSize : 0), 0, 0, 0},
              {0, 0, 0, 0} };
        GenICam::Client::Euresys::ImageConvertOutput output =
            { (int)pBuf.info.width, (int)pBuf.info.height, pBuf.getBuffer(), pBuf.info.format.c_str(),
              GenICam::Client::Euresys::IMAGE_CONVERT_OUTPUT_CONFIG_DEFAULT,
              GenICam::Client::Euresys::IMAGE_CONVERT_OUTPUT_OPERATION_1X2YE,
              {0, 0, 0, 0} };
        genTL.imageConvert(input, output, NULL);
        return pBuf.noAutoRelease();
    }

    static std::string get8BitFormat(const std::string& format)
    {
        size_t bitsPos = format.find_first_of("0123456789");
        if (bitsPos != std::string::npos)
        {
            std::string name(format, 0, bitsPos);
            size_t endBitsPos = format.find_first_not_of("0123456789", bitsPos);
            std::string rest;
            if (endBitsPos != std::string::npos)
            {
                rest = std::string(format, endBitsPos);
            }
            std::string format8 = name + std::string("8") + rest;
            return format8;
        }
        throw std::runtime_error(format.c_str());
    }

    EURESYS_NAMESPACE::GenTL &genTL;
    BP imageBufferPool;

    RGBConverterTImpl(const RGBConverterTImpl &);
    RGBConverterTImpl &operator=(const RGBConverterTImpl &);
};

template <typename BP>
class RGBConverterT {
public:
    RGBConverterT(EURESYS_NAMESPACE::GenTL &genTL)
    : impl(genTL) {}
    ~RGBConverterT() {}
    void prepareBuffers(size_t bufferSize, size_t count)
    {
        impl.prepareBuffers(bufferSize, count);
    }
    void trimBuffers()
    {
        impl.trimBuffers();
    }
    EURESYS_NAMESPACE::GenTL &getGenTL()
    {
        return impl.getGenTL();
    }

    RGBConverterImpl_EXPOSE(BGR8);
    RGBConverterImpl_EXPOSE(RGB8);

    void inplace1x2yeReordering(uint8_t* imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize = 0)
    {
        impl.toInplace1x2yeReordering(imgPtr, fmt, w, h, imgSize);
    }
    void inplace1x2yeReordering(uint8_t* imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize = 0)
    {
        impl.toInplace1x2yeReordering(imgPtr, getGenTL().imageGetPixelFormat(fmt), w, h, imgSize);
    }

private:
    RGBConverterTImpl<BP> impl;
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
