# Must have loaded envPaths via st.cmd.linux or st.cmd.win32

errlogInit(20000)

dbLoadDatabase("$(TOP)/dbd/coaxLinkApp.dbd")
coaxLinkApp_registerRecordDeviceDriver(pdbbase) 

#required for Linux to locate 'libs'
epicsEnvSet("EURESYS_COAXLINK_GENTL64_CTI","/opt/euresys/coaxlink/lib/x86_64/coaxlink.cti")

# Prefix for all records
epicsEnvSet("PREFIX", "13SIM1:")
# The port name for the detector
epicsEnvSet("PORT",   "SIM1")
# The queue size for all plugins
epicsEnvSet("QSIZE",  "50")
# The maximim image width; used for row profiles in the NDPluginStats plugin
epicsEnvSet("XSIZE",  "4096")
# The maximim image height; used for column profiles in the NDPluginStats plugin
epicsEnvSet("YSIZE",  "3072")
# The maximum number of time series points in the NDPluginStats plugin
epicsEnvSet("NCHANS", "2048")
# The maximum number of frames buffered in the NDPluginCircularBuff plugin
epicsEnvSet("CBUFFS", "20")
# The search path for database files
epicsEnvSet("EPICS_DB_INCLUDE_PATH", "$(ADCORE)/db")

# only has meaning under Windows
asynSetMinTimerPeriod(0.0001)

# The EPICS environment variable EPICS_CA_MAX_ARRAY_BYTES needs to be set to a value at least as large
# as the largest image that the standard arrays plugin will send.
# That vlaue is $(XSIZE) * $(YSIZE) * sizeof(FTVL data type) for the FTVL used when loading the NDStdArrays.template file.
# The variable can be set in the environment before running the IOC or it can be set here.
# It is often convenient to set it in the environment outside the IOC to the largest array any client 
# or server will need.  For example 10000000 (ten million) bytes may be enough.
# If it is set here then remember to also set it outside the IOC for any CA clients that need to access the waveform record.  
# Do not set EPICS_CA_MAX_ARRAY_BYTES to a value much larger than that required, because EPICS Channel Access actually
# allocates arrays of this size every time it needs a buffer larger than 16K.
# Uncomment the following line to set it in the IOC.

# note: this values works for 8-bit , 10-bit requires 16-bits worth of space
epicsEnvSet("EPICS_CA_MAX_ARRAY_BYTES", "25165824")

# Create a simDetector driver
# simDetectorConfig(const char *portName, int maxSizeX, int maxSizeY, int dataType,
#                   int maxBuffers, int maxMemory, int priority, int stackSize)
coaxLinkConfig("$(PORT)", $(XSIZE), $(YSIZE), 3, 0, 0)

dbLoadRecords("$(ADCOAXLINK)/db/coaxLink.template","P=$(PREFIX),R=cam1:,PORT=$(PORT),ADDR=0,TIMEOUT=1")

#kennan Raw binary file plugin, built in ADCore on my system, fastest way to dump data

#NDFileRawConfigure("Raw1", 20, 0, "$(PORT)", 0, 0, 0)
#dbLoadRecords("$(ADCORE)/ADApp/Db/NDFileRaw.template", "P=$(PREFIX), R=raw1:, PORT=$(PORT), ADDR=0, TIMEOUT=1, NDARRAY_PORT=$(PORT), NDARRAY_ADDR=0") 

# Load an NDFile database.  This is not supported for the simDetector which does not write files.
dbLoadRecords("NDFile.template","P=$(PREFIX),R=cam1:,PORT=SIM1,ADDR=0,TIMEOUT=1")

# Create a standard arrays plugin, set it to get data from first simDetector driver.
NDStdArraysConfigure("Image1", 10, 0, "$(PORT)", 0)

# This creates a waveform large enough for 4096 by 3072 by 2 (e.g. BW) arrays.
# This waveform only allows transporting 8-bit images

dbLoadRecords("NDStdArrays.template", "P=$(PREFIX),R=image1:,PORT=Image1,ADDR=0,TIMEOUT=1,NDARRAY_PORT=$(PORT),TYPE=Int8,FTVL=UCHAR,NELEMENTS=25165824")

# This waveform only allows transporting 16-bit images
#dbLoadRecords("NDStdArrays.template", "P=$(PREFIX),R=image1:,PORT=Image1,ADDR=0,TIMEOUT=1,NDARRAY_PORT=$(PORT),TYPE=Int16,FTVL=USHORT,NELEMENTS=25165824")
# This waveform allows transporting 32-bit images
#dbLoadRecords("NDStdArrays.template", "P=$(PREFIX),R=image1:,PORT=Image1,ADDR=0,TIMEOUT=1,NDARRAY_PORT=$(PORT),TYPE=Int32,FTVL=LONG,NELEMENTS=25165824")

# Load all other plugins using commonPlugins.cmd
< $(ADCORE)/iocBoot/commonPlugins.cmd

set_requestfile_path("$(ADCOAXLINK)/coaxLinkApp/Db")

#asynSetTraceIOMask("$(PORT)",0,2)
#asynSetTraceMask("$(PORT)",0,255)
#asynSetTraceIOMask("FileNetCDF",0,2)
#asynSetTraceMask("FileNetCDF",0,255)
#asynSetTraceMask("FileNexus",0,255)
#asynSetTraceMask("SIM2",0,255)

### Load alive record
dbLoadRecords("$(ALIVE)/aliveApp/Db/alive.db", "P=$(PREFIX),RHOST=164.54.100.11")

iocInit()

# generate list of all loaded PV's
dbl > pvs.txt

# save things every thirty seconds
create_monitor_set("auto_settings.req", 30, "P=$(PREFIX)")
