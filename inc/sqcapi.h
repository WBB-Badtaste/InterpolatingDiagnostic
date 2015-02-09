/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2014
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: firmware
 *  Subsystem Name: sqc
 *  %full_filespec: sqcapi.h`85:incl:1 %
 */
/**
 *  @file
 *  @brief  Public interface to the SQC subsystem
 */

#ifndef __SQCAPI_H__
#define __SQCAPI_H__

#ifdef NT
#pragma pack(push)
#pragma pack() //use default
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------------------------
 * GLOBAL INCLUDES
 *-----------------------------------------------------------------------*/
#include "n4k_deprecated.h" //lint !e451
#include "nycedefs.h"
#include "nyceversion.h"
#include "sacapi.h"
#include "nhiapi.h"
#include "seqtypes.h"

#include <string.h>
#include <stdlib.h>
#include <math.h>

#ifdef WIN32
#include "nyceapi.h"
#else
/** @cond  */
extern double atandp(double x);
extern double cosdp(double x);
extern double divdp(double x, double y);
extern double expdp(double x);
extern double logdp(double x);
extern double log10dp(double x);
extern double powdp(double x, double y);
extern double sindp(double x);
extern double sqrtdp(double x);
/** @endcond */
#endif

/**
 *  @defgroup sqc Sequence Control  (SQC)
 *
 *  Sequence Control (per node)
 *  The SQC sub-process takes care of sequence control. At firmware level, a sequence consists of a number
 *  of commands in a similar format as the task messages described above. In addition, the sequence command
 *  language contains primitives to send a sequence event to other nodes in order to trigger a sequence on the
 *  other node, to delay and to wait for an event (either generated by a sequence on another node, or one of the
 *  event handlers of the node itself). A repeat command makes it possible to repeat a sequence a limited or
 *  unlimited number of times.
 *
 *  @{
 */

/*-----------------------------------------------------------------------
 * To enable sequence debugging on the host.
 *-----------------------------------------------------------------------*/
#ifdef WIN32

#ifdef SEQ_DBG
#define main SqcMain
#endif

#define SQC_DBG_MAX_SYMBOL_NAME_LENGTH  80

// Datatype
typedef struct seq_dbg_var
{
    char     pcSymbol[SQC_DBG_MAX_SYMBOL_NAME_LENGTH];  // Symbol name
    void*    pData;                                     // Data
    uint32_t typeLen;                                   // Length of the data in bytes
    uint32_t nrOfItems;                                 // Nr of items

} SEQ_DBG_VAR;

extern uint32_t      seqDbgNrVars;
extern SEQ_DBG_VAR*  seqDbgVars;

#endif  // WIN32

#ifdef NYCE_VAR_SET_SIZE
#undef NYCE_VAR_SET_SIZE
#endif
#define NYCE_VAR_SET_SIZE 10 /* redefine variable set size for sequences */


/*-----------------------------------------------------------------------
 * GLOBAL DEFINES
 *-----------------------------------------------------------------------*/

#define SQC_INDEFINITE ((double)-1)     /**< The time-out value that will result in an indefinite suspension */

#define SQC_THIS_NODE   -1
#define SQC_HOST_NODE   -2

#define LED_FRONT_LEFT_RED_ON           0x0001
#define LED_FRONT_LEFT_GREEN_ON         0x0002
#define LED_FRONT_RIGHT_RED_ON          0x0004
#define LED_FRONT_RIGHT_GREEN_ON        0x0008
#define LED_PRINT_0_ON                  0x0010
#define LED_PRINT_1_ON                  0x0020
#define LED_ALL_ON                      0x00FF

#define LED_FRONT_LEFT_RED_OFF          0x0100
#define LED_FRONT_LEFT_GREEN_OFF        0x0200
#define LED_FRONT_RIGHT_RED_OFF         0x0400
#define LED_FRONT_RIGHT_GREEN_OFF       0x0800
#define LED_PRINT_0_OFF                 0x1000
#define LED_PRINT_1_OFF                 0x2000
#define LED_ALL_OFF                     0xFF00

/*-----------------------------------------------------------------------
 * GLOBAL DATA TYPES
 *-----------------------------------------------------------------------*/

typedef struct sqc_tweak_table
{
    SAC_POS_UPDATE_MODE updateMode;      /**< Position update mode. */
    double              startPosition;   /**< Start position [pu] */
    double              stepSize;        /**< Distance between successive tweak positions [pu] */
    uint32_t            tableSize;       /**< Total number of feedforward values. */
    float*              pFeedforward;    /**< Feedforward values */
} SQC_TWEAK_TABLE;

#ifdef _WIN64
#define SQC_HANDLE_BYTE_SIZE 56
#else
#define SQC_HANDLE_BYTE_SIZE 36
#endif

#define SQC_HANDLE_SIZE  (SQC_HANDLE_BYTE_SIZE/sizeof(void*))

typedef struct sqc_rw_handle
{
    void* opaque[SQC_HANDLE_SIZE];
} SQC_RW_HANDLE;

/*-----------------------------------------------------------------------
 * EXPORTED FUNCTIONAL PROTOTYPES
 *-----------------------------------------------------------------------*/

/**
 *  @defgroup sqc_configuration Configuration
 *
 *  @{
 */

/**
 *  @brief  Allocate an area for shared data use.
 *
 *  @param[in]  areaNr              Area to be used for shared data.
 *  @param[out] pStartSharedData    Start address of shared data.
 *  @param[out] pSharedDataSize     Size of shared data.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *  @retval SQC_WRN_SHARED_DATA_AREA_ALREADY_ALLOCATED
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcAllocateSharedDataArea(int32_t  areaNr,
                                               void**   pStartSharedData,
                                               int32_t* pSharedDataSize);


/**
 *  @brief  Free an area for shared data use.
 *
 *  @param[in]  areaNr              Area not to be used as shared data area anymore.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcFreeSharedDataArea(int32_t areaNr);

/** @} */



/**
 *  @defgroup sqc_state_transitions State Transitions
 *
 *  @{
 */

/**
 *  @brief  Sleep for a minimum specified time.
 *
 *  @param[in]  seconds             Time to sleep [s].
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcDelay(double seconds);


/**
 *  @brief  Start the sequence, identified by the area number.
 *
 *  If the maximum of active sequences is already reached during the
 *  call of this function, an error is returned.
 *
 *  @param[in]  areaNr              Area number.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcStart(int32_t areaNr);


/**
 *  @brief  Abort the sequence, identified by the area number.
 *
 *  @param[in]  areaNr              Area number.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcAbort(int32_t areaNr);


/**
 *  @brief  Deactivate the sequence.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    This function never returns.
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcExit(void);


/**
 *  @brief  Wait until the specified input has the defined level or the specified timeout expires.
 *
 *  @param[in]  nodeId              Node identifier (returned by NhiConnect).
 *  @param[in]  inputId             Digital input specifier.
 *  @param[in]  level               Digital IO level.
 *  @param[in]  seconds             Timeout value [s].
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcWaitForInput(NHI_NODE              nodeId,
                                     NYCE_DIGITAL_IO_ID    inputId,
                                     NYCE_DIGITAL_IO_LEVEL level,
                                     double                seconds);

/**
 *  @brief  Wait until the specified input of the IndraDrive has the defined level or the specified timeout expires.
 *
 *  @param[in]  axisId              Axis identifier.
 *  @param[in]  inputId             Input number.
 *  @param[in]  level               Inactive (0) or active (1) level.
 *  @param[in]  seconds             Timeout value [s].
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcDLWaitForInput(SAC_AXIS              axisId,
                                       NYCE_DIG_IO_NR        inputId,
                                       NYCE_DIGITAL_IO_LEVEL level,
                                       double                seconds);

/**
 *  @brief  Retrieve the current sequence state, identified by the area number.
 *
 *  @param[in]  areaNr              Area number.
 *  @param[out] pState              Sequence state.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 */
NYCE_STATUS NYCE_API SqcGetState(int32_t    areaNr,
                                 SEQ_STATE* pState);

/** @} */



/**
 *  @defgroup sqc_error_handling Error Handling
 *
 * @{
 */

/**
 *  @brief  Set a user error for a given axis.
 *
 *  If the axis has an error handler configured for the given error code,
 *  the handler will be activated.
 *
 *  @param[in]  axisId              Axis identifier.
 *  @param[in]  userErrorCode       The error code identifier (SAC_AX_ERR_USER_ERROR_0 .. SAC_AX_ERR_USER_ERROR_7).
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 */
NYCE_STATUS NYCE_API SqcSetUserError(SAC_AXIS        axisId,
                                     NYCE_ERROR_CODE userErrorCode);

/** @} */



/**
 *  @defgroup sqc_par_var Parameters and Variables
 *
 *  Functions to access node and axis parameters and variables.
 *
 *  @{
 */

/**
 *  @brief  Copy a value to a standard NHI variable NHI_VAR_NODE_x.
 *
 *  @param[in]  varNum              0..15 (for NHI_VAR_NODE_0 .. NHI_VAR_NODE_15).
 *  @param[in]  value               Any value.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The values in NHI_VAR_NODE_x can be traced.
 */
NYCE_STATUS NYCE_API SqcCopyToNodeVariable(int32_t varNum,
                                           float   value);


/**
 *  @brief  Copy a value to a standard SAC variable SAC_VAR_UDSX_TRACE_x.
 *
 *  @param[in]  axisId              Axis identifier.
 *  @param[in]  varNum              0..7 (for SAC_VAR_UDSX_TRACE_0 .. SAC_VAR_UDSX_TRACE_7).
 *  @param[in]  value               Any value.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The values in SAC_VAR_UDSX_TRACE_x can be traced.
 */
NYCE_STATUS NYCE_API SqcCopyToAxisVariable(SAC_AXIS axisId,
                                           int32_t  varNum,
                                           float    value);


/**
 *  @brief  Create a handle for fast axis data access.
 *
 *  @param[in]  axisId              Axis identifier.
 *  @param[in]  dataId              Unique SAC data ID.
 *  @param[out] pHandle             Pointer to fast data access handle.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcOpenAxisData(SAC_AXIS       axisId,
                                     uint32_t       dataId,
                                     SQC_RW_HANDLE* pHandle);


/**
 *  @brief  Create a handle for fast node data access.
 *
 *  @param[in]  dataId              Unique NHI data ID.
 *  @param[out] pHandle             Pointer to fast data access handle.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcOpenNodeData(uint32_t       dataId,
                                     SQC_RW_HANDLE* pHandle);


/**
 *  @brief  Read SAC/NHI data using the fast data access.
 *
 *  @param[in]  pHandle             Pointer to fast data access handle.
 *  @param[out] pValue              The value read.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcReadData(const SQC_RW_HANDLE* pHandle,
                                 double*              pValue);


/**
 *  @brief  Write SAC/NHI data using the fast data access.
 *
 *  @param[in]  pHandle             Pointer to fast data access handle.
 *  @param[in]  value               The value to be written.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcWriteData(const SQC_RW_HANDLE* pHandle,
                                  double               value);


/**
 *  @brief  Close the fast data access handle.
 *
 *  @param[in]  pHandle             Pointer to fast data access handle
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcCloseData(SQC_RW_HANDLE* pHandle);

/** @} */



/**
 *  @defgroup sqc_events Events
 *
 *  @{
 */

/**
 *  @brief  Send an event to another sequence.
 *
 *  @param[in]  nodeId              Node identifier:
 *                                  - (0 - (NYCE_MAX_NR_OF_NODES - 1)) if the addressed sequence resides on another node, or
 *                                  - SQC_THIS_NODE if the addressed sequence resides on the same node as the sender, or
 *                                  - SQC_HOST_NODE if the addressed sequence (or application) resides on the host.
 *  @param[in]  sequenceId          Sequence identifier (ignored if iNodeId = SQC_HOST_NODE).
 *  @param[in]  eventData           Any data which can be read by the receiver of the event.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    Each sequence can have only one event pending. The latest event stands.
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcSendEvent(int32_t nodeId,
                                  int32_t sequenceId,
                                  int32_t eventData);


/**
 *  @brief  Block until an event arrives.
 *
 *  @param[out] pEventData          Pointer to the event data.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    Each sequence can have only one event pending. The latest event stands.
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcWaitForEvent(int32_t* pEventData);


/**
 *  @brief Block until an event arrives or a wait time out is reached.
 *
 *  If the time out value is SQC_INDEFINITE, the function will wait indefinitely
 *  for an event.
 *
 *  @param[in]  timeOut             Time out [s].
 *  @param[out] pEventData          Pointer to the event data.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    Each sequence can have only one event pending. The latest event stands.
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcWaitForEventEx(double   timeOut,
                                       int32_t* pEventData);

/**
 *  @brief  Wait until an event is sent by the firmware and catch the event.
 *
 *  @param[out] pNyceId             NyceId.
 *  @param[out] pEventId            Event id.
 *  @param[out] pEventData          Event data.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcCatchEvent(NYCE_ID*         pNyceId,
                                   NYCE_EVENT*      pEventId,
                                   NYCE_EVENT_DATA* pEventData);

/**
 *  @brief  Delete all caught events.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcFlushEvents(void);

/**
 *  @}
 */



/**
 *  @defgroup sqc_miscellaneous Miscellaneous
 * @{
 */

/**
 *  @brief  Turn the LEDs on the MCU module on and off.
 *
 *  @param[in]  ledCmd              On/Off specification of LED's (see LED_... macros).
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    LEDs are also manipulated by other programs (for
 *              example, the FireWire communication manipulates the
 *              red LED at the right side on the front of the MCU.
 */
NYCE_STATUS NYCE_API SqcMcuLed(uint32_t ledCmd);


/**
 *  @brief  Write the normalized value of feedforward adjustment.
 *
 *  @param[in]  axisId              Axis identifier.
 *  @param[in]  value               Any value.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 */
NYCE_STATUS NYCE_API SqcWriteFeedforwardAdjustment(SAC_AXIS axisId,
                                                   double   value);

/**
 *  @brief  Write the normalized value of the setpoint position adjustment.
 *
 *  @param[in]  axisId              Axis identifier.
 *  @param[in]  value               Any value.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 */
NYCE_STATUS NYCE_API SqcWriteSetpointAdjustment(SAC_AXIS axisId,
                                                double   value);


/**
 *  @brief  Retrieve the current time.
 *
 *  @param[out] pSeconds            Pointer to the current time [s].
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The time stamp is modulo 128 seconds. The timer frequency
 *              is 24.576 MHz (resolution of 40 nano seconds).
 */
NYCE_STATUS NYCE_API SqcTimeStamp(double* pSeconds);


/**
 *  @brief  Retrieve data from flash memory.
 *
 *  @param[out] data                size(length); Filled with the flash data.
 *  @param[in]  length              Number of bytes to copy.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    This function copies a maximum of 4 kByte from flash
 *               to the user memory. It is the responsibility of the caller
 *               that enough memory is available. The data was saved with
 *               SqcMemToFlash.
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcFlashToMem(char     data[],
                                   uint32_t length);


/**
 *  @brief  Store data in flash memory.
 *
 *  @param[in]  data                size(length); Data buffer.
 *  @param[in]  length              Number of bytes to copy.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    This function copies a maximum of 4 kByte from user memory
 *               to flash memory. The data can be read with SqcFlashToMem.
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcMemToFlash(const char data[],
                                   uint32_t   length);


/**
 *  @brief  Print a message to a server application on the host.
 *
 *  @param[in]  szString            A zero-terminated string.
 *
 *  @return Any NYCE_STATUS error code.
 *  @retval NYCE_OK
 *
 *  @remarks    The string is sent in messages of NYCE_MAX_SEQ_DBG_NR_OF_CHARS
 *               bytes each to the host and queued in the driver. On slow
 *               or busy host PC's messages can be lost if the queue is
 *               filled faster than it is emptied.
 *  @remarks    The function is not allowed in UDSX main function.
 */
NYCE_STATUS NYCE_API SqcDbgPrint(const char* szString);


/**
 *  @brief  Download the tweak table from the specified struct to the firmware.
 *
 *  @param[in]  axisId               Axis identifier.
 *  @param[in]  pTweakTable          Pointer to tweak table.
 *
 *  @remarks     In a sequence SqcTweakDownloadTable is used instead of SacTweakDownloadTable, to avoid
 *                unnecessary copy and conversion operations of the feedforwards.
 *  @remarks    The function is not allowed in UDSX main function.
 */

NYCE_STATUS NYCE_API SqcTweakDownloadTable(SAC_AXIS               axisId,
                                           const SQC_TWEAK_TABLE* pTweakTable);


/**
 *  @brief  Return the local node name.
 *
 *  @return Name of this node.
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
const char* NYCE_API SqcGetNodeName(void);


/**
 *  @brief  Retrieve the area number of the currently active sequence.
 *
 *  It can be used in a sequence to get a unique identifier of the current sequence,
 *  e.g. for logging purpose.
 *
 *  @return Area number of the sequence currently active.
 *
 *  @remarks    The function is not allowed in UDSX main function.
 */
int32_t NYCE_API SqcGetAreaNumber(void);

/** @} */

#ifdef C67

/**
 *  @brief NyceSuccess
 *
 *                  This function is used to check if a return value from a
 *                  function indicated success or failure. This is especially
 *                  convenient for status codes from non public interfaces
 *                  which are forwarded to customer allocations. These
 *                  applications can then simply check by NyceSuccess(retVal)
 *                  if the post condition of the function is satisfied.
 *
 *  @param[in]statusCode            NYCE_STATUS value returned from a function call
 *
 *  @retval The boolean return value indicates whether the statusCode
 *                    indicates SUCCESS.
 */
/* BOOL NYCE_API NyceSuccess(NYCE_STATUS statusCode); */
#define NyceSuccess(s) ((s & NYCE_ERROR_MASK) == 0)


/**
 *  @brief NyceError
 *
 *                  This function is used to check if a return value from a
 *                  function indicated success or failure. This is especially
 *                  convenient for status codes from non public interfaces
 *                  which are forwarded to customer allocations. These
 *                  applications can then simply check by NyceError(retVal)
 *                  if the return code indicates some error.
 *
 *  @param[in]  statusCode          NYCE_STATUS value returned from a function call
 *
 *  @retval The boolean return value indicates whether the statusCode
 *                    indicates ERROR.
 */
/* BOOL NYCE_API NyceError(NYCE_STATUS statusCode); */
#define NyceError(s) ((s & NYCE_ERROR_MASK) != 0)

#define SqcAtan(x)      atandp(x)
#define SqcCos(x)       cosdp(x)
#define SqcDiv(x, y)    divdp(x, y)
#define SqcExp(x)       expdp(x)
#define SqcLog(x)       logdp(x)
#define SqcLog10(x)     log10dp(x)
#define SqcPow(x, y)    powdp(x, y)
#define SqcSin(x)       sindp(x)
#define SqcSqrt(x)      sqrtdp(x)
#define SqcCeil(x)      ceil(x)
#define SqcFloor(x)     floor(x)

extern double SqcAtan2(double y, double x);

#else

/**
 *  @brief  Calculate the arctangent.
 *  @param[in]  x   type(double) Any number.
 *  @return     type(double) The arctangent of x in the range of -pi/2 to pi/2 radians. If x is 0, the function returns 0.
 */
#define SqcAtan(x)      atan(x)

/**
 *  @brief  Calculate the arctangent.
 *  @param[in]  y   type(double) Any number.
 *  @param[in]  x   type(double) Any number.
 *  @return     type(double) The arctangent of y/x in the range -pi to pi radians. If both parameters are 0, the function returns 0.
 */
#define SqcAtan2(y, x)  atan2(y, x)

/**
 *  @brief  Calculate the cosine.
 *  @param[in]  x   type(double) Angle in radians.
 *  @return     type(double) The cosine of x.
 */
#define SqcCos(x)       cos(x)

/**
 *  @brief  Calculate the base-e exponential (e number raised to the power x).
 *  @param[in]  x   type(double) Any number.
 *  @return     type(double) Exponential value of x.
 */
#define SqcExp(x)       exp(x)

/**
 *  @brief  Calculate the natural (base-e) logarithm.
 *  The base-e logarithm is the inverse of the natural exponential function exp().
 *  @param[in]  x   type(double) Any positive number.
 *  @return     type(double) Natural logarithm of x.
 */
#define SqcLog(x)       log(x)

/**
 *  @brief  Calculate the common (base-10) logarithm.
 *  @param[in]  x   type(double) Any positive number.
 *  @return     type(double) Common logarithm value of x.
 */
#define SqcLog10(x)     log10(x)

/**
 *  @brief  Calculate the base raised to the power exponent.
 *  @param[in]  x   type(double) Base - any positive number.
 *  @param[in]  y   type(double) Exponent - any positive number.
 *  @return     type(double) x raised to the power y.
 */
#define SqcPow(x, y)    pow(x, y)

/**
 *  @brief  Calculate the sine.
 *  @param[in]  x   type(double) Angle in radians.
 *  @return     type(double) The sine of x.
 */
#define SqcSin(x)       sin(x)

/**
 *  @brief  Calculate the square root.
 *  @param[in]  x   type(double) Any positive number.
 *  @return     type(double) The square root of x.
 */
#define SqcSqrt(x)      sqrt(x)

/**
 *  @brief  Return the smallest integral value.
 *  @param[in]  x   type(double) Any number.
 *  @return     type(double) The smallest integral value not less than x.
 */
#define SqcCeil(x)      ceil(x)

/**
 *  @brief  Return the largest  integral value.
 *  @param[in]  x   type(double) Any number.
 *  @return     type(double) The largest  integral value not greater than x.
 */
#define SqcFloor(x)     floor(x)

#endif

#ifdef __cplusplus
    }
#endif

/** @} */

#ifdef NT
#pragma pack(pop)
#endif

#endif /* __SQCAPI_H__ */