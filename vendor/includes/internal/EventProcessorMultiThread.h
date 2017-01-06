/* Copyright Euresys 2015 */

#ifndef EVENTPROCESSORMULTITHREAD_IMPL_HEADER_FILE
#define EVENTPROCESSORMULTITHREAD_IMPL_HEADER_FILE

#include <map>

namespace EURESYS_NAMESPACE {
namespace Internal {

class EventThread: public Thread {
    public:
        EventThread()
        : gentl(0)
        , callbacks(0)
        , eventHandle(GENTL_INVALID_HANDLE)
        {}
        void start(GenTL *tl, EGrabberCallbacks *cbs, gc::EVENT_HANDLE eh) {
            gentl = tl;
            callbacks = cbs;
            eventHandle = eh;
            Thread::start();
        }
    protected:
        GenTL *gentl;
        EGrabberCallbacks *callbacks;
        gc::EVENT_HANDLE eventHandle;
};

template <typename DATA> class EventThreadFor: public EventThread {
    public:
        EventThreadFor(gc::EVENTSRC_HANDLE eventSource)
        : eventSource(eventSource)
        , doneWithPops(false)
        {}
        virtual void onStop() {
            do {
                gentl->eventKill(eventHandle);
                sleepMs(0);
            } while (!doneWithPops);
        }
        virtual void run(volatile bool &isStopping) {
            std::string context("EventThread for " + EventNotifier<DATA>::friendlyName() + ":");
            gentl->traceCtx.hTrace<'D',0x37d3494a6f3e40faULL,'s'>("%_ is listening for events", context);
            try {
                while (!isStopping) {
                    try {
                        eventPopNotify<DATA>(gentl, callbacks, eventSource, eventHandle, GENTL_INFINITE);
                    }
                    catch (const gentl_error& err) {
                        switch (err.gc_err) {
                            case gc::GC_ERR_INVALID_HANDLE: // unregistered
                            case gc::GC_ERR_ABORT: // cancel before unregister
                                goto leave;
                            default:
                                throw;
                        }
                    }
                }
            leave:
                doneWithPops = true;
                gentl->traceCtx.hTrace<'D',0x1bfe1e00f4eded28ULL,'s'>("%_ stopped", context);
            }
            catch (const gentl_error& err) {
                doneWithPops = true;
                gentl->traceCtx.hTrace<'E',0xb7ef01779cae09d8ULL,'s','s'>("%_ uncaught GenTL error: %_", context, err.what());
                throw;
            }
            catch (const std::runtime_error& err) {
                doneWithPops = true;
                gentl->traceCtx.hTrace<'E',0x5367105aa8ccb0d4ULL,'s','s'>("%_ uncaught runtime error: %_", context, err.what());
                throw;
            }
            catch (...) {
                doneWithPops = true;
                gentl->traceCtx.hTrace<'E',0x876a35135d65c30fULL,'s'>("%_ uncaught exception", context);
                throw;
            }
        }
    private:
        gc::EVENTSRC_HANDLE eventSource;
        volatile bool doneWithPops;
};

template <> class EventProcessor<CallbackMultiThread> {
    public:
        EventProcessor(GenTL &gentl, EGrabberCallbacks &callbacks)
        : gentl(gentl)
        , callbacks(callbacks)
        {
            for (int i = 0; i < Q_COUNT; ++i) {
                events[i] = 0;
            }
        }

        void start() {
        }

        void stop() {
            disableAll<Q_COUNT>();
        }
        
        void configureMode(bool enable) {
        }

        template <typename T>
        void enableEvent(gc::EVENTSRC_HANDLE eventSource, gc::EVENT_HANDLE handle) {
            checkEventQueueIndex<T>();
            AutoLock lock(mutex);
            if (!events[EventQueueIndex<T>::VALUE]) {
                events[EventQueueIndex<T>::VALUE] = new EventThreadFor<T>(eventSource);
                events[EventQueueIndex<T>::VALUE]->start(&gentl, &callbacks, handle);
            }
        }

        template <typename T> 
        void disableEvent() {
            checkEventQueueIndex<T>();
            disableEventI<EventQueueIndex<T>::VALUE>();
        }

        template <typename T> 
        void flushEvent(gc::EVENT_HANDLE handle) {
            gentl.eventFlush(handle);
        }

    private:
        template <int I> 
        void disableEventI() {
            AutoLock lock(mutex);
            EventThread *thread = events[I];
            if (thread) {
                if (thread->isCurrentThread()) {
                    throw client_error("Cannot disable current callback");
                }
                thread->stop();
                events[I] = 0;
                delete thread;
            }
        }

        template <int N> void disableAll() {
            try {
                disableEventI<N-1>();
            }
            catch (...) {
            }
            disableAll<N-1>();
        }

        ConcurrencyLock mutex;
        GenTL &gentl;
        EGrabberCallbacks &callbacks;
        static const int Q_COUNT = EventQueueCount::VALUE;
        EventThread *events[Q_COUNT];
};

template <> inline void EventProcessor<CallbackMultiThread>::disableAll<0>() {}

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
