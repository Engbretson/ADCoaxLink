/* ./Euresys_Coaxlink_TLInterface_9_5_1 */ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("InterfaceID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("InterfaceID")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("InterfaceID"); 
status = setStringParam(COAXLINK_Interface_InterfaceID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface InterfaceID \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("InterfaceType")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("InterfaceType")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("InterfaceType"); 
status = setIntegerParam(COAXLINK_Interface_InterfaceType, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface InterfaceType \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("ProductCode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ProductCode")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("ProductCode"); 
status = setStringParam(COAXLINK_Interface_ProductCode, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface ProductCode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("SerialNumber")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SerialNumber")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("SerialNumber"); 
status = setStringParam(COAXLINK_Interface_SerialNumber, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface SerialNumber \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PartNumber")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PartNumber")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("PartNumber"); 
status = setStringParam(COAXLINK_Interface_PartNumber, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface PartNumber \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("FirmwareRevision")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FirmwareRevision")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareRevision"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareRevision, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FirmwareRevision \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("FirmwareVariant")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FirmwareVariant")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareVariant"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareVariant, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FirmwareVariant \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("FirmwareStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FirmwareStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareStatus"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FirmwareStatus \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("FirmwareRecoverySwitch")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FirmwareRecoverySwitch")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareRecoverySwitch"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareRecoverySwitch, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FirmwareRecoverySwitch \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DeviceUpdateList")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceUpdateList")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DeviceUpdateList"); 
status = setIntegerParam(COAXLINK_Interface_DeviceUpdateList, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceUpdateList \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DeviceSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DeviceSelector"); 
status = setIntegerParam(COAXLINK_Interface_DeviceSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceSelector \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DeviceID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceID")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("DeviceID"); 
status = setStringParam(COAXLINK_Interface_DeviceID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceID \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DeviceVendorName")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceVendorName")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("DeviceVendorName"); 
status = setStringParam(COAXLINK_Interface_DeviceVendorName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceVendorName \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DeviceModelName")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceModelName")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("DeviceModelName"); 
status = setStringParam(COAXLINK_Interface_DeviceModelName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceModelName \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DeviceAccessStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceAccessStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DeviceAccessStatus"); 
status = setIntegerParam(COAXLINK_Interface_DeviceAccessStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DeviceAccessStatus \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpPoCxpHostConnectionSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpPoCxpHostConnectionSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpHostConnectionSelector"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpHostConnectionSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpHostConnectionSelector \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpPoCxpAuto")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpPoCxpAuto")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpAuto"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpAuto, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpAuto \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpPoCxpTurnOff")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpPoCxpTurnOff")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpTurnOff"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpTurnOff, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpTurnOff \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpPoCxpTripReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpPoCxpTripReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpTripReset"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpTripReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpTripReset \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpPoCxpConfigurationStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpPoCxpConfigurationStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpConfigurationStatus"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpConfigurationStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpConfigurationStatus \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpPoCxpStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpPoCxpStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpStatus"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpStatus \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpPoCxpCurrent")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpPoCxpCurrent")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("CxpPoCxpCurrent"); 
status = setDoubleParam(COAXLINK_Interface_CxpPoCxpCurrent, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpCurrent \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpPoCxpVoltage")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpPoCxpVoltage")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("CxpPoCxpVoltage"); 
status = setDoubleParam(COAXLINK_Interface_CxpPoCxpVoltage, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpVoltage \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpPoCxpPowerInputStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpPoCxpPowerInputStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpPoCxpPowerInputStatus"); 
status = setIntegerParam(COAXLINK_Interface_CxpPoCxpPowerInputStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpPoCxpPowerInputStatus \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpHostConnectionCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpHostConnectionCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionCount"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionCount \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpHostConnectionSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpHostConnectionSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionSelector"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpConnectionState")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpConnectionState")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpConnectionState"); 
status = setIntegerParam(COAXLINK_Interface_CxpConnectionState, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpConnectionState \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpDownConnectionSpeed")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpDownConnectionSpeed")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpDownConnectionSpeed"); 
status = setIntegerParam(COAXLINK_Interface_CxpDownConnectionSpeed, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpDownConnectionSpeed \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpDeviceConnectionID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpDeviceConnectionID")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpDeviceConnectionID"); 
status = setIntegerParam(COAXLINK_Interface_CxpDeviceConnectionID, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpDeviceConnectionID \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CXP1Supported")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CXP1Supported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP1Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP1Supported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CXP1Supported \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CXP2Supported")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CXP2Supported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP2Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP2Supported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CXP2Supported \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CXP3Supported")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CXP3Supported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP3Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP3Supported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CXP3Supported \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CXP5Supported")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CXP5Supported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP5Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP5Supported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CXP5Supported \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CXP6Supported")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CXP6Supported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP6Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP6Supported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CXP6Supported \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CXP10Supported")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CXP10Supported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP10Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP10Supported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CXP10Supported \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CXP12Supported")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CXP12Supported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CXP12Supported"); 
status = setIntegerParam(COAXLINK_Interface_CXP12Supported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CXP12Supported \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpHostConnectionTestMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpHostConnectionTestMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestMode"); 
status = setIntegerParam(COAXLINK_Interface_CxpHostConnectionTestMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionTestMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpHostConnectionTestErrorCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpHostConnectionTestErrorCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestErrorCount"); 
status = setIntegerParam(COAXLINK_Interface_tErrorCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionTestErrorCount \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpHostConnectionTestPacketCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpHostConnectionTestPacketCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestPacketCount"); 
status = setIntegerParam(COAXLINK_Interface_tPacketCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionTestPacketCount \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpHostConnectionTestInjectError")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpHostConnectionTestInjectError")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpHostConnectionTestInjectError"); 
status = setIntegerParam(COAXLINK_Interface_tInjectError, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpHostConnectionTestInjectError \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpRevisionSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpRevisionSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpRevisionSelector"); 
status = setIntegerParam(COAXLINK_Interface_CxpRevisionSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpRevisionSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CxpRevisionSupport")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CxpRevisionSupport")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CxpRevisionSupport"); 
status = setIntegerParam(COAXLINK_Interface_CxpRevisionSupport, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CxpRevisionSupport \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineSelector"); 
status = setIntegerParam(COAXLINK_Interface_LineSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineFormat")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineFormat")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineFormat"); 
status = setIntegerParam(COAXLINK_Interface_LineFormat, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineFormat \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineMode"); 
status = setIntegerParam(COAXLINK_Interface_LineMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineInverter")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineInverter")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInverter"); 
status = setIntegerParam(COAXLINK_Interface_LineInverter, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineInverter \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineFilterStrength")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineFilterStrength")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineFilterStrength"); 
status = setIntegerParam(COAXLINK_Interface_LineFilterStrength, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineFilterStrength \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineFilterDelay")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineFilterDelay")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("LineFilterDelay"); 
status = setDoubleParam(COAXLINK_Interface_LineFilterDelay, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineFilterDelay \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineStatus"); 
status = setIntegerParam(COAXLINK_Interface_LineStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineStatus \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineStatusAll")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineStatusAll")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineStatusAll"); 
status = setIntegerParam(COAXLINK_Interface_LineStatusAll, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineStatusAll \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineSource")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineSource"); 
status = setIntegerParam(COAXLINK_Interface_LineSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineSource \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("UserOutputValueAll")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("UserOutputValueAll")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("UserOutputValueAll"); 
status = setIntegerParam(COAXLINK_Interface_UserOutputValueAll, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface UserOutputValueAll \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("UserActions")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("UserActions")) 
try { 
/* 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("UserActions"); 
status = setIntegerParam(COAXLINK_Interface_UserActions, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Interface UserActions \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("AddUserAction")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AddUserAction")) 
try { 
/* 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("AddUserAction"); 
status = setIntegerParam(COAXLINK_Interface_AddUserAction, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Interface AddUserAction \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("ClearUserActions")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ClearUserActions")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ClearUserActions"); 
status = setIntegerParam(COAXLINK_Interface_ClearUserActions, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface ClearUserActions \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("ExecuteUserActions")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ExecuteUserActions")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ExecuteUserActions"); 
status = setIntegerParam(COAXLINK_Interface_ExecuteUserActions, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface ExecuteUserActions \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("ScheduleUserActions")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ScheduleUserActions")) 
try { 
/* 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ScheduleUserActions"); 
status = setIntegerParam(COAXLINK_Interface_ScheduleUserActions, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Interface ScheduleUserActions \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("UserActionsSchedulerReference")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("UserActionsSchedulerReference")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("UserActionsSchedulerReference"); 
status = setIntegerParam(COAXLINK_Interface_UserActionsSchedulerReference, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface UserActionsSchedulerReference \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("ScheduledUserActionsPoolStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ScheduledUserActionsPoolStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("ScheduledUserActionsPoolStatus"); 
status = setIntegerParam(COAXLINK_Interface_ScheduledUserActionsPoolStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface ScheduledUserActionsPoolStatus \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DiscardScheduledUserActions")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DiscardScheduledUserActions")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DiscardScheduledUserActions"); 
status = setIntegerParam(COAXLINK_Interface_DiscardScheduledUserActions, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DiscardScheduledUserActions \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineInputToolSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineInputToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInputToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_LineInputToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineInputToolSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineInputToolSource")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineInputToolSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInputToolSource"); 
status = setIntegerParam(COAXLINK_Interface_LineInputToolSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineInputToolSource \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("LineInputToolActivation")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineInputToolActivation")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("LineInputToolActivation"); 
status = setIntegerParam(COAXLINK_Interface_LineInputToolActivation, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface LineInputToolActivation \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("MultiplierDividerToolSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MultiplierDividerToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_MultiplierDividerToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("MultiplierDividerToolSource")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MultiplierDividerToolSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolSource"); 
status = setIntegerParam(COAXLINK_Interface_MultiplierDividerToolSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolSource \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("MultiplierDividerToolOutputControl")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MultiplierDividerToolOutputControl")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolOutputControl"); 
status = setIntegerParam(COAXLINK_Interface_lOutputControl, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolOutputControl \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("MultiplierDividerToolMultiplicationFactor")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MultiplierDividerToolMultiplicationFactor")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("MultiplierDividerToolMultiplicationFactor"); 
status = setDoubleParam(COAXLINK_Interface_lMultiplicationFactor, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolMultiplicationFactor \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("MultiplierDividerToolDivisionFactor")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MultiplierDividerToolDivisionFactor")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("MultiplierDividerToolDivisionFactor"); 
status = setDoubleParam(COAXLINK_Interface_lDivisionFactor, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolDivisionFactor \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("MultiplierDividerToolEffectiveMultiplicationFactor")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MultiplierDividerToolEffectiveMultiplicationFactor")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolEffectiveMultiplicationFactor"); 
status = setIntegerParam(COAXLINK_Interface_lEffectiveMultiplicationFactor, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolEffectiveMultiplicationFactor \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("MultiplierDividerToolEffectiveDivisionFactor")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MultiplierDividerToolEffectiveDivisionFactor")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MultiplierDividerToolEffectiveDivisionFactor"); 
status = setIntegerParam(COAXLINK_Interface_lEffectiveDivisionFactor, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface MultiplierDividerToolEffectiveDivisionFactor \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("QuadratureDecoderToolSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("QuadratureDecoderToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("QuadratureDecoderToolSources")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("QuadratureDecoderToolSources")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolSources"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolSources, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolSources \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("QuadratureDecoderToolActivation")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("QuadratureDecoderToolActivation")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolActivation"); 
status = setIntegerParam(COAXLINK_Interface_lActivation, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolActivation \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("QuadratureDecoderToolForwardDirection")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("QuadratureDecoderToolForwardDirection")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolForwardDirection"); 
status = setIntegerParam(COAXLINK_Interface_lForwardDirection, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolForwardDirection \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("QuadratureDecoderToolOutputMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("QuadratureDecoderToolOutputMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolOutputMode"); 
status = setIntegerParam(COAXLINK_Interface_lOutputMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolOutputMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("QuadratureDecoderToolPosition")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("QuadratureDecoderToolPosition")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolPosition"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolPosition, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolPosition \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("QuadratureDecoderToolDirection")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("QuadratureDecoderToolDirection")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolDirection"); 
status = setIntegerParam(COAXLINK_Interface_QuadratureDecoderToolDirection, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolDirection \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("QuadratureDecoderToolPositionReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("QuadratureDecoderToolPositionReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("QuadratureDecoderToolPositionReset"); 
status = setIntegerParam(COAXLINK_Interface_lPositionReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface QuadratureDecoderToolPositionReset \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DividerToolSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DividerToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DividerToolSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DividerToolSource")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DividerToolSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolSource"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DividerToolSource \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DividerToolEnableControl")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DividerToolEnableControl")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolEnableControl"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolEnableControl, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DividerToolEnableControl \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DividerToolDivisionFactor")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DividerToolDivisionFactor")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolDivisionFactor"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolDivisionFactor, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DividerToolDivisionFactor \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DividerToolInitialOffset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DividerToolInitialOffset")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DividerToolInitialOffset"); 
status = setIntegerParam(COAXLINK_Interface_DividerToolInitialOffset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DividerToolInitialOffset \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DelayToolSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DelayToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DelayToolSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DelayToolSource1")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DelayToolSource1")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolSource1"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolSource1, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DelayToolSource1 \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DelayToolSource2")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DelayToolSource2")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolSource2"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolSource2, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DelayToolSource2 \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DelayToolClockSource")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DelayToolClockSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolClockSource"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolClockSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DelayToolClockSource \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("DelayToolDelayValue")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DelayToolDelayValue")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("DelayToolDelayValue"); 
status = setIntegerParam(COAXLINK_Interface_DelayToolDelayValue, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface DelayToolDelayValue \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventInputToolSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventInputToolSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventInputToolSelector"); 
status = setIntegerParam(COAXLINK_Interface_EventInputToolSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventInputToolSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventInputToolSource")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventInputToolSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventInputToolSource"); 
status = setIntegerParam(COAXLINK_Interface_EventInputToolSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventInputToolSource \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventInputToolActivation")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventInputToolActivation")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventInputToolActivation"); 
status = setIntegerParam(COAXLINK_Interface_EventInputToolActivation, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventInputToolActivation \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("InternalTime")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("InternalTime")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("InternalTime"); 
status = setIntegerParam(COAXLINK_Interface_InternalTime, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface InternalTime \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PCIeMaxPayloadSizeSupported")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PCIeMaxPayloadSizeSupported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxPayloadSizeSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxPayloadSizeSupported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeMaxPayloadSizeSupported \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PCIeMaxPayloadSize")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PCIeMaxPayloadSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxPayloadSize"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxPayloadSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeMaxPayloadSize \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PCIeMaxReadRequestSize")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PCIeMaxReadRequestSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxReadRequestSize"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxReadRequestSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeMaxReadRequestSize \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PCIeMaxLinkSpeed")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PCIeMaxLinkSpeed")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaxLinkSpeed"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaxLinkSpeed, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeMaxLinkSpeed \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PCIeCurrentLinkSpeed")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PCIeCurrentLinkSpeed")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeCurrentLinkSpeed"); 
status = setIntegerParam(COAXLINK_Interface_PCIeCurrentLinkSpeed, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeCurrentLinkSpeed \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PCIeMaximumLinkWidth")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PCIeMaximumLinkWidth")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeMaximumLinkWidth"); 
status = setIntegerParam(COAXLINK_Interface_PCIeMaximumLinkWidth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeMaximumLinkWidth \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PCIeNegotiatedLinkWidth")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PCIeNegotiatedLinkWidth")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeNegotiatedLinkWidth"); 
status = setIntegerParam(COAXLINK_Interface_PCIeNegotiatedLinkWidth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeNegotiatedLinkWidth \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PCIeLinkSpeed2500MTpsSupported")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PCIeLinkSpeed2500MTpsSupported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeLinkSpeed2500MTpsSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeLinkSpeed2500MTpsSupported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeLinkSpeed2500MTpsSupported \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PCIeLinkSpeed5000MTpsSupported")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PCIeLinkSpeed5000MTpsSupported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeLinkSpeed5000MTpsSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeLinkSpeed5000MTpsSupported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeLinkSpeed5000MTpsSupported \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PCIeLinkSpeed8000MTpsSupported")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PCIeLinkSpeed8000MTpsSupported")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PCIeLinkSpeed8000MTpsSupported"); 
status = setIntegerParam(COAXLINK_Interface_PCIeLinkSpeed8000MTpsSupported, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PCIeLinkSpeed8000MTpsSupported \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("FanStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FanStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FanStatus"); 
status = setIntegerParam(COAXLINK_Interface_FanStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FanStatus \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("TemperatureSensorSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TemperatureSensorSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("TemperatureSensorSelector"); 
status = setIntegerParam(COAXLINK_Interface_TemperatureSensorSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface TemperatureSensorSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("Temperature")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Temperature")) 
try { 
systemDouble = grabber.getFloat<Euresys::InterfaceModule>("Temperature"); 
status = setDoubleParam(COAXLINK_Interface_Temperature, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Interface Temperature \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("AuxiliaryPowerInput")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AuxiliaryPowerInput")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("AuxiliaryPowerInput"); 
status = setIntegerParam(COAXLINK_Interface_AuxiliaryPowerInput, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface AuxiliaryPowerInput \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("AuxiliaryPower12VInput")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AuxiliaryPower12VInput")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("AuxiliaryPower12VInput"); 
status = setIntegerParam(COAXLINK_Interface_AuxiliaryPower12VInput, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface AuxiliaryPower12VInput \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("BoardCapabilities")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BoardCapabilities")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("BoardCapabilities"); 
status = setStringParam(COAXLINK_Interface_BoardCapabilities, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface BoardCapabilities \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("FirmwareBoardID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FirmwareBoardID")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("FirmwareBoardID"); 
status = setIntegerParam(COAXLINK_Interface_FirmwareBoardID, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface FirmwareBoardID \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CPLDRevision")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CPLDRevision")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CPLDRevision"); 
status = setIntegerParam(COAXLINK_Interface_CPLDRevision, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CPLDRevision \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PreviousBootBank")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PreviousBootBank")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PreviousBootBank"); 
status = setIntegerParam(COAXLINK_Interface_PreviousBootBank, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PreviousBootBank \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("NextBootBank")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("NextBootBank")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("NextBootBank"); 
status = setIntegerParam(COAXLINK_Interface_NextBootBank, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface NextBootBank \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CurrentBankSelect")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CurrentBankSelect")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CurrentBankSelect"); 
status = setIntegerParam(COAXLINK_Interface_CurrentBankSelect, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CurrentBankSelect \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CurrentBankSelectReadback")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CurrentBankSelectReadback")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CurrentBankSelectReadback"); 
status = setIntegerParam(COAXLINK_Interface_CurrentBankSelectReadback, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CurrentBankSelectReadback \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("NextBankSelect")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("NextBankSelect")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("NextBankSelect"); 
status = setIntegerParam(COAXLINK_Interface_NextBankSelect, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface NextBankSelect \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("SpiBankStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SpiBankStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("SpiBankStatus"); 
status = setIntegerParam(COAXLINK_Interface_SpiBankStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface SpiBankStatus \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("PotBankStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PotBankStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("PotBankStatus"); 
status = setIntegerParam(COAXLINK_Interface_PotBankStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface PotBankStatus \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventSelector"); 
status = setIntegerParam(COAXLINK_Interface_EventSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventNotification")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotification")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotification"); 
status = setIntegerParam(COAXLINK_Interface_EventNotification, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventNotification \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventNotificationContext1")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotificationContext1")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotificationContext1"); 
status = setIntegerParam(COAXLINK_Interface_EventNotificationContext1, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventNotificationContext1 \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventNotificationContext2")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotificationContext2")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotificationContext2"); 
status = setIntegerParam(COAXLINK_Interface_EventNotificationContext2, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventNotificationContext2 \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventNotificationContext3")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotificationContext3")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotificationContext3"); 
status = setIntegerParam(COAXLINK_Interface_EventNotificationContext3, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventNotificationContext3 \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventCount"); 
status = setIntegerParam(COAXLINK_Interface_EventCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventCount \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventCountReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventCountReset"); 
status = setIntegerParam(COAXLINK_Interface_EventCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventCountReset \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventNotificationAll")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotificationAll")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventNotificationAll"); 
status = setIntegerParam(COAXLINK_Interface_EventNotificationAll, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventNotificationAll \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EventCountResetAll")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventCountResetAll")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("EventCountResetAll"); 
status = setIntegerParam(COAXLINK_Interface_EventCountResetAll, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface EventCountResetAll \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("OemSafetyKeyVerification")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("OemSafetyKeyVerification")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("OemSafetyKeyVerification"); 
status = setIntegerParam(COAXLINK_Interface_OemSafetyKeyVerification, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface OemSafetyKeyVerification \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CheckOemSafetyKey")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CheckOemSafetyKey")) 
try { 
/* 
systemString = grabber.getString<Euresys::InterfaceModule>("CheckOemSafetyKey"); 
status = setStringParam(COAXLINK_Interface_CheckOemSafetyKey, systemString.c_str()); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Interface CheckOemSafetyKey \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("ProgramOemSafetyKey")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ProgramOemSafetyKey")) 
try { 
/* 
systemString = grabber.getString<Euresys::InterfaceModule>("ProgramOemSafetyKey"); 
status = setStringParam(COAXLINK_Interface_ProgramOemSafetyKey, systemString.c_str()); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Interface ProgramOemSafetyKey \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("EncryptedOemSafetyKey")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EncryptedOemSafetyKey")) 
try { 
systemString = grabber.getString<Euresys::InterfaceModule>("EncryptedOemSafetyKey"); 
status = setStringParam(COAXLINK_Interface_EncryptedOemSafetyKey, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Interface EncryptedOemSafetyKey \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("MaximumOemKeyLength")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MaximumOemKeyLength")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("MaximumOemKeyLength"); 
status = setIntegerParam(COAXLINK_Interface_MaximumOemKeyLength, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface MaximumOemKeyLength \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CustomLogicReg0")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CustomLogicReg0")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CustomLogicReg0"); 
status = setIntegerParam(COAXLINK_Interface_CustomLogicReg0, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CustomLogicReg0 \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::InterfaceModule>(Euresys::RegexFeatures("CustomLogicReg1")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CustomLogicReg1")) 
try { 
systemInteger = grabber.getInteger<Euresys::InterfaceModule>("CustomLogicReg1"); 
status = setIntegerParam(COAXLINK_Interface_CustomLogicReg1, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Interface CustomLogicReg1 \n "); } 
