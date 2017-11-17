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

template <typename DATA> static void eventNotifierShow(GenTL *gentl, const DATA &d);
template <typename DATA> static void eventNotifierEnter(GenTL *gentl, gc::EVENT_HANDLE eh, uint64_t timestamp);
template <typename DATA> static void eventNotifierLeave(GenTL *gentl, gc::EVENT_HANDLE eh);

template <> inline void eventNotifierShow<NewBufferData>(GenTL *gentl, const NewBufferData &d) {
    gentl->traceCtx.hTrace<'V',0xa0e35bd273f94246ULL,'p','p'>("NewBufferData { dsh, bh=%_, userPointer=%_, timestamp }", d.bh, d.userPointer);
}
template <> inline void eventNotifierEnter<NewBufferData>(GenTL *gentl, gc::EVENT_HANDLE eh, uint64_t timestamp) {
    gentl->traceCtx.hTrace<'D',0x9ffa42435a839019ULL, 'p','U'>("Entering onNewBufferEvent for hEvent = %_ (event data timestamp = %_)", eh, timestamp);
}
template <> inline void eventNotifierLeave<NewBufferData>(GenTL *gentl, gc::EVENT_HANDLE eh) {
    gentl->traceCtx.hTrace<'D',0x4edcfafb73b6a46cULL, 'p'>("Leaving onNewBufferEvent for hEvent = %_", eh);
}
template <> inline void eventNotifierShow<IoToolboxData>(GenTL *gentl, const IoToolboxData &d) {
    gentl->traceCtx.hTrace<'V',0x287620337c52e08bULL,'x','x','x','x'>("IoToolboxData { numid=0x%_, timestamp, context1=0x%_, context2=0x%_, context3=0x%_ }", (uint32_t)d.numid, d.context1, d.context2, d.context3);
}
template <> inline void eventNotifierEnter<IoToolboxData>(GenTL *gentl, gc::EVENT_HANDLE eh, uint64_t timestamp) {
    gentl->traceCtx.hTrace<'D',0xd3fed15290ddfde8ULL, 'p', 'U'>("Entering onIoToolboxEvent for hEvent = %_ (event data timestamp = %_)", eh, timestamp);
}
template <> inline void eventNotifierLeave<IoToolboxData>(GenTL *gentl, gc::EVENT_HANDLE eh) {
    gentl->traceCtx.hTrace<'D',0x2252f1c6848b8494ULL, 'p'>("Leaving onIoToolboxEvent for hEvent = %_", eh);
}
template <> inline void eventNotifierShow<CicData>(GenTL *gentl, const CicData &d) {
    gentl->traceCtx.hTrace<'V',0x4aeb6038764cdfc9ULL,'x','x','x','x'>("CicData { numid=0x%_, timestamp, context1=0x%_, context2=0x%_, context3=0x%_ }", (uint32_t)d.numid, d.context1, d.context2, d.context3);
}
template <> inline void eventNotifierEnter<CicData>(GenTL *gentl, gc::EVENT_HANDLE eh, uint64_t timestamp) {
    gentl->traceCtx.hTrace<'D',0xbefa446161b5f724ULL, 'p', 'U'>("Entering onCicEvent for hEvent = %_ (event data timestamp = %_)", eh, timestamp);
}
template <> inline void eventNotifierLeave<CicData>(GenTL *gentl, gc::EVENT_HANDLE eh) {
    gentl->traceCtx.hTrace<'D',0x30187f712b963806ULL, 'p'>("Leaving onCicEvent for hEvent = %_", eh);
}
template <> inline void eventNotifierShow<DataStreamData>(GenTL *gentl, const DataStreamData &d) {
    gentl->traceCtx.hTrace<'V',0xe2b5c5720725cb5bULL,'x','x','x','x'>("DataStreamData { numid=0x%_, timestamp, context1=0x%_, context2=0x%_, context3=0x%_ }", (uint32_t)d.numid, d.context1, d.context2, d.context3);
}
template <> inline void eventNotifierEnter<DataStreamData>(GenTL *gentl, gc::EVENT_HANDLE eh, uint64_t timestamp) {
    gentl->traceCtx.hTrace<'D',0x55da627c17f6bc67ULL, 'p', 'U'>("Entering onDataStreamEvent for hEvent = %_ (event data timestamp = %_)", eh, timestamp);
}
template <> inline void eventNotifierLeave<DataStreamData>(GenTL *gentl, gc::EVENT_HANDLE eh) {
    gentl->traceCtx.hTrace<'D',0x30cae9466283e184ULL, 'p'>("Leaving onDataStreamEvent for hEvent = %_", eh);
}
template <> inline void eventNotifierShow<CxpInterfaceData>(GenTL *gentl, const CxpInterfaceData &d) {
    gentl->traceCtx.hTrace<'V',0xe963f786585f25dbULL,'x','x','x','x'>("CxpInterfaceData { numid=0x%_, timestamp, context1=0x%_, context2=0x%_, context3=0x%_ }", (uint32_t)d.numid, d.context1, d.context2, d.context3);
}
template <> inline void eventNotifierEnter<CxpInterfaceData>(GenTL *gentl, gc::EVENT_HANDLE eh, uint64_t timestamp) {
    gentl->traceCtx.hTrace<'D',0x2dd96217a5727af5ULL, 'p', 'U'>("Entering onCxpInterfaceEvent for hEvent = %_ (event data timestamp = %_)", eh, timestamp);
}
template <> inline void eventNotifierLeave<CxpInterfaceData>(GenTL *gentl, gc::EVENT_HANDLE eh) {
    gentl->traceCtx.hTrace<'D',0x02f283b9e5db5111ULL, 'p'>("Leaving onCxpInterfaceEvent for hEvent = %_", eh);
}

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
            eventNotifierEnter<NewBufferData>(gentl, eh, bd.timestamp);
            eventNotifierShow<NewBufferData>(gentl, bd);
            callbacks->onNewBufferEvent(bd);
            eventNotifierLeave<NewBufferData>(gentl, eh);
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
            eventNotifierEnter<DATA_TYPE_ARG##Data>(gentl, eh, d.timestamp); \
            eventNotifierShow<DATA_TYPE_ARG##Data>(gentl, d); \
            callbacks->on##DATA_TYPE_ARG##Event(d); \
            eventNotifierLeave<DATA_TYPE_ARG##Data>(gentl, eh); \
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
        void configureMode(bool enable);
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

// ----------------------------------------------------------------------------
// Sequencer Event data wrappers
// ----------------------------------------------------------------------------

class EventBase {
    public:
        EventBase(uint64_t timestamp)
        : timestamp(timestamp)
        {}
        virtual ~EventBase() {}
        virtual void notify(GenTL &gentl) = 0;
        bool before(const EventBase &other) const {
            return timestamp < other.timestamp;
        }
    private:
        uint64_t timestamp;
};

template <typename T>
class Event: public EventBase {
    public:
        Event(EGrabberCallbacks &callbacks, const T &data)
        : EventBase(data.timestamp)
        , callbacks(callbacks)
        , data(data)
        {}
        virtual void notify(GenTL &);
        const T& get() {
            return data;
        }
    private:
        EGrabberCallbacks &callbacks;
        T data;
};

class EventPtr {
    public:
        EventPtr(EventBase *event)
        : event(event)
        {}
        ~EventPtr() {
            if (event) {
                delete event;
            }
        }
        EventBase *getEvent() {
            return event;
        }
        void notify(GenTL &gentl) {
            if (event) {
                event->notify(gentl);
            }
        }
        void detach() {
            event = 0;
        }
        template <typename DATA> const DATA &get() {
            Event<DATA> *eventDATA(dynamic_cast<Event<DATA> *>(event));
            if (!eventDATA) {
                throw client_error("EventPtr bad cast");
            }
            return eventDATA->get();
        }
    private:
        EventBase *event;
};

// ----------------------------------------------------------------------------
// Sequencer static configuration: add new data types here
// ----------------------------------------------------------------------------
template <> inline void Event<NewBufferData>::notify(GenTL &gentl) {
    gentl.traceCtx.hTrace<'I',0x4c28d986f8f27f1cULL>("Entering callback onNewBufferEvent(data)");
    callbacks.onNewBufferEvent(data);
    gentl.traceCtx.hTrace<'I',0x3e76249d56b15522ULL>("Leaving callback onNewBufferEvent(data)");
}
template <> inline void Event<IoToolboxData>::notify(GenTL &gentl) {
    gentl.traceCtx.hTrace<'I',0xd462b1620fa89d2dULL>("Entering callback onIoToolboxEvent(data)");
    callbacks.onIoToolboxEvent(data);
    gentl.traceCtx.hTrace<'I',0xfe5e111a7ee7416dULL>("Leaving callback onIoToolboxEvent(data)");
}
template <> inline void Event<CicData>::notify(GenTL &gentl) {
    gentl.traceCtx.hTrace<'I',0x58d8c1c9ffe80192ULL>("Entering callback onCicEvent(data)");
    callbacks.onCicEvent(data);
    gentl.traceCtx.hTrace<'I',0xe556efdce27527dcULL>("Leaving callback onCicEvent(data)");
}
template <> inline void Event<DataStreamData>::notify(GenTL &gentl) {
    gentl.traceCtx.hTrace<'I',0xa4b419b8e4a80490ULL>("Entering callback onDataStreamEvent(data)");
    callbacks.onDataStreamEvent(data);
    gentl.traceCtx.hTrace<'I',0xe4cb642fcebf0effULL>("Leaving callback onDataStreamEvent(data)");
}
template <> inline void Event<CxpInterfaceData>::notify(GenTL &gentl) {
    gentl.traceCtx.hTrace<'I',0x516ffd25af24504bULL>("Entering callback onCxpInterfaceEvent(data)");
    callbacks.onCxpInterfaceEvent(data);
    gentl.traceCtx.hTrace<'I',0xdb7cdedc982e9c50ULL>("Leaving callback onCxpInterfaceEvent(data)");
}

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#include "EventProcessorOnDemand.h"
#include "EventProcessorMultiThread.h"
#include "EventProcessorSingleThread.h"

#endif
