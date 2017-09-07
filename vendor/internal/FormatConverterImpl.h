/* Copyright Euresys 2017 */

#ifndef FORMATCONVERTERIMPL_HEADER_FILE
#define FORMATCONVERTERIMPL_HEADER_FILE

namespace EURESYS_NAMESPACE {

namespace Internal {

    class FormatConverterImpl {
        public:
            FormatConverterImpl(EGenTL &gentl)
            : gentl(gentl)
            {}
            ~FormatConverterImpl()
            {
                trimBuffers();
            }
            void prepareBuffers(size_t bufferSize, size_t count)
            {
                for (size_t i = 0; i < count; ++i) {
                    gentl.imageGet(0, &bufferSize);
                }
            }
            void trimBuffers()
            {
                gentl.imageRelease(0);
            }
            EGenTL &getGenTL()
            {
                return gentl;
            }

            void copy(uint8_t *destPtr, const uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
            {
                ge::ImageConvertInput input = {
                    static_cast<int>(w),
                    static_cast<int>(h),
                    imgPtr,
                    fmt.c_str(),
                    {((imgSize != 0) ? &imgSize : 0), ((imgPitch != 0) ? &imgPitch : 0), 0, 0},
                    {0, 0, 0, 0}
                };
                ge::ImageConvertOutput output = {
                    static_cast<int>(w),
                    static_cast<int>(h),
                    destPtr,
                    fmt.c_str(),
                    ge::IMAGE_CONVERT_OUTPUT_CONFIG_DEFAULT,
                    ge::IMAGE_CONVERT_OUTPUT_OPERATION_COPY,
                    {0, 0, 0, 0}
                };
                gentl.imageConvert(input, output, 0);
            }

            void inplace1x2yeReordering(uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
            {
                ge::ImageConvertInput input = {
                    static_cast<int>(w),
                    static_cast<int>(h),
                    imgPtr,
                    fmt.c_str(),
                    {((imgSize != 0) ? &imgSize : 0), ((imgPitch != 0) ? &imgPitch : 0), 0, 0},
                    {0, 0, 0, 0}
                };
                ge::ImageConvertOutput output = {
                    static_cast<int>(w),
                    static_cast<int>(h),
                    imgPtr,
                    fmt.c_str(),
                    ge::IMAGE_CONVERT_OUTPUT_CONFIG_DEFAULT,
                    ge::IMAGE_CONVERT_OUTPUT_OPERATION_1X2YE,
                    {0, 0, 0, 0}
                };
                gentl.imageConvert(input, output, 0);
            }
            void inplace1x2yeReordering(uint8_t *imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
            {
                inplace1x2yeReordering(imgPtr, gentl.imageGetPixelFormat(fmt), w, h, imgSize, imgPitch);
            }

        private:
            EGenTL &gentl;
    };

    class FormatConverterAny {
        public:
            FormatConverterAny(FormatConverterImpl &conv, const std::string &outputFormat,
                uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
            : gentl(conv.getGenTL()), dstFormat(outputFormat)
            , width(static_cast<int>(w)), height(static_cast<int>(h))
            , imageId(0), dstBuffer(0), dstSize(0)
            {
                convert(gentl, dstFormat, imgPtr, fmt, width, height, imgSize, imgPitch, &imageId, &dstBuffer, &dstSize);
            }
            FormatConverterAny(FormatConverterImpl &conv, const std::string &outputFormat,
                uint8_t *imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
            : gentl(conv.getGenTL()), dstFormat(outputFormat)
            , width(static_cast<int>(w)), height(static_cast<int>(h))
            , imageId(0), dstBuffer(0), dstSize(0)
            {
                convert(gentl, dstFormat, imgPtr, gentl.imageGetPixelFormat(fmt), width, height, imgSize, imgPitch, &imageId, &dstBuffer, &dstSize);
            }
            ~FormatConverterAny()
            {
                gentl.imageRelease(imageId);
            }
            uint8_t *getBuffer() const
            {
                return dstBuffer;
            }
            size_t getBufferSize() const
            {
                return dstSize;
            }
            void saveToDisk(const std::string &filepath, int64_t index, const ge::ImageSaveToDiskParams *params)
            {
                ge::ImageConvertInput input = {
                    width,
                    height,
                    dstBuffer,
                    dstFormat.c_str(),
                    {((dstSize != 0) ? &dstSize : 0), 0, 0, 0},
                    {0, 0, 0, 0}
                };
                gentl.imageSaveToDisk(input, filepath, index, params);
            }
        private:
            static ge::IMAGE_ID getConvertedImage(EGenTL &gentl, const std::string &dstFormat,
                uint8_t *imgPtr, const std::string &fmt, int width, int height, size_t imgSize, size_t imgPitch)
            {
                ge::ImageConvertInput input = {
                    width,
                    height,
                    imgPtr,
                    fmt.c_str(),
                    {((imgSize != 0) ? &imgSize : 0), ((imgPitch != 0) ? &imgPitch : 0), 0, 0},
                    {0, 0, 0, 0}
                };
                ge::IMAGE_ID id = 0;
                ge::ImageConvertOutput output = {
                    width,
                    height,
                    &id,
                    dstFormat.c_str(),
                    ge::IMAGE_CONVERT_OUTPUT_CONFIG_DEFAULT |
                    ge::IMAGE_CONVERT_OUTPUT_CONFIG_IMAGE_ID,
                    ge::IMAGE_CONVERT_OUTPUT_OPERATION_COPY,
                    {0, 0, 0, 0}
                };
                gentl.imageConvert(input, output, 0);
                return id;
            }
            static void convert(EGenTL &gentl, const std::string &dstFormat,
                uint8_t *imgPtr, const std::string &fmt, int width, int height, size_t imgSize, size_t imgPitch,
                ge::IMAGE_ID *outImageId, uint8_t **outDstBuffer, size_t *outDstSize)
            {
                ge::IMAGE_ID id = getConvertedImage(gentl, dstFormat, imgPtr, fmt, width, height, imgSize, imgPitch);
                uint8_t *dstBuffer = 0;
                size_t dstSize = 0;
                try {
                    dstBuffer = reinterpret_cast<uint8_t *>(gentl.imageGet(id, &dstSize));
                } catch (...) {
                    gentl.imageRelease(id);
                    throw;
                }
                *outImageId = id;
                *outDstBuffer = dstBuffer;
                *outDstSize = dstSize;
            }
            EGenTL &gentl;
            const std::string dstFormat;
            const int width;
            const int height;
            ge::IMAGE_ID imageId;
            uint8_t *dstBuffer;
            size_t dstSize;
    };

    class FormatConverterAny;
    template <typename TFormat> class FormatConverterT;

    struct TFormatBGR8 {};
    struct TFormatRGB8 {};

    template <typename TFormat> const char *getTFormatString();
    template <typename TFormat> class FormatConverterT: public FormatConverterAny {
        public:
            FormatConverterT(FormatConverterImpl &conv, uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
            : FormatConverterAny(conv, getTFormatString<TFormat>(), imgPtr, fmt, w, h, imgSize, imgPitch)
            {}
            FormatConverterT(FormatConverterImpl &conv, uint8_t *imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
            : FormatConverterAny(conv, getTFormatString<TFormat>(), imgPtr, fmt, w, h, imgSize, imgPitch)
            {}
    };

    template <> inline const char *getTFormatString<TFormatBGR8>() { return "BGR8"; }
    template <> inline const char *getTFormatString<TFormatRGB8>() { return "RGB8"; }

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
