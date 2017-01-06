/* /home/beams/MENGBRET/test/Euresys_Coaxlink_TLDataStream_6_1_1 */ 

try { 
systemString = grabber.getString<Euresys::StreamModule>("StreamID"); 
status = setStringParam(COAXLINK_Stream_StreamID, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamType"); 
status = setIntegerParam(COAXLINK_Stream_StreamType, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PixelFormat"); 
status = setIntegerParam(COAXLINK_Stream_PixelFormat, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PixelFormatNamespace"); 
status = setIntegerParam(COAXLINK_Stream_PixelFormatNamespace, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PixelSize"); 
status = setIntegerParam(COAXLINK_Stream_PixelSize, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("Width"); 
status = setIntegerParam(COAXLINK_Stream_Width, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("Height"); 
status = setIntegerParam(COAXLINK_Stream_Height, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("UnpackingMode"); 
status = setIntegerParam(COAXLINK_Stream_UnpackingMode, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("RedBlueSwap"); 
status = setIntegerParam(COAXLINK_Stream_RedBlueSwap, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("PayloadSize"); 
status = setIntegerParam(COAXLINK_Stream_PayloadSize, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamAnnouncedBufferCount"); 
status = setIntegerParam(COAXLINK_Stream_StreamAnnouncedBufferCount, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamBufferHandlingMode"); 
status = setIntegerParam(COAXLINK_Stream_StreamBufferHandlingMode, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamAnnounceBufferMinimum"); 
status = setIntegerParam(COAXLINK_Stream_StreamAnnounceBufferMinimum, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamAcquisitionModeSelector"); 
status = setIntegerParam(COAXLINK_Stream_StreamAcquisitionModeSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StartOfScanTriggerSource"); 
status = setIntegerParam(COAXLINK_Stream_StartOfScanTriggerSource, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EndOfScanTriggerSource"); 
status = setIntegerParam(COAXLINK_Stream_EndOfScanTriggerSource, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ScanLength"); 
status = setIntegerParam(COAXLINK_Stream_ScanLength, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("BufferHeight"); 
status = setIntegerParam(COAXLINK_Stream_BufferHeight, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StartScan"); 
status = setIntegerParam(COAXLINK_Stream_StartScan, systemInteger); 

} catch (const std::exception &e) { }  
*/ 


// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StopScan"); 
status = setIntegerParam(COAXLINK_Stream_StopScan, systemInteger); 

} catch (const std::exception &e) { }  
*/ 


// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StreamReset"); 
status = setIntegerParam(COAXLINK_Stream_StreamReset, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ErrorSelector"); 
status = setIntegerParam(COAXLINK_Stream_ErrorSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ErrorCount"); 
status = setIntegerParam(COAXLINK_Stream_ErrorCount, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("ErrorCountReset"); 
status = setIntegerParam(COAXLINK_Stream_ErrorCountReset, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StatisticsSamplingSelector"); 
status = setIntegerParam(COAXLINK_Stream_StatisticsSamplingSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::StreamModule>("StatisticsFrameRate"); 
status = setDoubleParam(COAXLINK_Stream_StatisticsFrameRate, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::StreamModule>("StatisticsLineRate"); 
status = setDoubleParam(COAXLINK_Stream_StatisticsLineRate, systemDouble); 

} catch (const std::exception &e) { }  
try { 
systemDouble = grabber.getFloat<Euresys::StreamModule>("StatisticsDataRate"); 
status = setDoubleParam(COAXLINK_Stream_StatisticsDataRate, systemDouble); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StatisticsStartSampling"); 
status = setIntegerParam(COAXLINK_Stream_StatisticsStartSampling, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("StatisticsStopSampling"); 
status = setIntegerParam(COAXLINK_Stream_StatisticsStopSampling, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventSelector"); 
status = setIntegerParam(COAXLINK_Stream_EventSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotification"); 
status = setIntegerParam(COAXLINK_Stream_EventNotification, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotificationContext1"); 
status = setIntegerParam(COAXLINK_Stream_EventNotificationContext1, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotificationContext2"); 
status = setIntegerParam(COAXLINK_Stream_EventNotificationContext2, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventNotificationContext3"); 
status = setIntegerParam(COAXLINK_Stream_EventNotificationContext3, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventCount"); 
status = setIntegerParam(COAXLINK_Stream_EventCount, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::StreamModule>("EventCountReset"); 
status = setIntegerParam(COAXLINK_Stream_EventCountReset, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

