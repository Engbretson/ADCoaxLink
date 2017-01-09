/* Copyright Euresys 2014 */

#ifndef MEMENTO_GENTL_HEADER_FILE
#define MEMENTO_GENTL_HEADER_FILE

/** @file
    Definition of MementoOutputString function
 **/

#if !defined(GC_IMPORT_EXPORT) || !defined(GC_CALLTYPE)
#error Include GenTL header file before MementoGenTL.h
#endif

/** @defgroup CMemento Memento (C API)
    @ingroup ECAPI
    Euresys Memento low-level C API
    @{
 **/

#define MEMENTO_API GC_IMPORT_EXPORT void GC_CALLTYPE

extern "C" {

#define MEMENTO_VERBOSITY_CRITICAL (1)
#define MEMENTO_VERBOSITY_ERROR    (2)
#define MEMENTO_VERBOSITY_WARNING  (3)
#define MEMENTO_VERBOSITY_NOTICE   (4)
#define MEMENTO_VERBOSITY_INFO     (5)
#define MEMENTO_VERBOSITY_DEBUG    (6)
#define MEMENTO_VERBOSITY_VERBOSE  (7)

MEMENTO_API MementoOutputString(const char *text);
MEMENTO_API MementoOutputStringEx(const char *text, unsigned char verbosity, unsigned char kind);

/** @cond */

/* typedefs for dynamic loading */
#define MEMENTO_API_P(function) typedef void( GC_CALLTYPE *function )

MEMENTO_API_P(PMementoOutputString)(const char *text);
MEMENTO_API_P(PMementoOutputStringEx)(const char *text, unsigned char verbosity, unsigned char kind);

/** @endcond */

}

/** @} */

#endif
