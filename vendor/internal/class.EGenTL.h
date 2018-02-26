    public:
        bool isShared() const {
            return shared;
        }
    private:
        Internal::GenTLImpl impl;
        const bool shared;
        Internal::ConcurrencyLock mutex;
        // TL_HANDLE
        Internal::RefCounted<gc::TL_HANDLE> tl;
        // IF_HANDLE
        typedef std::map<const std::string, Internal::RefCounted<gc::IF_HANDLE> > if_map_type;
        if_map_type ifs;
        // DEV_HANDLE
        typedef std::map<const std::string, Internal::RefCounted<gc::DEV_HANDLE> > dev_map_type;
        std::map<gc::IF_HANDLE, dev_map_type> devs;
    public:
        ETraceContext &traceCtx;
    private:
        EGenTL(const EGenTL&); // EGenTL objects cannot be copied
        EGenTL &operator=(const EGenTL&); // EGenTL objects cannot be copied
