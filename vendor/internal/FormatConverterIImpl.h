/* Copyright Euresys 2017 */

#ifndef FORMATCONVERTER_IIMPL_HEADER_FILE
#define FORMATCONVERTER_IIMPL_HEADER_FILE

namespace EURESYS_NAMESPACE {

inline FormatConverter::FormatConverter(EGenTL &gentl)
: impl(gentl)
{}
inline FormatConverter::~FormatConverter()
{}
inline void FormatConverter::prepareBuffers(size_t bufferSize, size_t count) {
    impl.prepareBuffers(bufferSize, count);
}
inline void FormatConverter::trimBuffers() {
    impl.trimBuffers();
}
inline EGenTL &FormatConverter::getGenTL() {
    return impl.getGenTL();
}
inline void FormatConverter::copy(uint8_t *destPtr, const uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch) {
    impl.copy(destPtr, imgPtr, fmt, w, h, imgSize, imgPitch);
}
inline void FormatConverter::inplace1x2yeReordering(uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch) {
    impl.inplace1x2yeReordering(imgPtr, fmt, w, h, imgSize, imgPitch);
}
inline void FormatConverter::inplace1x2yeReordering(uint8_t *imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch) {
    impl.inplace1x2yeReordering(imgPtr, fmt, w, h, imgSize, imgPitch);
}

inline FormatConverter::Auto::Auto(FormatConverter &conv, const OutputFormat &outputFormat, uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
: impl(conv.impl, outputFormat.value, outputFormat.config, imgPtr, fmt, w, h, imgSize, imgPitch)
{}
inline FormatConverter::Auto::Auto(FormatConverter &conv, const OutputFormat &outputFormat, uint8_t *imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
: impl(conv.impl, outputFormat.value, outputFormat.config, imgPtr, fmt, w, h, imgSize, imgPitch)
{}
inline FormatConverter::Auto::~Auto()
{}
inline uint8_t *FormatConverter::Auto::getBuffer() const {
    return impl.getBuffer();
}
inline size_t FormatConverter::Auto::getBufferSize() const {
    return impl.getBufferSize();
}
inline void FormatConverter::Auto::saveToDisk(const std::string &filepath, int64_t index, const ge::ImageSaveToDiskParams *params) {
    impl.saveToDisk(filepath, index, params);
}

inline FormatConverter::BGR8::BGR8(FormatConverter &conv, uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
: impl(conv.impl, imgPtr, fmt, w, h, imgSize, imgPitch)
{}
inline FormatConverter::BGR8::BGR8(FormatConverter &conv, uint8_t *imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
: impl(conv.impl, imgPtr, fmt, w, h, imgSize, imgPitch)
{}
inline FormatConverter::BGR8::~BGR8()
{}
inline uint8_t *FormatConverter::BGR8::getBuffer() const {
    return impl.getBuffer();
}
inline size_t FormatConverter::BGR8::getBufferSize() const {
    return impl.getBufferSize();
}
inline void FormatConverter::BGR8::saveToDisk(const std::string &filepath, int64_t index, const ge::ImageSaveToDiskParams *params) {
    impl.saveToDisk(filepath, index, params);
}

inline FormatConverter::RGB8::RGB8(FormatConverter &conv, uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
: impl(conv.impl, imgPtr, fmt, w, h, imgSize, imgPitch)
{}
inline FormatConverter::RGB8::RGB8(FormatConverter &conv, uint8_t *imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize, size_t imgPitch)
: impl(conv.impl, imgPtr, fmt, w, h, imgSize, imgPitch)
{}
inline FormatConverter::RGB8::~RGB8()
{}
inline uint8_t *FormatConverter::RGB8::getBuffer() const {
    return impl.getBuffer();
}
inline size_t FormatConverter::RGB8::getBufferSize() const {
    return impl.getBufferSize();
}
inline void FormatConverter::RGB8::saveToDisk(const std::string &filepath, int64_t index, const ge::ImageSaveToDiskParams *params) {
    impl.saveToDisk(filepath, index, params);
}

} // namespace EURESYS_NAMESPACE

#endif
