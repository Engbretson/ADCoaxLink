/* Copyright Euresys 2015 */

#ifndef EGRABBER_TYPES_HEADER_FILE
#define EGRABBER_TYPES_HEADER_FILE

/** @file
    Defines data types related to Euresys::EGrabber
 **/

namespace EURESYS_NAMESPACE {

// --------------------------------------------------------------------------
// Available Memory types to announce GenTL buffers
// --------------------------------------------------------------------------

struct GenTLMemory;
struct UserMemory;
struct BusMemory;
struct UserMemoryArray;

/// Memory allocated by the GenTL producer
struct GenTLMemory {
    /// @param bufferSize when bufferSize = 0, EGrabber evaluates a suitable bufferSize
    GenTLMemory(size_t bufferSize = 0)
    : bufferSize(bufferSize)
    {}
    /// bufferSize when bufferSize = 0, EGrabber evaluates a suitable bufferSize
    size_t bufferSize;
};

/// Memory allocated by the user
struct UserMemory {
    /// @param base address of buffer allocated by the user
    /// @param size size of the buffer allocated by the user
    /// @param userPointer optional pointer to private data (available in NewBufferData)
    UserMemory(void *base, size_t size, void *userPointer = 0)
    : base(base)
    , size(size)
    , userPointer(userPointer)
    {}
    /// address of buffer allocated by the user
    void *base;
    /// size of the buffer allocated by the user
    size_t size;
    /// optional pointer to private data (available in NewBufferData)
    void *userPointer;
};

/// Bus addressable memory
struct BusMemory {
    /// @param busAddress bus buffer address on the PCIe bus
    /// @param size size of the buffer allocated by the user
    /// @param userPointer optional pointer to private data (available in NewBufferData)
    BusMemory(uint64_t busAddress, size_t size, void *userPointer = 0)
    : busAddress(busAddress)
    , size(size)
    , userPointer(userPointer)
    {}
    /// bus buffer address on the PCIe bus
    uint64_t busAddress;
    /// size of the buffer allocated by the user
    size_t size;
    /// optional pointer to private data (available in NewBufferData)
    void *userPointer;
};

/// UserMemory split into an array of contiguous buffers
struct UserMemoryArray {
    /// @param memory memory allocated by the user to split into an array of contiguous buffers
    /// @param bufferSize size of buffers
    /// @warning depending on the size of the user memory and the requested buffer size,
    /// the size of the last buffer of the array can be smaller than bufferSize,
    /// therefore we recommend to make sure that memory.size is a multiple of bufferSize.
    UserMemoryArray(const UserMemory &memory, size_t bufferSize)
    : memory(memory)
    , bufferSize(bufferSize)
    {}
    /// memory allocated by the user to split into an array of contiguous buffers
    UserMemory memory;
    /// size of buffers
    size_t bufferSize;
};

// --------------------------------------------------------------------------
// Buffer Index Range returned by announce
// --------------------------------------------------------------------------

/** Range of buffer indexes returned by the EGrabber methods announcing buffers

    When buffers are announced to the EGrabber, their corresponding GenTL handles
    are stored in a private vector. Instead of returning those handles to the
    user, the EGrabber returns their indexes as a range.
    Buffer operations (such as EGrabber::getBufferInfo) use indexes to identify
    specific buffers in the list of all buffers managed by the EGrabber.
 **/
struct BufferIndexRange {
    /** Create a range of buffer indexes
        @param begin index of the first buffer of the range
        @param end index of the end of the range, the end is *not* included in the range
     **/
    BufferIndexRange(size_t begin, size_t end)
    : begin(begin)
    , end(end)
    {}
    /** Convert a 0-based index in the range to an absolute buffer index
        @param offset 0-based index of a buffer in the range
     **/
    size_t indexAt(size_t offset) {
        size_t ix = begin + offset;
        if (begin <= ix && ix < end) { return ix; }
        throw client_error("out of range");
    }
    /// index of the first buffer of the range
    size_t begin;
    /// index of the end of the range, the end is *not* included in the range
    size_t end;
};

/** @defgroup GenTLModulesAndPorts Available GenTL/Port Modules
    Euresys abstraction of GenTL Port modules as well as Remote Device Port
    @ingroup EGrabber
 **/

// --------------------------------------------------------------------------
// Available (Port) Modules (see getInfo<M, T>, GenApi methods <P>)
// --------------------------------------------------------------------------

/** @ingroup GenTLModulesAndPorts
    Identifies the EGrabber system module
 **/
struct SystemModule {
};

/** @ingroup GenTLModulesAndPorts
    Identifies the EGrabber interface module
 **/
struct InterfaceModule {
};

/** @ingroup GenTLModulesAndPorts
    Identifies the EGrabber device module
 **/
struct DeviceModule {
};

/** @ingroup GenTLModulesAndPorts
    Identifies the EGrabber data stream module
 **/
struct StreamModule {
};

/** @ingroup GenTLModulesAndPorts
    Identifies the EGrabber remote device port
 **/
struct RemoteModule {
};

/** @defgroup EGrabberEventDataOrAll Available Event DATA types to enable
    Euresys abstraction of GenTL event registration
    
    Types defined in this section identify specific GenTL event types that
    can be registered to the system.
    @sa Euresys::EGrabber::enableEvent
    @sa Euresys::EGrabber::disableEvent
    @sa Euresys::EGrabber::flushEvent
    @ingroup Events
 **/

/** @defgroup EGrabberEventAnyData Available Event DATA types to process
    Euresys abstraction of GenTL event handling
    
    Types defined in this section convey data associated to received GenTL
    events. The data is exposed through the EGrabber Event Callbacks.
    @sa Euresys::EGrabber::onNewBufferEvent
    @sa Euresys::EGrabber::onIoToolboxEvent
    @sa Euresys::EGrabber::onCicEvent
    @sa Euresys::EGrabber::onDataStreamEvent
    @sa Euresys::EGrabber::onCxpInterfaceEvent
    @ingroup Events
 **/

// --------------------------------------------------------------------------
// Available Event DATA types (see enableEvent<DATA>)
// --------------------------------------------------------------------------

/** Event DATA type corresponding to @ref GenICam::Client::EVENT_NEW_BUFFER
    @ingroup EGrabberEventDataOrAll
    @ingroup EGrabberEventAnyData
 **/
struct NewBufferData {
    gc::DS_HANDLE dsh;      /**< GenICam::Client::DS_HANDLE handle associated to buffer */
    gc::BUFFER_HANDLE bh;   /**< GenICam::Client::BUFFER_HANDLE handle */
    void *userPointer;      /**< Optional user pointer (if provided when announced) */
    uint64_t timestamp;     /**< Timestamp associated to new buffer event */
};

/** Event DATA type corresponding to @ref GenICam::Client::Euresys::EVENT_CUSTOM_IO_TOOLBOX
    @ingroup EGrabberEventDataOrAll
    @ingroup EGrabberEventAnyData
 **/
struct IoToolboxData {
    ge::EVENT_DATA_NUMID_CUSTOM numid;  /**< GenICam::Client::Euresys::EVENT_DATA_NUMID_CUSTOM custom Event data identifier */
    uint64_t timestamp;                 /**< Event timestamp */
    uint32_t context1;                  /**< Value of EventNotificationContext1 for this event (latched at the time the event occurred) */
    uint32_t context2;                  /**< Value of EventNotificationContext2 for this event (latched at the time the event occurred) */
    uint32_t context3;                  /**< Value of EventNotificationContext3 for this event (latched at the time the event occurred) */
};

/** Event DATA type corresponding to @ref GenICam::Client::Euresys::EVENT_CUSTOM_CIC
    @ingroup EGrabberEventDataOrAll
    @ingroup EGrabberEventAnyData
 **/
struct CicData {
    ge::EVENT_DATA_NUMID_CUSTOM numid;  /**< GenICam::Client::Euresys::EVENT_DATA_NUMID_CUSTOM custom Event data identifier */
    uint64_t timestamp;                 /**< Event timestamp */
    uint32_t context1;                  /**< Value of EventNotificationContext1 for this event (latched at the time the event occurred) */
    uint32_t context2;                  /**< Value of EventNotificationContext2 for this event (latched at the time the event occurred) */
    uint32_t context3;                  /**< Value of EventNotificationContext3 for this event (latched at the time the event occurred) */
};

/** Event DATA type corresponding to @ref GenICam::Client::Euresys::EVENT_CUSTOM_DATASTREAM
    @ingroup EGrabberEventDataOrAll
    @ingroup EGrabberEventAnyData
 **/
struct DataStreamData {
    ge::EVENT_DATA_NUMID_CUSTOM numid;  /**< GenICam::Client::Euresys::EVENT_DATA_NUMID_CUSTOM custom Event data identifier */
    uint64_t timestamp;                 /**< Event timestamp */
    uint32_t context1;                  /**< Value of EventNotificationContext1 for this event (latched at the time the event occurred) */
    uint32_t context2;                  /**< Value of EventNotificationContext2 for this event (latched at the time the event occurred) */
    uint32_t context3;                  /**< Value of EventNotificationContext3 for this event (latched at the time the event occurred) */
};

/** Event DATA type corresponding to @ref GenICam::Client::Euresys::EVENT_CUSTOM_CXP_INTERFACE
    @ingroup EGrabberEventDataOrAll
    @ingroup EGrabberEventAnyData
 **/
struct CxpInterfaceData {
    ge::EVENT_DATA_NUMID_CUSTOM numid;  /**< GenICam::Client::Euresys::EVENT_DATA_NUMID_CUSTOM custom Event data identifier */
    uint64_t timestamp;                 /**< Event timestamp */
    uint32_t context1;                  /**< Value of EventNotificationContext1 for this event (latched at the time the event occurred) */
    uint32_t context2;                  /**< Value of EventNotificationContext2 for this event (latched at the time the event occurred) */
    uint32_t context3;                  /**< Value of EventNotificationContext3 for this event (latched at the time the event occurred) */
};

/** @ingroup EGrabberEventDataOrAll
    Special data type to enable, disable or flush all available Event DATA types
    @code{.cpp}
    myGrabber.enableEvent<All>();
    @endcode
 **/
struct All {
};

/** @ingroup EGrabberEventAnyData
    Special data type to process or cancel any enabled events
    @code{.cpp}
    myGrabber.processEvent<Any>();
    @endcode
 **/
struct Any {
};

/// @cond
struct Undefined {
    // An undefined event DATA type
    // For implementation purpose only, see OneOf
};
/// @endcond

/** @ingroup EGrabberEventAnyData
    Special data type that groups a set of events,
    this is useful to process one event from a list of enabled event DATA types
    @code{.cpp}
    myGrabber.processEvent< OneOf<NewBufferData, IoToolboxData> >();
    @endcode
 **/
template < typename D1
         , typename D2 = Undefined
         , typename D3 = Undefined 
         , typename D4 = Undefined
         , typename D5 = Undefined >
struct OneOf {
};

/** @defgroup EGrabberCallbackModel Available Callback threading models
    Configurations of EGrabber Callback threading models
    @ingroup EGrabber
    @{
 **/

// --------------------------------------------------------------------------
// Available Callback threading models
// --------------------------------------------------------------------------

/** This is the simplest model which gives complete control over when and
    how callbacks are invoked. Events are processed on demand.
    
    This model enables the following EGrabber methods:
     - EGrabber::pop, EGrabber::cancelPop
     - EGrabber::processEvent<ANYDATA>, EGrabber::cancelEvent<ANYDATA>
    
    EGrabber::pop and EGrabber::processEvent<ANYDATA> are blocking functions,
    they wait for an event to occur before returning the event data to the
    caller. It is possible to stop them prematurely via EGrabber::cancelPop
    and EGrabber::cancelEvent<ANYDATA>
    
    When EGrabber::processEvent<ANYDATA> catches an event,
    the following steps happen:
     - relevant event data is extracted
     - corresponding EGrabber callback is called with extracted event data
     - EGrabber::processEvent<ANYDATA> returns the number of pending events
       of that type
    
    This model allows you to wait for one specific event type or for several
    event types:
     - EGrabber::processEvent<ANYDATA>: to wait for one event type
     - EGrabber::processEvent< OneOf<DATA1, DATA2...> >: to wait for one
       event from a list of types. This processes the oldest event from the
       requested types
    
    @note at most one callback is invoked for one call to EGrabber::processEvent,
    the callback is called in the same context as EGrabber::processEvent
 **/
struct CallbackOnDemand {
};

/** This model delivers events to callbacks in their chronological order,
    sequentially, in a dedicated thread context. Events are processed
    automatically as soon as they are available.
    
    When events are available in the system, the following steps happen:
     - the oldest (timestamp) event from the different enabled types is
       picked
     - relevant event data is extracted
     - corresponding EGrabber callback is called with extracted event data
     - same steps are repeated until the system runs out of pending events
    
    @note in this model, the methods EGrabber::pop, EGrabber::cancelPop,
    EGrabber::processEvent<ANYDATA> and EGrabber::cancelEvent<ANYDATA>
    are not available
 **/
struct CallbackSingleThread {
};

/** This model delivers events to callbacks in separate threads (one thread
    per event DATA type). Events are processed automatically as soon as they
    are available.

    When an event thread catches an event, the following steps happen:
     - relevant event data is extracted
     - corresponding EGrabber callback is called with extracted event data
     - event threads waits for another event...

    @note in this model, the methods EGrabber::pop, EGrabber::cancelPop,
    EGrabber::processEvent<ANYDATA> and EGrabber::cancelEvent<ANYDATA>
    are not available

    @warning
     - Care must be taken with this model because callbacks may be called
       concurrently for different event types
     - Depending on the system load, the order in which callbacks are
       invoked may be different from the chronological order of events
 **/
struct CallbackMultiThread {
};

/** @} */

} // EURESYS_NAMESPACE

#endif
