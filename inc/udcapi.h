/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2009
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000
//    Component Name: FIRMWARE
//    Subsystem Name: UDC
//    %full_filespec:    udcapi.h`13.1.5:incl:1 % (SYNERGY INFO, do not change)
// 
//    Description   : Public interface to the UDC subsystem
*/

#ifndef __UDCAPI_H__
#define __UDCAPI_H__

/*-----------------------------------------------------------------------------------------------*
 * GLOBAL INCLUDES
 *-----------------------------------------------------------------------------------------------*/
#include "nycedefs.h"

#ifdef NT
#pragma pack(push)
#pragma pack() //use default
#endif

/**
 * @defgroup udc User Definable Controller (UDC)
 *
 * The Controller in respect of the NYCe Software has some implementation level in the host 
 * and firmware level.  With NYCE UDC functionalities the user can upload controllers that
 * are designed by the user. The product will allow the user to design the controller via MATLAB.
 * Generate the controller C algorithm using RTW and
 * then upload the compiled and linked code to the DSP.
 *
 * @{
 */

/*-----------------------------------------------------------------------
 * GLOBAL DEFINES
 *-----------------------------------------------------------------------*/
#define UDC_MAX_NR_OF_CONTROLLERS 10 /* Maximum number of UDC controllers allowed */

/*-----------------------------------------------------------------------
 * EXPORTED FUNCTIONAL PROTOTYPES
 *-----------------------------------------------------------------------*/

/**
 * @defgroup udc_output_functions Controller output functions
 *
 */

/**
 * @defgroup udc_input_functions Controller input functions
 *
 */

/**
 *
 * @ingroup udc_output_functions
 * @brief UdcSetControllerOutput
 *
 *  This function sets the controller output as normalized data. cntrOut is the normalized controller output
 *  and will be saturated when exceeding the normalized saturation levels. 
 *
 * @param [in] axisId   axis id of the udc controlled axis
 * @param [in] cntrOut  controller output value
*/
void UdcSetControllerOutput(int32_t axisId,
                            float   cntrOut);
                     
/**
 *
 * @ingroup udc_output_functions
 * @brief UdcSetDigitalOutput
 *
 *  This function sets an output to the indicated active mode 
 *  depending on outputStatus. If this axis is connected to
 *  unitNr 0, only DIGOUT0 and FASTOUT0 can be used. For unitNr 1
 *  only DIGOUT1 and FASTOUT1 can be used
 *                 
 *
 * @param [in] axisId       - axis id of the udc controlled axis
 * @param [in] outputStatus - 0 = inactive, 1 = active
 * @param [in] fastOutput   - 0 = normal digital output, 1 = fast digital output
*/
void UdcSetDigitalOutput(int32_t  axisId, 
                         uint32_t outputStatus, 
                         int32_t  fastOutput);
                         
/**
 *
 * @ingroup udc_output_functions
 * @brief UdcSetAnalogOutput
 *
 *  This function sets the analogoutput (ANOUT0 for unitNr 0,
 *  ANOUT1 for unitNr 1) to the requested value
 *  The values is saturated when it exceeds 10.0 or -10.0.
 *
 * @param [in] axisId - axis id of the udc controlled axis
 * @param [in] value  - value to set on analog output
*/
void UdcSetAnalogOutput(int32_t axisId,
                        float   value);
                                                
/**
 *
 * @ingroup udc_input_functions
 * @brief UdcGetDigitalInput
 *
 *  This function returns the state of the requested input. 
 *  If unitNr = 0, it returns DIGIN0 or FASTIN0, if unitNr = 1
 *  it returns the value of DIGIN1 or FASTIN1
 *
 * @param [in] axisId    - axis id of the udc controlled axis
 * @param [in] fastInput - 0 = normal digital input, 1 = fast digital input
 *
 *
 * @retval Input status ( active or inactive )
*/
int32_t UdcGetDigitalInput(int32_t axisId,
                           int32_t fastInput);
                     
/**
 *
 * @ingroup udc_input_functions
 * @brief UdcGetAnalogInput
 *
 *  This function gets the value of the analogue input. In
 *  case of an invalid slotId or analogue output this function 
 *  will return 0.0.
 *
 * @param [in] axisId - axis id of the udc controlled axis
 *
 *
 * @retval The analogue input value
*/
float UdcGetAnalogInput(int32_t axisId);
                    
/**
 *
 * @ingroup udc_input_functions
 * @brief UdcGetSpgPosition
 *
 *  This function gets the setpoint position.
 *
 * @param [in] axisId - axis id of the udc controlled axis
 *
 *
 * @retval Setpoint position in increments.
*/
int32_t UdcGetSpgPosition(int32_t axisId);

/**
 *
 * @ingroup udc_input_functions
 * @brief UdcGetSpgVelocity
 *
 *  This function gets the setpoint velocity.
 *
 * @param [in] axisId - axis id of the udc controlled axis
 *
 *
 * @retval Setpoint velocity in increments per second.
*/
float UdcGetSpgVelocity(int32_t axisId);

/**
 *
 * @ingroup udc_input_functions
 * @brief UdcGetSpgAcceleration
 *
 *  This function gets the setpoint acceleration.
 *
 * @param [in] axisId - axis id of the udc controlled axis
 *
 *
 * @retval Setpoint acceleration in increments per second^2.
*/
float UdcGetSpgAcceleration(int32_t axisId);

/**
 *
 * @ingroup udc_input_functions
 * @brief UdcGetSpgJerk
 *
 *  This function gets the setpoint jerk.
 *
 * @param [in] axisId - axis id of the udc controlled axis
 *
 *
 * @retval Setpoint jerk in increments per second^3.
*/
float UdcGetSpgJerk(int32_t axisId);

/**
 *
 * @ingroup udc_input_functions
 * @brief UdcGetSpgDisplacement
 *
 *  This function gets the setpoint displacement.
 *
 * @param [in] axisId - axis id of the udc controlled axis
 *
 *
 * @retval Setpoint displacement between two samples.
*/
int32_t UdcGetSpgDisplacement(int32_t axisId);

/**
 *
 * @ingroup udc_input_functions
 * @brief UdcGetSpgDirection
 *
 *  This function gets the setpoint direction.
 *
 * @param [in] axisId - axis id of the udc controlled axis
 *
 *
 * @retval Setpoint direction -1, 0, 1 where 0 means that the 
 *                 setpoint generator idle is.
*/
int32_t UdcGetSpgDirection(int32_t axisId);

/**
 *
 * @ingroup udc_input_functions
 * @brief UdcGetAxisPosition
 *
 *  This function gets the axis position.
 *
 * @param [in] axisId - axis id of the udc controlled axis
 *
 *
 * @retval Axis position in increments
*/
int32_t UdcGetAxisPosition(int32_t axisId);

/**
 *
 * @ingroup udc_input_functions
 * @brief UdcGetPeerAxisPosition
 *
 *  This function gets the axis position.
 *
 * @param [in] slotId     - slot id of the peer axis
 * @param [in] axisUnitNr - unitNr [0,1] of the peer axis
 *
 *
 * @retval Axis position in increments of a peer axis encoder
*/
int32_t UdcGetPeerAxisPosition(NYCE_SLOT_ID slotId,
                               int32_t      axisUnitNr);

/**
 *
 * @ingroup udc_output_functions
 * @brief UdcSetTraceVariable
 *
 *  This function sets a value into one of the available trace variables
 *
 * @param [in] axisId   - axis id of the udc controlled axis
 * @param [in] value    - value to trace
 * @param [in] varIndex - index of SAC_VAR_UDC_TRACE_x, x = [0-(NYCE_MAX_NR_OF_UDC_TRACE_VARS-1)]
*/                         
void UdcSetTraceVariable(int32_t axisId,
                         float   value,
						 int32_t varIndex);  

/**
 *
 * @ingroup udc_output_functions
 * @brief UdcSetPositionError
 *
 *  This function activates the position error
 *
 * @param [in] axisId - axis id of the udc controlled axis
 * @param [in] value  - set position error value
*/  
void UdcSetPositionError(int32_t axisId,
                         int32_t value);

/**
 *
 * @ingroup udc_input_functions
 * @brief UdcGetInputParameter
 *
 *  This function returns the value of the input parameter requested
 *
 * @param [in] axisId    - axis id of the udc controlled axis
 * @param [in] parameter - index of the udc parameters [0-63]
*/ 
float UdcGetInputParameter(int32_t  axisId,
                           uint32_t parameter);

/**
 *
 * @ingroup udc_output_functions
 * @brief UdcSetUserError
 *
 *  This function activates the chosen user error. 
 *  The user error handlers can be configured using
 *  a configuration file or the NYCeConfigurator 
 *
 * @param [in] axisId      - axis id of the udc controlled axis
 * @param [in] userErrorNr - index of the user error to activate [0-7] 
*/ 
void UdcSetUserError(int32_t axisId,
                     int32_t userErrorNr);

/** @} */

#ifdef NT
#pragma pack(pop)
#endif

#endif /* __UDCAPI_H__ */

