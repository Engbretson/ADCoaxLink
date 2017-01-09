/* Copyright Euresys 2016 */

#ifndef EURESYS_TRACE_GENTL_HEADER_FILE
#define EURESYS_TRACE_GENTL_HEADER_FILE

#if !defined(GC_IMPORT_EXPORT) || !defined(GC_CALLTYPE)
#error Include GenTL header file before EuresysTraceGenTL.h
#endif

#define EURESYSTRACEGENTL_API GC_IMPORT_EXPORT int GC_CALLTYPE

extern "C" {

EURESYSTRACEGENTL_API EGrabberTrace(char level, uint64_t id, const char *format, int *args);

#define EURESYSTRACEGENTL_API_P(function) typedef int( GC_CALLTYPE *function )

EURESYSTRACEGENTL_API_P(PEGrabberTrace)(char level, uint64_t id, const char *format, int *args);

}

/** @} */

#endif
