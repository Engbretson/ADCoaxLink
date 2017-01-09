/* Copyright Euresys 2015 */

#ifndef EVENTPROCESSOR_IMPL_HEADER_FILE
#define EVENTPROCESSOR_IMPL_HEADER_FILE

namespace EURESYS_NAMESPACE {
namespace Internal {

template <typename T> struct EventQueueIndex        { /* enum { VALUE = index }; */ };
template <int I> struct EventQueueType              { /* typedef data TYPE; */ };

struct StartGettingEvent {
    int qIndex;
};

class EGrabberCallbacks {
    protected:
        virtual ~EGrabberCallbacks() {}
    public:
        virtual void onNewBufferEvent(const NewBufferData &data) = 0;
        virtual void onIoToolboxEvent(const IoToolboxData &data) = 0;
        virtual void onCicEvent(const CicData &data) = 0;
        virtual void onDataStreamEvent(const DataStreamData &data) = 0;
        virtual void onCxpInterfaceEvent(const CxpInterfaceData &data) = 0;
        virtual void onStartGettingEvent(const StartGettingEvent &info) {};
};

template <typename DATA> class EventNotifier {
    public:
        typedef char EVENT_DATA_TYPE; // dummy
        static std::string friendlyName();
        static void onData(GenTL *gentl, EGrabberCallbacks *callbacks,
                           gc::EVENTSRC_HANDLE eventSource,
                           gc::EVENT_HANDLE eh,
                           EVENT_DATA_TYPE &data, size_t size);
};

template <typename DATA>
inline void eventPopNotify(GenTL *gentl, EGrabberCallbacks *callbacks,
                           gc::EVENTSRC_HANDLE eventSource, gc::EVENT_HANDLE eventHandle,
                           uint64_t timeout) {
    typename EventNotifier<DATA>::EVENT_DATA_TYPE data;
    StartGettingEvent info = { EventQueueIndex<DATA>::VALUE };
    callbacks->onStartGettingEvent(info);
    size_t size = gentl->eventGetData(eventHandle, &data, sizeof(data), timeout);
    EventNotifier<DATA>::onData(gentl, callbacks, eventSource, eventHandle, data, size);
}

template <> class EventNotifier<NewBufferData> {
    public:
        typedef gc::EVENT_NEW_BUFFER_DATA EVENT_DATA_TYPE;
        static std::string friendlyName() { return "NewBuffer"; }
        static void onData(GenTL *gentl, EGrabberCallbacks *callbacks,
                           gc::EVENTSRC_HANDLE eventSource,
                           gc::EVENT_HANDLE eh,
                           gc::EVENT_NEW_BUFFER_DATA &data,
                           size_t size) {
            NewBufferData bd = {
                eventSource, data.BufferHandle, data.pUserPointer,
                gentl->dsGetBufferInfo<uint64_t>(eventSource, data.BufferHandle, gc::Euresys::BUFFER_INFO_CUSTOM_EVENT_TIMESTAMP)
            };
            callbacks->onNewBufferEvent(bd);
        }
};

struct CustomEventData {
    uint64_t data[8];
};

#define CREATE_CUSTOM_EVENT_NOTIFIER(DATA_TYPE_ARG) \
template <> class EventNotifier<DATA_TYPE_ARG##Data> { \
    public: \
        typedef CustomEventData EVENT_DATA_TYPE; \
        static std::string friendlyName() { return "Euresys Custom "#DATA_TYPE_ARG; } \
        static void onData(GenTL *gentl, EGrabberCallbacks *callbacks, \
                           gc::EVENTSRC_HANDLE eventSource, \
                           gc::EVENT_HANDLE eh, \
                           CustomEventData &data, \
                           size_t size) { \
            DATA_TYPE_ARG##Data d = { \
                static_cast<ge::EVENT_DATA_NUMID_CUSTOM>(gentl->eventGetDataInfo<uint64_t>(eh, &data, size, gc::EVENT_DATA_NUMID)), \
                gentl->eventGetDataInfo<uint64_t>(eh, &data, size, gc::Euresys::EVENT_DATA_CUSTOM_TIMESTAMP), \
                gentl->eventGetDataInfo<uint32_t>(eh, &data, size, gc::Euresys::EVENT_DATA_CUSTOM_CONTEXT_1), \
                gentl->eventGetDataInfo<uint32_t>(eh, &data, size, gc::Euresys::EVENT_DATA_CUSTOM_CONTEXT_2), \
                gentl->eventGetDataInfo<uint32_t>(eh, &data, size, gc::Euresys::EVENT_DATA_CUSTOM_CONTEXT_3) \
            }; \
            callbacks->on##DATA_TYPE_ARG##Event(d); \
        } \
}

CREATE_CUSTOM_EVENT_NOTIFIER(IoToolbox);
CREATE_CUSTOM_EVENT_NOTIFIER(Cic);
CREATE_CUSTOM_EVENT_NOTIFIER(DataStream);
CREATE_CUSTOM_EVENT_NOTIFIER(CxpInterface);

template <typename CallbackModel> class EventProcessor {
    public:
        void start();
        void stop();
        template <typename DATA> void enableEvent(gc::EVENTSRC_HANDLE eventSource, gc::EVENT_HANDLE handle);
        template <typename DATA> void disableEvent();
        template <typename DATA> void flushEvent(gc::EVENT_HANDLE handle);
};

template <> struct EventQueueIndex<NewBufferData>    { enum { VALUE = 0 }; };
template <> struct EventQueueIndex<IoToolboxData>    { enum { VALUE = 1 }; };
template <> struct EventQueueIndex<CicData>          { enum { VALUE = 2 }; };
template <> struct EventQueueIndex<DataStreamData>   { enum { VALUE = 3 }; };
template <> struct EventQueueIndex<CxpInterfaceData> { enum { VALUE = 4 }; };

struct             EventQueueCount                   { enum { VALUE = 5 }; };
template <> struct EventQueueIndex<Undefined>        { enum { VALUE = EventQueueCount::VALUE }; }; // -> index to ignore

template <> struct EventQueueType<0>                 { typedef NewBufferData    TYPE; };
template <> struct EventQueueType<1>                 { typedef IoToolboxData    TYPE; };
template <> struct EventQueueType<2>                 { typedef CicData          TYPE; };
template <> struct EventQueueType<3>                 { typedef DataStreamData   TYPE; };
template <> struct EventQueueType<4>                 { typedef CxpInterfaceData TYPE; };

template <typename U> void unused(const U &) {}
template <typename T> inline void checkEventQueueIndex() {
    // makes sure EventQueueCount::VALUE counts all queues
    typedef char static_check_count[((int)EventQueueIndex<T>::VALUE < (int)EventQueueCount::VALUE) ? 1 : -1];
    // makes sure EventQueueIndex<T>::VALUE == EventQueueType<VALUE>::TYPE
    typedef char static_check_types[((int)EventQueueIndex<T>::VALUE == (int)(EventQueueIndex<typename EventQueueType<EventQueueIndex<T>::VALUE>::TYPE>::VALUE)) ? 1 : -1];
    unused<static_check_count *>(0);
    unused<static_check_types *>(0);
}

template <typename T> struct EventFilter             { enum { VALUE = 1 << EventQueueIndex<T>::VALUE }; };
template <>           struct EventFilter<Undefined>  { enum { VALUE = 0 }; };
template <>           struct EventFilter<Any>        { enum { VALUE = -1 }; };

template <typename DATA> inline size_t getEventFilter() {
    return EventFilter<DATA>::VALUE;
}

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#include "EventProcessorOnDemand.h"
#include "EventProcessorMultiThread.h"
#include "EventProcessorSingleThread.h"

#endif
