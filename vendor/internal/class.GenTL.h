    public:
        bool isShared() const {
            return shared;
        }
    private:
        Internal::GenTLImpl impl;
        const bool shared;
        Internal::ConcurrencyLock mutex;
        Internal::RefCounted<gc::TL_HANDLE> tl;
        typedef std::map<const std::string, Internal::RefCounted<gc::IF_HANDLE> > if_map_type;
        if_map_type ifs;
    public:
        ETraceContext &traceCtx;
    private:
