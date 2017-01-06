//

// special case, first element is 255 (-1, 8-bit)

try { 
grabber.setInteger<Euresys::DeviceModule>("ErrorSelector",255); 
//callParamCallbacks();
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorCount"); 
status = setIntegerParam((COAXLINK_D_All), systemInteger); 
callParamCallbacks();
//printf(" %d %d %d\n",a,systemInteger,COAXLINK_D_All);
} catch (const std::exception &e) { }  


 for( int a = 1; a < 20; a = a + 1 ) {
try { 
grabber.setInteger<Euresys::DeviceModule>("ErrorSelector",a); 
//callParamCallbacks();
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorCount"); 
status = setIntegerParam((COAXLINK_D_All + a), systemInteger); 
callParamCallbacks();
//printf(" %d %d %d\n",a,systemInteger,COAXLINK_D_All + a );
} catch (const std::exception &e) { }  
      
}

// Special case, restore the original value

try { 
grabber.setInteger<Euresys::DeviceModule>("ErrorSelector",255); 
} catch (const std::exception &e) { }  

callParamCallbacks();

/*
try {
systemInteger = grabber.getInteger<Euresys::DeviceModule>("ErrorSelector"); 
printf(" %d \n",systemInteger);
} catch (const std::exception &e) { }  
*/
