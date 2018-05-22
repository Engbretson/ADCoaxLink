/* ./Euresys_Coaxlink_TLDataStream_9_5_2 */ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StreamID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StreamID")) 
try { 
systemString = grabber.getString<Euresys::StreamModule>("StreamID"); 
status = setStringParam(COAXLINK_Stream_StreamID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamID \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StreamType")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StreamType")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamType"); 
status = setIntegerParam(COAXLINK_Stream_StreamType, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamType \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("PixelFormat")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PixelFormat")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PixelFormat"); 
status = setIntegerParam(COAXLINK_Stream_PixelFormat, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream PixelFormat \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("PixelFormatNamespace")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PixelFormatNamespace")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PixelFormatNamespace"); 
status = setIntegerParam(COAXLINK_Stream_PixelFormatNamespace, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream PixelFormatNamespace \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("PixelSize")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PixelSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PixelSize"); 
status = setIntegerParam(COAXLINK_Stream_PixelSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream PixelSize \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("Width")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Width")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("Width"); 
status = setIntegerParam(COAXLINK_Stream_Width, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream Width \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("Height")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Height")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("Height"); 
status = setIntegerParam(COAXLINK_Stream_Height, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream Height \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("UnpackingMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("UnpackingMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("UnpackingMode"); 
status = setIntegerParam(COAXLINK_Stream_UnpackingMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream UnpackingMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("RedBlueSwap")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("RedBlueSwap")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("RedBlueSwap"); 
status = setIntegerParam(COAXLINK_Stream_RedBlueSwap, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream RedBlueSwap \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LUTConfiguration")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTConfiguration")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTConfiguration"); 
status = setIntegerParam(COAXLINK_Stream_LUTConfiguration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTConfiguration \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LUTLength")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTLength")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTLength"); 
status = setIntegerParam(COAXLINK_Stream_LUTLength, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTLength \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LUTMaxValue")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTMaxValue")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTMaxValue"); 
status = setIntegerParam(COAXLINK_Stream_LUTMaxValue, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTMaxValue \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LUTSet")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTSet")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTSet"); 
status = setIntegerParam(COAXLINK_Stream_LUTSet, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTSet \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LUTIndex")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTIndex")) 
try { 
/* unimplemented int type
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTIndex"); 
status = setIntegerParam(COAXLINK_Stream_LUTIndex, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Stream LUTIndex \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LUTValue")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTValue")) 
try { 
/* unimplemented String type
systemString = grabber.getString<Euresys::StreamModule>("LUTValue"); 
status = setStringParam(COAXLINK_Stream_LUTValue, systemString.c_str()); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Stream LUTValue \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LUTReadBlockLength")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTReadBlockLength")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTReadBlockLength"); 
status = setIntegerParam(COAXLINK_Stream_LUTReadBlockLength, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTReadBlockLength \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LUTEnable")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LUTEnable")) 
try { 
/* unimplemented enum type 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTEnable"); 
status = setIntegerParam(COAXLINK_Stream_LUTEnable, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Stream LUTEnable \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("PayloadSize")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("PayloadSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PayloadSize"); 
status = setIntegerParam(COAXLINK_Stream_PayloadSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream PayloadSize \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StreamAnnouncedBufferCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StreamAnnouncedBufferCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamAnnouncedBufferCount"); 
status = setIntegerParam(COAXLINK_Stream_StreamAnnouncedBufferCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamAnnouncedBufferCount \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StreamBufferHandlingMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StreamBufferHandlingMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamBufferHandlingMode"); 
status = setIntegerParam(COAXLINK_Stream_StreamBufferHandlingMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamBufferHandlingMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StreamAnnounceBufferMinimum")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StreamAnnounceBufferMinimum")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamAnnounceBufferMinimum"); 
status = setIntegerParam(COAXLINK_Stream_StreamAnnounceBufferMinimum, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamAnnounceBufferMinimum \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StreamAcquisitionModeSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StreamAcquisitionModeSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamAcquisitionModeSelector"); 
status = setIntegerParam(COAXLINK_Stream_StreamAcquisitionModeSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamAcquisitionModeSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StartOfScanTriggerSource")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StartOfScanTriggerSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StartOfScanTriggerSource"); 
status = setIntegerParam(COAXLINK_Stream_StartOfScanTriggerSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StartOfScanTriggerSource \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("EndOfScanTriggerSource")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EndOfScanTriggerSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EndOfScanTriggerSource"); 
status = setIntegerParam(COAXLINK_Stream_EndOfScanTriggerSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EndOfScanTriggerSource \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("ScanLength")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ScanLength")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ScanLength"); 
status = setIntegerParam(COAXLINK_Stream_ScanLength, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream ScanLength \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("BufferHeight")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BufferHeight")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("BufferHeight"); 
status = setIntegerParam(COAXLINK_Stream_BufferHeight, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream BufferHeight \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StartScan")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StartScan")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StartScan"); 
status = setIntegerParam(COAXLINK_Stream_StartScan, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StartScan \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StopScan")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StopScan")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StopScan"); 
status = setIntegerParam(COAXLINK_Stream_StopScan, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StopScan \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StreamReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StreamReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamReset"); 
status = setIntegerParam(COAXLINK_Stream_StreamReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamReset \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LineWidth")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LineWidth")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LineWidth"); 
status = setIntegerParam(COAXLINK_Stream_LineWidth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LineWidth \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LinePitch")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LinePitch")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LinePitch"); 
status = setIntegerParam(COAXLINK_Stream_LinePitch, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LinePitch \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StripeHeight")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StripeHeight")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StripeHeight"); 
status = setIntegerParam(COAXLINK_Stream_StripeHeight, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StripeHeight \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StripePitch")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StripePitch")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StripePitch"); 
status = setIntegerParam(COAXLINK_Stream_StripePitch, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StripePitch \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StripeArrangement")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StripeArrangement")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StripeArrangement"); 
status = setIntegerParam(COAXLINK_Stream_StripeArrangement, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StripeArrangement \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("ErrorSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ErrorSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ErrorSelector"); 
status = setIntegerParam(COAXLINK_Stream_ErrorSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream ErrorSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("ErrorCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ErrorCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ErrorCount"); 
status = setIntegerParam(COAXLINK_Stream_ErrorCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream ErrorCount \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("ErrorCountReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ErrorCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ErrorCountReset"); 
status = setIntegerParam(COAXLINK_Stream_ErrorCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream ErrorCountReset \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StatisticsSamplingSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StatisticsSamplingSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StatisticsSamplingSelector"); 
status = setIntegerParam(COAXLINK_Stream_StatisticsSamplingSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsSamplingSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StatisticsFrameRate")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StatisticsFrameRate")) 
try { 
systemDouble = grabber.getFloat<Euresys::StreamModule>("StatisticsFrameRate"); 
status = setDoubleParam(COAXLINK_Stream_StatisticsFrameRate, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsFrameRate \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StatisticsLineRate")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StatisticsLineRate")) 
try { 
systemDouble = grabber.getFloat<Euresys::StreamModule>("StatisticsLineRate"); 
status = setDoubleParam(COAXLINK_Stream_StatisticsLineRate, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsLineRate \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StatisticsDataRate")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StatisticsDataRate")) 
try { 
systemDouble = grabber.getFloat<Euresys::StreamModule>("StatisticsDataRate"); 
status = setDoubleParam(COAXLINK_Stream_StatisticsDataRate, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsDataRate \n "); }  

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StatisticsStartSampling")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StatisticsStartSampling")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StatisticsStartSampling"); 
status = setIntegerParam(COAXLINK_Stream_StatisticsStartSampling, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsStartSampling \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("StatisticsStopSampling")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("StatisticsStopSampling")) 
try { 
/* unimplemented command type 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StatisticsStopSampling"); 
status = setIntegerParam(COAXLINK_Stream_StatisticsStopSampling, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsStopSampling \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LinearFilterControl")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LinearFilterControl")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LinearFilterControl"); 
status = setIntegerParam(COAXLINK_Stream_LinearFilterControl, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LinearFilterControl \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LinearFilterCoefficientA")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LinearFilterCoefficientA")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LinearFilterCoefficientA"); 
status = setIntegerParam(COAXLINK_Stream_LinearFilterCoefficientA, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LinearFilterCoefficientA \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LinearFilterCoefficientB")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LinearFilterCoefficientB")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LinearFilterCoefficientB"); 
status = setIntegerParam(COAXLINK_Stream_LinearFilterCoefficientB, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LinearFilterCoefficientB \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("LinearFilterCoefficientC")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("LinearFilterCoefficientC")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LinearFilterCoefficientC"); 
status = setIntegerParam(COAXLINK_Stream_LinearFilterCoefficientC, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LinearFilterCoefficientC \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("ThresholdControl")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ThresholdControl")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ThresholdControl"); 
status = setIntegerParam(COAXLINK_Stream_ThresholdControl, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream ThresholdControl \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("ThresholdLevel")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("ThresholdLevel")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ThresholdLevel"); 
status = setIntegerParam(COAXLINK_Stream_ThresholdLevel, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream ThresholdLevel \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("Scan3dExtractionMethod")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Scan3dExtractionMethod")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("Scan3dExtractionMethod"); 
status = setIntegerParam(COAXLINK_Stream_Scan3dExtractionMethod, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream Scan3dExtractionMethod \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("Scan3dOutputMode")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("Scan3dOutputMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("Scan3dOutputMode"); 
status = setIntegerParam(COAXLINK_Stream_Scan3dOutputMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream Scan3dOutputMode \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("BayerDecoder")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("BayerDecoder")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("BayerDecoder"); 
status = setIntegerParam(COAXLINK_Stream_BayerDecoder, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream BayerDecoder \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("EventSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventSelector"); 
status = setIntegerParam(COAXLINK_Stream_EventSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventSelector \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("EventNotification")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotification")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotification"); 
status = setIntegerParam(COAXLINK_Stream_EventNotification, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventNotification \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("EventNotificationContext1")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotificationContext1")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotificationContext1"); 
status = setIntegerParam(COAXLINK_Stream_EventNotificationContext1, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventNotificationContext1 \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("EventNotificationContext2")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotificationContext2")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotificationContext2"); 
status = setIntegerParam(COAXLINK_Stream_EventNotificationContext2, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventNotificationContext2 \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("EventNotificationContext3")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotificationContext3")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotificationContext3"); 
status = setIntegerParam(COAXLINK_Stream_EventNotificationContext3, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventNotificationContext3 \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("EventCount")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventCount"); 
status = setIntegerParam(COAXLINK_Stream_EventCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventCount \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("EventCountReset")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventCountReset"); 
status = setIntegerParam(COAXLINK_Stream_EventCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventCountReset \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("EventNotificationAll")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventNotificationAll")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotificationAll"); 
status = setIntegerParam(COAXLINK_Stream_EventNotificationAll, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventNotificationAll \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("EventCountResetAll")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("EventCountResetAll")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventCountResetAll"); 
status = setIntegerParam(COAXLINK_Stream_EventCountResetAll, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventCountResetAll \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::StreamModule>(Euresys::RegexFeatures("FlipBit")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("FlipBit")) 
try { 
/* unimplemented int type
systemInteger = grabber.getInteger<Euresys::StreamModule>("FlipBit"); 
status = setIntegerParam(COAXLINK_Stream_FlipBit, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Stream FlipBit \n "); } 
