#!/bin/env python
import os, sys
from xml.dom.minidom import parse
from optparse import OptionParser

# parse args
parser = OptionParser("""%prog <genicam_xml> <camera_name>

This script parses a genicam xml file and creates a database template and edm 
screen to go with it. The edm screen should be used as indication of what
the driver supports, and the generated summary screen should be edited to make
a more sensible summary. The Db file will be generated in:
  ../Db/<camera_name>.template
and the edm files will be called:
  ../opi/edl/<camera_name>.edl
  ../opi/edl/<camera_name>-features.edl""")
options, args = parser.parse_args()
if len(args) != 3:
    parser.error("Incorrect number of arguments")

# parse xml file to dom object
xml_root = parse(args[0])
camera_name = args[1]
mask_name = args[2]

list = ['DeviceVendorName','DeviceModelName','ExposureTime','Gain','PixelFormat','Width','Height','PayloadSize',
	'ErrorSelector','ErrorCount','ErrorCountReset','EventSelector','EventNotification','EventNotificationContext1',
	'EventNotificationContext2','EventNotificationContext3','EventCountReset','DeviceID','DeviceAccessStatus',
	'CxpHostConnectionCount','EventCount','InterfaceID','Temperature','StreamID',
	] 

prefix = os.path.abspath(os.path.join(os.path.dirname(__file__),"."))
db_filename = os.path.join(prefix, "Db", camera_name + ".template")
#edl_filename = os.path.join(prefix, "opi", "edl", camera_name + ".edl")
adl_filename= os.path.join(prefix, "opi", "adl", camera_name + "_")

include_1_filename =os.path.join(prefix, "inc", camera_name + "_1.inc")
include_2_filename =os.path.join(prefix, "inc", camera_name + "_2.inc")
include_3_filename =os.path.join(prefix, "inc", camera_name + "_3.inc")
include_4_filename =os.path.join(prefix, "inc", camera_name + "_4.inc")


# function to read element children of a node
def elements(node):
    return [n for n in node.childNodes if n.nodeType == n.ELEMENT_NODE]  

# a function to read the text children of a node
def getText(node):
    return ''.join([n.data for n in node.childNodes if n.nodeType == n.TEXT_NODE])

# node lookup from nodeName -> node
lookup = {}
# lookup from nodeName -> recordName
records = {}
# add ADBase names to avoid
#ADNames = ["PortName", "Manufacturer", "Model", "MaxSizeX", "MaxSizeY", 
#"DataType", "ColorMode", "BinX", "BinY", "MinX", "MinY", "SizeX", "SizeY",
#"ReverseX", "ReverseY", "ArraySizeX", "ArraySizeY", "ArraySizeZ", "ArraySize",
#"AcquireTime", "AcquirePeriod", "TimeRemaining", "Gain", "FrameType", 
#"ImageMode", "TriggerMode", "NumExposures", "NumExposuresCounter", "NumImages",
#"NumImagesCounter", "Acquire", "ArrayCounter", "ArrayRate", "DetectorState",
#"ArrayCallbacks", "NDAttributesFile", "StatusMessage", "StringToServer",
#"StringFromServer", "ReadStatus", "ShutterMode", "ShutterControl",
#"ShutterStatus", "ShutterOpenDelay", "ShutterCloseDelay", "ShutterControlEPICS",
#"ShutterFanout", "ShutterOpenEPICS", "ShutterCloseEPICS", "ShutterStatusEPICS",
#"Temperature", "AsynIO", "PortName"]
#for name in ADNames:
#    records[name] = name
categories = []

# function to create a lookup table of nodes
def handle_node(node):
    if node.nodeName == "Group":
        for n in elements(node):
            handle_node(n)
    elif node.hasAttribute("Name"):
        name = str(node.getAttribute("Name"))
        lookup[name] = node
        recordName = name
	fullrecordName = name
#        if len(recordName) > 16:
#            recordName = recordName[:16]
        i = 0
        while recordName in records.values():
            recordName = recordName[:-len(str(i))] + str(i)
            i += 1
        records[name] = recordName
        if node.nodeName == "Category":
            categories.append(name)
    elif node.nodeName != "StructReg":
        print "Node has no Name attribute", node

# list of all nodes    
for node in elements(elements(xml_root)[0]):
    handle_node(node)

# Now make structure, [(title, [features...]), ...]
structure = []
doneNodes = []
def handle_category(category):
    # making flat structure, so if its already there then don't do anything
    if category in [x[0] for x in structure]:
        return
    node = lookup[category]
    # for each child feature of this node
    features = []
    cgs = []
    for feature in elements(node):        
        if feature.nodeName == "pFeature":
            featureName = str(getText(feature))
            featureNode = lookup[featureName]
            if str(featureNode.nodeName) == "Category":
                cgs.append(featureName)
            else:
                if featureNode not in doneNodes:
                    features.append(featureNode)   
                    doneNodes.append(featureNode)
    if features:
        if len(features) > 32:
            i = 1
            while features:
                structure.append((category+str(i), features[:32]))
                i += 1
                features = features[32:]
        else:            
            structure.append((category, features))
    for category in cgs:
        handle_category(category)

for category in categories:
    handle_category(category)
    
# Spit out a database file
db_file = open(db_filename, "w")
stdout = sys.stdout
sys.stdout = db_file

include_1_filename = open(include_1_filename, "w")
include_1_filename.write('/* %s */ \n\n' % camera_name)  
 
include_2_filename = open(include_2_filename, "w")
include_2_filename.write('/* %s */ \n\n' % camera_name)   

include_3_filename = open(include_3_filename, "w")
include_3_filename.write('/* %s */ \n\n' % camera_name) 

include_4_filename = open(include_4_filename, "w")
include_4_filename.write('/* %s */ \n\n' % camera_name)  
 

# print a header
print '# Macros:'
print '#% macro, P, Device Prefix'
print '#% macro, R, Device Suffix'
print '#% macro, PORT, Asyn Port name'
print '#% macro, TIMEOUT, Timeout'
print '#% macro, ADDR, Asyn Port address'
print '#%% gui, $(PORT), edmtab, %s.edl, P=$(P),R=$(R)' % camera_name
print 


# for each node
for node in doneNodes:
    nodeName = str(node.getAttribute("Name"))
    nodeName0 = nodeName
    nodeName1 = mask_name + '_' + nodeName
    
    ro = False
    execute = False
    longenum = False
    specialcase = False
    for n in elements(node):
    
        if str(n.nodeName) == "CommandValue" and getText(n) == "1":
            execute = True
  
        if str(n.nodeName) == "ImposedAccessMode" and getText(n) == "WO":
            execute = True

        if str(n.nodeName) == "AccessMode" and getText(n) == "RO":
            ro = True
	    
	if nodeName in list:
	   nodeNameSpecial = nodeName;
	   nodeName = nodeName + '+'+ mask_name[0]
#	   nodeName1 = nodeName1 + '+' + mask_name[0] # this may not work
	   specialcase = True
	    
    if node.nodeName in ["Integer", "IntConverter", "IntSwissKnife", "IntReg"]:
#        print 'record(longin, "$(P)$(R)%s_RBV") {' % records[nodeName]
        print 'record(longin, "$(P)$(R)%s_RBV") {' % nodeName
        print '  field(DTYP, "asynInt32")'
        print '  field(INP,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
        print '  field(SCAN, "I/O Intr")'
        print '  field(DISA, "0")'        
        print '}'
        print  
	include_1_filename.write('int COAXLINK_%s; \n' % nodeName1)   
	include_2_filename.write('#define COAXLINK_%(one)sString "%(two)s" \n'  % {"one":nodeName1, "two":nodeName}) 
	include_3_filename.write('createParam(COAXLINK_%(one)sString, asynParamInt32, &COAXLINK_%(two)s);\n\n'  % {"one":nodeName1, "two":nodeName1}) 
	include_4_filename.write('try { \n')
	include_4_filename.write('systemInteger = grabber.getInteger<Euresys::%(one)sModule>("%(three)s"); \n'  % {"three":nodeName0,"one":mask_name}) 
	include_4_filename.write('status = setIntegerParam(COAXLINK_%(one)s, systemInteger); \n\n'  % {"one":nodeName1}) 
#	include_4_filename.write('} catch (const std::exception &e) { std::cout << "error: %(one)s (" << COAXLINK_%(one)s << ") " << e.what() << std::endl; }  \n' % {"one":nodeName1)}  
#	include_4_filename.write('} catch (const std::exception &e) { std::cout << "error: %(one)s (" << COAXLINK_%(one)s << ") " <<e.what() << std::endl; }  \n' % {"one":nodeName1})  
	include_4_filename.write('} catch (const std::exception &e) { }  \n')  
        if ro:
            continue        
#        print 'record(longout, "$(P)$(R)%s") {' % records[nodeName]
        print 'record(longout, "$(P)$(R)%s") {' % nodeName
        print '  field(DTYP, "asynInt32")'
        print '  field(OUT,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
        print '  field(DISA, "0")'
        print '}'
        print        
    elif node.nodeName in ["Boolean"]:
#        print 'record(bi, "$(P)$(R)%s_RBV") {' % records[nodeName]
        print 'record(bi, "$(P)$(R)%s_RBV") {' % nodeName
        print '  field(DTYP, "asynInt32")'
        print '  field(INP,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
        print '  field(SCAN, "I/O Intr")'
        print '  field(ZNAM, "No")'
        print '  field(ONAM, "Yes")'                        
        print '  field(DISA, "0")'
        print '}'
        print
	include_1_filename.write('int COAXLINK_%s; \n' % nodeName1)   
	include_2_filename.write('#define COAXLINK_%(one)sString "%(two)s" \n'  % {"one":nodeName1, "two":nodeName})   
	include_3_filename.write('createParam(COAXLINK_%(one)sString, asynParamInt32, &COAXLINK_%(two)s);\n\n'  % {"one":nodeName1, "two":nodeName1}) 
	include_4_filename.write('try { \n')
	include_4_filename.write('systemInteger = grabber.getInteger<Euresys::%(one)sModule>("%(three)s"); \n'  % {"three":nodeName0,"one":mask_name}) 
	include_4_filename.write('status = setIntegerParam(COAXLINK_%(one)s, systemInteger); \n\n'  % {"one":nodeName1}) 
#	include_4_filename.write('} catch (const std::exception &e) { std::cout << "error: %(one)s (" << COAXLINK_%(one)s << ") " <<e.what() << std::endl; }  \n' % {"one":nodeName1})  
	include_4_filename.write('} catch (const std::exception &e) { }  \n')  

        if ro:
            continue        
#        print 'record(bo, "$(P)$(R)%s") {' % records[nodeName]
        print 'record(bo, "$(P)$(R)%s") {' % nodeName
        print '  field(DTYP, "asynInt32")'
        print '  field(OUT,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
        print '  field(ZNAM, "No")'
        print '  field(ONAM, "Yes")'                                
        print '  field(DISA, "0")'
        print '}'
        print           
    elif node.nodeName in ["Float", "Converter", "SwissKnife","FloatReg"]:
#        print 'record(ai, "$(P)$(R)%s_RBV") {' % records[nodeName]
        print 'record(ai, "$(P)$(R)%s_RBV") {' % nodeName
        print '  field(DTYP, "asynFloat64")'
        print '  field(INP,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
        print '  field(PREC, "3")'        
        print '  field(SCAN, "I/O Intr")'
        print '  field(DISA, "0")'
        print '}'
        print 
	include_1_filename.write('int COAXLINK_%s; \n' % nodeName1)     
	include_2_filename.write('#define COAXLINK_%(one)sString "%(two)s" \n'  % {"one":nodeName1, "two":nodeName})   
	include_3_filename.write('createParam(COAXLINK_%(one)sString, asynParamFloat64, &COAXLINK_%(two)s);\n\n'  % {"one":nodeName1, "two":nodeName1}) 
	include_4_filename.write('try { \n')
	include_4_filename.write('systemDouble = grabber.getFloat<Euresys::%(one)sModule>("%(three)s"); \n'  % {"three":nodeName0,"one":mask_name}) 
	include_4_filename.write('status = setDoubleParam(COAXLINK_%(one)s, systemDouble); \n\n'  % {"one":nodeName1}) 
#	include_4_filename.write('} catch (const std::exception &e) { std::cout << "error: %(one)s (" << COAXLINK_%(one)s << ") " <<e.what() << std::endl; }  \n' % {"one":nodeName1})  
	include_4_filename.write('} catch (const std::exception &e) { }  \n')  

        if ro:
            continue    
#        print 'record(ao, "$(P)$(R)%s") {' % records[nodeName]
        print 'record(ao, "$(P)$(R)%s") {' % nodeName
        print '  field(DTYP, "asynFloat64")'
        print '  field(OUT,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
        print '  field(PREC, "3")'
        print '  field(DISA, "0")'
        print '}'
        print
    elif node.nodeName in ["StringReg","String"]:
#        print 'record(stringin, "$(P)$(R)%s_RBV") {' % records[nodeName]
        print 'record(stringin, "$(P)$(R)%s_RBV") {' % nodeName
        print '  field(DTYP, "asynOctetRead")'
        print '  field(INP,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
        print '  field(SCAN, "I/O Intr")'
        print '  field(DISA, "0")'
        print '}'
        print
	include_1_filename.write('int COAXLINK_%s; \n' % nodeName1)  
	include_2_filename.write('#define COAXLINK_%(one)sString "%(two)s" \n'  % {"one":nodeName1, "two":nodeName})   
	include_3_filename.write('createParam(COAXLINK_%(one)sString, asynParamOctet, &COAXLINK_%(two)s);\n\n'  % {"one":nodeName1, "two":nodeName1}) 
	include_4_filename.write('try { \n')
#	include_4_filename.write('systemString = grabber.getString<Euresys::%(one)sModule>(COAXLINK_%(three)sString); \n'  % {"three":nodeName1,"one":mask_name}) 
	include_4_filename.write('systemString = grabber.getString<Euresys::%(one)sModule>("%(three)s"); \n'  % {"three":nodeName0,"one":mask_name}) 
	include_4_filename.write('status = setStringParam(COAXLINK_%(one)s, systemString.c_str()); \n\n'  % {"one":nodeName1}) 
#	include_4_filename.write('} catch (const std::exception &e) { std::cout << "error: %(one)s (" << COAXLINK_%(one)s << ") " <<e.what() << std::endl; }  \n' % {"one":nodeName1})  
	include_4_filename.write('} catch (const std::exception &e) { }  \n')  
    elif node.nodeName in ["Command"]:
#        print 'record(longout, "$(P)$(R)%s") {' % records[nodeName]
        print 'record(longout, "$(P)$(R)%s") {' % nodeName
        print '  field(DTYP, "asynInt32")'
        print '  field(OUT,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
        print '  field(DISA, "0")'
        print '}'
        print 
	include_1_filename.write('int COAXLINK_%s; \n' % nodeName1)          
	include_2_filename.write('#define COAXLINK_%(one)sString "%(two)s" \n'  % {"one":nodeName1, "two":nodeName})   
	include_3_filename.write('createParam(COAXLINK_%(one)sString, asynParamInt32, &COAXLINK_%(two)s);\n\n'  % {"one":nodeName1, "two":nodeName1}) 
        if execute:
	    include_4_filename.write('\n// start of an execute (write Only) command \n')
	    include_4_filename.write('/* \n')
	include_4_filename.write('try { \n')
	include_4_filename.write('systemInteger = grabber.getInteger<Euresys::%(one)sModule>("%(three)s"); \n'  % {"three":nodeName0,"one":mask_name}) 
	include_4_filename.write('status = setIntegerParam(COAXLINK_%(one)s, systemInteger); \n\n'  % {"one":nodeName1}) 
#	include_4_filename.write('} catch (const std::exception &e) { std::cout << "error: %(one)s (" << COAXLINK_%(one)s << ") " <<e.what() << std::endl; }  \n' % {"one":nodeName1})  
	include_4_filename.write('} catch (const std::exception &e) { }  \n')  
        if execute:
	    include_4_filename.write('*/ \n\n')

    elif node.nodeName in ["Enumeration"]:
        enumerations = ""
	bigenumerations = ""
        i = 0
        epicsId = ["ZR", "ON", "TW", "TH", "FR", "FV", "SX", "SV", "EI", "NI", "TE", "EL", "TV", "TT", "FT", "FF",
	"ZR1", "ON1", "TW1", "TH1", "FR1", "FV1", "SX1", "SV1", "EI1", "NI1", "TE1", "EL1", "TV1", "TT1", "FT1", "FF1",
	"ZR2", "ON2", "TW2", "TH2", "FR2", "FV2", "SX2", "SV2", "EI2", "NI2", "TE2", "EL2", "TV2", "TT2", "FT2", "FF2",
	"ZR3", "ON3", "TW3", "TH3", "FR3", "FV3", "SX3", "SV3", "EI3", "NI3", "TE3", "EL3", "TV3", "TT3", "FT3", "FF3",
	"ZR4", "ON4", "TW4", "TH4", "FR4", "FV4", "SX4", "SV4", "EI4", "NI4", "TE4", "EL4", "TV4", "TT4", "FT4", "FF4",
	"ZR5", "ON5", "TW5", "TH5", "FR5", "FV5", "SX5", "SV5", "EI5", "NI5", "TE5", "EL5", "TV5", "TT5", "FT5", "FF5",
	"ZR6", "ON6", "TW6", "TH6", "FR6", "FV6", "SX6", "SV6", "EI6", "NI6", "TE6", "EL6", "TV6", "TT6", "FT6", "FF6",
	"ZR7", "ON7", "TW7", "TH7", "FR7", "FV7", "SX7", "SV7", "EI7", "NI7", "TE7", "EL7", "TV7", "TT7", "FT7", "FF7",
	"ZR8", "ON8", "TW8", "TH8", "FR8", "FV8", "SX8", "SV8", "EI8", "NI8", "TE8", "EL8", "TV8", "TT8", "FT8", "FF8",
	"ZR9", "ON9", "TW9", "TH9", "FR9", "FV9", "SX9", "SV9", "EI9", "NI9", "TE9", "EL9", "TV9", "TT9", "FT9", "FF9",
	"ZR10", "ON10", "TW10", "TH10", "FR10", "FV10", "SX10", "SV10", "EI10", "NI10", "TE10", "EL10", "TV10", "TT10", "FT10", "FF10",
	"ZR11", "ON11", "TW11", "TH11", "FR11", "FV11", "SX11", "SV11", "EI11", "NI11", "TE11", "EL11", "TV11", "TT11", "FT11", "FF11",
	"ZR12", "ON12", "TW12", "TH12", "FR12", "FV12", "SX12", "SV12", "EI12", "NI12", "TE12", "EL12", "TV12", "TT12", "FT12", "FF12",
	"ZR13", "ON13", "TW13", "TH13", "FR13", "FV13", "SX13", "SV13", "EI13", "NI13", "TE13", "EL13", "TV13", "TT13", "FT13", "FF13",
	"ZR14", "ON14", "TW14", "TH14", "FR14", "FV14", "SX14", "SV14", "EI14", "NI14", "TE14", "EL14", "TV14", "TT14", "FT14", "FF14",
	"ZR15", "ON15", "TW15", "TH15", "FR15", "FV15", "SX15", "SV15", "EI15", "NI15", "TE15", "EL15", "TV15", "TT15", "FT15", "FF15",
	"ZR16", "ON16", "TW16", "TH16", "FR16", "FV16", "SX16", "SV16", "EI16", "NI16", "TE16", "EL16", "TV16", "TT16", "FT16", "FF16",
	
	]
        for n in elements(node):
            if str(n.nodeName) == "EnumEntry":
	    	if i >= 16:
		    longenum = True
                if i >= len(epicsId):
                    print >> sys.stderr, "Too many enum entries in %s, truncating" % nodeName
 #                   break
                name = str(n.getAttribute("Name"))
                bigenumerations += '#  field(%sST, "%s")\n' %(epicsId[i], name[:16])
                enumerations += '  field(%sST, "%s")\n' %(epicsId[i], name[:16])
                value = [x for x in elements(n) if str(x.nodeName) == "Value"]
                assert value, "EnumEntry %s in node %s doesn't have a value" %(name, nodeName)                
		bigenumerations += '#  field(%sVL, "%s")\n' %(epicsId[i], getText(value[0]))                
		enumerations += '  field(%sVL, "%s")\n' %(epicsId[i], getText(value[0]))                
                i += 1                
#        print 'record(mbbi, "$(P)$(R)%s_RBV") {' % records[nodeName]
	if longenum:
		print '#record(mbbi, "$(P)$(R)%s_RBV") {' % nodeName
	        print '#  field(DTYP, "asynInt32")'
	        print '#  field(INP,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
	        print bigenumerations,
	        print '#  field(SCAN, "I/O Intr")'
	        print '#  field(DISA, "0")'
	        print '#}'
	        print
		print 'record(stringin, "$(P)$(R)%s_RBV") {' % nodeName
        	print '  field(DTYP, "asynOctetRead")'
        	print '  field(INP,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
        	print '  field(SCAN, "I/O Intr")'
        	print '  field(DISA, "0")'
        	print '}'
        	print

	else:
		print 'record(mbbi, "$(P)$(R)%s_RBV") {' % nodeName
	        print '  field(DTYP, "asynInt32")'
	        print '  field(INP,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
	        print enumerations,
	        print '  field(SCAN, "I/O Intr")'
	        print '  field(DISA, "0")'
	        print '}'
	        print
	
 	include_1_filename.write('int COAXLINK_%s; \n' % nodeName1)  
	include_2_filename.write('#define COAXLINK_%(one)sString "%(two)s" \n'  % {"one":nodeName1, "two":nodeName})   
	include_3_filename.write('createParam(COAXLINK_%(one)sString, asynParamInt32, &COAXLINK_%(two)s);\n\n'  % {"one":nodeName1, "two":nodeName1}) 
	include_4_filename.write('try { \n')
	include_4_filename.write('systemInteger = grabber.getInteger<Euresys::%(one)sModule>("%(three)s"); \n'  % {"three":nodeName0,"one":mask_name}) 
	include_4_filename.write('status = setIntegerParam(COAXLINK_%(one)s, systemInteger); \n\n'  % {"one":nodeName1}) 
#	include_4_filename.write('} catch (const std::exception &e) { std::cout << "error: %(one)s (" << COAXLINK_%(one)s << ") " <<e.what() << std::endl; }  \n' % {"one":nodeName1})  
	include_4_filename.write('} catch (const std::exception &e) { }  \n')  
        if ro:
            continue        
#        print 'record(mbbo, "$(P)$(R)%s") {' % records[nodeName]
	if longenum:
		print '#record(mbbo, "$(P)$(R)%s") {' % nodeName
        	print '#  field(DTYP, "asynInt32")'
        	print '#  field(OUT,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
        	print bigenumerations,       
        	print '#  field(DISA, "0")'
        	print '#}'
        	print
	else:
		print 'record(mbbo, "$(P)$(R)%s") {' % nodeName
        	print '  field(DTYP, "asynInt32")'
        	print '  field(OUT,  "@asyn($(PORT),$(ADDR),$(TIMEOUT))%s")' % nodeName
        	print enumerations,       
        	print '  field(DISA, "0")'
        	print '}'
        	print
	          
        
    else:
        print >> sys.stderr, "Don't know what to do with >%s<" % node.nodeName
    
# tidy up
include_1_filename.close()
include_2_filename.close()
include_3_filename.close()
include_4_filename.close()

db_file.close()     
sys.stdout = stdout

# Spit out a feature screen
#edl_file = open(edl_more_filename, "w")
w = 260
h = 40
x = 5
y = 50
text = ""

def quoteString(string):
    escape_list = ["\\","{","}",'"']
    for e in escape_list:
        string = string.replace(e,"\\"+e) 
    string = string.replace("\n", "").replace(",", ";")
    return string

def make_box():
    return """
#rectangle {
#   object {
#	x=%(xx)d
#	y=%(y)d 
#        width=475
#	height=%(boxh)d
#	}
#	"basic attribute" {
#		clr=14
#		fill="outline"
#	}
#}
text {
   object {
	x=%(x)d
	y=%(laby)d
	width=150 
	height=15
	}
	"basic attribute" {
		clr=14
	}
	textix="%(name)s "
	align="horiz. right"
}
""" % globals()

def make_description():
    return """    
#
#object {
#	x=%(nx)d
#	y=%(y)d
#	width=10
#	height=15
#	}
#	"basic attribute" {
#		clr=14
#		fill="outline"
#	}
#}
#    
""" % globals()

def make_label():
    return """
text {
     object {
	    x=%(nx)d
	    y=%(y)d
	    width=100
	    height=15
	    }
	"basic attribute" {
		clr=14
	}
	textix="%(nodeName)s"
	align="horiz. right"
}    
""" % globals()             

def make_ro():
    return """
"text update" {
     object {
	    x=%(nx)d
	    y=%(y)d
	    width=125
	    height=15
	    }
	monitor {
	chan="$(P)$(R)%(recordName)s_RBV"   
	clr=54
	bclr=4
	}
	limits {
	}
	align="horiz. center"
}     
""" % globals()         

def make_demand():
    return """
"text entry" {
     object {
	    x=%(nx)d
	    y=%(y)d
	    width=60
	    height=15
	    }
	control {
	chan="$(P)$(R)%(recordName)s"   
	clr=14
	bclr=51
	}
	limits {
	}
}     
""" % globals()

def make_rbv():
    return """
"text update" {
     object {
	    x=%(nx)d
	    y=%(y)d
	    width=70
	    height=15
	    }
	monitor {
		chan="$(P)$(R)%(recordName)s_RBV"   
		clr=54
		bclr=4
		}
	limits {
	}
}     
""" % globals() 

def make_menu():
    return """
menu {
	object {
	    x=%(nx)d
	    y=%(y)d
	    width=125
	    height=15
	    }
	control {
		chan="$(P)$(R)%(recordName)s"
		clr=14
		bclr=51
	}
}    
 """ % globals()

def make_cmd():
    return """
"message button" {
     object {
	    x=%(nx)d
	    y=%(y)d
	    width=125
	    height=15
	    }
	control {
		chan="$(P)$(R)%(recordName)s.PROC"   
		clr=14
		bclr=51
		}
	label="%(nodeName)s"
	press_msg="1"
	release_msg=""
	clrmod="discrete"
}    
""" % globals()

# Write each section

###
### new header
###

for name, nodes in structure:

    w = 260
    w = 400
    h = 40
    xx = 5
    x = 160
    y = 50
    
    text = ""
    mytext = ""
    # write box
    boxh = len(nodes) * 25 + 5
#    if (boxh + y > 850):
#        y = 50
#        w += 260
#        x += 260  
    laby = y - 10  
    laby = y - 40    
    text += make_box()
    if mytext == "":
       mytext = name

    y += 5
    h = max(y, h)    
    for node in nodes:
        nodeName = str(node.getAttribute("Name"))
        recordName = records[nodeName]

        ro = False
        desc = ""
	if recordName in list:
	   recordName = recordName + '+'+ mask_name[0]
        for n in elements(node):
            if str(n.nodeName) == "AccessMode" and getText(n) == "RO":
                ro = True
            if str(n.nodeName) in ["ToolTip", "Description"]:
                desc = getText(n)
        descs = ["%s: "% nodeName, "", "", "", "", ""]
        i = 0
        for word in desc.split():
            if len(descs[i]) + len(word) > 80:
                i += 1
                if i >= len(descs):
                    break
            descs[i] += word + " "
        for i in range(6):
            if descs[i]:
                globals()["desc%d" % i] = quoteString(descs[i])
            else:
                globals()["desc%d" % i] = "''"
#        nx = x + 5
#        text += make_description()   

#        nx = x + 10
        nx = x

        text += make_label()
      
        nx += 110 
#        nx += 120           
        if node.nodeName in ["StringReg","String"] or ro:
            text += make_ro()
        elif node.nodeName in ["Integer", "Float", "Converter", "IntConverter", "IntSwissKnife", "SwissKnife","IntReg","FloatReg"]:  
            text += make_demand()
            nx += 65 
            text += make_rbv() 
        elif node.nodeName in ["Enumeration", "Boolean"]:
            text += make_menu()
        elif node.nodeName in ["Command"]:
            text += make_cmd()
        else:
            print "Don't know what to do with", node.nodeName
        y += 25

###
### New Footer
###
##        y += 15
        h = max(y, h)    

# tidy up
        w += 5

        exitX = w - 100
        exitY = h - min(30, h - y)
        h = exitY + 30
        hh = h - 60
        ww = w - 10
        filename = "".join([adl_filename, mytext, ".adl"])
        edl_file = open(filename, "w")

        edl_file.write("""
file {
	name="prototype.adl"
	version=030107
}
display {
	object {
		x=50
		y=50
		width=%(w)d
		height=%(h)d
	}
	clr=14
	bclr=4
	cmap=""
	gridSpacing=5
	gridOn=0
	snapToGrid=0
}
"color map" {
	ncolors=65
	colors {
                ffffff,
		ececec,
		dadada,
		c8c8c8,
		bbbbbb,
		aeaeae,
		9e9e9e,
		919191,
		858585,
		787878,
		696969,
		5a5a5a,
		464646,
		2d2d2d,
		000000,
		00d800,
		1ebb00,
		339900,
		2d7f00,
		216c00,
		fd0000,
		de1309,
		be190b,
		a01207,
		820400,
		5893ff,
		597ee1,
		4b6ec7,
		3a5eab,
		27548d,
		fbf34a,
		f9da3c,
		eeb62b,
		e19015,
		cd6100,
		ffb0ff,
		d67fe2,
		ae4ebc,
		8b1a96,
		610a75,
		a4aaff,
		8793e2,
		6a73c1,
		4d52a4,
		343386,
		c7bb6d,
		b79d5c,
		a47e3c,
		7d5627,
		58340f,
		99ffff,
		73dfff,
		4ea5f9,
		2a63e4,
		0a00b8,
		ebf1b5,
		d4db9d,
		bbc187,
		a6a462,
		8b8239,
		73ff6b,
		52da3b,
		3cb420,
		289315,
		1a7309,	}
}
rectangle {
   object {
	x=5
	y=5
	width=%(ww)d
	height=30
	}
	"basic attribute" {
		clr=14
		fill="outline"
	}
}
rectangle {
   object {
	x=5
	y=50
	width=%(ww)d
	height=%(hh)d
	}
	"basic attribute" {
		clr=14
		fill="outline"
	}
}


        """ %globals())
        edl_file.write(text)
        edl_file.write("""
        """ % globals())
        edl_file.close()
    

