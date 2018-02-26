/* Copyright Euresys 2015 */

#ifndef EURESYS_IMAGE_HEADER_FILE
#define EURESYS_IMAGE_HEADER_FILE

/** @file
    Header file for image manipulation functions
 **/

#ifndef EXT_IMAGE_CONVERT_TYPES
#if !defined(GC_IMPORT_EXPORT) || !defined(GC_CALLTYPE)
#error Include GenTL header file before EuresysImage.h
#endif

#define IMAGE_API GC_IMPORT_EXPORT GC_ERROR GC_CALLTYPE
#endif

#ifdef __cplusplus
extern "C" {
namespace GenTL {
namespace EuresysCustomGenTL {
#endif

/** @defgroup CImage Image (C API)
    @ingroup ECAPI
    Euresys Image low-level C API
    @{
 **/

enum IMAGE_CONVERT_OUTPUT_CONFIG
{
    IMAGE_CONVERT_OUTPUT_CONFIG_DEFAULT        =       0,  /**< use default bayer decoding when applicable */
    IMAGE_CONVERT_OUTPUT_CONFIG_BAYER_ADVANCED = (1 << 0), /**< enable advanced bayer decoding when applicable */
    IMAGE_CONVERT_OUTPUT_CONFIG_IMAGE_ID       = (1 << 1), /**< output pixels points to a IMAGE_ID */
};

enum IMAGE_CONVERT_OUTPUT_OPERATION
{
    IMAGE_CONVERT_OUTPUT_OPERATION_COPY       = 0,  /**< default conversion output mode */
    IMAGE_CONVERT_OUTPUT_OPERATION_1X2YE      = 1   /**< apply 1X2YE line reordering operation
                                                         @note in-place reordering is allowed,
                                                         i.e. input and output buffers can be the
                                                         same in this case
                                                     **/
};

enum IMAGE_CONVERT_INPUT_EXTRA
{
    IMAGE_CONVERT_INPUT_EXTRA_IX_BUFFER_SIZE    = 0, /**< extra[0] optional pointer to input buffer size (size_t) */
    IMAGE_CONVERT_INPUT_EXTRA_IX_LINE_PITCH     = 1, /**< extra[1] optional pointer to input line pitch, mandatory for packed formats (size_t) */
    IMAGE_CONVERT_INPUT_EXTRA_IX_RESERVED_2     = 2, /**< extra[2] reserved for future use, @pre must be 0 */
    IMAGE_CONVERT_INPUT_EXTRA_IX_RESERVED_3     = 3, /**< extra[3] reserved for future use, @pre must be 0 */
};

typedef size_t IMAGE_ID;

/** Image Conversion - Input Details
    @sa ImageConvert
 **/
typedef struct ImageConvertInput {
    int width;            /**< input buffer width in pixels */
    int height;           /**< input buffer height in pixels */
    const void *pixels;   /**< input buffer */
    const char *format;   /**< input format */
    const void *extra[4]; /**< see @ref IMAGE_CONVERT_INPUT_EXTRA */
    int reserved[4];      /**< reserved for future use, @pre must be 0 */
} ImageConvertInput;

/** Image Conversion - Output Details
    @sa ImageConvert
 **/
typedef struct ImageConvertOutput {
    int width;            /**< output buffer width in pixels */
    int height;           /**< output buffer height in pixels */
    void *pixels;         /**< output buffer (or address of new image id if IMAGE_CONVERT_OUTPUT_CONFIG_IMAGE_ID) */
    const char *format;   /**< output format */
    int config;           /**< convert configuration, see @ref IMAGE_CONVERT_OUTPUT_CONFIG */
    int operation;        /**< convert operation, see @ref IMAGE_CONVERT_OUTPUT_OPERATION */
    int reserved[4];      /**< reserved for future use, @pre must be 0 */
} ImageConvertOutput;

/** Image Conversion - Region Of Interest Details (Optional)
    @sa ImageConvert
    @note each field can be set to 0 to select its default value
 **/
typedef struct ImageConvertROI {
    int width;            /**< width of ROI in pixels (default: ImageConvertInput parameter width) */
    int height;           /**< height of ROI in pixels (default: ImageConvertInput parameter height) */
    int inOffsetX;        /**< x offset (in pixels) in the input buffer (default: 0) */
    int inOffsetY;        /**< y offset (in pixels) in the input buffer (default: 0) */
    int outOffsetX;       /**< x offset (in pixels) in the output decoded buffer (default: 0) */
    int outOffsetY;       /**< y offset (in pixels) in the output decoded buffer (default: 0) */
} ImageConvertROI;

#define IMAGE_SAVE_TO_DISK_DEFAULT_CONFIG  IMAGE_CONVERT_OUTPUT_CONFIG_BAYER_ADVANCED
#define IMAGE_SAVE_TO_DISK_DEFAULT_QUALITY 50

/** Image Save To Disk Parameters (Optional)
    @sa ImageSaveToDisk
 **/
typedef struct ImageSaveToDiskParams {
    int config;           /**< convert configuration, see  @ref IMAGE_CONVERT_OUTPUT_CONFIG */
    int quality;          /**< quality for jpeg files, from 0 (lowest) to 100 (highest) */
    int reserved[4];      /**< reserved for future use, @pre must be 0 */
} ImageSaveToDiskParams;

#ifndef EXT_IMAGE_CONVERT_TYPES
/** Convert image buffer
    @param input details of the image buffer to convert
    @param output details of the image output buffer (conversion result)
    @param roi optional region of interest to convert,
    if NULL the complete buffer is converted
    
    @warning unless explicitly stated (e.g. in-place reordering),
    input and output buffers shall not overlap
    
    @verbatim
    Supported image conversions:
    +-----------+-------------------------------------------------------+
    |           |                       O u p u t                       |
    |           +-------+-------+-------+-------+-------+-------+-------+
    |           | MONO  | BAYER | RGB   | RGBA  | BGR   | BGRA  | YCbCr |
    +---+-------+-------+-------+-------+-------+-------+-------+-------+
    |   | MONO  | A,C,E |       | B,C,F |       | B,C,F |       |       |
    |   +-------+-------+-------+-------+-------+-------+-------+-------+
    | I | BAYER |       | A,C,E | B,F   |       | B,F   |       |       |
    |   +-------+-------+-------+-------+-------+-------+-------+-------+
    | n | RGB   |       |       | A,C,D |       | C     |       |       |
    |   +-------+-------+-------+-------+-------+-------+-------+-------+
    | p | RGBA  |       |       | C     | A     | C     |       |       |
    |   +-------+-------+-------+-------+-------+-------+-------+-------+
    | u | BGR   |       |       | C     |       | A,C   |       |       |
    |   +-------+-------+-------+-------+-------+-------+-------+-------+
    | t | BGRA  |       |       | C     |       | C     | A     |       |
    |   +-------+-------+-------+-------+-------+-------+-------+-------+
    |   | YCbCr |       |       | F     |       | F     |       | A,C,E |
    +---+-------+-------+-------+-------+-------+-------+-------+-------+
    
    A: Operation: copy, 1x2ye, etc.
    B: RGB Output: N-bit to N-bit components with N in {8, 10, 12, 14, 16}
    C: Depth Reduction: N-bit to 8-bit component(s) with N in {10, 12, 14, 16}
    D: Align to 8-bit: Convert RGB8a32 to RGB8
    E: Unpacking: N-bit 'pmsb' to 8-bit/16-bit component(s) with N in {10, 12, 14}
    F: RGB8/BGR8 Output: Handle conversion paths from packed and/or Bayer/YCbCr formats internally
    @endverbatim
 **/
IMAGE_API ImageConvert(const ImageConvertInput *input, const ImageConvertOutput *output, const ImageConvertROI *roi);

/** Convert PFNC pixel format name into its numerical value
    @param[in] sFormat name to convert
    @param[in] iNs pixel format namespace value, available values:
    @parblock
     - @ref GenTL::PIXELFORMAT_NAMESPACE_UNKNOWN
     - @ref GenTL::PIXELFORMAT_NAMESPACE_PFNC_16BIT
     - @ref GenTL::PIXELFORMAT_NAMESPACE_PFNC_32BIT
    @endparblock
    @param[out] piValue numerical value of pixel format
 **/
IMAGE_API ImageGetPixelFormatValue(const char *sFormat, unsigned int iNs, unsigned int *piValue);

/** Convert PFNC pixel format numerical value into its name
    @param[in] iValue value to convert
    @param[out] sFormat pixel format name
    @param[in,out] piSize input: size of buffer sFormat; output: size of output format name
 **/
IMAGE_API ImageGetPixelFormat(uint64_t iValue, char *sFormat, size_t *piSize);

/** Get number of bytes per pixel in a specific pixel format
    @param[in] sFormat format to query
    @param[out] piValue number of bytes per pixel
 **/
IMAGE_API ImageGetBytesPerPixel(const char* sFormat, unsigned int *piValue);

/** Get number of bits per pixel in a specific pixel format
    @param[in] sFormat format to query
    @param[out] piValue number of bits per pixel
 **/
IMAGE_API ImageGetBitsPerPixel(const char* sFormat, unsigned int *piValue);

/** Save image buffer to disk
    @param input details of the image buffer to convert
    @param sFilepath path or path pattern
    @parblock
    - path of the new image file, the file extension determines the file format
    - path pattern where a group characters 'N' is replaced by the value of iIndex:
      - if iIndex is 5, N becomes 5
      - if iIndex is 9, NN becomes 09
      - if iIndex is 10, NN becomes 10
    @endparblock
    @param iIndex
    @parblock
    - if iIndex >= 0, enable pattern substitution with given iIndex value
    - if iIndex < 0, disable pattern substitution
    @endparblock
    @param params optional parameters
    @pre the parent directory must exist
    @note Prefer using Euresys::ScopedBuffer::saveToDisk,
    Euresys::Buffer::saveToDisk or Euresys::RGBConverter.
    They are safer and easier to use as they do the required queries and
    checks on the buffer sizes and formats automatically.
    
    Supported image conversions:
    @verbatim
    [X] Mono8
    [X] Mono10(pmsb)
    [X] Mono12(pmsb)
    [X] Mono14(pmsb)
    [X] Mono16
    [X] RGB8
    [X] RGBa8
    [X] RGB8a32
    [ ] RGB10
    [ ] RGBa10
    [ ] RGB12
    [ ] RGBa12
    [ ] RGB14
    [ ] RGBa14
    [ ] RGB16
    [ ] RGBa16
    [X] BGR8
    [X] BGRa8
    [X] BGR8a32
    [X] BayerRG8
    [X] BayerGR8
    [X] BayerBG8
    [X] BayerGB8
    [X] BayerRG10(pmsb)
    [X] BayerGR10(pmsb)
    [X] BayerBG10(pmsb)
    [X] BayerGB10(pmsb)
    [X] BayerRG12(pmsb)
    [X] BayerGR12(pmsb)
    [X] BayerBG12(pmsb)
    [X] BayerGB12(pmsb)
    [X] BayerRG14(pmsb)
    [X] BayerGR14(pmsb)
    [X] BayerBG14(pmsb)
    [X] BayerGB14(pmsb)
    [X] BayerRG16
    [X] BayerGR16
    [X] BayerBG16
    [X] BayerGB16
    @endverbatim
 **/
IMAGE_API ImageSaveToDisk(const ImageConvertInput *input, const char *sFilepath, int64_t iIndex, const ImageSaveToDiskParams *params);

/** Get image information associated to an image identifier
    @param[in] idImage identifier of an image created by ImageConvert
    @param[out] outPixels image pixels
    @param[out] outSize image size
 **/
IMAGE_API ImageGet(IMAGE_ID idImage, void **outPixels, size_t *outSize);

/** Release image associated to an image identifier
    @param[in] idImage identifier of the image to release
 **/
IMAGE_API ImageRelease(IMAGE_ID idImage);


/** @cond */

/* typedefs for dynamic loading */
#define IMAGE_API_P(function) typedef GC_ERROR( GC_CALLTYPE *function )

IMAGE_API_P(PImageConvert)(const ImageConvertInput *input, const ImageConvertOutput *output, const ImageConvertROI *roi);
IMAGE_API_P(PImageGetPixelFormatValue)(const char *sFormat, unsigned int iNs, unsigned int *piValue);
IMAGE_API_P(PImageGetPixelFormat)(uint64_t iValue, char *sFormat, size_t *piSize);
IMAGE_API_P(PImageGetBytesPerPixel)(const char* sFormat, unsigned int *piValue);
IMAGE_API_P(PImageGetBitsPerPixel)(const char* sFormat, unsigned int *piValue);
IMAGE_API_P(PImageSaveToDisk)(const ImageConvertInput *input, const char *sFilepath, int64_t iIndex, const ImageSaveToDiskParams *params);
IMAGE_API_P(PImageGet)(IMAGE_ID idImage, void **outPixels, size_t *outSize);
IMAGE_API_P(PImageRelease)(IMAGE_ID idImage);

/** @endcond */

#endif // EXT_IMAGE_CONVERT_TYPES

/** @} */

#ifdef __cplusplus
}
}
}
#endif

#endif
