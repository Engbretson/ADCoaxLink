/* ./Euresys_Coaxlink_TLInterface_6_2_4 */ 

std::vector<std::string> InterfaceFeature(grabber.getStringList<Euresys::InterfaceModule>(Euresys::Features())); 
std::set<std::string> isaInterfaceFeature(InterfaceFeature.begin(),InterfaceFeature.end() ); 


if (isaInterfaceFeature.count("InterfaceID")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("InterfaceID"); 
status = setStringParam(COAXLINK_Interface_InterfaceID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface InterfaceID \n "); }  

if (isaInterfaceFeature.count("InterfaceType")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("InterfaceType"); 
status = setIntegerParam(COAXLINK_Interface_InterfaceType, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface InterfaceType \n "); }  

if (isaInterfaceFeature.count("SerialNumber")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("SerialNumber"); 
status = setStringParam(COAXLINK_Interface_SerialNumber, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface SerialNumber \n "); }  

if (isaInterfaceFeature.count("PartNumber")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("PartNumber"); 
status = setStringParam(COAXLINK_Interface_PartNumber, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface PartNumber \n "); }  

if (isaInterfaceFeature.count("FirmwareRevision")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareRevision"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareRevision, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FirmwareRevision \n "); } 

if (isaInterfaceFeature.count("FirmwareVariant")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareVariant"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareVariant, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FirmwareVariant \n "); } 

if (isaInterfaceFeature.count("FirmwareStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareStatus"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FirmwareStatus \n "); }  

if (isaInterfaceFeature.count("FirmwareRecoverySwitch")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareRecoverySwitch"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareRecoverySwitch, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FirmwareRecoverySwitch \n "); }  

// start of an execute (write Only) command 
/* 

if (isaInterfaceFeature.count("DeviceUpdateList")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DeviceUpdateList"); 
status = setIntegerParam(COAXLINK_Interface_DeviceUpdateList, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceUpdateList \n "); }  
*/ 


if (isaInterfaceFeature.count("DeviceSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DeviceSelector"); 
status = setIntegerParam(COAXLINK_Interface_DeviceSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceSelector \n "); } 

if (isaInterfaceFeature.count("DeviceID")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("DeviceID"); 
status = setStringParam(COAXLINK_Interface_DeviceID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceID \n "); }  

if (isaInterfaceFeature.count("DeviceVendorName")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("DeviceVendorName"); 
status = setStringParam(COAXLINK_Interface_DeviceVendorName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceVendorName \n "); }  

if (isaInterfaceFeature.count("DeviceModelName")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("DeviceModelName"); 
status = setStringParam(COAXLINK_Interface_DeviceModelName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceModelName \n "); }  

if (isaInterfaceFeature.count("DeviceAccessStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DeviceAccessStatus"); 
status = setIntegerParam(COAXLINK_Interface_DeviceAccessStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceAccessStatus \n "); }  

if (isaInterfaceFeature.count("CxpPoCxpHostConnectionSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpHostConnectionSelector"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpHostConnectionSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpHostConnectionSelector \n "); }  

// start of an execute (write Only) command 
/* 

if (isaInterfaceFeature.count("CxpPoCxpAuto")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpAuto"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpAuto, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpAuto \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaInterfaceFeature.count("CxpPoCxpTurnOff")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpTurnOff"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpTurnOff, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpTurnOff \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaInterfaceFeature.count("CxpPoCxpTripReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpTripReset"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpTripReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpTripReset \n "); }  
*/ 


if (isaInterfaceFeature.count("CxpPoCxpConfigurationStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpConfigurationStatus"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpConfigurationStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpConfigurationStatus \n "); }  

if (isaInterfaceFeature.count("CxpPoCxpStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpStatus"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpStatus \n "); }  

if (isaInterfaceFeature.count("CxpPoCxpCurrent")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("CxpPoCxpCurrent"); 
status = setDoubleParam(COAXLINK_Interface_CxpPoCxpCurrent, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpCurrent \n "); }  

if (isaInterfaceFeature.count("CxpPoCxpVoltage")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("CxpPoCxpVoltage"); 
status = setDoubleParam(COAXLINK_Interface_CxpPoCxpVoltage, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpVoltage \n "); }  

if (isaInterfaceFeature.count("CxpPoCxpPowerInputStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpPowerInputStatus"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpPowerInputStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpPowerInputStatus \n "); }  

if (isaInterfaceFeature.count("CxpHostConnectionCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionCount"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionCount \n "); } 

if (isaInterfaceFeature.count("CxpHostConnectionSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionSelector"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionSelector \n "); }  

if (isaInterfaceFeature.count("CxpConnectionState")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpConnectionState"); 
status = setIntegerParam(COAXLINK_Interface_CxpConnectionState, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpConnectionState \n "); }  

if (isaInterfaceFeature.count("CxpDownConnectionSpeed")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpDownConnectionSpeed"); 
status = setIntegerParam(COAXLINK_Interface_CxpDownConnectionSpeed, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpDownConnectionSpeed \n "); }  

if (isaInterfaceFeature.count("CxpDeviceConnectionID")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpDeviceConnectionID"); 
status = setIntegerParam(COAXLINK_Interface_CxpDeviceConnectionID, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpDeviceConnectionID \n "); }  

if (isaInterfaceFeature.count("CxpHostConnectionTestMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestMode"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionTestMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionTestMode \n "); }  

if (isaInterfaceFeature.count("CxpHostConnectionTestErrorCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestErrorCount"); 
status = setIntegerParam(COAXLINK_Interface_tErrorCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionTestErrorCount \n "); } 

if (isaInterfaceFeature.count("CxpHostConnectionTestPacketCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestPacketCount"); 
status = setIntegerParam(COAXLINK_Interface_tPacketCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionTestPacketCount \n "); } 

// start of an execute (write Only) command 
/* 

if (isaInterfaceFeature.count("CxpHostConnectionTestInjectError")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestInjectError"); 
status = setIntegerParam(COAXLINK_Interface_tInjectError, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionTestInjectError \n "); }  
*/ 


if (isaInterfaceFeature.count("CxpRevisionSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpRevisionSelector"); 
status = setIntegerParam(COAXLINK_Interface_CxpRevisionSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpRevisionSelector \n "); }  

if (isaInterfaceFeature.count("CxpRevisionSupport")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpRevisionSupport"); 
status = setIntegerParam(COAXLINK_Interface_CxpRevisionSupport, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpRevisionSupport \n "); }  

if (isaInterfaceFeature.count("LineSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineSelector"); 
status = setIntegerParam(COAXLINK_Interface_LineSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineSelector \n "); }  

if (isaInterfaceFeature.count("LineFormat")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineFormat"); 
status = setIntegerParam(COAXLINK_Interface_LineFormat, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineFormat \n "); }  

if (isaInterfaceFeature.count("LineMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineMode"); 
status = setIntegerParam(COAXLINK_Interface_LineMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineMode \n "); }  

if (isaInterfaceFeature.count("LineInverter")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInverter"); 
status = setIntegerParam(COAXLINK_Interface_LineInverter, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineInverter \n "); }  

if (isaInterfaceFeature.count("LineFilterStrength")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineFilterStrength"); 
status = setIntegerParam(COAXLINK_Interface_LineFilterStrength, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineFilterStrength \n "); }  

if (isaInterfaceFeature.count("LineFilterDelay")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("LineFilterDelay"); 
status = setDoubleParam(COAXLINK_Interface_LineFilterDelay, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineFilterDelay \n "); }  

if (isaInterfaceFeature.count("LineStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineStatus"); 
status = setIntegerParam(COAXLINK_Interface_LineStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineStatus \n "); }  

if (isaInterfaceFeature.count("LineStatusAll")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineStatusAll"); 
status = setIntegerParam(COAXLINK_Interface_LineStatusAll, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineStatusAll \n "); } 

if (isaInterfaceFeature.count("LineSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineSource"); 
status = setIntegerParam(COAXLINK_Interface_LineSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineSource \n "); }  

if (isaInterfaceFeature.count("UserOutputValueAll")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("UserOutputValueAll"); 
status = setIntegerParam(COAXLINK_Interface_UserOutputValueAll, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface UserOutputValueAll \n "); } 

if (isaInterfaceFeature.count("UserActions")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("UserActions"); 
status = setIntegerParam(COAXLINK_Interface_UserActions, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface UserActions \n "); } 

if (isaInterfaceFeature.count("AddUserAction")) 
try { 
/* 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("AddUserAction"); 
status = setIntegerParam(COAXLINK_Interface_AddUserAction, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Interface AddUserAction \n "); }  

// start of an execute (write Only) command 
/* 

if (isaInterfaceFeature.count("ClearUserActions")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ClearUserActions"); 
status = setIntegerParam(COAXLINK_Interface_ClearUserActions, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface ClearUserActions \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaInterfaceFeature.count("ExecuteUserActions")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ExecuteUserActions"); 
status = setIntegerParam(COAXLINK_Interface_ExecuteUserActions, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface ExecuteUserActions \n "); }  
*/ 


if (isaInterfaceFeature.count("ScheduleUserActions")) 
try { 
/* 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ScheduleUserActions"); 
status = setIntegerParam(COAXLINK_Interface_ScheduleUserActions, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Interface ScheduleUserActions \n "); } 

if (isaInterfaceFeature.count("UserActionsSchedulerReference")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("UserActionsSchedulerReference"); 
status = setIntegerParam(COAXLINK_Interface_UserActionsSchedulerReference, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface UserActionsSchedulerReference \n "); }  

if (isaInterfaceFeature.count("ScheduledUserActionsPoolStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ScheduledUserActionsPoolStatus"); 
status = setIntegerParam(COAXLINK_Interface_ScheduledUserActionsPoolStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface ScheduledUserActionsPoolStatus \n "); }  

// start of an execute (write Only) command 
/* 

if (isaInterfaceFeature.count("DiscardScheduledUserActions")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DiscardScheduledUserActions"); 
status = setIntegerParam(COAXLINK_Interface_DiscardScheduledUserActions, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DiscardScheduledUserActions \n "); }  
*/ 


if (isaInterfaceFeature.count("LineInputToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInputToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_LineInputToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineInputToolSelector \n "); }  

if (isaInterfaceFeature.count("LineInputToolSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInputToolSource"); 
status = setIntegerParam(COAXLINK_Interface_LineInputToolSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineInputToolSource \n "); }  

if (isaInterfaceFeature.count("LineInputToolActivation")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInputToolActivation"); 
status = setIntegerParam(COAXLINK_Interface_LineInputToolActivation, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineInputToolActivation \n "); }  

if (isaInterfaceFeature.count("MultiplierDividerToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_MultiplierDividerToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolSelector \n "); }  

if (isaInterfaceFeature.count("MultiplierDividerToolSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolSource"); 
status = setIntegerParam(COAXLINK_Interface_MultiplierDividerToolSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolSource \n "); }  

if (isaInterfaceFeature.count("MultiplierDividerToolOutputControl")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolOutputControl"); 
status = setIntegerParam(COAXLINK_Interface_lOutputControl, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolOutputControl \n "); }  

if (isaInterfaceFeature.count("MultiplierDividerToolMultiplicationFactor")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("MultiplierDividerToolMultiplicationFactor"); 
status = setDoubleParam(COAXLINK_Interface_lMultiplicationFactor, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolMultiplicationFactor \n "); }  

if (isaInterfaceFeature.count("MultiplierDividerToolDivisionFactor")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("MultiplierDividerToolDivisionFactor"); 
status = setDoubleParam(COAXLINK_Interface_lDivisionFactor, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolDivisionFactor \n "); }  

if (isaInterfaceFeature.count("MultiplierDividerToolEffectiveMultiplicationFactor")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolEffectiveMultiplicationFactor"); 
status = setIntegerParam(COAXLINK_Interface_lEffectiveMultiplicationFactor, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolEffectiveMultiplicationFactor \n "); } 

if (isaInterfaceFeature.count("MultiplierDividerToolEffectiveDivisionFactor")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolEffectiveDivisionFactor"); 
status = setIntegerParam(COAXLINK_Interface_lEffectiveDivisionFactor, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolEffectiveDivisionFactor \n "); } 

if (isaInterfaceFeature.count("QuadratureDecoderToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolSelector \n "); }  

if (isaInterfaceFeature.count("QuadratureDecoderToolSources")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolSources"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolSources, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolSources \n "); }  

if (isaInterfaceFeature.count("QuadratureDecoderToolActivation")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolActivation"); 
status = setIntegerParam(COAXLINK_Interface_lActivation, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolActivation \n "); }  

if (isaInterfaceFeature.count("QuadratureDecoderToolForwardDirection")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolForwardDirection"); 
status = setIntegerParam(COAXLINK_Interface_lForwardDirection, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolForwardDirection \n "); }  

if (isaInterfaceFeature.count("QuadratureDecoderToolOutputMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolOutputMode"); 
status = setIntegerParam(COAXLINK_Interface_lOutputMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolOutputMode \n "); }  

if (isaInterfaceFeature.count("QuadratureDecoderToolPosition")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolPosition"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolPosition, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolPosition \n "); } 

if (isaInterfaceFeature.count("QuadratureDecoderToolDirection")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolDirection"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolDirection, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolDirection \n "); }  

// start of an execute (write Only) command 
/* 

if (isaInterfaceFeature.count("QuadratureDecoderToolPositionReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolPositionReset"); 
status = setIntegerParam(COAXLINK_Interface_lPositionReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolPositionReset \n "); }  
*/ 


if (isaInterfaceFeature.count("DividerToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DividerToolSelector \n "); }  

if (isaInterfaceFeature.count("DividerToolSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolSource"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DividerToolSource \n "); }  

if (isaInterfaceFeature.count("DividerToolEnableControl")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolEnableControl"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolEnableControl, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DividerToolEnableControl \n "); }  

if (isaInterfaceFeature.count("DividerToolDivisionFactor")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolDivisionFactor"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolDivisionFactor, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DividerToolDivisionFactor \n "); } 

if (isaInterfaceFeature.count("DividerToolInitialOffset")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolInitialOffset"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolInitialOffset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DividerToolInitialOffset \n "); } 

if (isaInterfaceFeature.count("DelayToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DelayToolSelector \n "); }  

if (isaInterfaceFeature.count("DelayToolSource1")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolSource1"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolSource1, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DelayToolSource1 \n "); }  

if (isaInterfaceFeature.count("DelayToolSource2")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolSource2"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolSource2, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DelayToolSource2 \n "); }  

if (isaInterfaceFeature.count("DelayToolClockSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolClockSource"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolClockSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DelayToolClockSource \n "); }  

if (isaInterfaceFeature.count("DelayToolDelayValue")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolDelayValue"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolDelayValue, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DelayToolDelayValue \n "); } 

if (isaInterfaceFeature.count("EventInputToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventInputToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_EventInputToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventInputToolSelector \n "); }  

if (isaInterfaceFeature.count("EventInputToolSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventInputToolSource"); 
status = setIntegerParam(COAXLINK_Interface_EventInputToolSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventInputToolSource \n "); }  

if (isaInterfaceFeature.count("EventInputToolActivation")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventInputToolActivation"); 
status = setIntegerParam(COAXLINK_Interface_EventInputToolActivation, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventInputToolActivation \n "); }  

if (isaInterfaceFeature.count("InternalTime")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("InternalTime"); 
status = setIntegerParam(COAXLINK_Interface_InternalTime, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface InternalTime \n "); } 

if (isaInterfaceFeature.count("PCIeMaxPayloadSizeSupported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxPayloadSizeSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxPayloadSizeSupported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeMaxPayloadSizeSupported \n "); } 

if (isaInterfaceFeature.count("PCIeMaxPayloadSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxPayloadSize"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxPayloadSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeMaxPayloadSize \n "); } 

if (isaInterfaceFeature.count("PCIeMaxReadRequestSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxReadRequestSize"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxReadRequestSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeMaxReadRequestSize \n "); } 

if (isaInterfaceFeature.count("PCIeMaxLinkSpeed")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxLinkSpeed"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxLinkSpeed, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeMaxLinkSpeed \n "); }  

if (isaInterfaceFeature.count("PCIeCurrentLinkSpeed")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeCurrentLinkSpeed"); 
status = setIntegerParam(COAXLINK_Interface_PCIeCurrentLinkSpeed, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeCurrentLinkSpeed \n "); }  

if (isaInterfaceFeature.count("PCIeMaximumLinkWidth")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaximumLinkWidth"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaximumLinkWidth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeMaximumLinkWidth \n "); }  

if (isaInterfaceFeature.count("PCIeNegotiatedLinkWidth")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeNegotiatedLinkWidth"); 
status = setIntegerParam(COAXLINK_Interface_PCIeNegotiatedLinkWidth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeNegotiatedLinkWidth \n "); }  

if (isaInterfaceFeature.count("PCIeLinkSpeed2500MTpsSupported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeLinkSpeed2500MTpsSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeLinkSpeed2500MTpsSupported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeLinkSpeed2500MTpsSupported \n "); }  

if (isaInterfaceFeature.count("PCIeLinkSpeed5000MTpsSupported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeLinkSpeed5000MTpsSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeLinkSpeed5000MTpsSupported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeLinkSpeed5000MTpsSupported \n "); }  

if (isaInterfaceFeature.count("PCIeLinkSpeed8000MTpsSupported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeLinkSpeed8000MTpsSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeLinkSpeed8000MTpsSupported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeLinkSpeed8000MTpsSupported \n "); }  

if (isaInterfaceFeature.count("FanStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FanStatus"); 
status = setIntegerParam(COAXLINK_Interface_FanStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FanStatus \n "); }  

if (isaInterfaceFeature.count("TemperatureSensorSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("TemperatureSensorSelector"); 
status = setIntegerParam(COAXLINK_Interface_TemperatureSensorSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface TemperatureSensorSelector \n "); }  

if (isaInterfaceFeature.count("Temperature")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("Temperature"); 
status = setDoubleParam(COAXLINK_Interface_Temperature, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface Temperature \n "); }  

if (isaInterfaceFeature.count("AuxiliaryPowerInput")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("AuxiliaryPowerInput"); 
status = setIntegerParam(COAXLINK_Interface_AuxiliaryPowerInput, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface AuxiliaryPowerInput \n "); }  

if (isaInterfaceFeature.count("AuxiliaryPower12VInput")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("AuxiliaryPower12VInput"); 
status = setIntegerParam(COAXLINK_Interface_AuxiliaryPower12VInput, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface AuxiliaryPower12VInput \n "); }  

if (isaInterfaceFeature.count("BoardCapabilities")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("BoardCapabilities"); 
status = setStringParam(COAXLINK_Interface_BoardCapabilities, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface BoardCapabilities \n "); }  

if (isaInterfaceFeature.count("FirmwareBoardID")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareBoardID"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareBoardID, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FirmwareBoardID \n "); } 

if (isaInterfaceFeature.count("CPLDRevision")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CPLDRevision"); 
status = setIntegerParam(COAXLINK_Interface_CPLDRevision, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CPLDRevision \n "); } 

if (isaInterfaceFeature.count("PreviousBootBank")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PreviousBootBank"); 
status = setIntegerParam(COAXLINK_Interface_PreviousBootBank, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PreviousBootBank \n "); } 

if (isaInterfaceFeature.count("NextBootBank")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("NextBootBank"); 
status = setIntegerParam(COAXLINK_Interface_NextBootBank, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface NextBootBank \n "); } 

if (isaInterfaceFeature.count("CurrentBankSelect")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CurrentBankSelect"); 
status = setIntegerParam(COAXLINK_Interface_CurrentBankSelect, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CurrentBankSelect \n "); } 

if (isaInterfaceFeature.count("CurrentBankSelectReadback")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CurrentBankSelectReadback"); 
status = setIntegerParam(COAXLINK_Interface_CurrentBankSelectReadback, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CurrentBankSelectReadback \n "); } 

if (isaInterfaceFeature.count("NextBankSelect")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("NextBankSelect"); 
status = setIntegerParam(COAXLINK_Interface_NextBankSelect, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface NextBankSelect \n "); } 

if (isaInterfaceFeature.count("SpiBankStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("SpiBankStatus"); 
status = setIntegerParam(COAXLINK_Interface_SpiBankStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface SpiBankStatus \n "); } 

if (isaInterfaceFeature.count("PotBankStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PotBankStatus"); 
status = setIntegerParam(COAXLINK_Interface_PotBankStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PotBankStatus \n "); } 

if (isaInterfaceFeature.count("EventSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventSelector"); 
status = setIntegerParam(COAXLINK_Interface_EventSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventSelector \n "); }  

if (isaInterfaceFeature.count("EventNotification")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotification"); 
status = setIntegerParam(COAXLINK_Interface_EventNotification, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventNotification \n "); }  

if (isaInterfaceFeature.count("EventNotificationContext1")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotificationContext1"); 
status = setIntegerParam(COAXLINK_Interface_EventNotificationContext1, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventNotificationContext1 \n "); }  

if (isaInterfaceFeature.count("EventNotificationContext2")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotificationContext2"); 
status = setIntegerParam(COAXLINK_Interface_EventNotificationContext2, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventNotificationContext2 \n "); }  

if (isaInterfaceFeature.count("EventNotificationContext3")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotificationContext3"); 
status = setIntegerParam(COAXLINK_Interface_EventNotificationContext3, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventNotificationContext3 \n "); }  

if (isaInterfaceFeature.count("EventCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventCount"); 
status = setIntegerParam(COAXLINK_Interface_EventCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventCount \n "); } 

// start of an execute (write Only) command 
/* 

if (isaInterfaceFeature.count("EventCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventCountReset"); 
status = setIntegerParam(COAXLINK_Interface_EventCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventCountReset \n "); }  
*/ 


if (isaInterfaceFeature.count("OemSafetyKeyVerification")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("OemSafetyKeyVerification"); 
status = setIntegerParam(COAXLINK_Interface_OemSafetyKeyVerification, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface OemSafetyKeyVerification \n "); }  

if (isaInterfaceFeature.count("CheckOemSafetyKey")) 
try { 
/* 
systemString = grabber.getString<Euresys::InterfaceModule>("CheckOemSafetyKey"); 
status = setStringParam(COAXLINK_Interface_CheckOemSafetyKey, systemString.c_str()); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Interface CheckOemSafetyKey \n "); }  

if (isaInterfaceFeature.count("ProgramOemSafetyKey")) 
try { 
/* 
systemString = grabber.getString<Euresys::InterfaceModule>("ProgramOemSafetyKey"); 
status = setStringParam(COAXLINK_Interface_ProgramOemSafetyKey, systemString.c_str()); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Interface ProgramOemSafetyKey \n "); }  

if (isaInterfaceFeature.count("EncryptedOemSafetyKey")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("EncryptedOemSafetyKey"); 
status = setStringParam(COAXLINK_Interface_EncryptedOemSafetyKey, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface EncryptedOemSafetyKey \n "); }  
