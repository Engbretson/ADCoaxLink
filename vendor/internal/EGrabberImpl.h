/* Copyright Euresys 2015 */

#ifndef EGRABBER_IMPL_HEADER_FILE
#define EGRABBER_IMPL_HEADER_FILE

#include "EventProcessor.h"

namespace EURESYS_NAMESPACE {
namespace Internal {

class EGrabberBase {
    public:
        virtual ~EGrabberBase() {}
        virtual GenTL &getGenTL() = 0;
};

template <typename M> struct ModuleInfo {
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    std::string getInfoString(GenTL &gentl, void *handle, int32_t cmd);
#endif
    template <typename T> T getInfo(GenTL &gentl, void *handle, int32_t cmd);
};
template <> struct ModuleInfo<SystemModule> {
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    std::string getInfoString(GenTL &gentl, void *handle, int32_t cmd) {
        return gentl.tlGetInfoString(handle, cmd);
    }
#endif
    template <typename T> T getInfo(GenTL &gentl, void *handle, int32_t cmd) {
        return gentl.tlGetInfo<T>(handle, cmd);
    }
};
template <> struct ModuleInfo<InterfaceModule> {
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    std::string getInfoString(GenTL &gentl, void *handle, int32_t cmd) {
        return gentl.ifGetInfoString(handle, cmd);
    }
#endif
    template <typename T> T getInfo(GenTL &gentl, void *handle, int32_t cmd) {
        return gentl.ifGetInfo<T>(handle, cmd);
    }
};
template <> struct ModuleInfo<DeviceModule> {
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    std::string getInfoString(GenTL &gentl, void *handle, int32_t cmd) {
        return gentl.devGetInfoString(handle, cmd);
    }
#endif
    template <typename T> T getInfo(GenTL &gentl, void *handle, int32_t cmd) {
        return gentl.devGetInfo<T>(handle, cmd);
    }
};
template <> struct ModuleInfo<StreamModule> {
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    std::string getInfoString(GenTL &gentl, void *handle, int32_t cmd) {
        return gentl.dsGetInfoString(handle, cmd);
    }
#endif
    template <typename T> T getInfo(GenTL &gentl, void *handle, int32_t cmd) {
        return gentl.dsGetInfo<T>(handle, cmd);
    }
};

template <typename CallbackModel> class EGrabberImpl {
    public:
        EGrabberImpl(GenTL &gentl, EGrabberCallbacks &callbacks, int interfaceIndex, int deviceIndex, int dataStreamIndex)
        : gentl(gentl)
        , eventProcessor(gentl, callbacks)
        , tlh(GENTL_INVALID_HANDLE)
        , ifh(GENTL_INVALID_HANDLE)
        , devh(GENTL_INVALID_HANDLE)
        , camh(GENTL_INVALID_HANDLE)
        , dsh(GENTL_INVALID_HANDLE)
        , eh_undefined(GENTL_INVALID_HANDLE)
        , eh_newbuffer(GENTL_INVALID_HANDLE)
        , eh_iotoolbox(GENTL_INVALID_HANDLE)
        , eh_cic(GENTL_INVALID_HANDLE)
        , eh_datastream(GENTL_INVALID_HANDLE)
        , eh_cxpinterface(GENTL_INVALID_HANDLE)
        , buffers(0)
        , externalHandles(false)
        , started(false)
        , cameraStarted(false)
        , isLineScan(false)
        {
            try {
                eventProcessor.start();
                tlh = gentl.tlOpen();
                gentl.tlUpdateInterfaceList(tlh);
                if (0 <= interfaceIndex) {
                    ifh = gentl.tlOpenInterface(tlh, gentl.tlGetInterfaceID(tlh, interfaceIndex));
                    gentl.ifUpdateDeviceList(ifh);
                    if (0 <= deviceIndex) {
                        devh = gentl.ifOpenDevice(ifh, gentl.ifGetDeviceID(ifh, deviceIndex));
                        camh = gentl.devGetPort(devh);
                        if (0 <= dataStreamIndex) {
                            dsh = gentl.devOpenDataStream(devh, gentl.devGetDataStreamID(devh, dataStreamIndex));
                            setup();
                        }
                    }
                }
            }
            catch (...)
            {
                shutdown();
                throw;
            }
        }

        EGrabberImpl(GenTL &gentl, EGrabberCallbacks &callbacks, gc::TL_HANDLE tlh, gc::IF_HANDLE ifh, gc::DEV_HANDLE devh, gc::DS_HANDLE dsh)
        : gentl(gentl)
        , eventProcessor(gentl, callbacks)
        , tlh(tlh)
        , ifh(ifh)
        , devh(devh)
        , camh(GENTL_INVALID_HANDLE)
        , dsh(dsh)
        , eh_undefined(GENTL_INVALID_HANDLE)
        , eh_newbuffer(GENTL_INVALID_HANDLE)
        , eh_iotoolbox(GENTL_INVALID_HANDLE)
        , eh_cic(GENTL_INVALID_HANDLE)
        , eh_datastream(GENTL_INVALID_HANDLE)
        , eh_cxpinterface(GENTL_INVALID_HANDLE)
        , buffers(0)
        , externalHandles(true)
        , started(false)
        , cameraStarted(false)
        , isLineScan(false)
        {
            try {
                eventProcessor.start();
                if (devh != GENTL_INVALID_HANDLE) {
                    camh = gentl.devGetPort(devh);
                }
                if (dsh != GENTL_INVALID_HANDLE) {
                    setup();
                }
            }
            catch (...)
            {
                shutdown();
                throw;
            }
        }

        virtual ~EGrabberImpl() {
            shutdown();
        }
        
    private:
        void setup() {
            isLineScan = 0 < gentl.genapiGetStringList(dsh, GlobFeatures("BufferHeight")).size();
            reallocBuffers(0, 0);
            enableEvent<NewBufferData>();
        }
    
        void shutdown() throw() {
            try {
                eventProcessor.configureMode(true);
            } catch (...) {
            }
            try {
                eventProcessor.stop();
            } catch (...) {
            }
            try {
                if (camh != GENTL_INVALID_HANDLE) {
                    gentl.genapiExecuteCommand(camh, "AcquisitionStop");
                    camh = GENTL_INVALID_HANDLE;
                }
            } catch (...) {
            }
            if (externalHandles) {
                try {
                    disableEvent<All>();
                } catch (...) {
                }
            } else {
                try {
                    if (devh != GENTL_INVALID_HANDLE) {
                        gentl.devClose(devh);
                        devh = GENTL_INVALID_HANDLE;
                    }
                } catch (...) {
                }
                try {
                    if (ifh != GENTL_INVALID_HANDLE) {
                        gentl.ifClose(ifh);
                        ifh = GENTL_INVALID_HANDLE;
                    }
                } catch (...) {
                }
                try {
                    if (tlh != GENTL_INVALID_HANDLE) {
                        gentl.tlClose(tlh);
                        tlh = GENTL_INVALID_HANDLE;
                    }
                } catch (...) {
                }
            }
        }

    public:
        void memento(const std::string &text) {
            gentl.memento(text);
        }
        void memento(unsigned char verbosity, unsigned char kind, const std::string &text) {
            gentl.memento(verbosity, kind, text);
        }

        GenTL &getGenTL() {
            return gentl;
        }

        BufferIndexRange reallocBuffers(size_t bufferCount, size_t bufferSize) {
            AutoLock lock(mutex);
            if (0 < bufferCount && bufferSize == 0) {
                bufferSize = getPayloadSize();
            }
            // revoke current buffers
            flushBuffers(gc::ACQ_QUEUE_ALL_DISCARD);
            gentl.dsRevokeBuffers(dsh, buffers);
            buffers.resize(bufferCount, GENTL_INVALID_HANDLE);
            // allocate and queue new buffers
            gentl.dsAllocAndAnnounceBuffers(dsh, bufferSize, buffers);
            gentl.dsQueueBuffers(dsh, buffers);
            return BufferIndexRange(0, buffers.size());
        }

        BufferIndexRange announceAndQueue(const GenTLMemory &memory) {
            AutoLock lock(mutex);
            size_t index = buffers.size();
            size_t bufferSize = (memory.bufferSize == 0) ? getPayloadSize() : memory.bufferSize;
            buffers.push_back(gentl.dsAllocAndAnnounceBuffer(dsh, bufferSize));
            gentl.dsQueueBuffer(dsh, buffers.back());
            return BufferIndexRange(index, buffers.size());
        }
        BufferIndexRange announceAndQueue(const UserMemory &memory) {
            AutoLock lock(mutex);
            size_t index = buffers.size();
            buffers.push_back(gentl.dsAnnounceBuffer(dsh, memory.base, memory.size, memory.userPointer));
            gentl.dsQueueBuffer(dsh, buffers.back());
            return BufferIndexRange(index, buffers.size());
        }
        BufferIndexRange announceAndQueue(const UserMemoryArray &memory) {
            if (!memory.bufferSize) {
                throw client_error("invalid argument");
            }
            AutoLock lock(mutex);
            size_t index = buffers.size();
            char *ptr = reinterpret_cast<char *>(memory.memory.base);
            size_t size = memory.memory.size;
            try {
                while (size) {
                    size_t s = memory.bufferSize;
                    if (s > size) {
                        s = size;
                    }
                    buffers.push_back(gentl.dsAnnounceBuffer(dsh, ptr, s, memory.memory.userPointer));
                    ptr += s;
                    size -= s;
                }
            }
            catch (...) {
                try {
                    revoke(BufferIndexRange(index, buffers.size()));
                }
                catch (...) {
                }
                throw;
            }
            for (size_t ix = index; ix < buffers.size(); ++ix) {
                gentl.dsQueueBuffer(dsh, buffers.at(ix));
            }
            return BufferIndexRange(index, buffers.size());
        }
        BufferIndexRange announceAndQueue(const BusMemory &memory) {
            AutoLock lock(mutex);
            size_t index = buffers.size();
            buffers.push_back(gentl.dsAnnounceBusBuffer(dsh, memory.busAddress, memory.size, memory.userPointer));
            gentl.dsQueueBuffer(dsh, buffers.back());
            return BufferIndexRange(index, buffers.size());
        }

#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
        size_t announceBuffer(void *ptr, size_t size, void *userPointer) {
            return announceAndQueue(UserMemory(ptr, size, userPointer)).begin;
        }
#endif

        size_t announceBusBuffer(uint64_t busAddress, size_t size, void *userPointer) {
            return announceAndQueue(BusMemory(busAddress, size, userPointer)).begin;
        }

        void flushBuffers(gc::ACQ_QUEUE_TYPE operation) {
            AutoLock lock(mutex);
            gentl.dsFlushQueue(dsh, operation);
            switch (operation) {
                case gc::ACQ_QUEUE_OUTPUT_DISCARD:
                case gc::ACQ_QUEUE_ALL_DISCARD:
                    flushEvent<NewBufferData>();
                    break;
                default:
                    break;
            }
        }

        void resetBufferQueue() {
            AutoLock lock(mutex);
            flushBuffers(gc::ACQ_QUEUE_ALL_DISCARD);
            gentl.dsQueueBuffers(dsh, buffers);
        }

        void revoke(const BufferIndexRange &range) {
            AutoLock lock(mutex);
            for (size_t ix = range.begin; ix < range.end; ++ix) {
                gc::BUFFER_HANDLE bh = buffers.at(ix);
                if (bh != GENTL_INVALID_HANDLE) {
                    gentl.dsRevokeBuffer(dsh, bh);
                    buffers[ix] = GENTL_INVALID_HANDLE;
                }
            }
            // trim buffers
            while (!buffers.empty() && buffers.back() == GENTL_INVALID_HANDLE) {
                buffers.pop_back();
            }
            // shrink to fit
            std::vector<gc::BUFFER_HANDLE>(buffers).swap(buffers);
        }

        void start(uint64_t frameCount) {
            AutoLock lock(mutex);
            if (!cameraStarted) {
                gentl.genapiExecuteCommand(camh, "AcquisitionStart");
                cameraStarted = true;
            }
            if (started) {
                gentl.dsStopAcquisition(dsh, gc::ACQ_STOP_FLAGS_KILL);
                started = false;
            }
            gentl.dsStartAcquisition(dsh, gc::ACQ_START_FLAGS_DEFAULT, frameCount);
            started = true;
        }

        void stop() {
            AutoLock lock(mutex);
            gentl.dsStopAcquisition(dsh, gc::ACQ_STOP_FLAGS_DEFAULT);
            started = false;
            gentl.genapiExecuteCommand(camh, "AcquisitionStop");
            cameraStarted = false;
        }

        NewBufferData pop(uint64_t timeout);

        void push(const NewBufferData &data) {
            gentl.dsQueueBuffer(data.dsh, data.bh);
        }

        size_t getWidth() {
            return static_cast<size_t>(gentl.genapiGetInteger(dsh, "Width"));
        }

        size_t getHeight() {
            return isLineScan
                ? static_cast<size_t>(gentl.genapiGetInteger(dsh, "BufferHeight"))
                : static_cast<size_t>(gentl.genapiGetInteger(dsh, "Height"));
        }

        size_t getPayloadSize() {
            return static_cast<size_t>(gentl.genapiGetInteger(dsh, "PayloadSize"));
        }

        std::string getPixelFormat() {
            return gentl.genapiGetString(dsh, "PixelFormat");
        }

#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
        template<typename M> std::string getInfoString(int32_t cmd) {
            return ModuleInfo<M>().getInfoString(gentl, getPort((M *)0), cmd);
        }
#endif

        template<typename M, typename T> T getInfo(int32_t cmd) {
            return ModuleInfo<M>().template getInfo<T>(gentl, getPort((M *)0), cmd);
        }

#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
        std::string getBufferInfoString(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
            AutoLock lock(mutex);
            return gentl.dsGetBufferInfoString(dsh, buffers.at(bufferIndex), cmd);
        }
#endif

        template<typename T> T getBufferInfo(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
            AutoLock lock(mutex);
            return gentl.dsGetBufferInfo<T>(dsh, buffers.at(bufferIndex), cmd);
        }

        template<typename M> int64_t getInteger(const std::string &feature) {
            return gentl.genapiGetInteger(getPort((M *)0), feature);
        }
        template<typename M> double getFloat(const std::string &feature) {
            return gentl.genapiGetFloat(getPort((M *)0), feature);
        }
        template<typename M> std::string getString(const std::string &feature) {
            return gentl.genapiGetString(getPort((M *)0), feature);
        }
        template<typename M> std::vector<std::string> getStringList(const std::string &what) {
            return gentl.genapiGetStringList(getPort((M *)0), what);
        }
        template<typename M> void setInteger(const std::string &feature, int64_t value) {
            gentl.genapiSetInteger(getPort((M *)0), feature, value);
        }
        template<typename M> void setFloat(const std::string &feature, double value) {
            gentl.genapiSetFloat(getPort((M *)0), feature, value);
        }
        template<typename M> void setString(const std::string &feature, const std::string &value) {
            gentl.genapiSetString(getPort((M *)0), feature, value);
        }
        template<typename M> void execute(const std::string &command) {
            gentl.genapiExecuteCommand(getPort((M *)0), command);
        }

        void runScript(const std::string &script) {
            gentl.genapiRunScript(dsh, script);
        }

        // Generic interface for event processing
        template <typename DATA> struct EventType {};
        template <typename DATA> void enableEvent() {
            AutoLock lock(mutex);
            try {
                eventProcessor.configureMode(true);
                doEnableEvent(EventType<DATA>());
                eventProcessor.configureMode(false);
            }
            catch (...) {
                eventProcessor.configureMode(false);
                throw;
            }
        }
        template <typename DATA> void disableEvent() {
            AutoLock lock(mutex);
            try {
                eventProcessor.configureMode(true);
                doDisableEvent(EventType<DATA>());
                eventProcessor.configureMode(false);
            }
            catch (...) {
                eventProcessor.configureMode(false);
                throw;
            }
        }
        template <typename DATA> void flushEvent() {
            AutoLock lock(mutex);
            doFlushEvent(EventType<DATA>());
        }
        template <typename DATA> size_t processEvent(uint64_t timeout) {
            return doProcessEvent(EventType<DATA>(), timeout);
        }
        size_t processEventFilter(size_t eventFilter, uint64_t timeout = GENTL_INFINITE) {
            return doProcessEventFilter(eventFilter, timeout);
        }
        template <typename DATA> void cancelEvent() {
            doCancelEvent(EventType<DATA>());
        }
        void cancelEventFilter(size_t eventFilter) {
            doCancelEventFilter(eventFilter);
        }

    private:
        // EventType<DATA> (generic implementation for enable, disable, flush, process and cancel)
        template <typename DATA> void doEnableEvent(EventType<DATA> tag) {
            if (*getEventHandlePtr(tag) == GENTL_INVALID_HANDLE) {
                *getEventHandlePtr(tag) = gentl.gcRegisterEvent(getEventSource(tag), getEventType(tag));
                eventProcessor.template enableEvent<DATA>(getEventSource(tag), *getEventHandlePtr(tag));
            }
        }
        template <typename DATA> void doDisableEvent(EventType<DATA> tag) {
            if (*getEventHandlePtr(tag) != GENTL_INVALID_HANDLE) {
                eventProcessor.template disableEvent<DATA>();
                gentl.gcUnregisterEvent(getEventSource(tag), getEventType(tag));
                *getEventHandlePtr(tag) = GENTL_INVALID_HANDLE;
            }
        }
        template <typename DATA> void doFlushEvent(EventType<DATA> tag) {
            if (*getEventHandlePtr(tag) != GENTL_INVALID_HANDLE) {
                eventProcessor.template flushEvent<DATA>(*getEventHandlePtr(tag));
            }
        }
        template <typename DATA> size_t doProcessEvent(EventType<DATA> tag, uint64_t timeout) {
            return doProcessEvent(EventType<OneOf<DATA> >(), timeout);
        }
        template <typename DATA> void doCancelEvent(EventType<DATA> tag) {
            doCancelEvent(EventType<OneOf<DATA> >());
        }
        // Generic implemenation for one event data type needs to access following event details
        template <typename DATA> gc::EVENTSRC_HANDLE getEventSource(EventType<DATA>);
        template <typename DATA> gc::EVENT_HANDLE *getEventHandlePtr(EventType<DATA>);
        template <typename DATA> gc::EVENT_TYPE getEventType(EventType<DATA>);

        // Event details for EventType<NewBufferData>
        gc::EVENTSRC_HANDLE getEventSource(EventType<NewBufferData>)  { return dsh; }
        gc::EVENT_HANDLE *getEventHandlePtr(EventType<NewBufferData>) { return &eh_newbuffer; }
        gc::EVENT_TYPE getEventType(EventType<NewBufferData>)         { return gc::EVENT_NEW_BUFFER; }
        // Event details for EventType<IoToolboxData>
        gc::EVENTSRC_HANDLE getEventSource(EventType<IoToolboxData>)  { return devh; }
        gc::EVENT_HANDLE *getEventHandlePtr(EventType<IoToolboxData>) { return &eh_iotoolbox; }
        gc::EVENT_TYPE getEventType(EventType<IoToolboxData>)         { return gc::Euresys::EVENT_CUSTOM_IO_TOOLBOX; }
        // Event details for EventType<CicData>
        gc::EVENTSRC_HANDLE getEventSource(EventType<CicData>)  { return devh; }
        gc::EVENT_HANDLE *getEventHandlePtr(EventType<CicData>) { return &eh_cic; }
        gc::EVENT_TYPE getEventType(EventType<CicData>)         { return gc::Euresys::EVENT_CUSTOM_CIC; }
        // Event details for EventType<DataStreamData>
        gc::EVENTSRC_HANDLE getEventSource(EventType<DataStreamData>)  { return dsh; }
        gc::EVENT_HANDLE *getEventHandlePtr(EventType<DataStreamData>) { return &eh_datastream; }
        gc::EVENT_TYPE getEventType(EventType<DataStreamData>)         { return gc::Euresys::EVENT_CUSTOM_DATASTREAM; }
        // Event details for EventType<CxpInterfaceData>
        gc::EVENTSRC_HANDLE getEventSource(EventType<CxpInterfaceData>)  { return devh; }
        gc::EVENT_HANDLE *getEventHandlePtr(EventType<CxpInterfaceData>) { return &eh_cxpinterface; }
        gc::EVENT_TYPE getEventType(EventType<CxpInterfaceData>)         { return gc::Euresys::EVENT_CUSTOM_CXP_INTERFACE; }
        // Event details for EventType<Undefined>
        gc::EVENTSRC_HANDLE getEventSource(EventType<Undefined>)  { return GENTL_INVALID_HANDLE; }
        gc::EVENT_HANDLE *getEventHandlePtr(EventType<Undefined>) { return &eh_undefined; }
        gc::EVENT_TYPE getEventType(EventType<Undefined>);

        // EventType<All> (only for enable, disable, flush)
        void doEnableEvent(EventType<All> tag) {
            enableEventAll<EventQueueCount::VALUE>(); 
        }
        void doDisableEvent(EventType<All> tag) {
            disableEventAll<EventQueueCount::VALUE>();
        }
        void doFlushEvent(EventType<All> tag) {
            flushEventAll<EventQueueCount::VALUE>();
        }
        template <int N> void enableEventAll() {
            enableEvent< typename EventQueueType<N-1>::TYPE >();
            enableEventAll<N-1>();
        }
        template <int N> void disableEventAll() {
            disableEvent< typename EventQueueType<N-1>::TYPE >();
            disableEventAll<N-1>();
        }
        template <int N> void flushEventAll() {
            flushEvent< typename EventQueueType<N-1>::TYPE >();
            flushEventAll<N-1>();
        }

        // EventType<Any> (only for processEvent and cancelEvent)
        typedef OneOf< typename EventQueueType<0>::TYPE,
                       typename EventQueueType<1>::TYPE,
                       typename EventQueueType<2>::TYPE,
                       typename EventQueueType<3>::TYPE,
                       typename EventQueueType<4>::TYPE > OneOfAll;
        size_t doProcessEvent(EventType<Any> tag, uint64_t timeout) {
            return doProcessEvent(EventType<OneOfAll>(), timeout);
        }
        void doCancelEvent(EventType<Any> tag) {
            doCancelEvent(EventType<OneOfAll>());
        }

        // EventType<OneOf> (only for processEvent and cancelEvent)
        template <typename D1, typename D2, typename D3, typename D4, typename D5>
        size_t filter() {
            return EventFilter<D1>::VALUE |
                   EventFilter<D2>::VALUE |
                   EventFilter<D3>::VALUE |
                   EventFilter<D4>::VALUE |
                   EventFilter<D5>::VALUE;
        }
        template <typename D1, typename D2, typename D3, typename D4, typename D5>
        size_t doProcessEvent(EventType<OneOf<D1, D2, D3, D4, D5> > tag, uint64_t timeout) {
            return doProcessEventFilter(filter<D1, D2, D3, D4, D5>(), timeout);
        }
        template <typename D1, typename D2, typename D3, typename D4, typename D5>
        void doCancelEvent(EventType<OneOf<D1, D2, D3, D4, D5> > tag) {
            doCancelEventFilter(filter<D1, D2, D3, D4, D5>());
        }
        
        size_t doProcessEventFilter(size_t eventFilter, uint64_t timeout) {
            return eventProcessor.popNotifyOneOf(eventFilter, timeout);
        }
        void doCancelEventFilter(size_t eventFilter) {
            eventProcessor.cancelNotifyOneOf(eventFilter);
        }
        
        template <typename DATA> DATA getEvent(uint64_t timeout) {
            return eventProcessor.template getEvent<DATA>(timeout);
        }

        gc::PORT_HANDLE getPort(SystemModule *) {
            return tlh;
        }
        gc::PORT_HANDLE getPort(InterfaceModule *) {
            return ifh;
        }
        gc::PORT_HANDLE getPort(DeviceModule *) {
            return devh;
        }
        gc::PORT_HANDLE getPort(StreamModule *) {
            return dsh;
        }
        gc::PORT_HANDLE getPort(RemoteModule *) {
            return camh;
        }

        size_t evalPixelSize(const std::string &pixelFormat) {
            return static_cast<size_t>(gentl.imageGetBytesPerPixel(pixelFormat));
        }

        size_t evalPayloadSize(size_t width, size_t height, const std::string &pixelFormat) {
            return width * height * evalPixelSize(pixelFormat);
        }

        ConcurrencyLock mutex;
        GenTL &gentl;
        EventProcessor<CallbackModel> eventProcessor;
        gc::TL_HANDLE tlh;
        gc::IF_HANDLE ifh;
        gc::DEV_HANDLE devh;
        gc::PORT_HANDLE camh;
        gc::DS_HANDLE dsh;
        gc::EVENT_HANDLE eh_undefined;
        gc::EVENT_HANDLE eh_newbuffer;
        gc::EVENT_HANDLE eh_iotoolbox;
        gc::EVENT_HANDLE eh_cic;
        gc::EVENT_HANDLE eh_datastream;
        gc::EVENT_HANDLE eh_cxpinterface;
        std::vector<gc::BUFFER_HANDLE> buffers;
        bool externalHandles;
        bool started;
        bool cameraStarted;
        bool isLineScan;
};

template <> inline NewBufferData EGrabberImpl<CallbackOnDemand>::pop(uint64_t timeout) {
    return getEvent<NewBufferData>(timeout);
}

template <> template <> inline void EGrabberImpl<CallbackOnDemand>::template enableEventAll<0>() {}
template <> template <> inline void EGrabberImpl<CallbackMultiThread>::template enableEventAll<0>() {}
template <> template <> inline void EGrabberImpl<CallbackSingleThread>::template enableEventAll<0>() {}

template <> template <> inline void EGrabberImpl<CallbackOnDemand>::template disableEventAll<0>() {}
template <> template <> inline void EGrabberImpl<CallbackMultiThread>::template disableEventAll<0>() {}
template <> template <> inline void EGrabberImpl<CallbackSingleThread>::template disableEventAll<0>() {}

template <> template <> inline void EGrabberImpl<CallbackOnDemand>::template flushEventAll<0>() {}
template <> template <> inline void EGrabberImpl<CallbackMultiThread>::template flushEventAll<0>() {}
template <> template <> inline void EGrabberImpl<CallbackSingleThread>::template flushEventAll<0>() {}

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
