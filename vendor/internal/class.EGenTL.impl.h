/** When shared is true, the class EGenTL allows multiple opens of TL/IF handles.
 *  TL_HANDLE and IF_HANDLE are reference-counted.
 *  The first call to tlOpen actually calls the GenTL function TLOpen.
 *  Subsequent calls only increase the reference counter and return the handle
 *  obtained in the first call. Calls to tlClose decrease the reference
 *  counter. When the reference counter reaches 0, the GenTL function TLClose
 *  is called.
 *  IF_HANDLE are treated similarly.
 **/

namespace EURESYS_NAMESPACE {

inline EGenTL::EGenTL(const std::string &path, bool shared)
: impl(path)
, shared(shared)
, traceCtx(impl.traceCtx)
{
    traceCtx.hTrace<'I',0x9ce5d9b74c4028b2ULL,'s','s'>("EGenTL::EGenTL(%_, shared = %_)", path, (shared ? "true" : "false"));
}

inline EGenTL::EGenTL(const char *path, bool shared)
: impl((path) ? std::string(path) : std::string())
, shared(shared)
, traceCtx(impl.traceCtx)
{
    traceCtx.hTrace<'I',0x9ce5d9b74c4028b2ULL,'s','s'>("EGenTL::EGenTL(%_, shared = %_)", path, (shared ? "true" : "false"));
}

inline EGenTL::EGenTL(bool shared, const std::string &path)
: impl(path)
, shared(shared)
, traceCtx(impl.traceCtx)
{
    traceCtx.hTrace<'I',0x47bcca95df846f80ULL,'s','s'>("EGenTL::EGenTL(shared = %_, %_)", (shared ? "true" : "false"), path);
}

inline EGenTL::~EGenTL() {
    traceCtx.hTrace<'I',0x22cb44fd2a8be3d3ULL,'s'>("EGenTL::~EGenTL(shared = %_)", (shared ? "true" : "false"));
}

inline gc::TL_HANDLE EGenTL::tlOpen() {
    if (shared) {
        Internal::AutoLock lock(mutex);
        traceCtx.hTrace<'I',0x6ca6b1d72c6ceca5ULL,'S'>("EGenTL::tlOpen() // TL_HANDLE use count = %_", tl.use_count());
        if (tl.use_count() == 0) {
            tl.set(impl.tlOpen());
        }
        return tl.use();
    } else {
        return impl.tlOpen();
    }
}
inline void EGenTL::tlClose(gc::TL_HANDLE tlh) {
    if (shared) {
        Internal::AutoLock lock(mutex);
        traceCtx.hTrace<'I',0xffce78a2ed5b17d6ULL,'p','S'>("EGenTL::tlClose(TL_HANDLE tlh = %_) // TL_HANDLE use count = %_", tlh, tl.use_count());
        tl.release(tlh);
        if (tl.use_count() == 0) {
            ifs = if_map_type();
            impl.tlClose(tlh);
        }
    } else {
        return impl.tlClose(tlh);
    }
}
inline gc::IF_HANDLE EGenTL::tlOpenInterface(gc::TL_HANDLE tlh, const std::string &ifID) {
    if (shared) {
        Internal::AutoLock lock(mutex);
        traceCtx.hTrace<'I',0x616da54174cf831dULL,'p','s','S'>("EGenTL::tlOpenInterface(TL_HANDLE tlh = %_, const std::string &ifID = %_) // IF_HANDLE use count = %_", tlh, ifID.c_str(), ifs[ifID].use_count());
        if (ifs[ifID].use_count() == 0) {
            ifs[ifID].set(impl.tlOpenInterface(tlh, ifID));
        }
        return ifs[ifID].use();
    } else {
        return impl.tlOpenInterface(tlh, ifID);
    }
}
inline void EGenTL::ifClose(gc::IF_HANDLE ifh) {
    if (shared) {
        Internal::AutoLock lock(mutex);
        if_map_type::iterator elem;
        for (elem = ifs.begin(); elem != ifs.end(); ++elem) {
            if (elem->second.equals(ifh)) {
                break;
            }
        }
        if (elem == ifs.end()) {
            traceCtx.hTrace<'E',0x60de0d7048b0bc69ULL,'p'>("EGenTL::ifClose(IF_HANDLE ifh = %_) // IF_HANDLE is unknown", ifh);
            throw gentl_error(gc::GC_ERR_INVALID_HANDLE, __FUNCTION__);
        }
        traceCtx.hTrace<'I',0x6952d42590dfbde2ULL,'p','S'>("EGenTL::ifClose(IF_HANDLE ifh = %_) // IF_HANDLE use count = %_", ifh, elem->second.use_count());
        elem->second.release(ifh);
        if (elem->second.use_count() == 0) {
            ifs.erase(elem);
            impl.ifClose(ifh);
        }
    } else {
        return impl.ifClose(ifh);
    }
}

} // namespace EURESYS_NAMESPACE
