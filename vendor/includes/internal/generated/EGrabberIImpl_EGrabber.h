namespace EURESYS_NAMESPACE {

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4355 ) // 'this' : used in base member initializer list
#endif
template <typename CallbackModel> inline EGrabber<CallbackModel>::EGrabber(GenTL &gentl, int interfaceIndex, int deviceIndex, int dataStreamIndex)
: impl(gentl, *this, interfaceIndex, deviceIndex, dataStreamIndex)
{
}
template <typename CallbackModel> inline EGrabber<CallbackModel>::EGrabber(GenTL &gentl, gc::TL_HANDLE tlh, gc::IF_HANDLE ifh, gc::DEV_HANDLE devh, gc::DS_HANDLE dsh)
: impl(gentl, *this, tlh, ifh, devh, dsh)
{
}
#ifdef _MSC_VER
#pragma warning( pop )
#endif
template <typename CallbackModel >  inline BufferIndexRange EGrabber<CallbackModel>::reallocBuffers(size_t bufferCount, size_t bufferSize) {
    return impl.reallocBuffers(bufferCount, bufferSize);
}
template <typename CallbackModel >  inline BufferIndexRange EGrabber<CallbackModel>::announceAndQueue(const GenTLMemory & memory) {
    return impl.announceAndQueue(memory);
}
template <typename CallbackModel >  inline BufferIndexRange EGrabber<CallbackModel>::announceAndQueue(const UserMemory & memory) {
    return impl.announceAndQueue(memory);
}
template <typename CallbackModel >  inline BufferIndexRange EGrabber<CallbackModel>::announceAndQueue(const UserMemoryArray & memory) {
    return impl.announceAndQueue(memory);
}
template <typename CallbackModel >  inline BufferIndexRange EGrabber<CallbackModel>::announceAndQueue(const BusMemory & memory) {
    return impl.announceAndQueue(memory);
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::flushBuffers(gc::ACQ_QUEUE_TYPE operation) {
    return impl.flushBuffers(operation);
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::resetBufferQueue() {
    return impl.resetBufferQueue();
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::revoke(const BufferIndexRange & range) {
    return impl.revoke(range);
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::start(uint64_t frameCount) {
    return impl.start(frameCount);
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::stop() {
    return impl.stop();
}
template <typename CallbackModel >  inline size_t EGrabber<CallbackModel>::getWidth() {
    return impl.getWidth();
}
template <typename CallbackModel >  inline size_t EGrabber<CallbackModel>::getHeight() {
    return impl.getHeight();
}
template <typename CallbackModel >  inline size_t EGrabber<CallbackModel>::getPayloadSize() {
    return impl.getPayloadSize();
}
template <typename CallbackModel >  inline std::string EGrabber<CallbackModel>::getPixelFormat() {
    return impl.getPixelFormat();
}
template <typename CallbackModel > template <typename M, typename T> inline T EGrabber<CallbackModel>::getInfo(int32_t cmd) {
    return impl.template getInfo<M, T>(cmd);
}
template <typename CallbackModel > template <typename T> inline T EGrabber<CallbackModel>::getBufferInfo(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    return impl.template getBufferInfo<T>(bufferIndex, cmd);
}
template <typename CallbackModel > template <typename P> inline int64_t EGrabber<CallbackModel>::getInteger(const std::string & feature) {
    return impl.template getInteger<P>(feature);
}
template <typename CallbackModel > template <typename P> inline double EGrabber<CallbackModel>::getFloat(const std::string & feature) {
    return impl.template getFloat<P>(feature);
}
template <typename CallbackModel > template <typename P> inline std::string EGrabber<CallbackModel>::getString(const std::string & feature) {
    return impl.template getString<P>(feature);
}
template <typename CallbackModel > template <typename P> inline std::vector<std::string> EGrabber<CallbackModel>::getStringList(const std::string & what) {
    return impl.template getStringList<P>(what);
}
template <typename CallbackModel > template <typename P> inline void EGrabber<CallbackModel>::setInteger(const std::string & feature, int64_t value) {
    return impl.template setInteger<P>(feature, value);
}
template <typename CallbackModel > template <typename P> inline void EGrabber<CallbackModel>::setFloat(const std::string & feature, double value) {
    return impl.template setFloat<P>(feature, value);
}
template <typename CallbackModel > template <typename P> inline void EGrabber<CallbackModel>::setString(const std::string & feature, const std::string & value) {
    return impl.template setString<P>(feature, value);
}
template <typename CallbackModel > template <typename P> inline void EGrabber<CallbackModel>::execute(const std::string & command) {
    return impl.template execute<P>(command);
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::runScript(const std::string & script) {
    return impl.runScript(script);
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::memento(const std::string & text) {
    return impl.memento(text);
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::memento(unsigned char verbosity, unsigned char kind, const std::string & text) {
    return impl.memento(verbosity, kind, text);
}
template <typename CallbackModel > template <typename DATA> inline void EGrabber<CallbackModel>::enableEvent() {
    return impl.template enableEvent<DATA>();
}
template <typename CallbackModel > template <typename DATA> inline void EGrabber<CallbackModel>::disableEvent() {
    return impl.template disableEvent<DATA>();
}
template <typename CallbackModel > template <typename DATA> inline void EGrabber<CallbackModel>::flushEvent() {
    return impl.template flushEvent<DATA>();
}
template <typename CallbackModel >  inline NewBufferData EGrabber<CallbackModel>::pop(uint64_t timeout) {
    return impl.pop(timeout);
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::cancelPop() {
    impl.template cancelEvent<NewBufferData>();
}
template <typename CallbackModel > template <typename ANYDATA> inline size_t EGrabber<CallbackModel>::processEvent(uint64_t timeout) {
    return impl.template processEvent<ANYDATA>(timeout);
}
template <typename CallbackModel > template <typename ANYDATA> inline void EGrabber<CallbackModel>::cancelEvent() {
    return impl.template cancelEvent<ANYDATA>();
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::onNewBufferEvent(const NewBufferData & data) {
    // default implementation
    impl.getGenTL().traceCtx.template hTrace<'W',0xdcace9ba6fb63470ULL>("onNewBufferEvent default implementation");
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::onIoToolboxEvent(const IoToolboxData & data) {
    // default implementation
    impl.getGenTL().traceCtx.template hTrace<'W',0xa926edfe11254661ULL>("onIoToolboxEvent default implementation");
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::onCicEvent(const CicData & data) {
    // default implementation
    impl.getGenTL().traceCtx.template hTrace<'W',0x7023b051be982860ULL>("onCicEvent default implementation");
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::onDataStreamEvent(const DataStreamData & data) {
    // default implementation
    impl.getGenTL().traceCtx.template hTrace<'W',0xa44d9b3352a61703ULL>("onDataStreamEvent default implementation");
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::onCxpInterfaceEvent(const CxpInterfaceData & data) {
    // default implementation
    impl.getGenTL().traceCtx.template hTrace<'W',0xf0d95318b80b0fd9ULL>("onCxpInterfaceEvent default implementation");
}
template <typename CallbackModel >  inline GenTL & EGrabber<CallbackModel>::getGenTL() {
    return impl.getGenTL();
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::push(const NewBufferData & buffer) {
    return impl.push(buffer);
}
template <typename CallbackModel >  inline size_t EGrabber<CallbackModel>::processEventFilter(size_t eventFilter, uint64_t timeout) {
    return impl.processEventFilter(eventFilter, timeout);
}
template <typename CallbackModel >  inline size_t EGrabber<CallbackModel>::processEventFilter(size_t eventFilter) {
    return impl.processEventFilter(eventFilter);
}
template <typename CallbackModel >  inline void EGrabber<CallbackModel>::cancelEventFilter(size_t eventFilter) {
    return impl.cancelEventFilter(eventFilter);
}
template <typename CallbackModel >  inline size_t EGrabber<CallbackModel>::announceBusBuffer(uint64_t busAddress, size_t size, void * userPointer) {
    return impl.announceBusBuffer(busAddress, size, userPointer);
}
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
template <typename CallbackModel >  inline size_t EGrabber<CallbackModel>::announceBuffer(void * ptr, size_t size, void * userPointer) {
    return impl.announceBuffer(ptr, size, userPointer);
}
#endif // EURESYS_USE_EGRABBER_DEPRECATED_API
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
template <typename CallbackModel > template <typename M> inline std::string EGrabber<CallbackModel>::getInfoString(int32_t cmd) {
    return impl.template getInfoString<M>(cmd);
}
#endif // EURESYS_USE_EGRABBER_DEPRECATED_API
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
template <typename CallbackModel >  inline std::string EGrabber<CallbackModel>::getBufferInfoString(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    return impl.getBufferInfoString(bufferIndex, cmd);
}
#endif // EURESYS_USE_EGRABBER_DEPRECATED_API
} // namespace EURESYS_NAMESPACE
