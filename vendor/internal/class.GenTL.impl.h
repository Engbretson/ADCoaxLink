/** When shared is true, the class GenTL allows multiple opens of TL/IF handles.
 *  TL_HANDLE and IF_HANDLE are reference-counted.
 *  The first call to tlOpen actually calls the GenTL function TLOpen.
 *  Subsequent calls only increase the reference counter and return the handle
 *  obtained in the first call. Calls to tlClose decrease the reference
 *  counter. When the reference counter reaches 0, the GenTL function TLClose
 *  is called.
 *  IF_HANDLE are treated similarly.
 **/

namespace EURESYS_NAMESPACE {

inline GenTL::GenTL(const std::string &path, bool shared)
: impl(path)
, shared(shared)
{
    memento(std::string("GenTL::GenTL(") + path + ", shared = " + (shared ? "true" : "false") + ")");
}

inline GenTL::GenTL(bool shared, const std::string &path)
: impl(path)
, shared(shared)
{
    memento(std::string("GenTL::GenTL(shared = ") + (shared ? "true" : "false") + ", " + path + ")");
}

inline GenTL::~GenTL() {
    memento(std::string("GenTL::~GenTL(shared = ") + (shared ? "true" : "false") + ")");
}

inline gc::TL_HANDLE GenTL::tlOpen() {
    if (shared) {
        Internal::AutoLock lock(mutex);
        memento("GenTL::tlOpen() // TL_HANDLE use count = %i", tl.use_count());
        if (tl.use_count() == 0) {
            tl.set(impl.tlOpen());
        }
        return tl.use();
    } else {
        return impl.tlOpen();
    }
}
inline void GenTL::tlClose(gc::TL_HANDLE tlh) {
    if (shared) {
        Internal::AutoLock lock(mutex);
        memento("GenTL::tlClose(TL_HANDLE tlh = %p) // TL_HANDLE use count = %i", tlh, tl.use_count());
        tl.release(tlh);
        if (tl.use_count() == 0) {
            ifs = if_map_type();
            impl.tlClose(tlh);
        }
    } else {
        return impl.tlClose(tlh);
    }
}
inline gc::IF_HANDLE GenTL::tlOpenInterface(gc::TL_HANDLE tlh, const std::string &ifID) {
    if (shared) {
        Internal::AutoLock lock(mutex);
        memento("GenTL::tlOpenInterface(TL_HANDLE tlh = %p, const std::string &ifID = %s) // IF_HANDLE use count = %i", tlh, ifID.c_str(), ifs[ifID].use_count());
        if (ifs[ifID].use_count() == 0) {
            ifs[ifID].set(impl.tlOpenInterface(tlh, ifID));
        }
        return ifs[ifID].use();
    } else {
        return impl.tlOpenInterface(tlh, ifID);
    }
}
inline void GenTL::ifClose(gc::IF_HANDLE ifh) {
    if (shared) {
        Internal::AutoLock lock(mutex);
        if_map_type::iterator elem;
        for (elem = ifs.begin(); elem != ifs.end(); ++elem) {
            if (elem->second.equals(ifh)) {
                break;
            }
        }
        if (elem == ifs.end()) {
            memento("GenTL::ifClose(IF_HANDLE ifh = %p) // IF_HANDLE is unknown", ifh);
            throw gentl_error(gc::GC_ERR_INVALID_HANDLE, __FUNCTION__);
        }
        memento("GenTL::ifClose(IF_HANDLE ifh = %p) // IF_HANDLE use count = %i", ifh, elem->second.use_count());
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
