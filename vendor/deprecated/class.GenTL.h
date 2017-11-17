#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    public:
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

        /** Retrieves textual information for the system module.
         *  See ::TL_INFO_CMD_LIST for allowed \c cmd values.
         *  Internal buffer size is adjusted if needed.
         *  @throw unexpected_data_type if the given cmd does not return a STRING.
         */
        std::string gcGetInfoString(gc::TL_INFO_CMD cmd) {
            return impl.gcGetInfoString(cmd);
        }

        /** Retrieves textual information for a port module.
         *  See ::PORT_INFO_CMD_LIST for allowed \c cmd values.
         *  Internal buffer size is adjusted if needed.
         *  @throw unexpected_data_type if the given cmd does not return a STRING.
         */
        std::string gcGetPortInfoString(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
            return impl.gcGetPortInfoString(ph, cmd);
        }

        /** Retrieves textual information for the event data given in buffer.
         *  See ::EVENT_DATA_INFO_CMD_LIST for allowed \c cmd values.
         *  Internal buffer size is adjusted if needed.
         *  @throw unexpected_data_type if the given cmd does not return a STRING.
         */
        std::string eventGetDataInfoString(gc::EVENT_HANDLE eh,
                                           const void *buffer, size_t size,
                                           gc::EVENT_DATA_INFO_CMD cmd) {
            return impl.eventGetDataInfoString(eh, buffer, size, cmd);
        }

        /** Retrieves textual information for an event.
         *  See ::EVENT_INFO_CMD_LIST for allowed \c cmd values.
         *  Internal buffer size is adjusted if needed.
         *  @throw unexpected_data_type if the given cmd does not return a STRING.
         */
        std::string eventGetInfoString(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
            return impl.eventGetInfoString(eh, cmd);
        }

        /** Retrieves textual information for the TL module.
         *  See ::TL_INFO_CMD_LIST for allowed \c cmd values
         *  Internal buffer size is adjusted if needed.
         *  @throw unexpected_data_type if the given cmd does not return a STRING.
         */
        std::string tlGetInfoString(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
            return impl.tlGetInfoString(tlh, cmd);
        }

        /** Retrieves textual information for the Interface module identified by its ID.
         *  See ::INTERFACE_INFO_CMD_LIST for allowed \c cmd values
         *  Internal buffer size is adjusted if needed.
         *  @throw unexpected_data_type if the given cmd does not return a STRING.
         */
        std::string tlGetInterfaceInfoString(gc::TL_HANDLE tlh, const std::string &ifID, gc::TL_INFO_CMD cmd) {
            return impl.tlGetInterfaceInfoString(tlh, ifID, cmd);
        }

        /** Retrieves textual information for the Interface module.
         *  See ::INTERFACE_INFO_CMD_LIST for allowed \c cmd values
         *  Internal buffer size is adjusted if needed.
         *  @throw unexpected_data_type if the given cmd does not return a STRING.
         */
        std::string ifGetInfoString(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
            return impl.ifGetInfoString(ifh, cmd);
        }

        /** Retrieves textual information for the Device module identified by its ID.
         *  See ::DEVICE_INFO_CMD_LIST for allowed \c cmd values
         *  Internal buffer size is adjusted if needed.
         *  @throw unexpected_data_type if the given cmd does not return a STRING.
         */
        std::string ifGetDeviceInfoString(gc::IF_HANDLE ifh, const std::string &devID, gc::INTERFACE_INFO_CMD cmd) {
            return impl.ifGetDeviceInfoString(ifh, devID, cmd);
        }

        /** Retrieves textual information for the Device module.
         *  See ::DEVICE_INFO_CMD_LIST for allowed \c cmd values
         *  Internal buffer size is adjusted if needed.
         *  @throw unexpected_data_type if the given cmd does not return a STRING.
         */
        std::string devGetInfoString(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
            return impl.devGetInfoString(devh, cmd);
        }

        /** Retrieves textual information for the DataStream module.
         *  See ::STREAM_INFO_CMD_LIST for allowed \c cmd values
         *  Internal buffer size is adjusted if needed.
         *  @throw unexpected_data_type if the given cmd does not return a STRING.
         */
        std::string dsGetInfoString(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
            return impl.dsGetInfoString(dsh, cmd);
        }

        /** Retrieves textual information for a buffer.
         *  See ::BUFFER_INFO_CMD_LIST for allowed \c cmd values.
         *  Internal buffer size is adjusted if needed.
         *  @throw unexpected_data_type if the given cmd does not return a STRING.
         */
        std::string dsGetBufferInfoString(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh,
                                          gc::BUFFER_INFO_CMD cmd) {
            return impl.dsGetBufferInfoString(dsh, bh, cmd);
        }

        std::string gcGetPortURLInfoString(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
            return impl.gcGetPortURLInfoString(h, index, cmd);
        }
#endif
#ifdef EURESYS_USE_BAYER_DEPRECATED_API
    public:
        ///@{ @name Euresys Bayer functions
        /** Decodes a bayer image.
         */
        void bayerConvert(ge::BAYER_METHOD method,
                          ge::PIXEL_FORMAT in_format, int in_width, int in_height, const void *in_pixels,
                          ge::PIXEL_FORMAT out_format, int out_width, int out_height, void *out_pixels,
                          const ge::ROI_DETAILS *roi_details = 0,
                          void *reserved = 0) {
            return impl.bayerConvert(method, in_format, in_width, in_height, in_pixels,
                                     out_format, out_width, out_height, out_pixels,
                                     roi_details, reserved);
        }
        ///@}
#endif
