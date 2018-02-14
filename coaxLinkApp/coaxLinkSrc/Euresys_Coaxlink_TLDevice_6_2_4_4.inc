/* ./Euresys_Coaxlink_TLDevice_6_2_4 */ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("DeviceID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceID")) 
try { 
systemString = grabber.getString<Euresys::DeviceModule>("DeviceID"); 
status = setStringParam(COAXLINK_Device_DeviceID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceID \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("DeviceVendorName")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceVendorName")) 
try { 
systemString = grabber.getString<Euresys::DeviceModule>("DeviceVendorName"); 
status = setStringParam(COAXLINK_Device_DeviceVendorName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceVendorName \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("DeviceModelName")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceModelName")) 
try { 
systemString = grabber.getString<Euresys::DeviceModule>("DeviceModelName"); 
status = setStringParam(COAXLINK_Device_DeviceModelName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceModelName \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("DeviceAccessStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceAccessStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("DeviceAccessStatus"); 
status = setIntegerParam(COAXLINK_Device_DeviceAccessStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceAccessStatus \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("DeviceType")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceType")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("DeviceType"); 
status = setIntegerParam(COAXLINK_Device_DeviceType, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceType \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("StreamSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StreamSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StreamSelector"); 
status = setIntegerParam(COAXLINK_Device_StreamSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device StreamSelector \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("StreamID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StreamID")) 
try { 
systemString = grabber.getString<Euresys::DeviceModule>("StreamID"); 
status = setStringParam(COAXLINK_Device_StreamID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Device StreamID \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("DeviceReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("DeviceReset"); 
status = setIntegerParam(COAXLINK_Device_DeviceReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device DeviceReset \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CameraControlMethod")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CameraControlMethod")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CameraControlMethod"); 
status = setIntegerParam(COAXLINK_Device_CameraControlMethod, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CameraControlMethod \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("C2CLinkConfiguration")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("C2CLinkConfiguration")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("C2CLinkConfiguration"); 
status = setIntegerParam(COAXLINK_Device_C2CLinkConfiguration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device C2CLinkConfiguration \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("ExposureReadoutOverlap")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ExposureReadoutOverlap")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ExposureReadoutOverlap"); 
status = setIntegerParam(COAXLINK_Device_ExposureReadoutOverlap, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device ExposureReadoutOverlap \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("ExposureRecoveryTime")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ExposureRecoveryTime")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("ExposureRecoveryTime"); 
status = setDoubleParam(COAXLINK_Device_ExposureRecoveryTime, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device ExposureRecoveryTime \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("ExposureTime")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ExposureTime")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("ExposureTime"); 
status = setDoubleParam(COAXLINK_Device_ExposureTime, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device ExposureTime \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("StrobeDelay")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StrobeDelay")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("StrobeDelay"); 
status = setDoubleParam(COAXLINK_Device_StrobeDelay, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device StrobeDelay \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("StrobeDuration")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StrobeDuration")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("StrobeDuration"); 
status = setDoubleParam(COAXLINK_Device_StrobeDuration, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device StrobeDuration \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CycleTriggerSource")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CycleTriggerSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CycleTriggerSource"); 
status = setIntegerParam(COAXLINK_Device_CycleTriggerSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CycleTriggerSource \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CycleTargetPeriod")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CycleTargetPeriod")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("CycleTargetPeriod"); 
status = setDoubleParam(COAXLINK_Device_CycleTargetPeriod, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device CycleTargetPeriod \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("StartCycle")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StartCycle")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StartCycle"); 
status = setIntegerParam(COAXLINK_Device_StartCycle, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device StartCycle \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CycleLostTriggerCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CycleLostTriggerCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CycleLostTriggerCount"); 
status = setIntegerParam(COAXLINK_Device_CycleLostTriggerCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CycleLostTriggerCount \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CycleLostTriggerCountReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CycleLostTriggerCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CycleLostTriggerCountReset"); 
status = setIntegerParam(COAXLINK_Device_CycleLostTriggerCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CycleLostTriggerCountReset \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("StartOfSequenceTriggerSource")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StartOfSequenceTriggerSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StartOfSequenceTriggerSource"); 
status = setIntegerParam(COAXLINK_Device_StartOfSequenceTriggerSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device StartOfSequenceTriggerSource \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("StartSequence")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StartSequence")) 
try { 
/* 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("StartSequence"); 
status = setIntegerParam(COAXLINK_Device_StartSequence, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Device StartSequence \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("AbortSequence")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AbortSequence")) 
try { 
/* 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("AbortSequence"); 
status = setIntegerParam(COAXLINK_Device_AbortSequence, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Device AbortSequence \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CxpLinkConfiguration")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpLinkConfiguration")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpLinkConfiguration"); 
status = setIntegerParam(COAXLINK_Device_CxpLinkConfiguration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpLinkConfiguration \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CxpLinkConfigurationOption")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpLinkConfigurationOption")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpLinkConfigurationOption"); 
status = setIntegerParam(COAXLINK_Device_CxpLinkConfigurationOption, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpLinkConfigurationOption \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CxpHostConnectionBase")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpHostConnectionBase")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpHostConnectionBase"); 
status = setIntegerParam(COAXLINK_Device_CxpHostConnectionBase, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpHostConnectionBase \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CxpHostConnectionCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpHostConnectionCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpHostConnectionCount"); 
status = setIntegerParam(COAXLINK_Device_CxpHostConnectionCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpHostConnectionCount \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CxpTriggerMessageFormat")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpTriggerMessageFormat")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpTriggerMessageFormat"); 
status = setIntegerParam(COAXLINK_Device_CxpTriggerMessageFormat, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpTriggerMessageFormat \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CxpTriggerAckTimeout")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpTriggerAckTimeout")) 
try { 
systemDouble = grabber.getFloat<Euresys::DeviceModule>("CxpTriggerAckTimeout"); 
status = setDoubleParam(COAXLINK_Device_CxpTriggerAckTimeout, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpTriggerAckTimeout \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CxpTriggerMaxResendCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpTriggerMaxResendCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpTriggerMaxResendCount"); 
status = setIntegerParam(COAXLINK_Device_CxpTriggerMaxResendCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpTriggerMaxResendCount \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("CxpPacketArbiterReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpPacketArbiterReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("CxpPacketArbiterReset"); 
status = setIntegerParam(COAXLINK_Device_CxpPacketArbiterReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device CxpPacketArbiterReset \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("EventSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventSelector"); 
status = setIntegerParam(COAXLINK_Device_EventSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("EventNotification")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotification")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotification"); 
status = setIntegerParam(COAXLINK_Device_EventNotification, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventNotification \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("EventNotificationContext1")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotificationContext1")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotificationContext1"); 
status = setIntegerParam(COAXLINK_Device_EventNotificationContext1, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventNotificationContext1 \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("EventNotificationContext2")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotificationContext2")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotificationContext2"); 
status = setIntegerParam(COAXLINK_Device_EventNotificationContext2, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventNotificationContext2 \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("EventNotificationContext3")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotificationContext3")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventNotificationContext3"); 
status = setIntegerParam(COAXLINK_Device_EventNotificationContext3, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventNotificationContext3 \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("EventCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventCount"); 
status = setIntegerParam(COAXLINK_Device_EventCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventCount \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("EventCountReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("EventCountReset"); 
status = setIntegerParam(COAXLINK_Device_EventCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device EventCountReset \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("ErrorSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ErrorSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorSelector"); 
status = setIntegerParam(COAXLINK_Device_ErrorSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device ErrorSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("ErrorCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ErrorCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorCount"); 
status = setIntegerParam(COAXLINK_Device_ErrorCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device ErrorCount \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::DeviceModule>(Euresys::RegexFeatures("ErrorCountReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ErrorCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorCountReset"); 
status = setIntegerParam(COAXLINK_Device_ErrorCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Device ErrorCountReset \n "); }  
*/ 

