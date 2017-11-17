/* Copyright Euresys 2014 */

#ifndef EURESYS_GENTL_HEADER_FILE
#define EURESYS_GENTL_HEADER_FILE

#include <stdio.h>
#include <stdarg.h>
#include <map>
#include "internal/EuresysGenTLImpl.h"
#include "internal/EuresysLocks.h"
#include "internal/EuresysRefCounted.h"

/** @file
    Defines GenTL
 **/

namespace EURESYS_NAMESPACE {

/** @namespace Euresys::gc
    Shortcut to ::GenICam::Client namespace
 **/
namespace gc = GenICam::Client;
/** @namespace Euresys::ge
    Shortcut to ::GenICam::Client::Euresys namespace
 **/
namespace ge = GenICam::Client::Euresys;

/** @defgroup GenTL GenTL
    Euresys C++ wrapper around <a href=../coaxlink.html#gentl>GenTL</a>
    low-level C API
    @{
 **/

/** <a href=../coaxlink.html#euresysgentl>GenTL library functions</a>
 *  @throw gentl_error on return codes other than GenICam::Client::GC_ERR_SUCCESS.
 *  The error code can then be found in \c gentl_error.gc_err .
 **/
class GenTL {
    public:
        /** Initializes the GenTL library.
         *  @arg path: filesystem path to the GenTL library.
         *  @arg shared: shared mode allows multiple opens of TL/IF handles.
         *      when shared is false, GenTL behaves as specified in the GenTL
         *      standard, i.e. opening an already opened TL or interface will
         *      throw a gentl_error (GenICam::Client::GC_ERR_RESOURCE_IN_USE).
         */
        GenTL(const std::string &path = Internal::getEuresysCtiPath(), bool shared = true);
        GenTL(bool shared, const std::string &path = Internal::getEuresysCtiPath());
        virtual ~GenTL();

        /** Retrieves numerical information for the system module. 
         *  See GenICam::Client::TL_INFO_CMD_LIST for allowed \c cmd values.
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T gcGetInfo(gc::TL_INFO_CMD cmd) {
            return impl.gcGetInfo<T>(cmd);
        }

        ///@{ @name Low-level GenTL Port functions

        /** Fills \c data with \c data.size bytes from \c ph 's registers space.
         *    values at [address .. address+data.size[ will be read.
         *  @throw unexpected_data_size if the vector couldn't be filled.
         */
        void gcReadPort(gc::PORT_HANDLE ph, uint64_t address,
                        std::vector<char> &data) {
            return impl.gcReadPort(ph, address, data);
        }
        /** Reads up to \c size bytes from \c ph 's registers space as a string.
         */
        std::string gcReadPortString(gc::PORT_HANDLE ph, uint64_t address, size_t size) {
            return impl.gcReadPortString(ph, address, size);
        }

        /** Reads a single 32-bit value from \c ph 's registers space.
         */
        uint32_t gcReadPort(gc::PORT_HANDLE ph, uint64_t address) {
            return impl.gcReadPort(ph, address);
        }
        /** Writes \c data.size bytes into \c ph 's registers space.
         *  @throw unexpected_data_size if some bytes couldn't be sent.
         */
        void gcWritePort(gc::PORT_HANDLE ph, uint64_t address,
                         const std::vector<char> &data) {
            return impl.gcWritePort(ph, address, data);
        }

        /** Returns the list of XML description URL for the given port.
         */
        std::vector<std::string> gcGetPortURL(gc::PORT_HANDLE ph) {
            return impl.gcGetPortURL(ph);
        }

        /** retrieve numerical information for a port module.
         *  See GenICam::Client::PORT_INFO_CMD_LIST for allowed \c cmd values.
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T gcGetPortInfo(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
            return impl.gcGetPortInfo<T>(ph, cmd);
        }
        ///@}

        ///@{ @name GenTL Event functions

        /** Returns the handle to a newly registered event
         *  @arg h: the source module handle (e.g. a GenICam::Client::DS_HANDLE)
         */
        gc::EVENT_HANDLE gcRegisterEvent(gc::EVENTSRC_HANDLE h, gc::EVENT_TYPE event) {
            return impl.gcRegisterEvent(h, event);
        }
        void gcUnregisterEvent(gc::EVENTSRC_HANDLE h, gc::EVENT_TYPE event) {
            return impl.gcUnregisterEvent(h, event);
        }
        /** Waits for event to happen for at most \c timeout ms and returns filled data size
         *  @throw gentl_error on timeout or termination through @ref eventKill.
         */
        size_t eventGetData(gc::EVENT_HANDLE eh, void *buffer, size_t size, uint64_t timeout) {
            return impl.eventGetData(eh, buffer, size, timeout);
        }
        /** Waits for multiple events to happen for at most \c timeout ms
         *  @throw gentl_error on timeout (unless timeout is NULL) or termination through @ref eventKill.
         *  @warning see documentation of underlying function GenICam::Client::Euresys::EuresysEventsGetData
         */
        void eventsGetData(std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY> &entries, uint64_t *timeout) {
            impl.eventsGetData(entries, timeout);
        }

        /** Retrieves numerical information for an event data given in buffer.
         *  See GenICam::Client::EVENT_DATA_INFO_CMD_LIST for allowed \c cmd values.
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T eventGetDataInfo(gc::EVENT_HANDLE eh,
                                                 const void *buffer, size_t size,
                                                 gc::EVENT_DATA_INFO_CMD cmd) {
            return impl.eventGetDataInfo<T>(eh, buffer, size, cmd);
        }
        /** Retrieves numerical information for an event.
         *  See GenICam::Client::EVENT_INFO_CMD_LIST for allowed \c cmd values.
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T eventGetInfo(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
            return impl.eventGetInfo<T>(eh, cmd);
        }
        /** Discards all the past occurrences.
         */
        void eventFlush(gc::EVENT_HANDLE eh) {
            return impl.eventFlush(eh);
        }
        /** Terminates a pending operation.
         */
        void eventKill(gc::EVENT_HANDLE eh) {
            return impl.eventKill(eh);
        }
        ///@}

        ///@{ @name GenTL TL functions
        gc::TL_HANDLE tlOpen();
        void tlClose(gc::TL_HANDLE tlh);
        /** Retrieves numerical information for the TL module. 
         *  See GenICam::Client::TL_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T tlGetInfo(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
            return impl.tlGetInfo<T>(tlh, cmd);
        }
        uint32_t tlGetNumInterfaces(gc::TL_HANDLE tlh) {
            return impl.tlGetNumInterfaces(tlh);
        }
        std::string tlGetInterfaceID(gc::TL_HANDLE tlh, uint32_t index) {
            return impl.tlGetInterfaceID(tlh, index);
        }
        /** Retrieves numerical information for the Interface module identified by its ID. 
         *  See GenICam::Client::INTERFACE_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T tlGetInterfaceInfo(gc::TL_HANDLE tlh, const std::string &ifID, gc::TL_INFO_CMD cmd) {
            return impl.tlGetInterfaceInfo<T>(tlh, ifID, cmd);
        }
        gc::IF_HANDLE tlOpenInterface(gc::TL_HANDLE tlh, const std::string &ifID);
        /** Checks whether the list of interface modules has changed.
         */
        bool tlUpdateInterfaceList(gc::TL_HANDLE tlh, uint64_t timeout = GENTL_INFINITE) {
            return impl.tlUpdateInterfaceList(tlh, timeout);
        }
        ///@}

        ///@{ @name GenTL Interface functions
        void ifClose(gc::IF_HANDLE ifh);
        /** Retrieves numerical information for the Interface module. 
         *  See GenICam::Client::INTERFACE_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T ifGetInfo(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
            return impl.ifGetInfo<T>(ifh, cmd);
        }
        uint32_t ifGetNumDevices(gc::IF_HANDLE ifh) {
            return impl.ifGetNumDevices(ifh);
        }
        std::string ifGetDeviceID(gc::IF_HANDLE ifh, uint32_t index) {
            return impl.ifGetDeviceID(ifh, index);
        }
        /** Checks whether the list of devices has changed.
         */
        bool ifUpdateDeviceList(gc::IF_HANDLE ifh, uint64_t timeout = GENTL_INFINITE) {
            return impl.ifUpdateDeviceList(ifh, timeout);
        }
        /** Retrieves numerical information for the Device module identified by its ID. 
         *  See GenICam::Client::DEVICE_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T ifGetDeviceInfo(gc::IF_HANDLE ifh, const std::string &devID, gc::INTERFACE_INFO_CMD cmd) {
            return impl.ifGetDeviceInfo<T>(ifh, devID, cmd);
        }
        gc::DEV_HANDLE ifOpenDevice(gc::IF_HANDLE ifh, const std::string &devID,
                                    gc::DEVICE_ACCESS_FLAGS flags = gc::DEVICE_ACCESS_CONTROL) {
            return impl.ifOpenDevice(ifh, devID, flags);
        }
        ///@}

        ///@{ @name GenTL Device functions
        gc::PORT_HANDLE devGetPort(gc::DEV_HANDLE devh) {
            return impl.devGetPort(devh);
        }
        uint32_t devGetNumDataStreams(gc::DEV_HANDLE devh) {
            return impl.devGetNumDataStreams(devh);
        }
        std::string devGetDataStreamID(gc::DEV_HANDLE devh, uint32_t index) {
            return impl.devGetDataStreamID(devh, index);
        }
        gc::DS_HANDLE devOpenDataStream(gc::DEV_HANDLE devh, const std::string &dsID) {
            return impl.devOpenDataStream(devh, dsID);
        }
        void devClose(gc::DEV_HANDLE devh) {
            return impl.devClose(devh);
        }
        /** Retrieves numerical information for the Device module. 
         *  See GenICam::Client::DEVICE_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T devGetInfo(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
            return impl.devGetInfo<T>(devh, cmd);
        }
        ///@}

        ///@{ @name GenTL DataStream functions
        /** Gets the handle of a new DataStream buffer allocated by the user.
         *  @arg buffer: user buffer address
         *  @arg size: user buffer size
         *  @arg userPointer: pointer to private data (passed to new buffer events)
         */
        gc::BUFFER_HANDLE dsAnnounceBuffer(gc::DS_HANDLE dsh, void *buffer,
                                           size_t size, void *userPointer = 0) {
            return impl.dsAnnounceBuffer(dsh, buffer, size, userPointer);
        }
        /** Gets the handle of a new DataStream buffer allocated automatically.
         *  @arg size: desired buffer size
         *  @arg userPointer: pointer to private data (passed to new buffer events)
         */
        gc::BUFFER_HANDLE dsAllocAndAnnounceBuffer(gc::DS_HANDLE dsh, size_t size,
                                                   void *userPointer = 0) {
            return impl.dsAllocAndAnnounceBuffer(dsh, size, userPointer);
        }
        /** Gets the handle of a new DataStream buffer allocated by the user
         *  and addressable on the PCIe bus.
         *  @arg buffer: bus buffer address
         *  @arg size: buffer size
         *  @arg userPointer: pointer to private data (passed to new buffer events)
         */
        gc::BUFFER_HANDLE dsAnnounceBusBuffer(gc::DS_HANDLE dsh, uint64_t busAddress,
                                              size_t size, void *userPointer = 0) {
            return impl.dsAnnounceBusBuffer(dsh, busAddress, size, userPointer);
        }
        /** Fills \c buffers vector with \c buffers.size handles to newly allocated buffers.
         *  @arg size: desired size for the buffers.
         */
        void dsAllocAndAnnounceBuffers(gc::DS_HANDLE dsh, size_t size,
                                       std::vector<gc::BUFFER_HANDLE> &buffers) {
            return impl.dsAllocAndAnnounceBuffers(dsh, size, buffers);
        }
        /** Flushes a buffers pool/queue.
         */
        void dsFlushQueue(gc::DS_HANDLE dsh, gc::ACQ_QUEUE_TYPE operation) {
            return impl.dsFlushQueue(dsh, operation);
        }
        /** Declares the DataStream ready for acquisition.
         *  does not execute a GenApi StartAcquisition command.
         */
        void dsStartAcquisition(gc::DS_HANDLE dsh,
                                gc::ACQ_START_FLAGS flags = gc::ACQ_START_FLAGS_DEFAULT,
                                uint64_t count = GENTL_INFINITE) {
            return impl.dsStartAcquisition(dsh, flags, count);
        }

        /** Declares the DataStream as done with acquisition.
         *  does not execute a GenApi StopAcquisition command.
         */
        void dsStopAcquisition(gc::DS_HANDLE dsh,
                               gc::ACQ_STOP_FLAGS flags = gc::ACQ_STOP_FLAGS_DEFAULT) {
            return impl.dsStopAcquisition(dsh, flags);
        }
        void dsClose(gc::DS_HANDLE dsh) {
            return impl.dsClose(dsh);
        }
        /** Retrieves numerical information for the DataStream module. 
         *  See GenICam::Client::STREAM_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T dsGetInfo(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
            return impl.dsGetInfo<T>(dsh, cmd);
        }
        gc::BUFFER_HANDLE dsGetBufferID(gc::DS_HANDLE dsh, uint32_t index) {
            return impl.dsGetBufferID(dsh, index);
        }
        void dsRevokeBuffer(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh,
                            void **buffer = 0, void **userPointer = 0) {
            return impl.dsRevokeBuffer(dsh, bh, buffer, userPointer);
        }
        /** Revokes the buffers contained in the \c buffers vector.
         */
        void dsRevokeBuffers(gc::DS_HANDLE dsh, std::vector<gc::BUFFER_HANDLE> &buffers) {
            return impl.dsRevokeBuffers(dsh, buffers);
        }
        /** Adds a buffer to the input buffer queue.
         */
        void dsQueueBuffer(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh) {
            return impl.dsQueueBuffer(dsh, bh);
        }
        /** Adds the buffers contained in the \c buffers vector to the input
         *  buffer queue.
         */
        void dsQueueBuffers(gc::DS_HANDLE dsh,
                            const std::vector<gc::BUFFER_HANDLE> &buffers) {
            return impl.dsQueueBuffers(dsh, buffers);
        }
        /** Retrieves numerical information for a buffer.
         *  See GenICam::Client::BUFFER_INFO_CMD_LIST for allowed \c cmd values.
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T dsGetBufferInfo(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh,
                                                gc::BUFFER_INFO_CMD cmd) {
            return impl.dsGetBufferInfo<T>(dsh, bh, cmd);
        }
        uint32_t gcGetNumPortURLs(gc::PORT_HANDLE h) {
            return impl.gcGetNumPortURLs(h);
        }
        template <typename T> T gcGetPortURLInfo(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
            return impl.gcGetPortURLInfo<T>(h, index, cmd);
        }
        /** Reads a number of bytes from the given address on the specified port for
         *  every element in the entries vector
         *  @note If an exception occurs, entries is resized according to the number of
         *  successful operations.
         */
        void gcReadPortStacked(gc::PORT_HANDLE h, std::vector<gc::PORT_REGISTER_STACK_ENTRY> &entries) {
            return impl.gcReadPortStacked(h, entries);
        }
        /** Writes a number of bytes to the given address on the specified port for
         *  every element in the entries vector
         *  @note If an exception occurs, entries is resized according to the number of
         *  successful operations.
         */
        void gcWritePortStacked(gc::PORT_HANDLE h, std::vector<gc::PORT_REGISTER_STACK_ENTRY> &entries) {
            return impl.gcWritePortStacked(h, entries);
        }
        gc::TL_HANDLE ifGetParent(gc::IF_HANDLE ifh) {
            return impl.ifGetParent(ifh);
        }
        gc::IF_HANDLE devGetParent(gc::DEV_HANDLE devh) {
            return impl.devGetParent(devh);
        }
        gc::DEV_HANDLE dsGetParent(gc::DS_HANDLE dsh) {
            return impl.dsGetParent(dsh);
        }
        ///@}
        ///@{ @name Euresys Memento functions
        /** Reports a string to the memento logging system.
         */
        void memento(const std::string &text) {
            return impl.memento(text);
        }
        void memento(unsigned char verbosity, unsigned char kind, const std::string &text) {
            return impl.memento(verbosity, kind, text.c_str());
        }
        ///@}

        ///@{ @name Euresys Genapi functions
        /** Updates a feature with string contents.
         *  @throw gentl_error if feature is missing or read-only.
         */
        void genapiSetString(gc::PORT_HANDLE h, const std::string &feature,
                             const std::string &value) {
            return impl.genapiSetString(h, feature, value);
        }
        /** Reads a feature as string.
         *  @throw gentl_error if feature is missing.
         *  @note when an integer or a float feature is accessed, optional
         *  suffixes (as documented in @ref genapiGetInteger and @ref genapiGetFloat)
         *  can be used
         */
        std::string genapiGetString(gc::PORT_HANDLE h, const std::string &feature) {
            return impl.genapiGetString(h, feature);
        }
        /** Reads a list of strings.
         *  @throw gentl_error if an error occurs.
         *  @sa Features
         *  @sa RegexFeatures
         *  @sa GlobFeatures
         *  @sa EnumEntries
         *  @sa RegexEnumEntries
         *  @sa GlobEnumEntries
         */
        std::vector<std::string> genapiGetStringList(gc::PORT_HANDLE h, const std::string &what) {
            return impl.genapiGetStringList(h, what);
        }
        /** Updates a feature with integer value
         *  @throw gentl_error if feature is missing or read-only.
         */
        void genapiSetInteger(gc::PORT_HANDLE h, const std::string &feature,
                              int64_t value) {
            return impl.genapiSetInteger(h, feature, value);
        }
        /** Reads a feature as an integer.
         *  @param h port handle
         *  @param feature name of feature to read with or without one of the following suffixes:
         *  @parblock
         *  - .Min: to read the minimum of the feature
         *  - .Max: to read the maximum of the feature
         *  - .Inc: to read the increment of the feature
         *  - .Value: to read the value of the feature (same as without .Value suffix)
         *  @endparblock
         *  @throw gentl_error if feature is missing.
         *
         *  Examples:
         *  - genapiGetInteger(cameraHandle, "Width");
         *  - genapiGetInteger(deviceHandle, "CxpTriggerMaxResendCount.Max");
         */
        int64_t genapiGetInteger(gc::PORT_HANDLE h, const std::string &feature) {
            return impl.genapiGetInteger(h, feature);
        }
        /** Reads a feature as an integer.
         *  @return feature value or defaultValue if feature is missing.
         */
        int64_t genapiGetIntegerWithDefault(gc::PORT_HANDLE h,
                                            const std::string &feature,
                                            int64_t defaultValue) {
            return impl.genapiGetIntegerWithDefault(h, feature, defaultValue);
        }
        /** Updates a feature with float value
         *  @throw gentl_error if feature is missing or read-only.
         */
        void genapiSetFloat(gc::PORT_HANDLE h, const std::string &feature,
                            double value) {
            return impl.genapiSetFloat(h, feature, value);
        }
        /** Reads a feature as a float.
         *  @param h port handle
         *  @param feature name of feature to read with or without one of the following suffixes:
         *  @parblock
         *  - .Min: to read the minimum of the feature
         *  - .Max: to read the maximum of the feature
         *  - .Inc: to read the increment of the feature (when defined)
         *  - .Value: to read the value of the feature (same as without .Value suffix)
         *  @endparblock
         *  @throw gentl_error if feature is missing.
         *
         *  Examples:
         *  - genapiGetFloat(interfaceHandle, "Temperature");
         *  - genapiGetFloat(deviceHandle, "CycleTargetPeriod.Min");
         */
        double genapiGetFloat(gc::PORT_HANDLE h, const std::string &feature) {
            return impl.genapiGetFloat(h, feature);
        }
        /** Reads a feature as a float.
         *  @return feature value or default_value if feature is missing.
         */
        double genapiGetFloatWithDefault(gc::PORT_HANDLE h,
                                         const std::string &feature,
                                         double defaultValue) {
            return impl.genapiGetFloatWithDefault(h, feature, defaultValue);
        }
        /** Executes a GenApi command.
         */
        void genapiExecuteCommand(gc::PORT_HANDLE h, const std::string &feature) {
            return impl.genapiExecuteCommand(h, feature);
        }
        /** Run a Euresys GenApi script.
         */
        void genapiRunScript(gc::PORT_HANDLE h, const std::string &script) {
            return impl.genapiRunScript(h, script);
        }
        ///@}

        ///@{ @name Euresys Image functions
        /** Get PFNC value from name.
         */
        unsigned int imageGetPixelFormatValue(const std::string &format, unsigned int ns) {
            return impl.imageGetPixelFormatValue(format, ns);
        }
        std::string imageGetPixelFormat(uint64_t format) {
            return impl.imageGetPixelFormat(format);
        }
        /** Get Bytes per pixel.
         */
        unsigned int imageGetBytesPerPixel(const std::string &format) {
            return impl.imageGetBytesPerPixel(format);
        }
        /** Convert an image.
         */
        void imageConvert(const ge::ImageConvertInput &input, const ge::ImageConvertOutput &output, const ge::ImageConvertROI *roi) {
            return impl.imageConvert(input, output, roi);
        }
        /** Save an image to disk.
         */
        void imageSaveToDisk(const ge::ImageConvertInput &input, const std::string &filepath,
                             int64_t index = -1, const ge::ImageSaveToDiskParams *params = 0) {
            return impl.imageSaveToDisk(input, filepath, index, params);
        }

        ///@}

    private:
        #include "internal/class.GenTL.h"
        #include "deprecated/class.GenTL.h"
};

/** @} */

/** @addtogroup GenApi GenApi
    Helper functions to build Euresys GenApi queries

    The functions below create queries to list features or enumeration entries
    of features from a GenApi module

    @note these functions do not return actual information but do return
    queries for EGrabber::getStringList
    @note a query string is a Euresys custom extension only supported the
    Euresys GenApi module
    @{
 **/

/** Create a query to get the list of features exposed by a GenApi Module
    @param availableOnly if true: the query will be configured to only include
    features available at "query" time; if false: the query will be configured
    to include all the exposed features
    
    Example: get names of all available features exposed by the camera
    @code{.cpp}
    vector<string> cameraFeatures(grabber.getStringList<RemoteModule>(Features()));
    @endcode
 **/
std::string Features(bool availableOnly = true);
/** Create a query to get the list of features exposed by a GenApi Module
    and matching a given regular expression pattern
    @param re regular expression matching feature names
    @param availableOnly if true: the query will be configured to only include
    matching features available at "query" time; if false: the query will be
    configured to include all matching exposed features
    
    Example: get names of all features starting with "Cxp"
    @code{.cpp}
    vector<string> cameraFeatures(grabber.getStringList<RemoteModule>(RegexFeatures("^Cxp")));
    @endcode
 **/
std::string RegexFeatures(const std::string &re, bool availableOnly = true);
/** Create a query to get the list of features exposed by a GenApi Module
    and matching a given glob pattern
    @param glob glob pattern matching feature names
    @param availableOnly if true: the query will be configured to only include
    matching features available at "query" time; if false: the query will be
    configured to include all matching exposed features
    @note Available glob pattern wildcards:
      - @b * matches 0, 1 or several characters
        e.g. "*Max" could match "WidthMax", "HeightMax", "Max"
      - @b ? matches exactly 1 character
        e.g. "offset?" could match "offsetX", "offsetY"

    Example: get names of all features with name ending with "Max"
    @code{.cpp}
    vector<string> maxFeatures(grabber.getStringList<RemoteModule>(GlobFeatures("*Max")));
    @endcode
 **/
std::string GlobFeatures(const std::string &glob, bool availableOnly = true);
/** Create a query to get the list of entries of a GenApi enumeration feature
    @param feature name of enumeration feature to query
    @param availableOnly if true: the query will be configured to only include
    enumeration entries available at "query" time; if false: the query will be
    configured to include all the enumeration entries of the given feature

    Example: get all enumeration entries of PixelFormat, including those which
    are not available at "query" time
    @code{.cpp}
    vector<string> allFormats(grabber.getStringList<RemoteModule>(EnumEntries("PixelFormat", false)));
    @endcode
 **/
std::string EnumEntries(const std::string &feature, bool availableOnly = true);
/** Create a query to get the list of entries of a GenApi enumeration feature
    and matching a given regular expression pattern
    @param feature name of enumeration feature to query
    @param re regular expression matching enumeration entry names
    @param availableOnly if true: the query will be configured to only include
    matching enumeration entries available at "query" time; if false: the query
    will be configured to include all matching enumeration entries of the given
    feature

    Example: get all available enumeration entries of PixelFormat starting with
    "Mono"
    @code{.cpp}
    vector<string> monoFormats(grabber.getStringList<RemoteModule>(RegexEnumEntries("PixelFormat", "^Mono")));
    @endcode
 **/
std::string RegexEnumEntries(const std::string &feature, const std::string &re, bool availableOnly = true);
/** Create a query to get the list of entries of a GenApi enumeration feature
    and matching a given glob pattern
    @param feature name of enumeration feature to query
    @param glob glob pattern matching enumeration entry names
    @param availableOnly if true: the query will be configured to only include
    matching enumeration entries available at "query" time; if false: the query
    will be configured to include all matching enumeration entries of the given
    feature
    @note Available glob pattern wildcards:
      - @b * matches 0, 1 or several characters
        e.g. "Mono*" could match "Mono8", "Mono16"
      - @b ? matches exactly 1 character
        e.g. "Mono1?" could match "Mono10", "Mono12", "Mono14", "Mono16"

    Example: get all available enumeration entries of PixelFormat containing
    with "BGR"
    @code{.cpp}
    vector<string> bgrFormats(grabber.getStringList<RemoteModule>(GlobEnumEntries("PixelFormat", "*BGR*")));
    @endcode
 **/
std::string GlobEnumEntries(const std::string &feature, const std::string &glob, bool availableOnly = true);

/** @} */

} // namespace EURESYS_NAMESPACE

#include "internal/class.GenTL.impl.h"

#endif
