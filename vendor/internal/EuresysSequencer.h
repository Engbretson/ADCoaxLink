/* Copyright Euresys 2016 */

#ifndef EEURESYSEVENTSEQUENCER_IMPL_HEADER_FILE
#define EEURESYSEVENTSEQUENCER_IMPL_HEADER_FILE

namespace EURESYS_NAMESPACE {
namespace Internal {

class EuresysSequencer: public EGrabberCallbacks {
    public:
        EuresysSequencer(EGenTL &gentl, EGrabberCallbacks &callbacks)
        : gentl(gentl)
        , callbacks(callbacks)
        , configuring(0)
        , currentFilter(0)
        {
            for (int i = 0; i < Q_COUNT; ++i) {
                eventSources[i] = GENTL_INVALID_HANDLE;
                eventHandles[i] = GENTL_INVALID_HANDLE;
                heads[i] = 0;
            }

        }
        ~EuresysSequencer()
        {
            try {
                stop();
            }
            catch (...) {
            }
        }

        void start() {
        }

        void stop() {
            AutoLock lock(mutex);
            if (!configuring) {
                throw client_error("Not in configuration mode");
            }
            for (int i = 0; i < Q_COUNT; ++i) {
                eventSources[i] = GENTL_INVALID_HANDLE;
                eventHandles[i] = GENTL_INVALID_HANDLE;
                delete heads[i];
                heads[i] = 0;
            }
        }

        void configureMode(bool enable) {
            bool needsToCancel = false;
            if (enable) {
                AutoLock lock(mutex);
                needsToCancel = !configuring;
                ++configuring;
            } else {
                AutoLock lock(mutex);
                --configuring;
            }
            if (needsToCancel) {
                cancel((size_t)-1); // stop any pending popNotifyOneEvent as the configuration will change
            }
        }

        template <typename DATA> void enableEvent(gc::EVENTSRC_HANDLE eventSource, gc::EVENT_HANDLE handle) {
            checkEventQueueIndex<DATA>();
            AutoLock lock(mutex);
            if (!configuring) {
                throw client_error("Not in configuration mode");
            }
            delete heads[EventQueueIndex<DATA>::VALUE];
            heads[EventQueueIndex<DATA>::VALUE] = 0;
            eventSources[EventQueueIndex<DATA>::VALUE] = eventSource;
            eventHandles[EventQueueIndex<DATA>::VALUE] = handle;
        }

        template <typename DATA> void disableEvent() {
            checkEventQueueIndex<DATA>();
            AutoLock lock(mutex);
            if (!configuring) {
                throw client_error("Not in configuration mode");
            }
            delete heads[EventQueueIndex<DATA>::VALUE];
            heads[EventQueueIndex<DATA>::VALUE] = 0;
            eventSources[EventQueueIndex<DATA>::VALUE] = GENTL_INVALID_HANDLE;
            eventHandles[EventQueueIndex<DATA>::VALUE] = GENTL_INVALID_HANDLE;
        }

        template <typename DATA> void flushEvent(gc::EVENT_HANDLE handle) {
            checkEventQueueIndex<DATA>();
            AutoLock lock(mutex);
            delete heads[EventQueueIndex<DATA>::VALUE];
            heads[EventQueueIndex<DATA>::VALUE] = 0;
            gentl.eventFlush(handle);
        }

        void popNotifyOneEvent(size_t filter = (size_t)-1, uint64_t timeout = GENTL_INFINITE) {
            EventBase* e;
            {
                AutoLock lock(mutex);
                checkFilter(filter);
                currentFilter |= filter;
            }
            try {
                if ((e = tryPopOne(filter))) {
                    EventPtr event(e);
                    AutoLock lock(mutex);
                    currentFilter &= ~filter;
                    event.notify(gentl);
                } else {
                    EventPtr event(wait(filter, timeout));
                    AutoLock lock(mutex);
                    currentFilter &= ~filter;
                    event.notify(gentl);
                }
            }
            catch (...) {
                AutoLock lock(mutex);
                currentFilter &= ~filter;
                throw;
            }
        }

        template <typename DATA> DATA getEvent(uint64_t timeout) {
            checkEventQueueIndex<DATA>();
            const size_t filter = 1 << EventQueueIndex<DATA>::VALUE;
            EventBase* e;
            {
                AutoLock lock(mutex);
                checkFilter(filter);
                currentFilter |= filter;
            }
            try {
                if ((e = tryPopOne(filter))) {
                    EventPtr event(e);
                    AutoLock lock(mutex);
                    currentFilter &= ~filter;
                    return event.get<DATA>();
                }
                EventPtr event(wait(filter, timeout));
                AutoLock lock(mutex);
                currentFilter &= ~filter;
                return event.get<DATA>();
            }
            catch (...) {
                AutoLock lock(mutex);
                currentFilter &= ~filter;
                throw;
            }
        }

        // Cancel all popNotifyOneEvent that wait for any filtered events
        void cancel(size_t filter) {
            while (true) {
                AutoLock lock(mutex);
                if (filter & currentFilter) {
                    for (int i = 0; i < Q_COUNT; ++i) {
                        if (0 != (currentFilter & static_cast<size_t>(1ULL << i))) {
                            if (eventHandles[i] != GENTL_INVALID_HANDLE) {
                                try {
                                    gentl.eventKill(eventHandles[i]);
                                }
                                catch (...) {
                                }
                            }
                        }
                    }
                    Thread::sleepMs(0);
                } else {
                    return;
                }
            }
        }

        size_t getNumInQueues(size_t filter) {
            AutoLock lock(mutex);
            size_t num = 0;
            for (int i = 0; i < Q_COUNT; ++i) {
                if (0 != (filter & static_cast<size_t>(1ULL << i))) {
                    if (eventHandles[i] != GENTL_INVALID_HANDLE) {
                        num += gentl.eventGetInfo<size_t>(eventHandles[i], gc::EVENT_NUM_IN_QUEUE);
                    }
                    if (heads[i]) {
                        ++num;
                    }
                }
            }
            return num;
        }

    private:
        template <typename T> void push(const T &data) {
            heads[EventQueueIndex<T>::VALUE] = new Event<T>(callbacks, data);
        }

        // EGrabberCallbacks
        void onNewBufferEvent(const NewBufferData &data) {
            push(data);
        }
        void onIoToolboxEvent(const IoToolboxData &data) {
            push(data);
        }
        void onCicEvent(const CicData &data) {
            push(data);
        }
        void onDataStreamEvent(const DataStreamData &data) {
            push(data);
        }
        void onCxpInterfaceEvent(const CxpInterfaceData &data) {
            push(data);
        }

        void checkFilter(size_t filter) {
            if (filter & currentFilter) {
                throw client_error("EGrabber is busy in another thread");
            }
            for (int i = 0; i < Q_COUNT; ++i) {
                if (0 != (filter & static_cast<size_t>(1ULL << i))) {
                    if (eventHandles[i] != GENTL_INVALID_HANDLE) {
                        return;
                    }
                }
            }
            throw client_error("EGrabber has no registered event for this filter");
        }
        
        template <int N> void getHeads(size_t filter,
                                       std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY> &entries,
                                       uint64_t *timeout) {
            ge::EURESYS_EVENT_GET_DATA_ENTRY entry = { GENTL_INVALID_HANDLE, 0, 0, false };
            if (0 != (filter & static_cast<size_t>(1 << (N - 1)))) {
                AutoLock lock(mutex);
                if ((heads[N - 1] == 0) && (eventHandles[N - 1] != GENTL_INVALID_HANDLE)) {
                    entry.hEvent = eventHandles[N - 1];
                }
            }
            if (entry.hEvent == GENTL_INVALID_HANDLE) {
                getHeads<N - 1>(filter, entries, timeout);
            } else {
                typename EventNotifier<typename EventQueueType<N - 1>::TYPE>::EVENT_DATA_TYPE data;
                entry.pBuffer = &data;
                size_t dataSize = sizeof(data);
                entry.piSize = &dataSize;
                size_t ix = entries.size();
                entries.push_back(entry);
                getHeads<N - 1>(filter, entries, timeout);
                if (entries[ix].bGotData) {
                    AutoLock lock(mutex);
                    EventNotifier<typename EventQueueType<N - 1>::TYPE>::onData(&gentl, this, eventSources[N - 1], eventHandles[N - 1], data, dataSize);
                }
            }
        }

        void updateHeads(size_t filter, uint64_t *timeout) {
            std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY> entries;
            return getHeads<Q_COUNT>(filter, entries, timeout);
        }

        EventBase* getOldestHead(size_t filter) {
            AutoLock lock(mutex);
            int oldest = -1;
            for (int i = 0; i < Q_COUNT; ++i) {
                if (0 != (filter & static_cast<size_t>(1ULL << i))) {
                    if (heads[i]) {
                        if (oldest == -1) {
                            oldest = i;
                        } else if (heads[i]->before(*heads[oldest])) {
                            oldest = i;
                        }
                    }
                }
            }
            if (oldest != -1) {
                EventBase* event = heads[oldest];
                heads[oldest] = 0;
                return event;
            }
            return 0;
        }

        // Try and pop the oldest event from the filtered queues
        EventBase* tryPopOne(size_t filter) {
            updateHeads(filter, 0);
            return getOldestHead(filter);
        }

        EventBase* wait(size_t filter, uint64_t timeout) {
            updateHeads(filter, &timeout);
            EventBase* e = getOldestHead(filter);
            if (!e) {
                // should not happen
                gentl.traceCtx.hTrace<'E',0x9f5b5fd182f38342ULL>("EuresysSequencer client_error: EGrabber got no event data");
                throw client_error("EGrabber got no event data");
            }
            return e;
        }

        static const int Q_COUNT = EventQueueCount::VALUE;
        
        EGenTL &gentl;
        EGrabberCallbacks &callbacks;
        ConcurrencyLock mutex;
        size_t configuring;
        size_t currentFilter;
        gc::EVENTSRC_HANDLE eventSources[Q_COUNT];
        gc::EVENT_HANDLE eventHandles[Q_COUNT];
        EventBase *heads[Q_COUNT];
};

template <> inline void EuresysSequencer::getHeads<0>(size_t filter,
                                                      std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY> &entries,
                                                      uint64_t *timeout) {
    {
        AutoLock lock(mutex);
        if (configuring) {
            gentl.traceCtx.hTrace<'D',0x806b5b64950ac43dULL>("EuresysSequencer client_error: EGrabber is reconfiguring");
            throw client_error("EGrabber is reconfiguring");
        }
    }
    if (!entries.empty()) {
        gentl.eventsGetData(entries, timeout);
    }
}

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
