/* Copyright Euresys 2014 */

#ifndef EURESYS_GENAPI_HEADER_FILE
#define EURESYS_GENAPI_HEADER_FILE

/** @file
    Header file for Euresys GenApi implementation
 **/

#if !defined(GC_IMPORT_EXPORT) || !defined(GC_CALLTYPE)
#error Include GenTL header file before EuresysGenapi.h
#endif

#define GENAPI_API GC_IMPORT_EXPORT GC_ERROR GC_CALLTYPE

#ifndef GC_USER_DEFINED_TYPES
#  if defined(_WIN32)
#    if !defined _STDINT_H && !defined _STDINT
        typedef __int64 int64_t;
#    endif
#  endif
#endif /* GC_DEFINE_TYPES */

#ifdef __cplusplus
extern "C" {
namespace GenICam {
    namespace Client {
        namespace Euresys {
#endif

/** @defgroup CGenApi GenApi (C API)
    @ingroup ECAPI
    Euresys GenApi low-level C API
    @{
 **/

GENAPI_API GenapiSetString(PORT_HANDLE h, const char *sFeature, const char *sValue);
GENAPI_API GenapiGetString(PORT_HANDLE h, const char *sFeature, char *sValue, size_t *piSize);
GENAPI_API GenapiSetInteger(PORT_HANDLE h, const char *sFeature, int64_t iValue);
GENAPI_API GenapiGetInteger(PORT_HANDLE h, const char *sFeature, int64_t *piValue);
GENAPI_API GenapiSetFloat(PORT_HANDLE h, const char *sFeature, double dValue);
GENAPI_API GenapiGetFloat(PORT_HANDLE h, const char *sFeature, double *pdValue);
GENAPI_API GenapiExecuteCommand(PORT_HANDLE h, const char *sFeature);
GENAPI_API GenapiRunScript(const PORT_HANDLE *hPorts, size_t iNumPorts, const char *sScript, size_t reserved1, void *reserved2);

/** @cond */

/* typedefs for dynamic loading */
#define GENAPI_API_P(function) typedef GC_ERROR( GC_CALLTYPE *function )

GENAPI_API_P(PGenapiSetString)(PORT_HANDLE h, const char *sFeature, const char *sValue);
GENAPI_API_P(PGenapiGetString)(PORT_HANDLE h, const char *sFeature, char *sValue, size_t *piSize);
GENAPI_API_P(PGenapiSetInteger)(PORT_HANDLE h, const char *sFeature, int64_t iValue);
GENAPI_API_P(PGenapiGetInteger)(PORT_HANDLE h, const char *sFeature, int64_t *piValue);
GENAPI_API_P(PGenapiSetFloat)(PORT_HANDLE h, const char *sFeature, double dValue);
GENAPI_API_P(PGenapiGetFloat)(PORT_HANDLE h, const char *sFeature, double *pdValue);
GENAPI_API_P(PGenapiExecuteCommand)(PORT_HANDLE h, const char *sFeature);
GENAPI_API_P(PGenapiRunScript)(const PORT_HANDLE *hPorts, size_t iNumPorts, const char *sScript, size_t reserved1, void *reserved2);

/** @endcond */


/** @} */

#ifdef __cplusplus
        }
    }
}
}
#endif

#endif
