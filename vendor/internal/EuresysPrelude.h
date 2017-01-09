/* Copyright Euresys 2015 */

#ifndef EURESYS_PRELUDE_HEADER_FILE
#define EURESYS_PRELUDE_HEADER_FILE

#ifndef EURESYS_NAMESPACE
#define EURESYS_NAMESPACE Euresys
#endif

#ifndef EURESYS_DISABLE_ALL_DEPRECATED_API_WARNINGS

#define MESSAGE_USING_DEPRECATED_EGRABBER_API "Using deprecated EGrabber API"
#define MESSAGE_USING_DEPRECATED_BAYER_API "Using deprecated Bayer API"

#if defined(linux) || defined(__linux) || defined(__linux__)

#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
#warning MESSAGE_USING_DEPRECATED_EGRABBER_API
#endif
#ifdef EURESYS_USE_BAYER_DEPRECATED_API
#warning MESSAGE_USING_DEPRECATED_BAYER_API
#endif

#else

#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
#pragma message(MESSAGE_USING_DEPRECATED_EGRABBER_API)
#endif
#ifdef EURESYS_USE_BAYER_DEPRECATED_API
#pragma message(MESSAGE_USING_DEPRECATED_BAYER_API)
#endif

#endif

#endif

#endif
