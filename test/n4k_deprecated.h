/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2011-2012
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  %full_filespec: n4k_deprecated.h`12.1.10:incl:1 %
 */
/**
 *  @file
 *  @brief  This file contains all deprecated definitions which support will be removed in a later version of the software.
 *
 */

#ifndef __N4K_DEPRECATED_H__
#define __N4K_DEPRECATED_H__

#ifndef N4K_REMOVE_DEPRECATED_SYMBOLS

/**
 *  @defgroup deprecated_symbols Deprecated symbols (legacy support).
 *
 *  Define N4K_REMOVE_DEPRECATED_SYMBOLS to remove all deprecated symbols.
 * @{
 */

/** Following sqc function is deprecated since 40V00 */
/** sqcapi.h */
#define SqcFlushCatchedEvents SqcFlushEvents

/** nycetypes.h */
/** This definition is deprecated since V2.1; use NYCE_NO_UNIT instead. */
#define NHI_NO_UNIT   NYCE_NO_UNIT
/** This definition is deprecated since V2.1; use NYCE_NY4120 instead. */
#define NHI_NY4120    NYCE_NY4120
/** This definition is deprecated since V2.1; use NYCE_NY4130 instead. */
#define NHI_NY4130    NYCE_NY4130
/** This definition is deprecated since V2.1; use NYCE_NY4140 instead. */
#define NHI_NY4140    NYCE_NY4140
/** This definition is deprecated since V2.1; use NYCE_NY4150 instead. */
#define NHI_NY4150    NYCE_NY4150
/** This definition is deprecated since V2.1; use NYCE_LAST_UNIT instead. */
#define NHI_LAST_UNIT NYCE_LAST_UNIT
/** This definition is deprecated since V2.1; use NYCE_UNIT_TYPE instead. */
#define NHI_UNIT_TYPE NYCE_UNIT_TYPE

/** This definition is deprecated since V2.1; use NYCE_NY4110 instead. */
#define NHI_NY4110          NYCE_NY4110
/** This definition is deprecated since V2.1; use NYCE_LAST_MCU_UNIT instead. */
#define NHI_LAST_MCU_UNIT   NYCE_LAST_MCU_UNIT
/** This definition is deprecated since V2.1; use NYCE_MCU_UNIT_TYPE instead. */
#define NHI_MCU_UNIT_TYPE   NYCE_MCU_UNIT_TYPE

/** This definition is deprecated since 40V00; use NYCE_NO_EXPANSION_MODULE instead. */
#define NHI_NO_EXPANSION_MODULE   NYCE_NO_EXPANSION_MODULE
/** This definition is deprecated since 40V00; use NYCE_NY4199 instead. */
#define NHI_NY4199                NYCE_NY4199
/** This definition is deprecated since 40V00; use NYCE_EXPANSION_MODULE_TYPE instead. */
#define NHI_EXPANSION_MODULE_TYPE NYCE_EXPANSION_MODULE_TYPE

/** Following trace definitions are deprecated since 40V00 */
/** nyceapi.h */
#define NhiDeleteVariableFromTrace NyceDeleteVariableFromTrace
#define NhiDeleteVariableFromSet   NyceDeleteVariableFromSet
#define SacDeleteVariableFromTrace NyceDeleteVariableFromTrace
#define SacDeleteVariableFromSet   NyceDeleteVariableFromSet

/** nycedefs.h */
#define NYCE_MAX_VARS_PER_NODE           NYCE_TRACE_MAX_NR_OF_VARS_PER_NODE 
#define NYCE_TRACE_MAX_VARS_PER_NODE     NYCE_TRACE_MAX_NR_OF_VARS_PER_NODE
#define NYCE_TRACE_MAX_VARS              NYCE_TRACE_MAX_NR_OF_VARS
#define NYCE_MAX_HSD_TRACE_VARS_PER_AXIS NYCE_TRACE_MAX_NR_OF_HSD_VARS_PER_AXIS

/** Following definitions are deprecated since 40V00 due to change of: 
 *    safety input / safety mode to service input / service mode, and 
 *    emergency input to stop axes input
 */
/** n4k_basictypes.h */
#define FWM_EDHSAFETY FWM_EDHSERVICE

/** nhiparameters.h */
#define NHI_PAR_NODE_SAFETY_POLARITY    NHI_PAR_NODE_SERVICE_POLARITY
#define NHI_PAR_NODE_EMERGENCY_POLARITY NHI_PAR_NODE_STOP_AXES_POLARITY 

/** nhivariables.h */
#define NHI_VAR_SAFETY_INPUT    NHI_VAR_SERVICE_INPUT
#define NHI_VAR_EMERGENCY_INPUT NHI_VAR_STOP_AXES_INPUT

/** sacparameters.h */
#define SAC_PAR_AX_ERR_EMERGENCY_STOP_INPUT SAC_PAR_AX_ERR_STOP_AXES_INPUT

/** sacvariables.h */
#define SAC_VAR_SAFETY_MODE_ACTIVE SAC_VAR_SERVICE_MODE_ACTIVE

/** nycedefs.h */
#define EDH_ERR_SAFETY_MODE_ACTIVE                  EDH_ERR_SERVICE_MODE_ACTIVE    
#define CTR_ERR_SAFETY_MODE_ACTIVE                  CTR_ERR_SERVICE_MODE_ACTIVE      
#define SAC_AX_ERR_SAFETY_INPUT                     SAC_AX_ERR_SERVICE_INPUT
#define SAC_AX_ERR_EMERGENCY_STOP_INPUT             SAC_AX_ERR_STOP_AXES_INPUT                
#define SAC_AX_ERR_MAX_SAFETY_VELOCITY_EXCEEDED     SAC_AX_ERR_MAX_SERVICE_VELOCITY_EXCEEDED    
#define SAC_AX_ERR_MAX_SAFETY_ACCELERATION_EXCEEDED SAC_AX_ERR_MAX_SERVICE_ACCELERATION_EXCEEDED  
#define SAC_AX_ERR_MAX_SAFETY_JERK_EXCEEDED         SAC_AX_ERR_MAX_SERVICE_JERK_EXCEEDED        
#define NHI_EV_SAFETY_INPUT_CHANGED                 NHI_EV_SERVICE_INPUT_CHANGED
#define NHI_EV_EMERGENCY_INPUT_CHANGED              NHI_EV_STOP_AXES_INPUT_CHANGED

/** sactypes.h */
#define safetyInputErrorHandler        serviceInputErrorHandler  
#define safetyVelocityErrorHandler     serviceVelocityErrorHandler 
#define safetyAccelerationErrorHandler serviceAccelerationErrorHandler
#define safetyJerkErrorHandler         serviceJerkErrorHandler
#define SAC_SAFETY_MODE_OPERATION_PARS SAC_SERVICE_MODE_OPERATION_PARS

/** sacapi.h */
#define SacSetSafetyModeOperation SacSetServiceModeOperation
#define SacEnterSafetyMode        SacEnterServiceMode 
#define SacExitSafetyMode         SacExitServiceMode

/** simapi.h */
#define SimSetSafetyInput    SimSetServiceInput
#define SimSetEmergencyInput SimSetStopAxesInput

/** Following definitions are deprecated since 42V00 due to change of: 
 *    I2T protection to drive I2t protection 
 *    netservice to n4knetservice
 *    simservice to n4ksimservice
 */
/** sacparameters.h */
#define SAC_PAR_MAX_I2T_LEVEL                 SAC_PAR_DRIVE_MAX_I2T_LEVEL
#define SAC_PAR_AX_ERR_MAX_I2T_LEVEL_EXCEEDED SAC_PAR_AX_ERR_DRIVE_MAX_I2T_LEVEL_EXCEEDED

/** nycedefs.h */
#define SAC_AX_ERR_MAX_I2T_LEVEL_EXCEEDED SAC_AX_ERR_DRIVE_MAX_I2T_LEVEL_EXCEEDED
#define NCS_ERR_NETSERVICE_NOT_AVAILABLE  NCS_ERR_N4KNETSERVICE_NOT_AVAILABLE
#define NCS_ERR_SIMSERVICE_NOT_AVAILABLE  NCS_ERR_N4KSIMSERVICE_NOT_AVAILABLE
#define NCS_ERR_WRONG_NETSERVICE_VERSION  NCS_ERR_WRONG_N4KNETSERVICE_VERSION
#define NCS_ERR_WRONG_SIMSERVICE_VERSION  NCS_ERR_WRONG_N4KSIMSERVICE_VERSION
#define NNI_ERR_SIMSERVICE_NOT_AVAILABLE  NNI_ERR_N4KSIMSERVICE_NOT_AVAILABLE

/** sacvariables.h */
#define SAC_VAR_I2T_CRITERION_VALUE SAC_VAR_DRIVE_I2T_CRITERION_VALUE

/** sactypes.h */
#define maxI2T driveMaxI2t

/** Following definition is deprecated since 42V00 due to change of: 
 *    SAC_CLOSED_LOOP_STEPPER_AXIS in SAC_SENSING_STEPPER_AXIS 
 */
/** sactypes.h */
#define SAC_CLOSED_LOOP_STEPPER_AXIS SAC_SENSING_STEPPER_AXIS

/** Following lms definitions are deprecated since 40V00 */
/** saclmstypes.h */
#define SACLMSMAXPROFILEPOINTS SAC_LMS_MAX_PROFILE_POINTS
#define SENSOR_BITS            SAC_LMS_SENSOR_BITS
#define SENSOR_STATUS          SAC_LMS_SENSOR_BITS_UNION


/** Following seq functions are deprecated since 40V00 */
/** seqapi.h */
#define SeqGetData(n, a, s, l, d)  SeqGetDataBuffer(n, a, s, l, 1, d)
#define SeqSetData(n, a, s, d)     SeqSetDataBuffer(n, a, s, 4, 1, d)

/** Following seq definitions are deprecated since 42V04 due to change of:
 *  SEQ_DBG_VAR structure elements
 *  SEQ_ACTIVITY_INFO structure elements
 *  SEQ_SCHEDULE_INFO structure elements
 */
/** seqapi.h */
#define iIndividualPeriod individualPeriod
#define iAreaNr           areaNr
#define iCpuTime          cpuTime
#define iWaitCounter      waitCounter
#define iEventCounter     eventCounter
#define iEventData        eventData
#define iNrActiveSeq      nrOfActiveSeq
#define uiDefaultPeriod   defaultPeriod

/** sqcapi.h */
#define pvData    pData
#define ulTypeLen typeLen
#define ulNrItems nrOfItems

/** Following definition is deprecated since 46V04 due to change of:
 *    EnDat2.2 and MSM specific encoder errors to general encoder errors
 */
/** sacparameters.h */
#define SAC_PAR_AX_ERR_MSM_BATTERY_ALARM SAC_PAR_AX_ERR_ENCODER_BATTERY_WARNING

/** nycedefs.h */
#define SAC_AX_ERR_MSM_BATTERY_ALARM SAC_AX_ERR_ENCODER_BATTERY_WARNING

/** sactypes.h */
#define SAC_ENDAT_22_LIGHT_UNIT_FAILURE            SAC_ENCODER_LIGHT_UNIT_FAILURE
#define SAC_ENDAT_22_SIGNAL_AMPLITUDE_TOO_LOW      SAC_ENCODER_SIGNAL_AMPLITUDE_TOO_LOW
#define SAC_ENDAT_22_POSITION_CALCULATION_ERROR    SAC_ENCODER_POSITION_CALCULATION_ERROR
#define SAC_ENDAT_22_OVER_VOLTAGE                  SAC_ENCODER_OVER_VOLTAGE
#define SAC_ENDAT_22_UNDER_VOLTAGE                 SAC_ENCODER_UNDER_VOLTAGE
#define SAC_ENDAT_22_EXCESSIVE_CURRENT_CONSUMPTION SAC_ENCODER_EXCESSIVE_CURRENT_CONSUMPTION
#define SAC_ENDAT_22_SYSTEM_DOWN                   SAC_ENCODER_BATTERY_ALARM

/**
 * @}
 */

#endif

#endif

