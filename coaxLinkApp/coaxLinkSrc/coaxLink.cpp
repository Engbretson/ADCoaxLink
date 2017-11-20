/* coaxLink.cpp
 *
 * This is a driver for a simulated area detector.
 *
 * Author: Mark Rivers
 *         University of Chicago
 *
 * Created:  March 20, 2008
 *
 */
#include <iostream>

#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <epicsTime.h>
#include <epicsThread.h>
#include <epicsEvent.h>
#include <epicsMutex.h>
#include <epicsString.h>
#include <epicsStdio.h>
#include <epicsMutex.h>
#include <cantProceed.h>
#include <iocsh.h>

#include "ADDriver.h"
#include <epicsExport.h>

#include "coaxLink.h"
#include <EGrabber.h>
#include <RGBConverter.h>
#include "EuresysImage.h"


static const char *driverName = "coaxLink";


static void simTaskC(void *drvPvt)
{
	//	printf("simTaskC hit \n");
	coaxLink *pPvt = (coaxLink *)drvPvt;
	pPvt->simTask();
}

static void coaxlinkHandleReadOnlyParamsTaskC(void *drvPvt)
{
	//	printf("handle readonly values hit \n");
	coaxLink *pPvt = (coaxLink *)drvPvt;
	pPvt->coaxlinkHandleReadOnlyParamsTask();
}


void coaxLink::coaxlinkHandleReadOnlyParamsTask(void){
	double delayTimeout = 5.0;
	std::string systemString;
	int64_t systemInteger;
	double systemDouble;
	int status;

	while (true) {
		epicsThreadSleep(delayTimeout);
		if (!readonlyThreadKeepAlive){
			/*			asynPrint(pasynUserSelf, ASYN_TRACE_FLOW,
							"%s:%s Read Only handling thread has been terminated.\n",
							driverName,
							__func__);
							*/
			return;
		}

#include "Euresys_Coaxlink_TLSystem_6_2_4_4.inc"
		callParamCallbacks();
//#include "Euresys_Coaxlink_TLInterface_6_2_4_4.inc"
		callParamCallbacks();
#include "Euresys_Coaxlink_TLDevice_6_2_4_4.inc"
		callParamCallbacks();
#include "Adimec_Q12A180CXP_1_1_3_4.inc"
		callParamCallbacks();
		//#include "Euresys_Coaxlink_TLDataStream_6_2_4_4.inc"
	//callParamCallbacks();

#include "Decode_Errors_4.inc"
		callParamCallbacks();
	}
}

/** This thread calls computeImage to compute new image data and does the callbacks to send it to higher layers.
  * It implements the logic for single, multiple or continuous acquisition. */


// #ifdef KNOWNTOBEWORKING
void coaxLink::simTask()
{
	NDDataType_t dataType;
	int arrayCallbacks = 1;
	int imageCounter = 0;
	size_t dims[2];
	uint32_t size;

	int astatus = asynSuccess;
	int acquire;
	int iMode, numImages, numImagesCounter;
	const char *functionName = "CoaXLinkTask";
	dims[0] = 0;
	dims[1] = 0;

	this->lock();
	// Loop forever
	while (1) {
		// Is acquisition active?
		getIntegerParam(ADAcquire, &acquire);
		callParamCallbacks();
		// If we are not acquiring then wait for a semaphore that is given when acquisition is started
		if (!acquire)  {
			// Release the lock while we wait for an event that says acquire has started, then lock again
			asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW,
				"%s:%s: waiting for acquire to start\n", driverName, functionName);
			setIntegerParam(ADNumImagesCounter, 0);
			callParamCallbacks();
			this->unlock();
			astatus = epicsEventWait(this->startEventId);
			this->lock();
		}

//		printf("Starting Acquire \n");

		// start acq
		getIntegerParam(ADImageMode, &iMode);
		getIntegerParam(ADNumImages, &numImages);
		getIntegerParam(ADNumImagesCounter, &numImagesCounter);
		callParamCallbacks();

		// I need some frame memory buffers, which are both size and speed dependent


		printf("right before buffers \n");
		try {
			grabber.reallocBuffers(4);
		}
		catch (const std::exception &e) { printf("Issues allocating a buffer\n"); }



		if (iMode == ADImageSingle)
			// Starts a single transfer
			//			grabber.start(1);
	
			grabber.start(1);

		else if (iMode == ADImageMultiple)
			// Starts a multiple transfer
			grabber.start((uint32_t)numImages);
		else
			// Starts a continuous transfer (live grab)
			grabber.start();

		// Wait using epicsEventWaitWithTimeout, so we can abort.

		////
#ifdef BIG_COMMENT
		Ok, what is requested is that by this point, we have preallocated as much memory as we can so then when the buffer comes back to use a filled,
			we just copy the contents and the timestamp to memory and repeat until the number of images has expired.
			Then we hit the following code using our cached memory values, not fresh values from the camera.
			we do this from the image count which, I guess, is validated from available memory

#endif
			////

			while (1) {

				this->unlock();
				
////				Euresys::ScopedBuffer buf1(grabber, 5000); // 5 second timeout to recover from a jammed camera
				Euresys::ScopedBuffer buf1(grabber);

				this->lock();

				getIntegerParam(NDDataType, (int *)&dataType);
				getIntegerParam(NDArrayCallbacks, &arrayCallbacks);

				// playing with empty databuffers seem to have little real life use
						if (arrayCallbacks) {
				getIntegerParam(ADMaxSizeX, (int *)&dims[0]);
				getIntegerParam(ADMaxSizeY, (int *)&dims[1]);

				}

////				dataType = NDUInt8;

				switch (dataType) {
				case 0:
				case 1:
					size = dims[0] * dims[1] * sizeof(uint8_t);
					break;
				case 2:
				case 3:
					size = dims[0] * dims[1] * sizeof(uint16_t); // although really it is only 10 bits 
					break;
				default:
//					printf("error setting image buffer size\n");
					asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
						"%s:%s: error setting image buffer size\n",
						driverName, functionName);
				}

//							printf("arrayCallbacks %d \n", arrayCallbacks);
//							printf("dataType %d \n", dataType);
//							printf("dims 0 X %d \n", dims[0]);
//							printf("dims 1 y %d \n", dims[1]);
//							printf("size %d \n", size);

				//			dataType = NDUInt16;
				//			dims[0] = 4096;
				//			dims[1] = 3072;
				//			arrayCallbacks = 1;

							this->pImage = this->pNDArrayPool->alloc(2, dims, dataType, 0, NULL);				
//							this->pImage = this->pNDArrayPool->alloc(2, dims, dataType, 2, NULL);


				if (!this->pImage) {
					asynPrint(this->pasynUserSelf, ASYN_TRACE_ERROR,
						"%s:%s: error allocating image buffer\n",
						driverName, functionName);
					break;

				}

				
					// data and ts
					uint64_t size1 = buf1.getInfo<uint64_t>(GenICam::Client::BUFFER_INFO_SIZE);
//					printf("Image Buffer size %d \n", size1);
					uint64_t ts1 = buf1.getInfo<uint64_t>(GenICam::Client::BUFFER_INFO_TIMESTAMP);
					void *ptr1 = buf1.getInfo<void *>(GenICam::Client::BUFFER_INFO_BASE);


					////				uint64_t ts2 = buf2.getInfo<uint64_t>(GenICam::Client::BUFFER_INFO_TIMESTAMP);
					////				void *ptr2 = buf2.getInfo<void *>(GenICam::Client::BUFFER_INFO_BASE);

					// Put the frame number and time stamp into the buffer
					// Set the the start time

					pImage->uniqueId = imageCounter;
					pImage->timeStamp = ts1;

//					printf("Before Copy1 \n");
					memcpy(pImage->pData, ptr1, size);


					//				pImage->dataType
					////				printf("Before Copy2 \n");
					//				memcpy(&pImage->pData+size, ptr2, size);
					//				memcpy((void *)pImage->pData + size, ptr2, size);

//					printf("After Copy \n");

					// Get any attributes that have been defined for this driver        
					this->getAttributes(pImage->pAttributeList);

					// Call the NDArray callback
					asynPrint(this->pasynUserSelf, ASYN_TRACE_FLOW,
						"%s:%s: calling NDArray callback\n", driverName, functionName);

					this->unlock();
					doCallbacksGenericPointer(pImage, NDArrayData, 0);
					this->lock();


			
					getIntegerParam(ADNumImagesCounter, &numImagesCounter);
					numImagesCounter++;
					////				numImagesCounter++;
					setIntegerParam(ADNumImagesCounter, numImagesCounter);
					callParamCallbacks();

				pImage->release();

				this->unlock();
				astatus = epicsEventWaitWithTimeout(this->stopEventId, 0.0);
				this->lock();

				if (astatus == epicsEventWaitOK) break;
				if ((numImagesCounter >= numImages) && (iMode == ADImageMultiple)) break;
				if ((numImagesCounter >= 1) && (iMode == ADImageSingle)) break;
			}

		// finish acq
		setIntegerParam(ADAcquire, 0);
		callParamCallbacks();
		grabber.stop();

	}
}


// #endif


asynStatus coaxLink::writeInt32(asynUser *pasynUser, epicsInt32 value)
{
	static const char *functionName = "writeInt32";
	int function = pasynUser->reason;
	asynStatus status = asynSuccess;
	char *whoami;
	int CoaxInterface = 0;

	getParamName(function, (const char **)&whoami);

	asynPrint(pasynUserSelf, ASYN_TRACE_ERROR, "%s:%s: Debug %d (%s) %d\n", driverName,
		functionName, function, whoami, value);

	if ((function >= FIRST_SYSTEM_PARAM)    & (function <= LAST_SYSTEM_PARAM))    { 
		//printf("System Level Command \n"); 
		CoaxInterface = 1; }
	if ((function >= FIRST_INTERFACE_PARAM) & (function <= LAST_INTERFACE_PARAM)) { 
		//printf("Interface Level Command \n");
		CoaxInterface = 2; }
	if ((function >= FIRST_DEVICE_PARAM)    & (function <= LAST_DEVICE_PARAM))    { 
		//printf("Device Level Command \n");
		CoaxInterface = 3; }
	if ((function >= FIRST_CAMERA_PARAM)    & (function <= LAST_CAMERA_PARAM))    { 
		//printf("Camera Level Command \n");
		CoaxInterface = 4; }
	if ((function >= FIRST_STREAM_PARAM)    & (function <= LAST_STREAM_PARAM))    { 
		//printf("Stream Level Command \n");
		CoaxInterface = 5; }

	// Trims duplicate interface string commands back down to the actual string as required

	int length = strlen(whoami);
	if (whoami[length - 2] == '+') whoami[length - 2] = 0;

	// Coaxlink Special Cases, Commands that are known to execute and not actually setInteger

	if (
		(function == COAXLINK_Device_DeviceReset) |
		(function == COAXLINK_Device_StartCycle) |
		(function == COAXLINK_Device_CycleLostTriggerCountReset) |
		(function == COAXLINK_Device_StartSequence) |
		(function == COAXLINK_Device_AbortSequence) |
		(function == COAXLINK_Device_CxpPacketArbiterReset) |
		(function == COAXLINK_Device_EventCountReset) |
		(function == COAXLINK_Device_ErrorCountReset)
		) CoaxInterface = 13;

	if (
		(function == COAXLINK_Remote_AcquisitionStart) |
		(function == COAXLINK_Remote_AcquisitionStop) |
		(function == COAXLINK_Remote_AcquisitionMaxFrameRate) |
		(function == COAXLINK_Remote_WhiteBalanceCalibrate)
		) CoaxInterface = 14;


	try {
		switch (CoaxInterface)
		{
		case 1:
			grabber.setInteger<Euresys::SystemModule>(whoami, value);
			break;
		case 2:
			grabber.setInteger<Euresys::InterfaceModule>(whoami, value);
			break;
		case 3:
			grabber.setInteger<Euresys::DeviceModule>(whoami, value);
			break;
		case 4:
			grabber.setInteger<Euresys::RemoteModule>(whoami, value);
			break;
		case 5:
			grabber.setInteger<Euresys::StreamModule>(whoami, value);
			break;
		case 13:
			grabber.execute<Euresys::DeviceModule>(whoami);
			break;
		case 14:
			grabber.execute<Euresys::RemoteModule>(whoami);
			break;
		}

		status = setIntegerParam(function, value);
	}
	catch (const std::exception &e) { asynPrint(pasynUserSelf, ASYN_TRACE_ERROR, "Error setting %s %d (%s) to %d \n", functionName, function, whoami, value); }

	// commands that have to be sent down into Area Detector via a different name/meaning

	if (function == COAXLINK_Remote_Width) {
		setIntegerParam(ADSizeX, value); 
		setIntegerParam(ADMaxSizeX, value);
		setIntegerParam(NDArraySizeX, value);

		}

	if (function == COAXLINK_Remote_Height) {
		setIntegerParam(ADSizeY, value);
		setIntegerParam(ADMaxSizeY, value);
		setIntegerParam(NDArraySizeY, value);

	}

	if (function == COAXLINK_Remote_OffsetX) setIntegerParam(ADMinX, value); // ???
	if (function == COAXLINK_Remote_OffsetY) setIntegerParam(ADMinY, value); // ???

	if (function == COAXLINK_Remote_SensorBitDepth)
		if (value == 0) {
			setIntegerParam(NDDataType, 1);
			printf("corrected to 1\n");
		}
		else {
			setIntegerParam(NDDataType, 3);
			printf("corrected to 3\n");
		}
	status = setIntegerParam(function, value);
	callParamCallbacks();

	if ((function == ADAcquire) & (value == 1)) epicsEventSignal(this->startEventId);
	if ((function == ADAcquire) & (value == 0)) epicsEventSignal(this->stopEventId);

	if (function < FIRST_COAXLINK_PARAM) {
		status = ADDriver::writeInt32(pasynUser, value);
	}


	return (asynStatus)status;
}

asynStatus coaxLink::writeFloat64(asynUser *pasynUser, epicsFloat64 value)
{
	static const char *functionName = "writeFloat64";
	int function = pasynUser->reason;
	asynStatus status = asynSuccess;
	char *whoami;
	int CoaxInterface = 0;

	getParamName(function, (const char **)&whoami);

	asynPrint(pasynUserSelf, ASYN_TRACE_FLOW, "%s:%s: Debug %d (%s) %d\n", driverName,
		functionName, function, whoami, value);

	if ((function >= FIRST_SYSTEM_PARAM)    & (function <= LAST_SYSTEM_PARAM))    { 
		//printf("System Level Command \n");    
		CoaxInterface = 1; }
	if ((function >= FIRST_INTERFACE_PARAM) & (function <= LAST_INTERFACE_PARAM)) { 
		//printf("Interface Level Command \n"); 
		CoaxInterface = 2; }
	if ((function >= FIRST_DEVICE_PARAM)    & (function <= LAST_DEVICE_PARAM))    { 
		//printf("Device Level Command \n");    
		CoaxInterface = 3; }
	if ((function >= FIRST_CAMERA_PARAM)    & (function <= LAST_CAMERA_PARAM))    { 
		//printf("Camera Level Command \n");    
		CoaxInterface = 4; }
	if ((function >= FIRST_STREAM_PARAM)    & (function <= LAST_STREAM_PARAM))    { 
		//printf("Stream Level Command \n");    
		CoaxInterface = 5; }

	// Trims duplicate interface string commands back down to the actual string

	int length = strlen(whoami);
	if (whoami[length - 2] == '+') whoami[length - 2] = 0;

	try {
		switch (CoaxInterface)
		{
		case 1:
			grabber.setFloat<Euresys::SystemModule>(whoami, value);
			break;
		case 2:
			grabber.setFloat<Euresys::InterfaceModule>(whoami, value);
			break;
		case 3:
			grabber.setFloat<Euresys::DeviceModule>(whoami, value);
			break;
		case 4:
			grabber.setFloat<Euresys::RemoteModule>(whoami, value);
			break;
		case 5:
			grabber.setFloat<Euresys::StreamModule>(whoami, value);
			break;

		}

		status = setDoubleParam(function, value);
	}
	catch (const std::exception &e) { asynPrint(pasynUserSelf, ASYN_TRACE_ERROR, "Error setting %s %d (%s) to %f \n", functionName, function, whoami, value); }

	
	status = setDoubleParam(function, value);
	callParamCallbacks();

	if (function < FIRST_COAXLINK_PARAM) {
		status = ADDriver::writeFloat64(pasynUser, value);
	}

	callParamCallbacks();

	return (asynStatus)status;
}

/** Report status of the driver.
  * Prints details about the driver if details>0.
  * It then calls the ADDriver::report() method.
  * \param[in] fp File pointed passed by caller where the output is written to.
  * \param[in] details If >0 then driver details are printed.
  */
void coaxLink::report(FILE *fp, int details)
{

	fprintf(fp, "CoaxLink detector %s\n", this->portName);
	if (details > 0) {
	}
	/* Invoke the base class method */
	ADDriver::report(fp, details);
}

/** Constructor for coaxLink; most parameters are simply passed to ADDriver::ADDriver.
  * After calling the base class constructor this method creates a thread to compute the simulated detector data,
  * and sets reasonable default values for parameters defined in this class, asynNDArrayDriver and ADDriver.
  * \param[in] portName The name of the asyn port driver to be created.
  * \param[in] maxSizeX The maximum X dimension of the images that this driver can create.
  * \param[in] maxSizeY The maximum Y dimension of the images that this driver can create.
  * \param[in] dataType The initial data type (NDDataType_t) of the images that this driver will create.
  * \param[in] maxBuffers The maximum number of NDArray buffers that the NDArrayPool for this driver is
  *            allowed to allocate. Set this to -1 to allow an unlimited number of buffers.
  * \param[in] maxMemory The maximum amount of memory that the NDArrayPool for this driver is
  *            allowed to allocate. Set this to -1 to allow an unlimited amount of memory.
  * \param[in] priority The thread priority for the asyn port driver thread if ASYN_CANBLOCK is set in asynFlags.
  * \param[in] stackSize The stack size for the asyn port driver thread if ASYN_CANBLOCK is set in asynFlags.
  */
coaxLink::coaxLink(const char *portName, int maxSizeX, int maxSizeY, NDDataType_t dataType,
	int maxBuffers, size_t maxMemory, int priority, int stackSize)
	: grabber(genTL, CARD_IX, DEVICE_IX, STREAM_IX),
	ADDriver(portName, 1, NUM_COAXLINK_PARAMS, maxBuffers, maxMemory,
	0, 0, /* No interfaces beyond those set in ADDriver.cpp */
	0, 1, /* ASYN_CANBLOCK=0, ASYN_MULTIDEVICE=0, autoConnect=1 */
	priority, stackSize),
	pImage(NULL)

{
	int64_t status = asynSuccess;
	const char *functionName = "coaxLink";

	this->startEventId = epicsEventCreate(epicsEventEmpty);
	if (!this->startEventId) {
		printf("%s:%s epicsEventCreate failure for start event\n",
			driverName, functionName);
		return;
	}

	this->stopEventId = epicsEventCreate(epicsEventEmpty);
	if (!this->stopEventId) {
		printf("%s:%s epicsEventCreate failure for stop event\n",
			driverName, functionName);
		return;
	}

	// all the create Param code

#include "Euresys_Coaxlink_TLSystem_6_2_4_3.inc"
//#include "Euresys_Coaxlink_TLInterface_6_2_4_3.inc"
#include "Euresys_Coaxlink_TLDevice_6_2_4_3.inc"
#include "Adimec_Q12A180CXP_1_1_3_3.inc"

	//#include "Euresys_Coaxlink_TLDataStream_6_2_4_3.inc"

 #include "Decode_Errors_3.inc"


	std::string systemString;
	int64_t systemInteger;
	double systemDouble;

	/*
	Initialization, if required. Note: I am attempting to read a value from everything that was setup, however, many of these parameters are EXECUTE, WRITE ONLY, or have no valid value
	at the current instant since they depend upon other paramters being set first. Also have the issue with the command being the same on many interfaces. Currently this means that I special
	cased them by adding a "_X" string that needs to be popped off at runtime.
	*/


#include "Euresys_Coaxlink_TLSystem_6_2_4_4.inc"
	callParamCallbacks();
//#include "Euresys_Coaxlink_TLInterface_6_2_4_4.inc"
	callParamCallbacks();
#include "Euresys_Coaxlink_TLDevice_6_2_4_4.inc"
	callParamCallbacks();
#include "Adimec_Q12A180CXP_1_1_3_4.inc"
	callParamCallbacks();
	//#include "Euresys_Coaxlink_TLDataStream_6_2_4_4.inc"

	callParamCallbacks();

	try {
		grabber.execute<Euresys::DeviceModule>("DeviceReset");
		grabber.stop();
	}
	catch (const std::exception &e) { printf("The Frame Grabber is in use by another application\n"); exit(0); }

	
	status =  setStringParam (ADManufacturer, "Adimec");
	status |= setStringParam (ADModel, "Q-12A180-Fm/CXP-6");
	status |= setIntegerParam(ADMaxSizeX, 4096);
	status |= setIntegerParam(ADMaxSizeY, 3072);
	status |= setIntegerParam(ADMinX, 0);
	status |= setIntegerParam(ADMinY, 0);
	status |= setIntegerParam(ADBinX, 1);
	status |= setIntegerParam(ADBinY, 1);
	status |= setIntegerParam(ADReverseX, 0);
	status |= setIntegerParam(ADReverseY, 0);
	status |= setIntegerParam(ADSizeX, 4096);
	status |= setIntegerParam(ADSizeY, 3072);
	status |= setIntegerParam(NDArraySizeX, 4096);
	status |= setIntegerParam(NDArraySizeY, 3072);
	status |= setIntegerParam(NDArraySize, 0);
	status |= setIntegerParam(NDDataType, NDUInt8);
	status |= setIntegerParam(ADImageMode, ADImageContinuous);
	status |= setDoubleParam (ADAcquireTime, .001);
	status |= setDoubleParam (ADAcquirePeriod, .005);
	status |= setIntegerParam(ADNumImages, 100);
	

	if (status) {
		printf("%s: unable to set camera parameters\n", functionName);
		return;
	}

	/* Create the thread to update read only parameters */
	status = (epicsThreadCreate("coaxlinkHandleReadOnlyParamsTaskC",
		epicsThreadPriorityLow,
		epicsThreadGetStackSize(epicsThreadStackMedium),
		(EPICSTHREADFUNC)coaxlinkHandleReadOnlyParamsTaskC,
		this) == NULL);

	readonlyThreadKeepAlive = true;


	/* Create the thread that updates the images */
	status = (epicsThreadCreate("SimDetTask",
		epicsThreadPriorityLow,
		epicsThreadGetStackSize(epicsThreadStackBig),
		(EPICSTHREADFUNC)simTaskC,
		this) == NULL);

	if (status) {
		printf("%s:%s epicsThreadCreate failure for image task\n",
			driverName, functionName);
		return;
	}
}


/** Configuration command, called directly or from iocsh */
extern "C" int coaxLinkConfig(const char *portName, int maxSizeX, int maxSizeY, int dataType,
	int maxBuffers, int maxMemory, int priority, int stackSize)
{
	new coaxLink(portName, maxSizeX, maxSizeY, (NDDataType_t)dataType,
		(maxBuffers < 0) ? 0 : maxBuffers,
		(maxMemory < 0) ? 0 : maxMemory,
		priority, stackSize);
	return(asynSuccess);
}

/** Code for iocsh registration */
static const iocshArg coaxLinkConfigArg0 = { "Port name", iocshArgString };
static const iocshArg coaxLinkConfigArg1 = { "Max X size", iocshArgInt };
static const iocshArg coaxLinkConfigArg2 = { "Max Y size", iocshArgInt };
static const iocshArg coaxLinkConfigArg3 = { "Data type", iocshArgInt };
static const iocshArg coaxLinkConfigArg4 = { "maxBuffers", iocshArgInt };
static const iocshArg coaxLinkConfigArg5 = { "maxMemory", iocshArgInt };
static const iocshArg coaxLinkConfigArg6 = { "priority", iocshArgInt };
static const iocshArg coaxLinkConfigArg7 = { "stackSize", iocshArgInt };
static const iocshArg * const coaxLinkConfigArgs[] = { &coaxLinkConfigArg0,
&coaxLinkConfigArg1,
&coaxLinkConfigArg2,
&coaxLinkConfigArg3,
&coaxLinkConfigArg4,
&coaxLinkConfigArg5,
&coaxLinkConfigArg6,
&coaxLinkConfigArg7 };
static const iocshFuncDef configcoaxLink = { "coaxLinkConfig", 8, coaxLinkConfigArgs };
static void configcoaxLinkCallFunc(const iocshArgBuf *args)
{
	coaxLinkConfig(args[0].sval, args[1].ival, args[2].ival, args[3].ival,
		args[4].ival, args[5].ival, args[6].ival, args[7].ival);
}


static void coaxLinkRegister(void)
{

	iocshRegister(&configcoaxLink, configcoaxLinkCallFunc);
}

extern "C" {
	epicsExportRegistrar(coaxLinkRegister);
}
