    public:
        bool isShared() const {
            return shared;
        }
#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4996 ) // 'vsnprintf': This function or variable may be unsafe
#endif
        void memento(const char *fmt, ...) {
            char text[256];
            va_list args;
            va_start(args, fmt);
            vsnprintf(text, sizeof(text), fmt, args);
            va_end(args);
            return impl.memento(text);
        }
#ifdef _MSC_VER
#pragma warning( pop )
#endif
    private:
        Internal::GenTLImpl impl;
        const bool shared;
        Internal::ConcurrencyLock mutex;
        Internal::RefCounted<gc::TL_HANDLE> tl;
        typedef std::map<const std::string, Internal::RefCounted<gc::IF_HANDLE> > if_map_type;
        if_map_type ifs;
