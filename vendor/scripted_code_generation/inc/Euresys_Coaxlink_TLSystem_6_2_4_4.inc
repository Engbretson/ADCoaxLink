/* ./Euresys_Coaxlink_TLSystem_6_2_4 */ 

std::vector<std::string> SystemFeature(grabber.getStringList<Euresys::SystemModule>(Euresys::Features())); 
std::set<std::string> isaSystemFeature(SystemFeature.begin(),SystemFeature.end() ); 


if (isaSystemFeature.count("TLVendorName")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLVendorName"); 
status = setStringParam(COAXLINK_System_TLVendorName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System TLVendorName \n "); }  

if (isaSystemFeature.count("TLModelName")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLModelName"); 
status = setStringParam(COAXLINK_System_TLModelName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System TLModelName \n "); }  

if (isaSystemFeature.count("TLID")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLID"); 
status = setStringParam(COAXLINK_System_TLID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System TLID \n "); }  

if (isaSystemFeature.count("TLVersion")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLVersion"); 
status = setStringParam(COAXLINK_System_TLVersion, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System TLVersion \n "); }  

if (isaSystemFeature.count("TLPath")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLPath"); 
status = setStringParam(COAXLINK_System_TLPath, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System TLPath \n "); }  

if (isaSystemFeature.count("TLType")) 
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("TLType"); 
status = setIntegerParam(COAXLINK_System_TLType, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception System TLType \n "); }  

if (isaSystemFeature.count("GenTLVersionMajor")) 
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("GenTLVersionMajor"); 
status = setIntegerParam(COAXLINK_System_GenTLVersionMajor, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception System GenTLVersionMajor \n "); } 

if (isaSystemFeature.count("GenTLVersionMinor")) 
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("GenTLVersionMinor"); 
status = setIntegerParam(COAXLINK_System_GenTLVersionMinor, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception System GenTLVersionMinor \n "); } 

// start of an execute (write Only) command 
/* 

if (isaSystemFeature.count("InterfaceUpdateList")) 
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("InterfaceUpdateList"); 
status = setIntegerParam(COAXLINK_System_InterfaceUpdateList, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception System InterfaceUpdateList \n "); }  
*/ 


if (isaSystemFeature.count("InterfaceSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("InterfaceSelector"); 
status = setIntegerParam(COAXLINK_System_InterfaceSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception System InterfaceSelector \n "); } 

if (isaSystemFeature.count("InterfaceID")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("InterfaceID"); 
status = setStringParam(COAXLINK_System_InterfaceID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System InterfaceID \n "); }  
