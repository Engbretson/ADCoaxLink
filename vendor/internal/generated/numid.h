namespace EURESYS_NAMESPACE {
inline std::string getEventDescription(ge::EVENT_DATA_NUMID_CUSTOM numid) {
    switch (numid) {
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_LIN1: return "Line Input Tool 1";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_LIN2: return "Line Input Tool 2";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_LIN3: return "Line Input Tool 3";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_LIN4: return "Line Input Tool 4";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_LIN5: return "Line Input Tool 5";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_LIN6: return "Line Input Tool 6";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_LIN7: return "Line Input Tool 7";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_LIN8: return "Line Input Tool 8";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_QDC1: return "Quadrature Decoder Tool 1";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_QDC1_DIR: return "Quadrature Decoder Tool 1 Changed Direction";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_QDC2: return "Quadrature Decoder Tool 2";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_QDC2_DIR: return "Quadrature Decoder Tool 2 Changed Direction";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_QDC3: return "Quadrature Decoder Tool 3";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_QDC3_DIR: return "Quadrature Decoder Tool 3 Changed Direction";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_QDC4: return "Quadrature Decoder Tool 4";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_QDC4_DIR: return "Quadrature Decoder Tool 4 Changed Direction";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DIV1: return "Divider Tool 1";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DIV2: return "Divider Tool 2";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DIV3: return "Divider Tool 3";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DIV4: return "Divider Tool 4";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_MDV1: return "Multiplier/Divider Tool 1";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_MDV2: return "Multiplier/Divider Tool 2";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_MDV3: return "Multiplier/Divider Tool 3";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_MDV4: return "Multiplier/Divider Tool 4";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DEL1_1: return "Delay Tool 1 Output 1";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DEL1_2: return "Delay Tool 1 Output 2";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DEL2_1: return "Delay Tool 2 Output 1";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DEL2_2: return "Delay Tool 2 Output 2";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DEL3_1: return "Delay Tool 3 Output 1";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DEL3_2: return "Delay Tool 3 Output 2";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DEL4_1: return "Delay Tool 4 Output 1";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_DEL4_2: return "Delay Tool 4 Output 2";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_USER_EVENT_1: return "User Event 1";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_USER_EVENT_2: return "User Event 2";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_USER_EVENT_3: return "User Event 3";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_USER_EVENT_4: return "User Event 4";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_EIN1: return "Event Input Tool 1";
        case ge::EVENT_DATA_NUMID_IO_TOOLBOX_EIN2: return "Event Input Tool 2";
        case ge::EVENT_DATA_NUMID_CXP_INTERFACE_CRC_ERROR_CXP_A: return "Detected CRC error on CXP connector A";
        case ge::EVENT_DATA_NUMID_CXP_INTERFACE_CRC_ERROR_CXP_B: return "Detected CRC error on CXP connector B";
        case ge::EVENT_DATA_NUMID_CXP_INTERFACE_CRC_ERROR_CXP_C: return "Detected CRC error on CXP connector C";
        case ge::EVENT_DATA_NUMID_CXP_INTERFACE_CRC_ERROR_CXP_D: return "Detected CRC error on CXP connector D";
        case ge::EVENT_DATA_NUMID_CIC_CAMERA_TRIGGER_RISING_EDGE: return "Start of camera trigger";
        case ge::EVENT_DATA_NUMID_CIC_CAMERA_TRIGGER_FALLING_EDGE: return "End of camera trigger";
        case ge::EVENT_DATA_NUMID_CIC_STROBE_RISING_EDGE: return "Start of light strobe";
        case ge::EVENT_DATA_NUMID_CIC_STROBE_FALLING_EDGE: return "End of light strobe";
        case ge::EVENT_DATA_NUMID_CIC_ALLOW_NEXT_CYCLE: return "CIC is ready for next camera cycle";
        case ge::EVENT_DATA_NUMID_CIC_DISCARDED_CIC_TRIGGER: return "Ignored CIC trigger because CIC is not ready for next camera cycle";
        case ge::EVENT_DATA_NUMID_CIC_PENDING_CIC_TRIGGER: return "Delayed CIC trigger until CIC is ready for next camera cycle";
        case ge::EVENT_DATA_NUMID_CIC_CXP_TRIGGER_ACK: return "Received acknowledgement for previous CXP trigger message";
        case ge::EVENT_DATA_NUMID_CIC_CXP_TRIGGER_RESEND: return "Resent CXP trigger message (acknowledgement to previous CXP trigger message not received)";
        case ge::EVENT_DATA_NUMID_CIC_TRIGGER: return "CIC trigger";
        case ge::EVENT_DATA_NUMID_DATASTREAM_START_OF_CAMERA_READOUT: return "Starts acquiring data of a new image frame (area-scan only)";
        case ge::EVENT_DATA_NUMID_DATASTREAM_END_OF_CAMERA_READOUT: return "Stops acquiring data of an image frame (area-scan only)";
        case ge::EVENT_DATA_NUMID_DATASTREAM_START_OF_SCAN: return "Starts acquiring data of a new image scan (line-scan only )";
        case ge::EVENT_DATA_NUMID_DATASTREAM_END_OF_SCAN: return "Stops acquiring data of an image scan (line-scan only)";
        case ge::EVENT_DATA_NUMID_DATASTREAM_REJECTED_FRAME: return "Dropped image frame data  (area-scan only)";
        case ge::EVENT_DATA_NUMID_DATASTREAM_REJECTED_SCAN: return "Dropped image scan data (line-scan only)";
        default: return "unknown event";
    }
}
} // namespace EURESYS_NAMESPACE
