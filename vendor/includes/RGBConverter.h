/* Copyright Euresys 2015 */

#ifndef RGBCONVERTER_HEADER_FILE
#define RGBCONVERTER_HEADER_FILE

#include "internal/RGBConverterImpl.h"

/** @file
    Defines Euresys::RGBConverter helper class
 **/

namespace EURESYS_NAMESPACE {

/** @class Euresys::RGBConverter
    Image Converter Helper Class
    @details
    
    Usage:

    @code{.cpp}
    Euresys::GenTL genTL;
    Euresys::EGrabber<CallbackModel> grabber(genTL);
    
    // Create an RGBConverter instance
    Euresys::RGBConverter rgbConverter(genTL);
    
    // Add code to configure the grabber
    
    grabber.start();
    Euresys::ScopedBuffer buffer(grabber);
    
    // Retrieve image buffer information
    uint8_t *imgPtr = buffer.getInfo<uint8_t *>(gc::BUFFER_INFO_BASE);
    const std::string format(genTL.imageGetPixelFormat(buffer.getInfo<uint64_t>(gc::BUFFER_INFO_PIXELFORMAT)));
    const size_t width = buffer.getInfo<size_t>(gc::BUFFER_INFO_WIDTH);
    const size_t height = buffer.getInfo<size_t>(gc::BUFFER_INFO_DELIVERED_IMAGEHEIGHT);
    const size_t imgSize = buffer.getInfo<size_t>(gc::BUFFER_INFO_SIZE);
    
    // For conversions to BGR8, create a RGBConverter::BGR8 instance:
    RGBConverter::BGR8 bgr(rgbConverter, imgPtr, format, width, height, imgSize);
    // For conversions to RGB8, create a RGBConverter::RGB8 instance:
    RGBConverter::RGB8 rgb(rgbConverter, imgPtr, format, width, height, imgSize);
    
    // Use getBuffer() method to get a pointer to the converted image
    DoSomethingWithConvertedImage(bgr.getBuffer());
    DoSomethingWithConvertedImage(rgb.getBuffer());
    
    // Use saveToDisk() method to save the converted buffer to disk
    bgr.saveToDisk(filepath, index, optional_parameters);
    // Supported formats: .tiff, .bmp, .png, .jpeg, .jpg
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
    
    // For in-place 1X2YE line reordering,
    // call inplace1x2yeReordering method of the converter
    rgbConverter.inplace1x2yeReordering(imgPtr, format, width, height, imgSize);
    DoSomethingWithConvertedImage(imgPtr);
    @endcode
 **/

/** @class Euresys::RGBConverter::RGB8
    Perform conversions to RGB8 format
    @sa RGBConverter for usage
    @memberof Euresys::RGBConverter
    @warning this converter instance cannot outlive its originating RGBConverter instance
    @class Euresys::RGBConverter::BGR8
    Perform conversions to BGR8 format
    @sa RGBConverter for usage
    @memberof Euresys::RGBConverter
    @warning this converter instance cannot outlive its originating RGBConverter instance
    @fn uint8_t *getBuffer() const
    Get a pointer to converted image (RGB8)
    @memberof Euresys::RGBConverter::RGB8
    @warning the pointer to the converted image is valid as long as its creator (RGB8 instance) is valid,
    in other words the pointer can no longer be used when the RGB8 converter goes out of scope.
    @fn uint8_t *getBuffer() const
    Get a pointer to converted image (BGR8)
    @memberof Euresys::RGBConverter::BGR8
    @warning the pointer to the converted image is valid as long as its creator (BGR8 instance) is valid,
    in other words the pointer can no longer be used when the BGR8 converter goes out of scope.
    @fn void saveToDisk(const std::string &filepath, int64_t index = -1, const GenICam::Client::Euresys::ImageSaveToDiskParams *params = 0)
    Save converted image to disk (RGB8)
    @memberof Euresys::RGBConverter::RGB8
    @fn void saveToDisk(const std::string &filepath, int64_t index = -1, const GenICam::Client::Euresys::ImageSaveToDiskParams *params = 0)
    Save converted image to disk (BGR8)
    @memberof Euresys::RGBConverter::BGR8
 **/

/** @fn void inplace1x2yeReordering(uint8_t* imgPtr, const std::string &fmt, size_t w, size_t h, size_t imgSize = 0)
    Perform in-place 1X2YE line reordering (within the image buffer pointed to by imgPtr)
    @memberof Euresys::RGBConverter
 **/

typedef Internal::RGBConverterT<Internal::BufferPool> RGBConverter;

} // namespace EURESYS_NAMESPACE

#endif
