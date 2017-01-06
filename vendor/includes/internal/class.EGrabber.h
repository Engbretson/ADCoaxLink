    protected:
        EGrabber(GenTL &gentl, gc::TL_HANDLE tlh, gc::IF_HANDLE ifh, gc::DEV_HANDLE devh, gc::DS_HANDLE dsh);
    public:
        // push a buffer back to the input queue manually
        // Note: prefer using ScopedBuffer or Buffer object
        void push(const NewBufferData &buffer);
        // dynamic version of processEvent<ANYDATA>
        // Note: this is an advanced usage, eventFilter is built by "or-ing"
        // event filters. E.g.
        // processEventFilter(getEventFilter<DATA1>() | getEventFilter<DATA2>())
        // Only available with CallbackOnDemand
        size_t processEventFilter(size_t eventFilter, uint64_t timeout);
        size_t processEventFilter(size_t eventFilter);
        // dynamic version of cancelEvent<ANYDATA>
        // Note: advanced usage, see processEventFilter
        // Only available with CallbackOnDemand
        void cancelEventFilter(size_t eventFilter);
        // announceBusBuffer performs the following operations:
        // - announce a bus-addressable buffer to the data stream
        // - queue the bus-addressable buffer to the data stream input fifo
        // - return value is the buffer index
        // Note: announceBusBuffer does not invalidate existing buffer indexes
        // Prefer announceAndQueue(BusMemory(busAddress, size, userPointer))
        //   over announceBusBuffer(busAddress, size, userPointer)
        size_t announceBusBuffer(uint64_t busAddress, size_t size, void *userPointer = 0);
