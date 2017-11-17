/* Copyright Euresys 2014 */

#ifndef EURESYS_GENTL_IMPL_HEADER_FILE
#define EURESYS_GENTL_IMPL_HEADER_FILE

#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#include "EuresysGenTLRaw.h"

namespace EURESYS_NAMESPACE {

struct CommandInfo {
    gc::INFO_DATATYPE type;
    size_t size;
    std::vector<char> buffer;
};

namespace Internal {

// TODO: expose DSGetBufferChunkData (not available in Coaxlink CTI)

namespace {
    template<int> const char *getEuresysCtiEnvVariable();
    template<> inline const char *getEuresysCtiEnvVariable<32>() {
        return "EURESYS_COAXLINK_GENTL32_CTI";
    }
    template<> inline const char *getEuresysCtiEnvVariable<64>() {
        return "EURESYS_COAXLINK_GENTL64_CTI";
    }

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4996 ) // 'getenv': This function or variable may be unsafe
#endif
    inline std::string getEuresysCtiPath() {
        std::string envvar(getEuresysCtiEnvVariable<8*sizeof(size_t)>());
        const char *value = std::getenv(envvar.c_str());
        if (!value || !value[0]) {
            throw client_error(envvar + " is not set");
        }
        return std::string(value);
    }
#ifdef _MSC_VER
#pragma warning( pop )
#endif

    std::vector<std::string> split(const std::string &str) {
        std::stringstream ss(str);
        std::vector<std::string> elems;
        std::string item;
        while (std::getline(ss, item)) {
            elems.push_back(item);
        }
        return elems;
    }

    std::vector<std::string> split(const std::string &str, char sep) {
        std::vector<std::string> elems;
        size_t pos = 0;
        for (size_t p = 0; p < str.size(); ++p) {
            if (str[p] == sep) {
                elems.push_back(std::string(str, pos, p - pos));
                pos = p + 1;
            }
        }
        elems.push_back(std::string(str, pos));
        return elems;
    }

    template<typename T> bool isInfoString(const T *) {
        return false;
    }
    template<> inline bool isInfoString<std::string>(const std::string *) {
        return true;
    }
    template<typename T> bool isCommandInfo(const T *) {
        return false;
    }
    template<> inline bool isCommandInfo<CommandInfo>(const CommandInfo *) {
        return true;
    }
    template<typename T> T fromString(const std::string &) {
        // Should never happen
        throw client_error("types don't match");
    }
    template<> inline std::string fromString<std::string>(const std::string &s) {
        return s;
    }
    template<typename T> T fromCommandInfo(const CommandInfo &) {
        // Should never happen
        throw client_error("types don't match");
    }
    template<> inline CommandInfo fromCommandInfo<CommandInfo>(const CommandInfo &d) {
        return d;
    }
}

class GenTLImpl: private GenTLRaw {
#ifdef EURESYS_GENTL_IMPL_ALLOW_GCINITLIB_FAILURE
        bool initialized;
#endif
    public:
        ETraceContext traceCtx;
        GenTLImpl(const std::string &path)
        : GenTLRaw(path)
#ifdef EURESYS_GENTL_IMPL_ALLOW_GCINITLIB_FAILURE
        , initialized(false)
#endif
        , traceCtx(EGrabberTrace)
        {
#ifdef EURESYS_GENTL_IMPL_ALLOW_GCINITLIB_FAILURE
            if (chkCatch<gc::GC_ERR_RESOURCE_IN_USE>(GCInitLib())) {
                traceCtx.hTrace<'W',0x3924e3ba0ae7dd4eULL,'s'>("%_: GCInitLib failed (GC_ERR_RESOURCE_IN_USE), continue anyway", cti.getPath());
            } else {
                initialized = true;
            }
#else
            chk(GCInitLib());
#endif
            try {
                traceCtx.hTrace<'D',0xb65e49d49aa2e475ULL,'s'>("initialized %_", cti.getPath());
            }
            catch (...) {
            }
        }
        virtual ~GenTLImpl() {
            try {
                traceCtx.hTrace<'D',0x7cdfb054062362e5ULL,'s'>("closing %_", cti.getPath());
#ifdef EURESYS_GENTL_IMPL_ALLOW_GCINITLIB_FAILURE
                if (initialized) {
                    GCCloseLib();
                } else {
                    traceCtx.hTrace<'D',0x93377cb5f786ccc6ULL,'s'>("%_: skip GCCloseLib", cti.getPath());
                }
#else
                GCCloseLib();
#endif
            }
            catch (...) {
            }
        }
        std::string gcGetInfoString(gc::TL_INFO_CMD cmd) {
            return infoString(CgcGetInfo(cmd));
        }
        template <typename T> T gcGetInfo(gc::TL_INFO_CMD cmd) {
            return info<T, CgcGetInfo>(CgcGetInfo(cmd));
        }
        // GenTL Port functions
        void gcReadPort(gc::PORT_HANDLE ph, uint64_t address, std::vector<char> &data) {
            size_t size = data.size();
            chk(GCReadPort(ph, address, &data[0], &size));
            if (size != data.size()) {
                throw unexpected_data_size(data.size(), size);
            }
        }
        std::string gcReadPortString(gc::PORT_HANDLE ph, uint64_t address, size_t size) {
            std::vector<char> data(size);
            gcReadPort(ph, address, data);
            return toString(data, size);
        }
        uint32_t gcReadPort(gc::PORT_HANDLE ph, uint64_t address) {
            uint32_t data;
            const size_t SIZE = sizeof(data);
            size_t size = SIZE;
            chk(GCReadPort(ph, address, &data, &size));
            if (size != SIZE) {
                throw unexpected_data_size(SIZE, size);
            }
            return data;
        }
        void gcWritePort(gc::PORT_HANDLE ph, uint64_t address, const std::vector<char> &data) {
            size_t size = data.size();
            chk(GCWritePort(ph, address, &data[0], &size));
            if (size != data.size()) {
                throw unexpected_data_size(data.size(), size);
            }
        }
        std::vector<std::string> gcGetPortURL(gc::PORT_HANDLE ph) {
            return split((getString(CgcGetPortURL(ph))), 0);
        }
        std::string gcGetPortInfoString(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
            return infoString(CgcGetPortInfo(ph, cmd));
        }
        template <typename T> T gcGetPortInfo(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
            return info<T, CgcGetPortInfo>(CgcGetPortInfo(ph, cmd));
        }
        // GenTL Event functions
        gc::EVENT_HANDLE gcRegisterEvent(gc::EVENTSRC_HANDLE h, gc::EVENT_TYPE event) {
            gc::EVENT_HANDLE eh;
            chk(GCRegisterEvent(h, event, &eh));
            return eh;
        }
        void gcUnregisterEvent(gc::EVENTSRC_HANDLE h, gc::EVENT_TYPE event) {
            chk(GCUnregisterEvent(h, event));
        }
        size_t eventGetData(gc::EVENT_HANDLE eh, void *buffer, size_t size, uint64_t timeout) {
            size_t s = size;
            chk(EventGetData(eh, buffer, &s, timeout));
            return s;
        }
        void eventsGetData(std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY> &entries, uint64_t *timeout) {
            chk(EuresysEventsGetData(&entries[0], entries.size(), timeout));
        }
        std::string eventGetDataInfoString(gc::EVENT_HANDLE eh,
                                           const void *buffer, size_t size,
                                           gc::EVENT_DATA_INFO_CMD cmd) {
            return infoString(CeventGetDataInfo(eh, buffer, size, cmd));
        }
        template <typename T> T eventGetDataInfo(gc::EVENT_HANDLE eh,
                                                 const void *buffer, size_t size,
                                                 gc::EVENT_DATA_INFO_CMD cmd) {
            return info<T, CeventGetDataInfo>(CeventGetDataInfo(eh, buffer, size, cmd));
        }
        std::string eventGetInfoString(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
            return infoString(CeventGetInfo(eh, cmd));
        }
        template <typename T> T eventGetInfo(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
            return info<T, CeventGetInfo>(CeventGetInfo(eh, cmd));
        }
        void eventFlush(gc::EVENT_HANDLE eh) {
            chk(EventFlush(eh));
        }
        void eventKill(gc::EVENT_HANDLE eh) {
            chk(EventKill(eh));
        }
        // GenTL TL functions
        gc::TL_HANDLE tlOpen() {
            gc::TL_HANDLE tlh;
            chk(TLOpen(&tlh));
            return tlh;
        }
        void tlClose(gc::TL_HANDLE tlh) {
            chk(TLClose(tlh));
        }
        std::string tlGetInfoString(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
            return infoString(CtlGetInfo(tlh, cmd));
        }
        template <typename T> T tlGetInfo(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
            return info<T, CtlGetInfo>(CtlGetInfo(tlh, cmd));
        }
        uint32_t tlGetNumInterfaces(gc::TL_HANDLE tlh) {
            uint32_t nif = 0;
            chk(TLGetNumInterfaces(tlh, &nif));
            return nif;
        }
        std::string tlGetInterfaceID(gc::TL_HANDLE tlh, uint32_t index) {
            return getString(CtlGetInterfaceID(tlh, index));
        }
        std::string tlGetInterfaceInfoString(gc::TL_HANDLE tlh, const std::string &ifID, gc::TL_INFO_CMD cmd) {
            return infoString(CtlGetInterfaceInfo(tlh, ifID, cmd));
        }
        template <typename T> T tlGetInterfaceInfo(gc::TL_HANDLE tlh, const std::string &ifID, gc::TL_INFO_CMD cmd) {
            return info<T, CtlGetInterfaceInfo>(CtlGetInterfaceInfo(tlh, ifID, cmd));
        }
        gc::IF_HANDLE tlOpenInterface(gc::TL_HANDLE tlh, const std::string &ifID) {
            gc::IF_HANDLE ifh;
            chk(TLOpenInterface(tlh, ifID.c_str(), &ifh));
            return ifh;
        }
        bool tlUpdateInterfaceList(gc::TL_HANDLE tlh, uint64_t timeout) {
            bool8_t changed;
            chk(TLUpdateInterfaceList(tlh, &changed, timeout));
            return (changed != 0);
        }
        // GenTL Interface functions
        void ifClose(gc::IF_HANDLE ifh) {
            chk(IFClose(ifh));
        }
        std::string ifGetInfoString(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
            return infoString(CifGetInfo(ifh, cmd));
        }
        template <typename T> T ifGetInfo(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
            return info<T, CifGetInfo>(CifGetInfo(ifh, cmd));
        }
        uint32_t ifGetNumDevices(gc::IF_HANDLE ifh) {
            uint32_t ndev = 0;
            chk(IFGetNumDevices(ifh, &ndev));
            return ndev;
        }
        std::string ifGetDeviceID(gc::IF_HANDLE ifh, uint32_t index) {
            return getString(CifGetDeviceID(ifh, index));
        }
        bool ifUpdateDeviceList(gc::IF_HANDLE ifh, uint64_t timeout) {
            bool8_t changed;
            chk(IFUpdateDeviceList(ifh, &changed, timeout));
            return (changed != 0);            
        }
        std::string ifGetDeviceInfoString(gc::IF_HANDLE ifh, const std::string &devID, gc::INTERFACE_INFO_CMD cmd) {
            return infoString(CifGetDeviceInfo(ifh, devID, cmd));
        }
        template <typename T> T ifGetDeviceInfo(gc::IF_HANDLE ifh, const std::string &devID, gc::INTERFACE_INFO_CMD cmd) {
            return info<T, CifGetDeviceInfo>(CifGetDeviceInfo(ifh, devID, cmd));
        }
        gc::DEV_HANDLE ifOpenDevice(gc::IF_HANDLE ifh, const std::string &devID,
                                    gc::DEVICE_ACCESS_FLAGS flags) {
            gc::DEV_HANDLE devh;
            chk(IFOpenDevice(ifh, devID.c_str(), flags, &devh));
            return devh;
        }
        // GenTL Device functions
        gc::PORT_HANDLE devGetPort(gc::DEV_HANDLE devh) {
            gc::PORT_HANDLE ph;
            chk(DevGetPort(devh, &ph));
            return ph;
        }
        uint32_t devGetNumDataStreams(gc::DEV_HANDLE devh) {
            uint32_t nds = 0;
            chk(DevGetNumDataStreams(devh, &nds));
            return nds;
        }
        std::string devGetDataStreamID(gc::DEV_HANDLE devh, uint32_t index) {
            return getString(CdevGetDataStreamID(devh, index));
        }
        gc::DS_HANDLE devOpenDataStream(gc::DEV_HANDLE devh, const std::string &dsID) {
            gc::DS_HANDLE dsh;
            chk(DevOpenDataStream(devh, dsID.c_str(), &dsh));
            return dsh;
        }
        void devClose(gc::DEV_HANDLE devh) {
            chk(DevClose(devh));
        }
        std::string devGetInfoString(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
            return infoString(CdevGetInfo(devh, cmd));
        }
        template <typename T> T devGetInfo(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
            return info<T, CdevGetInfo>(CdevGetInfo(devh, cmd));
        }
        // GenTL DataStream functions
        gc::BUFFER_HANDLE dsAnnounceBuffer(gc::DS_HANDLE dsh,
                                           void *buffer,
                                           size_t size,
                                           void *userPointer) {
            gc::BUFFER_HANDLE bh;
            chk(DSAnnounceBuffer(dsh, buffer, size, userPointer, &bh));
            return bh;
        }
        gc::BUFFER_HANDLE dsAllocAndAnnounceBuffer(gc::DS_HANDLE dsh, size_t size,
                                                   void *userPointer) {
            gc::BUFFER_HANDLE bh;
            chk(DSAllocAndAnnounceBuffer(dsh, size, userPointer, &bh));
            return bh;
        }
        gc::BUFFER_HANDLE dsAnnounceBusBuffer(gc::DS_HANDLE dsh,
                                              uint64_t busAddress,
                                              size_t size,
                                              void *userPointer) {
            gc::BUFFER_HANDLE bh;
            chk(EuresysDSAnnounceBusBuffer(dsh, busAddress, size, 0, userPointer, &bh));
            return bh;
        }
        void dsAllocAndAnnounceBuffers(gc::DS_HANDLE dsh, size_t size,
                                       std::vector<gc::BUFFER_HANDLE> &buffers) {
            size_t count = buffers.size();
            for (size_t i = 0; i < count; ++i) {
                buffers[i] = dsAllocAndAnnounceBuffer(dsh, size, 0);
            }
        }
        void dsFlushQueue(gc::DS_HANDLE dsh, gc::ACQ_QUEUE_TYPE operation) {
            chk(DSFlushQueue(dsh, operation));
        }
        void dsStartAcquisition(gc::DS_HANDLE dsh,
                                gc::ACQ_START_FLAGS flags,
                                uint64_t count) {
            chk(DSStartAcquisition(dsh, flags, count));
        }
        void dsStopAcquisition(gc::DS_HANDLE dsh,
                               gc::ACQ_STOP_FLAGS flags) {
            chk(DSStopAcquisition(dsh, flags));
        }
        void dsClose(gc::DS_HANDLE dsh){
            chk(DSClose(dsh));
        }
        std::string dsGetInfoString(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
            return infoString(CdsGetInfo(dsh, cmd));
        }
        template <typename T> T dsGetInfo(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
            return info<T, CdsGetInfo>(CdsGetInfo(dsh, cmd));
        }
        gc::BUFFER_HANDLE dsGetBufferID(gc::DS_HANDLE dsh, uint32_t index) {
            gc::BUFFER_HANDLE h;
            chk(DSGetBufferID(dsh, index, &h));
            return h;
        }
        void dsRevokeBuffer(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh,
                            void **buffer, void **userPointer) {
            chk(DSRevokeBuffer(dsh, bh, buffer, userPointer));
        }
        void dsRevokeBuffers(gc::DS_HANDLE dsh, std::vector<gc::BUFFER_HANDLE> &buffers) {
            size_t count = buffers.size();
            for (size_t i = 0; i < count; ++i) {
                if (buffers.at(i) != GENTL_INVALID_HANDLE) {
                    dsRevokeBuffer(dsh, buffers.at(i), 0, 0);
                    buffers[i] = GENTL_INVALID_HANDLE;
                }
            }
        }
        void dsQueueBuffer(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh) {
            chk(DSQueueBuffer(dsh, bh));
        }
        void dsQueueBuffers(gc::DS_HANDLE dsh,
                            const std::vector<gc::BUFFER_HANDLE> &buffers) {
            size_t count = buffers.size();
            for (size_t i = 0; i < count; ++i) {
                if (buffers.at(i) != GENTL_INVALID_HANDLE) {
                    dsQueueBuffer(dsh, buffers.at(i));
                }
            }
        }
        std::string dsGetBufferInfoString(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh,
                                          gc::BUFFER_INFO_CMD cmd) {
            return infoString(CdsGetBufferInfo(dsh, bh, cmd));
        }
        template <typename T> T dsGetBufferInfo(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh,
                                                gc::BUFFER_INFO_CMD cmd) {
            return info<T, CdsGetBufferInfo>(CdsGetBufferInfo(dsh, bh, cmd));
        }
        uint32_t gcGetNumPortURLs(gc::PORT_HANDLE h) {
            uint32_t n;
            chk(GCGetNumPortURLs(h, &n));
            return n;
        }
        std::string gcGetPortURLInfoString(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
            return infoString(CgcGetPortURLInfo(h, index, cmd));
        }
        template <typename T> T gcGetPortURLInfo(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
            return info<T, CgcGetPortURLInfo>(CgcGetPortURLInfo(h, index, cmd));
        }
        void gcReadPortStacked(gc::PORT_HANDLE h, std::vector<gc::PORT_REGISTER_STACK_ENTRY> &entries) {
            if (!entries.empty()) {
                size_t num = entries.size();
                gc::GC_ERROR err = GCReadPortStacked(h, &entries[0], &num);
                entries.resize(num);
                chk(err);
            }
        }
        void gcWritePortStacked(gc::PORT_HANDLE h, std::vector<gc::PORT_REGISTER_STACK_ENTRY> &entries) {
            if (!entries.empty()) {
                size_t num = entries.size();
                gc::GC_ERROR err = GCWritePortStacked(h, &entries[0], &num);
                entries.resize(num);
                chk(err);
            }
        }
        gc::TL_HANDLE ifGetParent(gc::IF_HANDLE ifh) {
            gc::TL_HANDLE h;
            chk(IFGetParentTL(ifh, &h));
            return h;
        }
        gc::IF_HANDLE devGetParent(gc::DEV_HANDLE devh) {
            gc::IF_HANDLE h;
            chk(DevGetParentIF(devh, &h));
            return h;
        }
        gc::DEV_HANDLE dsGetParent(gc::DS_HANDLE dsh) {
            gc::DEV_HANDLE h;
            chk(DSGetParentDev(dsh, &h));
            return h;
        }
        // Euresys Memento functions
        void memento(const std::string &text) {
            MementoOutputString(text.c_str());
        }
        void memento(unsigned char verbosity, unsigned char kind, const std::string &text) {
            MementoOutputStringEx(text.c_str(), verbosity, kind);
        }
        // Euresys Genapi functions
        void genapiSetString(gc::PORT_HANDLE h, const std::string &feature, const std::string &value) {
            chk(GenapiSetString(h, feature.c_str(), value.c_str()));
        }
        std::string genapiGetString(gc::PORT_HANDLE h, const std::string &feature) {
            return getString(CgenapiGetString(h, feature.c_str()));
        }
        std::vector<std::string> genapiGetStringList(gc::PORT_HANDLE h, const std::string &what) {
            std::string fs = genapiGetString(h, what);
            return split(fs);
        }
        void genapiSetInteger(gc::PORT_HANDLE h, const std::string &feature, int64_t value)  {
            chk(GenapiSetInteger(h, feature.c_str(), value));
        }
        int64_t genapiGetInteger(gc::PORT_HANDLE h, const std::string &feature)  {
            int64_t value = 0;
            chk(GenapiGetInteger(h, feature.c_str(), &value));
            return value;
        }
        int64_t genapiGetIntegerWithDefault(gc::PORT_HANDLE h,
                                            const std::string &feature,
                                            int64_t defaultValue) {
            int64_t value = 0;
            if (chkCatch<ge::GC_ERR_CUSTOM_GENAPI_ERROR>(GenapiGetInteger(h, feature.c_str(), &value))) {
                return defaultValue;
            }
            return value;
        }
        void genapiSetFloat(gc::PORT_HANDLE h, const std::string &feature,
                            double value) {
            chk(GenapiSetFloat(h, feature.c_str(), value));
        }
        double genapiGetFloat(gc::PORT_HANDLE h, const std::string &feature) {
            double value = 0;
            chk(GenapiGetFloat(h, feature.c_str(), &value));
            return value;
        }
        double genapiGetFloatWithDefault(gc::PORT_HANDLE h,
                                         const std::string &feature,
                                         double defaultValue) {
            double value = 0;
            if (chkCatch<ge::GC_ERR_CUSTOM_GENAPI_ERROR>(GenapiGetFloat(h, feature.c_str(), &value))) {
                return defaultValue;
            }
            return value;
        }
        void genapiExecuteCommand(gc::PORT_HANDLE h, const std::string &feature)  {
            chk(GenapiExecuteCommand(h, feature.c_str()));
        }
        void genapiRunScript(gc::PORT_HANDLE h, const std::string &script) {
            chk(GenapiRunScript(&h, 1, script.c_str(), 0, 0));
        }
#ifdef EURESYS_USE_BAYER_DEPRECATED_API
        void bayerConvert(ge::BAYER_METHOD method,
                          ge::PIXEL_FORMAT in_format, int in_width, int in_height, const void *in_pixels,
                          ge::PIXEL_FORMAT out_format, int out_width, int out_height, void *out_pixels,
                          const ge::ROI_DETAILS *roi_details,
                          void *reserved) {
            chk(BayerConvert(method, in_format, in_width, in_height, in_pixels,
                             out_format, out_width, out_height, out_pixels,
                             roi_details, reserved));
        }
#endif
        unsigned int imageGetPixelFormatValue(const std::string &format, unsigned int ns) {
            unsigned int value = 0;
            chk(ImageGetPixelFormatValue(format.c_str(), ns, &value));
            return value;
        }
        std::string imageGetPixelFormat(uint64_t value) {
            return getString(CimageGetPixelFormat(value));
        }
        unsigned int imageGetBytesPerPixel(const std::string &format) {
            unsigned int value = 0;
            chk(ImageGetBytesPerPixel(format.c_str(), &value));
            return value;
        }
        void imageConvert(const ge::ImageConvertInput &input, const ge::ImageConvertOutput &output, const ge::ImageConvertROI *roi) {
            chk(ImageConvert(&input, &output, roi));
        }
        void imageSaveToDisk(const ge::ImageConvertInput &input, const std::string &filepath, int64_t index, const ge::ImageSaveToDiskParams *params) {
            chk(ImageSaveToDisk(&input, filepath.c_str(), index, params));
        }

        void chk(gc::GC_ERROR e) {
            if (e != gc::GC_ERR_SUCCESS) {
                gc::GC_ERROR error;
                std::vector<char> data(256);
                size_t size = data.size();
                switch (GCGetLastError(&error, &data[0], &size)) {
                    case gc::GC_ERR_SUCCESS:
                    case gc::GC_ERR_BUFFER_TOO_SMALL:
                        throw gentl_error(error, toString(data, size));
                    default:
                        throw gentl_error(e);
                }
            }
        }
        template <gc::GC_ERROR ERR>
        bool chkCatch(gc::GC_ERROR e) {
            if (e == ERR) {
                return true;
            }
            chk(e);
            return false;
        }
        std::string toString(const std::vector<char> &data, size_t size) {
            if ((!size) || (data.empty())) {
                return std::string();
            }
            // trim trailing NULL characters
            while (size && !data[size - 1]) {
                --size;
            }
            return std::string(&data[0], size);
        }
        class CgcGetInfo {
            public:
                CgcGetInfo(gc::TL_INFO_CMD cmd)
                : cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.GCGetInfo(cmd, type, buffer, size);
                }
            private:
                gc::TL_INFO_CMD cmd;
        };
        class CgcGetPortURL {
            public:
                CgcGetPortURL(gc::PORT_HANDLE ph)
                : ph(ph)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, char *str, size_t *size) const {
                    return gentl.GCGetPortURL(ph, str, size);
                }
            private:
                gc::PORT_HANDLE ph;
        };
        class CgcGetPortInfo {
            public:
                CgcGetPortInfo(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd)
                : ph(ph)
                , cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.GCGetPortInfo(ph, cmd, type, buffer, size);
                }
            private:
                gc::PORT_HANDLE ph;
                gc::PORT_INFO_CMD cmd;
        };
        class CeventGetDataInfo {
            public:
                CeventGetDataInfo(gc::EVENT_HANDLE eh,
                                  const void *in_buffer, size_t in_size,
                                  gc::EVENT_DATA_INFO_CMD cmd)
                : eh(eh)
                , in_buffer(in_buffer)
                , in_size(in_size)
                , cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.EventGetDataInfo(eh, in_buffer, in_size, cmd, type, buffer, size);
                }
            private:
                gc::EVENT_HANDLE eh;
                const void *in_buffer;
                size_t in_size;
                gc::EVENT_DATA_INFO_CMD cmd;
        };
        class CeventGetInfo {
            public:
                CeventGetInfo(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd)
                : eh(eh)
                , cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.EventGetInfo(eh, cmd, type, buffer, size);
                }
            private:
                gc::EVENT_HANDLE eh;
                gc::EVENT_INFO_CMD cmd;
        };
        class CtlGetInfo {
            public:
                CtlGetInfo(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd)
                : tlh(tlh)
                , cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.TLGetInfo(tlh, cmd, type, buffer, size);
                }
            private:
                gc::TL_HANDLE tlh;
                gc::TL_INFO_CMD cmd;
        };
        class CtlGetInterfaceInfo {
            public:
                CtlGetInterfaceInfo(gc::TL_HANDLE tlh, const std::string &ifID, gc::TL_INFO_CMD cmd)
                : tlh(tlh)
                , ifID(ifID)
                , cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.TLGetInterfaceInfo(tlh, ifID.c_str(), cmd, type, buffer, size);
                }
            private:
                gc::TL_HANDLE tlh;
                std::string ifID;
                gc::TL_INFO_CMD cmd;
        };
        class CifGetInfo {
            public:
                CifGetInfo(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd)
                : ifh(ifh)
                , cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.IFGetInfo(ifh, cmd, type, buffer, size);
                }
            private:
                gc::IF_HANDLE ifh;
                gc::INTERFACE_INFO_CMD cmd;
        };
        class CifGetDeviceInfo {
            public:
                CifGetDeviceInfo(gc::IF_HANDLE ifh, const std::string &devID, gc::INTERFACE_INFO_CMD cmd)
                : ifh(ifh)
                , devID(devID)
                , cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.IFGetDeviceInfo(ifh, devID.c_str(), cmd, type, buffer, size);
                }
            private:
                gc::IF_HANDLE ifh;
                std::string devID;
                gc::INTERFACE_INFO_CMD cmd;
        };
        class CdevGetInfo {
            public:
                CdevGetInfo(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd)
                : devh(devh)
                , cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.DevGetInfo(devh, cmd, type, buffer, size);
                }
            private:
                gc::DEV_HANDLE devh;
                gc::DEVICE_INFO_CMD cmd;
        };
        class CdsGetInfo {
            public:
                CdsGetInfo(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd)
                : dsh(dsh)
                , cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.DSGetInfo(dsh, cmd, type, buffer, size);
                }
            private:
                gc::DS_HANDLE dsh;
                gc::STREAM_INFO_CMD cmd;
        };
        class CgenapiGetString {
            public:
                CgenapiGetString(gc::PORT_HANDLE ph, const char *feature)
                : ph(ph)
                , feature(feature)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, char *str, size_t *size) const {
                    return gentl.GenapiGetString(ph, feature, str, size);
                }
            private:
                gc::PORT_HANDLE ph;
                const char *feature;
        };
        class CtlGetInterfaceID {
            public:
                CtlGetInterfaceID(gc::TL_HANDLE tlh, uint32_t index)
                : tlh(tlh)
                , index(index)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, char *str, size_t *size) const {
                    return gentl.TLGetInterfaceID(tlh, index, str, size);
                }
            private:
                gc::TL_HANDLE tlh;
                uint32_t index;
        };
        class CifGetDeviceID {
            public:
                CifGetDeviceID(gc::IF_HANDLE ifh, uint32_t index)
                : ifh(ifh)
                , index(index)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, char *str, size_t *size) const {
                    return gentl.IFGetDeviceID(ifh, index, str, size);
                }
            private:
                gc::IF_HANDLE ifh;
                uint32_t index;
        };
        class CdevGetDataStreamID {
            public:
                CdevGetDataStreamID(gc::DEV_HANDLE devh, uint32_t index)
                : devh(devh)
                , index(index)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, char *str, size_t *size) const {
                    return gentl.DevGetDataStreamID(devh, index, str, size);
                }
            private:
                gc::DEV_HANDLE devh;
                uint32_t index;
        };
        class CdsGetBufferInfo {
            public:
                CdsGetBufferInfo(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh,
                                 gc::BUFFER_INFO_CMD cmd)
                : dsh(dsh)
                , bh(bh)
                , cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.DSGetBufferInfo(dsh, bh, cmd, type, buffer, size);
                }
            private:
                gc::DS_HANDLE dsh;
                gc::BUFFER_HANDLE bh;
                gc::BUFFER_INFO_CMD cmd;
        };
        class CgcGetPortURLInfo {
            public:
                CgcGetPortURLInfo(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd)
                : h(h)
                , index(index)
                , cmd(cmd)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, gc::INFO_DATATYPE *type, void *buffer, size_t *size) const {
                    return gentl.GCGetPortURLInfo(h, index, cmd, type, buffer, size);
                }
            private:
                gc::PORT_HANDLE h;
                uint32_t index;
                gc::URL_INFO_CMD cmd;
        };
        class CimageGetPixelFormat {
            public:
                CimageGetPixelFormat(uint64_t value)
                : value(value)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, char *str, size_t *size) const {
                    return gentl.ImageGetPixelFormat(value, str, size);
                }
            private:
                uint64_t value;
        };
        template<typename CINFO>
        class CinfoString {
            public:
                CinfoString(const CINFO &info)
                : info(info)
                {}
                gc::GC_ERROR get(const GenTLImpl &gentl, char *str, size_t *size) const {
                    gc::INFO_DATATYPE type;
                    gc::GC_ERROR err = info.get(gentl, &type, str, size);
                    if (err == gc::GC_ERR_SUCCESS) {
                        if (type != gc::INFO_DATATYPE_STRING) {
                            throw unexpected_data_type(type);
                        }
                    }
                    return err;
                }
            private:
                const CINFO &info;
        };
        template<typename T, typename CINFO> T info(const CINFO &command) {
            if (isCommandInfo<T>((T *)0)) {
                return fromCommandInfo<T>(infoCommand<CINFO>(command));
            }
            else if (isInfoString<T>((T *)0)) {
                return fromString<T>(infoString<CINFO>(command));
            } else {
                return infoInteger<T, CINFO>(command);
            }
        }
        template<typename CINFO> CommandInfo infoCommand(const CINFO &command) {
            CommandInfo data;
            data.buffer.resize(8);
            data.size = data.buffer.size();
            if (chkCatch<gc::GC_ERR_BUFFER_TOO_SMALL>(command.get(*this, &data.type, &data.buffer[0], &data.size))) {
                chk(command.get(*this, &data.type, 0, &data.size));
                data.buffer.resize(data.size);
                chk(command.get(*this, &data.type, &data.buffer[0], &data.size));
            }
            return data;
        }
        template<typename CINFO> std::string infoString(const CINFO &command) {
            return getString(CinfoString<CINFO>(command));
        }
        template<typename T, typename CINFO> T infoInteger(const CINFO &command) {
            gc::INFO_DATATYPE type;
            T data;
            const size_t SIZE = sizeof(data);
            size_t size = SIZE;
            chk(command.get(*this, &type, &data, &size));
            switch (type) {
                case gc::INFO_DATATYPE_INT16:
                case gc::INFO_DATATYPE_UINT16:
                case gc::INFO_DATATYPE_INT32:
                case gc::INFO_DATATYPE_UINT32:
                case gc::INFO_DATATYPE_INT64:
                case gc::INFO_DATATYPE_UINT64:
                case gc::INFO_DATATYPE_FLOAT64:
                case gc::INFO_DATATYPE_PTR:
                case gc::INFO_DATATYPE_BOOL8:
                case gc::INFO_DATATYPE_SIZET:
                case gc::INFO_DATATYPE_PTRDIFF:
                    break;
                default:
                    throw unexpected_data_type(type);
            }
            if (size != SIZE) {
                throw unexpected_data_size(SIZE, size);
            }
            return data;
        }
        template<typename CSTR> std::string getString(const CSTR &str) {
            std::vector<char> data(DEFAULT_STR_SIZE);
            size_t size = data.size();
            if (chkCatch<gc::GC_ERR_BUFFER_TOO_SMALL>(str.get(*this, &data[0], &size))) {
                chk(str.get(*this, 0, &size));
                data.resize(size);
                chk(str.get(*this, &data[0], &size));
            }
            return toString(data, size);
        }

        static const size_t DEFAULT_STR_SIZE = 128;
};

} // namespace Internal

inline std::string Features(bool availableOnly) {
    if (availableOnly) {
        return "@!features";
    } else {
        return "@features";
    }
}
inline std::string RegexFeatures(const std::string &re, bool availableOnly) {
    return Features(availableOnly) + " =~ " + re;
}
inline std::string GlobFeatures(const std::string &glob, bool availableOnly) {
    return Features(availableOnly) + " =? " + glob;
}
inline std::string EnumEntries(const std::string &feature, bool availableOnly) {
    if (availableOnly) {
        return "@!ee " + feature;
    } else {
        return "@ee " + feature;
    }
}
inline std::string RegexEnumEntries(const std::string &feature, const std::string &re, bool availableOnly) {
    return EnumEntries(feature, availableOnly) + " =~ " + re;
}
inline std::string GlobEnumEntries(const std::string &feature, const std::string &glob, bool availableOnly) {
    return EnumEntries(feature, availableOnly) + " =? " + glob;
}

} // namespace EURESYS_NAMESPACE

#endif
