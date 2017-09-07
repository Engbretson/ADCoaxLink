#ifdef EURESYS_USE_BAYER_DEPRECATED_API

/* Copyright Euresys 2014 */

#ifndef EURESYS_BAYER_HEADER_FILE
#define EURESYS_BAYER_HEADER_FILE

#if !defined(GC_IMPORT_EXPORT) || !defined(GC_CALLTYPE)
#error Include GenTL header file before EuresysBayer.h
#endif

#define BAYER_API GC_IMPORT_EXPORT GC_ERROR GC_CALLTYPE

#ifdef __cplusplus
extern "C" {
namespace GenTL {
namespace EuresysCustomGenTL {
#endif

/* Pixel formats of input/output buffers */
enum PIXEL_FORMAT_LIST {
    PIXEL_FORMAT_BAYER_GB8 = 0,
    PIXEL_FORMAT_BAYER_BG8 = 1,
    PIXEL_FORMAT_BAYER_RG8 = 2,
    PIXEL_FORMAT_BAYER_GR8 = 3,
    PIXEL_FORMAT_RGB24     = 4,
};
typedef int32_t PIXEL_FORMAT;

/* Details related to Region Of Interest */
typedef struct S_ROI_DETAILS {
    int width;      /* width of ROI in pixels (default: BayerConvert parameter inWidth) */
    int height;     /* height of ROI in pixels (default: BayerConvert parameter inHeight) */
    int inOffsetX;  /* x offset (in pixels) in the input bayer buffer (default: 0) */
    int inOffsetY;  /* y offset (in pixels) in the input bayer buffer (default: 0) */
    int outOffsetX; /* x offset (in pixels) in the output decoded buffer (default: 0) */
    int outOffsetY; /* y offset (in pixels) in the output decoded buffer (default: 0) */
    /* Note: each field can be set to 0 to select its default value */
} ROI_DETAILS;

/* Available Bayer decoding methods */
enum BAYER_METHOD_LIST {
    BAYER_METHOD_LEGACY   = 0,
    BAYER_METHOD_ADVANCED = 1,
};
typedef int32_t BAYER_METHOD;

/**
 * Decodes a bayer input buffer into an output buffer
 * @arg method: bayer decoding algorithm
 * @arg inFormat: input buffer pixel format
 * @arg inWidth: input buffer width in pixels
 * @arg inHeight: input buffer height in pixels
 * @arg inPixels: input buffer
 * @arg outFormat: output buffer pixel format
 * @arg outWidth: output buffer width in pixels
 * @arg outHeight: output buffer height in pixels
 * @arg outPixels: output buffer
 * @arg roiDetails: optional roi details
 * @arg reserved: reserved for future use, must be NULL
 */
BAYER_API BayerConvert(BAYER_METHOD method,
                       PIXEL_FORMAT inFormat, int inWidth, int inHeight, const void *inPixels,
                       PIXEL_FORMAT outFormat, int outWidth, int outHeight, void *outPixels,
                       const ROI_DETAILS *roiDetails, void *reserved);

/* typedefs for dynamic loading */
#define BAYER_API_P(function) typedef GC_ERROR( GC_CALLTYPE *function )

BAYER_API_P(PBayerConvert)(BAYER_METHOD method,
                           PIXEL_FORMAT inFormat, int inWidth, int inHeight, const void *inPixels,
                           PIXEL_FORMAT outFormat, int outWidth, int outHeight, void *outPixels,
                           const ROI_DETAILS *roiDetails, void *reserved);

#ifdef __cplusplus
}
}
}
#endif

#endif

#endif
