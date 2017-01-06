/* /home/beams/MENGBRET/test/Euresys_Coaxlink_TLSystem_6_1_1 */ 

try { 
systemString = grabber.getString<Euresys::SystemModule>("TLVendorName"); 
status = setStringParam(COAXLINK_System_TLVendorName, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLModelName"); 
status = setStringParam(COAXLINK_System_TLModelName, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLID"); 
status = setStringParam(COAXLINK_System_TLID, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLVersion"); 
status = setStringParam(COAXLINK_System_TLVersion, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLPath"); 
status = setStringParam(COAXLINK_System_TLPath, systemString.c_str()); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("TLType"); 
status = setIntegerParam(COAXLINK_System_TLType, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("GenTLVersionMajor"); 
status = setIntegerParam(COAXLINK_System_GenTLVersionMajor, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("GenTLVersionMinor"); 
status = setIntegerParam(COAXLINK_System_GenTLVersionMinor, systemInteger); 

} catch (const std::exception &e) { }  

// start of an execute (write Only) command 
/* 
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("InterfaceUpdateList"); 
status = setIntegerParam(COAXLINK_System_InterfaceUpdateList, systemInteger); 

} catch (const std::exception &e) { }  
*/ 

try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("InterfaceSelector"); 
status = setIntegerParam(COAXLINK_System_InterfaceSelector, systemInteger); 

} catch (const std::exception &e) { }  
try { 
systemString = grabber.getString<Euresys::SystemModule>("InterfaceID"); 
status = setStringParam(COAXLINK_System_InterfaceID, systemString.c_str()); 

} catch (const std::exception &e) { }  
