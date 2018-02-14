/* ./Euresys_Coaxlink_TLDevice_6_2_4 */ 

std::vector<std::string> DeviceFeature(grabber.getStringList<Euresys::DeviceModule>(Euresys::Features())); 
std::set<std::string> isaDeviceFeature(DeviceFeature.begin(),DeviceFeature.end() ); 


if (isaDeviceFeature.count("DeviceID")) 
try { 
systemString = grabber.getString<Euresys::DeviceModule>("DeviceID"); 
status = setStringParam(COAXLINK_Device_DeviceID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceID \n "); }  

if (isaDeviceFeature.count("DeviceVendorName")) 
try { 
systemString = grabber.getString<Euresys::DeviceModule>("DeviceVendorName"); 
status = setStringParam(COAXLINK_Device_DeviceVendorName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceVendorName \n "); }  

if (isaDeviceFeature.count("DeviceModelName")) 
try { 
systemString = grabber.getString<Euresys::DeviceModule>("DeviceModelName"); 
status = setStringParam(COAXLINK_Device_DeviceModelName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceModelName \n "); }  

if (isaDeviceFeature.count("DeviceAccessStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("DeviceAccessStatus"); 
status = setIntegerParam(COAXLINK_Device_DeviceAccessStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceAccessStatus \n "); }  

if (isaDeviceFeature.count("DeviceType")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("DeviceType"); 
status = setIntegerParam(COAXLINK_Device_DeviceType, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceType \n "); }  

if (isaDeviceFeature.count("StreamSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StreamSelector"); 
status = setIntegerParam(COAXLINK_Device_StreamSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device StreamSelector \n "); } 

if (isaDeviceFeature.count("StreamID")) 
try { 
systemString = grabber.getString<Euresys::DeviceModule>("StreamID"); 
status = setStringParam(COAXLINK_Device_StreamID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Device StreamID \n "); }  

// start of an execute (write Only) command 
/* 

if (isaDeviceFeature.count("DeviceReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("DeviceReset"); 
status = setIntegerParam(COAXLINK_Device_DeviceReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceReset \n "); }  
*/ 


if (isaDeviceFeature.count("CameraControlMethod")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CameraControlMethod"); 
status = setIntegerParam(COAXLINK_Device_CameraControlMethod, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CameraControlMethod \n "); }  

if (isaDeviceFeature.count("C2CLinkConfiguration")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("C2CLinkConfiguration"); 
status = setIntegerParam(COAXLINK_Device_C2CLinkConfiguration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device C2CLinkConfiguration \n "); }  

if (isaDeviceFeature.count("ExposureReadoutOverlap")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ExposureReadoutOverlap"); 
status = setIntegerParam(COAXLINK_Device_ExposureReadoutOverlap, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device ExposureReadoutOverlap \n "); }  

if (isaDeviceFeature.count("ExposureRecoveryTime")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("ExposureRecoveryTime"); 
status = setDoubleParam(COAXLINK_Device_ExposureRecoveryTime, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device ExposureRecoveryTime \n "); }  

if (isaDeviceFeature.count("ExposureTime")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("ExposureTime"); 
status = setDoubleParam(COAXLINK_Device_ExposureTime, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device ExposureTime \n "); }  

if (isaDeviceFeature.count("StrobeDelay")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("StrobeDelay"); 
status = setDoubleParam(COAXLINK_Device_StrobeDelay, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device StrobeDelay \n "); }  

if (isaDeviceFeature.count("StrobeDuration")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("StrobeDuration"); 
status = setDoubleParam(COAXLINK_Device_StrobeDuration, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device StrobeDuration \n "); }  

if (isaDeviceFeature.count("CycleTriggerSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CycleTriggerSource"); 
status = setIntegerParam(COAXLINK_Device_CycleTriggerSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CycleTriggerSource \n "); }  

if (isaDeviceFeature.count("CycleTargetPeriod")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("CycleTargetPeriod"); 
status = setDoubleParam(COAXLINK_Device_CycleTargetPeriod, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device CycleTargetPeriod \n "); }  

// start of an execute (write Only) command 
/* 

if (isaDeviceFeature.count("StartCycle")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StartCycle"); 
status = setIntegerParam(COAXLINK_Device_StartCycle, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device StartCycle \n "); }  
*/ 


if (isaDeviceFeature.count("CycleLostTriggerCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CycleLostTriggerCount"); 
status = setIntegerParam(COAXLINK_Device_CycleLostTriggerCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CycleLostTriggerCount \n "); } 

// start of an execute (write Only) command 
/* 

if (isaDeviceFeature.count("CycleLostTriggerCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CycleLostTriggerCountReset"); 
status = setIntegerParam(COAXLINK_Device_CycleLostTriggerCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CycleLostTriggerCountReset \n "); }  
*/ 


if (isaDeviceFeature.count("StartOfSequenceTriggerSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StartOfSequenceTriggerSource"); 
status = setIntegerParam(COAXLINK_Device_StartOfSequenceTriggerSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device StartOfSequenceTriggerSource \n "); }  

if (isaDeviceFeature.count("StartSequence")) 
try { 
/* 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StartSequence"); 
status = setIntegerParam(COAXLINK_Device_StartSequence, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Device StartSequence \n "); }  

if (isaDeviceFeature.count("AbortSequence")) 
try { 
/* 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("AbortSequence"); 
status = setIntegerParam(COAXLINK_Device_AbortSequence, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Device AbortSequence \n "); }  

if (isaDeviceFeature.count("CxpLinkConfiguration")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpLinkConfiguration"); 
status = setIntegerParam(COAXLINK_Device_CxpLinkConfiguration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpLinkConfiguration \n "); }  

if (isaDeviceFeature.count("CxpLinkConfigurationOption")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpLinkConfigurationOption"); 
status = setIntegerParam(COAXLINK_Device_CxpLinkConfigurationOption, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpLinkConfigurationOption \n "); }  

if (isaDeviceFeature.count("CxpHostConnectionBase")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpHostConnectionBase"); 
status = setIntegerParam(COAXLINK_Device_CxpHostConnectionBase, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpHostConnectionBase \n "); }  

if (isaDeviceFeature.count("CxpHostConnectionCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpHostConnectionCount"); 
status = setIntegerParam(COAXLINK_Device_CxpHostConnectionCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpHostConnectionCount \n "); } 

if (isaDeviceFeature.count("CxpTriggerMessageFormat")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpTriggerMessageFormat"); 
status = setIntegerParam(COAXLINK_Device_CxpTriggerMessageFormat, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpTriggerMessageFormat \n "); }  

if (isaDeviceFeature.count("CxpTriggerAckTimeout")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("CxpTriggerAckTimeout"); 
status = setDoubleParam(COAXLINK_Device_CxpTriggerAckTimeout, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpTriggerAckTimeout \n "); }  

if (isaDeviceFeature.count("CxpTriggerMaxResendCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpTriggerMaxResendCount"); 
status = setIntegerParam(COAXLINK_Device_CxpTriggerMaxResendCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpTriggerMaxResendCount \n "); } 

// start of an execute (write Only) command 
/* 

if (isaDeviceFeature.count("CxpPacketArbiterReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpPacketArbiterReset"); 
status = setIntegerParam(COAXLINK_Device_CxpPacketArbiterReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpPacketArbiterReset \n "); }  
*/ 


if (isaDeviceFeature.count("EventSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventSelector"); 
status = setIntegerParam(COAXLINK_Device_EventSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventSelector \n "); }  

if (isaDeviceFeature.count("EventNotification")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotification"); 
status = setIntegerParam(COAXLINK_Device_EventNotification, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventNotification \n "); }  

if (isaDeviceFeature.count("EventNotificationContext1")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotificationContext1"); 
status = setIntegerParam(COAXLINK_Device_EventNotificationContext1, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventNotificationContext1 \n "); }  

if (isaDeviceFeature.count("EventNotificationContext2")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotificationContext2"); 
status = setIntegerParam(COAXLINK_Device_EventNotificationContext2, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventNotificationContext2 \n "); }  

if (isaDeviceFeature.count("EventNotificationContext3")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotificationContext3"); 
status = setIntegerParam(COAXLINK_Device_EventNotificationContext3, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventNotificationContext3 \n "); }  

if (isaDeviceFeature.count("EventCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventCount"); 
status = setIntegerParam(COAXLINK_Device_EventCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventCount \n "); } 

// start of an execute (write Only) command 
/* 

if (isaDeviceFeature.count("EventCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventCountReset"); 
status = setIntegerParam(COAXLINK_Device_EventCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventCountReset \n "); }  
*/ 


if (isaDeviceFeature.count("ErrorSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorSelector"); 
status = setIntegerParam(COAXLINK_Device_ErrorSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device ErrorSelector \n "); }  

if (isaDeviceFeature.count("ErrorCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorCount"); 
status = setIntegerParam(COAXLINK_Device_ErrorCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device ErrorCount \n "); } 

// start of an execute (write Only) command 
/* 

if (isaDeviceFeature.count("ErrorCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorCountReset"); 
status = setIntegerParam(COAXLINK_Device_ErrorCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device ErrorCountReset \n "); }  
*/ 

