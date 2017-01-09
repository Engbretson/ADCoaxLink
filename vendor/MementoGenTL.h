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

MEMENTO_API MementoOutputString(const char *text);

/** @cond */

/* typedefs for dynamic loading */
#define MEMENTO_API_P(function) typedef void( GC_CALLTYPE *function )

MEMENTO_API_P(PMementoOutputString)(const char *text);

/** @endcond */

}

/** @} */

#endif
