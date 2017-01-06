#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    public:
        // announceBuffer performs the following operations:
        // - announce the user-allocated buffer to the data stream
        // - queue the user-allocated buffer to the data stream input fifo
        // - return value is the buffer index
        // Note: announceBuffer does not invalidate existing buffer indexes
        size_t announceBuffer(void *ptr, size_t size, void *userPointer = 0);

        template <typename M> std::string getInfoString(int32_t cmd);
        std::string getBufferInfoString(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd);
#endif
