/** When shared is true, the class EGenTL allows multiple opens of TL/IF/DEV
 *  handles.
 *  TL_HANDLE, IF_HANDLE, and DEV_HANDLE are reference-counted.
 *  The first call to tlOpen actually calls the GenTL function TLOpen.
 *  Subsequent calls only increase the reference counter and return the handle
 *  obtained in the first call. Calls to tlClose decrease the reference
 *  counter. When the reference counter reaches 0, the GenTL function TLClose
 *  is called.
 *  IF_HANDLE and DEV_HANDLE are treated similarly. (When opening an already
 *  opened DEV_HANDLE, the DEVICE_ACCESS_FLAGS must be the same as those used
 *  to open the DEV_HANDLE in the first place).
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
            ifs.clear();
            devs.clear();
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
            devs[ifh].clear();
            impl.ifClose(ifh);
        }
    } else {
        return impl.ifClose(ifh);
    }
}

inline gc::DEV_HANDLE EGenTL::ifOpenDevice(gc::IF_HANDLE ifh, const std::string &devID, gc::DEVICE_ACCESS_FLAGS flags) {
    if (shared) {
        Internal::AutoLock lock(mutex);
        if (devs[ifh][devID].use_count() == 0) {
            traceCtx.hTrace<'I',0x5da45f478a13e5d9ULL,'p','s','i','i'>("EGenTL::ifOpenDevice(IF_HANDLE ifh = %_, const std::string &devID = %_, DEVICE_ACCESS_FLAGS flags = %_) // DEV_HANDLE use count = %_", ifh, devID.c_str(), flags, (int)(devs[ifh][devID].use_count()));
            gc::DEV_HANDLE devh = impl.ifOpenDevice(ifh, devID, flags);
            devs[ifh][devID].set(devh, flags);
        } else if (devs[ifh][devID].access_flags() != flags) {
            traceCtx.hTrace<'E',0x394dfd560ffeddb5ULL,'p','s','i','i'>("EGenTL::ifOpenDevice(IF_HANDLE ifh = %_, const std::string &devID = %_, DEVICE_ACCESS_FLAGS flags = %_) // DEV_HANDLE already opened with different access flags (%_)", ifh, devID.c_str(), flags, devs[ifh][devID].access_flags());
            throw gentl_error(gc::GC_ERR_RESOURCE_IN_USE, __FUNCTION__);
        } else {
            traceCtx.hTrace<'I',0x5da45f478a13e5d9ULL,'p','s','i','i'>("EGenTL::ifOpenDevice(IF_HANDLE ifh = %_, const std::string &devID = %_, DEVICE_ACCESS_FLAGS flags = %_) // DEV_HANDLE use count = %_", ifh, devID.c_str(), flags, (int)(devs[ifh][devID].use_count()));
        }
        return devs[ifh][devID].use();
    } else {
        return impl.ifOpenDevice(ifh, devID, flags);
    }
}

inline void EGenTL::devClose(gc::DEV_HANDLE devh) {
    if (shared) {
        Internal::AutoLock lock(mutex);
        gc::IF_HANDLE ifh = GENTL_INVALID_HANDLE;
        try {
            ifh = devGetParent(devh);
        } catch (const gentl_error &) {
            traceCtx.hTrace<'E',0x44481c58ed203ec8ULL,'p'>("EGenTL::devClose(DEV_HANDLE devh = %_) // DEV_HANDLE is invalid", devh);
            throw gentl_error(gc::GC_ERR_INVALID_HANDLE, __FUNCTION__);
        }
        dev_map_type::iterator elem;
        for (elem = devs[ifh].begin(); elem != devs[ifh].end(); ++elem) {
            if (elem->second.equals(devh)) {
                break;
            }
        }
        if (elem == devs[ifh].end()) {
            traceCtx.hTrace<'E',0xe10da202c4dbc209ULL,'p'>("EGenTL::devClose(DEV_HANDLE devh = %_) // DEV_HANDLE is unknown", devh);
            throw gentl_error(gc::GC_ERR_INVALID_HANDLE, __FUNCTION__);
        }
        traceCtx.hTrace<'I',0x608ba00447cb3f0eULL,'p','S'>("EGenTL::devClose(DEV_HANDLE devh = %_) // DEV_HANDLE use count = %_", devh, elem->second.use_count());
        elem->second.release(devh);
        if (elem->second.use_count() == 0) {
            devs[ifh].erase(elem);
            impl.devClose(devh);
        }
    } else {
        return impl.devClose(devh);
    }
}

} // namespace EURESYS_NAMESPACE
