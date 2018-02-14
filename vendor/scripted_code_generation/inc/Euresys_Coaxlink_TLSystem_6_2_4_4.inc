/* ./Euresys_Coaxlink_TLSystem_6_2_4 */ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::SystemModule>(Euresys::RegexFeatures("TLVendorName")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TLVendorName")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLVendorName"); 
status = setStringParam(COAXLINK_System_TLVendorName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System TLVendorName \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::SystemModule>(Euresys::RegexFeatures("TLModelName")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TLModelName")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLModelName"); 
status = setStringParam(COAXLINK_System_TLModelName, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System TLModelName \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::SystemModule>(Euresys::RegexFeatures("TLID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TLID")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLID"); 
status = setStringParam(COAXLINK_System_TLID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System TLID \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::SystemModule>(Euresys::RegexFeatures("TLVersion")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TLVersion")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLVersion"); 
status = setStringParam(COAXLINK_System_TLVersion, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System TLVersion \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::SystemModule>(Euresys::RegexFeatures("TLPath")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TLPath")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("TLPath"); 
status = setStringParam(COAXLINK_System_TLPath, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System TLPath \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::SystemModule>(Euresys::RegexFeatures("TLType")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("TLType")) 
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("TLType"); 
status = setIntegerParam(COAXLINK_System_TLType, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception System TLType \n "); }  

Feature.clear(); 
Feature = grabber.getStringList<Euresys::SystemModule>(Euresys::RegexFeatures("GenTLVersionMajor")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("GenTLVersionMajor")) 
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("GenTLVersionMajor"); 
status = setIntegerParam(COAXLINK_System_GenTLVersionMajor, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception System GenTLVersionMajor \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::SystemModule>(Euresys::RegexFeatures("GenTLVersionMinor")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("GenTLVersionMinor")) 
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("GenTLVersionMinor"); 
status = setIntegerParam(COAXLINK_System_GenTLVersionMinor, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception System GenTLVersionMinor \n "); } 

// start of an execute (write Only) command 
/* 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::SystemModule>(Euresys::RegexFeatures("InterfaceUpdateList")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("InterfaceUpdateList")) 
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("InterfaceUpdateList"); 
status = setIntegerParam(COAXLINK_System_InterfaceUpdateList, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception System InterfaceUpdateList \n "); }  
*/ 


Feature.clear(); 
Feature = grabber.getStringList<Euresys::SystemModule>(Euresys::RegexFeatures("InterfaceSelector")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("InterfaceSelector")) 
try { 
systemInteger = grabber.getInteger<Euresys::SystemModule>("InterfaceSelector"); 
status = setIntegerParam(COAXLINK_System_InterfaceSelector, systemInteger); 

} catch (const std::exception &e) { printf("Fix me exception System InterfaceSelector \n "); } 

Feature.clear(); 
Feature = grabber.getStringList<Euresys::SystemModule>(Euresys::RegexFeatures("InterfaceID")); 
isaFeature.insert(Feature.begin(),Feature.end() ); 

if (isaFeature.count("InterfaceID")) 
try { 
systemString = grabber.getString<Euresys::SystemModule>("InterfaceID"); 
status = setStringParam(COAXLINK_System_InterfaceID, systemString.c_str()); 

} catch (const std::exception &e) { printf("Fix me exception System InterfaceID \n "); }  
