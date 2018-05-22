#include <epicsEvent.h>
#include "ADDriver.h"
#include <EGrabber.h>
//#include <RGBConverter.h>
#include <FormatConverter.h>

//using namespace Euresys;
typedef Euresys::EGrabberCallbackOnDemand MyGrabber;

class epicsShareClass coaxLink : public ADDriver {
public:
    coaxLink(const char *portName, int maxSizeX, int maxSizeY, NDDataType_t dataType,
                int maxBuffers, size_t maxMemory,
                int priority, int stackSize);

    /* These are the methods that we override from ADDriver */
    virtual asynStatus writeInt32(asynUser *pasynUser, epicsInt32 value);
    virtual asynStatus writeFloat64(asynUser *pasynUser, epicsFloat64 value);
    virtual void report(FILE *fp, int details);
    void simTask(); /**< Should be private, but gets called from C, so must be public */
	void coaxlinkHandleReadOnlyParamsTask();

protected:

#include "Euresys_Coaxlink_TLSystem_9_5_2_1.inc"
#include "Euresys_Coaxlink_TLInterface_9_5_2_1.inc"
#include "Euresys_Coaxlink_TLDevice_9_5_2_1.inc"
#include "Adimec_Q12A180CXP_1_1_5_1.inc"
#include "Euresys_Coaxlink_TLDataStream_9_5_2_1.inc"
#include "Decode_Errors_1.inc"


#define FIRST_SYSTEM_PARAM COAXLINK_System_TLVendorName
#define LAST_SYSTEM_PARAM COAXLINK_System_InterfaceID

#define FIRST_INTERFACE_PARAM COAXLINK_Interface_InterfaceID
#define LAST_INTERFACE_PARAM COAXLINK_Interface_EncryptedOemSafetyKey

#define FIRST_DEVICE_PARAM COAXLINK_Device_DeviceID
#define LAST_DEVICE_PARAM COAXLINK_Device_ErrorCountReset

#define FIRST_CAMERA_PARAM COAXLINK_Remote_Standard
#define LAST_CAMERA_PARAM COAXLINK_Remote_UserSetSave

#define FIRST_STREAM_PARAM COAXLINK_Stream_StreamID
#define LAST_STREAM_PARAM COAXLINK_Stream_EventCountReset

#define FIRST_ERROR_PARAM COAXLINK_D_All
#define LAST_ERROR_PARAM COAXLINK_D_Unknown


#define FIRST_COAXLINK_PARAM COAXLINK_System_TLVendorName
//#define LAST_COAXLINK_PARAM COAXLINK_Stream_EventCountReset
#define LAST_COAXLINK_PARAM COAXLINK_D_Unknown


private:
    /* These are the methods that are new to this class */

    /* Our data */
    epicsEventId startEventId;
    epicsEventId stopEventId;
	NDArray	*pImage;
	static const uint32_t CARD_IX = 0;
	static const uint32_t DEVICE_IX = 0;
	static const uint32_t STREAM_IX = 0;
	bool readonlyThreadKeepAlive;	
//	Euresys::GenTL genTL;
	Euresys::EGenTL mygenTL;

	MyGrabber grabber;
	Euresys::Buffer *currentBuffer;
};

#include "Euresys_Coaxlink_TLSystem_9_5_2_2.inc"
#include "Euresys_Coaxlink_TLInterface_9_5_2_2.inc"
#include "Euresys_Coaxlink_TLDevice_9_5_2_2.inc"
#include "Adimec_Q12A180CXP_1_1_5_2.inc"
#include "Euresys_Coaxlink_TLDataStream_9_5_2_2.inc"
#include "Decode_Errors_2.inc"

#define NUM_COAXLINK_PARAMS ((int)(&LAST_COAXLINK_PARAM - &FIRST_COAXLINK_PARAM + 1))

