/* ./Adimec_Q12A180CXP_1_1_3 */ 

std::vector<std::string> RemoteFeature(grabber.getStringList<Euresys::RemoteModule>(Euresys::Features())); 
std::set<std::string> isaRemoteFeature(RemoteFeature.begin(),RemoteFeature.end() ); 


if (isaRemoteFeature.count("Standard")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Standard"); 
status = setIntegerParam(COAXLINK_Remote_Standard, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Standard \n "); } 

if (isaRemoteFeature.count("Revision")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Revision"); 
status = setIntegerParam(COAXLINK_Remote_Revision, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Revision \n "); } 

if (isaRemoteFeature.count("XmlManifestSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("XmlManifestSize"); 
status = setIntegerParam(COAXLINK_Remote_XmlManifestSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote XmlManifestSize \n "); } 

if (isaRemoteFeature.count("XmlManifestSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("XmlManifestSelector"); 
status = setIntegerParam(COAXLINK_Remote_XmlManifestSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote XmlManifestSelector \n "); } 

if (isaRemoteFeature.count("XmlVersion")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("XmlVersion"); 
status = setIntegerParam(COAXLINK_Remote_XmlVersion, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote XmlVersion \n "); } 

if (isaRemoteFeature.count("XmlSchemeVersion")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("XmlSchemeVersion"); 
status = setIntegerParam(COAXLINK_Remote_XmlSchemeVersion, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote XmlSchemeVersion \n "); } 

if (isaRemoteFeature.count("XmlUrlAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("XmlUrlAddress"); 
status = setIntegerParam(COAXLINK_Remote_XmlUrlAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote XmlUrlAddress \n "); } 

if (isaRemoteFeature.count("Iidc2Address")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Iidc2Address"); 
status = setIntegerParam(COAXLINK_Remote_Iidc2Address, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Iidc2Address \n "); } 

if (isaRemoteFeature.count("ConnectionReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ConnectionReset"); 
status = setIntegerParam(COAXLINK_Remote_ConnectionReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ConnectionReset \n "); } 

if (isaRemoteFeature.count("DeviceConnectionID")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DeviceConnectionID"); 
status = setIntegerParam(COAXLINK_Remote_DeviceConnectionID, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceConnectionID \n "); } 

if (isaRemoteFeature.count("MasterHostConnectionID")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("MasterHostConnectionID"); 
status = setIntegerParam(COAXLINK_Remote_MasterHostConnectionID, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote MasterHostConnectionID \n "); } 

if (isaRemoteFeature.count("ControlPacketSizeMax")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ControlPacketSizeMax"); 
status = setIntegerParam(COAXLINK_Remote_ControlPacketSizeMax, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ControlPacketSizeMax \n "); } 

if (isaRemoteFeature.count("StreamPacketSizeMax")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("StreamPacketSizeMax"); 
status = setIntegerParam(COAXLINK_Remote_StreamPacketSizeMax, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote StreamPacketSizeMax \n "); } 

if (isaRemoteFeature.count("ConnectionConfig")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ConnectionConfig"); 
status = setIntegerParam(COAXLINK_Remote_ConnectionConfig, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ConnectionConfig \n "); }  

if (isaRemoteFeature.count("ConnectionConfigDefault")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ConnectionConfigDefault"); 
status = setIntegerParam(COAXLINK_Remote_ConnectionConfigDefault, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ConnectionConfigDefault \n "); }  

if (isaRemoteFeature.count("TestMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestMode"); 
status = setIntegerParam(COAXLINK_Remote_TestMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestMode \n "); }  

if (isaRemoteFeature.count("TestErrorCountSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestErrorCountSelector"); 
status = setIntegerParam(COAXLINK_Remote_TestErrorCountSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestErrorCountSelector \n "); } 

if (isaRemoteFeature.count("TestErrorCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestErrorCount"); 
status = setIntegerParam(COAXLINK_Remote_TestErrorCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestErrorCount \n "); } 

if (isaRemoteFeature.count("TestPacketCountTx")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestPacketCountTx"); 
status = setIntegerParam(COAXLINK_Remote_TestPacketCountTx, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestPacketCountTx \n "); } 

if (isaRemoteFeature.count("TestPacketCountRx")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestPacketCountRx"); 
status = setIntegerParam(COAXLINK_Remote_TestPacketCountRx, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestPacketCountRx \n "); } 

if (isaRemoteFeature.count("ElectricalCompliancyTest")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ElectricalCompliancyTest"); 
status = setIntegerParam(COAXLINK_Remote_ElectricalCompliancyTest, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ElectricalCompliancyTest \n "); }  

if (isaRemoteFeature.count("WidthAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WidthAddress"); 
status = setIntegerParam(COAXLINK_Remote_WidthAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WidthAddress \n "); } 

if (isaRemoteFeature.count("HeightAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("HeightAddress"); 
status = setIntegerParam(COAXLINK_Remote_HeightAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote HeightAddress \n "); } 

if (isaRemoteFeature.count("AcquisitionModeAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionModeAddress"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionModeAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionModeAddress \n "); } 

if (isaRemoteFeature.count("AcquisitionStartAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionStartAddress"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionStartAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionStartAddress \n "); } 

if (isaRemoteFeature.count("AcquisitionStopAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionStopAddress"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionStopAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionStopAddress \n "); } 

if (isaRemoteFeature.count("PixelFormatAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("PixelFormatAddress"); 
status = setIntegerParam(COAXLINK_Remote_PixelFormatAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote PixelFormatAddress \n "); } 

if (isaRemoteFeature.count("DeviceTapGeometryAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DeviceTapGeometryAddress"); 
status = setIntegerParam(COAXLINK_Remote_DeviceTapGeometryAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceTapGeometryAddress \n "); } 

if (isaRemoteFeature.count("Image1StreamIDAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Image1StreamIDAddress"); 
status = setIntegerParam(COAXLINK_Remote_Image1StreamIDAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Image1StreamIDAddress \n "); } 

if (isaRemoteFeature.count("HsUpconnection")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("HsUpconnection"); 
status = setIntegerParam(COAXLINK_Remote_HsUpconnection, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote HsUpconnection \n "); } 

if (isaRemoteFeature.count("DeviceVendorName")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceVendorName"); 
status = setStringParam(COAXLINK_Remote_DeviceVendorName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceVendorName \n "); }  

if (isaRemoteFeature.count("DeviceModelName")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceModelName"); 
status = setStringParam(COAXLINK_Remote_DeviceModelName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceModelName \n "); }  

if (isaRemoteFeature.count("DeviceManufacturerInfo")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceManufacturerInfo"); 
status = setStringParam(COAXLINK_Remote_DeviceManufacturerInfo, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceManufacturerInfo \n "); }  

if (isaRemoteFeature.count("DeviceVersion")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceVersion"); 
status = setStringParam(COAXLINK_Remote_DeviceVersion, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceVersion \n "); }  

if (isaRemoteFeature.count("DeviceFirmwareVersion")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceFirmwareVersion"); 
status = setStringParam(COAXLINK_Remote_DeviceFirmwareVersion, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceFirmwareVersion \n "); }  

if (isaRemoteFeature.count("DeviceSerialNumber")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceSerialNumber"); 
status = setStringParam(COAXLINK_Remote_DeviceSerialNumber, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceSerialNumber \n "); }  

if (isaRemoteFeature.count("DeviceUserID")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceUserID"); 
status = setStringParam(COAXLINK_Remote_DeviceUserID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceUserID \n "); }  

if (isaRemoteFeature.count("DeviceIndicatorMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DeviceIndicatorMode"); 
status = setIntegerParam(COAXLINK_Remote_DeviceIndicatorMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceIndicatorMode \n "); }  

if (isaRemoteFeature.count("BuiltInTest")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BuiltInTest"); 
status = setIntegerParam(COAXLINK_Remote_BuiltInTest, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BuiltInTest \n "); } 

if (isaRemoteFeature.count("SensorTemperature")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorTemperature"); 
status = setIntegerParam(COAXLINK_Remote_SensorTemperature, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorTemperature \n "); } 

if (isaRemoteFeature.count("Width")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Width"); 
status = setIntegerParam(COAXLINK_Remote_Width, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Width \n "); } 

if (isaRemoteFeature.count("Height")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Height"); 
status = setIntegerParam(COAXLINK_Remote_Height, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Height \n "); } 

if (isaRemoteFeature.count("SensorWidth")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorWidth"); 
status = setIntegerParam(COAXLINK_Remote_SensorWidth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorWidth \n "); } 

if (isaRemoteFeature.count("SensorHeight")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorHeight"); 
status = setIntegerParam(COAXLINK_Remote_SensorHeight, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorHeight \n "); } 

if (isaRemoteFeature.count("WidthMax")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WidthMax"); 
status = setIntegerParam(COAXLINK_Remote_WidthMax, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WidthMax \n "); } 

if (isaRemoteFeature.count("HeightMax")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("HeightMax"); 
status = setIntegerParam(COAXLINK_Remote_HeightMax, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote HeightMax \n "); } 

if (isaRemoteFeature.count("OffsetX")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("OffsetX"); 
status = setIntegerParam(COAXLINK_Remote_OffsetX, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote OffsetX \n "); } 

if (isaRemoteFeature.count("OffsetY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("OffsetY"); 
status = setIntegerParam(COAXLINK_Remote_OffsetY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote OffsetY \n "); } 

if (isaRemoteFeature.count("ReverseX")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ReverseX"); 
status = setIntegerParam(COAXLINK_Remote_ReverseX, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ReverseX \n "); }  

if (isaRemoteFeature.count("ReverseY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ReverseY"); 
status = setIntegerParam(COAXLINK_Remote_ReverseY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ReverseY \n "); }  

if (isaRemoteFeature.count("PixelFormat")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("PixelFormat"); 
status = setIntegerParam(COAXLINK_Remote_PixelFormat, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote PixelFormat \n "); }  

if (isaRemoteFeature.count("TestImageSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestImageSelector"); 
status = setIntegerParam(COAXLINK_Remote_TestImageSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestImageSelector \n "); }  

if (isaRemoteFeature.count("TestImageVideoLevel")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestImageVideoLevel"); 
status = setIntegerParam(COAXLINK_Remote_TestImageVideoLevel, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestImageVideoLevel \n "); } 

if (isaRemoteFeature.count("DeviceTapGeometry")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DeviceTapGeometry"); 
status = setIntegerParam(COAXLINK_Remote_DeviceTapGeometry, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceTapGeometry \n "); }  

if (isaRemoteFeature.count("Image1StreamID")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Image1StreamID"); 
status = setIntegerParam(COAXLINK_Remote_Image1StreamID, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Image1StreamID \n "); } 

if (isaRemoteFeature.count("CrosshairOverlay")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("CrosshairOverlay"); 
status = setIntegerParam(COAXLINK_Remote_CrosshairOverlay, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote CrosshairOverlay \n "); }  

if (isaRemoteFeature.count("AcquisitionMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionMode"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionMode \n "); }  

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("AcquisitionStart")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionStart"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionStart, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionStart \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("AcquisitionStop")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionStop"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionStop, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionStop \n "); }  
*/ 


if (isaRemoteFeature.count("AcquisitionFrameRate")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("AcquisitionFrameRate"); 
status = setDoubleParam(COAXLINK_Remote_AcquisitionFrameRate, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionFrameRate \n "); }  

if (isaRemoteFeature.count("AcquisitionFramePeriod")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("AcquisitionFramePeriod"); 
status = setDoubleParam(COAXLINK_Remote_AcquisitionFramePeriod, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionFramePeriod \n "); }  

if (isaRemoteFeature.count("AcquisitionFramePeriodRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionFramePeriodRaw"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionFramePeriodRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionFramePeriodRaw \n "); } 

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("AcquisitionMaxFrameRate")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionMaxFrameRate"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionMaxFrameRate, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionMaxFrameRate \n "); }  
*/ 


if (isaRemoteFeature.count("TriggerSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TriggerSource"); 
status = setIntegerParam(COAXLINK_Remote_TriggerSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TriggerSource \n "); }  

if (isaRemoteFeature.count("TriggerActivation")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TriggerActivation"); 
status = setIntegerParam(COAXLINK_Remote_TriggerActivation, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TriggerActivation \n "); }  

if (isaRemoteFeature.count("ExposureMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ExposureMode"); 
status = setIntegerParam(COAXLINK_Remote_ExposureMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ExposureMode \n "); }  

if (isaRemoteFeature.count("ExposureTime")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("ExposureTime"); 
status = setDoubleParam(COAXLINK_Remote_ExposureTime, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote ExposureTime \n "); }  

if (isaRemoteFeature.count("ExposureTimeRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ExposureTimeRaw"); 
status = setIntegerParam(COAXLINK_Remote_ExposureTimeRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ExposureTimeRaw \n "); } 

if (isaRemoteFeature.count("InterfaceUtilization")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("InterfaceUtilization"); 
status = setIntegerParam(COAXLINK_Remote_InterfaceUtilization, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote InterfaceUtilization \n "); } 

if (isaRemoteFeature.count("FlashStrobeMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FlashStrobeMode"); 
status = setIntegerParam(COAXLINK_Remote_FlashStrobeMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeMode \n "); }  

if (isaRemoteFeature.count("FlashStrobeDuration")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("FlashStrobeDuration"); 
status = setDoubleParam(COAXLINK_Remote_FlashStrobeDuration, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeDuration \n "); }  

if (isaRemoteFeature.count("FlashStrobeDurationRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FlashStrobeDurationRaw"); 
status = setIntegerParam(COAXLINK_Remote_FlashStrobeDurationRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeDurationRaw \n "); } 

if (isaRemoteFeature.count("FlashStrobeDelay")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("FlashStrobeDelay"); 
status = setDoubleParam(COAXLINK_Remote_FlashStrobeDelay, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeDelay \n "); }  

if (isaRemoteFeature.count("FlashStrobeDelayRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FlashStrobeDelayRaw"); 
status = setIntegerParam(COAXLINK_Remote_FlashStrobeDelayRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeDelayRaw \n "); } 

if (isaRemoteFeature.count("FlashStrobeActiveState")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FlashStrobeActiveState"); 
status = setIntegerParam(COAXLINK_Remote_FlashStrobeActiveState, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeActiveState \n "); }  

if (isaRemoteFeature.count("HDR_Mode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("HDR_Mode"); 
status = setIntegerParam(COAXLINK_Remote_HDR_Mode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote HDR_Mode \n "); }  

if (isaRemoteFeature.count("SecondExposureTimeRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SecondExposureTimeRaw"); 
status = setIntegerParam(COAXLINK_Remote_SecondExposureTimeRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SecondExposureTimeRaw \n "); } 

if (isaRemoteFeature.count("SecondExposureTime")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("SecondExposureTime"); 
status = setDoubleParam(COAXLINK_Remote_SecondExposureTime, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote SecondExposureTime \n "); }  

if (isaRemoteFeature.count("MultiSlopeNodeSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("MultiSlopeNodeSelector"); 
status = setIntegerParam(COAXLINK_Remote_MultiSlopeNodeSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote MultiSlopeNodeSelector \n "); } 

if (isaRemoteFeature.count("MultiSlopeLevel")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("MultiSlopeLevel"); 
status = setIntegerParam(COAXLINK_Remote_MultiSlopeLevel, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote MultiSlopeLevel \n "); } 

if (isaRemoteFeature.count("MultiSlopeTime")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("MultiSlopeTime"); 
status = setIntegerParam(COAXLINK_Remote_MultiSlopeTime, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote MultiSlopeTime \n "); } 

if (isaRemoteFeature.count("GainSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("GainSelector"); 
status = setIntegerParam(COAXLINK_Remote_GainSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote GainSelector \n "); }  

if (isaRemoteFeature.count("Gain")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("Gain"); 
status = setDoubleParam(COAXLINK_Remote_Gain, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote Gain \n "); }  

if (isaRemoteFeature.count("GainRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("GainRaw"); 
status = setIntegerParam(COAXLINK_Remote_GainRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote GainRaw \n "); } 

if (isaRemoteFeature.count("BlackLevel")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("BlackLevel"); 
status = setDoubleParam(COAXLINK_Remote_BlackLevel, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote BlackLevel \n "); }  

if (isaRemoteFeature.count("BlackLevelRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BlackLevelRaw"); 
status = setIntegerParam(COAXLINK_Remote_BlackLevelRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BlackLevelRaw \n "); } 

if (isaRemoteFeature.count("WhiteBalanceWidth")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceWidth"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceWidth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceWidth \n "); } 

if (isaRemoteFeature.count("WhiteBalanceHeight")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceHeight"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceHeight, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceHeight \n "); } 

if (isaRemoteFeature.count("WhiteBalanceOffsetX")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceOffsetX"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceOffsetX, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceOffsetX \n "); } 

if (isaRemoteFeature.count("WhiteBalanceOffsetY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceOffsetY"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceOffsetY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceOffsetY \n "); } 

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("WhiteBalanceCalibrate")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceCalibrate"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceCalibrate, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceCalibrate \n "); }  
*/ 


if (isaRemoteFeature.count("WhiteBalanceStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceStatus"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceStatus \n "); }  

if (isaRemoteFeature.count("SensorBitDepth")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorBitDepth"); 
status = setIntegerParam(COAXLINK_Remote_SensorBitDepth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorBitDepth \n "); }  

if (isaRemoteFeature.count("ProgrammableGainAmplifier")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ProgrammableGainAmplifier"); 
status = setIntegerParam(COAXLINK_Remote_ProgrammableGainAmplifier, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ProgrammableGainAmplifier \n "); } 

if (isaRemoteFeature.count("UserMode")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("UserMode"); 
status = setStringParam(COAXLINK_Remote_UserMode, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote UserMode \n "); }  

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("UserModeUpdate")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("UserModeUpdate"); 
status = setIntegerParam(COAXLINK_Remote_UserModeUpdate, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote UserModeUpdate \n "); }  
*/ 


if (isaRemoteFeature.count("AdvancedParameterSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AdvancedParameterSelector"); 
status = setIntegerParam(COAXLINK_Remote_AdvancedParameterSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AdvancedParameterSelector \n "); } 

if (isaRemoteFeature.count("AdvancedParameter")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AdvancedParameter"); 
status = setIntegerParam(COAXLINK_Remote_AdvancedParameter, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AdvancedParameter \n "); } 

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("AdvancedParameterSave")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AdvancedParameterSave"); 
status = setIntegerParam(COAXLINK_Remote_AdvancedParameterSave, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AdvancedParameterSave \n "); }  
*/ 


if (isaRemoteFeature.count("ConfigurationInfo")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ConfigurationInfo"); 
status = setIntegerParam(COAXLINK_Remote_ConfigurationInfo, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ConfigurationInfo \n "); } 

if (isaRemoteFeature.count("ConfigurationFactoryInfo")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ConfigurationFactoryInfo"); 
status = setIntegerParam(COAXLINK_Remote_ConfigurationFactoryInfo, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ConfigurationFactoryInfo \n "); } 

if (isaRemoteFeature.count("SensorRegisterReadWriteMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterReadWriteMode"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterReadWriteMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterReadWriteMode \n "); }  

if (isaRemoteFeature.count("SensorRegisterNonVolatileReadSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterNonVolatileReadSelector"); 
status = setIntegerParam(COAXLINK_Remote_atileReadSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterNonVolatileReadSelector \n "); } 

if (isaRemoteFeature.count("SensorRegisterNonVolatileListSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterNonVolatileListSize"); 
status = setIntegerParam(COAXLINK_Remote_atileListSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterNonVolatileListSize \n "); } 

if (isaRemoteFeature.count("SensorRegisterAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterAddress"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterAddress \n "); } 

if (isaRemoteFeature.count("SensorRegisterSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterSize"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterSize \n "); } 

if (isaRemoteFeature.count("SensorRegisterData")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterData"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterData, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterData \n "); } 

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("SensorRegisterRead")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterRead"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterRead, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterRead \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("SensorRegisterWrite")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterWrite"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterWrite, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterWrite \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("SensorRegisterRemove")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterRemove"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterRemove, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterRemove \n "); }  
*/ 


if (isaRemoteFeature.count("FPGA_RegisterAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FPGA_RegisterAddress"); 
status = setIntegerParam(COAXLINK_Remote_FPGA_RegisterAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FPGA_RegisterAddress \n "); } 

if (isaRemoteFeature.count("FPGA_RegisterSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FPGA_RegisterSize"); 
status = setIntegerParam(COAXLINK_Remote_FPGA_RegisterSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FPGA_RegisterSize \n "); } 

if (isaRemoteFeature.count("FPGA_RegisterData")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FPGA_RegisterData"); 
status = setIntegerParam(COAXLINK_Remote_FPGA_RegisterData, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FPGA_RegisterData \n "); } 

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("FPGA_RegisterRead")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FPGA_RegisterRead"); 
status = setIntegerParam(COAXLINK_Remote_FPGA_RegisterRead, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FPGA_RegisterRead \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("FPGA_RegisterWrite")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FPGA_RegisterWrite"); 
status = setIntegerParam(COAXLINK_Remote_FPGA_RegisterWrite, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FPGA_RegisterWrite \n "); }  
*/ 


if (isaRemoteFeature.count("CustomerSpecialID")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("CustomerSpecialID"); 
status = setStringParam(COAXLINK_Remote_CustomerSpecialID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote CustomerSpecialID \n "); }  

if (isaRemoteFeature.count("LUTEnable")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTEnable"); 
status = setIntegerParam(COAXLINK_Remote_LUTEnable, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote LUTEnable \n "); }  

if (isaRemoteFeature.count("LUTIndex")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTIndex"); 
status = setIntegerParam(COAXLINK_Remote_LUTIndex, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote LUTIndex \n "); } 

if (isaRemoteFeature.count("LUTValue")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTValue"); 
status = setIntegerParam(COAXLINK_Remote_LUTValue, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote LUTValue \n "); } 

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("LUTStart")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTStart"); 
status = setIntegerParam(COAXLINK_Remote_LUTStart, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote LUTStart \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("LUTEnd")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTEnd"); 
status = setIntegerParam(COAXLINK_Remote_LUTEnd, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote LUTEnd \n "); }  
*/ 


if (isaRemoteFeature.count("LUTStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTStatus"); 
status = setIntegerParam(COAXLINK_Remote_LUTStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote LUTStatus \n "); }  

if (isaRemoteFeature.count("PayloadSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("PayloadSize"); 
status = setIntegerParam(COAXLINK_Remote_PayloadSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote PayloadSize \n "); } 

if (isaRemoteFeature.count("DefectPixelCorrectionEnable")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelCorrectionEnable"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelCorrectionEnable, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelCorrectionEnable \n "); }  

if (isaRemoteFeature.count("DefectPixelTestMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelTestMode"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelTestMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelTestMode \n "); }  

if (isaRemoteFeature.count("DefectPixelTotal")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelTotal"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelTotal, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelTotal \n "); } 

if (isaRemoteFeature.count("DefectPixelSelect")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelSelect"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelSelect, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelSelect \n "); } 

if (isaRemoteFeature.count("DefectPixelReadX")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelReadX"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelReadX, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelReadX \n "); } 

if (isaRemoteFeature.count("DefectPixelReadY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelReadY"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelReadY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelReadY \n "); } 

if (isaRemoteFeature.count("DefectPixelWriteX")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelWriteX"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelWriteX, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelWriteX \n "); } 

if (isaRemoteFeature.count("DefectPixelWriteY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelWriteY"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelWriteY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelWriteY \n "); } 

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("DefectPixelAdd")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelAdd"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelAdd, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelAdd \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("DefectPixelRemove")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelRemove"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelRemove, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelRemove \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("DefectPixelClearAll")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelClearAll"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelClearAll, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelClearAll \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("DefectPixelSave")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelSave"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelSave, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelSave \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("DefectPixelRestore")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelRestore"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelRestore, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelRestore \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("DefectPixelRestoreFactory")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelRestoreFactory"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelRestoreFactory, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelRestoreFactory \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("DefectPixelSaveAsFactoryDefault")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelSaveAsFactoryDefault"); 
status = setIntegerParam(COAXLINK_Remote_toryDefault, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelSaveAsFactoryDefault \n "); }  
*/ 


if (isaRemoteFeature.count("DF_BlackClamp")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_BlackClamp"); 
status = setIntegerParam(COAXLINK_Remote_DF_BlackClamp, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_BlackClamp \n "); }  

if (isaRemoteFeature.count("DF_ColumnOffsetCorrection")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_ColumnOffsetCorrection"); 
status = setIntegerParam(COAXLINK_Remote_DF_ColumnOffsetCorrection, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_ColumnOffsetCorrection \n "); }  

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("DF_Calibrate")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_Calibrate"); 
status = setIntegerParam(COAXLINK_Remote_DF_Calibrate, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_Calibrate \n "); }  
*/ 


if (isaRemoteFeature.count("DF_Status")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_Status"); 
status = setIntegerParam(COAXLINK_Remote_DF_Status, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_Status \n "); }  

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("DF_RestoreFactory")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_RestoreFactory"); 
status = setIntegerParam(COAXLINK_Remote_DF_RestoreFactory, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_RestoreFactory \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("DF_SaveAsFactoryDefault")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_SaveAsFactoryDefault"); 
status = setIntegerParam(COAXLINK_Remote_DF_SaveAsFactoryDefault, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_SaveAsFactoryDefault \n "); }  
*/ 


if (isaRemoteFeature.count("DF_IsUserCalibration")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_IsUserCalibration"); 
status = setIntegerParam(COAXLINK_Remote_DF_IsUserCalibration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_IsUserCalibration \n "); }  

if (isaRemoteFeature.count("BF_ColumnGainCorrection")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_ColumnGainCorrection"); 
status = setIntegerParam(COAXLINK_Remote_BF_ColumnGainCorrection, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_ColumnGainCorrection \n "); }  

if (isaRemoteFeature.count("BF_AutoLevelAdjust")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_AutoLevelAdjust"); 
status = setIntegerParam(COAXLINK_Remote_BF_AutoLevelAdjust, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_AutoLevelAdjust \n "); }  

if (isaRemoteFeature.count("BF_CalibrationVideoLevel")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_CalibrationVideoLevel"); 
status = setIntegerParam(COAXLINK_Remote_BF_CalibrationVideoLevel, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_CalibrationVideoLevel \n "); } 

if (isaRemoteFeature.count("BF_OutputImagesDuringCalibration")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_OutputImagesDuringCalibration"); 
status = setIntegerParam(COAXLINK_Remote_gCalibration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_OutputImagesDuringCalibration \n "); }  

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("BF_Calibrate")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_Calibrate"); 
status = setIntegerParam(COAXLINK_Remote_BF_Calibrate, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_Calibrate \n "); }  
*/ 


if (isaRemoteFeature.count("BF_Status")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_Status"); 
status = setIntegerParam(COAXLINK_Remote_BF_Status, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_Status \n "); }  

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("BF_RestoreFactory")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_RestoreFactory"); 
status = setIntegerParam(COAXLINK_Remote_BF_RestoreFactory, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_RestoreFactory \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("BF_SaveAsFactoryDefault")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_SaveAsFactoryDefault"); 
status = setIntegerParam(COAXLINK_Remote_BF_SaveAsFactoryDefault, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_SaveAsFactoryDefault \n "); }  
*/ 


if (isaRemoteFeature.count("BF_IsUserCalibration")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_IsUserCalibration"); 
status = setIntegerParam(COAXLINK_Remote_BF_IsUserCalibration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_IsUserCalibration \n "); }  

if (isaRemoteFeature.count("CFG_FACTORY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("CFG_FACTORY"); 
status = setIntegerParam(COAXLINK_Remote_CFG_FACTORY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote CFG_FACTORY \n "); }  

if (isaRemoteFeature.count("CFG_COLOR")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("CFG_COLOR"); 
status = setIntegerParam(COAXLINK_Remote_CFG_COLOR, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote CFG_COLOR \n "); }  

if (isaRemoteFeature.count("CFG_MONO")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("CFG_MONO"); 
status = setIntegerParam(COAXLINK_Remote_CFG_MONO, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote CFG_MONO \n "); }  

if (isaRemoteFeature.count("UserSetSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("UserSetSelector"); 
status = setIntegerParam(COAXLINK_Remote_UserSetSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote UserSetSelector \n "); }  

// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("UserSetLoad")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("UserSetLoad"); 
status = setIntegerParam(COAXLINK_Remote_UserSetLoad, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote UserSetLoad \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaRemoteFeature.count("UserSetSave")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("UserSetSave"); 
status = setIntegerParam(COAXLINK_Remote_UserSetSave, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote UserSetSave \n "); }  
*/ 

