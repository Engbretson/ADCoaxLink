/* ./Adimec_Q12A180CXP_1_1_3 */ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("Standard")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Standard")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Standard"); 
status = setIntegerParam(COAXLINK_Remote_Standard, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Standard \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("Revision")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Revision")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Revision"); 
status = setIntegerParam(COAXLINK_Remote_Revision, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Revision \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("XmlManifestSize")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("XmlManifestSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("XmlManifestSize"); 
status = setIntegerParam(COAXLINK_Remote_XmlManifestSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote XmlManifestSize \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("XmlManifestSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("XmlManifestSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("XmlManifestSelector"); 
status = setIntegerParam(COAXLINK_Remote_XmlManifestSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote XmlManifestSelector \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("XmlVersion")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("XmlVersion")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("XmlVersion"); 
status = setIntegerParam(COAXLINK_Remote_XmlVersion, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote XmlVersion \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("XmlSchemeVersion")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("XmlSchemeVersion")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("XmlSchemeVersion"); 
status = setIntegerParam(COAXLINK_Remote_XmlSchemeVersion, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote XmlSchemeVersion \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("XmlUrlAddress")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("XmlUrlAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("XmlUrlAddress"); 
status = setIntegerParam(COAXLINK_Remote_XmlUrlAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote XmlUrlAddress \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("Iidc2Address")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Iidc2Address")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Iidc2Address"); 
status = setIntegerParam(COAXLINK_Remote_Iidc2Address, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Iidc2Address \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ConnectionReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ConnectionReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ConnectionReset"); 
status = setIntegerParam(COAXLINK_Remote_ConnectionReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ConnectionReset \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DeviceConnectionID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceConnectionID")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DeviceConnectionID"); 
status = setIntegerParam(COAXLINK_Remote_DeviceConnectionID, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceConnectionID \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("MasterHostConnectionID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MasterHostConnectionID")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("MasterHostConnectionID"); 
status = setIntegerParam(COAXLINK_Remote_MasterHostConnectionID, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote MasterHostConnectionID \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ControlPacketSizeMax")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ControlPacketSizeMax")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ControlPacketSizeMax"); 
status = setIntegerParam(COAXLINK_Remote_ControlPacketSizeMax, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ControlPacketSizeMax \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("StreamPacketSizeMax")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StreamPacketSizeMax")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("StreamPacketSizeMax"); 
status = setIntegerParam(COAXLINK_Remote_StreamPacketSizeMax, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote StreamPacketSizeMax \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ConnectionConfig")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ConnectionConfig")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ConnectionConfig"); 
status = setIntegerParam(COAXLINK_Remote_ConnectionConfig, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ConnectionConfig \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ConnectionConfigDefault")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ConnectionConfigDefault")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ConnectionConfigDefault"); 
status = setIntegerParam(COAXLINK_Remote_ConnectionConfigDefault, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ConnectionConfigDefault \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("TestMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TestMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestMode"); 
status = setIntegerParam(COAXLINK_Remote_TestMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("TestErrorCountSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TestErrorCountSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestErrorCountSelector"); 
status = setIntegerParam(COAXLINK_Remote_TestErrorCountSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestErrorCountSelector \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("TestErrorCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TestErrorCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestErrorCount"); 
status = setIntegerParam(COAXLINK_Remote_TestErrorCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestErrorCount \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("TestPacketCountTx")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TestPacketCountTx")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestPacketCountTx"); 
status = setIntegerParam(COAXLINK_Remote_TestPacketCountTx, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestPacketCountTx \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("TestPacketCountRx")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TestPacketCountRx")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestPacketCountRx"); 
status = setIntegerParam(COAXLINK_Remote_TestPacketCountRx, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestPacketCountRx \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ElectricalCompliancyTest")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ElectricalCompliancyTest")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ElectricalCompliancyTest"); 
status = setIntegerParam(COAXLINK_Remote_ElectricalCompliancyTest, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ElectricalCompliancyTest \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("WidthAddress")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("WidthAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WidthAddress"); 
status = setIntegerParam(COAXLINK_Remote_WidthAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WidthAddress \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("HeightAddress")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("HeightAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("HeightAddress"); 
status = setIntegerParam(COAXLINK_Remote_HeightAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote HeightAddress \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AcquisitionModeAddress")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AcquisitionModeAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionModeAddress"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionModeAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionModeAddress \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AcquisitionStartAddress")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AcquisitionStartAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionStartAddress"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionStartAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionStartAddress \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AcquisitionStopAddress")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AcquisitionStopAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionStopAddress"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionStopAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionStopAddress \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("PixelFormatAddress")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PixelFormatAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("PixelFormatAddress"); 
status = setIntegerParam(COAXLINK_Remote_PixelFormatAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote PixelFormatAddress \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DeviceTapGeometryAddress")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceTapGeometryAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DeviceTapGeometryAddress"); 
status = setIntegerParam(COAXLINK_Remote_DeviceTapGeometryAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceTapGeometryAddress \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("Image1StreamIDAddress")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Image1StreamIDAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Image1StreamIDAddress"); 
status = setIntegerParam(COAXLINK_Remote_Image1StreamIDAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Image1StreamIDAddress \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("HsUpconnection")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("HsUpconnection")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("HsUpconnection"); 
status = setIntegerParam(COAXLINK_Remote_HsUpconnection, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote HsUpconnection \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DeviceVendorName")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceVendorName")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceVendorName"); 
status = setStringParam(COAXLINK_Remote_DeviceVendorName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceVendorName \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DeviceModelName")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceModelName")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceModelName"); 
status = setStringParam(COAXLINK_Remote_DeviceModelName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceModelName \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DeviceManufacturerInfo")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceManufacturerInfo")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceManufacturerInfo"); 
status = setStringParam(COAXLINK_Remote_DeviceManufacturerInfo, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceManufacturerInfo \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DeviceVersion")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceVersion")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceVersion"); 
status = setStringParam(COAXLINK_Remote_DeviceVersion, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceVersion \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DeviceFirmwareVersion")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceFirmwareVersion")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceFirmwareVersion"); 
status = setStringParam(COAXLINK_Remote_DeviceFirmwareVersion, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceFirmwareVersion \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DeviceSerialNumber")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceSerialNumber")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceSerialNumber"); 
status = setStringParam(COAXLINK_Remote_DeviceSerialNumber, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceSerialNumber \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DeviceUserID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceUserID")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("DeviceUserID"); 
status = setStringParam(COAXLINK_Remote_DeviceUserID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceUserID \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DeviceIndicatorMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceIndicatorMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DeviceIndicatorMode"); 
status = setIntegerParam(COAXLINK_Remote_DeviceIndicatorMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceIndicatorMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BuiltInTest")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BuiltInTest")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BuiltInTest"); 
status = setIntegerParam(COAXLINK_Remote_BuiltInTest, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BuiltInTest \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorTemperature")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorTemperature")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorTemperature"); 
status = setIntegerParam(COAXLINK_Remote_SensorTemperature, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorTemperature \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("Width")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Width")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Width"); 
status = setIntegerParam(COAXLINK_Remote_Width, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Width \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("Height")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Height")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Height"); 
status = setIntegerParam(COAXLINK_Remote_Height, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Height \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorWidth")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorWidth")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorWidth"); 
status = setIntegerParam(COAXLINK_Remote_SensorWidth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorWidth \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorHeight")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorHeight")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorHeight"); 
status = setIntegerParam(COAXLINK_Remote_SensorHeight, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorHeight \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("WidthMax")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("WidthMax")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WidthMax"); 
status = setIntegerParam(COAXLINK_Remote_WidthMax, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WidthMax \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("HeightMax")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("HeightMax")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("HeightMax"); 
status = setIntegerParam(COAXLINK_Remote_HeightMax, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote HeightMax \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("OffsetX")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("OffsetX")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("OffsetX"); 
status = setIntegerParam(COAXLINK_Remote_OffsetX, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote OffsetX \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("OffsetY")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("OffsetY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("OffsetY"); 
status = setIntegerParam(COAXLINK_Remote_OffsetY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote OffsetY \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ReverseX")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ReverseX")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ReverseX"); 
status = setIntegerParam(COAXLINK_Remote_ReverseX, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ReverseX \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ReverseY")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ReverseY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ReverseY"); 
status = setIntegerParam(COAXLINK_Remote_ReverseY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ReverseY \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("PixelFormat")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PixelFormat")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("PixelFormat"); 
status = setIntegerParam(COAXLINK_Remote_PixelFormat, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote PixelFormat \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("TestImageSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TestImageSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestImageSelector"); 
status = setIntegerParam(COAXLINK_Remote_TestImageSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestImageSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("TestImageVideoLevel")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TestImageVideoLevel")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TestImageVideoLevel"); 
status = setIntegerParam(COAXLINK_Remote_TestImageVideoLevel, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TestImageVideoLevel \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DeviceTapGeometry")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DeviceTapGeometry")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DeviceTapGeometry"); 
status = setIntegerParam(COAXLINK_Remote_DeviceTapGeometry, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DeviceTapGeometry \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("Image1StreamID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Image1StreamID")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("Image1StreamID"); 
status = setIntegerParam(COAXLINK_Remote_Image1StreamID, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote Image1StreamID \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("CrosshairOverlay")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CrosshairOverlay")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("CrosshairOverlay"); 
status = setIntegerParam(COAXLINK_Remote_CrosshairOverlay, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote CrosshairOverlay \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AcquisitionMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AcquisitionMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionMode"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionMode \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AcquisitionStart")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AcquisitionStart")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionStart"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionStart, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionStart \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AcquisitionStop")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AcquisitionStop")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionStop"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionStop, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionStop \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AcquisitionFrameRate")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AcquisitionFrameRate")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("AcquisitionFrameRate"); 
status = setDoubleParam(COAXLINK_Remote_AcquisitionFrameRate, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionFrameRate \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AcquisitionFramePeriod")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AcquisitionFramePeriod")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("AcquisitionFramePeriod"); 
status = setDoubleParam(COAXLINK_Remote_AcquisitionFramePeriod, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionFramePeriod \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AcquisitionFramePeriodRaw")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AcquisitionFramePeriodRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionFramePeriodRaw"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionFramePeriodRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionFramePeriodRaw \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AcquisitionMaxFrameRate")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AcquisitionMaxFrameRate")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AcquisitionMaxFrameRate"); 
status = setIntegerParam(COAXLINK_Remote_AcquisitionMaxFrameRate, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AcquisitionMaxFrameRate \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("TriggerSource")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TriggerSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TriggerSource"); 
status = setIntegerParam(COAXLINK_Remote_TriggerSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TriggerSource \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("TriggerActivation")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TriggerActivation")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("TriggerActivation"); 
status = setIntegerParam(COAXLINK_Remote_TriggerActivation, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote TriggerActivation \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ExposureMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ExposureMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ExposureMode"); 
status = setIntegerParam(COAXLINK_Remote_ExposureMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ExposureMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ExposureTime")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ExposureTime")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("ExposureTime"); 
status = setDoubleParam(COAXLINK_Remote_ExposureTime, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote ExposureTime \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ExposureTimeRaw")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ExposureTimeRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ExposureTimeRaw"); 
status = setIntegerParam(COAXLINK_Remote_ExposureTimeRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ExposureTimeRaw \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("InterfaceUtilization")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("InterfaceUtilization")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("InterfaceUtilization"); 
status = setIntegerParam(COAXLINK_Remote_InterfaceUtilization, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote InterfaceUtilization \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("FlashStrobeMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FlashStrobeMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FlashStrobeMode"); 
status = setIntegerParam(COAXLINK_Remote_FlashStrobeMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("FlashStrobeDuration")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FlashStrobeDuration")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("FlashStrobeDuration"); 
status = setDoubleParam(COAXLINK_Remote_FlashStrobeDuration, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeDuration \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("FlashStrobeDurationRaw")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FlashStrobeDurationRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FlashStrobeDurationRaw"); 
status = setIntegerParam(COAXLINK_Remote_FlashStrobeDurationRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeDurationRaw \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("FlashStrobeDelay")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FlashStrobeDelay")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("FlashStrobeDelay"); 
status = setDoubleParam(COAXLINK_Remote_FlashStrobeDelay, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeDelay \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("FlashStrobeDelayRaw")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FlashStrobeDelayRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FlashStrobeDelayRaw"); 
status = setIntegerParam(COAXLINK_Remote_FlashStrobeDelayRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeDelayRaw \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("FlashStrobeActiveState")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FlashStrobeActiveState")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FlashStrobeActiveState"); 
status = setIntegerParam(COAXLINK_Remote_FlashStrobeActiveState, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FlashStrobeActiveState \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("HDR_Mode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("HDR_Mode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("HDR_Mode"); 
status = setIntegerParam(COAXLINK_Remote_HDR_Mode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote HDR_Mode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SecondExposureTimeRaw")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SecondExposureTimeRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SecondExposureTimeRaw"); 
status = setIntegerParam(COAXLINK_Remote_SecondExposureTimeRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SecondExposureTimeRaw \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SecondExposureTime")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SecondExposureTime")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("SecondExposureTime"); 
status = setDoubleParam(COAXLINK_Remote_SecondExposureTime, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote SecondExposureTime \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("MultiSlopeNodeSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MultiSlopeNodeSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("MultiSlopeNodeSelector"); 
status = setIntegerParam(COAXLINK_Remote_MultiSlopeNodeSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote MultiSlopeNodeSelector \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("MultiSlopeLevel")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MultiSlopeLevel")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("MultiSlopeLevel"); 
status = setIntegerParam(COAXLINK_Remote_MultiSlopeLevel, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote MultiSlopeLevel \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("MultiSlopeTime")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("MultiSlopeTime")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("MultiSlopeTime"); 
status = setIntegerParam(COAXLINK_Remote_MultiSlopeTime, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote MultiSlopeTime \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("GainSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("GainSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("GainSelector"); 
status = setIntegerParam(COAXLINK_Remote_GainSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote GainSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("Gain")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Gain")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("Gain"); 
status = setDoubleParam(COAXLINK_Remote_Gain, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote Gain \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("GainRaw")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("GainRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("GainRaw"); 
status = setIntegerParam(COAXLINK_Remote_GainRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote GainRaw \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BlackLevel")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BlackLevel")) 
try { 
systemDouble = grabber.getFloat<Euresys::RemoteModule>("BlackLevel"); 
status = setDoubleParam(COAXLINK_Remote_BlackLevel, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Remote BlackLevel \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BlackLevelRaw")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BlackLevelRaw")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BlackLevelRaw"); 
status = setIntegerParam(COAXLINK_Remote_BlackLevelRaw, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BlackLevelRaw \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("WhiteBalanceWidth")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("WhiteBalanceWidth")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceWidth"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceWidth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceWidth \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("WhiteBalanceHeight")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("WhiteBalanceHeight")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceHeight"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceHeight, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceHeight \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("WhiteBalanceOffsetX")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("WhiteBalanceOffsetX")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceOffsetX"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceOffsetX, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceOffsetX \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("WhiteBalanceOffsetY")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("WhiteBalanceOffsetY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceOffsetY"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceOffsetY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceOffsetY \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("WhiteBalanceCalibrate")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("WhiteBalanceCalibrate")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceCalibrate"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceCalibrate, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceCalibrate \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("WhiteBalanceStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("WhiteBalanceStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("WhiteBalanceStatus"); 
status = setIntegerParam(COAXLINK_Remote_WhiteBalanceStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote WhiteBalanceStatus \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorBitDepth")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorBitDepth")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorBitDepth"); 
status = setIntegerParam(COAXLINK_Remote_SensorBitDepth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorBitDepth \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ProgrammableGainAmplifier")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ProgrammableGainAmplifier")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ProgrammableGainAmplifier"); 
status = setIntegerParam(COAXLINK_Remote_ProgrammableGainAmplifier, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ProgrammableGainAmplifier \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("UserMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("UserMode")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("UserMode"); 
status = setStringParam(COAXLINK_Remote_UserMode, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote UserMode \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("UserModeUpdate")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("UserModeUpdate")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("UserModeUpdate"); 
status = setIntegerParam(COAXLINK_Remote_UserModeUpdate, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote UserModeUpdate \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AdvancedParameterSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AdvancedParameterSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AdvancedParameterSelector"); 
status = setIntegerParam(COAXLINK_Remote_AdvancedParameterSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AdvancedParameterSelector \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AdvancedParameter")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AdvancedParameter")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AdvancedParameter"); 
status = setIntegerParam(COAXLINK_Remote_AdvancedParameter, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AdvancedParameter \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("AdvancedParameterSave")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("AdvancedParameterSave")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("AdvancedParameterSave"); 
status = setIntegerParam(COAXLINK_Remote_AdvancedParameterSave, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote AdvancedParameterSave \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ConfigurationInfo")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ConfigurationInfo")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ConfigurationInfo"); 
status = setIntegerParam(COAXLINK_Remote_ConfigurationInfo, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ConfigurationInfo \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("ConfigurationFactoryInfo")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ConfigurationFactoryInfo")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("ConfigurationFactoryInfo"); 
status = setIntegerParam(COAXLINK_Remote_ConfigurationFactoryInfo, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote ConfigurationFactoryInfo \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorRegisterReadWriteMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorRegisterReadWriteMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterReadWriteMode"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterReadWriteMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterReadWriteMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorRegisterNonVolatileReadSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorRegisterNonVolatileReadSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterNonVolatileReadSelector"); 
status = setIntegerParam(COAXLINK_Remote_atileReadSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterNonVolatileReadSelector \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorRegisterNonVolatileListSize")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorRegisterNonVolatileListSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterNonVolatileListSize"); 
status = setIntegerParam(COAXLINK_Remote_atileListSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterNonVolatileListSize \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorRegisterAddress")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorRegisterAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterAddress"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterAddress \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorRegisterSize")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorRegisterSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterSize"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterSize \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorRegisterData")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorRegisterData")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterData"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterData, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterData \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorRegisterRead")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorRegisterRead")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterRead"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterRead, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterRead \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorRegisterWrite")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorRegisterWrite")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterWrite"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterWrite, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterWrite \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("SensorRegisterRemove")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("SensorRegisterRemove")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("SensorRegisterRemove"); 
status = setIntegerParam(COAXLINK_Remote_SensorRegisterRemove, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote SensorRegisterRemove \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("FPGA_RegisterAddress")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FPGA_RegisterAddress")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FPGA_RegisterAddress"); 
status = setIntegerParam(COAXLINK_Remote_FPGA_RegisterAddress, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FPGA_RegisterAddress \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("FPGA_RegisterSize")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FPGA_RegisterSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FPGA_RegisterSize"); 
status = setIntegerParam(COAXLINK_Remote_FPGA_RegisterSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FPGA_RegisterSize \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("FPGA_RegisterData")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FPGA_RegisterData")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FPGA_RegisterData"); 
status = setIntegerParam(COAXLINK_Remote_FPGA_RegisterData, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FPGA_RegisterData \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("FPGA_RegisterRead")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FPGA_RegisterRead")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FPGA_RegisterRead"); 
status = setIntegerParam(COAXLINK_Remote_FPGA_RegisterRead, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FPGA_RegisterRead \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("FPGA_RegisterWrite")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FPGA_RegisterWrite")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("FPGA_RegisterWrite"); 
status = setIntegerParam(COAXLINK_Remote_FPGA_RegisterWrite, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote FPGA_RegisterWrite \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("CustomerSpecialID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CustomerSpecialID")) 
try { 
systemString = grabber.getString<Euresys::RemoteModule>("CustomerSpecialID"); 
status = setStringParam(COAXLINK_Remote_CustomerSpecialID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Remote CustomerSpecialID \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("LUTEnable")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTEnable")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTEnable"); 
status = setIntegerParam(COAXLINK_Remote_LUTEnable, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote LUTEnable \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("LUTIndex")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTIndex")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTIndex"); 
status = setIntegerParam(COAXLINK_Remote_LUTIndex, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote LUTIndex \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("LUTValue")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTValue")) 
try { 
/* 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTValue"); 
status = setIntegerParam(COAXLINK_Remote_LUTValue, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Remote LUTValue \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("LUTStart")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTStart")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTStart"); 
status = setIntegerParam(COAXLINK_Remote_LUTStart, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote LUTStart \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("LUTEnd")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTEnd")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTEnd"); 
status = setIntegerParam(COAXLINK_Remote_LUTEnd, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote LUTEnd \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("LUTStatus")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTStatus")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("LUTStatus"); 
status = setIntegerParam(COAXLINK_Remote_LUTStatus, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote LUTStatus \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("PayloadSize")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PayloadSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("PayloadSize"); 
status = setIntegerParam(COAXLINK_Remote_PayloadSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote PayloadSize \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelCorrectionEnable")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelCorrectionEnable")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelCorrectionEnable"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelCorrectionEnable, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelCorrectionEnable \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelTestMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelTestMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelTestMode"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelTestMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelTestMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelTotal")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelTotal")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelTotal"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelTotal, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelTotal \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelSelect")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelSelect")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelSelect"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelSelect, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelSelect \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelReadX")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelReadX")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelReadX"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelReadX, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelReadX \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelReadY")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelReadY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelReadY"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelReadY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelReadY \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelWriteX")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelWriteX")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelWriteX"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelWriteX, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelWriteX \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelWriteY")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelWriteY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelWriteY"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelWriteY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelWriteY \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelAdd")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelAdd")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelAdd"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelAdd, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelAdd \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelRemove")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelRemove")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelRemove"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelRemove, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelRemove \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelClearAll")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelClearAll")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelClearAll"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelClearAll, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelClearAll \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelSave")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelSave")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelSave"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelSave, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelSave \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelRestore")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelRestore")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelRestore"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelRestore, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelRestore \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelRestoreFactory")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelRestoreFactory")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelRestoreFactory"); 
status = setIntegerParam(COAXLINK_Remote_DefectPixelRestoreFactory, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelRestoreFactory \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DefectPixelSaveAsFactoryDefault")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DefectPixelSaveAsFactoryDefault")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DefectPixelSaveAsFactoryDefault"); 
status = setIntegerParam(COAXLINK_Remote_toryDefault, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DefectPixelSaveAsFactoryDefault \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DF_BlackClamp")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DF_BlackClamp")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_BlackClamp"); 
status = setIntegerParam(COAXLINK_Remote_DF_BlackClamp, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_BlackClamp \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DF_ColumnOffsetCorrection")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DF_ColumnOffsetCorrection")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_ColumnOffsetCorrection"); 
status = setIntegerParam(COAXLINK_Remote_DF_ColumnOffsetCorrection, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_ColumnOffsetCorrection \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DF_Calibrate")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DF_Calibrate")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_Calibrate"); 
status = setIntegerParam(COAXLINK_Remote_DF_Calibrate, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_Calibrate \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DF_Status")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DF_Status")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_Status"); 
status = setIntegerParam(COAXLINK_Remote_DF_Status, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_Status \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DF_RestoreFactory")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DF_RestoreFactory")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_RestoreFactory"); 
status = setIntegerParam(COAXLINK_Remote_DF_RestoreFactory, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_RestoreFactory \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DF_SaveAsFactoryDefault")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DF_SaveAsFactoryDefault")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_SaveAsFactoryDefault"); 
status = setIntegerParam(COAXLINK_Remote_DF_SaveAsFactoryDefault, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_SaveAsFactoryDefault \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("DF_IsUserCalibration")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("DF_IsUserCalibration")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("DF_IsUserCalibration"); 
status = setIntegerParam(COAXLINK_Remote_DF_IsUserCalibration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote DF_IsUserCalibration \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BF_ColumnGainCorrection")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BF_ColumnGainCorrection")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_ColumnGainCorrection"); 
status = setIntegerParam(COAXLINK_Remote_BF_ColumnGainCorrection, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_ColumnGainCorrection \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BF_AutoLevelAdjust")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BF_AutoLevelAdjust")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_AutoLevelAdjust"); 
status = setIntegerParam(COAXLINK_Remote_BF_AutoLevelAdjust, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_AutoLevelAdjust \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BF_CalibrationVideoLevel")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BF_CalibrationVideoLevel")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_CalibrationVideoLevel"); 
status = setIntegerParam(COAXLINK_Remote_BF_CalibrationVideoLevel, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_CalibrationVideoLevel \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BF_OutputImagesDuringCalibration")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BF_OutputImagesDuringCalibration")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_OutputImagesDuringCalibration"); 
status = setIntegerParam(COAXLINK_Remote_gCalibration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_OutputImagesDuringCalibration \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BF_Calibrate")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BF_Calibrate")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_Calibrate"); 
status = setIntegerParam(COAXLINK_Remote_BF_Calibrate, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_Calibrate \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BF_Status")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BF_Status")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_Status"); 
status = setIntegerParam(COAXLINK_Remote_BF_Status, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_Status \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BF_RestoreFactory")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BF_RestoreFactory")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_RestoreFactory"); 
status = setIntegerParam(COAXLINK_Remote_BF_RestoreFactory, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_RestoreFactory \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BF_SaveAsFactoryDefault")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BF_SaveAsFactoryDefault")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_SaveAsFactoryDefault"); 
status = setIntegerParam(COAXLINK_Remote_BF_SaveAsFactoryDefault, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_SaveAsFactoryDefault \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("BF_IsUserCalibration")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BF_IsUserCalibration")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("BF_IsUserCalibration"); 
status = setIntegerParam(COAXLINK_Remote_BF_IsUserCalibration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote BF_IsUserCalibration \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("CFG_FACTORY")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CFG_FACTORY")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("CFG_FACTORY"); 
status = setIntegerParam(COAXLINK_Remote_CFG_FACTORY, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote CFG_FACTORY \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("CFG_COLOR")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CFG_COLOR")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("CFG_COLOR"); 
status = setIntegerParam(COAXLINK_Remote_CFG_COLOR, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote CFG_COLOR \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("CFG_MONO")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("CFG_MONO")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("CFG_MONO"); 
status = setIntegerParam(COAXLINK_Remote_CFG_MONO, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote CFG_MONO \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("UserSetSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("UserSetSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("UserSetSelector"); 
status = setIntegerParam(COAXLINK_Remote_UserSetSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote UserSetSelector \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("UserSetLoad")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("UserSetLoad")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("UserSetLoad"); 
status = setIntegerParam(COAXLINK_Remote_UserSetLoad, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote UserSetLoad \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::RemoteModule>(Euresys::RegexFeatures("UserSetSave")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("UserSetSave")) 
try { 
systemInteger = grabber.getInteger<Euresys::RemoteModule>("UserSetSave"); 
status = setIntegerParam(COAXLINK_Remote_UserSetSave, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Remote UserSetSave \n "); }  
*/ 

