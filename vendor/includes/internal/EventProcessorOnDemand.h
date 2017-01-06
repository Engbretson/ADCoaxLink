/* Copyright Euresys 2015 */

#ifndef EVENTPROCESSORONDEMAND_IMPL_HEADER_FILE
#define EVENTPROCESSORONDEMAND_IMPL_HEADER_FILE

#ifdef EURESYS_GENERIC_SEQUENCER
#include "EuresysGenericSequencer.h"
#else
#include "EuresysSequencer.h"
#endif

namespace EURESYS_NAMESPACE {
namespace Internal {

template <> class EventProcessor<CallbackOnDemand> {
    public:
        EventProcessor(GenTL &gentl, EGrabberCallbacks &callbacks)
        : sequencer(gentl, callbacks)
        {}

        void start() {
            sequencer.start();
        }

        void stop() {
            sequencer.stop();
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

        size_t popNotifyOneOf(size_t filter, uint64_t timeout) {
            sequencer.popNotifyOneEvent(filter, timeout);
            return sequencer.getNumInQueues(filter);
        }

        void cancelNotifyOneOf(size_t filter) {
            sequencer.cancel(filter);
        }

        template <typename DATA> DATA getEvent(uint64_t timeout) {
            return sequencer.getEvent<DATA>(timeout);
        }

    private:
#ifdef EURESYS_GENERIC_SEQUENCER
        GenericSequencer sequencer;
#else
        EuresysSequencer sequencer;
#endif
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
