/* Copyright Euresys 2014 */

#ifndef EGRABBER_HEADER_FILE
#define EGRABBER_HEADER_FILE

#include <string>
#include <vector>
#include <algorithm>
#include "internal/EuresysPrelude.h"
#include "EuresysGenTL.h"
#include "EGrabberTypes.h"
#include "internal/EuresysLocks.h"
#include "internal/EuresysThreads.h"
#include "internal/EGrabberImpl.h"

/** @file

    Main EGrabber header file (defines EGrabber, Buffer, and ScopedBuffer)
 **/

namespace EURESYS_NAMESPACE {

/** @defgroup EGrabber EGrabber
    Euresys EGrabber C++ classes (abstracting lower-level GenTL concepts)
    @{
 **/

/** An <a href=../coaxlink.html#euresysegrabber>EGrabber</a> object
    encapsulates a set of related <a href=../coaxlink.html#gentl>GenTL</a>
    modules (an interface, a device, a data stream, a remote device, and a
    number of buffers).

    -   An InterfaceModule: the module that represents global (shared) frame
        grabber settings and features. This includes digital I/O control, PCIe
        and firmware status...
    -   A DeviceModule (or local device, as opposed to remote device): the
        module that contains the frame grabber settings and features relating
        to the camera. This consists mainly of camera and illumination control
        features: strobes, triggers...
    -   A StreamModule: the module that handles image buffers.
    -   A RemoteModule: the CoaXPress camera.
    -   A number of buffers.
 **/
template <typename CallbackModel = CallbackOnDemand>
class EGrabber: public Internal::EGrabberBase, private Internal::EGrabberCallbacks {
    public:
        ///@{ @name Constructor
        /** Create an EGrabber object
            @tparam CallbackModel   the EGrabber callback configuration to use (@ref EGrabberCallbackModel)
            @param gentl            GenTL object
            @param interfaceIndex   index of the InterfaceModule to use
            @param deviceIndex      index of the DeviceModule to use
            @param dataStreamIndex  index of the StreamModule to use
         **/
        EGrabber(GenTL &gentl, int interfaceIndex = 0, int deviceIndex = 0, int dataStreamIndex = 0);
        ///@}

        ///@{ @name Buffer manipulation

        /** Reallocates the buffers

            reallocBuffers performs the following operations:
            - revoke current buffers (if any)
            - allocate bufferCount buffers (if bufferSize is zero, the size is
              determined automatically)
            - announce the new buffers to the data stream
            - queue the new buffers to the data stream input fifo

            @note reallocBuffers invalidates all buffer indexes
         **/
        BufferIndexRange reallocBuffers(size_t bufferCount, size_t bufferSize = 0);
        /// Allocate, announce and queue a memory buffer.
        BufferIndexRange announceAndQueue(const GenTLMemory &memory);
        /// Announce and queue a user-allocated memory buffer.
        BufferIndexRange announceAndQueue(const UserMemory &memory);
        /// Announce and queue an array of contiguous buffers using a user-allocated memory buffer.
        BufferIndexRange announceAndQueue(const UserMemoryArray &memory);
        /// Announce and queue a user-allocated bus-memory buffer.
        BufferIndexRange announceAndQueue(const BusMemory &memory);
        /// Move buffers from/to specific data stream buffer queues (see ACQ_QUEUE_TYPE_LIST)
        void flushBuffers(gc::ACQ_QUEUE_TYPE operation = gc::ACQ_QUEUE_ALL_TO_INPUT);
        /** Reset the buffers queues

            resetBufferQueue performs the following operations:
            - discard pending buffers (if any)
            - queue all buffers to the data stream input fifo, in the initial
              order (i.e., the order in which they were announced with
              reallocBuffers or announceBuffer)
            
            @note the data stream must be idle when calling this function
         **/
        void resetBufferQueue();
        /** Revoke a range of announced buffers
            @note revoke does not invalidate other buffer indexes
         **/
        void revoke(const BufferIndexRange &range);

        ///@}

        ///@{ @name Acquisitions

        /** Start acquisitions
        
            start performs the following operations:
            - start the remote device if required
            - start the data stream for frameCount buffers
            
            @note the data stream must be idle when calling this function
            @note when frameCount buffers have been filled, the data stream
            automatically goes idle, but the remote device is not stopped
         **/
        void start(uint64_t frameCount = GENTL_INFINITE);
        /** Stop acquisitions
        
            stop performs the following operations:
            - stop the data stream
            - stop the remote device
            
            @note this function will block until the data stream is idle
         **/
        void stop();

        ///@}

        ///@{ @name Image format

        /// Get the width (in pixels) of images produced by the grabber
        size_t getWidth();
        /** Get the height (in lines) of images produced by the grabber
            @note for line-scan cameras, the height is determined by the data
            stream feature "BufferHeight"
         **/
        size_t getHeight();
        /// Get the payload size of images produced by the grabber
        size_t getPayloadSize();
        /** Get the pixel format of images produced by the grabber
            @note both the camera and the data stream influence this
         **/
        std::string getPixelFormat();

        ///@}

        /**@{ @name GenTL get info
              Working with <a href=../coaxlink.html#gentl>GenTL</a> Module info commands
         **/

        /** Getting Module information
            @tparam M Module to query (@ref GenTLModulesAndPorts)
            @tparam T The C++ type corresponding to the type
            (@ref GenICam::Client::INFO_DATATYPE_LIST) of data to get
            @param cmd the info command to get, available values depend on the module M
            @parblock
            - if M is SystemModule: cmd values belong to @ref GenICam::Client::TL_INFO_CMD_LIST
            - if M is InterfaceModule: cmd values belong to @ref GenICam::Client::INTERFACE_INFO_CMD_LIST
            - if M is DeviceModule: cmd values belong to @ref GenICam::Client::DEVICE_INFO_CMD_LIST
            - if M is StreamModule: cmd values belong to @ref GenICam::Client::STREAM_INFO_CMD_LIST
            @endparblock
            @note the template parameter M cannot be set to RemoteModule because the GenTL
            standard does not expose module information about the remote device
         **/
        template <typename M, typename T> T getInfo(int32_t cmd);

        /** Get information of buffer at index bufferIndex
            @tparam T The C++ type corresponding to the type
            (@ref GenICam::Client::INFO_DATATYPE_LIST) of data to get
            @param bufferIndex the index of the buffer to query (see @ref BufferIndexRange)
            @param cmd cmd values belong to either
            @ref GenICam::Client::BUFFER_INFO_CMD_LIST or
            @ref GenICam::Client::Euresys::BUFFER_INFO_CUSTOM_CMD_LIST
         **/
        template <typename T> T getBufferInfo(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd);

        ///@}

        /**@{ @name GenApi functions
              Working with <a href=../coaxlink.html#genapi>GenApi</a> Port Module features
         **/
        
        /** Get Integer (INT64) value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to read (@ref GenTL::genapiGetInteger)
         **/
        template <typename P> int64_t getInteger(const std::string &feature);
        /** Get Float (DOUBLE) value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to read (@ref GenTL::genapiGetFloat)
         **/
        template <typename P> double getFloat(const std::string &feature);
        /** Get String value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to read (@ref GenTL::genapiGetString)
         **/
        template <typename P> std::string getString(const std::string &feature);
        /** Get list of String values returned by some query on GenApi Port Module
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param what Euresys specific query to perform, such queries are built using the following helpers:
            @parblock
            - @ref GenTL::genapiGetStringList
            - @ref Features
            - @ref RegexFeatures
            - @ref GlobFeatures
            - @ref EnumEntries
            - @ref RegexEnumEntries
            - @ref GlobEnumEntries
            @endparblock
         **/
        template <typename P> std::vector<std::string> getStringList(const std::string &what);
        /**
            Set Integer (INT64) value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to modify (@ref GenTL::genapiSetInteger)
            @param value value to write
         **/
        template <typename P> void setInteger(const std::string &feature, int64_t value);
        /** Set Float (DOUBLE) value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to modify (@ref GenTL::genapiSetFloat)
            @param value value to write
         **/
        template <typename P> void setFloat(const std::string &feature, double value);
        /** Set String value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to modify (@ref GenTL::genapiSetString)
            @param value value to write
         **/
        template <typename P> void setString(const std::string &feature, const std::string &value);
        /** Execute specified GenApi Port Module command feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param command name of feature to execute (@ref GenTL::genapiExecuteCommand)
         **/
        template <typename P> void execute(const std::string &command);

        /** Run a <a href=../coaxlink.html#euresys-genapi-scripts>Euresys GenApi script</a>.
            @param script Euresys GenApi script to run,
            this can be either a location (path) or some actual script statements (@ref GenTL::genapiRunScript)
         **/
        void runScript(const std::string &script);

        ///@}

        ///@{ @name Memento
        
        /** Output text to Memento
            @note text is inserted into the stream of Memento traces under the Kind "User0"
            with the verbosity MEMENTO_VERBOSITY_INFO
         **/
        void memento(const std::string &text);
        /** Output text to Memento with specified verbosity and user kind
            @param verbosity
            @parblock
            - MEMENTO_VERBOSITY_CRITICAL
            - MEMENTO_VERBOSITY_ERROR
            - MEMENTO_VERBOSITY_WARNING
            - MEMENTO_VERBOSITY_NOTICE
            - MEMENTO_VERBOSITY_INFO
            - MEMENTO_VERBOSITY_DEBUG
            - MEMENTO_VERBOSITY_VERBOSE
            @endparblock
            @param kind user kind identifier, from 0 to 15
            @parblock
            - 0 to output trace under the Kind "User0"
            - 1 to output trace under the Kind "User1"
            - ...
            - 10 (0xA) to output trace under the Kind "UserA"
            - 11 (0xB) to output trace under the Kind "UserB"
            - 12 (0xC) to output trace under the Kind "UserC"
            - 13 (0xD) to output trace under the Kind "UserD"
            - 14 (0xE) to output trace under the Kind "UserE"
            - 15 (0xF) to output trace under the Kind "UserF"
            @endparblock
            @param text string to output
         **/
        void memento(unsigned char verbosity, unsigned char kind, const std::string &text);
        ///@}

        ///@{ @name Events

        /** Enable event handling for the specified event
            @tparam DATA the event(s) to enable (@ref EGrabberEventDataOrAll)
            @note by default NewBufferData is enabled
            @note under the hood, this method registers the corresponding GenTL event(s) to the system.
         **/
        template <typename DATA> void enableEvent();
        /** Disable event handling for the specified event
            @tparam DATA the event(s) to disable (@ref EGrabberEventDataOrAll)
            @note under the hood, this method unregisters the corresponding GenTL event(s) from the system.
         **/
        template <typename DATA> void disableEvent();
        /** Flush the event queue(s)
            @tparam DATA the event(s) to flush (@ref EGrabberEventDataOrAll)
         **/
        template <typename DATA> void flushEvent();

        /** Return a NewBufferData structure (to be given to ScopedBuffer or Buffer)
            @param timeout timeout in milliseconds
            @pre only available on EGrabber configuration CallbackOnDemand
            @pre NewBufferData event is enabled (this is the default)
            @pre EGrabber is not already waiting for NewBufferData event in another thread
            @note only the most important exceptions are listed below
            @throw gentl_error @ref GenICam::Client::GC_ERR_ABORT when @ref cancelPop
            @throw gentl_error @ref GenICam::Client::GC_ERR_INVALID_HANDLE when NewBufferData event is disabled
            @throw gentl_error @ref GenICam::Client::GC_ERR_TIMEOUT when pop times out before an event occurs
            @throw client_error with message "EGrabber is busy in another thread"
                   if EGrabber is already waiting for NewBufferData event in another thread
                   with either pop or processEvent
            @throw client_error with message "EGrabber has no registered event for this filter"
                   if NewBufferData event is not enabled
         **/
        NewBufferData pop(uint64_t timeout = GENTL_INFINITE);
        /** Cancel a waiting pop
            @note any waiting pop will be aborted by throwing a gentl_error (@ref GenICam::Client::GC_ERR_ABORT) exception
            @note cancelPop is equivalent to cancelEvent<NewBufferData>
         **/
        void cancelPop();
        /** Invoke the corresponding Event Callback(s)
            @pre events are enabled (enableEvent<DATA>)
            @pre events are available
            @tparam ANYDATA the set of events to process (@ref EGrabberEventAnyData)
            @return the number of pending events when the callback returned
            @pre only available with EGrabber configuration CallbackOnDemand
            @pre EGrabber is not already waiting for one of ANYDATA event in another thread
            @note only the most important exceptions are listed below
            @throw gentl_error @ref GenICam::Client::GC_ERR_ABORT when @ref cancelEvent
            @throw gentl_error @ref GenICam::Client::GC_ERR_INVALID_HANDLE when corresponding event is disabled
            @throw gentl_error @ref GenICam::Client::GC_ERR_TIMEOUT when processEvent times out before an event occurs
            @throw client_error with message "EGrabber is busy in another thread"
                   if EGrabber is already waiting for one of ANYDATA event in another thread
                   with pop or processEvent
            @throw client_error with message "EGrabber has no registered event for this filter"
                   if none of ANYDATA event is enabled
         **/
        template <typename ANYDATA> size_t processEvent(uint64_t timeout = GENTL_INFINITE);
        /** Cancel a waiting processEvent<ANYDATA>
            the current processEvent<ANYDATA> will abort by throwing a gentl_error
            (@ref GenICam::Client::GC_ERR_ABORT) exception
            @tparam ANYDATA the set of events to cancel (@ref EGrabberEventAnyData)
            @pre only available with EGrabber configuration CallbackOnDemand
         **/
        template <typename ANYDATA> void cancelEvent();
        
        ///@}

        /**@{ @name Event Callbacks
              The following methods are overridable callbacks.
              They are invoked if
              - their corresponding events are enabled with enableEvent<DATA>
              - events do occur
              @note depending on the EGrabber callback configuration (@ref EGrabberCallbackModel),
              the callbacks are invoked at different timings and from different contexts
         **/
        
        /// @pre @ref enableEvent<NewBufferData>
        virtual void onNewBufferEvent(const NewBufferData &data);
        /// @pre @ref enableEvent<IoToolboxData>
        virtual void onIoToolboxEvent(const IoToolboxData &data);
        /// @pre @ref enableEvent<CicData>
        virtual void onCicEvent(const CicData &data);
        /// @pre @ref enableEvent<DataStreamData>
        virtual void onDataStreamEvent(const DataStreamData &data);
        /// @pre @ref enableEvent<CxpInterfaceData>
        virtual void onCxpInterfaceEvent(const CxpInterfaceData &data);
        
        ///@}
        
        ///@cond
        // For implementation purpose only
        GenTL &getGenTL();

    private:
        Internal::EGrabberImpl<CallbackModel> impl;
        #include "deprecated/class.EGrabber.h"
        #include "internal/class.EGrabber.h"
        ///@endcond
};

/// EGrabber using the configuration CallbackOnDemand
typedef EGrabber<CallbackOnDemand>     EGrabberCallbackOnDemand;
/// EGrabber using the configuration CallbackSingleThread
typedef EGrabber<CallbackSingleThread> EGrabberCallbackSingleThread;
/// EGrabber using the configuration CallbackMultiThread
typedef EGrabber<CallbackMultiThread>  EGrabberCallbackMultiThread;

/** Represents a GenTL buffer
 *
    @sa EGrabber<CallbackOnDemand>::pop()
 **/
class Buffer {
    public:
        /** Create a Buffer object encapsulating a GenTL buffer
            @param data data from the callback @ref EGrabber::onNewBufferEvent
         **/
        Buffer(const NewBufferData &data);
        /** Push the GenTL buffer back to the data stream input fifo
            @param grabber the grabber managing the underlying GenTL buffer to push back
         */
        void push(Internal::EGrabberBase &grabber);
        /** Get buffer information
            @tparam T The C++ type corresponding to the type (@ref GenICam::Client::INFO_DATATYPE_LIST) of data to get
            @param grabber the grabber managing the underlying GenTL buffer to query
            @param cmd cmd values belong to either
            @ref GenICam::Client::BUFFER_INFO_CMD_LIST or
            @ref GenICam::Client::Euresys::BUFFER_INFO_CUSTOM_CMD_LIST
         **/
        template <typename T> T getInfo(Internal::EGrabberBase &grabber, gc::BUFFER_INFO_CMD cmd);
        /// Get the user pointer provided when the GenTL buffer was announced (if any)
        void *getUserPointer();
        /** Save the buffer content to disk
            @param grabber the grabber managing the underlying GenTL buffer to save to disk
            @param filepath path or path pattern
            @parblock
            - path of the new image file, the file extension determines the file format
            - path pattern where a group characters 'N' is replaced by the value of index:
              - if index is 5, N becomes 5
              - if index is 9, NN becomes 09
              - if index is 10, NN becomes 10
            @code{.cpp}
            for (size_t i = 0; i < 20; ++i) {
                buffer[i]->saveToDisk(grabber, "images/buffer.NNN.jpeg", i);
            }
            @endcode
            @endparblock
            @param index
            @parblock
            - if index >= 0, enable pattern substitution with given index value
            - if index < 0, disable pattern substitution
            @endparblock
            @param params optional parameters (see @ref GenICam::Client::Euresys::ImageSaveToDiskParams)
            @pre the parent directory must exist
            @note buffer informations (address, width, height, format) are automatically
            queried
            @note no buffer conversion will be applied before writing the image file,
            please use the RGBConverter if needed
            @sa EuresysImage.h
         **/
        void saveToDisk(Internal::EGrabberBase &grabber,
                        const std::string &filepath,
                        int64_t index = -1,
                        const ge::ImageSaveToDiskParams *params = 0);

        ///@cond
    private:
        NewBufferData data;
        #include "deprecated/class.Buffer.h"
        ///@endcond
};

/** Buffer wrapper that queues its buffer when going out of scope.

    When the ScopedBuffer is destroyed, the buffer it contains is pushed to the
    back of the data stream input fifo).

    ScopedBuffer has two use cases:

    -   ScopedBuffer(grabber, timeout) with EGrabberCallbackOnDemand
        In this case, EGrabberCallbackOnDemand::pop(timeout) is called

    -   ScopedBuffer(grabber, bufferData) from the callback onNewBufferEvent
    
    @warning ScopedBuffer objects are designed to be used as short-lived variables.
    They hold a reference to a grabber therefore they *cannot* outlive their grabbers.
 **/
class ScopedBuffer {
    public:
        /** Pop a buffer and return it as a ScopedBuffer
            @param grabber the grabber managing the underlying GenTL buffer
            @param timeout timeout in milliseconds
            @sa EGrabber<CallbackOnDemand>::pop
         **/
        ScopedBuffer(EGrabber<CallbackOnDemand> &grabber, uint64_t timeout = GENTL_INFINITE);
        /** Create a ScopedBuffer encapsulating a GenTL buffer
            @param grabber the grabber managing the underlying GenTL buffer
            @param data data from the callback @ref EGrabber::onNewBufferEvent
         **/
        ScopedBuffer(Internal::EGrabberBase &grabber, const NewBufferData &data);
        /** Push the underlying GenTL buffer back to the grabber data stream
            input fifo automatically
         **/
        ~ScopedBuffer();
        /** Get buffer information
            @tparam T The C++ type corresponding to the type
            (@ref GenICam::Client::INFO_DATATYPE_LIST) of data to get
            @param cmd cmd values belong to either
            @ref GenICam::Client::BUFFER_INFO_CMD_LIST or
            @ref GenICam::Client::Euresys::BUFFER_INFO_CUSTOM_CMD_LIST
         **/
        template <typename T> T getInfo(gc::BUFFER_INFO_CMD cmd);
        /// Get the user pointer provided when the GenTL buffer was announced (if any)
        void *getUserPointer();
        /** Save the buffer content to disk
            @param filepath path or path pattern
            @parblock
            - path of the new image file, the file extension determines the file format
            - path pattern where a group characters 'N' is replaced by the value of index:
              - if index is 5, N becomes 5
              - if index is 9, NN becomes 09
              - if index is 10, NN becomes 10
            @code{.cpp}
            for (size_t i = 0; i < 20; ++i) {
                ScopedBuffer buffer(grabber);
                buffer.saveToDisk("images/buffer.NNN.jpeg", i);
            }
            @endcode
            @endparblock
            @param index
            @parblock
            - if index >= 0, enable pattern substitution with given index value
            - if index < 0, disable pattern substitution
            @endparblock
            @param params optional parameters (see @ref GenICam::Client::Euresys::ImageSaveToDiskParams)
            @pre the parent directory must exist
            @note buffer informations (address, width, height, format) are automatically
            queried
            @note no buffer conversion will be applied before writing the image file,
            please use the RGBConverter if needed
            @sa EuresysImage.h
         **/
        void saveToDisk(const std::string &filepath, // path or file pattern
                        int64_t index = -1,  // if >= 0, value to use in file pattern
                        const ge::ImageSaveToDiskParams *params = 0);

        ///@cond
    protected:
        static void *operator new(size_t); // no new ScopedBuffer
        static void *operator new[](size_t);  // no new ScopedBuffer[]
    private:
        ScopedBuffer(const ScopedBuffer &); // no copy
        ScopedBuffer &operator=(const ScopedBuffer &); // no assignment
        Internal::EGrabberBase &grabber;
        Buffer buffer;
        #include "deprecated/class.ScopedBuffer.h"
        ///@endcond
};

/** @} */

/** @defgroup Events Events
    Euresys Event/Notification definitions
    @{
 **/

/** Get a textual description of an event
    @param numid identifier of the event to describe
 **/
std::string getEventDescription(ge::EVENT_DATA_NUMID_CUSTOM numid);

/** @} */

} // EURESYS_NAMESPACE

#include "internal/EGrabberIImpl.h"

#endif
