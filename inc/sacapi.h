/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2009-2012
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000
//    Component Name: hostsw
//    Subsystem Name: sac
//    %full_filespec:    sacapi.h`185:incl:1 % (SYNERGY INFO, do not change)
//
//    Description   : External interface of SAC library
*/

#ifndef __SACAPI_H__
#define __SACAPI_H__

/*-----------------------------------------------------------------------------------------------
 * GLOBAL INCLUDES
 *-----------------------------------------------------------------------------------------------*/
#include "n4k_deprecated.h" //lint !e451
#include "nycedefs.h"
#include "sactypes.h"

/**
 * @addtogroup sac
 *
 * @{
 */

/*-----------------------------------------------------------------------------------------------
 * GLOBAL DEFINES
 *-----------------------------------------------------------------------------------------------*/

    /* If SAC is defined, the functions are exported, otherwise they are imported */
#ifdef SAC_EXPORT
#undef SAC_EXPORT
#endif

#ifdef NT
#ifdef SAC
#define SAC_EXPORT __declspec(dllexport)
#else
#define SAC_EXPORT __declspec(dllimport)
#endif
#else
#define SAC_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * EXPORTED FUNCTIONAL PROTOTYPES
 *-----------------------------------------------------------------------------------------------*/

/**
 * @ingroup sac_function_io
 * @brief SacDefineFunctionIO
 *
 *  This function defines a digital input or output as a particular motion I/O for an axis. The
 *  input or output to use is always located on the same node as the axis for which it is
 *  defined.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 * @param [in] axisId          id of the axis addressed
 * @param [in] ioFunction      function id
 * @param [in] digIOId         slot id and I/O number
 *
 *
 * @remarks The axis must be connected by the client.
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacDefineFunctionIO(SAC_AXIS           axisId,
                                                     SAC_IO_FUNCTION    ioFunction,
                                                     NYCE_DIGITAL_IO_ID digIOId);



/**
 *
 * @ingroup sac_function_io
 * @brief SacGetFunctionIO
 *
 * This function gets the input or output motion -function of a particular digital I/O.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId             axis identifier
 * @param [in] ioFunction         I/O function
 *
 * @param [out] pIOId             I/O identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetFunctionIO(SAC_AXIS           axisId,
                                                 SAC_IO_FUNCTION    ioFunction,
                                                 NYCE_DIGITAL_IO_ID *pIOId);



/**
 *
 * @ingroup sac_function_io
 * @brief SacDeleteFunctionIO
 *
 * This function deletes a particular motion I/O function of an axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId     - axis identifier
 * @param [in] ioFunction - I/O function
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDeleteFunctionIO(SAC_AXIS        axisId,
                                                    SAC_IO_FUNCTION ioFunction);



/**
 *
 * @ingroup sac_configuration
 * @brief SacConfigureAxis
 *
 * This function configures an axis. It defines the axis type, axis unit on a specific
 * drive, motor interface and position sensor interface.
 * Depending on the motor interface additional commutation parameters must be supplied.
 * Depending on the position sensor interface additional encoder parameters must be supplied.
 *
 * State  : SAC_IDLE,
 *          SAC_INACTIVE
 *
 * Trans. : -
 *
 * @param [in] axisId    - axis identifier
 * @param [in] pAxisPars - pointer to axis configuration parameters
 *
 *
 *
 * @remarks The defined configuration of an axis can be retrieved with SacGetAxisConfiguration.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacConfigureAxis(SAC_AXIS                      axisId,
                                                 const SAC_CONFIGURE_AXIS_PARS *pAxisPars);



/**
 *
 * @ingroup sac_configuration
 * @brief SacGetAxisConfiguration
 *
 * This function gets the defined configuration of an axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 * @param [out] pAxisPars - pointer to axis configuration parameters
 *
 *
 * @remarks The configuration of an axis can be defined with SacConfigureAxis.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetAxisConfiguration(SAC_AXIS                axisId,
                                                        SAC_CONFIGURE_AXIS_PARS *pAxisPars);



/**
 *
 * @ingroup sac_configuration
 * @brief SacCheckAxisConfiguration
 *
 * This function checks if the axis parameters supplied during the initialization phase
 *          are consistent.
 *
 * State  : SAC_IDLE,
 *          SAC_INACTIVE
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacCheckAxisConfiguration(SAC_AXIS axisId );



/**
 *
 * @ingroup sac_configuration
 * @brief SacEnableEncoderPower
 *
 * This function switches the encoder power of an axis on or off.
 *
 *          The encoder power of each axis of a drive module can be switched
 *          on/off independently.
 *
 * State  : All states (except SAC_IDLE)
 *
 * Trans. : -
 *
 * @param [in] axisId        - axis identifier
 * @param [in] encoderSwitch - TRUE = on, FALSE = off
 *
 *
 * @remarks Switching the encoder power off will lead to a cable or phase alarm error. Resetting the
 *          error can only be done when the encoder power is enabled again.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEnableEncoderPower(SAC_AXIS axisId,
                                                      BOOL     encoderSwitch);



/**
 *
 * @ingroup sac_configuration
 * @brief SacAlignMotor
 *
 * This function is used to perform a magnetic alignment procedure for a brushless AC motor.
 *
 * State  : SAC_INACTIVE
 *
 * Trans. : -
 *
 * @param [in] axisId     - axis identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacAlignMotor(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_configuration
 * @brief SacMoveCurrentAngle
 *
 * This function lets a brushless AC motor make a move by ramping up the quiescent current to
 * a maximum value, and then rotating the angle at which this current is applied.
 *
 * State  : SAC_INACTIVE
 *
 * Trans. : -
 *
 * @param [in] axisId            - axis identifier
 * @param [in] pCurrentAnglePars - pointer to the current angle parameters
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacMoveCurrentAngle(SAC_AXIS                          axisId,
                                                    const SAC_MOVE_CURRENT_ANGLE_PARS *pCurrentAnglePars);



/**
 *
 * @ingroup sac_configuration
 * @brief SacResetMultiTurnCounter
 *
 * This function resets the multi-turn counter of the encoder
 *
 * State  : SAC_INACTIVE,
 *          SAC_ERROR
 *
 * Trans. : -
 *
 * @param [in] axisId            - axis identifier
 *
 *
 * @remarks This function is only supported by Rexroth MSM absolute and Sanyo Denki absolute (PA035C type) encoders
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacResetMultiTurnCounter(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacConnect
 *
 * This function establishes a logical connection between an axis and a calling client.
 *
 *          The axis identifier, that is returned, is used by the client for all functions calls for
 *          that particular axis. The identifier is also used by the SAC library to communicate with
 *          the correct client.
 *
 *          SacConnect never implies a reset of the software on the node. The state of the axis
 *          after the connect is determined by the software running on the node.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] pAxisName - string for the axis name
 *
 * @param [out] pAxisId - pointer to axis identifier
 *
 *                       SAC_WRN_ALREADY_CONNECTED
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacConnect(const char *pAxisName,
                                           SAC_AXIS   *pAxisId);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacOpenLoop
 *
 * This function opens the control loop of the axis and keeps the axis activated.
 *
 * State  : SAC_READY,
 *          SAC_READY_STOPPED
 *
 * Trans. : SAC_READY         -> SAC_FREE,
 *          SAC_READY_STOPPED -> SAC_FREE_STOPPED
 *
 * @param [in] axisId - axis identifier
 *
 * @retval NYCE_OK
 * @retval STD_ERR_STATE_ERROR  - This function is not allowed in the current axis state.
 * @retval errorcode            - if not successful
 *
 * @remarks The axis can be activated again by the SacLock function.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacOpenLoop(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacDisconnect
 *
 * This function concludes the logical connection between the axis and the calling client.
 *          After successful completion, the axis can no longer be accessed by that client using
 *          the identifier.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 *
 *
 * @remarks Concluding the connection includes clearing all event enrolments.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDisconnect(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacEnableMotion
 *
 * This function enables motion for the axis. Non-fatal errors and warnings are cleared.
 *
 * State  : SAC_READY_STOPPED,
 *          SAC_FREE_STOPPED
 *
 * Trans. : SAC_READY_STOPPED   -> SAC_READY,
 *          SAC_FREE_STOPPED    -> SAC_FREE
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks This function can be used to enable motion after a stop profile, either as the result of
 *          error handling or after SacSmoothStop, SacQuickStop or SacFullStop was called.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEnableMotion(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacEnablePower
 *
 * This function enables the power of the amplifier for the axis.
 *
 * State  : SAC_INACTIVE
 *
 * Trans. : SAC_INACTIVE -> SAC_FREE
 *
 * @param [in] axisId - axis identifier
 *
 * @retval NYCE_OK
 * @retval errorcode                                - if not successful
 *
 * @remarks This function is not allowed for sensor axes.
 * @remarks The enabling of the power amplifier may be implemented differently for each supported motor type.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEnablePower(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacInitialize
 *
 * This function initializes the axis with the axis parameter values contained in the
 *          configuration file or from flash. If the string defined by SAC_USE_FLASH is supplied
 *          the initialization uses the parameter values from flash.
 *
 *          An error or warningcode returned by this function can be related to a specific SAC parameter identifier.
 *          Details about the error are logged and can be retrieved using the Deh logging functions or by using the NYCeLogger.
 *
 * State  : SAC_IDLE, SAC_INACTIVE
 *
 * Trans. : SAC_IDLE -> SAC_INACTIVE
 *
 * @param [in] axisId    - axis identifier
 * @param [in] pFileName - pointer to the name of the configuration file or indication that
 *                         configuration of flash is used
 *
 * @retval NYCE_OK
 * @retval CFG_ERR_INITIALIZE_INTERRUPTED            - Initialize was interrupted, because another process performed a SacInitialize during the execution of this call.
 * @retval CTR_ERR_SERVICE_MODE_ACTIVE               - The specified axis is in service mode.
 * @retval STD_ERR_STATE_ERROR                       - The specified axis is not IDLE or SAC_INACTIVE.
 * @retval CFG_WRN_UNFINISHED_INITIALIZE_INTERRUPTED - This initialize interrupted the SacInitialize of another process.
 * @retval CFG_WRN_PARAMETER_DEFAULT_USED            - One or more parameters are missing in the axis configuration file. Default values are used for these parameters.
 * @retval CFG_WRN_PARAMETER_NOT_SUPPORTED           - The axis configuration file contains parameter settings that are not used in the specified axis configuration.
 * @retval errorcode                                 - if not successful for some other reason.
 *
 * @remarks The NYCeConfigurator will show all warnings/errors during initialize in a message box.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacInitialize(SAC_AXIS   axisId,
                                              const char *pFileName);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacLock
 *
 * This function closes the feedback loop of the axis.
 *
 * State  : SAC_INACTIVE,
 *          SAC_FREE,
 *          SAC_FREE_STOPPED
 *
 * Trans. : SAC_INACTIVE     -> SAC_READY,
 *          SAC_FREE         -> SAC_READY,
 *          SAC_FREE_STOPPED -> SAC_READY_STOPPED
 *
 * @param [in] axisId - axis identifier
 *
 * @retval NYCE_OK
 * @retval STD_ERR_STATE_ERROR                      - This function is not allowed in the current axis state.
 * @retval errorcode                                - if not successful
 *
 * @remarks This function is not allowed for sensor axes and open loop axes.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacLock(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacReset
 *
 * This function resets the axis. This is particularly of use after handling a fatal error.
 *          Non-fatal errors and warnings are cleared.
 *
 *
 * State  : All states (except SAC_IDLE)
 *
 * Trans. : All states (except SAC_IDLE) -> SAC_INACTIVE
 *
 * @param [in] axisId - axis identifier
 *
 * Output :
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReset(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacShutdown
 *
 * This function shuts down the axis. All errors and warnings are cleared.
 *
 * State  : All states (except SAC_MOVING)
 *
 * Trans. : All states (except SAC_MOVING) -> SAC_IDLE
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacShutdown(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacRelease
 *
 * This function causes the state transition READY->FREE, similar to SacOpenLoop.However, the
 *          function SacRelease uses the last closed loop controller output value as open loop value.
 *
 * State  : SAC_READY
 *
 * Trans. : SAC_READY -> SAC_FREE
 *
 * @param [in] axisId - axis identifier
 *
 * @retval NYCE_OK
 * @retval STD_ERR_INVALID_AXIS_TYPE        - The axis type is SAC_INDRA_BLAC_AXIS.
 * @retval errorcode                        - if not successful
 *
 * @remarks For axes of type SAC_INDRA_BLAC_AXIS this function is not allowed.
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacRelease(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacHold
 *
 * This function causes the state transition FREE->READY, similar to SacLock. However the
 *          function SacHold performs initialization of the closed loop controller in such a way that
 *          the first closed loop controller output equals the last open loop controller output. This
 *          is realized mainly by appropriate initialization of the integrator buffer when the loop
 *          is closed.
 *
 * State  : SAC_FREE
 *
 * Trans. : SAC_FREE -> SAC_READY
 *
 * @param [in] axisId - axis identifier
 *
 * @retval NYCE_OK
 * @retval STD_ERR_INVALID_AXIS_TYPE        - The axis type is SAC_INDRA_BLAC_AXIS.
 * @retval errorcode                        - if not successful
 *
 * @remarks For axes of type SAC_INDRA_BLAC_AXIS this function is not allowed.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacHold(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_motion
 * @brief SacHome
 *
 * This function starts a homing sequence for an axis to locate the zero reference position
 *          or to define the current position as the zero position.
 *
 *          Which homing sequence is executed is specified with the parameters in the
 *          SAC_HOME_PARS structure. This structure is used with the function SacWriteParameterSet.
 *          Set the correct parameters in the configuration file is another way to specify
 *          this (See SAC_PAR_ID).
 *
 *          Homing with define home modes SAC_HOME_MODE_AXIS_POS, SAC_HOME_MODE_SETPOINT_POS,
 *          SAC_HOME_MODE_POS_ENCODER and SAC_HOME_MODE_HERE are possible in all states. No axis
 *          movement is involved but sets the current position to the specified home position. No state
 *          changes will result from these home modes. Only the home parameters mode and offset are used.
 *
 *          Other home modes are only possible in the state SAC_READY. During the total home
 *          sequence the state is SAC_MOVING or, when the end of stroke is hit, SAC_FREE; only after
 *          it has been completed, the state changes to SAC_READY. On detection of the specified home
 *          marker the current position is set to the specified home position.
 *
 *
 * State  : All states except SAC_IDLE if mode is SAC_HOME_MODE_AXIS_POS |
 *                                                SAC_HOME_MODE_SETPOINT_POS |
 *                                                SAC_HOME_MODE_ENCODER_POS,
 *          SAC_READY for all other home search modes
 *
 * Trans. : None if home search mode is SAC_HOME_MODE_AXIS_POS |
 *                                      SAC_HOME_MODE_SETPOINT_POS |
 *                                      SAC_HOME_MODE_ENCODER_POS,
 *          SAC_READY -> SAC_MOVING -> SAC_READY if home search mode is SAC_HOME_MODE_INDEX_ONLY |
 *                                                                      SAC_HOME_MODE_AREA_ONLY |
 *                                                                      SAC_HOME_MODE_INDEX_AREA
 *                                                                      SAC_HOME_MODE_LIMIT_SWITCH_ONLY |
 *                                                                      SAC_HOME_MODE_INDEX_LIMIT_SWITCH,
 *          SAC_READY -> SAC_MOVING -> SAC_FREE if home search mode is SAC_HOME_MODE_END_OF_STROKE,
 *          SAC_READY -> SAC_MOVING -> SAC_FREE  -> SAC_MOVING -> SAC_READY if home search mode
 *          is SAC_HOME_MODE_AREA_NEAR_EOS |
 *             SAC_HOME_MODE_INDEX_NEAR_EOS |
 *             SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS |
 *             SAC_HOME_MODE_LIMIT_SWITCH_NEAR_EOS |
 *             SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS
 *
 * @param [in] axisId - axis identifier
 *
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacHome(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_motion
 * @brief SacPointToPoint
 *
 * This function starts or continues a point to point movement for an axis with the
 *          specified parameters.
 *
 *          There are three movement profiles supported: quadratic, cubic and stepper. With a
 *          quadratic profile the specified velocity and acceleration will not be exceeded. With a
 *          cubic profile the specified velocity, acceleration and jerk values will not be exceeded.
 *          The stepper profile is the same as the quadratic profile. Except the velocity profile
 *          begins and ends with a step according the base velocity value.
 *
 *          If jerk is SAC_INDEFINITE or state is SAC_MOVING and in both cases the stepper parameters
 *          are zero the quadratic profile is used. If in one of the cases the stepper parameters are
 *          non zero the stepper profile is used. In all other situations the cubic profile is used.
 *
 * State  : SAC_READY ; spg state SAC_SPG_IDLE,
 *          SAC_MOVING ; spg state SAC_SPG_PTPING | SAC_SPG_JOGGING | SAC_SPG_INTERPOLATING |
 *                                SAC_SPG_GEARING | SAC_SPG_CAMMING
 *
 * Trans. : SAC_READY  -> SAC_MOVING ; spg state SAC_SPG_PTPING,
 *          SAC_MOVING -> SAC_MOVING ; spg state SAC_SPG_PTPING
 *
 * @param [in] axisId   - axis identifier
 * @param [in] pPtpPars - pointer to the structure for the point to point parameters
 *
 *
 * @remarks The velocity, acceleration must be greater than zero.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacPointToPoint(SAC_AXIS           axisId,
                                                const SAC_PTP_PARS *pPtpPars);



/**
 *
 * @ingroup sac_motion
 * @brief SacStartJog
 *
 * This function starts or continues a jogging movement for an axis with the specified
 *          parameters.
 *
 *          Two movement profiles are supported: cubic and stepper. With a cubic profile the
 *          specified velocity, acceleration and jerk values will not be exceeded. With a stepper
 *          profile the specified velocity and acceleration values will not be exceeded. Except the
 *          velocity profile begins according the base velocity.
 *
 *          Which profile to use is depending on the stepper axis parameters: base velocity and pre
 *          motion delay. If they are non zero the stepper profile is used. In all other situations
 *          the cubic profile is used.
 *
 * State  : SAC_READY ; spg state SAC_SPG_IDLE,
 *          SAC_MOVING ; spg state SAC_SPG_JOGGING | SAC_SPG_PTPING | SAC_SPG_GEARING | SAC_SPG_CAMMING
 *
 * Trans. : SAC_READY  -> SAC_MOVING ; spg state SAC_SPG_JOGGING,
 *          SAC_MOVING -> SAC_MOVING ; spg state SAC_SPG_JOGGING
 *
 * @param [in] axisId   - axis identifier
 * @param [in] pJogPars - Jog parameters
 *
 *
 * @remarks The values of the acceleration and jerk must be greater than zero.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacStartJog(SAC_AXIS           axisId,
                                            const SAC_JOG_PARS *pJogPars);



/**
 *
 * @ingroup sac_motion
 * @brief SacStopJog
 *
 * This function commands the axis to stop jogging by decelerating until the velocity is
 *          zero.
 *
 *          Two movement profiles are supported: cubic and stepper. With a cubic profile the
 *          specified velocity, acceleration and jerk values will not be exceeded. With a stepper
 *          profile the specified velocity and acceleration values will not be exceeded. Except the
 *          velocity profile ends according the base velocity.
 *
 *          Which profile to use is depending on the stepper axis parameters: base velocity and pre
 *          motion delay. If they are non zero the stepper profile is used. In all other situations
 *          the cubic profile is used.
 *
 * State  : SAC_MOVING ; all spg states
 *
 * Trans. : SAC_MOVING -> SAC_READY
 *
 * @param [in] axisId   - axis identifier
 * @param [in] pJogPars - Jog parameters
 *
 *
 * @remarks The values of the acceleration and jerk must be greater than zero.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacStopJog(SAC_AXIS           axisId,
                                           const SAC_JOG_PARS *pJogPars);



/**
 *
 * @ingroup sac_motion
 * @brief SacSetFeedOverride
 *
 * This function sets the feed override factor for the axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId   - axis identifier
 * @param [in] pFovPars - pointer to the feed override parameters
 *
 *
 * @remarks The default value for the feed override is 1.0. The value must be non-negative. It is
 *          limited to 1.0e+06. Feed override values below 1.0e-06 are rounded to 0 without
 *          notification.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacSetFeedOverride(SAC_AXIS                     axisId,
                                                   const SAC_FEED_OVERRIDE_PARS *pFovPars);



/**
 *
 * @ingroup sac_motion
 * @brief SacFullStop
 *
 * This function stops the current movement of an axis using the 'Full stop' profile.
 *
 * State  : SAC_MOVING ; all spg states,
 *          SAC_READY,
 *          SAC_FREE
 *
 * Trans. : SAC_MOVING  -> SAC_READY_STOPPED,
 *          SAC_READY   -> SAC_READY_STOPPED,
 *          SAC_FREE    -> SAC_FREE_STOPPED
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks No new motion commands are accepted until motion is enabled again by the function
 *          SacEnableMotion.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacFullStop(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_motion
 * @brief SacQuickStop
 *
 * This function stops the current movement of an axis using the 'Quick stop' profile.
 *
 * State  : SAC_MOVING ; all spg states,
 *          SAC_READY,
 *          SAC_FREE
 *
 * Trans. : SAC_MOVING  -> SAC_READY_STOPPED,
 *          SAC_READY   -> SAC_READY_STOPPED,
 *          SAC_FREE    -> SAC_FREE_STOPPED
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks No new motion commands are accepted until motion is enabled again by the function
 *          SacEnableMotion.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacQuickStop(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_motion
 * @brief SacSmoothStop
 *
 * This function stops the current movement of an axis using the 'Smooth stop' profile.
 *
 * State  : SAC_MOVING ; all spg states  (except SAC_QUICKSTOPPING),
 *          SAC_READY,
 *          SAC_FREE
 *
 * Trans. : SAC_MOVING  -> SAC_READY_STOPPED,
 *          SAC_READY   -> SAC_READY_STOPPED,
 *          SAC_FREE    -> SAC_FREE_STOPPED
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks No new motion commands are accepted until motion is enabled again by the function
 *          SacEnableMotion.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacSmoothStop(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_synchronize_groups
 * @brief MacDefineSyncGroup
 *
 *
 * This function groups the axes of which the identifiers are supplied. At successful
 *          definition of the group, the group identifier is returned
 *
 *          Successful grouping implies that the function takes care of it that movement commands
 *          and feed override commands are no longer executed upon reception; they are only executed
 *          after the function MacStartSyncGroup has been executed with the appropriate parameters.
 *          All axis identifiers supplied as input for this function have to be valid.
 *          That means for example that all axes have to be connected by the SAC client calling this function.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId   - size(nrOfAxes); array of axis identifiers
 * @param [in] nrOfAxes - number of axis identifiers in the array
 *
 * @param [out] pGroupId - identifier of the group
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API MacDefineSyncGroup(const SAC_AXIS   axisId[],
                                                   uint32_t         nrOfAxes,
                                                   uint32_t         *pGroupId);



/**
 *
 * @ingroup sac_synchronize_groups
 * @brief MacGetSyncGroup
 *
 * This function gets the identifiers of the axes belonging to the specified group.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] groupId    - identifier of a group
 *
 * @param [out] pNrOfAxes - number of axis in the sync group
 * @param [out] axisId    - size(NYCE_MAX_NR_OF_AXES); array of axis identifiers belonging to the specified group
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API MacGetSyncGroup(uint32_t    groupId,
                                                uint32_t    *pNrOfAxes,
                                                SAC_AXIS    axisId[]);



/**
 *
 * @ingroup sac_synchronize_groups
 * @brief MacStartSyncGroup
 *
 * This function starts the defined action synchronously on all axes defined in the group.
 * The synchronously started actions on all axes that are member of the synchronization
 * group can be a movement, the activation of new feed override parameters (presuming that
 * new movement or feed override parameters have been set for these axes) or a stop profile.
 * With the syncAction id's that execute a stop profile, all axes in the group can be stopped
 * synchronously.
 *
 * State  : All states
 *
 * Trans. : SAC_READY -> SAC_MOVING for all axes of the group involved; or none
 *
 * @param [in] groupId    - identifier of a group
 * @param [in] syncAction - action to be synchronized
 *
 *
 * @remarks A synchronously executed stop profile is not possible with the functions
 *          SacSmoothStop, SacQuickStop and SacFullStop on axes in a group, because these
 *          functions perform the requested action immediately on the specified axis.
 */
SAC_EXPORT NYCE_STATUS NYCE_API MacStartSyncGroup(uint32_t          groupId,
                                                  MAC_SYNC_ACTION   syncAction);



/**
 *
 * @ingroup sac_synchronize_groups
 * @brief MacDeleteSyncGroup
 *
 * This function deletes a group of axes.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] groupId   - identifier of a group
 *
 *
 * @remarks If an axis to be deleted has a motion or feed override command pending,
 *              - if the axis does not belong to any other group and it does not wait for a start trigger,
 *                the pending motion of this axis is removed.
 *              - if the axis does not belong to any other group and it does not wait for a feed override change,
 *                the pending feed override command of this axis is removed
 */
SAC_EXPORT NYCE_STATUS NYCE_API MacDeleteSyncGroup(uint32_t groupId);



/**
 *
 * @ingroup sac_electronic_gearing
 * @brief SacEcgLink
 *
 * The functions establish a link between the slave axis and master axis.
 *
 *          Before establishing the link, it checks the axis identifiers of master and slave. In
 *          addition, it checks the following validity aspects of the requested link (cf. the third
 *          until fifth errorcode):
 *          - An axis cannot be its own master.
 *          - The slave axis may not yet have another master (NB: the current master should be
 *            "unlinked" first; see the function SacEcgUnlink).
 *          - The master source should be a valid master source.
 *
 *          If these conditions are satisfied the requested link is established.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] slaveAxisId   - axis identifier of the slave axis
 * @param [in] pSacEcgMaster - pointer to master description
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEcgLink(SAC_AXIS             slaveAxisId,
                                           const SAC_ECG_MASTER *pSacEcgMaster);



/**
 *
 * @ingroup sac_electronic_gearing
 * @brief SacEcgUnlink
 *
 * This function deletes the link of the current axis to a master.
 *
 * State  : All states (except SAC_MOVING or spg state SAC_SPG_CAMMING or SAC_SPG_GEARING)
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEcgUnlink(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_electronic_gearing
 * @brief SacEcgLockGear
 *
 * This function commands the slave axis to start gearing with the specified parameters.
 *
 * State  : SAC_READY,
 *          SAC_MOVING ; spg states SAC_SPG_GEARING | SAC_SPG_CAMMING | SAC_SPG_PTPING |
 *                                  SAC_SPG_JOGGING | SAC_SPG_INTERPOLATING
 *
 * Trans. : SAC_READY  -> SAC_MOVING,
 *          SAC_MOVING -> SAC_READY if gearing ratio is 0
 *
 * @param [in] axisId          - axis identifier of the prior linked slave axis
 * @param [in] pGearPars       - pointer to gearing parameters
 *
 * Output :
 *
 *
 *
 * @remarks The lock will always break when a SacFullStop, SacQuickStop or SacSmoothStop is executed
 *          on the slave axis, the link remains though.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEcgLockGear(SAC_AXIS                     axisId,
                                               const SAC_ECG_LOCK_GEAR_PARS *pGearPars);


/**
 *
 * @ingroup sac_electronic_gearing
 * @brief SacEcgSetMasterSign
 *
 * This function commands the slave axis to use the specified sign for converting the
 *          master input to master displacements.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 * @param [in] masterSign - master sign
 *
 *
 * @remarks By default, the master input is converted to master displacements with a positive sign.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEcgSetMasterSign(SAC_AXIS      axisId,
                                                    SAC_DIRECTION masterSign);



/**
 *
 * @ingroup sac_electronic_gearing
 * @brief SacEcgUnlock
 *
 * This function commands the slave axis to stop gearing or camming within a displacement
 *          of the master axis given by masterDisplacement.
 *
 *          The stop gearing/camming is performed by locking to gearing with ratio 0 in lock mode
 *          SAC_ECG_LOCK_MAS_REL_SLAVE_AUTO.
 *
 * State  : SAC_MOVING ; spg state SAC_SPG_CAMMING | SAC_SPG_GEARING
 *
 * Trans. : SAC_MOVING -> SAC_READY
 *
 * @param [in] axisId             - axis identifier
 * @param [in] masterDisplacement - displacement of master axis [pu]
 *
 * @retval NYCE_OK
 * @retval errorcode                        - if not successful
 *
 * @remarks The axis must be linked to a master axis.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEcgUnlock(SAC_AXIS axisId,
                                             double   masterDisplacement);



/**
 *
 * @ingroup sac_electronic_gearing
 * @brief SacEcgSetMasterPos
 *
 * This function sets a new value for the current master position. From that moment on
 *          this value is kept updated with the master displacements.
 *
 *          Updating will be stopped when the function SacEcgUnlink is executed.
 *
 *          This master position is only used during the lock cam and gear commands using locking
 *          on master position (SAC_ECG_POS_ lock modes).
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId    - axis identifier
 * @param [in] masterPos - new position for the master axis of the slave axis
 *
 *
 * @remarks The axis must be linked to a master axis.
 *
 *          The user is responsible for correct use of this function; e.g., the master position is
 *          not well defined on the slave axis when the master axis is moving during execution of
 *          this function.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEcgSetMasterPos(SAC_AXIS axisId,
                                                   double   masterPos);



/**
 *
 * @ingroup sac_electronic_gearing
 * @brief SacEcgChangeMasterPos
 *
 * This function subtracts the master offset from the master position variable of the slave
 *          axis. This master position is only used during the lock cam and gear commands using
 *          locking on master position (SAC_ECG_POS_ lock modes). It can be used to prevent roll-over
 *          on the master position variable, or to adapt this variable for modulo operation on the
 *          actual master axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId       - axis identifier
 * @param [in] masterOffset - master offset
 *
 *
 * @remarks The axis must be linked to a master axis.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEcgChangeMasterPos(SAC_AXIS axisId,
                                                      double   masterOffset);

/**
*
* @ingroup sac_electronic_gearing
* @brief SacEcgLockCam
*
* This function commands the slave axis to start camming
* with a cam table as specified in the pLockCamPars structure with the specified parameters.
*
* State  : SAC_READY,
*          SAC_MOVING ; spg states SAC_SPG_GEARING | SAC_SPG_CAMMING | SAC_SPG_PTPING |
*                                  SAC_SPG_JOGGING | SAC_SPG_INTERPOLATING
*
* Trans. : SAC_READY  -> SAC_MOVING
*
* @param [in] axisId          - axis identifier of the prior linked slave axis
* @param [in] pLockCamPars    - pointer to parameters for the locking procedure
*
* @remarks If the axis is not linked to a master an error is returned.
*          The lock will always break when a SacFullStop, SacQuickStop or SacSmoothStop is executed
*          on the slave axis, the link remains though.
*/
SAC_EXPORT NYCE_STATUS NYCE_API SacEcgLockCam(SAC_AXIS                     axisId,
                                              const SAC_ECG_LOCK_CAM_PARS* pLockCamPars);


/**
*
* @ingroup sac_electronic_gearing
* @brief SacEcgShiftCamTable
*
* This function requests the axis controller to continue camming
* with the same cam profile as before but with a shifted cam function.
*
* State  : SAC_MOVING ; SPG state SAC_SPG_CAMMING
*
* @param [in] axisId                - axis identifier of the prior locked slave axis
* @param [in] pShiftCamTablePars     - pointer to the shift cam table parameters
*
* @remarks
*/
SAC_EXPORT NYCE_STATUS NYCE_API SacEcgShiftCamTable(SAC_AXIS                            axisId,
                                                    const SAC_ECG_SHIFT_CAM_TABLE_PARS* pShiftCamTablePars);


/**
 *
 * @ingroup sac_spline
 * @brief SacClearInterpolantBuffer
 *
 * This function clears the spline buffer of an axis.
 *
 * State  : All states (except SAC_MOVING ; spg state SAC_SPG_INTERPOLATING)
 *
 * Trans. : -
 *
 *
 * @param [in] axisId - axis identifier
 *
 * @remarks The spline buffer is cleared automatically when one of the states SAC_INACTIVE,
 *          SAC_READY_STOPPED or SAC_FREE_STOPPED is entered.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacClearInterpolantBuffer(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_spline
 * @brief SacStartInterpolation
 *
 * This function start interpolating the splines segments previously buffered for an axis.
 *
 * State  : SAC_READY,
 *          SAC_MOVING ; all spg states (except SAC_SPG_INTERPOLATING)
 *
 * Trans. : SAC_READY -> SAC_MOVING ; spg state SAC_SPG_INTERPOLATING,
 *          SAC_MOVING ; all spg states (except SAC_SPG_INTERPOLATING) -> SAC_MOVING ; spg state SAC_SPG_INTERPOLATING
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacStartInterpolation(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_spline
 * @brief SacStopInterpolation
 *
 * This function commands the axis to return to the state SAC_READY. When all splines in
 *          the buffer have been interpolated, the end velocity of the last spline was 0 and the
 *          command SacStopInterpolation has been given, the axis controller returns to the state
 *          SAC_READY.
 *
 *          It delineates the end of the splines in the buffer.
 *
 * State  : SAC_READY,
 *          SAC_MOVING ; all spg states
 *
 * Trans. : SAC_MOVING ; spg state SAC_SPG_INTERPOLATING -> SAC_READY
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks When this function is called before spline interpolation was started the spline buffer
 *          is cleared.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacStopInterpolation(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_spline
 * @brief SacWriteCubicInterpolant
 *
 * This function writes a spline segment to the spline buffer of an axis.
 *
 * State  : SAC_READY,
 *          SAC_MOVING ; all spg states
 *
 * Trans. : -
 *
 * @param [in] axisId   - axis identifier
 * @param [in] pCubPars - pointer to the spline parameters
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteCubicInterpolant(SAC_AXIS           axisId,
                                                         const SAC_CUB_PARS *pCubPars);



/**
 *
 * @ingroup sac_spline
 * @brief SacWriteCubicIntBuffer
 *
 * This function writes several spline segments to the spline buffer of an axis.
 *
 *          The maximum number of spline segments that can be written with this function is limited
 *          to NYCE_MAX_NR_OF_SPLINE_SEGMENTS_WRITE.
 *
 * State  : SAC_READY,
 *          SAC_MOVING ; all spg states
 *
 * Trans. : -
 *
 * @param [in] axisId      - axis identifier
 * @param [in] nrOfSplines - max(NYCE_MAX_NR_OF_SPLINE_SEGMENTS_WRITE); number of splines segments to be written
 * @param [in] cubBuffer   - size(nrOfSplines); Array of spline parameters
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteCubicIntBuffer(SAC_AXIS             axisId,
                                                       uint32_t             nrOfSplines,
                                                       const SAC_CUB_PARS   cubBuffer[]);



/**
 *
 * @ingroup sac_test_generator
 * @brief SacStartTestSignal
 *
 * This function starts the test-signal generator. If the test-signal generator is already
 *          running, it is restarted immediately with the new settings.
 *
 *          The test signal generator type and all general and specific parameters for the test
 *          signal generation are contained in the SAC_TEST_SIGNAL_PARS structure.
 *
 *          The test signal generator types 'block' ,'sine' and 'saw-tooth' generate a periodic
 *          signal. The number of full periods to be generated is also contained in the
 *          SAC_TEST_SIGNAL_PARS structure. After generation of the number of periods, the test
 *          signal generator is stopped. Its output is set to zero.
 *          If the number of periods to be generated equals to (int32_t)-1, an infinite sequence
 *          of periods is generated.
 *
 *          The test signal generator types 'PRBS' and 'random noise' generate a random
 *          (i.e. non-periodical) signal for the number of seconds, which is also contained in the
 *          SAC_TEST_SIGNAL_PARS structure. After this time has expired, the test signal generator
 *          is stopped and its output set to zero.
 *          If the time to be generated equals to SAC_INDEFINITE ((double)-1), the test signal is
 *          generated indefinitely.
 *
 *          If the SAC_TEST_SIGNAL_INJECT_POINT_ID in the SAC_TEST_SIGNAL_PARS structure equals
 *          SAC_TEST_SIGNAL_INJ_OL_OUTPUT, the test signal is added to the open loop controller
 *          output. If it equals SAC_TEST_SIGNAL_INJ_CL_OUTPUT, it is added to the closed loop
 *          controller output, and if it equals SAC_TEST_SIGNAL_INJ_SETPOINT, the test signal
 *          is superposed on the setpoint position.
 *
 * State  : SAC_FREE                if SAC_TEST_SIGNAL_INJECT_POINT_ID equals SAC_TEST_SIGNAL_INJ_OL_OUTPUT,
 *          SAC_READY or SAC_MOVING if SAC_TEST_SIGNAL_INJECT_POINT_ID equals SAC_TEST_SIGNAL_INJ_CL_OUTPUT
 *                                  or SAC_TEST_SIGNAL_INJ_SETPOINT
 *
 * Trans. : -
 *
 * @param [in] axisId          - axis identifier
 * @param [in] pTestSignalPars - pointer to the test signal parameter structure
 *
 *
 * @remarks For none-periodical test signal generator types the number of periods to be generated
 *          is irrelevant.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacStartTestSignal(SAC_AXIS                   axisId,
                                                   const SAC_TEST_SIGNAL_PARS *pTestSignalPars);



/**
 *
 * @ingroup sac_test_generator
 * @brief SacStopTestSignal
 *
 * This function stops the test-signal generator.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks If no test-signal generator is running the function just returns with NYCE_OK.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacStopTestSignal(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_test_generator
 * @brief SacSetTestSignalCountDirection
 *
 * This function defines the count direction of the period counter of a specific type of
 *          test signal generator. The period counter is modified at the start of every new period
 *          according to "periodCounter += countDirection". The function is only allowed if the type
 *          of generator specified is inactive.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId         - axis identifier
 * @param [in] testSignalType - type of test signal generator
 * @param [in] countDirection - count direction for period counter
 *
 *
 * @remarks For non-periodical test signal generator types this function returns SAC_ERR_INVALID_PARAMETER.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacSetTestSignalCountDirection(SAC_AXIS             axisId,
                                                               SAC_TEST_SIGNAL_TYPE testSignalType,
                                                               SAC_DIRECTION        countDirection);



/**
 *
 * @ingroup sac_test_generator
 * @brief SacSetTestSignalCounter
 *
 * This function assigns the specified value to the period counter of a specific type of
 *          test signal generator. The function is only allowed if the type of generator specified
 *          is inactive.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId         - axis identifier
 * @param [in] testSignalType - type of test signal generator
 * @param [in] counterValue   - new value for period counter
 *
 *
 * @remarks For non-periodical test signal generator types this function returns SAC_ERR_INVALID_PARAMETER.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacSetTestSignalCounter(SAC_AXIS                axisId,
                                                        SAC_TEST_SIGNAL_TYPE    testSignalType,
                                                        int32_t                 counterValue);



/**
 *
 * @ingroup sac_parameters
 * @brief SacGetParameterBounds
 *
 * This function reads the maximum and minimum value of the axis parameter of an axis
 *
 *          A valid value for a parameter lies between or is equal to the boundaries indicated by
 *          the maximum and minimum value.
 *
 * State  : All states (except SAC_IDLE)
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 * @param [in] parId  - parameter identifier
 *
 * @param [out] pMaxValue - pointer to maximum parameter value
 * @param [out] pMinValue - pointer to minimum parameter value
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetParameterBounds(SAC_AXIS   axisId,
                                                      SAC_PAR_ID parId,
                                                      double     *pMaxValue,
                                                      double     *pMinValue);

/**
 *
 * @ingroup sac_parameters
 * @brief SacReadParameter
 *
 * This function reads the parameter value for the axis.
 *
 * State  : All states (except SAC_IDLE)
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 * @param [in] parId  - parameter identifier
 *
 * @param [out] pValue - pointer to parameter value
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadParameter(SAC_AXIS   axisId,
                                                 SAC_PAR_ID parId,
                                                 double     *pValue);

/**
 *
 * @ingroup sac_parameters
 * @brief SacReadParameterSet
 *
 * This function reads a parameter set of an axis.
 *
 * State  : All states (except SAC_IDLE)
 *
 * Trans. : -
 *
 * @param [in] axisId     - axis identifier
 * @param [in] paramSetId - identifies the parameter set
 *
 * @param [out] pParamSet - pointer to the parameter structure for the relevant parameter set
 *
 *
 * @remarks Depending of the parameter set identifier pParamSet must point to the correct parameter
 *          structure. Which parameter structure to use with a particular parameter set identifier
 *          can be found in the following way: the parameter set identifier minus the characters
 *          '_ID' is the name of the parameter structure to be used.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadParameterSet(SAC_AXIS         axisId,
                                                    SAC_PARAM_SET_ID paramSetId,
                                                    void             *pParamSet);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadControllerPidPars(SAC_AXIS                 axisId,
                                                         SAC_CONTROLLER_PID_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadControllerFilterPars(SAC_AXIS                    axisId,
                                                            SAC_CONTROLLER_FILTER_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadControllerDmfPars(SAC_AXIS                 axisId,
                                                         SAC_CONTROLLER_DMF_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadControllerStatePars(SAC_AXIS                   axisId,
                                                           SAC_CONTROLLER_STATE_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadControllerTypePars(SAC_AXIS                  axisId,
                                                          SAC_CONTROLLER_TYPE_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadControllerEnhancementPars(SAC_AXIS                         axisId,
                                                                 SAC_CONTROLLER_ENHANCEMENT_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadErrorCheckPars(SAC_AXIS              axisId,
                                                      SAC_ERROR_CHECK_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadHomePars(SAC_AXIS       axisId,
                                                SAC_HOME_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadAlignMotorPars(SAC_AXIS              axisId,
                                                      SAC_ALIGN_MOTOR_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadCurrentControlPars(SAC_AXIS                  axisId,
                                                          SAC_CURRENT_CONTROL_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadPwmPars(SAC_AXIS      axisId,
                                               SAC_PWM_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadQuickstopPars(SAC_AXIS            axisId,
                                                     SAC_QUICKSTOP_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Read the parameters set from the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[out] pPars   - Parameter set to read.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadSmoothstopPars(SAC_AXIS             axisId,
                                                      SAC_SMOOTHSTOP_PARS* pPars);


/**
 *
 * @ingroup sac_parameters
 * @brief SacSaveToFlash
 *
 * This function saves all currently active axis parameters of the axis to flash.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks The parameters in flash can be used with the function SacInitialize.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacSaveToFlash(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_parameters
 * @brief SacUpload
 *
 * This function uploads the configuration data of the axis into a file. If a file with the
 *          same name exists, it will be over-written.
 *
 *          The layout of the configuration file has to be specified yet.
 *
 * State  : All states (except SAC_IDLE)
 *
 * Trans. : -
 *
 * @param [in] axisId    - axis identifier
 * @param [in] pFileName - pointer to the name of the configuration file
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacUpload(SAC_AXIS   axisId,
                                          const char *pFileName);



/**
 *
 * @ingroup sac_parameters
 * @brief SacWriteParameter
 *
 * This function writes the parameter value to the axis.
 *
 * State  : All states (except SAC_IDLE)
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 * @param [in] parId  - parameter identifier
 * @param [in] value  - parameter value
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteParameter(SAC_AXIS   axisId,
                                                  SAC_PAR_ID parId,
                                                  double     value);



/**
 *
 * @ingroup sac_parameters
 * @brief SacWriteParameterSet
 *
 * This function writes the parameters set to the axis.
 *
 * State  : All states (except SAC_IDLE)
 *
 * Trans. : -
 *
 * @param [in] axisId     - axis identifier
 * @param [in] paramSetId - identifies the parameter set
 * @param [in] pParamSet  - pointer to the parameter structure for the relevant parameter set
 *
 *
 * @remarks See SacReadParameterSet for an explanation of the parameter addressing.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteParameterSet(SAC_AXIS         axisId,
                                                     SAC_PARAM_SET_ID paramSetId,
                                                     const void       *pParamSet);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteControllerPidPars(SAC_AXIS                       axisId,
                                                          const SAC_CONTROLLER_PID_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteControllerFilterPars(SAC_AXIS                          axisId,
                                                             const SAC_CONTROLLER_FILTER_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteControllerDmfPars(SAC_AXIS                       axisId,
                                                          const SAC_CONTROLLER_DMF_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteControllerStatePars(SAC_AXIS                         axisId,
                                                            const SAC_CONTROLLER_STATE_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteControllerTypePars(SAC_AXIS                        axisId,
                                                           const SAC_CONTROLLER_TYPE_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteControllerEnhancementPars(SAC_AXIS                               axisId,
                                                                  const SAC_CONTROLLER_ENHANCEMENT_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteErrorCheckPars(SAC_AXIS                    axisId,
                                                       const SAC_ERROR_CHECK_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteHomePars(SAC_AXIS             axisId,
                                                 const SAC_HOME_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteAlignMotorPars(SAC_AXIS                    axisId,
                                                       const SAC_ALIGN_MOTOR_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteCurrentControlPars(SAC_AXIS                        axisId,
                                                           const SAC_CURRENT_CONTROL_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWritePwmPars(SAC_AXIS            axisId,
                                                const SAC_PWM_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteQuickstopPars(SAC_AXIS                  axisId,
                                                      const SAC_QUICKSTOP_PARS* pPars);


/**
 *  @ingroup sac_parameters
 *
 *  @brief  Write the parameters set to the axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  - Axis identifier.
 *  @param[in]  pPars   - Parameter set to write.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacWriteSmoothstopPars(SAC_AXIS                   axisId,
                                                       const SAC_SMOOTHSTOP_PARS* pPars);


/**
 * @ingroup sac_variables
 *
 * @brief Add an axis variable to the NYCE trace.
 *
 *      This function adds an axis variable to the NYCE trace and returns its
 *      position in a trace sample.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 * @param [in]  axisId         Axis identifier.
 * @param [in]  varId          Axis variable identifier.
 * @param [out] pVariableIndex Returned index of the variable in a trace sample.
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      SAC_ERR_INVALID_AXIS_ID                 The axis id is invalid.
 * @retval      SAC_ERR_INVALID_PARAMETER               The variable id is invalid.
 * @retval      SAC_ERR_INVALID_OUTPUT_ARGUMENT         pVariableIndex is NULL.
 * @retval      CML_ERR_HSD_NOT_SUPPORTED_WITH_NY4150   An NY4150 is used on the node. HSD is not supported by the node when
 *                                                      it has an NY4150 installed.
 * @retval      CML_ERR_HSD_NOT_ENABLED                 HSD is not enabled at node level. NHI_PAR_NODE_HSD_ENABLE must be set to 1.
 * @retval      PDS_WRN_HSD_VAR_DATA_NOT_AVAILABLE      A HSD variable is added, but the current axis state and configuration
 *                                                      does not allow it to generate trace data for the variable.
 *                                                      For example, if the axis is IDLE, this warning is generated. When tracing,
 *                                                      the traced data will be zero. As soon as the axis is initialized and runs in
 *                                                      PVL on the drive mode, valid trace data will be generated.
 * @retval      PDS_ERR_OUT_OF_HSD_RESOURCES            No HSD variable can be selected anymore.
 *                                                      Up to 2 HSD variables per axis can be selected and up to 8 axes can be used
 *                                                      for selecting HSD variables.
 * @retval      TRACE_WRN_VARIABLE_ALREADY_SELECTED     The variable was already added.
 * @retval      TRACE_ERR_INVALID_STATE                 The trace state is invalid. It must be NYCE_TRACE_READY or NYCE_TRACE_ERROR.
 * @retval      TRACE_ERR_MAX_NR_OF_VARS_REACHED        The maximum number of variables which can be added to the variable set
 *                                                      has been reached.
 * @retval      TRACE_ERR_MAX_NR_OF_NODES_REACHED       The maximum number of nodes which can be used by trace and variable set
 *                                                      has been reached.
 *                                                      The amount of available free trace variables on the node will be
 *                                                      decreased by 1 when a non-HSD variable is added. It will be decreased
 *                                                      by 4 when a HSD variable is added, because it uses more resources.
 *
 * @remarks
 *      The trace must have been defined using NyceDefineTrace before variables can be added and removed.
 *
 *      An error will be returned if one of the following conditions are met, while adding a HSD variable:
 *          - HSD is not enabled at node level. NHI_PAR_NODE_HSD_ENABLE must be set to 1 in order to select HSD variables.
 *            Note that this parameter can only be changed when all axes are IDLE.
 *          - An NY4150 unit is used by the node.
 *          - The maximum number of selectable HSD variables for the axis, which is 2 per axis, has been reached.
 *          - The maximum number of axes for which HSD variables can be selected has been reached.
 *            Up to 8 axes per node can be used for tracing HSD variables.
 *
 *      Trace data for a HSD variable is only generated if the following constraints are met:
 *          - Axis must be initialized and use PVL on the drive. The drive must be in one of the first 4 slots on the node.
 *          - The drive must be an NY4120, NY4130 or NY4140.
 *          - If the node frequency is 1 kHz (lowest node frequency) and the axis PVL frequency is 32kHz (highest PVL frequency),
 *            the variable must be the first and only selected HSD variable for the axis. Any second added HSD variable for
 *            the same axis will not generate valid trace data. For other node and PVL frequency combinations, valid trace data
 *            for 2 HSD variables on one axis can be generated.
 *
 *      If one of the above constraints is not met while adding the HSD variable, the warning PDS_WRN_HSD_VAR_DATA_NOT_AVAILABLE
 *      is returned. When tracing, the trace data for these invalid HSD variables will be set to zero and the trace error code
 *      in the trace info will be set to NYCE_TRACE_ERR_HSD_INVALID to notify that the trace buffer has stored invalid HSD data.
 *      As soon when these conditions are met, valid trace data will be generated.
 *
 *      Only up to NYCE_MAX_NR_OF_ISOCHRONOUS_CHANNELS defined number of nodes can be used, system wide, by the trace
 *      and variable set functionality together.
 *
 *      The given axis id is stored in the trace system and will be returned by the functions NyceGetTraceElement and
 *      NyceGetLocalTraceElements. You should not disconnect any axis while it is being used by trace because the stored
 *      axis id will become invalid.
 *
 * @see NyceDeleteVariableFromTrace
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacAddVariableToTrace(SAC_AXIS      axisId,
                                                      SAC_VAR_ID    varId,
                                                      uint32_t      *pVariableIndex);



/**
 *
 * @ingroup sac_variables
 * @brief SacReadVariable
 *
 * This function reads the actual value of the variable for an axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 * @param [in] varId  - variable identifier
 *
 * @param [out] pValue - pointer to variable value
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadVariable(SAC_AXIS   axisId,
                                                SAC_VAR_ID varId,
                                                double     *pValue);

/**
 * @ingroup sac_variables
 *
 * @brief Add an axis variable to the NYCE variable set.
 *
 *      This function adds an axis variable to the NYCE variable set and returns its
 *      position in the set.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in]  axisId          Axis identifier.
 * @param [in]  varId           Axis variable identifier.
 * @param [out] pVariableIndex  Returned index of the variable in the variable set.
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      SAC_ERR_INVALID_AXIS_ID                 The axis id is invalid.
 * @retval      SAC_ERR_INVALID_PARAMETER               The variable id is invalid.
 * @retval      SAC_ERR_INVALID_OUTPUT_ARGUMENT         pVariableIndex is NULL.
 * @retval      TRACE_WRN_VARIABLE_ALREADY_SELECTED     The variable was already added.
 * @retval      TRACE_ERR_MAX_NR_OF_VARS_REACHED        The maximum number of variables which can be added to the variable set
 *                                                      has been reached.
 * @retval      TRACE_ERR_MAX_NR_OF_NODES_REACHED       The maximum number of nodes which can be used by trace and variable set
 *                                                      has been reached.
 *
 * @remarks
 *      Only up to NYCE_MAX_NR_OF_ISOCHRONOUS_CHANNELS defined number of nodes can be used, system wide, by the trace
 *      and variable set functionality together.
 *
 * @see NyceDeleteVariableFromSet
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacAddVariableToSet(SAC_AXIS    axisId,
                                                    SAC_VAR_ID  varId,
                                                    uint32_t    *pVariableIndex);



/**
 *
 * @ingroup sac_state_transitions
 * @brief SacReadState
 *
 * This function reads the actual state and setpoint generator state of the axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 * @param [out] pState    - pointer to axis state
 * @param [out] pSpgState - pointer to axis setpoint generator state
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacReadState(SAC_AXIS      axisId,
                                             SAC_STATE     *pState,
                                             SAC_SPG_STATE *pSpgState);



/* Event Handling--------------------------------------------------------------------------------*/

/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief SacDefineErrorHandler
 *
 * This function defines how the detection of an axis error should be handled.
 *
 *          With this function it is possible to change the default error handling of an error. The
 *          default error handling is installed at start-up of the system.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId       - axis identifier
 * @param [in] axisError    - axis error number
 * @param [in] errorHandler - error handler
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefineErrorHandler(SAC_AXIS          axisId,
                                                      NYCE_ERROR_CODE   axisError,
                                                      SAC_ERROR_HANDLER errorHandler);



/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief SacGetErrorHandler
 *
 * This function gets the error handler that is defined for a specific axis error.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId       - axis identifier
 * @param [in] axisError    - axis error number
 *
 * @param [out] pErrorHandler - pointer to error handler
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetErrorHandler(SAC_AXIS          axisId,
                                                   NYCE_ERROR_CODE   axisError,
                                                   SAC_ERROR_HANDLER *pErrorHandler);



/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief SacSetServiceModeOperation
 *
 * This function sets the service mode operation parameters for an axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId          - axis identifier
 * @param [in] pServiceModePars - pointer to the parameters for service mode operations
 *
 * @retval      NYCE_OK on success
 * @retval      EDH_ERR_SERVICE_MODE_ACTIVE - It is not allowed to change the service mode settings when service mode is enabled.
 * @return      Any other NYCE_STATUS error code on failure.
 *
 * @remarks   In service mode it is possible to temporarily overwrite the saturation levels by writing the parameters
 *            SAC_PAR_SAT_LEVEL and SAC_PAR_MIN_SAT_LEVEL.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacSetServiceModeOperation(SAC_AXIS                              axisId,
                                                           const SAC_SERVICE_MODE_OPERATION_PARS *pServiceModePars);



/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief SacEnterServiceMode
 *
 * The function commands the axis to enter the service mode.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEnterServiceMode(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief SacExitServiceMode
 *
 * This function commands the axis to leave the service mode.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacExitServiceMode(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief SacClearWarning
 *
 * This function clears and enables the detection of an axis error which is handled by the
 *          warning error handler.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacClearWarning(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief SacSetRecoverMode
 *
 * This function sets the axis in the recover mode. In this mode the detection of all
 *          currently active axis error inputs is suppressed. In this mode the user is able to
 *          control the axis and to clear the error. The axis leaves the recover mode automatically
 *          as soon as all axis error inputs present when entering recover mode are no longer active.
 *
 * State  : All states (ignore if no error inputs are active)
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacSetRecoverMode(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief MacDefineErrorGroup
 *
 * This function groups the axes into an error group. At successful definition of the
 *          group, the group identifier is returned.
 *          All axis identifiers supplied as input for this function have to be valid.
 *          That means for example that all axes have to be connected by the SAC client calling this function.
 *
 * State  : All states.
 *
 * Trans. : -
 *
 * @param [in] axisId   - size(nrOfAxes); array of axis identifiers
 * @param [in] nrOfAxes - number of axis identifiers in the array
 *
 * @param [out] pGroupId - pointer to error group identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API MacDefineErrorGroup(const SAC_AXIS  axisId[],
                                                    uint32_t        nrOfAxes,
                                                    uint32_t        *pGroupId);



/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief MacDeleteErrorGroup
 *
 * This function deletes an error group. The groupId becomes available for a new group to
 *          be defined.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] groupId - error group identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API MacDeleteErrorGroup(uint32_t groupId);



/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief SacDeleteAxisFromErrorGroup
 *
 * This function deletes an axis from its error group.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks None.
 */

SAC_EXPORT NYCE_STATUS NYCE_API SacDeleteAxisFromErrorGroup(SAC_AXIS axisId);


/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief SacAddAxisToErrorGroup
 *
 * This function adds an axis to an existing error group.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 * @param [in] groupId - group identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacAddAxisToErrorGroup(SAC_AXIS axisId,
                                                       uint32_t groupId);



/**
 *
 * @ingroup sac_error_and_service_handling
 * @brief SacGetEncoderError
 *
 * This function retrieves the active encoder error from the digital EnDat2.2 or Sanyo Denki absolute encoder interface.
 *
 * State  : SAC_ERROR
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 * @param [out] pEncoderError - pointer to encoder error
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetEncoderError(SAC_AXIS          axisId,
                                                   SAC_ENCODER_ERROR *pEncoderError);


/**
 *
 * @ingroup sac_events_and_actions
 * @brief SacDefineEventAction
 *
 * This function defines how the occurrence of an event generated for an axis will
 *          subsequently be handled by the axis controller. When that event occurs, the defined
 *          action is executed automatically without interference of any client.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId      - axis identifier
 * @param [in] eventId     - SAC event identifier
 * @param [in] eventAction - event action
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefineEventAction(SAC_AXIS         axisId,
                                                     NYCE_EVENT       eventId,
                                                     SAC_EVENT_ACTION eventAction);



/**
 *
 * @ingroup sac_events_and_actions
 * @brief SacDefineEventEnrolment
 *
 * This function defines how the occurrence of an event generated for an axis will
 *          subsequently be handled by the client.
 *
 *          For every event multiple but separate enrolment functions can be installed. The order of
 *          execution is the same as the order in which they are defined.
 *
 *          When an event is raised, the user defined handler is called with the appropriate
 *          parameters.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId    - axis identifier
 * @param [in] eventId   - SAC event identifier
 * @param [in] handler   - pointer to the event enrolment function of the user
 * @param [in] pUserData - pointer to user specific data concerning the event
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefineEventEnrolment(SAC_AXIS           axisId,
                                                        NYCE_EVENT         eventId,
                                                        NYCE_EVENT_HANDLER handler,
                                                        void               *pUserData);



/**
 *
 * @ingroup sac_events_and_actions
 * @brief SacDeleteEventAction
 *
 * This function deletes an action from an event for an axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId      - axis identifier
 * @param [in] eventId     - SAC event identifier
 * @param [in] eventAction - event action
 *
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDeleteEventAction(SAC_AXIS         axisId,
                                                     NYCE_EVENT       eventId,
                                                     SAC_EVENT_ACTION eventAction);



/**
 *
 * @ingroup sac_events_and_actions
 * @brief SacDeleteEventEnrolment
 *
 * This function deletes an event enrolment function from an event for an axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId    - axis identifier
 * @param [in] eventId   - SAC event identifier
 * @param [in] handler   - pointer to the event enrolment function of the user
 * @param [in] pUserData - pointer to user specific data.
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDeleteEventEnrolment(SAC_AXIS           axisId,
                                                        NYCE_EVENT         eventId,
                                                        NYCE_EVENT_HANDLER handler,
                                                        void               *pUserData);



/**
 *
 * @ingroup sac_events_and_actions
 * @brief SacSynchronize
 *
 *
 * This function waits until a synchronize request has been completed.
 *
 *          How long it has to wait is specified with a time out parameter. If time out of 0 is used,
 *          SacSynchronize polls instead of waiting on completion of the request. If time out of
 *          SAC_INDEFINITE is used SacSynchronize waits indefinitely on completion of the request.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId      - axis identifier
 * @param [in] syncRequest - synchronize request
 * @param [in] timeOut     - time out [s]
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacSynchronize(SAC_AXIS         axisId,
                                               SAC_SYNC_REQUEST syncRequest,
                                               double           timeOut);



/**
 *
 * @ingroup sac_latches
 * @brief SacActivateProbe
 *
 * This function activates the probe signal detection for an axis.
 *
 *          After each trigger of the probe the probe signal detection is deactivated so if another
 *          trigger is wanted, the function SacActivateProbe must be called again.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId        - axis identifier
 * @param [in] latchFunction - one of the latch functions: SAC_LATCH_0
 *                                                      SAC_LATCH_1
 *                                                      SAC_LATCH_2
 *                                                      SAC_LATCH_3
 *
 *
 * @remarks To define the latch input use SacDefineFunctionIO with the function type SAC_LATCH_x.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacActivateProbe(SAC_AXIS        axisId,
                                                 SAC_IO_FUNCTION latchFunction);



/**
 *
 * @ingroup sac_events_and_actions
 * @brief SacDefineStartOnEvent
 *
 * This function defines a start event for an axis. If the event occurs and a motion command is pending the motion command is started.
 *
 *          If one or more start events are defined, all motion commands given after this call
 *          are started on occurrence of a defined event. If the event occurs while no
 *          motion command is pending, the event is ignored. A motion command given while the
 *          axis is moving is queued and will be executed only when the event occurs.
 *
 *          This function can be applied on all sensible SAC events.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId  - axis identifier
 * @param [in] eventId - SAC event identifier
 *
 *
 * @remarks A start event can be deleted with the function SacDeleteStartOnEvent.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefineStartOnEvent(SAC_AXIS   axisId,
                                                      NYCE_EVENT eventId);



/**
 *
 * @ingroup sac_events_and_actions
 * @brief SacDeleteStartOnEvent
 *
 * This function deletes a start event for an axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId  - axis identifier
 * @param [in] eventId - SAC event identifier
 *
 *
 * @remarks A start event can be defined with the function SacDefineStartOnEvent.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDeleteStartOnEvent(SAC_AXIS   axisId,
                                                      NYCE_EVENT eventId);



/**
 *
 * @ingroup sac_events_and_actions
 * @brief SacDefineStopOnEvent
 *
 * This function defines a stop event for an axis. If the event occurs the current motion
 *          command is terminated by stopping the axis with a specified maximum velocity and
 *          acceleration. For specifying the maximum velocity and acceleration two axis parameters
 *          are available.
 *
 *          If one or more stop events are defined each motion command is terminated on occurrence
 *          of a defined event. If a defined event occurs when no motion command is executed the
 *          event is ignored.
 *
 *          This function can be applied on all sensible SAC events.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId  - axis identifier
 * @param [in] eventId - SAC event identifier
 *
 *
 * @remarks A stop event can be deleted with the function SacDeleteStopOnEvent.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefineStopOnEvent(SAC_AXIS   axisId,
                                                     NYCE_EVENT eventId);



/**
 *
 * @ingroup sac_events_and_actions
 * @brief SacDeleteStopOnEvent
 *
 * This function deletes a stop event for an axis.
 *
 *          When the last event is deleted all pending movements are cancelled.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId  - axis identifier
 * @param [in] eventId - SAC event identifier
 *
 *
 * @remarks A stop event can be defined with the function SacDefineStopOnEvent.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDeleteStopOnEvent(SAC_AXIS   axisId,
                                                     NYCE_EVENT eventId);



/**
 *
 * @ingroup sac_output_triggers
 * @brief SacActivateOutputTrigger
 *
 * This function activates the output trigger mode for an axis for a specific event.
 *
 *          This function can be applied on all sensible SAC events. Per event only one output
 *          action can be defined.
 *
 *          The user is also responsible that no I/O conflicts occur with defining an output for this
 *          functionality. An output can also be defined with the function SacDefineFunctionIO.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId      - axis identifier
 * @param [in] ioId        - output identifier
 * @param [in] action      - action for the output (only: SET, RESET and TOGGLE applicable)
 * @param [in] eventId     - SAC event identifier
 *
 *
 * @remarks The output trigger mode is deactivated with the function SacDeactivateOutputTrigger.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacActivateOutputTrigger(SAC_AXIS           axisId,
                                                         NYCE_DIGITAL_IO_ID ioId,
                                                         NYCE_DIGOUT_ACTION action,
                                                         NYCE_EVENT         eventId);



/**
 *
 * @ingroup sac_output_triggers
 * @brief SacDeactivateOutputTrigger
 *
 * This function deactivates the output trigger mode for an axis for a specific event.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId  - axis identifier
 * @param [in] eventId - SAC event identifier
 *
 *
 * @remarks The output trigger mode is activated with the function SacActivateOutputTrigger.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDeactivateOutputTrigger(SAC_AXIS   axisId,
                                                           NYCE_EVENT eventId);



/**
 *  @ingroup sac_markers
 *  @brief Define a number of single shot markers.
 *
 *  Up to SAC_MAX_NR_OF_SINGLE_SHOT_MARKERS single shot markers can be active per axis. If more than
 *  SAC_MAX_NR_OF_SINGLE_SHOT_LOADABLE should be defined, this function should be called repeatedly.
 *
 *  The markers are queued, and handled in the queued order. When a marker is crossed, it will be removed from the queue.
 *  If two consecutive markers are defined on exactly the same position, their action will be processed in parallel.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId      Axis identifier.
 *  @param[in]  nrOfMarkers max(SAC_MAX_NR_OF_SINGLE_SHOT_LOADABLE); Number of single shot markers.
 *  @param[in]  marker      size(nrOfMarkers); Single shot marker definitions.
 *
 *
 *  @remarks    The output action is performed and the event is transmitted when a marker has been detected.
 *  @remarks    The marker definitions are removed at SacShutdown().
 *  @remarks    At most 8 markers per drive unit per firmware DSP sample can be detected.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefineSingleShotMarkers(SAC_AXIS         axisId,
                                                           uint32_t         nrOfMarkers,
                                                           const SAC_MARKER marker[]);



/**
 *  @ingroup sac_markers
 *  @brief Clear the single shot marker buffer.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  Axis identifier.
 *
 *
 *  @remarks    None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacClearSingleShotMarkerBuffer(SAC_AXIS axisId);



/**
 *  @ingroup sac_markers
 *  @brief Define a permanent marker.
 *
 *  The marker definitions remain active until they are explicitly removed.
 *  Up to SAC_MAX_NR_OF_PERMANENT_MARKERS permanent markers can be active per axis.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  Axis identifier.
 *  @param[in]  pMarker Permanent marker definition.
 *
 *
 *  @remarks    The output action is performed and the event is transmitted when the marker has been detected.
 *  @remarks    The marker definition is removed at SacShutdown().
 *  @remarks    At most 8 markers per drive unit per firmware DSP sample can be detected.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefinePermanentMarker(SAC_AXIS         axisId,
                                                         const SAC_MARKER *pMarker);



/**
 *  @ingroup sac_markers
 *  @brief Delete a permanent marker.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId      Axis identifier.
 *  @param[in]  markerId    Marker Id.
 *
 *
 *  @remarks    None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDeletePermanentMarker(SAC_AXIS   axisId,
                                                         uint32_t   markerId);



/**
 *  @ingroup sac_markers
 *  @brief Define a repetitive marker.
 *
 *  Up to SAC_MAX_NR_OF_REPETITIVE_MARKERS repetitive markers can be active per axis.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId                  Axis identifier.
 *  @param[in]  pMarker                 Repetitive marker definition.
 *  @param[in]  markerRepeatDistance    Distance between successive detection of marker.
 *
 *
 *  @remarks    The output action is performed and the event is transmitted when a marker has been detected.
 *  @remarks    The marker definition is removed at SacShutdown().
 *  @remarks    At most 8 markers per drive unit per firmware DSP sample can be detected.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefineRepetitiveMarker(SAC_AXIS         axisId,
                                                          const SAC_MARKER *pMarker,
                                                          double           markerRepeatDistance);



/**
 *  @ingroup sac_markers
 *  @brief Delete a repetitive marker.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId      Axis identifier.
 *  @param[in]  markerId    Marker Id.
 *
 *
 *  @remarks    None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDeleteRepetitiveMarker(SAC_AXIS  axisId,
                                                          uint32_t  markerId);



/**
 *  @ingroup sac_markers
 *  @brief Define the time marker.
 *
 *  The time marker is a single shot marker. It is removed when the marker is crossed.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  Axis identifier.
 *  @param[in]  pMarker Time marker definition.
 *
 *
 *  @remarks    The output action is performed and the event is transmitted when the marker has been detected.
 *  @remarks    The marker definition is removed at SacShutdown().
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefineTimeMarker(SAC_AXIS                axisId,
                                                    const SAC_TIME_MARKER   *pMarker);



/**
 *  @ingroup sac_markers
 *  @brief Delete the time marker.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  Axis identifier
 *
 *
 *  @remarks    None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDeleteTimeMarker(SAC_AXIS    axisId);


/**
 *  @ingroup sac_markers
 *  @brief  Define a number of single shot markers for an axis with an S0S90 encoder.
 *
 *  Up to SAC_MAX_NR_OF_SINGLE_SHOT_MARKERS S0S90 single shot markers can be active per axis. If more than
 *  SAC_MAX_NR_OF_SINGLE_SHOT_LOADABLE should be defined, this function should be called repeatedly.
 *
 *  The markers are queued, and handled in the queued order. When a marker is crossed, it will be removed from the queue.
 *  If two consecutive markers are defined on exactly the same position, their action will be processed in parallel.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId      Axis identifier.
 *  @param[in]  nrOfMarkers max(SAC_MAX_NR_OF_SINGLE_SHOT_LOADABLE); Number of single shot markers.
 *  @param[in]  marker      size(nrOfMarkers); Single shot marker definitions.
 *
 *  @retval     NYCE_OK on success.
 *  @retval     SAC_ERR_INVALID_AXIS_ID
 *  @retval     CFG_ERR_PARAMETER_OUT_OF_RANGE
 *  @retval     EVH_ERR_INVALID_PARAMETER
 *  @retval     SAC_ERR_INVALID_ENCODER_TYPE
 *  @retval     STD_ERR_STATE_ERROR
 *  @retval     EVH_ERR_AXIS_NOT_HOMED
 *  @retval     EVH_ERR_INVALID_SLOT_ID
 *  @retval     EVH_ERR_TOO_MANY_MARKERS_DEFINED
 *  @retval     EVH_ERR_INVALID_MARKER_POSITION
 *
 *  @remarks    The output action is performed and the event is transmitted when a marker has been detected.
 *  @remarks    The marker definitions are removed when the axis is not homed anymore.
 *  @remarks    At most 2 markers per 2 firmware DSP samples can be detected.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefineSingleShotS0S90Markers(SAC_AXIS         axisId,
                                                                uint32_t         nrOfMarkers,
                                                                const SAC_MARKER marker[]);

/**
 *  @ingroup sac_markers
 *  @brief  Retrieve the marker IDs of all pending single shot S0S90 markers.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId          Axis identifier.
 *  @param[out] pNrOfMarkers    Number of single shot markers in the queue.
 *  @param[out] markerIds       size(SAC_MAX_NR_OF_SINGLE_SHOT_MARKERS); usedSize(pNrOfMarkers); Single shot marker IDs.
 *
 *  @retval     NYCE_OK on success.
 *  @retval     SAC_ERR_INVALID_AXIS_ID
 *  @retval     SAC_ERR_INVALID_OUTPUT_ARGUMENT
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetSingleShotS0S90MarkerIds(SAC_AXIS  axisId,
                                                               uint32_t* pNrOfMarkers,
                                                               uint32_t  markerIds[]);

/**
 *  @ingroup sac_markers
 *  @brief  Clear the single shot S0S90 marker buffer.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId      Axis identifier.
 *
 *  @retval     NYCE_OK on success.
 *  @retval     SAC_ERR_INVALID_AXIS_ID
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacClearSingleShotS0S90MarkerBuffer(SAC_AXIS axisId);

/**
 *  @ingroup sac_markers
 *  @brief  Define a permanent marker for an axis with an S0S90 encoder.
 *
 *  The marker definitions remain active until they are explicitly removed.
 *  Up to SAC_MAX_NR_OF_PERMANENT_MARKERS S0S90 permanent markers can be active per axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId  Axis identifier.
 *  @param[in]  pMarker Permanent marker definition.
 *
 *  @retval     NYCE_OK on success.
 *  @retval     SAC_ERR_INVALID_AXIS_ID
 *  @retval     CFG_ERR_PARAMETER_OUT_OF_RANGE
 *  @retval     EVH_ERR_INVALID_PARAMETER
 *  @retval     SAC_ERR_INVALID_ENCODER_TYPE
 *  @retval     STD_ERR_STATE_ERROR
 *  @retval     EVH_ERR_AXIS_NOT_HOMED
 *  @retval     EVH_ERR_INVALID_SLOT_ID
 *  @retval     EVH_ERR_TOO_MANY_MARKERS_DEFINED
 *  @retval     EVH_ERR_MARKER_ID_ALREADY_DEFINED
 *  @retval     EVH_ERR_INVALID_MARKER_POSITION
 *
 *  @remarks    The output action is performed and the event is transmitted when the marker has been detected.
 *  @remarks    The marker definition is removed when the axis is not homed anymore.
 *  @remarks    At most 2 markers per 2 firmware DSP samples can be detected.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefinePermanentS0S90Marker(SAC_AXIS          axisId,
                                                              const SAC_MARKER* pMarker);

/**
 *  @ingroup sac_markers
 *  @brief  Retrieve the marker IDs of all defined permanent S0S90 markers.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId          Axis identifier.
 *  @param[out] pNrOfMarkers    Number of permanent markers in the queue.
 *  @param[out] markerIds       size(SAC_MAX_NR_OF_PERMANENT_MARKERS); usedSize(pNrOfMarkers); Permanent marker IDs.
 *
 *  @retval     NYCE_OK on success.
 *  @retval     SAC_ERR_INVALID_AXIS_ID
 *  @retval     SAC_ERR_INVALID_OUTPUT_ARGUMENT
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetPermanentS0S90MarkerIds(SAC_AXIS  axisId,
                                                              uint32_t* pNrOfMarkers,
                                                              uint32_t  markerIds[]);

/**
 *  @ingroup sac_markers
 *  @brief  Delete a permanent S0S90 marker.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId      Axis identifier.
 *  @param[in]  markerId    Marker Id.
 *
 *  @retval     NYCE_OK on success.
 *  @retval     SAC_ERR_INVALID_AXIS_ID
 *  @retval     EVH_ERR_INVALID_MARKER_ID
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDeletePermanentS0S90Marker(SAC_AXIS axisId,
                                                              uint32_t markerId);

/**
 *  @ingroup sac_markers
 *  @brief  Define a repetitive marker for an axis with an S0S90 encoder.
 *
 *  Up to SAC_MAX_NR_OF_REPETITIVE_MARKERS repetitive S0S90 markers can be active per axis.
 *
 *  State  : All states (except SAC_IDLE)
 *
 *  Trans. : -
 *
 *  @param[in]  axisId                  Axis identifier.
 *  @param[in]  pMarker                 Repetitive marker definition.
 *  @param[in]  markerRepeatDistance    Distance between successive detection of marker.
 *
 *  @retval     NYCE_OK on success.
 *  @retval     SAC_ERR_INVALID_AXIS_ID
 *  @retval     CFG_ERR_PARAMETER_OUT_OF_RANGE
 *  @retval     EVH_ERR_INVALID_PARAMETER
 *  @retval     SAC_ERR_INVALID_ENCODER_TYPE
 *  @retval     STD_ERR_STATE_ERROR
 *  @retval     EVH_ERR_AXIS_NOT_HOMED
 *  @retval     EVH_ERR_INVALID_SLOT_ID
 *  @retval     EVH_ERR_TOO_MANY_MARKERS_DEFINED
 *  @retval     EVH_ERR_MARKER_ID_ALREADY_DEFINED
 *  @retval     EVH_ERR_INVALID_MARKER_POSITION
 *  @retval     EVH_ERR_INVALID_MARKER_REPEAT_DISTANCE
 *
 *  @remarks    The output action is performed and the event is transmitted when a marker has been detected.
 *  @remarks    The marker definition is removed when the axis is not homed anymore.
 *  @remarks    At most 2 markers per 2 firmware DSP samples can be detected.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDefineRepetitiveS0S90Marker(SAC_AXIS          axisId,
                                                               const SAC_MARKER* pMarker,
                                                               double            markerRepeatDistance);

/**
 *  @ingroup sac_markers
 *  @brief  Retrieve the marker IDs of all repetitive permanent S0S90 markers.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId          Axis identifier.
 *  @param[out] pNrOfMarkers    Number of repetitive markers in the queue.
 *  @param[out] markerIds       size(SAC_MAX_NR_OF_REPETITIVE_MARKERS); usedSize(pNrOfMarkers); Repetitive marker IDs.
 *
 *  @retval     NYCE_OK on success.
 *  @retval     SAC_ERR_INVALID_AXIS_ID
 *  @retval     SAC_ERR_INVALID_OUTPUT_ARGUMENT
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetRepetitiveS0S90MarkerIds(SAC_AXIS  axisId,
                                                               uint32_t* pNrOfMarkers,
                                                               uint32_t  markerIds[]);

/**
 *  @ingroup sac_markers
 *  @brief  Delete a repetitive S0S90 marker.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId      Axis identifier.
 *  @param[in]  markerId    Marker Id.
 *
 *  @retval     NYCE_OK on success.
 *  @retval     SAC_ERR_INVALID_AXIS_ID
 *  @retval     EVH_ERR_INVALID_MARKER_ID
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDeleteRepetitiveS0S90Marker(SAC_AXIS axisId,
                                                               uint32_t markerId);

/**
 *  @ingroup sac_markers
 *  @brief  Retrieve S0S90 marker statistics and clear the S0S90 missed marker counter.
 *
 *  Missed markers are markers that are not detected by the hardware, this can occur when the axis is moving too fast.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param[in]  axisId              Axis identifier.
 *  @param[out] pS0S90MarkerStats   Pointer to S0S90 marker statistics.
 *
 *  @retval     NYCE_OK on success.
 *  @retval     SAC_ERR_INVALID_AXIS_ID
 *  @retval     SAC_ERR_INVALID_OUTPUT_ARGUMENT
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetS0S90MarkerStatistics(SAC_AXIS                     axisId,
                                                            SAC_S0S90_MARKER_STATISTICS* pS0S90MarkerStats);

/**
 *
 * @ingroup sac_latches
 * @brief SacStartMultipleLatch
 *
 * This function starts or restarts multiple latching on the input specified as latch input
 *          of the axis and for the edge specified. Restarting implies that the positions latched until
 *          now are cleared. Latching is stopped when SAC_MAX_NR_OF_LATCHED_POSITIONS have been latched,
 *          or by SacStopMultipleLatch.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId            id of the axis addressed
 * @param [in] latchFunction     one of the SAC_LATCH_x IO function
 *
 *
 *
 * @remarks The axis must be connected by the client.
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacStartMultipleLatch(SAC_AXIS        axisId,
                                                       SAC_IO_FUNCTION latchFunction);



/**
 *
 * @ingroup sac_latches
 * @brief SacStopMultipleLatch
 *
 * This function stops multiple latching. If multiple latching is not active,
 *          this function takes no effect.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId            id of the axis addressed
 * @param [in] latchFunction     one of the SAC_LATCH_x IO function
 *
 *
 *
 * @remarks The axis must be connected by the client.
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacStopMultipleLatch(SAC_AXIS        axisId,
                                                      SAC_IO_FUNCTION latchFunction);



/**
 *
 * @ingroup sac_latches
 * @brief SacGetMultipleLatchPositions
 *
 * This function gets the latched positions
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId                id of the axis addressed
 * @param [in] latchFunction         one of the SAC_LATCH_x IO function
 * @param [in] nrOfLatchedPosInArray number of positions, which can be placed in latchedPos
 *
 * @param [out] pNrOfLatches          nr of latched positions since last start
 * @param [out] latchedPos            size(nrOfLatchedPosInArray); array of latched positions
 *
 *
 * @remarks The axis must be connected by the client.
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacGetMultipleLatchPositions(SAC_AXIS          axisId,
                                                              SAC_IO_FUNCTION   latchFunction,
                                                              int32_t           nrOfLatchedPosInArray,
                                                              int32_t           *pNrOfLatches,
                                                              double            latchedPos[]);



/**
 *
 * @ingroup sac_monitor
 * @brief SacStartMonitor
 *
 * Starts the monitor function. After calling this function the value of the selected
 *          variable is put continuously on the specified monitor output of the axis controller.
 *          If the monitor is already running, first stop it before starting it again.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId       - axis identifier
 * @param [in] anOutId      - analog output identifier
 * @param [in] pMonitorPars - pointer to monitor parameters
 *
 *
 *
 * @remarks None.
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacStartMonitor(SAC_AXIS               axisId,
                                                 NYCE_ANALOG_OUT_ID     anOutId,
                                                 const SAC_MONITOR_PARS *pMonitorPars);



/**
 *
 * @ingroup sac_monitor
 * @brief SacStopMonitor
 *
 * Stops a running monitor function on a analog output. If the monitor was not running, an
 *          error is returned
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId  - axis identifier
 * @param [in] anOutId - analog output identifier
 *
 *
 *
 * @remarks None.
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacStopMonitor(SAC_AXIS           axisId,
                                                NYCE_ANALOG_OUT_ID anOutId);



/**
 *
 * @ingroup sac_monitor
 * @brief SacGetMonitors
 *
 * This function gets the number of defined monitor channels and the accompanying parameters.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId  - axis identifier
 *
 * @param [out] pNrOfDefinedMonitors - number of defined monitors
 * @param [out] monitors             - size((NYCE_MAX_NR_OF_SLOTS * 2)); array of monitor parameters.
 *
 *
 * @remarks None.
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacGetMonitors(SAC_AXIS    axisId,
                                                uint32_t    *pNrOfDefinedMonitors,
                                                SAC_MONITOR monitors[]);



/**
 *
 * @ingroup sac_udc
 * @brief SacWriteUdcParameterByIndex
 *
 * This function sets an UDC specific parameter
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId      - axis identifier
 * @param [in] udcCtrl     - UDC controller number (0..9)
 * @param [in] udcParIndex - designated parameter index
 * @param [in] dataType    - type of the pointed parameter
 * @param [in] value       - parameter value
 *
 *
 *
 * @remarks None.
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacWriteUdcParameterByIndex(SAC_AXIS       axisId,
                                                             uint32_t       udcCtrl,
                                                             uint32_t       udcParIndex,
                                                             NYCE_FW_TYPE   dataType,
                                                             double         value);



/**
 *
 * @ingroup sac_udc
 * @brief SacReadUdcParameterByIndex
 *
 * This function gets an UDC specific parameter
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId      - axis identifier
 * @param [in] udcCtrl     - UDC controller number (0..9)
 * @param [in] udcParIndex - designated parameter index
 * @param [in] dataType    - type of the pointed parameter
 *
 * @param [out] pValue - pointer to parameter value
 *
 *
 * @remarks None.
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacReadUdcParameterByIndex(SAC_AXIS        axisId,
                                                            uint32_t        udcCtrl,
                                                            uint32_t        udcParIndex,
                                                            NYCE_FW_TYPE    dataType,
                                                            double          *pValue);



/**
 *
 * @ingroup sac_udc
 * @brief SacReadUdcVariableByIndex
 *
 * This function reads a UDC specific variable.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId      - axis identifier
 * @param [in] udcCtrl     - UDC controller number (0..9)
 * @param [in] udcVarIndex - designated variable index
 * @param [in] dataType    - type of the pointed variable
 *
 * @param [out] pValue      - pointer to variable value
 *
 *
 * @remarks None.
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacReadUdcVariableByIndex(SAC_AXIS     axisId,
                                                           uint32_t     udcCtrl,
                                                           uint32_t     udcVarIndex,
                                                           NYCE_FW_TYPE dataType,
                                                           double       *pValue);



/**
 *
 * @ingroup sac_autotweak
 * @brief SacTweakDownloadTableFromFile
 *
 * This function downloads the tweak table from file to firmware.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId    - axis identifier
 * @param [in] pFileName - pointer to the name of the file
 *
 *
 * @remarks Before the tweak table is actually downloaded the table data is checked to be consistent
 *          with the current position update mode and - for modulo axis - range properties of the axis.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacTweakDownloadTableFromFile(SAC_AXIS   axisId,
                                                              const char *pFileName);



/**
 *
 * @ingroup sac_autotweak
 * @brief SacTweakLoadTableFromFlash
 *
 * This function loads the tweak table from flash to firmware.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId    - axis identifier
 *
 *
 * @remarks Before the tweak table is actually loaded the table data is checked to be consistent
 *          with the current position update mode and - for modulo axis - range properties of the axis.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacTweakLoadTableFromFlash(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_autotweak
 * @brief SacTweakSaveTableToFlash
 *
 * This function saves the currently active tweak table from firmware to flash.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId    - axis identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacTweakSaveTableToFlash(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_autotweak
 * @brief SacTweakDownloadTable
 *
 * This function downloads the tweak table from struct to firmware.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId      - axis identifier
 * @param [in] pTweakTable - pointer to tweak table
 *
 *
 * @remarks Before the tweak table is actually downloaded the table data is checked to be consistent
 *          with the current position update mode and - for modulo axis - range properties of the axis.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacTweakDownloadTable(SAC_AXIS              axisId,
                                                      const SAC_TWEAK_TABLE *pTweakTable);



/**
 *
 * @ingroup sac_autotweak
 * @brief SacTweakReadTableFromFile
 *
 * This function copies a tweak table from file to struct.
 *
 * @param [in] pFileName - pointer to the name of the file
 *
 * @param [out] pTweakTable - pointer to tweak table
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacTweakReadTableFromFile(const char      *pFileName,
                                                          SAC_TWEAK_TABLE *pTweakTable);



/**
 *
 * @ingroup sac_autotweak
 * @brief SacTweakWriteTableToFile
 *
 * This function copies a tweak table from struct to file.
 *
 * @param [in] pTweakTable - pointer to tweak table
 *
 * @param [in] pFileName - pointer to the name of the file
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacTweakWriteTableToFile(const SAC_TWEAK_TABLE *pTweakTable,
                                                         const char            *pFileName);



/**
 *
 * @ingroup sac_sensor_linearization
 * @brief SacLinLutDownloadTableFromFile
 *
 * This function downloads a linearization look-up table. It takes an xml-file as its source.
 * This file contains a table that contains the points that are used by the setpoint generator
 * to correct the scale inaccuracy.
 * If a table was previously downloaded for the same axis, the previous table will be overwritten.
 * The axis must be in the IDLE or INACTIVE state.
 *
 * State  : SAC_IDLE,
 *          SAC_INACTIVE
 *
 * Trans. : -
 *
 * @param [in] axisId    - axis identifier
 * @param [in] pFileName - pointer to the name of the file
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacLinLutDownloadTableFromFile(SAC_AXIS   axisId,
                                                               const char *pFileName);


/**
 *
 * @ingroup sac_sensor_linearization
 * @brief SacLinLutDownloadTable
 *
 * This function downloads a linearization look-up table. It takes a pointer to a
 * SAC_LIN_LUT_TABLE variable as its source. This table contains the points that are used by
 * the setpoint generator to correct the scale inaccuracy.
 * If a table was previously downloaded for the same axis, the previous table will be overwritten.
 * The axis must be in the IDLE or INACTIVE state.
 *
 * State  : SAC_IDLE,
 *          SAC_INACTIVE
 *
 * Trans. : -
 *
 * @param [in] axisId       - axis identifier
 * @param [in] pLinLutTable - pointer to lin lut table
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacLinLutDownloadTable(SAC_AXIS                axisId,
                                                       const SAC_LIN_LUT_TABLE *pLinLutTable);

/**
 *
 * @ingroup sac_sensor_linearization
 * @brief SacLinLutWriteTableToFile
 *
 * This function copies a sensor linearization look-up table from struct to file.
 *
 * @param [in] pLinLutTable - pointer to sensor linearization table
 *
 * @param [in] pFileName    - pointer to the name of the file
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacLinLutWriteTableToFile(const SAC_LIN_LUT_TABLE *pLinLutTable,
                                                          const char              *pFileName);


/**
 *
 * @ingroup sac_position_force_control
 * @brief SacPfcSetSensorConfiguration
 *
 * This function configures the force sensor of an axis.
 *
 * State  : SAC_IDLE,
 *          SAC_INACTIVE,
 *          SAC_READY
 *
 * Trans. : -
 *
 *
 * @param [in] axisId        - axis identifier
 * @param [in] pSensorConfig - pointer to force sensor configuration parameters
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacPfcSetSensorConfiguration(SAC_AXIS                    axisId,
                                                             const SAC_PFC_SENSOR_CONFIG *pSensorConfig);


/**
 *
 * @ingroup sac_position_force_control
 * @brief SacPfcGetSensorConfiguration
 *
 * This function gets the actual configuration of the force sensor of an axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 *
 * @param [in] axisId        - axis identifier
 *
 * @param [out] pSensorConfig - pointer to force sensor configuration parameters
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacPfcGetSensorConfiguration(SAC_AXIS              axisId,
                                                             SAC_PFC_SENSOR_CONFIG *pSensorConfig);


/**
 *
 * @ingroup sac_position_force_control
 * @brief SacPfcWriteForceProfile
 *
 * This function writes a number of force segments into the
 * force segment buffer of an axis.
 *
 *          The maximum number of force segments that can be written
 *          with this function is limited to SAC_MAX_NR_OF_FORCE_SEGMENTS.
 *
 * State  : SAC_READY,
 *          SAC_MOVING, all spg states (except SAC_SPG_PFC)
 *
 * Trans. : -
 *
 *
 * @param [in] axisId         - axis identifier
 * @param [in] nrOfSegments   - number of force segments
 * @param [in] forceSegment   - size(nrOfSegments); array of force segments
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacPfcWriteForceProfile(SAC_AXIS                    axisId,
                                                        uint32_t                    nrOfSegments,
                                                        const SAC_PFC_FORCE_SEGMENT forceSegment[]);


/**
 *
 * @ingroup sac_position_force_control
 * @brief SacPfcStartForceProfile
 *
 * This function start interpolating the force segments previously buffered for an axis.
 *
 * State  : SAC_READY,
 *          SAC_MOVING, all spg states (except SAC_SPG_PFC)
 *
 * Trans. : SAC_READY -> SAC_MOVING, spg state SAC_SPG_PFC
 *          SAC_MOVING, all spg states (except SAC_SPG_PFC) -> SAC_MOVING, spg state SAC_SPG_PFC
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacPfcStartForceProfile(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_miscellaneous
 * @brief SacGetVersion
 *
 * This function reads the SAC version information.
 *
 * @param [out] pSacVersion - pointer to SAC version information
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetVersion(NYCE_VERSION_TYPE *pSacVersion);



/**
 *
 * @ingroup sac_miscellaneous
 * @brief SacGetNrOfClients
 *
 * This function retrieves the number of clients which are connected to the axis.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 * @param [out] pNrOfClients - number of clients
 *
 *
 * @remarks The client that calls this function is included in the number of clients.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetNrOfClients(SAC_AXIS  axisId,
                                                  uint32_t  *pNrOfClients);


/**
*
* @ingroup sac_configuration
* @brief SacCalibrateCurrentOffsets
*
* This function calibrates the current offsets of the H-bridges on the
* NY4120 and NY4140 drive modules for the specified axis.
*
* State  : SAC_INACTIVE
*
* Trans. : -
*
* @param [in] axisId - axis identifier
*
*
* @remarks This function (re)calibrates the current offsets per axis.
*/
SAC_EXPORT NYCE_STATUS NYCE_API SacCalibrateCurrentOffsets(SAC_AXIS      axisId);



/**
 *
 * @ingroup sac_conversion
 * @brief SacGetEventEnum
 *
 * This function returns the SAC event identifier that represents the SAC event string.
 *
 * @param [in] pEventString - pointer to SAC event string
 *
 * @param [out] pEventId - pointer to SAC event identifier
 *
 *
 * @remarks
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetEventEnum(const char *pEventString,
                                                NYCE_EVENT *pEventId);



/**
 *
 * @ingroup sac_conversion
 * @brief SacGetEventString
 *
 * This function returns the SAC event string that represents the SAC event identifier.
 *
 * @param [in] eventId - SAC event identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT const char* NYCE_API SacGetEventString(NYCE_EVENT eventId);



/**
 *
 * @ingroup sac_conversion
 * @brief SacGetParIdEnum
 *
 * This function returns the parameter identifier that represents the parameter string.
 *
 * @param [in] pParIdString - pointer to parameter string
 *
 * @param [out] pParId - pointer to parameter identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetParIdEnum(const char *pParIdString,
                                                SAC_PAR_ID *pParId);



/**
 *
 * @ingroup sac_conversion
 * @brief SacGetParIdString
 *
 * This function returns the parameter string that represents the parameter identifier.
 *
 * @param [in] parId - parameter identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT const char* NYCE_API SacGetParIdString(SAC_PAR_ID parId);



/**
 *
 * @ingroup sac_conversion
 * @brief SacGetVarIdEnum
 *
 * This function returns the variable identifier that represents the variable string.
 *
 * @param [in] pVarIdString - pointer to variable string
 * @param [out] pVarId      - pointer to variable identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetVarIdEnum(const char *pVarIdString,
                                                SAC_VAR_ID *pVarId);



/**
 *
 * @ingroup sac_conversion
 * @brief SacGetVarIdString
 *
 * This function returns the variable string that represents the variable identifier.
 *
 * @param [in] varId - variable identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT const char* NYCE_API SacGetVarIdString(SAC_VAR_ID varId);



/**
 *
 * @ingroup sac_conversion
 * @brief SacGetStateEnum
 *
 * This function returns the state identifier that represents the state string.
 *
 * @param [in] pStateString - pointer to state string
 * @param [out] pStateId - pointer to state identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetStateEnum(const char *pStateString,
                                                SAC_STATE  *pStateId);



/**
 *
 * @ingroup sac_conversion
 * @brief SacGetStateString
 *
 * This function returns the state string that represents the state identifier.
 *
 * @param [in] stateId - state identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT const char* NYCE_API SacGetStateString(SAC_STATE stateId);



/**
 *
 * @ingroup sac_conversion
 * @brief SacGetSpgStateEnum
 *
 * This function returns the setpoint generator state identifier that represents the
 *          setpoint generator state string.
 *
 * @param [in] pSpgStateString - pointer to setpoint generator state string
 * @param [out] pSpgStateId - pointer to setpoint generator state identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetSpgStateEnum(const char    *pSpgStateString,
                                                   SAC_SPG_STATE *pSpgStateId);


/**
 *
 * @ingroup sac_conversion
 * @brief SacGetSpgStateString
 *
 * This function returns the setpoint generator state string that represents the setpoint
 *          generator state identifier.
 *
 * @param [in] spgStateId - setpoint generator state identifier
 *
 *
 * @remarks None.
 */
SAC_EXPORT const char* NYCE_API SacGetSpgStateString(SAC_SPG_STATE spgStateId);



/**
 *
 * @ingroup sac_conversion
 * @brief SacGetAxisName
 *
 * This function returns the name of the axis that is addressed with the axis identifier.
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 *
 * @remarks The axis must be connected by the client.
 */
SAC_EXPORT const char* NYCE_API SacGetAxisName(SAC_AXIS axisId);



/**
 *
 * @ingroup sac_commutation_correction
 * @brief SacSetCommutationCorrectionPars
 *
 * This function sets the commutation correction parameters
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 * @param [in] pCommutationCorrectionPars - pointer to commutation correction parameters
 *
 *
 * @remarks The axis must be connected by the client.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacSetCommutationCorrectionPars(SAC_AXIS                                axisId,
                                                                const SAC_COMMUTATION_CORRECTION_PARS   *pCommutationCorrectionPars);


/**
 *
 * @ingroup sac_commutation_correction
 * @brief SacGetCommutationCorrectionPars
 *
 * This function gets the commutation correction parameters
 *
 * State  : All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 *
 * @param [out] pCommutationCorrectionPars - pointer to commutation correction parameters
 *
 *
 * @remarks The axis must be connected by the client.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacGetCommutationCorrectionPars(SAC_AXIS                          axisId,
                                                                SAC_COMMUTATION_CORRECTION_PARS   *pCommutationCorrectionPars);


/**
 *
 * @ingroup sac_commutation_correction
 * @brief SacEnableCommutationCorrection
 *
 * This function enables/disables the commutation correction
 *
 * State  : if commutation correction is enabled:
 *          - SAC_READY
 *          - SAC_READY_STOPPED
 *          - SAC_FREE
 *          - SAC_FREE_STOPPED
 *          - SAC_INACTIVE
 *
 *          if commutation correction is disabled:
 *          - All states
 *
 * Trans. : -
 *
 * @param [in] axisId - axis identifier
 * @param [in] enable - TRUE = enable, FALSE = disable
 *
 *
 * @remarks The axis must be connected by the client.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacEnableCommutationCorrection(SAC_AXIS axisId,
                                                               BOOL     enable);


/**
 *
 *  @ingroup sac_variable_latch_set
 *  @brief SacAddVarToLatchSet
 *
 *  Add an axis (SAC) variable to a latch set.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param [in] axisId        Axis identifier, which must reside on the node where the latch set is located.
 *  @param [in] latchSetId    Latch set number.
 *  @param [in] varId         SAC variable to add.
 *  @param [out] pIndex       Returned index, at which this variable is added in the latch set.
 *                            Using this index, the value can be located in the returned array
 *                            of latched values returned by \ref NhiReadLatchSetValues.
 *  @remarks
 *  Adding variables is only allowed in the NHI_LATCH_SET_STATE_IDLE state.
 *  There are \ref NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE sets per node.
 *  The latchSetId must be in the range [0..NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE-1].
 *  There may be \ref NYCE_MAX_NR_OF_VARIABLES_PER_LATCH_SET variables in one latch set. When
 *  more variables are needed, you can use more latch sets using the same event condition
 *  when activating.
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacAddVarToLatchSet(SAC_AXIS    axisId,
                                                    uint32_t    latchSetId,
                                                    SAC_VAR_ID  varId,
                                                    uint32_t   *pIndex );


/**
 *
 *  @ingroup sac_variable_latch_set
 *  @brief SacActivateLatchSet
 *
 *  Activates the latch set using a node event.
 *  The state will become NHI_LATCH_SET_STATE_ARMED. When the given event is triggered,
 *  the variables are all latched at once after which the state will be NHI_LATCH_SET_STATE_READY.
 *
 *  State  : All states
 *
 *  Trans. : -
 *
 *  @param [in] axisId            Axis identifier, which must reside on the node where the latch set is located.
 *  @param [in] latchSetId        Latch set number.
 *  @param [in] eventId           Event identifier, which must be an axis (SAC) event.
 *
 *  @remarks
 *  The latch set must be in the NHI_LATCH_SET_STATE_IDLE when this function is called.
 *  There of \ref NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE sets per node.
 *  The latchSetId must be in the range [0..NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE-1]
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacActivateLatchSet(SAC_AXIS    axisId,
                                                    uint32_t    latchSetId,
                                                    NYCE_EVENT  eventId );




/** @} */




/**
 * @defgroup sacdl Single Axis Control Drivelink (SACDL)
 *
 * The SAC library contains all functionality needed to control a single axis on an IndraDrive.
 *
 * @{
 */

/************************************************************************************************
 *                                                                                              *
 *                                    DRIVE LINK                                                *
 *                                                                                              *
 ************************************************************************************************/


/* Parameters ----------------------------------------------------------------------------------*/
/**
 * @defgroup sac_dl_parameters Parameters
 *
 * For IndraDrives, with motors without encoder memory, \ref SacDLLoadMotorParametersFromFile
 * writes the motor parameters from an xml-file on the host to the working memory of the
 * IndraDrive.
 * \ref SacDLSaveMotorParametersToFlash saves the motor parameters into the flash memory
 * of the IndraDrive.
 * \ref SacDLSaveMotorParametersToFile saves the motor parameters from the working memory
 * of the IndraDrive to an xml-file on the host.
 */

/* Digital I/O ---------------------------------------------------------------------------------*/
/**
 * @defgroup sac_dl_digital_io Digital I/O
 */

/* Analog I/O ----------------------------------------------------------------------------------*/
/**
 * @defgroup sac_dl_analog_io Analog I/O
 */

/* Position Switch------------------------------------------------------------------------------*/
/**
 * @defgroup sac_dl_position_switch Position Switch
 */

/* Sercos Device Info---------------------------------------------------------------------------*/
/**
* @defgroup sac_dl_sercos_device_info Sercos Device Info
*/

/**
 * @ingroup sac_dl_position_switch
 */
typedef struct sac_dl_pos_switch_pars
{
    double        switchOnPosition;         /* switch ON position [pu] */
    double        switchOffPosition;        /* switch OFF position [pu] */

} SAC_DL_POS_SWITCH_PARS;



/**
* @ingroup sac_dl_sercos_device_info
*/
typedef struct sac_dl_sercos_device_info
{
    NYCE_SERCOS_DEVICE_TYPE     deviceType;                                     /**<  Device type */
    char                        firmwareVersion[ NYCE_MAX_STRING_LENGTH ];      /**<  Firmware version string of device*/

    char                        controlSectionType[ NYCE_MAX_STRING_LENGTH ];   /**<  Type name of control section */
    uint32_t                    controlSectionSerialNumber;                     /**<  Serial number of control section */
    uint32_t                    controlSectionVersion;                          /**<  Version of control section */

    char                        powerSectionType[ NYCE_MAX_STRING_LENGTH ];     /**<  Type name of power section */
    uint32_t                    powerSectionSerialNumber;                       /**<  Serial number of power section */
    uint32_t                    powerSectionVersion;                            /**<  Version of power section */
} SAC_DL_SERCOS_DEVICE_INFO;



/**
 *
 * @ingroup sac_dl_digital_io
 * @brief SacDLGetNrOfDigitalInputs
 *
 * This function returns the number of digital inputs,
 * available on the IndraDrive axis.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId         - id of axis addressed
 * @param [out] pNrOfDigInputs - pointer to number of digital inputs
 *
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacDLGetNrOfDigitalInputs(SAC_AXIS axisId,
                                                           uint32_t *pNrOfDigInputs);

/**
 *
 * @ingroup sac_dl_digital_io
 * @brief SacDLGetNrOfDigitalOutputs
 *
 * This function returns the number of digital outputs,
 * available on the IndraDrive axis.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId          - id of axis addressed
 * @param [out] pNrOfDigOutputs - pointer to number of digital outputs
 *
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacDLGetNrOfDigitalOutputs(SAC_AXIS axisId,
                                                            uint32_t *pNrOfDigOutputs);


/**
 *
 * @ingroup sac_dl_analog_io
 * @brief SacDLGetNrOfAnalogInputs
 *
 * This function returns the number of analog inputs,
 * available on the IndraDrive axis.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId        - id of axis addressed
 * @param [out] pNrOfAnInputs - pointer to number of analog inputs
 *
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacDLGetNrOfAnalogInputs(SAC_AXIS axisId,
                                                          uint32_t *pNrOfAnInputs);

/**
 *
 * @ingroup sac_dl_analog_io
 * @brief SacDLGetNrOfAnalogOutputs
 *
 * This function returns the number of analog outputs,
 * available on the IndraDrive axis.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId         - id of axis addressed
 * @param [out] pNrOfAnOutputs - pointer to number of analog outputs
 *
 */
SAC_EXPORT  NYCE_STATUS NYCE_API SacDLGetNrOfAnalogOutputs(SAC_AXIS axisId,
                                                           uint32_t *pNrOfAnOutputs);

/**
 *
 * @ingroup sac_dl_digital_io
 * @brief SacDLDefineDigitalIOActiveState
 *
 * This function defines the active state of a digital input or
 * output on the IndraDrive axis.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId         - id of axis addressed
 * @param [in]  ioNr           - number of the digital I/O
 * @param [in]  activeState    - new active state of the I/O
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLDefineDigitalIOActiveState( SAC_AXIS           axisId,
                                                                 NYCE_DIG_IO_NR     ioNr,
                                                                 NYCE_ACTIVE_STATE  activeState );
/**
 *
 * @ingroup sac_dl_digital_io
 * @brief SacDLReadDigitalIORegister
 *
 * This function returns the value of the digital I/O status
 * register of the I/O available on the IndraDrive axis.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId         - id of axis addressed
 * @param [out] pDigIOStatus   - pointer to status register
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLReadDigitalIORegister( SAC_AXIS axisId,
                                                            uint32_t *pDigIOStatus );

/**
 *
 * @ingroup sac_dl_digital_io
 * @brief SacDLReadDigitalIO
 *
 * This function returns the status of a digital I/O
 * on the IndraDrive axis.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId         - id of axis addressed
 * @param [in]  ioNr           - number of the digital I/O
 * @param [out] pDigIOStatus   - pointer to I/O status value
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLReadDigitalIO(     SAC_AXIS       axisId,
                                                        NYCE_DIG_IO_NR ioNr,
                                                        uint32_t       *pDigIOStatus );

/**
 *
 * @ingroup sac_dl_digital_io
 * @brief SacDLClearDigitalOutput
 *
 * This function clears a digital output on the IndraDrive axis.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId         - id of axis addressed
 * @param [in]  ioNr           - number of the digital output
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLClearDigitalOutput(    SAC_AXIS        axisId,
                                                            NYCE_DIG_IO_NR  ioNr);

/**
 *
 * @ingroup sac_dl_digital_io
 * @brief SacDLSetDigitalOutput
 *
 * This function sets a digital output on the IndraDrive axis.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId         - id of axis addressed
 * @param [in]  ioNr           - number of the digital output
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLSetDigitalOutput(  SAC_AXIS        axisId,
                                                        NYCE_DIG_IO_NR  ioNr);

/**
 *
 * @ingroup sac_dl_digital_io
 * @brief SacDLToggleDigitalOutput
 *
 * This function toggles a digital output on the IndraDrive
 * axis.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId         - id of axis addressed
 * @param [in]  ioNr           - number of the digital output
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLToggleDigitalOutput(  SAC_AXIS        axisId,
                                                           NYCE_DIG_IO_NR  ioNr);

/**
 *
 * @ingroup sac_dl_analog_io
 * @brief SacDLWriteAnalogOutput
 *
 * This function set an analog output on the IndraDrive axis to
 * a new value.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId         - id of axis addressed
 * @param [in]  anOutNr        - number of analog output
 * @param [in]  anOutValue     - value of the analog output
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLWriteAnalogOutput( SAC_AXIS  axisId,
                                                        uint32_t  anOutNr,
                                                        double    anOutValue);

/**
 * @ingroup sac_dl_position_switch
 * @brief SacDLDefinePositionSwitchRange
 *
 * This function defines the position switch on and off positions for the IndraDrive axis.
 *
 * State  : SAC_IDLE, axis must be configured on IndraDrive
 *          SAC_INACTIVE
 *
 * Trans. : -
 *
 * @param [in]  axisId            - id of the axis addressed
 * @param [in]  pPosSwPars        - pointer to the structure for the position switch parameters
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLDefinePositionSwitchRange(SAC_AXIS                     axisId,
                                                               const SAC_DL_POS_SWITCH_PARS *pPosSwPars);

/**
 * @ingroup sac_dl_position_switch
 * @brief SacDLDeletePositionSwitchRange
 *
 * This function deletes the position switch on and off positions for the IndraDrive axis.
 *
 * State  : SAC_IDLE, axis must be configured on IndraDrive
 *          SAC_INACTIVE
 *
 * Trans. : -
 *
 * @param [in]  axisId            - id of the axis addressed
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLDeletePositionSwitchRange(SAC_AXIS axisId);


/**
 * @ingroup sac_dl_parameters
 * @brief SacDLLoadDefaultParametersFromEncoder
 *
 * This function loads the parameters from the encoder memory to
 * the IndraDrive (if supported) and saves them as NYCe4000
 * parameters.
 *
 * State  : SAC_IDLE, axis must be configured on IndraDrive
 *          SAC_INACTIVE
 *
 * Trans. : -
 *
 * @param [in]  axisId            - id of the axis addressed
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLLoadDefaultParametersFromEncoder(SAC_AXIS axisId);


/**
 * @ingroup sac_dl_parameters
 * @brief SacDLSaveMotorParametersToFlash
 *
 * This function saves the motor parameters in the flash memory of the IndraDrive
 * for the IndraDrive axis.
 *
 * State  : SAC_IDLE, axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId            - id of the axis addressed
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLSaveMotorParametersToFlash(SAC_AXIS axisId);


/**
 * @ingroup sac_dl_parameters
 * @brief SacDLLoadMotorParametersFromFile
 *
 * This function writes the motor parameters from the specified motor parameters
 * xml file to the working memory of the IndraDrive for the IndraDrive axis.
 *
 * State  : SAC_IDLE, axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId    - id of the axis addressed
 * @param [in]  pFileName - pointer to the name of the file
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLLoadMotorParametersFromFile(SAC_AXIS   axisId,
                                                                 const char *pFileName);



/**
 * @ingroup sac_dl_parameters
 * @brief SacDLSaveMotorParametersToFile
 *
 * This function writes the motor parameters from the working memory of the
 * IndraDrive to the specified motor parameters xml file for the IndraDrive axis.
 *
 * State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
 *
 * Trans. : -
 *
 * @param [in]  axisId    - id of the axis addressed
 *
 * @param [in] pFileName - pointer to the name of the file
 *
 */
SAC_EXPORT NYCE_STATUS NYCE_API SacDLSaveMotorParametersToFile(SAC_AXIS   axisId,
                                                               const char *pFileName);



/**
* @ingroup sac_dl_sercos_device_info
* @brief SacDLGetSercosDeviceInfo
*
* This function retrieves device specific information from the Sercos device of the axis.
*
* State  : All states; in SAC_IDLE state the axis must be configured on IndraDrive
*
*
* Trans. : -
*
* @param [in]  axisId    - id of the axis addressed
*
* @param [out] pSercosDeviceInfo - pointer to the structure to store the Sercos device info
*
*/
SAC_EXPORT NYCE_STATUS NYCE_API SacDLGetSercosDeviceInfo(SAC_AXIS                   axisId,
                                                         SAC_DL_SERCOS_DEVICE_INFO  *pSercosDeviceInfo);



/************************************************************************************************
 *                                  END OF DRIVE LINK                                           *
 ************************************************************************************************/




#ifdef __cplusplus
    }
#endif

/** @} */

#endif /* __SACAPI_H__ */
