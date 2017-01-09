/* Copyright Euresys 2015 */

#ifndef EVENTPROCESSORSINGLETHREAD_IMPL_HEADER_FILE
#define EVENTPROCESSORSINGLETHREAD_IMPL_HEADER_FILE

#include "EuresysGenericSequencer.h"

namespace EURESYS_NAMESPACE {
namespace Internal {

template <> class EventProcessor<CallbackSingleThread>: public Thread {
    public:
        EventProcessor(GenTL &gentl, EGrabberCallbacks &callbacks)
        : gentl(gentl)
        , sequencer(gentl, callbacks)
        , context("EventProcessor<CallbackSingleThread>: ")
        , doneWithPops(false)
        {}

        void start() {
            Thread::start();
            sequencer.start();
        }

        template <typename DATA> void enableEvent(gc::EVENTSRC_HANDLE eventSource, gc::EVENT_HANDLE handle) {
            sequencer.enableEvent<DATA>(eventSource, handle);
        }

        template <typename DATA> void disableEvent() {
            sequencer.disableEvent<DATA>();
        }

        template <typename DATA> void flushEvent(gc::EVENT_HANDLE handle) {
            sequencer.flushEvent<DATA>(handle);
        }

    private:
        virtual void onStop() {
            do {
                sequencer.cancel((size_t)-1);
                sleepMs(0);
            } while (!doneWithPops);
            sequencer.stop();
        }
        virtual void run(volatile bool &isStopping) {
            memento("is ready");
            try {
                while (!isStopping) {
                    try {
                        sequencer.popNotifyOneEvent((size_t)-1);
                    }
                    catch (const gentl_error& err) {
                        switch (err.gc_err) {
                            case gc::GC_ERR_INVALID_HANDLE: // unregistered
                            case gc::GC_ERR_ABORT: // cancel event before unregister
                                break;
                            default:
                                throw;
                        }
                    }
                }
                doneWithPops = true;
                memento(" stopped");
            }
            catch (const gentl_error& err) {
                doneWithPops = true;
                memento(context + " uncaught GenTL error: " + err.what());
                throw;
            }
            catch (const std::runtime_error& err) {
                doneWithPops = true;
                memento(context + " uncaught runtime error: " + err.what());
                throw;
            }
            catch (...) {
                doneWithPops = true;
                memento(context + " uncaught exception");
                throw;
            }
        }

        // Helpers
        void memento(const std::string &msg) {
            gentl.memento(context + msg);
        }
        
        GenTL &gentl;
        GenericSequencer sequencer;
        std::string context;
        volatile bool doneWithPops;
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
