/* ./Euresys_Coaxlink_TLDevice_6_2_4 */ 

try { 
systemString = grabber.getString<Euresys::DeviceModule>("DeviceID"); 
status = setStringParam(COAXLINK_Device_DeviceID, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::DeviceModule>("DeviceVendorName"); 
status = setStringParam(COAXLINK_Device_DeviceVendorName, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::DeviceModule>("DeviceModelName"); 
status = setStringParam(COAXLINK_Device_DeviceModelName, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("DeviceAccessStatus"); 
status = setIntegerParam(COAXLINK_Device_DeviceAccessStatus, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("DeviceType"); 
status = setIntegerParam(COAXLINK_Device_DeviceType, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StreamSelector"); 
status = setIntegerParam(COAXLINK_Device_StreamSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::DeviceModule>("StreamID"); 
status = setStringParam(COAXLINK_Device_StreamID, systemString.c_str()); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("DeviceReset"); 
status = setIntegerParam(COAXLINK_Device_DeviceReset, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CameraControlMethod"); 
status = setIntegerParam(COAXLINK_Device_CameraControlMethod, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("C2CLinkConfiguration"); 
status = setIntegerParam(COAXLINK_Device_C2CLinkConfiguration, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ExposureReadoutOverlap"); 
status = setIntegerParam(COAXLINK_Device_ExposureReadoutOverlap, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("ExposureRecoveryTime"); 
status = setDoubleParam(COAXLINK_Device_ExposureRecoveryTime, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("ExposureTime"); 
status = setDoubleParam(COAXLINK_Device_ExposureTime, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("StrobeDelay"); 
status = setDoubleParam(COAXLINK_Device_StrobeDelay, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("StrobeDuration"); 
status = setDoubleParam(COAXLINK_Device_StrobeDuration, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CycleTriggerSource"); 
status = setIntegerParam(COAXLINK_Device_CycleTriggerSource, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("CycleTargetPeriod"); 
status = setDoubleParam(COAXLINK_Device_CycleTargetPeriod, systemDouble); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StartCycle"); 
status = setIntegerParam(COAXLINK_Device_StartCycle, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CycleLostTriggerCount"); 
status = setIntegerParam(COAXLINK_Device_CycleLostTriggerCount, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CycleLostTriggerCountReset"); 
status = setIntegerParam(COAXLINK_Device_CycleLostTriggerCountReset, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StartOfSequenceTriggerSource"); 
status = setIntegerParam(COAXLINK_Device_StartOfSequenceTriggerSource, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StartSequence"); 
status = setIntegerParam(COAXLINK_Device_StartSequence, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("AbortSequence"); 
status = setIntegerParam(COAXLINK_Device_AbortSequence, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpLinkConfiguration"); 
status = setIntegerParam(COAXLINK_Device_CxpLinkConfiguration, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpLinkConfigurationOption"); 
status = setIntegerParam(COAXLINK_Device_CxpLinkConfigurationOption, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpHostConnectionBase"); 
status = setIntegerParam(COAXLINK_Device_CxpHostConnectionBase, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpHostConnectionCount"); 
status = setIntegerParam(COAXLINK_Device_CxpHostConnectionCount, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpTriggerMessageFormat"); 
status = setIntegerParam(COAXLINK_Device_CxpTriggerMessageFormat, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("CxpTriggerAckTimeout"); 
status = setDoubleParam(COAXLINK_Device_CxpTriggerAckTimeout, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpTriggerMaxResendCount"); 
status = setIntegerParam(COAXLINK_Device_CxpTriggerMaxResendCount, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpPacketArbiterReset"); 
status = setIntegerParam(COAXLINK_Device_CxpPacketArbiterReset, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventSelector"); 
status = setIntegerParam(COAXLINK_Device_EventSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotification"); 
status = setIntegerParam(COAXLINK_Device_EventNotification, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotificationContext1"); 
status = setIntegerParam(COAXLINK_Device_EventNotificationContext1, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotificationContext2"); 
status = setIntegerParam(COAXLINK_Device_EventNotificationContext2, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotificationContext3"); 
status = setIntegerParam(COAXLINK_Device_EventNotificationContext3, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventCount"); 
status = setIntegerParam(COAXLINK_Device_EventCount, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventCountReset"); 
status = setIntegerParam(COAXLINK_Device_EventCountReset, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorSelector"); 
status = setIntegerParam(COAXLINK_Device_ErrorSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorCount"); 
status = setIntegerParam(COAXLINK_Device_ErrorCount, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorCountReset"); 
status = setIntegerParam(COAXLINK_Device_ErrorCountReset, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

