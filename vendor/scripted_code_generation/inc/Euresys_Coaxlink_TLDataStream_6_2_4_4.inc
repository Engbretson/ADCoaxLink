/* ./Euresys_Coaxlink_TLDataStream_6_2_4 */ 

std::vector<std::string> StreamFeature(grabber.getStringList<Euresys::StreamModule>(Euresys::Features())); 
std::set<std::string> isaStreamFeature(StreamFeature.begin(),StreamFeature.end() ); 


if (isaStreamFeature.count("StreamID")) 
try { 
systemString = grabber.getString<Euresys::StreamModule>("StreamID"); 
status = setStringParam(COAXLINK_Stream_StreamID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamID \n "); }  

if (isaStreamFeature.count("StreamType")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamType"); 
status = setIntegerParam(COAXLINK_Stream_StreamType, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamType \n "); }  

if (isaStreamFeature.count("PixelFormat")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PixelFormat"); 
status = setIntegerParam(COAXLINK_Stream_PixelFormat, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream PixelFormat \n "); }  

if (isaStreamFeature.count("PixelFormatNamespace")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PixelFormatNamespace"); 
status = setIntegerParam(COAXLINK_Stream_PixelFormatNamespace, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream PixelFormatNamespace \n "); }  

if (isaStreamFeature.count("PixelSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PixelSize"); 
status = setIntegerParam(COAXLINK_Stream_PixelSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream PixelSize \n "); } 

if (isaStreamFeature.count("Width")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("Width"); 
status = setIntegerParam(COAXLINK_Stream_Width, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream Width \n "); } 

if (isaStreamFeature.count("Height")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("Height"); 
status = setIntegerParam(COAXLINK_Stream_Height, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream Height \n "); } 

if (isaStreamFeature.count("UnpackingMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("UnpackingMode"); 
status = setIntegerParam(COAXLINK_Stream_UnpackingMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream UnpackingMode \n "); }  

if (isaStreamFeature.count("RedBlueSwap")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("RedBlueSwap"); 
status = setIntegerParam(COAXLINK_Stream_RedBlueSwap, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream RedBlueSwap \n "); }  

if (isaStreamFeature.count("LUTConfiguration")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTConfiguration"); 
status = setIntegerParam(COAXLINK_Stream_LUTConfiguration, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTConfiguration \n "); }  

if (isaStreamFeature.count("LUTLength")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTLength"); 
status = setIntegerParam(COAXLINK_Stream_LUTLength, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTLength \n "); } 

if (isaStreamFeature.count("LUTMaxValue")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTMaxValue"); 
status = setIntegerParam(COAXLINK_Stream_LUTMaxValue, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTMaxValue \n "); } 

if (isaStreamFeature.count("LUTSet")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTSet"); 
status = setIntegerParam(COAXLINK_Stream_LUTSet, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTSet \n "); }  

if (isaStreamFeature.count("LUTIndex")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTIndex"); 
status = setIntegerParam(COAXLINK_Stream_LUTIndex, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTIndex \n "); } 

if (isaStreamFeature.count("LUTValue")) 
try { 
systemString = grabber.getString<Euresys::StreamModule>("LUTValue"); 
status = setStringParam(COAXLINK_Stream_LUTValue, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTValue \n "); }  

if (isaStreamFeature.count("LUTReadBlockLength")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTReadBlockLength"); 
status = setIntegerParam(COAXLINK_Stream_LUTReadBlockLength, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTReadBlockLength \n "); } 

if (isaStreamFeature.count("LUTEnable")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LUTEnable"); 
status = setIntegerParam(COAXLINK_Stream_LUTEnable, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LUTEnable \n "); }  

if (isaStreamFeature.count("PayloadSize")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PayloadSize"); 
status = setIntegerParam(COAXLINK_Stream_PayloadSize, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream PayloadSize \n "); } 

if (isaStreamFeature.count("StreamAnnouncedBufferCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamAnnouncedBufferCount"); 
status = setIntegerParam(COAXLINK_Stream_StreamAnnouncedBufferCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamAnnouncedBufferCount \n "); } 

if (isaStreamFeature.count("StreamBufferHandlingMode")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamBufferHandlingMode"); 
status = setIntegerParam(COAXLINK_Stream_StreamBufferHandlingMode, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamBufferHandlingMode \n "); }  

if (isaStreamFeature.count("StreamAnnounceBufferMinimum")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamAnnounceBufferMinimum"); 
status = setIntegerParam(COAXLINK_Stream_StreamAnnounceBufferMinimum, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamAnnounceBufferMinimum \n "); } 

if (isaStreamFeature.count("StreamAcquisitionModeSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamAcquisitionModeSelector"); 
status = setIntegerParam(COAXLINK_Stream_StreamAcquisitionModeSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamAcquisitionModeSelector \n "); }  

if (isaStreamFeature.count("StartOfScanTriggerSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StartOfScanTriggerSource"); 
status = setIntegerParam(COAXLINK_Stream_StartOfScanTriggerSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StartOfScanTriggerSource \n "); }  

if (isaStreamFeature.count("EndOfScanTriggerSource")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EndOfScanTriggerSource"); 
status = setIntegerParam(COAXLINK_Stream_EndOfScanTriggerSource, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EndOfScanTriggerSource \n "); }  

if (isaStreamFeature.count("ScanLength")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ScanLength"); 
status = setIntegerParam(COAXLINK_Stream_ScanLength, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream ScanLength \n "); } 

if (isaStreamFeature.count("BufferHeight")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("BufferHeight"); 
status = setIntegerParam(COAXLINK_Stream_BufferHeight, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream BufferHeight \n "); } 

// start of an execute (write Only) command 
/* 

if (isaStreamFeature.count("StartScan")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StartScan"); 
status = setIntegerParam(COAXLINK_Stream_StartScan, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StartScan \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaStreamFeature.count("StopScan")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StopScan"); 
status = setIntegerParam(COAXLINK_Stream_StopScan, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StopScan \n "); }  
*/ 


// start of an execute (write Only) command 
/* 

if (isaStreamFeature.count("StreamReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamReset"); 
status = setIntegerParam(COAXLINK_Stream_StreamReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StreamReset \n "); }  
*/ 


if (isaStreamFeature.count("LineWidth")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LineWidth"); 
status = setIntegerParam(COAXLINK_Stream_LineWidth, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LineWidth \n "); } 

if (isaStreamFeature.count("LinePitch")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("LinePitch"); 
status = setIntegerParam(COAXLINK_Stream_LinePitch, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream LinePitch \n "); } 

if (isaStreamFeature.count("StripeHeight")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StripeHeight"); 
status = setIntegerParam(COAXLINK_Stream_StripeHeight, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StripeHeight \n "); } 

if (isaStreamFeature.count("StripePitch")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StripePitch"); 
status = setIntegerParam(COAXLINK_Stream_StripePitch, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StripePitch \n "); } 

if (isaStreamFeature.count("ErrorSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ErrorSelector"); 
status = setIntegerParam(COAXLINK_Stream_ErrorSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream ErrorSelector \n "); }  

if (isaStreamFeature.count("ErrorCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ErrorCount"); 
status = setIntegerParam(COAXLINK_Stream_ErrorCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream ErrorCount \n "); } 

// start of an execute (write Only) command 
/* 

if (isaStreamFeature.count("ErrorCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ErrorCountReset"); 
status = setIntegerParam(COAXLINK_Stream_ErrorCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream ErrorCountReset \n "); }  
*/ 


if (isaStreamFeature.count("StatisticsSamplingSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StatisticsSamplingSelector"); 
status = setIntegerParam(COAXLINK_Stream_StatisticsSamplingSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsSamplingSelector \n "); }  

if (isaStreamFeature.count("StatisticsFrameRate")) 
try { 
systemDouble = grabber.getFloat<Euresys::StreamModule>("StatisticsFrameRate"); 
status = setDoubleParam(COAXLINK_Stream_StatisticsFrameRate, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsFrameRate \n "); }  

if (isaStreamFeature.count("StatisticsLineRate")) 
try { 
systemDouble = grabber.getFloat<Euresys::StreamModule>("StatisticsLineRate"); 
status = setDoubleParam(COAXLINK_Stream_StatisticsLineRate, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsLineRate \n "); }  

if (isaStreamFeature.count("StatisticsDataRate")) 
try { 
systemDouble = grabber.getFloat<Euresys::StreamModule>("StatisticsDataRate"); 
status = setDoubleParam(COAXLINK_Stream_StatisticsDataRate, systemDouble); 

} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsDataRate \n "); }  

// start of an execute (write Only) command 
/* 

if (isaStreamFeature.count("StatisticsStartSampling")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StatisticsStartSampling"); 
status = setIntegerParam(COAXLINK_Stream_StatisticsStartSampling, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsStartSampling \n "); }  
*/ 


if (isaStreamFeature.count("StatisticsStopSampling")) 
try { 
/* 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StatisticsStopSampling"); 
status = setIntegerParam(COAXLINK_Stream_StatisticsStopSampling, systemInteger); 

*/ 
} catch (const std::exception &e) { printf("Fix me exception Stream StatisticsStopSampling \n "); }  

if (isaStreamFeature.count("EventSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventSelector"); 
status = setIntegerParam(COAXLINK_Stream_EventSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventSelector \n "); }  

if (isaStreamFeature.count("EventNotification")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotification"); 
status = setIntegerParam(COAXLINK_Stream_EventNotification, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventNotification \n "); }  

if (isaStreamFeature.count("EventNotificationContext1")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotificationContext1"); 
status = setIntegerParam(COAXLINK_Stream_EventNotificationContext1, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventNotificationContext1 \n "); }  

if (isaStreamFeature.count("EventNotificationContext2")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotificationContext2"); 
status = setIntegerParam(COAXLINK_Stream_EventNotificationContext2, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventNotificationContext2 \n "); }  

if (isaStreamFeature.count("EventNotificationContext3")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotificationContext3"); 
status = setIntegerParam(COAXLINK_Stream_EventNotificationContext3, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventNotificationContext3 \n "); }  

if (isaStreamFeature.count("EventCount")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventCount"); 
status = setIntegerParam(COAXLINK_Stream_EventCount, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventCount \n "); } 

// start of an execute (write Only) command 
/* 

if (isaStreamFeature.count("EventCountReset")) 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventCountReset"); 
status = setIntegerParam(COAXLINK_Stream_EventCountReset, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception Stream EventCountReset \n "); }  
*/ 

