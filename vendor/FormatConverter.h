/* Copyright Euresys 2017 */

#ifndef FORMATCONVERTER_HEADER_FILE
#define FORMATCONVERTER_HEADER_FILE

#include "internal/FormatConverterImpl.h"

/** @file
    Defines Euresys::FormatConverter helper class
 **/

namespace EURESYS_NAMESPACE {

/** Image Converter Helper Class
    @details
    
    Usage:

    @code{.cpp}
    Euresys::EGenTL genTL;
    Euresys::EGrabber<CallbackModel> grabber(genTL);

    // Create an FormatConverter instance
    Euresys::FormatConverter converter(genTL);

    // Add code to configure the grabber

    grabber.start();
    Euresys::ScopedBuffer buffer(grabber);

    // Retrieve image buffer information
    uint8_t *imgPtr = buffer.getInfo<uint8_t *>(gc::BUFFER_INFO_BASE);
    const std::string format(genTL.imageGetPixelFormat(buffer.getInfo<uint64_t>(gc::BUFFER_INFO_PIXELFORMAT)));
    const size_t width = buffer.getInfo<size_t>(gc::BUFFER_INFO_WIDTH);
    const size_t height = buffer.getInfo<size_t>(gc::BUFFER_INFO_DELIVERED_IMAGEHEIGHT);
    const size_t imgSize = buffer.getInfo<size_t>(gc::BUFFER_INFO_SIZE);
    const size_t imgPitch = buffer.getInfo<size_t>(ge::BUFFER_INFO_CUSTOM_LINE_PITCH);

    // For conversions to any format (when conversion is applicable),
    // create an instance of FormatConverter::Auto and use a FormatConverter::OutputFormat to specify output details
    // Example - for conversions to BGR8
    FormatConverter::Auto bgr(converter, FormatConverter::OutputFormat("BGR8"), imgPtr, format, width, height, imgSize, imgPitch);
    // Example - for conversions to RGB8
    FormatConverter::Auto rgb(converter, FormatConverter::OutputFormat("RGB8"), imgPtr, format, width, height, imgSize, imgPitch);
    // Example - to unpack Mono10pmsb to Mono8
    FormatConverter::Auto unpacked(converter, FormatConverter::OutputFormat("Mono8"), packedImgPtr, "Mono10pmsb", width, height, imgSize, imgPitch);
    // For conversions involving custom configurations such as specific bayer decoding method,
    // add the config parameter to FormatConverter::OutputFormat
    // Example - to decode BayerRG8 to RGB8 using advanced bayer decoding method
    FormatConverter::Auto decoded(converter, FormatConverter::OutputFormat("RGB8", IMAGE_CONVERT_OUTPUT_CONFIG_BAYER_ADVANCED), imgPtr, "BayerRG8", width, height, imgSize, imgPitch);

    // Use getBuffer() method to get a pointer to the converted image
    DoSomethingWithConvertedImage(bgr.getBuffer(), bgr.getBufferSize());
    DoSomethingWithConvertedImage(rgb.getBuffer(), rgb.getBufferSize());
    DoSomethingWithConvertedImage(unpacked.getBuffer(), unpacked.getBufferSize());

    // Use saveToDisk() method to save the converted buffer to disk
    bgr.saveToDisk(filepath, index, optional_parameters);
    // Supported formats: .tiff, .bmp, .png, .jpeg, .jpg, .raw
    // See EuresysImage.h for details on optional_parameters (ImageSaveToDiskParams)
    // To save buffer as "path/to/image.bmp" file
    bgr.saveToDisk("path/to/image.bmp");
    // To save buffer as "image.012.jpeg" when index is 12
    bgr.saveToDisk("image.NNN.jpeg", index);
    // To save buffer as "image.012.jpeg" when index is 12,
    //                                    with jpeg quality set to 100,
    //                                    using advanced bayer method
    ImageSaveToDiskParams parameters = { IMAGE_CONVERT_OUTPUT_CONFIG_BAYER_ADVANCED
                                       , 100 };
    bgr.saveToDisk("image.NNN.jpeg", index, &parameters);

    // To copy an image to another buffer,
    // call the copy method of the converter
    converter.copy(destImgPtr, srcImgPtr, format, width, height, imgSize, imgPitch);

    // For in-place 1X2YE line reordering,
    // call inplace1x2yeReordering method of the converter
    converter.inplace1x2yeReordering(imgPtr, format, width, height, imgSize, imgPitch);
    DoSomethingWithConvertedImage(imgPtr);
    @endcode
 **/
class FormatConverter {
    public:
        FormatConverter(EGenTL &gentl);
        ~FormatConverter();
        /** Preallocate buffers in the pool to improve conversion performance
            @param bufferSize size of the buffers to preallocate in the converter pool
            @param count the number of buffers to preallocate
            @note when used properly, this function improves the initial conversion
                  performance that needs a buffer of that size (bufferSize)
            @warning a conversion requiring a buffer of a different size (for which
                     there is no preallocated or unused buffer in the pool) will
                     automatically allocate a new buffer prior to applying the conversion
         **/
        void prepareBuffers(size_t bufferSize, size_t count);
        /// Reclaim unused buffers managed by converter to free memory
        void trimBuffers();
        /// Get the genTL context, for convenience
        EGenTL &getGenTL();

        /** An output format value (see @ref Auto)
         **/
        struct OutputFormat {
            explicit OutputFormat(const char *format, int config = ge::IMAGE_CONVERT_OUTPUT_CONFIG_DEFAULT): value(format), config(config) {}
            explicit OutputFormat(const std::string &format, int config = ge::IMAGE_CONVERT_OUTPUT_CONFIG_DEFAULT): value(format), config(config) {}
            const std::string value;
            int config;
        };

        /** Perform conversions to any specified output format (when applicable)
            @warning this converter instance cannot outlive its originating FormatConverter instance
         **/
        class Auto {
            public:
                Auto(FormatConverter &conv, const OutputFormat &outputFormat, uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize = 0, size_t imgPitch = 0);
                Auto(FormatConverter &conv, const OutputFormat &outputFormat, uint8_t *imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize = 0, size_t imgPitch = 0);
                ~Auto();
                /// Get a pointer to converted image
                uint8_t *getBuffer() const;
                /// Get converted image size in bytes
                size_t getBufferSize() const;
                /// Save converted image to disk
                void saveToDisk(const std::string &filepath, int64_t index = -1, const ge::ImageSaveToDiskParams *params = 0);
            private:
                Internal::FormatConverterAny impl;
        };
        
        /** Perform conversions to BGR8
            @warning this converter instance cannot outlive its originating FormatConverter instance
            @deprecated please use FormatConverter::Auto and FormatConverter::OutputFormat instead, e.g.
            @code{.cpp}
            FormatConverter::Auto bgr8(conv, FormatConverter::OutputFormat("BGR8"), imgPtr, format, width, height);
            @endcode
         **/
        class BGR8 {
            public:
                BGR8(FormatConverter &conv, uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize = 0, size_t imgPitch = 0);
                BGR8(FormatConverter &conv, uint8_t *imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize = 0, size_t imgPitch = 0);
                ~BGR8();
                /// Get a pointer to converted image
                uint8_t *getBuffer() const;
                /// Get converted image size in bytes
                size_t getBufferSize() const;
                /// Save converted image to disk
                void saveToDisk(const std::string &filepath, int64_t index = -1, const ge::ImageSaveToDiskParams *params = 0);
            private:
                Internal::FormatConverterT<Internal::TFormatBGR8> impl;
        };

        /** Perform conversions to RGB8
            @warning this converter instance cannot outlive its originating FormatConverter instance
            @deprecated please use FormatConverter::Auto and FormatConverter::OutputFormat instead, e.g.
            @code{.cpp}
            FormatConverter::Auto rgb8(conv, FormatConverter::OutputFormat("RGB8"), imgPtr, format, width, height);
            @endcode
         **/
        class RGB8 {
            public:
                RGB8(FormatConverter &conv, uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize = 0, size_t imgPitch = 0);
                RGB8(FormatConverter &conv, uint8_t *imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize = 0, size_t imgPitch = 0);
                ~RGB8();
                /// Get a pointer to converted image
                uint8_t *getBuffer() const;
                /// Get converted image size in bytes
                size_t getBufferSize() const;
                /// Save converted image to disk
                void saveToDisk(const std::string &filepath, int64_t index = -1, const ge::ImageSaveToDiskParams *params = 0);
            private:
                Internal::FormatConverterT<Internal::TFormatRGB8> impl;
        };

        /// Copy image from srcImgPtr to destImgPtr
        void copy(uint8_t *destPtr, const uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize = 0, size_t imgPitch = 0);

        /// Perform in-place 1X2YE line reordering (within the image buffer pointed to by imgPtr)
        void inplace1x2yeReordering(uint8_t *imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize = 0, size_t imgPitch = 0);
        /// Perform in-place 1X2YE line reordering (within the image buffer pointed to by imgPtr)
        void inplace1x2yeReordering(uint8_t *imgPtr, uint64_t fmt, size_t w, size_t h, size_t imgSize = 0, size_t imgPitch = 0);

    private:
        Internal::FormatConverterImpl impl;
};

} // namespace EURESYS_NAMESPACE

#include "internal/FormatConverterIImpl.h"

#endif
