/* Copyright Euresys 2015 */

#ifndef EGENERICEVENTSEQUENCER_IMPL_HEADER_FILE
#define EGENERICEVENTSEQUENCER_IMPL_HEADER_FILE

#include <queue>
#include "EventProcessorMultiThread.h"
#include "EuresysGenericSequencerWaiter.h"

namespace EURESYS_NAMESPACE {
namespace Internal {

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4355 ) // 'this' : used in base member initializer list
#endif
class GenericSequencer: public EGrabberCallbacks {
    public:
        GenericSequencer(EGenTL &gentl, EGrabberCallbacks &callbacks)
        : gentl(gentl)
        , callbacks(callbacks)
        , multi(gentl, *this)
        , enabled(0)
        {
            for (int i = 0; i < Q_COUNT; ++i) {
                eventHandles[i] = GENTL_INVALID_HANDLE;
                events[i] = 0;
            }
        }

        void start() {
            multi.start();
        }

        void stop() {
            cancel((size_t)-1);
            multi.stop();
        }

        void configureMode(bool enable) {
        }

        template <typename DATA> void enableEvent(gc::EVENTSRC_HANDLE eventSource, gc::EVENT_HANDLE handle) {
            AutoLock lock(mutexEnable);
            setEventHandle<DATA>(handle);
            multi.enableEvent<DATA>(eventSource, handle);
        }

        template <typename DATA> void disableEvent() {
            AutoLock lock(mutexEnable);
            setEventHandle<DATA>(GENTL_INVALID_HANDLE);
            multi.disableEvent<DATA>();
        }

        template <typename DATA> void flushEvent(gc::EVENT_HANDLE handle) {
            checkEventQueueIndex<DATA>();
            AutoLock qlock(getQueueMutex<EventQueueIndex<DATA>::VALUE>());
            emptyQueue<EventQueueIndex<DATA>::VALUE>();
        }

        void popNotifyOneEvent(size_t filter = (size_t)-1, uint64_t timeout = GENTL_INFINITE) {
            EventBase* e;
            int waiter = allocWaiter(filter, timeout);
            if ((e = tryPopOne(filter))) {
                releaseWaiter(waiter);
                EventPtr event(e);
                event.notify(gentl);
                return;
            }
            EventPtr event(wait(filter, waiter));
            event.notify(gentl);
        }

        template <typename DATA> DATA getEvent(uint64_t timeout) {
            checkEventQueueIndex<DATA>();
            const size_t filter = 1 << EventQueueIndex<DATA>::VALUE;
            EventBase* e;
            int waiter = allocWaiter(filter, timeout);
            if ((e = tryPopOne(filter))) {
                releaseWaiter(waiter);
                EventPtr event(e);
                return event.get<DATA>();
            }
            EventPtr event(wait(filter, waiter));
            return event.get<DATA>();
        }

        // Cancel all popNotifyOneEvent that wait for any filtered events
        void cancel(size_t filter) {
            AutoLock lock(mutexWaiters);
            for (int i = 0; i < WAITER_COUNT; ++i) {
                waiters[i].cancel(filter);
            }
        }

        size_t getNumInQueues(size_t filter) {
            return getAllNumInQueues<Q_COUNT>(filter);
        }

    private:
        template <int N> size_t getAllNumInQueues(size_t filter) {
            size_t num = getAllNumInQueues<N-1>(filter);
            if (useQ<N-1>(filter)) {
                AutoLock lock(getQueueMutex<N-1>());
                num += getQueue<N-1>().size();
            }
            return num;
        }

        // Notify all popNotifyOneEvent that wait for any filtered events
        void notify(size_t filter) {
            AutoLock lock(mutexWaiters);
            for (int i = 0; i < WAITER_COUNT; ++i) {
                waiters[i].notify(filter);
            }
        }

        int allocWaiter(size_t filter, uint64_t timeout) {
            AutoLock lock(mutexWaiters);
            if (filter & (~enabled)) {
                gentl.traceCtx.hTrace<'D',0x7a223163effc8185ULL,'x','x'>("Sequencer prepare wait on filter 0x%_ including disabled events (enabled=0x%_)", (uint32_t)filter, (uint32_t)enabled);
            }
            for (int i = 0; i < WAITER_COUNT; ++i) {
                if (waiters[i].alloc(filter, timeout)) {
                    return i;
                }
            }
            throw client_error("Too many waiting contexts");
        }

        void releaseWaiter(int i) {
            AutoLock lock(mutexWaiters);
            waiters[i].release();
        }

        EventBase* wait(size_t filter, int waiter) {
            EventBase* e = 0;
            GenericSequencerWaiter::WaitResult r = GenericSequencerWaiter::NOTIFIED;
            while (r == GenericSequencerWaiter::NOTIFIED && e == 0) {
                r = waiters[waiter].wait();
                if (r == GenericSequencerWaiter::NOTIFIED) {
                    e = tryPopOne(filter);
                }
            }
            releaseWaiter(waiter);
            if (e) {
                return e;
            } else if (r == GenericSequencerWaiter::TIMEOUT) {
                throw gentl_error(gc::GC_ERR_TIMEOUT);
            } else /* if (r == GenericSequencerWaiter::CANCELLED) */ {
                throw gentl_error(gc::GC_ERR_ABORT);
            }
        }

        // Try and pop the oldest event from the filtered queues
        EventBase* tryPopOne(size_t filter) {
            AutoLock lock(mutexPop);
            if (!popAll(filter)) {
                int i = findOldest<Q_COUNT>(filter);
                if (i < Q_COUNT) {
                    EventBase* event = events[i];
                    events[i] = 0;
                    return event;
                }
            }
            return 0;
        }

        template <int N> bool useQ(size_t filter) {
            return (0 != ((filter) & (1 << (N))));
        }

        bool popAll(size_t filter) {
            return popAllDec<Q_COUNT>(filter) || popAllDec<Q_COUNT>(filter);
        }
        
        // Pop one event from each queue, returns true if there are pending events
        template <int N> bool popAllDec(size_t filter) {
            bool pending = false;
            {
                if (useQ<N-1>(filter) && !events[N-1]) {
                    events[N-1] = popEvent<N-1>(&pending);
                }
            }
            return popAllDec<N-1>(filter) || pending;
        }

        // Find oldest event from events array
        // Note: findOldest<N> returns N if there is no oldest events
        template <int N> int findOldest(size_t filter) {
            int oldest = findOldest<N-1>(filter);
            if (oldest == N-1) {
                // N-1 queues are empty, check current queue
                return (useQ<N-1>(filter) && events[N-1]) ? N-1 : N;
            } else if (useQ<N-1>(filter) && events[N-1]) {
                return (events[oldest]->before(*events[N-1])) ?
                            (oldest) : (N-1);
            } else {
                return oldest;
            }
        }

        template <int I> ConcurrencyLock &getQueueMutex() {
            return qMutex[I];
        }

        template <int I> std::queue<EventBase *> &getQueue() {
            return q[I];
        }

        template <int I> EventBase *popEvent(bool *pending) {
            AutoLock lock(getQueueMutex<I>());
            std::queue<EventBase *> &q(getQueue<I>());
            if (q.empty()) {
                if (checkPending<I>()) {
                    *pending = true;
                }
                return 0;
            } else {
                EventBase *e = q.front();
                q.pop();
                return e;
            }
        }

        template <int I> bool checkPending() {
            if (eventHandles[I] != GENTL_INVALID_HANDLE) {
                if (gentl.eventGetInfo<size_t>(eventHandles[I], gc::EVENT_NUM_IN_QUEUE)) {
                    return true;
                }
                if (getting[I]) {
                    uint64_t fired = gentl.eventGetInfo<uint64_t>(eventHandles[I], gc::EVENT_NUM_FIRED);
                    if (fired > queued[I] + numFired[I]) {
                        return true;
                    }
                }
            }
            return false;
        }

        template <int I> void emptyQueue() {
            std::queue<EventBase *> &q(getQueue<I>());
            while (!q.empty()) {
                EventPtr event(q.front());
                q.pop();
            }
        }

        template <typename T> void pushEvent(EventBase *event) {
            checkEventQueueIndex<T>();
            {
                AutoLock lock(getQueueMutex<EventQueueIndex<T>::VALUE>());
                getQueue<EventQueueIndex<T>::VALUE>().push(event);
                ++queued[EventQueueIndex<T>::VALUE];
                getting[EventQueueIndex<T>::VALUE] = false;
            }
            notify(1 << EventQueueIndex<T>::VALUE);
        }

        template <typename T> void push(const T &data) {
            EventPtr event(new Event<T>(callbacks, data));
            pushEvent<T>(event.getEvent());
            event.detach();
        }

        template <typename T> void setEventHandle(gc::EVENT_HANDLE eh) {
            checkEventQueueIndex<T>();
            AutoLock lock(getQueueMutex<EventQueueIndex<T>::VALUE>());
            eventHandles[EventQueueIndex<T>::VALUE] = eh;
            queued[EventQueueIndex<T>::VALUE] = 0;
            numFired[EventQueueIndex<T>::VALUE] = 0;
            getting[EventQueueIndex<T>::VALUE] = false;
            if (eh != GENTL_INVALID_HANDLE) {
                 // Event has been registered so EVENT_NUM_FIRED starts from 0
                emptyQueue<EventQueueIndex<T>::VALUE>();
                enabled |= 1 << EventQueueIndex<T>::VALUE;
                notify(1 << EventQueueIndex<T>::VALUE);
            } else {
                enabled &= ~(1 << EventQueueIndex<T>::VALUE);
                cancel(1 << EventQueueIndex<T>::VALUE);
            }
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
        
        void onStartGettingEvent(const StartGettingEvent &info) {
            if (0 <= info.qIndex && info.qIndex < Q_COUNT) {
                AutoLock lock(qMutex[info.qIndex]);
                if (eventHandles[info.qIndex] != GENTL_INVALID_HANDLE) {
                    // queued[ix] is the number of items pushed to the
                    // sequencer queue[ix] from now on
                    queued[info.qIndex] = 0;
                    // We get the number of fired items in the event queue
                    // (EVENT_NUM_FIRED) before getting the current number of
                    // items in the queue (EVENT_NUM_IN_QUEUE) because
                    // EVENT_NUM_FIRED can be underestimated while
                    // EVENT_NUM_IN_QUEUE cannot.
                    uint64_t fired = gentl.eventGetInfo<uint64_t>(eventHandles[info.qIndex], gc::EVENT_NUM_FIRED);
                    uint64_t numInQ = (uint64_t)gentl.eventGetInfo<size_t>(eventHandles[info.qIndex], gc::EVENT_NUM_IN_QUEUE);
                    // numFired[ix] is corrected by subtracting numInQ because
                    // numFired[ix] is the base value when queued[ix] == 0,
                    // see checkPending()
                    numFired[info.qIndex] = (fired > numInQ) ? (fired - numInQ) : 0;
                    getting[info.qIndex] = true;
                } else {
                    queued[info.qIndex] = 0;
                    numFired[info.qIndex] = 0;
                    getting[info.qIndex] = false;
                }
            }
        }

        static const int Q_COUNT = EventQueueCount::VALUE;
        static const int WAITER_COUNT = 10;
        
        ConcurrencyLock mutexWaiters;
        ConcurrencyLock mutexPop;
        ConcurrencyLock mutexEnable;
        EGenTL &gentl;
        EGrabberCallbacks &callbacks;
        EventProcessor<CallbackMultiThread> multi;
        ConcurrencyLock qMutex[Q_COUNT];
        std::queue<EventBase *> q[Q_COUNT];
        gc::EVENT_HANDLE eventHandles[Q_COUNT];
        EventBase *events[Q_COUNT];
        uint64_t queued[Q_COUNT];
        uint64_t numFired[Q_COUNT];
        bool getting[Q_COUNT];
        GenericSequencerWaiter waiters[WAITER_COUNT];
        size_t enabled;
};
#ifdef _MSC_VER
#pragma warning( pop )
#endif

// Note: gcc requires template specialization here (and not inside GenericSequencer class)
template <> inline bool GenericSequencer::popAllDec<0>(size_t filter) {
    return false;
}
template <> inline int GenericSequencer::findOldest<0>(size_t filter) {
    return 0;
}

template <> inline size_t GenericSequencer::getAllNumInQueues<0>(size_t filter) {
    return 0;
}

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
