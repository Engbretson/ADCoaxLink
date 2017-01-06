/* Copyright Euresys 2015 */

#ifndef EURESYS_REFCOUNTED_HEADER_FILE
#define EURESYS_REFCOUNTED_HEADER_FILE

namespace EURESYS_NAMESPACE {

namespace Internal {

template<typename H> struct RefCounted {
    public:
        RefCounted()
        : handle(0)
        , refcount(0)
        {
        }
        size_t use_count() const {
            return refcount;
        }
        void set(const H h) {
            if (refcount) {
                throw gentl_error(gc::GC_ERR_RESOURCE_IN_USE, __FUNCTION__);
            }
            handle = h;
        }
        H use() {
            if (!handle) {
                throw gentl_error(gc::GC_ERR_NOT_INITIALIZED, __FUNCTION__);
            }
            ++refcount;
            return handle;
        }
        void release(const H h) {
            if (!refcount) {
                throw gentl_error(gc::GC_ERR_NOT_INITIALIZED, __FUNCTION__);
            }
            if (!handle) {
                throw gentl_error(gc::GC_ERR_NOT_INITIALIZED, __FUNCTION__);
            }
            if (h != handle) {
                throw gentl_error(gc::GC_ERR_INVALID_HANDLE, __FUNCTION__);
            }
            --refcount;
        }
        bool equals(const H h) {
            return handle == h;
        }

    private:
        H handle;
        size_t refcount;
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
