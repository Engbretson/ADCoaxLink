/* Copyright Euresys 2015 */

#ifndef EGRABBER_IIMPL_HEADER_FILE
#define EGRABBER_IIMPL_HEADER_FILE

namespace EURESYS_NAMESPACE {

inline Buffer::Buffer(const NewBufferData &data)
: data(data)
{}
inline void Buffer::push(Internal::EGrabberBase &grabber) {
    grabber.getGenTL().dsQueueBuffer(data.dsh, data.bh);
}
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
inline std::string Buffer::getInfoString(Internal::EGrabberBase &grabber, gc::BUFFER_INFO_CMD cmd) {
    return grabber.getGenTL().dsGetBufferInfoString(data.dsh, data.bh, cmd);
}
#endif
template <typename T> inline T Buffer::getInfo(Internal::EGrabberBase &grabber, gc::BUFFER_INFO_CMD cmd) {
    return grabber.getGenTL().dsGetBufferInfo<T>(data.dsh, data.bh, cmd);
}
inline void *Buffer::getUserPointer() {
    return data.userPointer;
}
inline void Buffer::saveToDisk(Internal::EGrabberBase &grabber, const std::string &filepath, int64_t index, const ge::ImageSaveToDiskParams *params) {
    std::string format(grabber.getGenTL().imageGetPixelFormat(getInfo<uint64_t>(grabber, gc::BUFFER_INFO_PIXELFORMAT)));
    size_t bufferSize = getInfo<size_t>(grabber, gc::BUFFER_INFO_SIZE);
    ge::ImageConvertInput input = { static_cast<int>(getInfo<size_t>(grabber, gc::BUFFER_INFO_WIDTH)),
                                    static_cast<int>(getInfo<size_t>(grabber, gc::BUFFER_INFO_DELIVERED_IMAGEHEIGHT)),
                                    getInfo<uint8_t *>(grabber, gc::BUFFER_INFO_BASE),
                                    format.c_str(),
                                    {&bufferSize, 0, 0, 0},
                                    {0, 0, 0, 0} };
    return grabber.getGenTL().imageSaveToDisk(input, filepath, index, params);
}


inline ScopedBuffer::ScopedBuffer(EGrabber<CallbackOnDemand> &grabberSimple, uint64_t timeout)
: grabber(grabberSimple)
, buffer(grabberSimple.pop(timeout))
{}
inline ScopedBuffer::ScopedBuffer(Internal::EGrabberBase &grabber, const NewBufferData &data)
: grabber(grabber)
, buffer(data)
{}
inline ScopedBuffer::~ScopedBuffer() {
    try {
        buffer.push(grabber);
    } catch (...) {
    }
}
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
inline std::string ScopedBuffer::getInfoString(gc::BUFFER_INFO_CMD cmd) {
    return buffer.getInfoString(grabber, cmd);
}
#endif
template <typename T> inline T ScopedBuffer::getInfo(gc::BUFFER_INFO_CMD cmd) {
    return buffer.template getInfo<T>(grabber, cmd);
}
inline void *ScopedBuffer::getUserPointer() {
    return buffer.getUserPointer();
}
inline void ScopedBuffer::saveToDisk(const std::string &filepath, int64_t index, const ge::ImageSaveToDiskParams *params) {
    return buffer.saveToDisk(grabber, filepath, index, params);
}


} // namespace EURESYS_NAMESPACE

#include "generated/EGrabberIImpl_EGrabber.h"
#include "generated/numid.h"

#endif
