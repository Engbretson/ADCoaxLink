/* Copyright Euresys 2014 */

#ifndef EURESYS_EGENTL_RAW_HEADER_FILE
#define EURESYS_EGENTL_RAW_HEADER_FILE

#include "internal/EuresysPrelude.h"

#ifdef __linux__
#include <dlfcn.h>
#else
#include <Windows.h>
#endif

#include <string>
#include <sstream>
#include <vector>

#include "GenTL_v1_5.h"
#include "GenTL_v1_5_EuresysCustom.h"

#if defined(_WIN32)
#  if !defined _STDINT_H && !defined _STDINT
      typedef __int16 int16_t;
      typedef unsigned __int16 uint16_t;
      typedef __int64 int64_t;
#  endif
#endif

#include "EuresysGenapi.h"
#include "deprecated/EuresysBayer.h"
#include "EuresysImage.h"
#include "MementoGenTL.h"
#include "EGenTLErrors.h"
#include "internal/EuresysTraceGenTL.h"
#include "internal/EuresysTrace.h"

namespace EURESYS_NAMESPACE {
namespace Internal {

#ifdef __linux__
namespace {
    typedef void *CTI_HANDLE;
    CTI_HANDLE loadCti(const std::string &path) {
        void *h = dlopen(path.c_str(), RTLD_NOW);
        if (!h) {
            char *err = dlerror();
            if (!err) {
                throw cti_loading_error(path);
            }
            else {
                throw cti_loading_error(path + ", " + err);
            }
        }
        return h;
    }
    void unloadCti(CTI_HANDLE h) {
        dlclose(h);
    }
    void *getCtiSymbol(CTI_HANDLE h, const std::string &symbol) {
        return dlsym(h, symbol.c_str());
    }
}
#else
namespace {
    typedef HMODULE CTI_HANDLE;
    CTI_HANDLE loadCti(const std::string &path) {
        HMODULE h = LoadLibraryA(path.c_str());
        if (!h) {
            throw cti_loading_error(path);
        }
        return h;
    }
    void unloadCti(CTI_HANDLE h) {
        FreeLibrary(h);
    }
    void *getCtiSymbol(CTI_HANDLE h, const std::string &symbol) {
        return GetProcAddress(h, symbol.c_str());
    }
}
#endif

class CtiLibrary {
    public:
        CtiLibrary(const std::string &path)
        : path(path)
        , cti(loadCti(path))
        {}
        ~CtiLibrary()
        {
            try {
                unloadCti(cti);
            }
            catch (...) {
            }
        }
        void *getSymbol(const std::string &symbol)
        {
            void *s = getCtiSymbol(cti, symbol);
            if (!s) {
                throw missing_gentl_symbol(path, symbol);
            }
            return s;
        }
        const std::string &getPath() const {
            return path;
        }
    private:
        std::string path;
        CTI_HANDLE cti;
};

#define INIT_GENTL_PROC(cti, proc) proc(reinterpret_cast<gc::P##proc>(cti.getSymbol(#proc)))
#define INIT_EURESYS_PROC(cti, proc) proc(reinterpret_cast<ge::P##proc>(cti.getSymbol(#proc)))
#define INIT_MEMENTO_PROC(cti, proc) proc(reinterpret_cast<P##proc>(cti.getSymbol(#proc)))
#define INIT_BAYER_PROC(cti, proc) proc(reinterpret_cast<ge::P##proc>(cti.getSymbol(#proc)))
#define INIT_IMAGE_PROC(cti, proc) proc(reinterpret_cast<ge::P##proc>(cti.getSymbol(#proc)))
#define INIT_ETRACE_PROC(cti, proc) proc(reinterpret_cast<P##proc>(cti.getSymbol(#proc)))

/** GenICam Transport Layer library support */
class GenTLRaw {
    public:
        GenTLRaw(const std::string &path)
        : cti(path)

        // GenTL functions
        , INIT_GENTL_PROC(cti, GCGetInfo)
        , INIT_GENTL_PROC(cti, GCGetLastError)
        , INIT_GENTL_PROC(cti, GCInitLib)
        , INIT_GENTL_PROC(cti, GCCloseLib)
        , INIT_GENTL_PROC(cti, GCReadPort)
        , INIT_GENTL_PROC(cti, GCWritePort)
        , INIT_GENTL_PROC(cti, GCGetPortURL)
        , INIT_GENTL_PROC(cti, GCGetPortInfo)
        , INIT_GENTL_PROC(cti, GCRegisterEvent)
        , INIT_GENTL_PROC(cti, GCUnregisterEvent)
        , INIT_GENTL_PROC(cti, EventGetData)
        , INIT_EURESYS_PROC(cti, EuresysEventsGetData)
        , INIT_GENTL_PROC(cti, EventGetDataInfo)
        , INIT_GENTL_PROC(cti, EventGetInfo)
        , INIT_GENTL_PROC(cti, EventFlush)
        , INIT_GENTL_PROC(cti, EventKill)
        , INIT_GENTL_PROC(cti, TLOpen)
        , INIT_GENTL_PROC(cti, TLClose)
        , INIT_GENTL_PROC(cti, TLGetInfo)
        , INIT_GENTL_PROC(cti, TLGetNumInterfaces)
        , INIT_GENTL_PROC(cti, TLGetInterfaceID)
        , INIT_GENTL_PROC(cti, TLGetInterfaceInfo)
        , INIT_GENTL_PROC(cti, TLOpenInterface)
        , INIT_GENTL_PROC(cti, TLUpdateInterfaceList)
        , INIT_GENTL_PROC(cti, IFClose)
        , INIT_GENTL_PROC(cti, IFGetInfo)
        , INIT_GENTL_PROC(cti, IFGetNumDevices)
        , INIT_GENTL_PROC(cti, IFGetDeviceID)
        , INIT_GENTL_PROC(cti, IFUpdateDeviceList)
        , INIT_GENTL_PROC(cti, IFGetDeviceInfo)
        , INIT_GENTL_PROC(cti, IFOpenDevice)
        , INIT_GENTL_PROC(cti, DevGetPort)
        , INIT_GENTL_PROC(cti, DevGetNumDataStreams)
        , INIT_GENTL_PROC(cti, DevGetDataStreamID)
        , INIT_GENTL_PROC(cti, DevOpenDataStream)
        , INIT_GENTL_PROC(cti, DevGetInfo)
        , INIT_GENTL_PROC(cti, DevClose)
        , INIT_GENTL_PROC(cti, DSAnnounceBuffer)
        , INIT_GENTL_PROC(cti, DSAllocAndAnnounceBuffer)
        , INIT_EURESYS_PROC(cti, EuresysDSAnnounceBusBuffer)
        , INIT_GENTL_PROC(cti, DSFlushQueue)
        , INIT_GENTL_PROC(cti, DSStartAcquisition)
        , INIT_GENTL_PROC(cti, DSStopAcquisition)
        , INIT_GENTL_PROC(cti, DSGetInfo)
        , INIT_GENTL_PROC(cti, DSGetBufferID)
        , INIT_GENTL_PROC(cti, DSClose)
        , INIT_GENTL_PROC(cti, DSRevokeBuffer)
        , INIT_GENTL_PROC(cti, DSQueueBuffer)
        , INIT_GENTL_PROC(cti, DSGetBufferInfo)
        , INIT_GENTL_PROC(cti, GCGetNumPortURLs)
        , INIT_GENTL_PROC(cti, GCGetPortURLInfo)
        , INIT_GENTL_PROC(cti, GCReadPortStacked)
        , INIT_GENTL_PROC(cti, GCWritePortStacked)
        , INIT_GENTL_PROC(cti, DSGetBufferChunkData)
        , INIT_GENTL_PROC(cti, IFGetParentTL)
        , INIT_GENTL_PROC(cti, DevGetParentIF)
        , INIT_GENTL_PROC(cti, DSGetParentDev)
        , INIT_GENTL_PROC(cti, DSGetNumBufferParts)
        , INIT_GENTL_PROC(cti, DSGetBufferPartInfo)
        // Euresys Memento functions
        , INIT_MEMENTO_PROC(cti, MementoOutputString)
        , INIT_MEMENTO_PROC(cti, MementoOutputStringEx)
        // Euresys Internal Memento
        , INIT_ETRACE_PROC(cti, EGrabberTrace)
        // Euresys Genapi functions
        , INIT_EURESYS_PROC(cti, GenapiSetString)
        , INIT_EURESYS_PROC(cti, GenapiGetString)
        , INIT_EURESYS_PROC(cti, GenapiSetInteger)
        , INIT_EURESYS_PROC(cti, GenapiGetInteger)
        , INIT_EURESYS_PROC(cti, GenapiSetFloat)
        , INIT_EURESYS_PROC(cti, GenapiGetFloat)
        , INIT_EURESYS_PROC(cti, GenapiExecuteCommand)
        , INIT_EURESYS_PROC(cti, GenapiRunScript)
#ifdef EURESYS_USE_BAYER_DEPRECATED_API
        //  Euresys Bayer functions
        , INIT_BAYER_PROC(cti, BayerConvert)
#endif
        //  Euresys Image functions
        , INIT_IMAGE_PROC(cti, ImageConvert)
        , INIT_IMAGE_PROC(cti, ImageGetPixelFormatValue)
        , INIT_IMAGE_PROC(cti, ImageGetPixelFormat)
        , INIT_IMAGE_PROC(cti, ImageGetBytesPerPixel)
        , INIT_IMAGE_PROC(cti, ImageGetBitsPerPixel)
        , INIT_IMAGE_PROC(cti, ImageSaveToDisk)
        , INIT_IMAGE_PROC(cti, ImageGet)
        , INIT_IMAGE_PROC(cti, ImageRelease)
        {}
        virtual ~GenTLRaw()
        {}

        CtiLibrary cti;
        // GenTL functions
        gc::PGCGetInfo GCGetInfo;
        gc::PGCGetLastError GCGetLastError;
        gc::PGCInitLib GCInitLib;
        gc::PGCCloseLib GCCloseLib;
        gc::PGCReadPort GCReadPort;
        gc::PGCWritePort GCWritePort;
        gc::PGCGetPortURL GCGetPortURL;
        gc::PGCGetPortInfo GCGetPortInfo;
        gc::PGCRegisterEvent GCRegisterEvent;
        gc::PGCUnregisterEvent GCUnregisterEvent;
        gc::PEventGetData EventGetData;
        ge::PEuresysEventsGetData EuresysEventsGetData;
        gc::PEventGetDataInfo EventGetDataInfo;
        gc::PEventGetInfo EventGetInfo;
        gc::PEventFlush EventFlush;
        gc::PEventKill EventKill;
        gc::PTLOpen TLOpen;
        gc::PTLClose TLClose;
        gc::PTLGetInfo TLGetInfo;
        gc::PTLGetNumInterfaces TLGetNumInterfaces;
        gc::PTLGetInterfaceID TLGetInterfaceID;
        gc::PTLGetInterfaceInfo TLGetInterfaceInfo;
        gc::PTLOpenInterface TLOpenInterface;
        gc::PTLUpdateInterfaceList TLUpdateInterfaceList;
        gc::PIFClose IFClose;
        gc::PIFGetInfo IFGetInfo;
        gc::PIFGetNumDevices IFGetNumDevices;
        gc::PIFGetDeviceID IFGetDeviceID;
        gc::PIFUpdateDeviceList IFUpdateDeviceList;
        gc::PIFGetDeviceInfo IFGetDeviceInfo;
        gc::PIFOpenDevice IFOpenDevice;
        gc::PDevGetPort DevGetPort;
        gc::PDevGetNumDataStreams DevGetNumDataStreams;
        gc::PDevGetDataStreamID DevGetDataStreamID;
        gc::PDevOpenDataStream DevOpenDataStream;
        gc::PDevGetInfo DevGetInfo;
        gc::PDevClose DevClose;
        gc::PDSAnnounceBuffer DSAnnounceBuffer;
        gc::PDSAllocAndAnnounceBuffer DSAllocAndAnnounceBuffer;
        ge::PEuresysDSAnnounceBusBuffer EuresysDSAnnounceBusBuffer;
        gc::PDSFlushQueue DSFlushQueue;
        gc::PDSStartAcquisition DSStartAcquisition;
        gc::PDSStopAcquisition DSStopAcquisition;
        gc::PDSGetInfo DSGetInfo;
        gc::PDSGetBufferID DSGetBufferID;
        gc::PDSClose DSClose;
        gc::PDSRevokeBuffer DSRevokeBuffer;
        gc::PDSQueueBuffer DSQueueBuffer;
        gc::PDSGetBufferInfo DSGetBufferInfo;
        gc::PGCGetNumPortURLs GCGetNumPortURLs;
        gc::PGCGetPortURLInfo GCGetPortURLInfo;
        gc::PGCReadPortStacked GCReadPortStacked;
        gc::PGCWritePortStacked GCWritePortStacked;
        gc::PDSGetBufferChunkData DSGetBufferChunkData;
        gc::PIFGetParentTL IFGetParentTL;
        gc::PDevGetParentIF DevGetParentIF;
        gc::PDSGetParentDev DSGetParentDev;
        gc::PDSGetNumBufferParts DSGetNumBufferParts;
        gc::PDSGetBufferPartInfo DSGetBufferPartInfo;
        // Euresys Memento functions
        PMementoOutputString MementoOutputString;
        PMementoOutputStringEx MementoOutputStringEx;
        // Euresys Internal Memento
        PEGrabberTrace EGrabberTrace;
        // Euresys Genapi functions
        ge::PGenapiSetString GenapiSetString;
        ge::PGenapiGetString GenapiGetString;
        ge::PGenapiSetInteger GenapiSetInteger;
        ge::PGenapiGetInteger GenapiGetInteger;
        ge::PGenapiSetFloat GenapiSetFloat;
        ge::PGenapiGetFloat GenapiGetFloat;
        ge::PGenapiExecuteCommand GenapiExecuteCommand;
        ge::PGenapiRunScript GenapiRunScript;
#ifdef EURESYS_USE_BAYER_DEPRECATED_API
        // Euresys Bayer functions
        ge::PBayerConvert BayerConvert;
#endif
        // Euresys Image functions
        ge::PImageConvert ImageConvert;
        ge::PImageGetPixelFormatValue ImageGetPixelFormatValue;
        ge::PImageGetPixelFormat ImageGetPixelFormat;
        ge::PImageGetBytesPerPixel ImageGetBytesPerPixel;
        ge::PImageGetBitsPerPixel ImageGetBitsPerPixel;
        ge::PImageSaveToDisk ImageSaveToDisk;
        ge::PImageGet ImageGet;
        ge::PImageRelease ImageRelease;
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
