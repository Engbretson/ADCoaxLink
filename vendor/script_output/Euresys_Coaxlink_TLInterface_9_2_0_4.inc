/* /home/oxygen/MENGBRET/test/Euresys_Coaxlink_TLInterface_9_2_0 */ 

try { 
systemString = grabber.getString<Euresys::InterfaceModule>("InterfaceID"); 
status = setStringParam(COAXLINK_Interface_InterfaceID, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("InterfaceType"); 
status = setIntegerParam(COAXLINK_Interface_InterfaceType, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("SerialNumber"); 
status = setStringParam(COAXLINK_Interface_SerialNumber, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("PartNumber"); 
status = setStringParam(COAXLINK_Interface_PartNumber, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareRevision"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareRevision, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareVariant"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareVariant, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareStatus"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareStatus, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareRecoverySwitch"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareRecoverySwitch, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DeviceUpdateList"); 
status = setIntegerParam(COAXLINK_Interface_DeviceUpdateList, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DeviceSelector"); 
status = setIntegerParam(COAXLINK_Interface_DeviceSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("DeviceID"); 
status = setStringParam(COAXLINK_Interface_DeviceID, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("DeviceVendorName"); 
status = setStringParam(COAXLINK_Interface_DeviceVendorName, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("DeviceModelName"); 
status = setStringParam(COAXLINK_Interface_DeviceModelName, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DeviceAccessStatus"); 
status = setIntegerParam(COAXLINK_Interface_DeviceAccessStatus, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpHostConnectionSelector"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpHostConnectionSelector, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpAuto"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpAuto, systemInteger); 

} catch (const std::exception &e) { }  
*/ 


// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpTurnOff"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpTurnOff, systemInteger); 

} catch (const std::exception &e) { }  
*/ 


// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpTripReset"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpTripReset, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpConfigurationStatus"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpConfigurationStatus, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpStatus"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpStatus, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("CxpPoCxpCurrent"); 
status = setDoubleParam(COAXLINK_Interface_CxpPoCxpCurrent, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("CxpPoCxpVoltage"); 
status = setDoubleParam(COAXLINK_Interface_CxpPoCxpVoltage, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpPowerInputStatus"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpPowerInputStatus, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionCount"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionCount, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionSelector"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpConnectionState"); 
status = setIntegerParam(COAXLINK_Interface_CxpConnectionState, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpDownConnectionSpeed"); 
status = setIntegerParam(COAXLINK_Interface_CxpDownConnectionSpeed, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpDeviceConnectionID"); 
status = setIntegerParam(COAXLINK_Interface_CxpDeviceConnectionID, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP1Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP1Supported, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP2Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP2Supported, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP3Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP3Supported, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP5Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP5Supported, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP6Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP6Supported, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP10Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP10Supported, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP12Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP12Supported, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestMode"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionTestMode, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestErrorCount"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionTestErrorCount, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestPacketCount"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionTestPacketCount, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestInjectError"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionTestInjectError, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpRevisionSelector"); 
status = setIntegerParam(COAXLINK_Interface_CxpRevisionSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpRevisionSupport"); 
status = setIntegerParam(COAXLINK_Interface_CxpRevisionSupport, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineSelector"); 
status = setIntegerParam(COAXLINK_Interface_LineSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineFormat"); 
status = setIntegerParam(COAXLINK_Interface_LineFormat, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineMode"); 
status = setIntegerParam(COAXLINK_Interface_LineMode, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInverter"); 
status = setIntegerParam(COAXLINK_Interface_LineInverter, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineFilterStrength"); 
status = setIntegerParam(COAXLINK_Interface_LineFilterStrength, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("LineFilterDelay"); 
status = setDoubleParam(COAXLINK_Interface_LineFilterDelay, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineStatus"); 
status = setIntegerParam(COAXLINK_Interface_LineStatus, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineStatusAll"); 
status = setIntegerParam(COAXLINK_Interface_LineStatusAll, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineSource"); 
status = setIntegerParam(COAXLINK_Interface_LineSource, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("UserOutputValueAll"); 
status = setIntegerParam(COAXLINK_Interface_UserOutputValueAll, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("UserActions"); 
status = setIntegerParam(COAXLINK_Interface_UserActions, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("AddUserAction"); 
status = setIntegerParam(COAXLINK_Interface_AddUserAction, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ClearUserActions"); 
status = setIntegerParam(COAXLINK_Interface_ClearUserActions, systemInteger); 

} catch (const std::exception &e) { }  
*/ 


// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ExecuteUserActions"); 
status = setIntegerParam(COAXLINK_Interface_ExecuteUserActions, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ScheduleUserActions"); 
status = setIntegerParam(COAXLINK_Interface_ScheduleUserActions, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("UserActionsSchedulerReference"); 
status = setIntegerParam(COAXLINK_Interface_UserActionsSchedulerReference, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ScheduledUserActionsPoolStatus"); 
status = setIntegerParam(COAXLINK_Interface_ScheduledUserActionsPoolStatus, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DiscardScheduledUserActions"); 
status = setIntegerParam(COAXLINK_Interface_DiscardScheduledUserActions, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInputToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_LineInputToolSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInputToolSource"); 
status = setIntegerParam(COAXLINK_Interface_LineInputToolSource, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInputToolActivation"); 
status = setIntegerParam(COAXLINK_Interface_LineInputToolActivation, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_MultiplierDividerToolSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolSource"); 
status = setIntegerParam(COAXLINK_Interface_MultiplierDividerToolSource, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolOutputControl"); 
status = setIntegerParam(COAXLINK_Interface_MultiplierDividerToolOutputControl, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("MultiplierDividerToolMultiplicationFactor"); 
status = setDoubleParam(COAXLINK_Interface_MultiplierDividerToolMultiplicationFactor, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("MultiplierDividerToolDivisionFactor"); 
status = setDoubleParam(COAXLINK_Interface_MultiplierDividerToolDivisionFactor, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolEffectiveMultiplicationFactor"); 
status = setIntegerParam(COAXLINK_Interface_MultiplierDividerToolEffectiveMultiplicationFactor, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolEffectiveDivisionFactor"); 
status = setIntegerParam(COAXLINK_Interface_MultiplierDividerToolEffectiveDivisionFactor, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolSources"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolSources, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolActivation"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolActivation, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolForwardDirection"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolForwardDirection, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolOutputMode"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolOutputMode, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolPosition"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolPosition, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolDirection"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolDirection, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolPositionReset"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolPositionReset, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolSource"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolSource, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolEnableControl"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolEnableControl, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolDivisionFactor"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolDivisionFactor, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolInitialOffset"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolInitialOffset, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolSource1"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolSource1, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolSource2"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolSource2, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolClockSource"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolClockSource, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolDelayValue"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolDelayValue, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventInputToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_EventInputToolSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventInputToolSource"); 
status = setIntegerParam(COAXLINK_Interface_EventInputToolSource, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventInputToolActivation"); 
status = setIntegerParam(COAXLINK_Interface_EventInputToolActivation, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("InternalTime"); 
status = setIntegerParam(COAXLINK_Interface_InternalTime, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxPayloadSizeSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxPayloadSizeSupported, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxPayloadSize"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxPayloadSize, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxReadRequestSize"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxReadRequestSize, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxLinkSpeed"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxLinkSpeed, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeCurrentLinkSpeed"); 
status = setIntegerParam(COAXLINK_Interface_PCIeCurrentLinkSpeed, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaximumLinkWidth"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaximumLinkWidth, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeNegotiatedLinkWidth"); 
status = setIntegerParam(COAXLINK_Interface_PCIeNegotiatedLinkWidth, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeLinkSpeed2500MTpsSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeLinkSpeed2500MTpsSupported, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeLinkSpeed5000MTpsSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeLinkSpeed5000MTpsSupported, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeLinkSpeed8000MTpsSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeLinkSpeed8000MTpsSupported, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FanStatus"); 
status = setIntegerParam(COAXLINK_Interface_FanStatus, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("TemperatureSensorSelector"); 
status = setIntegerParam(COAXLINK_Interface_TemperatureSensorSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("Temperature"); 
status = setDoubleParam(COAXLINK_Interface_Temperature, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("AuxiliaryPowerInput"); 
status = setIntegerParam(COAXLINK_Interface_AuxiliaryPowerInput, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("AuxiliaryPower12VInput"); 
status = setIntegerParam(COAXLINK_Interface_AuxiliaryPower12VInput, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("BoardCapabilities"); 
status = setStringParam(COAXLINK_Interface_BoardCapabilities, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareBoardID"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareBoardID, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CPLDRevision"); 
status = setIntegerParam(COAXLINK_Interface_CPLDRevision, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PreviousBootBank"); 
status = setIntegerParam(COAXLINK_Interface_PreviousBootBank, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("NextBootBank"); 
status = setIntegerParam(COAXLINK_Interface_NextBootBank, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CurrentBankSelect"); 
status = setIntegerParam(COAXLINK_Interface_CurrentBankSelect, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CurrentBankSelectReadback"); 
status = setIntegerParam(COAXLINK_Interface_CurrentBankSelectReadback, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("NextBankSelect"); 
status = setIntegerParam(COAXLINK_Interface_NextBankSelect, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("SpiBankStatus"); 
status = setIntegerParam(COAXLINK_Interface_SpiBankStatus, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PotBankStatus"); 
status = setIntegerParam(COAXLINK_Interface_PotBankStatus, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventSelector"); 
status = setIntegerParam(COAXLINK_Interface_EventSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotification"); 
status = setIntegerParam(COAXLINK_Interface_EventNotification, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotificationContext1"); 
status = setIntegerParam(COAXLINK_Interface_EventNotificationContext1, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotificationContext2"); 
status = setIntegerParam(COAXLINK_Interface_EventNotificationContext2, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotificationContext3"); 
status = setIntegerParam(COAXLINK_Interface_EventNotificationContext3, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventCount"); 
status = setIntegerParam(COAXLINK_Interface_EventCount, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventCountReset"); 
status = setIntegerParam(COAXLINK_Interface_EventCountReset, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotificationAll"); 
status = setIntegerParam(COAXLINK_Interface_EventNotificationAll, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventCountResetAll"); 
status = setIntegerParam(COAXLINK_Interface_EventCountResetAll, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("OemSafetyKeyVerification"); 
status = setIntegerParam(COAXLINK_Interface_OemSafetyKeyVerification, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("CheckOemSafetyKey"); 
status = setStringParam(COAXLINK_Interface_CheckOemSafetyKey, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("ProgramOemSafetyKey"); 
status = setStringParam(COAXLINK_Interface_ProgramOemSafetyKey, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("EncryptedOemSafetyKey"); 
status = setStringParam(COAXLINK_Interface_EncryptedOemSafetyKey, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MaximumOemKeyLength"); 
status = setIntegerParam(COAXLINK_Interface_MaximumOemKeyLength, systemInteger); 

} catch (const std::exception &e) { }  
