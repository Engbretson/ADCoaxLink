/* Copyright Euresys 2015 */

#ifndef EVENTPROCESSORSINGLETHREAD_IMPL_HEADER_FILE
#define EVENTPROCESSORSINGLETHREAD_IMPL_HEADER_FILE

#ifdef EURESYS_GENERIC_SEQUENCER
#include "EuresysGenericSequencer.h"
#else
#include "EuresysSequencer.h"
#endif

namespace EURESYS_NAMESPACE {
namespace Internal {

template <> class EventProcessor<CallbackSingleThread>: public Thread {
    public:
        EventProcessor(GenTL &gentl, EGrabberCallbacks &callbacks)
        : gentl(gentl)
        , sequencer(gentl, callbacks)
        , doneWithPops(false)
        {}

        void start() {
            Thread::start();
            sequencer.start();
        }

        void configureMode(bool enable) {
            sequencer.configureMode(enable);
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
            std::string context("EventProcessor<CallbackSingleThread>:");
            gentl.traceCtx.hTrace<'D',0xf86919c71a0dc09bULL,'s'>("%_ is ready", context);
            try {
                while (!isStopping) {
                    try {
                        sequencer.popNotifyOneEvent((size_t)-1);
                    }
                    catch (const client_error&) {
                        sleepMs(10); // the sequencer has no registered event ...
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
                gentl.traceCtx.hTrace<'D',0x1bfe1e00f4eded28ULL,'s'>("%_ stopped", context);
            }
            catch (const gentl_error& err) {
                doneWithPops = true;
                gentl.traceCtx.hTrace<'E',0xb7ef01779cae09d8ULL,'s','s'>("%_ uncaught GenTL error: %_", context, err.what());
                throw;
            }
            catch (const std::runtime_error& err) {
                doneWithPops = true;
                gentl.traceCtx.hTrace<'E',0x5367105aa8ccb0d4ULL,'s','s'>("%_ uncaught runtime error: %_", context, err.what());
                throw;
            }
            catch (...) {
                doneWithPops = true;
                gentl.traceCtx.hTrace<'E',0x876a35135d65c30fULL,'s'>("%_ uncaught exception", context);
                throw;
            }
        }

        GenTL &gentl;
#ifdef EURESYS_GENERIC_SEQUENCER
        GenericSequencer sequencer;
#else
        EuresysSequencer sequencer;
#endif
        volatile bool doneWithPops;
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
