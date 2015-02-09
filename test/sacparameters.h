/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2011
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: SAC
 *  %full_filespec: sacparameters.h`52:incl:1 %
 */
/**
 *  @file
 *  @brief  All parameters for an axis.
 */

#ifndef __SACPARAMETERS_H__
#define __SACPARAMETERS_H__

#include "n4k_deprecated.h" //lint !e451
#include "n4k_basictypes.h"

/**
 *  @addtogroup sac_parameters
 *  @{
 */

/** Axis parameter ID type. */
typedef uint32_t SAC_PAR_ID;

/**
 *  @defgroup def define parameters
 *  @{
 */

/**
 *  @brief  output of the position controller
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @minvalue       1.0e-12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0e+9
 *  @xmlPath        definitions/SAC_PAR_RES_CONTROLLER_OUT
 *  @_adminPath     definitions.resControllerOut
 *  @readOnly       FALSE
 */
#define SAC_PAR_RES_CONTROLLER_OUT                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  ramp of position controller output in SAC_FREE state
 *
 *  @datatype       double
 *  @unit           [cout/s]
 *  @firmwareDim    NormalizedPerNodeSample
 *  @hostDim        CoutPerSec
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0e+10
 *  @xmlPath        definitions/SAC_PAR_OPEN_LOOP_RAMP
 *  @_adminPath     definitions.openLoopRamp
 *  @readOnly       FALSE
 */
#define SAC_PAR_OPEN_LOOP_RAMP                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  position controller output in SAC_FREE state
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        definitions/SAC_PAR_OPEN_LOOP_VALUE
 *  @_adminPath     definitions.openLoopValue
 *  @readOnly       FALSE
 */
#define SAC_PAR_OPEN_LOOP_VALUE                       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  position controller output in SAC_FREE_STOPPED state
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        definitions/SAC_PAR_OPEN_LOOP_SAFE_VALUE
 *  @_adminPath     definitions.openLoopSafeValue
 *  @readOnly       FALSE
 */
#define SAC_PAR_OPEN_LOOP_SAFE_VALUE                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @}
 */

/**
 *  @defgroup stepper stepper parameters
 *  @{
 */

/**
 *  @brief  stepper motor hold current
 *
 *  @datatype       double
 *  @unit           [A]
 *  @firmwareDim    Normalized
 *  @hostDim        Amp
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/stepperPars/SAC_PAR_STEPPER_HOLD_CURRENT
 *  @_adminPath     motion.stepperPars.holdCurrent
 *  @readOnly       FALSE
 */
#define SAC_PAR_STEPPER_HOLD_CURRENT                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  stepper motor acceleration current
 *
 *  @datatype       double
 *  @unit           [A]
 *  @firmwareDim    Normalized
 *  @hostDim        Amp
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/stepperPars/SAC_PAR_STEPPER_ACCELERATION_CURRENT
 *  @_adminPath     motion.stepperPars.accCurrent
 *  @readOnly       FALSE
 */
#define SAC_PAR_STEPPER_ACCELERATION_CURRENT          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  stepper motor deceleration current
 *
 *  @datatype       double
 *  @unit           [A]
 *  @firmwareDim    Normalized
 *  @hostDim        Amp
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/stepperPars/SAC_PAR_STEPPER_DECELERATION_CURRENT
 *  @_adminPath     motion.stepperPars.decCurrent
 *  @readOnly       FALSE
 */
#define SAC_PAR_STEPPER_DECELERATION_CURRENT          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  stepper motor constant velocity current
 *
 *  @datatype       double
 *  @unit           [A]
 *  @firmwareDim    Normalized
 *  @hostDim        Amp
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/stepperPars/SAC_PAR_STEPPER_CONSTANT_VEL_CURRENT
 *  @_adminPath     motion.stepperPars.constVelCurrent
 *  @readOnly       FALSE
 */
#define SAC_PAR_STEPPER_CONSTANT_VEL_CURRENT          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @}
 */

/**
 *  @defgroup pid pid parameters
 *  @{
 */

/**
 *  @brief  IndraDrive load inertia
 *
 *  @datatype       double
 *  @unit           [kg or kgm^2]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/SAC_PAR_INDRA_LOAD_INERTIA
 *  @_adminPath     controller.positionVelocityLoop.indraLoadInertia
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_LOAD_INERTIA                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  type of controller
 *
 *  @datatype       SAC_CONTROLLER_TYPE
 *  @defaultvalue   SAC_CTR_PVL_ON_DRV
 *  @xmlPath        controller/positionVelocityLoop/SAC_PAR_CONTROLLER_TYPE
 *  @_adminPath     controller.positionVelocityLoop.controllerType
 *  @readOnly       FALSE
 */
#define SAC_PAR_CONTROLLER_TYPE                       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  maximum positive saturation level of the position controller output
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_SAT_LEVEL
 *  @_adminPath     controller.positionVelocityLoop.pidPars.saturationLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_SAT_LEVEL                             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  maximum negative saturation level of the position controller output, only used when asymmetric saturation level is enabled
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       -1.0
 *  @maxvalue       0.0
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_SAT_MIN_LEVEL
 *  @_adminPath     controller.positionVelocityLoop.pidPars.saturationMinLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_SAT_MIN_LEVEL                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  asymmetric saturation level
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_ASYMMETRIC_SATURATION
 *  @_adminPath     controller.positionVelocityLoop.pidPars.asymmetricSaturation
 *  @readOnly       FALSE
 */
#define SAC_PAR_ASYMMETRIC_SATURATION                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRAXC<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @}
 */

/**
 *  @addtogroup pid
 *  @{
 */

/**
 *  @brief  proportional gain of position loop
 *
 *  @datatype       double
 *  @unit           [cout/pu]
 *  @firmwareDim    NormalizedPerInc
 *  @hostDim        CoutPerPu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_KP
 *  @_adminPath     controller.positionVelocityLoop.pidPars.parKp
 *  @readOnly       FALSE
 */
#define SAC_PAR_KP                                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_PER_INC<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  derivative gain of position loop
 *
 *  @datatype       double
 *  @unit           [cout*s/pu]
 *  @firmwareDim    NormalizedPerInc
 *  @hostDim        CoutPerPu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_KV
 *  @_adminPath     controller.positionVelocityLoop.pidPars.parKv
 *  @readOnly       FALSE
 */
#define SAC_PAR_KV                                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_PER_INC<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  integral gain of position loop
 *
 *  @datatype       double
 *  @unit           [rad/s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_KI
 *  @_adminPath     controller.positionVelocityLoop.pidPars.parKi
 *  @readOnly       FALSE
 */
#define SAC_PAR_KI                                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  velocity feedforward gain of position loop
 *
 *  @datatype       double
 *  @unit           [cout*s/pu]
 *  @firmwareDim    NormalizedPerInc
 *  @hostDim        CoutPerPu
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_KFV
 *  @_adminPath     controller.positionVelocityLoop.pidPars.parKfv
 *  @readOnly       FALSE
 */
#define SAC_PAR_KFV                                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_PER_INC<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  acceleration feedforward gain of position loop
 *
 *  @datatype       double
 *  @unit           [cout*s^2/pu]
 *  @firmwareDim    NormalizedPerInc
 *  @hostDim        CoutPerPu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_KFA
 *  @_adminPath     controller.positionVelocityLoop.pidPars.parKfa
 *  @readOnly       FALSE
 */
#define SAC_PAR_KFA                                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_PER_INC<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  jerk feedforward gain of position loop
 *
 *  @datatype       double
 *  @unit           [cout*s^3/pu]
 *  @firmwareDim    NormalizedPerInc
 *  @hostDim        CoutPerPu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_KFJ
 *  @_adminPath     controller.positionVelocityLoop.pidPars.parKfj
 *  @readOnly       FALSE
 */
#define SAC_PAR_KFJ                                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_PER_INC<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  snap feedforward gain of position loop
 *
 *  @datatype       double
 *  @unit           [cout*s^4/pu]
 *  @firmwareDim    NormalizedPerInc
 *  @hostDim        CoutPerPu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/SAC_PAR_KFSNAP
 *  @_adminPath     controller.positionVelocityLoop.pidKfSnap
 *  @readOnly       FALSE
 */
#define SAC_PAR_KFSNAP                                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_PER_INC<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  static feedforward gain of position loop
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_KFST
 *  @_adminPath     controller.positionVelocityLoop.pidPars.parKfst
 *  @readOnly       FALSE
 */
#define SAC_PAR_KFST                                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  coulomb friction feedforward gain of position loop
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_KFC
 *  @_adminPath     controller.positionVelocityLoop.pidPars.parKfc
 *  @readOnly       FALSE
 */
#define SAC_PAR_KFC                                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  velocity estimation method in position loop
 *
 *  @datatype       SAC_VELOCITY_ESTIMATION_METHOD
 *  @defaultvalue   SAC_VEL_EST_LAGRANGE2
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_VELOCITY_ESTIMATION_METHOD
 *  @_adminPath     controller.positionVelocityLoop.pidPars.velocityEstimationMethod
 *  @readOnly       FALSE
 */
#define SAC_PAR_VELOCITY_ESTIMATION_METHOD            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  nr of samples used for averaging if velocity estimation method is derivative sample
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @minvalue       0
 *  @maxvalue       16
 *  @defaultvalue   1
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_NR_OF_SAMPLES
 *  @_adminPath     controller.positionVelocityLoop.pidPars.nrOfSamples
 *  @readOnly       FALSE
 */
#define SAC_PAR_NR_OF_SAMPLES                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  below threshold velocity, integrator of the position loop is enabled
 *
 *  @datatype       double
 *  @unit           [pu/s]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   SAC_INDEFINITE
 *  @infAllowed
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_THRESHOLD_VELOCITY
 *  @_adminPath     controller.positionVelocityLoop.pidPars.thresholdVelocity
 *  @readOnly       FALSE
 */
#define SAC_PAR_THRESHOLD_VELOCITY                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  Integrator behavior above threshold velocity
 *
 *  @datatype       SAC_INTEGRATOR_SWITCH_OFF_MODE
 *  @defaultvalue   SAC_INTEGRATOR_RESET_AND_DISABLE
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_INTEGRATOR_SWITCH_OFF_MODE
 *  @_adminPath     controller.positionVelocityLoop.pidPars.integratorSwitchOffMode
 *  @readOnly       FALSE
 */
#define SAC_PAR_INTEGRATOR_SWITCH_OFF_MODE            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  maximum level of the integrator of the position loop
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_MAX_INTEGRATOR_LEVEL
 *  @_adminPath     controller.positionVelocityLoop.pidPars.maxIntegratorLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_INTEGRATOR_LEVEL                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  feedforward addition point
 *
 *  @datatype       SAC_FF_ADDITION_POINT
 *  @defaultvalue   SAC_FF_BEFORE_NOTCH
 *  @xmlPath        controller/positionVelocityLoop/pidPars/SAC_PAR_FF_ADDITION_POINT
 *  @_adminPath     controller.positionVelocityLoop.pidPars.ffAdditionPoint
 *  @readOnly       FALSE
 */
#define SAC_PAR_FF_ADDITION_POINT                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @}
 */

/**
 *  @defgroup filter filter parameters
 *  @{
 */

/**
 *  @brief  low pass filter of position loop: 0=disable, 1=enable
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_LPF_SWITCH
 *  @_adminPath     controller.positionVelocityLoop.filterPars.lowPassEnabled
 *  @readOnly       FALSE
 */
#define SAC_PAR_LPF_SWITCH                            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  break frequency of low pass filter of position loop
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       1.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_LPF_FREQ
 *  @_adminPath     controller.positionVelocityLoop.filterPars.lowPassFreq
 *  @readOnly       FALSE
 */
#define SAC_PAR_LPF_FREQ                              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @brief  damping ratio of low pass filter of position loop
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_LPF_DAMPING
 *  @_adminPath     controller.positionVelocityLoop.filterPars.lowPassDamping
 *  @readOnly       FALSE
 */
#define SAC_PAR_LPF_DAMPING                           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @brief  enable lead-lag filter of position loop
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_LLF_SWITCH
 *  @_adminPath     controller.positionVelocityLoop.filterPars.leadLagEnabled
 *  @readOnly       FALSE
 */
#define SAC_PAR_LLF_SWITCH                            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  lead frequency of the lead-lag filter of position loop
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.001
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_LLF_LEAD_FREQ
 *  @_adminPath     controller.positionVelocityLoop.filterPars.leadFreq
 *  @readOnly       FALSE
 */
#define SAC_PAR_LLF_LEAD_FREQ                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  lag frequency of the lead-lag filter of position loop
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.001
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_LLF_LAG_FREQ
 *  @_adminPath     controller.positionVelocityLoop.filterPars.lagFreq
 *  @readOnly       FALSE
 */
#define SAC_PAR_LLF_LAG_FREQ                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  enable first notch filter of position loop
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFA_SWITCH
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchAEnabled
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFA_SWITCH                            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  numerator frequency of first notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       1.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFA_NUM_FREQ
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchANumFreq
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFA_NUM_FREQ                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  numerator relative damping of first notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFA_NUM_DAMP
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchANumDamping
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFA_NUM_DAMP                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  denominator frequency of first notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       1.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFA_DEN_FREQ
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchADenFreq
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFA_DEN_FREQ                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  denominator relative damping of first notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFA_DEN_DAMP
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchADenDamping
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFA_DEN_DAMP                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  enable second notch filter of position loop
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFB_SWITCH
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchBEnabled
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFB_SWITCH                            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  numerator frequency of second notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       1.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFB_NUM_FREQ
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchBNumFreq
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFB_NUM_FREQ                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  numerator relative damping of second notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFB_NUM_DAMP
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchBNumDamping
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFB_NUM_DAMP                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  denominator frequency of second notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       1.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFB_DEN_FREQ
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchBDenFreq
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFB_DEN_FREQ                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  denominator relative damping of second notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFB_DEN_DAMP
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchBDenDamping
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFB_DEN_DAMP                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  enable third notch filter of position loop
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFC_SWITCH
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchCEnabled
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFC_SWITCH                            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  numerator frequency of third notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFC_NUM_FREQ
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchCNumFreq
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFC_NUM_FREQ                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @brief  numerator relative damping of third notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFC_NUM_DAMP
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchCNumDamping
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFC_NUM_DAMP                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|37))

/**
 *  @brief  denominator frequency of third notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFC_DEN_FREQ
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchCDenFreq
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFC_DEN_FREQ                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|38))

/**
 *  @brief  denominator relative damping of third notch filter of position loop
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/filterPars/SAC_PAR_NFC_DEN_DAMP
 *  @_adminPath     controller.positionVelocityLoop.filterPars.notchCDenDamping
 *  @readOnly       FALSE
 */
#define SAC_PAR_NFC_DEN_DAMP                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|39))

/**
 *  @}
 */

/**
 *  @defgroup enhanced enhanced parameters
 *  @{
 */

/**
 *  @brief  switched control mechanism: enable
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_SCM_ENABLE
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.scmEnable
 *  @readOnly       FALSE
 */
#define SAC_PAR_SCM_ENABLE                            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|40))

/**
 *  @brief  switched control mechanism: positive range of reset window
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       2147483647.0
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_SCM_RESET_POS
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.scmResetPos
 *  @readOnly       FALSE
 */
#define SAC_PAR_SCM_RESET_POS                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|41))

/**
 *  @brief  switched control mechanism: negative range of reset window
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       -2147483647.0
 *  @maxvalue       0.0
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_SCM_RESET_NEG
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.scmResetNeg
 *  @readOnly       FALSE
 */
#define SAC_PAR_SCM_RESET_NEG                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|42))

/**
 *  @brief  switched control mechanism: positive restart value of the integrators
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_SCM_RESTART_INT_POS
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.scmRestartIntPos
 *  @readOnly       FALSE
 */
#define SAC_PAR_SCM_RESTART_INT_POS                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|43))

/**
 *  @brief  switched control mechanism: negative restart value of the integrators
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_SCM_RESTART_INT_NEG
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.scmRestartIntNeg
 *  @readOnly       FALSE
 */
#define SAC_PAR_SCM_RESTART_INT_NEG                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|44))

/**
 *  @brief  intrinsic friction compensation: gain in dead zone
 *
 *  @datatype       double
 *  @unit           [-]
 *  @firmwareDim    Minus1
 *  @hostDim        _
 *  @minvalue       -1.0
 *  @maxvalue       1999.0
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_IFC_DEAD_ZONE_GAIN
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.ifcDeadZoneGain
 *  @readOnly       FALSE
 */
#define SAC_PAR_IFC_DEAD_ZONE_GAIN                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|45))

/**
 *  @brief  intrinsic friction compensation: contr. output at positive bound of dead zone
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_IFC_DEAD_ZONE_CONTROL_OUT_POS
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.ifcDeadZoneOutputPos
 *  @readOnly       FALSE
 */
#define SAC_PAR_IFC_DEAD_ZONE_CONTROL_OUT_POS         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|46))

/**
 *  @brief  intrinsic friction compensation: contr. output at negative bound of dead zone
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       -1.0e+12
 *  @maxvalue       0.0
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_IFC_DEAD_ZONE_CONTROL_OUT_NEG
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.ifcDeadZoneOutputNeg
 *  @readOnly       FALSE
 */
#define SAC_PAR_IFC_DEAD_ZONE_CONTROL_OUT_NEG         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|47))

/**
 *  @brief  enhanced P gain: proportional gain of position loop at standstill
 *
 *  @datatype       double
 *  @unit           [cout/pu]
 *  @firmwareDim    NormalizedPerInc
 *  @hostDim        CoutPerPu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_P_GAIN_AT_STAND_STILL
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.pGainAtStandStill
 *  @readOnly       FALSE
 */
#define SAC_PAR_P_GAIN_AT_STAND_STILL                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_PER_INC<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|48))

/**
 *  @brief  enhanced P gain: velocity where prop. gain is avg of Kp and gain at standstill
 *
 *  @datatype       double
 *  @unit           [pu/s]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_P_HALF_WAY_VEL
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.pHalfWayVel
 *  @readOnly       FALSE
 */
#define SAC_PAR_P_HALF_WAY_VEL                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|49))

/**
 *  @brief  enhanced I gain: integral gain of position loop at standstill
 *
 *  @datatype       double
 *  @unit           [rad/s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_I_GAIN_AT_STAND_STILL
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.iGainAtStandStill
 *  @readOnly       FALSE
 */
#define SAC_PAR_I_GAIN_AT_STAND_STILL                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|50))

/**
 *  @brief  enhanced I gain: velocity where int. gain is average of Ki and gain at standstill
 *
 *  @datatype       double
 *  @unit           [pu/s]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_I_HALF_WAY_VEL
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.iHalfWayVel
 *  @readOnly       FALSE
 */
#define SAC_PAR_I_HALF_WAY_VEL                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|51))

/**
 *  @brief  enhanced D gain: derivative gain of position loop at standstill
 *
 *  @datatype       double
 *  @unit           [cout*s/pu]
 *  @firmwareDim    NormalizedPerInc
 *  @hostDim        CoutPerPu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_D_GAIN_AT_STAND_STILL
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.dGainAtStandStill
 *  @readOnly       FALSE
 */
#define SAC_PAR_D_GAIN_AT_STAND_STILL                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_PER_INC<<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|52))

/**
 *  @brief  enhanced D gain: velocity where der. gain is average of Kv and gain at standstill
 *
 *  @datatype       double
 *  @unit           [pu/s]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_D_HALF_WAY_VEL
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.dHalfWayVel
 *  @readOnly       FALSE
 */
#define SAC_PAR_D_HALF_WAY_VEL                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|53))

/**
 *  @brief  enable reset of integrator of position loop if pos.error=0
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_CLEGG_ENABLE
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.cleggEnable
 *  @readOnly       FALSE
 */
#define SAC_PAR_CLEGG_ENABLE                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|54))

/**
 *  @brief  frequency of dither signal added to position controller output
 *
 *  @datatype       double
 *  @unit           [Hz], 0.0=disable
 *  @minvalue       0.0
 *  @maxvalue       16000.0
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_DITHER_FREQUENCY
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.ditherFrequency
 *  @readOnly       FALSE
 */
#define SAC_PAR_DITHER_FREQUENCY                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|55))

/**
 *  @brief  max positive amplitude of dither signal added to position controller output
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_DITHER_HIGH
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.ditherHigh
 *  @readOnly       FALSE
 */
#define SAC_PAR_DITHER_HIGH                           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|56))

/**
 *  @brief  min negative amplitude of dither signal added to position controller output
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       -1.0e+12
 *  @maxvalue       0.0
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_DITHER_LOW
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.ditherLow
 *  @readOnly       FALSE
 */
#define SAC_PAR_DITHER_LOW                            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|57))

/**
 *  @brief  duty cycle of the dither signal added to position controller output
 *
 *  @datatype       double
 *  @unit           [%]
 *  @firmwareDim    Normalized
 *  @hostDim        Percentage
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_DITHER_DUTY_CYCLE
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.ditherDutyCycle
 *  @readOnly       FALSE
 */
#define SAC_PAR_DITHER_DUTY_CYCLE                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|58))

/**
 *  @brief  type of dither signal added to position controller output
 *
 *  @datatype       SAC_DITHER_TYPE
 *  @defaultvalue   SAC_DITHER_BLOCK
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_DITHER_TYPE
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.ditherType
 *  @readOnly       FALSE
 */
#define SAC_PAR_DITHER_TYPE                           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|59))

/**
 *  @brief  Enhanced max integrator level: max integrator level of position loop at standstill.
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_MAX_INTEGRATOR_LEVEL_AT_STAND_STILL
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.maxIntegratorLevelAtStandStill
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_INTEGRATOR_LEVEL_AT_STAND_STILL ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|60))

/**
 *  @brief  Enhanced max integrator level: velocity where max integrator level is avg of max integrator level and max integrator level at standstill.
 *
 *  @datatype       double
 *  @unit           [pu/s]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/positionVelocityLoop/enhancementPars/SAC_PAR_MAX_INTEGRATOR_LEVEL_HALF_WAY_VEL
 *  @_adminPath     controller.positionVelocityLoop.enhancementPars.maxIntegratorLevelHalfWayVel
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_INTEGRATOR_LEVEL_HALF_WAY_VEL   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_CTRCLL<<NYCE_FWMODULE_SHIFT)|61))

/**
 *  @}
 */

/**
 *  @addtogroup def
 *  @{
 */

/**
 *  @brief  input selection for the drive monitor function
 *
 *  @datatype       SAC_DMF_INPUT
 *  @defaultvalue   SAC_DMF_INPUT_NONE
 *  @xmlPath        controller/positionVelocityLoop/dmfPars/SAC_PAR_DMF_INPUT_SELECTION
 *  @_adminPath     controller.positionVelocityLoop.dmfPars.dmfInput
 *  @readOnly       FALSE
 */
#define SAC_PAR_DMF_INPUT_SELECTION                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRPVL<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  output selection for the drive monitor function
 *
 *  @datatype       SAC_DMF_OUTPUT
 *  @defaultvalue   SAC_DMF_INPUT_NONE
 *  @xmlPath        controller/positionVelocityLoop/dmfPars/SAC_PAR_DMF_OUTPUT_SELECTION
 *  @_adminPath     controller.positionVelocityLoop.dmfPars.dmfOutput
 *  @readOnly       FALSE
 */
#define SAC_PAR_DMF_OUTPUT_SELECTION                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRPVL<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  ADC input scaling when using the drive monitor function
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/dmfPars/SAC_PAR_DMF_VOLT_TO_INPUT
 *  @_adminPath     controller.positionVelocityLoop.dmfPars.voltToInput
 *  @readOnly       FALSE
 */
#define SAC_PAR_DMF_VOLT_TO_INPUT                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRPVL<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  DAC output scaling when using the drive monitor function
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        controller/positionVelocityLoop/dmfPars/SAC_PAR_DMF_OUTPUT_TO_VOLT
 *  @_adminPath     controller.positionVelocityLoop.dmfPars.outputToVolt
 *  @readOnly       FALSE
 */
#define SAC_PAR_DMF_OUTPUT_TO_VOLT                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRPVL<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  enable or disable anti aliasing filters
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        controller/antiAliasFilterPars/SAC_PAR_ANTI_ALIASING_FILTERS_ENABLE
 *  @_adminPath     controller.antiAliasFilterPars.aafEnable
 *  @readOnly       FALSE
 */
#define SAC_PAR_ANTI_ALIASING_FILTERS_ENABLE          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_CTRPVL<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @}
 */

/**
 *  @addtogroup pid
 *  @{
 */

/**
 *  @brief  Force proportional gain
 *
 *  @datatype       double
 *  @unit           [pu/N]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/pfcPars/SAC_PAR_PFC_KP
 *  @_adminPath     controller.pfcPars.parKp
 *  @readOnly       FALSE
 */
#define SAC_PAR_PFC_KP                                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_CTRPFC<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @}
 */

/**
 *  @addtogroup def
 *  @{
 */

/**
 *  @brief  modulo axis: minimum position
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       -1073741822.0
 *  @maxvalue       1073741822.0
 *  @defaultvalue   0.0
 *  @xmlPath        definitions/SAC_PAR_POSITION_MIN
 *  @_adminPath     definitions.positionMin
 *  @readOnly       FALSE
 */
#define SAC_PAR_POSITION_MIN                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC <<NYCE_FWDIM_SHIFT)|(FWM_CTRPOS<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  modulo axis: maximum position
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       -1073741822.0
 *  @maxvalue       1073741822.0
 *  @defaultvalue   0.0
 *  @xmlPath        definitions/SAC_PAR_POSITION_MAX
 *  @_adminPath     definitions.positionMax
 *  @readOnly       FALSE
 */
#define SAC_PAR_POSITION_MAX                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC <<NYCE_FWDIM_SHIFT)|(FWM_CTRPOS<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  position update mode
 *
 *  @datatype       SAC_POS_UPDATE_MODE
 *  @defaultvalue   SAC_POS_UPDATE_LINEAR
 *  @xmlPath        definitions/SAC_PAR_POSITION_UPDATE_MODE
 *  @_adminPath     definitions.positionUpdateMode
 *  @readOnly       FALSE
 */
#define SAC_PAR_POSITION_UPDATE_MODE                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRPOS<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  position unit type
 *
 *  @datatype       SAC_POSITION_UNIT_TYPE
 *  @defaultvalue   SAC_POSITION_UNIT
 *  @xmlPath        definitions/SAC_PAR_POSITION_UNIT_TYPE
 *  @_adminPath     definitions.positionUnitType
 *  @readOnly       FALSE
 */
#define SAC_PAR_POSITION_UNIT_TYPE                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRPOS<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  encoder increments per position unit
 *
 *  @datatype       double
 *  @unit           [incs/pu]
 *  @minvalue       1.0e-05
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1
 *  @xmlPath        definitions/SAC_PAR_RESOLUTION
 *  @_adminPath     definitions.resolution
 *  @readOnly       FALSE
 */
#define SAC_PAR_RESOLUTION                            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_DOUBLE<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRPOS<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  direction of the secondary S00/S90 counter
 *
 *  @datatype       SAC_DIRECTION
 *  @defaultvalue   SAC_DIR_POSITIVE
 *  @xmlPath        definitions/SAC_PAR_SECONDARY_COUNTER_DIRECTION
 *  @_adminPath     definitions.secondaryCounterDirection
 *  @readOnly       FALSE
 */
#define SAC_PAR_SECONDARY_COUNTER_DIRECTION           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRPOS<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Sensor Linearization
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        -
 *  @_adminPath     configuration.linLutPars.enabled
 *  @readOnly       FALSE
 */
#define SAC_PAR_LIN_LOOK_UP_TABLE_ENABLE              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRPOS<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  IndraDrive resolution for linear or rotational encoder
 *
 *  @datatype       double
 *  @unit           [millimeters or degrees]
 *  @minvalue       1.0e-6
 *  @maxvalue       1.0e-3
 *  @defaultvalue   1.0e-4
 *  @xmlPath        definitions/SAC_PAR_INDRA_RESOLUTION
 *  @_adminPath     definitions.indraResolution
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_RESOLUTION                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRPOS<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @}
 */

/**
 *  @addtogroup pid
 *  @{
 */

/**
 *  @brief  measuring system direction
 *
 *  @datatype       SAC_DIRECTION
 *  @defaultvalue   SAC_DIR_POSITIVE
 *  @xmlPath        definitions/SAC_PAR_MEAS_SYST_DIRECTION
 *  @_adminPath     definitions.measSystemDirection
 *  @readOnly       FALSE
 */
#define SAC_PAR_MEAS_SYST_DIRECTION                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRPOS<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @}
 */

/**
 *  @defgroup states states parameters
 *  @{
 */

/**
 *  @brief  position ready window
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       2147483647.0
 *  @defaultvalue   0.0
 *  @xmlPath        definitions/statePars/SAC_PAR_POS_READY_WIN
 *  @_adminPath     definitions.statePars.posReadyWin
 *  @readOnly       FALSE
 */
#define SAC_PAR_POS_READY_WIN                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_CTRSTATE<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  velocity ready window
 *
 *  @datatype       double
 *  @unit           [pu/s]
 *  @firmwareDim    IncPerNodeSample
 *  @hostDim        PuPerSec
 *  @minvalue       0
 *  @maxvalue       INT_MAX
 *  @defaultvalue   0
 *  @xmlPath        definitions/statePars/SAC_PAR_VEL_READY_WIN
 *  @_adminPath     definitions.statePars.velReadyWin
 *  @readOnly       FALSE
 */
#define SAC_PAR_VEL_READY_WIN                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_INC   <<NYCE_FWDIM_SHIFT)|(FWM_CTRSTATE<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  time that position and velocity should be in their ready windows
 *
 *  @datatype       double
 *  @unit           [s]
 *  @firmwareDim    NrOfNodeSamples
 *  @hostDim        Sec
 *  @minvalue       0
 *  @maxvalue       INT_MAX
 *  @defaultvalue   0
 *  @xmlPath        definitions/statePars/SAC_PAR_TIME_IN_READY_WINDOWS
 *  @_adminPath     definitions.statePars.timeInReadyWindows
 *  @readOnly       FALSE
 */
#define SAC_PAR_TIME_IN_READY_WINDOWS                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME  <<NYCE_FWDIM_SHIFT)|(FWM_CTRSTATE<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  maximum allowed time between generator ready and controller ready
 *
 *  @datatype       double
 *  @unit           [s]
 *  @firmwareDim    NrOfNodeSamples
 *  @hostDim        Sec
 *  @minvalue       0
 *  @maxvalue       INT_MAX
 *  @defaultvalue   0
 *  @xmlPath        definitions/statePars/SAC_PAR_SETTLING_TIMEOUT
 *  @_adminPath     definitions.statePars.settlingTimeout
 *  @readOnly       FALSE
 */
#define SAC_PAR_SETTLING_TIMEOUT                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME  <<NYCE_FWDIM_SHIFT)|(FWM_CTRSTATE<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  after this time period the controller is set to steady
 *
 *  @datatype       double
 *  @unit           [s]
 *  @firmwareDim    NrOfNodeSamples
 *  @hostDim        Sec
 *  @minvalue       0
 *  @maxvalue       INT_MAX
 *  @defaultvalue   0
 *  @xmlPath        definitions/statePars/SAC_PAR_STEADY_STATE_DELAY
 *  @_adminPath     definitions.statePars.steadyStateDelay
 *  @readOnly       FALSE
 */
#define SAC_PAR_STEADY_STATE_DELAY                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME  <<NYCE_FWDIM_SHIFT)|(FWM_CTRSTATE<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @}
 */

/**
 *  @defgroup align align parameters
 *  @{
 */

/**
 *  @brief  alignment mode for brushless AC motor
 *
 *  @datatype       SAC_ALIGNMENT_MODE
 *  @defaultvalue   SAC_ALIGN_MODE_NONE
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_ALIGNMENT_MODE
 *  @_adminPath     motion.alignMotorPars.mode
 *  @readOnly       FALSE
 */
#define SAC_PAR_ALIGNMENT_MODE                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  maximum controller output during alignment procedure
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_MAX_ALIGNMENT_OUTPUT
 *  @_adminPath     motion.alignMotorPars.maxControllerOutput
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_ALIGNMENT_OUTPUT                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  period time of test signal during wake & shake (mode SAC_ALIGN_WAKE_AND_SHAKE only)
 *
 *  @datatype       double
 *  @unit           [s]
 *  @firmwareDim    NrOfNodeSamplesDiv10
 *  @hostDim        Sec
 *  @minvalue       1
 *  @maxvalue       0x7FFFFFFF
 *  @defaultvalue   1
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_WAKE_AND_SHAKE_PERIOD_TIME
 *  @_adminPath     motion.alignMotorPars.testSignalTestTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_WAKE_AND_SHAKE_PERIOD_TIME            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  critical displacement; threshold for no motion (mode SAC_ALIGN_WAKE_AND_SHAKE only)
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       2147483647.0
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_WAKE_AND_SHAKE_CRIT_DISPL
 *  @_adminPath     motion.alignMotorPars.criticalDisplacement
 *  @readOnly       FALSE
 */
#define SAC_PAR_WAKE_AND_SHAKE_CRIT_DISPL             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC  <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  commutation angle (mode SAC_ALIGN_SET_COMMUTATION_OFFSET) or commutation offset (mode SAC_ALIGN_ON_ENCODER_POSITION)
 *
 *  @datatype       double
 *  @unit           [rad/-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_COMMUTATION_OFFSET
 *  @_adminPath     motion.alignMotorPars.commutationOffset
 *  @readOnly       FALSE
 */
#define SAC_PAR_COMMUTATION_OFFSET                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  commutation angle at one endstop, typically negative endstop (mode SAC_ALIGN_CATCH_AND_MOVE only)
 *
 *  @datatype       double
 *  @unit           [rad]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_CATCH_AND_MOVE_ANGLE_ALPHA
 *  @_adminPath     motion.alignMotorPars.angleAlpha
 *  @readOnly       FALSE
 */
#define SAC_PAR_CATCH_AND_MOVE_ANGLE_ALPHA            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  commutation angle at one endstop, typically positive endstop (mode SAC_ALIGN_CATCH_AND_MOVE only)
 *
 *  @datatype       double
 *  @unit           [rad]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_CATCH_AND_MOVE_ANGLE_BETA
 *  @_adminPath     motion.alignMotorPars.angleBeta
 *  @readOnly       FALSE
 */
#define SAC_PAR_CATCH_AND_MOVE_ANGLE_BETA             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  distance to be made during alignment (mode SAC_ALIGN_CATCH_AND_MOVE only)
 *
 *  @datatype       double
 *  @unit           [rad]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_CATCH_AND_MOVE_DISTANCE
 *  @_adminPath     motion.alignMotorPars.distance
 *  @readOnly       FALSE
 */
#define SAC_PAR_CATCH_AND_MOVE_DISTANCE               ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  allowed deviation in between angle move and actual position change, as a percentage of the pole pitch (mode SAC_ALIGN_CATCH_AND_MOVE only)
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_CATCH_AND_MOVE_DEVIATION
 *  @_adminPath     motion.alignMotorPars.deviation
 *  @readOnly       FALSE
 */
#define SAC_PAR_CATCH_AND_MOVE_DEVIATION              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  time used during the catch and hold phase(mode SAC_ALIGN_CATCH_AND_MOVE only)
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_CATCH_AND_MOVE_RAMP_TIME
 *  @_adminPath     motion.alignMotorPars.rampTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_CATCH_AND_MOVE_RAMP_TIME              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  time used during the catch and move phase(mode SAC_ALIGN_CATCH_AND_MOVE only)
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_CATCH_AND_MOVE_MOVE_TIME
 *  @_adminPath     motion.alignMotorPars.moveTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_CATCH_AND_MOVE_MOVE_TIME              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  time used during the catch, hold and move phase(mode SAC_ALIGN_CATCH_AND_MOVE only)
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_CATCH_AND_MOVE_HOLD_TIME
 *  @_adminPath     motion.alignMotorPars.holdTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_CATCH_AND_MOVE_HOLD_TIME              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  max current used during the catch phase(mode SAC_ALIGN_CATCH_AND_MOVE only)
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_CATCH_AND_MOVE_MIN_CURRENT_LEVEL
 *  @_adminPath     motion.alignMotorPars.minCurrentLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_CATCH_AND_MOVE_MIN_CURRENT_LEVEL      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  max current used during the hold and move phase(mode SAC_ALIGN_CATCH_AND_MOVE only)
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_CATCH_AND_MOVE_MAX_CURRENT_LEVEL
 *  @_adminPath     motion.alignMotorPars.maxCurrentLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_CATCH_AND_MOVE_MAX_CURRENT_LEVEL      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  Amplitude for angle acquisition on IndraDrive (mode SAC_ALIGN_INDRA_SATURATION and SAC_ALIGN_INDRA_SINE_WAVE only)
 *
 *  @datatype       double
 *  @unit           [V], for alignment mode SAC_ALIGN_INDRA_SATURATION or percentage for mode SAC_ALIGN_INDRA_SINE_WAVE
 *  @minvalue       0.0
 *  @maxvalue       1000.0
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_INDRA_TEST_SIGNAL_START_AMPLITUDE
 *  @_adminPath     motion.alignMotorPars.indraTestSignalStartAmplitude
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_TEST_SIGNAL_START_AMPLITUDE     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  Test frequency for angle acquisition on IndraDrive(mode SAC_ALIGN_INDRA_SATURATION and SAC_ALIGN_INDRA_SINE_WAVE only)
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.0
 *  @maxvalue       1000.0
 *  @defaultvalue   500.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_INDRA_TEST_SIGNAL_START_FREQUENCY
 *  @_adminPath     motion.alignMotorPars.indraTestSignalStartFrequency
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_TEST_SIGNAL_START_FREQUENCY     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  time used during the push phase(mode SAC_ALIGN_PUSH_AND_SETTLE only)
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/alignMotorPars/SAC_PAR_PUSH_AND_SETTLE_RAMP_TIME
 *  @_adminPath     motion.alignMotorPars.pushSettleRampTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_PUSH_AND_SETTLE_RAMP_TIME              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_CTRWNS<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @}
 */

/**
 *  @addtogroup def
 *  @{
 */

/**
 *  @brief  Auto Tweak
 *
 *  @datatype       SAC_TWEAK_MODE
 *  @defaultvalue   SAC_TWEAK_DISABLED
 *  @xmlPath        -
 *  @_adminPath     configuration.tweakPars.mode
 *  @readOnly       FALSE
 */
#define SAC_PAR_TWEAK_MODE                            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRTWK<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  ramp of the tweak values, used when the controller mode is closed loop and the tweak functionality is activated
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0x7FFFFFFF/8000
 *  @defaultvalue   0.0
 *  @xmlPath        configuration/tweakPars/SAC_PAR_TWEAK_RAMP_TIME
 *  @_adminPath     configuration.tweakPars.rampTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_TWEAK_RAMP_TIME                       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRTWK<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  position source for tweak
 *
 *  @datatype       SAC_TWEAK_POSITION_SOURCE
 *  @defaultvalue   SAC_TWEAK_AXIS_POSITION
 *  @xmlPath        configuration/tweakPars/SAC_PAR_TWEAK_POSITION_SOURCE
 *  @_adminPath     configuration.tweakPars.positionSource
 *  @readOnly       FALSE
 */
#define SAC_PAR_TWEAK_POSITION_SOURCE                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CTRTWK<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @}
 */

/**
 *  @defgroup err err parameters
 *  @{
 */

/**
 *  @brief  maximum position for the axis
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_POS_SW_END_SWITCH
 *  @_adminPath     edh.errorCheckPars.posSwEndSwitch
 *  @readOnly       FALSE
 */
#define SAC_PAR_POS_SW_END_SWITCH                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  minimum position for the axis
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_NEG_SW_END_SWITCH
 *  @_adminPath     edh.errorCheckPars.negSwEndSwitch
 *  @readOnly       FALSE
 */
#define SAC_PAR_NEG_SW_END_SWITCH                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  enable check of software end switches before movement
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_POSITION_RANGE_CHECK
 *  @_adminPath     edh.errorCheckPars.swSwitchPreCheckEnable
 *  @readOnly       FALSE
 */
#define SAC_PAR_POSITION_RANGE_CHECK                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  maximum position error when the controller is steady
 *
 *  @datatype       double
 *  @unit           [pu], 0.0=disable
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       2147483646.0
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_MAX_STEADY_STATE_ERROR
 *  @_adminPath     edh.errorCheckPars.maxSteadyStateError
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_STEADY_STATE_ERROR                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  maximum position error when the axis is locked
 *
 *  @datatype       double
 *  @unit           [pu], 0.0=disable
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       2147483646.0
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_MAX_DYN_POS_ERROR
 *  @_adminPath     edh.errorCheckPars.maxDynPosError
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_DYN_POS_ERROR                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  maximum settling time
 *
 *  @datatype       double
 *  @unit           [s], 0.0=disable
 *  @firmwareDim    NrOfNodeSamples
 *  @hostDim        Sec
 *  @minvalue       0
 *  @maxvalue       INT_MAX-1
 *  @defaultvalue   0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_MAX_SETTLING_TIME
 *  @_adminPath     edh.errorCheckPars.maxSettlingTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_SETTLING_TIME                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME  <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  collision detection time window
 *
 *  @datatype       double
 *  @unit           [s], 0.0=disable
 *  @firmwareDim    NrOfNodeSamples
 *  @hostDim        Sec
 *  @minvalue       0
 *  @maxvalue       INT_MAX-1
 *  @defaultvalue   0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_COLLISION_TIME_WINDOW
 *  @_adminPath     edh.errorCheckPars.collisionTimeWindow
 *  @readOnly       FALSE
 */
#define SAC_PAR_COLLISION_TIME_WINDOW                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME  <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  collision detection controller output threshold
 *
 *  @datatype       double
 *  @unit           [cout], 0.0=disable
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       2147483392.0
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_COLLISION_CONTROLLER_OUT
 *  @_adminPath     edh.errorCheckPars.collisionControllerOutput
 *  @readOnly       FALSE
 */
#define SAC_PAR_COLLISION_CONTROLLER_OUT              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  collision detection axis velocity threshold
 *
 *  @datatype       double
 *  @unit           [pu/s], 0.0=disable
 *  @firmwareDim    IncPerNodeSample
 *  @hostDim        PuPerSec
 *  @minvalue       0
 *  @maxvalue       INT_MAX
 *  @defaultvalue   0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_COLLISION_VEL
 *  @_adminPath     edh.errorCheckPars.collisionVelocity
 *  @readOnly       FALSE
 */
#define SAC_PAR_COLLISION_VEL                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  maximum velocity constraint for setpoint generator in normal mode
 *
 *  @datatype       double
 *  @unit           [pu/s], 0.0=INF
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_MAX_VEL_NORMAL_MODE
 *  @_adminPath     edh.errorCheckPars.maxSpgVelocity
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_VEL_NORMAL_MODE                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  maximum acceleration constraint for setpoint generator in normal mode
 *
 *  @datatype       double
 *  @unit           [pu/s^2], 0.0=INF
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_MAX_ACC_NORMAL_MODE
 *  @_adminPath     edh.errorCheckPars.maxSpgAcceleration
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_ACC_NORMAL_MODE                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  maximum jerk constraint for setpoint generator in normal mode
 *
 *  @datatype       double
 *  @unit           [pu/s^3], 0.0=INF
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_MAX_JERK_NORMAL_MODE
 *  @_adminPath     edh.errorCheckPars.maxSpgJerk
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_JERK_NORMAL_MODE                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  upper limit of the positive servo voltage of the drive
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       5.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   12.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_POS_SERVO_OVER_VOLTAGE_LIMIT
 *  @_adminPath     edh.errorCheckPars.posServoOverVoltageLimit
 *  @readOnly       FALSE
 */
#define SAC_PAR_POS_SERVO_OVER_VOLTAGE_LIMIT          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  lower limit of the positive servo voltage of the drive
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       5.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   12.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_POS_SERVO_UNDER_VOLTAGE_LIMIT
 *  @_adminPath     edh.errorCheckPars.posServoUnderVoltageLimit
 *  @readOnly       FALSE
 */
#define SAC_PAR_POS_SERVO_UNDER_VOLTAGE_LIMIT         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  lower limit of the negative servo voltage of the drive
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -1.0e+12
 *  @maxvalue       -0.0
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_NEG_SERVO_UNDER_VOLTAGE_LIMIT
 *  @_adminPath     edh.errorCheckPars.negServoUnderVoltageLimit
 *  @readOnly       FALSE
 */
#define SAC_PAR_NEG_SERVO_UNDER_VOLTAGE_LIMIT         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  upper limit of the negative servo voltage of the drive
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -1.0e+12
 *  @maxvalue       -0.0
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_NEG_SERVO_OVER_VOLTAGE_LIMIT
 *  @_adminPath     edh.errorCheckPars.negServoOverVoltageLimit
 *  @readOnly       FALSE
 */
#define SAC_PAR_NEG_SERVO_OVER_VOLTAGE_LIMIT          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  maximum motor current
 *
 *  @datatype       double
 *  @unit           [A], 0.0=INF
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_MAX_CURRENT
 *  @_adminPath     edh.errorCheckPars.maxCurrent
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_CURRENT                           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  maximum I2t level of the axis for drive protection
 *
 *  @datatype       double
 *  @unit           [A^2s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   35.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_DRIVE_MAX_I2T_LEVEL
 *  @_adminPath     edh.errorCheckPars.driveMaxI2t
 *  @readOnly       FALSE
 */
#define SAC_PAR_DRIVE_MAX_I2T_LEVEL                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  maximum velocity constraint for axis in normal mode
 *
 *  @datatype       double
 *  @unit           [pu/s], 0.0=INF
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_MAX_AXIS_VEL_NORMAL_MODE
 *  @_adminPath     edh.errorCheckPars.maxAxisVelocity
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_AXIS_VEL_NORMAL_MODE              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  LMS sensor supply voltage
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       5.0
 *  @maxvalue       15.0
 *  @defaultvalue   5.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_LMS_SENSOR_SUPPLY_VALUE
 *  @_adminPath     edh.errorCheckPars.sensorSupply
 *  @readOnly       FALSE
 */
#define SAC_PAR_LMS_SENSOR_SUPPLY_VALUE               ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @brief  nominal motor current also known as maximum continuous current
 *
 *  @datatype       double
 *  @unit           [A]
 *  @minvalue       0.0
 *  @maxvalue       1000.0
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_MOTOR_NOMINAL_CURRENT
 *  @_adminPath     edh.errorCheckPars.motorNominalCurrent
 *  @readOnly       FALSE
 */
#define SAC_PAR_MOTOR_NOMINAL_CURRENT                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @brief  thermal time constant of the motor winding
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+6
 *  @defaultvalue   0.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_MOTOR_THERMAL_TIME_CONSTANT
 *  @_adminPath     edh.errorCheckPars.motorThermalTimeConstant
 *  @readOnly       FALSE
 */
#define SAC_PAR_MOTOR_THERMAL_TIME_CONSTANT           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  maximum overload factor for the motor current
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       2.0
 *  @defaultvalue   1.0
 *  @xmlPath        edh/errorCheckPars/SAC_PAR_MOTOR_MAX_OVERLOAD_FACTOR
 *  @_adminPath     edh.errorCheckPars.motorMaxOverloadFactor
 *  @readOnly       FALSE
 */
#define SAC_PAR_MOTOR_MAX_OVERLOAD_FACTOR             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @}
 */

/**
 *  @addtogroup stepper
 *  @{
 */

/**
 *  @brief  stepper motor base velocity
 *
 *  @datatype       double
 *  @unit           [pu/s]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/stepperPars/SAC_PAR_STEPPER_BASE_VELOCITY
 *  @_adminPath     motion.stepperPars.baseVelocity
 *  @readOnly       FALSE
 */
#define SAC_PAR_STEPPER_BASE_VELOCITY                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC  <<NYCE_FWDIM_SHIFT)|(FWM_SPGMAIN<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  stepper motor pre acceleration delay time
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/stepperPars/SAC_PAR_PRE_ACC_DELAY
 *  @_adminPath     motion.stepperPars.preAccDelay
 *  @readOnly       FALSE
 */
#define SAC_PAR_PRE_ACC_DELAY                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_SPGMAIN<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  stepper motor post acceleration delay time
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/stepperPars/SAC_PAR_POST_ACC_DELAY
 *  @_adminPath     motion.stepperPars.postAccDelay
 *  @readOnly       FALSE
 */
#define SAC_PAR_POST_ACC_DELAY                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_SPGMAIN<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  stepper motor pre deceleration delay time
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/stepperPars/SAC_PAR_PRE_DEC_DELAY
 *  @_adminPath     motion.stepperPars.preDecDelay
 *  @readOnly       FALSE
 */
#define SAC_PAR_PRE_DEC_DELAY                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_SPGMAIN<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  stepper motor post deceleration delay time
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/stepperPars/SAC_PAR_POST_DEC_DELAY
 *  @_adminPath     motion.stepperPars.postDecDelay
 *  @readOnly       FALSE
 */
#define SAC_PAR_POST_DEC_DELAY                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_SPGMAIN<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  stepper motor acceleration threshold
 *
 *  @datatype       double
 *  @unit           [pu/s^2]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/stepperPars/SAC_PAR_STEPPER_ACCELERATION_THRESHOLD
 *  @_adminPath     motion.stepperPars.accThreshold
 *  @readOnly       FALSE
 */
#define SAC_PAR_STEPPER_ACCELERATION_THRESHOLD        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC  <<NYCE_FWDIM_SHIFT)|(FWM_SPGMAIN<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @}
 */

/**
 *  @defgroup ptp ptp parameters
 *  @{
 */

/**
 *  @brief  maximum snap for 4th order point-to-point profiles
 *
 *  @datatype       double
 *  @unit           [pu/s^4]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       1.0e-4
 *  @maxvalue       1.0e18
 *  @defaultvalue   SAC_INDEFINITE
 *  @infAllowed
 *  @xmlPath        motion/SAC_PAR_MAX_PTP_SNAP
 *  @_adminPath     motion.ptpMaxSnap
 *  @readOnly       FALSE
 */
#define SAC_PAR_MAX_PTP_SNAP                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC  <<NYCE_FWDIM_SHIFT)|(FWM_SPGPTP<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  delay in setpoint position w.r.t. the setpoint derivatives
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   0.0
 *  @xmlPath        motion/SAC_PAR_PTP_POSITION_DELAY
 *  @_adminPath     motion.ptpPositionDelay
 *  @readOnly       FALSE
 */
#define SAC_PAR_PTP_POSITION_DELAY                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_SPGPTP<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  maximum jerk ramp time to generate 4th order EPC enabled point-to-points
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+6
 *  @defaultvalue   0.0
 *  @xmlPath        motion/SAC_PAR_PTP_MAX_JERK_RAMP_TIME
 *  @_adminPath     motion.ptpMaxJerkRampTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_PTP_MAX_JERK_RAMP_TIME                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME <<NYCE_FWDIM_SHIFT)|(FWM_SPGPTP<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @}
 */

/**
 *  @defgroup home home parameters
 *  @{
 */

/**
 *  @brief  home mode
 *
 *  @datatype       SAC_HOME_MODE
 *  @defaultvalue   SAC_HOME_MODE_AXIS_POS
 *  @xmlPath        motion/homePars/SAC_PAR_HOME_MODE
 *  @_adminPath     motion.homePars.mode
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_MODE                             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  home offset
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @defaultvalue   0.0
 *  @xmlPath        motion/homePars/SAC_PAR_HOME_OFFSET
 *  @_adminPath     motion.homePars.offset
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_OFFSET                           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC <<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  home velocity (home mode 3-13 only)
 *
 *  @datatype       double
 *  @unit           [pu/s]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        motion/homePars/SAC_PAR_HOME_VEL
 *  @_adminPath     motion.homePars.velocity
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_VEL                              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC <<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  home acceleration ( home mode 3-13 only)
 *
 *  @datatype       double
 *  @unit           [pu/s^2]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       1.0e-4
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @xmlPath        motion/homePars/SAC_PAR_HOME_ACC
 *  @_adminPath     motion.homePars.acceleration
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_ACC                              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC <<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  home jerk (home mode 3-13 only)
 *
 *  @datatype       double
 *  @unit           [pu/s^3]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       1.0e-4
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1.0
 *  @infAllowed
 *  @xmlPath        motion/homePars/SAC_PAR_HOME_JERK
 *  @_adminPath     motion.homePars.jerk
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_JERK                             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC <<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  type of end-of-stoke detection criterion
 *
 *  @datatype       SAC_EOS_CRITERION
 *  @defaultvalue   SAC_POSITION_ERROR
 *  @xmlPath        motion/homePars/SAC_PAR_HOME_EOS_CRITERION
 *  @_adminPath     motion.homePars.eosCriterion
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_EOS_CRITERION                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  criterion value if end-of-stroke detection is based on position error
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       2147483647.0
 *  @defaultvalue   0.0
 *  @xmlPath        motion/homePars/SAC_PAR_HOME_EOS_POS_CRIT_VALUE
 *  @_adminPath     motion.homePars.eosPosCriterion
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_EOS_POS_CRIT_VALUE               ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC <<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  criterion value if end-of-stroke detection is based on controller output
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/homePars/SAC_PAR_HOME_EOS_CONTR_CRIT_VALUE
 *  @_adminPath     motion.homePars.eosContrCriterion
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_EOS_CONTR_CRIT_VALUE             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  controller output value to apply when end-of-stroke is detected
 *
 *  @datatype       double
 *  @unit           [cout]
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        motion/homePars/SAC_PAR_HOME_EOS_OUTPUT
 *  @_adminPath     motion.homePars.eosOutput
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_EOS_OUTPUT                       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  time period from end-of-stroke detection before axis home position is defined
 *
 *  @datatype       double
 *  @unit           [s]
 *  @firmwareDim    NrOfNodeSamples
 *  @hostDim        Sec
 *  @minvalue       0
 *  @maxvalue       INT_MAX
 *  @defaultvalue   0
 *  @xmlPath        motion/homePars/SAC_PAR_HOME_EOS_OPEN_LOOP_TIME
 *  @_adminPath     motion.homePars.eosOpenLoopTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_EOS_OPEN_LOOP_TIME               ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  controller output maximum positive saturation level during homing
 *
 *  @datatype       double
 *  @unit           [cout], 0.0=disable
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   0.0
 *  @xmlPath        motion/homeExtensionPars/SAC_PAR_HOME_SAT_LEVEL
 *  @_adminPath     motion.homeExtensionPars.homeSatLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_SAT_LEVEL                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  controller output maximum negative saturation level during homing
 *
 *  @datatype       double
 *  @unit           [cout], 0.0=disable
 *  @firmwareDim    Normalized
 *  @hostDim        Cout
 *  @minvalue       -1.0
 *  @maxvalue       0.0
 *  @defaultvalue   0.0
 *  @xmlPath        motion/homeExtensionPars/SAC_PAR_HOME_SAT_MIN_LEVEL
 *  @_adminPath     motion.homeExtensionPars.homeSatMinLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_SAT_MIN_LEVEL                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  max dyn pos error level during homing
 *
 *  @datatype       double
 *  @unit           [pu], 0.0=disable
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       2147483647.0
 *  @defaultvalue   0.0
 *  @xmlPath        motion/homeExtensionPars/SAC_PAR_HOME_MAX_DYN_POS_ERROR
 *  @_adminPath     motion.homeExtensionPars.homeMaxDynPosError
 *  @readOnly       FALSE
 */
#define SAC_PAR_HOME_MAX_DYN_POS_ERROR                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC <<NYCE_FWDIM_SHIFT)|(FWM_SPGHOME<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @}
 */

/**
 *  @defgroup stop stop parameters
 *  @{
 */

/**
 *  @brief  maximum deceleration for quickstop
 *
 *  @datatype       double
 *  @unit           [pu/s^2]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       1.0e-4
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1000.0
 *  @xmlPath        motion/quickStopPars/SAC_PAR_QUICKSTOP_ACC
 *  @_adminPath     motion.quickStopPars.acceleration
 *  @readOnly       FALSE
 */
#define SAC_PAR_QUICKSTOP_ACC                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC<<NYCE_FWDIM_SHIFT)|(FWM_SPGQST<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  maximum deceleration for smoothstop
 *
 *  @datatype       double
 *  @unit           [pu/s^2]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       1.0e-4
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1000.0
 *  @xmlPath        motion/smoothStopPars/SAC_PAR_SMOOTHSTOP_ACC
 *  @_adminPath     motion.smoothStopPars.acceleration
 *  @readOnly       FALSE
 */
#define SAC_PAR_SMOOTHSTOP_ACC                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC<<NYCE_FWDIM_SHIFT)|(FWM_SPGSTP<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  maximum jerk for smoothstop
 *
 *  @datatype       double
 *  @unit           [pu/s^3]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       1.0e-4
 *  @maxvalue       1.0e+12
 *  @defaultvalue   1000.0
 *  @infAllowed
 *  @xmlPath        motion/smoothStopPars/SAC_PAR_SMOOTHSTOP_JERK
 *  @_adminPath     motion.smoothStopPars.jerk
 *  @readOnly       FALSE
 */
#define SAC_PAR_SMOOTHSTOP_JERK                       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC<<NYCE_FWDIM_SHIFT)|(FWM_SPGSTP<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  maximum deceleration used with stop on event function
 *
 *  @datatype       double
 *  @unit           [pu/s^2]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       1.0e-4
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.001
 *  @xmlPath        motion/triggerStopPars/SAC_PAR_TRIGGERED_STOP_ACC
 *  @_adminPath     motion.triggerStopPars.acceleration
 *  @readOnly       FALSE
 */
#define SAC_PAR_TRIGGERED_STOP_ACC                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC<<NYCE_FWDIM_SHIFT)|(FWM_SPGJOG<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  maximum jerk used with stop on event function
 *
 *  @datatype       double
 *  @unit           [pu/s^3]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       1.0e-4
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.001
 *  @infAllowed
 *  @xmlPath        motion/triggerStopPars/SAC_PAR_TRIGGERED_STOP_JERK
 *  @_adminPath     motion.triggerStopPars.jerk
 *  @readOnly       FALSE
 */
#define SAC_PAR_TRIGGERED_STOP_JERK                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC<<NYCE_FWDIM_SHIFT)|(FWM_SPGJOG<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @}
 */

/**
 *  @addtogroup def
 *  @{
 */

/**
 *  @brief  stop alarm polarity for NY4125 and NY4130
 *
 *  @datatype       NYCE_ACTIVE_STATE
 *  @defaultvalue   NYCE_ACTIVE_HIGH
 *  @xmlPath        configuration/stopAlarmPars/SAC_PAR_STOP_ALARM_ACTIVE_LEVEL
 *  @_adminPath     configuration.stopAlarmPars.activeLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_STOP_ALARM_ACTIVE_LEVEL               ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  disable drive polarity for NY4120, NY4125 and NY4140
 *
 *  @datatype       NYCE_ACTIVE_STATE
 *  @defaultvalue   NYCE_ACTIVE_HIGH
 *  @xmlPath        configuration/disableDrivePars/SAC_PAR_DISABLE_DRIVE_ACTIVE_LEVEL
 *  @_adminPath     configuration.disableDrivePars.activeLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_DISABLE_DRIVE_ACTIVE_LEVEL            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  disable drive enable flag for NY4120, NY4125 and NY4140
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        configuration/disableDrivePars/SAC_PAR_DISABLE_DRIVE_ENABLE
 *  @_adminPath     configuration.disableDrivePars.enabled
 *  @readOnly       FALSE
 */
#define SAC_PAR_DISABLE_DRIVE_ENABLE                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  FET states at drive disable for NY4120, NY4125 and NY4140
 *
 *  @datatype       SAC_H_BRIDGE_STATE_AT_POWER_DISABLED
 *  @defaultvalue   SAC_H_BRIDGE_OPEN
 *  @xmlPath        configuration/hBridgeStatePars/SAC_PAR_H_BRIDGE_STATE_AT_POWER_DISABLED
 *  @_adminPath     configuration.hBridgePars.hBridgeState
 *  @readOnly       FALSE
 */
#define SAC_PAR_H_BRIDGE_STATE_AT_POWER_DISABLED      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @}
 */

/**
 *  @defgroup cc cc parameters
 *  @{
 */

/**
 *  @brief  proportional gain of current loop
 *
 *  @datatype       double
 *  @unit           [V/A]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/currentLoop/currentControlPars/SAC_PAR_CC_KP
 *  @_adminPath     controller.currentLoop.currentControlPars.parKp
 *  @readOnly       FALSE
 */
#define SAC_PAR_CC_KP                                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  integral gain of current loop
 *
 *  @datatype       double
 *  @unit           [rad/s]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/currentLoop/currentControlPars/SAC_PAR_CC_KI
 *  @_adminPath     controller.currentLoop.currentControlPars.parKi
 *  @readOnly       FALSE
 */
#define SAC_PAR_CC_KI                                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  maximum level of integrator in current loop
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/currentLoop/currentControlPars/SAC_PAR_CC_MAX_INTEGRATOR_LEVEL
 *  @_adminPath     controller.currentLoop.currentControlPars.maxIntegratorLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_CC_MAX_INTEGRATOR_LEVEL               ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  saturation level of current controller output
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        controller/currentLoop/currentControlPars/SAC_PAR_CC_SAT_LEVEL
 *  @_adminPath     controller.currentLoop.currentControlPars.saturationLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_CC_SAT_LEVEL                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  sample time of current loop
 *
 *  @datatype       double
 *  @unit           [s]
 *  @firmwareDim    Hz
 *  @hostDim        Sec
 *  @minvalue       4000
 *  @maxvalue       96000
 *  @defaultvalue   32000
 *  @xmlPath        controller/currentLoop/SAC_PAR_CC_SAMPLE_TIME
 *  @_adminPath     controller.currentLoop.sampleTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_CC_SAMPLE_TIME                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @}
 */

/**
 *  @defgroup pwm pwm parameters
 *  @{
 */

/**
 *  @brief  chopper frequency of PWM controller
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       4000
 *  @maxvalue       96000
 *  @defaultvalue   32000
 *  @xmlPath        controller/pwmPars/SAC_PAR_PWM_FREQUENCY
 *  @_adminPath     controller.pwmPars.frequency
 *  @readOnly       FALSE
 */
#define SAC_PAR_PWM_FREQUENCY                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @}
 */

/**
 *  @addtogroup pid
 *  @{
 */

/**
 *  @brief  position controller output inversion
 *
 *  @datatype       SAC_INVERSION
 *  @defaultvalue   SAC_NO_INVERT
 *  @xmlPath        definitions/SAC_PAR_CONTROLLER_OUTPUT_INVERT
 *  @_adminPath     definitions.controllerOutputInvert
 *  @readOnly       FALSE
 */
#define SAC_PAR_CONTROLLER_OUTPUT_INVERT              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  position velocity loop sample time
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       1.0/32000.0
 *  @maxvalue       1.0/2000.0
 *  @defaultvalue   1.0/32000.0
 *  @xmlPath        controller/positionVelocityLoop/SAC_PAR_PVL_SAMPLE_TIME
 *  @_adminPath     controller.positionVelocityLoop.pvlSampleTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_PVL_SAMPLE_TIME                       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @}
 */

/**
 *  @addtogroup align
 *  @{
 */

/**
 *  @brief  commutation direction
 *
 *  @datatype       SAC_DIRECTION
 *  @defaultvalue   SAC_DIR_POSITIVE
 *  @xmlPath        definitions/SAC_PAR_COMMUTATION_DIRECTION
 *  @_adminPath     definitions.commutationDirection
 *  @readOnly       FALSE
 */
#define SAC_PAR_COMMUTATION_DIRECTION                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @}
 */

/**
 *  @addtogroup def
 *  @{
 */

/**
 *  @brief  measuring system single ended (TRUE) or differential (FALSE) mode.
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        definitions/SAC_PAR_S0S90_SINGLE_ENDED
 *  @_adminPath     definitions.s0s90SingleEnded
 *  @readOnly       FALSE
 */
#define SAC_PAR_S0S90_SINGLE_ENDED                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @}
 */

/**
 *  @defgroup cfg_axis axis config parameters
 *  @{
 */

/**
 *  @brief  axis type
 *
 *  @datatype       SAC_AXIS_TYPE
 *  @defaultvalue   SAC_NO_AXIS
 *  @xmlPath        configuration/axisPars/SAC_PAR_AXIS_TYPE
 *  @_adminPath     configuration.axisPars.axisType
 *  @readOnly       TRUE
 */
#define SAC_PAR_AXIS_TYPE                             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  slot identifier
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/axisPars/axisUnitId/SAC_PAR_AXIS_SLOT_ID
 *  @_adminPath     configuration.axisPars.axisUnitId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_AXIS_SLOT_ID                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  unit number
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @minvalue       -1
 *  @maxvalue       NYCE_MAX_UNIT_NR
 *  @defaultvalue   0
 *  @xmlPath        configuration/axisPars/axisUnitId/SAC_PAR_AXIS_UNIT_NR
 *  @_adminPath     configuration.axisPars.axisUnitId.axisUnitNr
 *  @readOnly       TRUE
 */
#define SAC_PAR_AXIS_UNIT_NR                          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  motor type
 *
 *  @datatype       SAC_MOTOR_TYPE
 *  @defaultvalue   SAC_NO_MOTOR
 *  @xmlPath        configuration/axisPars/SAC_PAR_MOTOR_TYPE
 *  @_adminPath     configuration.axisPars.motorType
 *  @readOnly       TRUE
 */
#define SAC_PAR_MOTOR_TYPE                            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  position sensor type
 *
 *  @datatype       SAC_POSITION_SENSOR_TYPE
 *  @defaultvalue   SAC_NO_POSITION_SENSOR
 *  @xmlPath        configuration/axisPars/SAC_PAR_POSITION_SENSOR_TYPE
 *  @_adminPath     configuration.axisPars.positionSensorType
 *  @readOnly       TRUE
 */
#define SAC_PAR_POSITION_SENSOR_TYPE                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLPSI<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  number of microsteps in a full step for a stepper motor
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @minvalue       1
 *  @maxvalue       4294967295
 *  @defaultvalue   1
 *  @xmlPath        configuration/axisPars/commutationPars/stepper/SAC_PAR_STEP_NR_OF_MICRO_STEPS
 *  @_adminPath     configuration.axisPars.commutationPars.stepper.nrOfMicroSteps
 *  @readOnly       TRUE
 */
#define SAC_PAR_STEP_NR_OF_MICRO_STEPS                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @}
 */

/**
 *  @addtogroup stepper
 *  @{
 */

/**
 *  @brief  time to compensate for calculation delay in the current controller for a stepper motor
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       -0.0005
 *  @maxvalue       0.0005
 *  @defaultvalue   0.0
 *  @xmlPath        configuration/axisPars/commutationPars/stepper/SAC_PAR_STEP_DELAY_COMPENSATION_TIME
 *  @_adminPath     configuration.axisPars.commutationPars.stepper.delayCompensationTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_STEP_DELAY_COMPENSATION_TIME          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @}
 */

/**
 *  @addtogroup cfg_axis
 *  @{
 */

/**
 *  @brief  number of pole pairs for a brushless AC motor
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @minvalue       1
 *  @maxvalue       4294967295
 *  @defaultvalue   1
 *  @xmlPath        configuration/axisPars/commutationPars/brushlessAC/SAC_PAR_BLAC_NR_OF_POLE_PAIRS
 *  @_adminPath     configuration.axisPars.commutationPars.brushlessAC.nrOfPolePairs
 *  @readOnly       TRUE
 */
#define SAC_PAR_BLAC_NR_OF_POLE_PAIRS                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  position units per number of pole pairs for a a brushless AC motor
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @firmwareDim    Inc
 *  @hostDim        Pu
 *  @minvalue       0.0
 *  @maxvalue       2147483647.0
 *  @defaultvalue   0.0
 *  @xmlPath        configuration/axisPars/commutationPars/brushlessAC/SAC_PAR_BLAC_PU_PER_NR_OF_POLE_PAIRS
 *  @_adminPath     configuration.axisPars.commutationPars.brushlessAC.puPerNrOfPolePairs
 *  @readOnly       TRUE
 */
#define SAC_PAR_BLAC_PU_PER_NR_OF_POLE_PAIRS          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_INC <<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  hall sensor input selection
 *
 *  @datatype       SAC_HALL_SENSOR_SET
 *  @defaultvalue   SAC_HALL_SENSOR_RS422
 *  @xmlPath        configuration/axisPars/commutationPars/brushlessDC/SAC_PAR_BLDC_HALL_SENSOR_SET
 *  @_adminPath     configuration.axisPars.commutationPars.brushlessDC.hallSensorSet
 *  @readOnly       TRUE
 */
#define SAC_PAR_BLDC_HALL_SENSOR_SET                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  signal of the three hall sensors for commutation step 0
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @minvalue       0
 *  @maxvalue       7
 *  @defaultvalue   6
 *  @xmlPath        configuration/axisPars/commutationPars/brushlessDC/SAC_PAR_BLDC_SIX_STEP_COMM_0
 *  @_adminPath     configuration.axisPars.commutationPars.brushlessDC.sixStepCommutation[0]
 *  @readOnly       TRUE
 */
#define SAC_PAR_BLDC_SIX_STEP_COMM_0                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  signal of the three hall sensors for commutation step 1
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @minvalue       0
 *  @maxvalue       7
 *  @defaultvalue   4
 *  @xmlPath        configuration/axisPars/commutationPars/brushlessDC/SAC_PAR_BLDC_SIX_STEP_COMM_1
 *  @_adminPath     configuration.axisPars.commutationPars.brushlessDC.sixStepCommutation[1]
 *  @readOnly       TRUE
 */
#define SAC_PAR_BLDC_SIX_STEP_COMM_1                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  signal of the three hall sensors for commutation step 2
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @minvalue       0
 *  @maxvalue       7
 *  @defaultvalue   5
 *  @xmlPath        configuration/axisPars/commutationPars/brushlessDC/SAC_PAR_BLDC_SIX_STEP_COMM_2
 *  @_adminPath     configuration.axisPars.commutationPars.brushlessDC.sixStepCommutation[2]
 *  @readOnly       TRUE
 */
#define SAC_PAR_BLDC_SIX_STEP_COMM_2                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  signal of the three hall sensors for commutation step 3
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @minvalue       0
 *  @maxvalue       7
 *  @defaultvalue   1
 *  @xmlPath        configuration/axisPars/commutationPars/brushlessDC/SAC_PAR_BLDC_SIX_STEP_COMM_3
 *  @_adminPath     configuration.axisPars.commutationPars.brushlessDC.sixStepCommutation[3]
 *  @readOnly       TRUE
 */
#define SAC_PAR_BLDC_SIX_STEP_COMM_3                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  signal of the three hall sensors for commutation step 4
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @minvalue       0
 *  @maxvalue       7
 *  @defaultvalue   3
 *  @xmlPath        configuration/axisPars/commutationPars/brushlessDC/SAC_PAR_BLDC_SIX_STEP_COMM_4
 *  @_adminPath     configuration.axisPars.commutationPars.brushlessDC.sixStepCommutation[4]
 *  @readOnly       TRUE
 */
#define SAC_PAR_BLDC_SIX_STEP_COMM_4                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  signal of the three hall sensors for commutation step 5
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @minvalue       0
 *  @maxvalue       7
 *  @defaultvalue   2
 *  @xmlPath        configuration/axisPars/commutationPars/brushlessDC/SAC_PAR_BLDC_SIX_STEP_COMM_5
 *  @_adminPath     configuration.axisPars.commutationPars.brushlessDC.sixStepCommutation[5]
 *  @readOnly       TRUE
 */
#define SAC_PAR_BLDC_SIX_STEP_COMM_5                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  pulse on time of external stepper drive
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0000001
 *  @maxvalue       0.001
 *  @defaultvalue   0.000001
 *  @xmlPath        configuration/axisPars/externalStepperPars/SAC_PAR_PULSE_ON_TIME
 *  @_adminPath     configuration.axisPars.externalStepperPars.pulseOnTime
 *  @readOnly       TRUE
 */
#define SAC_PAR_PULSE_ON_TIME                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  pulse off time of external stepper drive
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0000001
 *  @maxvalue       0.001
 *  @defaultvalue   0.000001
 *  @xmlPath        configuration/axisPars/externalStepperPars/SAC_PAR_PULSE_OFF_TIME
 *  @_adminPath     configuration.axisPars.externalStepperPars.pulseOffTime
 *  @readOnly       TRUE
 */
#define SAC_PAR_PULSE_OFF_TIME                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  time between changing the direction signal and generating the first pulse
 *          of external stepper drive
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0000001
 *  @maxvalue       0.001
 *  @defaultvalue   0.000001
 *  @xmlPath        configuration/axisPars/externalStepperPars/SAC_PAR_DIRECTION_DELAY_TIME
 *  @_adminPath     configuration.axisPars.externalStepperPars.directionDelayTime
 *  @readOnly       TRUE
 */
#define SAC_PAR_DIRECTION_DELAY_TIME                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  pulse output active level
 *
 *  The pulse output active level corresponds with the pulse on level
 *
 *  @datatype       NYCE_ACTIVE_STATE
 *  @defaultvalue   NYCE_ACTIVE_HIGH
 *  @xmlPath        configuration/axisPars/externalStepperPars/SAC_PAR_PULSE_ACTIVE_LEVEL
 *  @_adminPath     configuration.axisPars.externalStepperPars.pulseLevel
 *  @readOnly       TRUE
 */
#define SAC_PAR_PULSE_ACTIVE_LEVEL                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  direction output active level
 *
 *  The direction output active level corresponds with the positive movement direction
 *
 *  @datatype       NYCE_ACTIVE_STATE
 *  @defaultvalue   NYCE_ACTIVE_HIGH
 *  @xmlPath        configuration/axisPars/externalStepperPars/SAC_PAR_DIRECTION_ACTIVE_LEVEL
 *  @_adminPath     configuration.axisPars.externalStepperPars.directionLevel
 *  @readOnly       TRUE
 */
#define SAC_PAR_DIRECTION_ACTIVE_LEVEL                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXC<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @}
 */

/**
 *  @defgroup cfg_io config io parameters
 *  @{
 */

/**
 *  @brief  slot identifier for area switch
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/areaSensorPars/ioId/SAC_PAR_AREA_SENSOR_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_AREA_SENSOR].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_AREA_SENSOR_SLOT_ID                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  digital input identifier for area switch
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/areaSensorPars/ioId/SAC_PAR_AREA_SENSOR_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_AREA_SENSOR].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_AREA_SENSOR_DIG_IO_NR                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  slot identifier for latch 0
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/latch0Pars/ioId/SAC_PAR_LATCH0_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_0].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_LATCH0_SLOT_ID                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  digital input identifier for latch 0
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/latch0Pars/ioId/SAC_PAR_LATCH0_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_0].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_LATCH0_DIG_IO_NR                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  edge type for IndraDrive latch0
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        configuration/inputFunction/latch0Pars/SAC_PAR_INDRA_LATCH0_EDGE
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_0].edgeType
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_LATCH0_EDGE                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  slot identifier for latch 1
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/latch1Pars/ioId/SAC_PAR_LATCH1_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_1].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_LATCH1_SLOT_ID                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  digital input identifier for latch 1
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/latch1Pars/ioId/SAC_PAR_LATCH1_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_1].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_LATCH1_DIG_IO_NR                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  edge type for IndraDrive latch0
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        configuration/inputFunction/latch1Pars/SAC_PAR_INDRA_LATCH1_EDGE
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_1].edgeType
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_LATCH1_EDGE                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  slot identifier for latch 2
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/latch2Pars/ioId/SAC_PAR_LATCH2_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_2].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_LATCH2_SLOT_ID                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  digital input identifier for latch 2
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/latch2Pars/ioId/SAC_PAR_LATCH2_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_2].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_LATCH2_DIG_IO_NR                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  edge type for IndraDrive latch0
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        configuration/inputFunction/latch2Pars/SAC_PAR_INDRA_LATCH2_EDGE
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_2].edgeType
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_LATCH2_EDGE                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  slot identifier for latch 3
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/latch3Pars/ioId/SAC_PAR_LATCH3_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_3].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_LATCH3_SLOT_ID                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  digital input identifier for latch 3
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/latch3Pars/ioId/SAC_PAR_LATCH3_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_3].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_LATCH3_DIG_IO_NR                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  edge type for IndraDrive latch0
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        configuration/inputFunction/latch3Pars/SAC_PAR_INDRA_LATCH3_EDGE
 *  @_adminPath     configuration.ioFunction[SAC_LATCH_3].edgeType
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_LATCH3_EDGE                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  slot identifier for positive limit switch
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/posLimitSwitchPars/ioId/SAC_PAR_LIMIT_SWITCH_POS_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_POS_LIMIT_SWITCH].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_LIMIT_SWITCH_POS_SLOT_ID              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  digital input identifier for positive limit switch
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/posLimitSwitchPars/ioId/SAC_PAR_LIMIT_SWITCH_POS_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_POS_LIMIT_SWITCH].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_LIMIT_SWITCH_POS_DIG_IO_NR            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  slot identifier for negative limit switch
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/negLimitSwitchPars/ioId/SAC_PAR_LIMIT_SWITCH_NEG_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_NEG_LIMIT_SWITCH].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_LIMIT_SWITCH_NEG_SLOT_ID              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  digital input identifier for negative limit switch
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/negLimitSwitchPars/ioId/SAC_PAR_LIMIT_SWITCH_NEG_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_NEG_LIMIT_SWITCH].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_LIMIT_SWITCH_NEG_DIG_IO_NR            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  slot identifier for error 0
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/error0Pars/ioId/SAC_PAR_ERROR0_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_0].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR0_SLOT_ID                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  digital input identifier for error 0
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/error0Pars/ioId/SAC_PAR_ERROR0_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_0].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR0_DIG_IO_NR                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @brief  slot identifier for error 1
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/error1Pars/ioId/SAC_PAR_ERROR1_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_1].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR1_SLOT_ID                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @brief  digital input identifier for error 1
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/error1Pars/ioId/SAC_PAR_ERROR1_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_1].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR1_DIG_IO_NR                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  slot identifier for error 2
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/error2Pars/ioId/SAC_PAR_ERROR2_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_2].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR2_SLOT_ID                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  digital input identifier for error 2
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/error2Pars/ioId/SAC_PAR_ERROR2_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_2].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR2_DIG_IO_NR                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  slot identifier for error 3
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/error3Pars/ioId/SAC_PAR_ERROR3_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_3].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR3_SLOT_ID                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  digital input identifier for error 3
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/error3Pars/ioId/SAC_PAR_ERROR3_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_3].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR3_DIG_IO_NR                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  slot identifier for error 4
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/error4Pars/ioId/SAC_PAR_ERROR4_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_4].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR4_SLOT_ID                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  digital input identifier for error 4
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/error4Pars/ioId/SAC_PAR_ERROR4_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_4].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR4_DIG_IO_NR                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  slot identifier for error 5
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/error5Pars/ioId/SAC_PAR_ERROR5_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_5].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR5_SLOT_ID                        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  digital input identifier for error 5
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/error5Pars/ioId/SAC_PAR_ERROR5_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_ERROR_5].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_ERROR5_DIG_IO_NR                      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  slot identifier for start trigger
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/startTriggerPars/ioId/SAC_PAR_START_TRIGGER_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_START_TRIGGER].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_START_TRIGGER_SLOT_ID                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  digital input identifier for start trigger
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/startTriggerPars/ioId/SAC_PAR_START_TRIGGER_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_START_TRIGGER].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_START_TRIGGER_DIG_IO_NR               ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  edge type for start trigger
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @xmlPath        configuration/inputFunction/startTriggerPars/SAC_PAR_START_TRIGGER_EDGE
 *  @_adminPath     configuration.ioFunction[SAC_START_TRIGGER].edgeType
 *  @readOnly       FALSE
 */
#define SAC_PAR_START_TRIGGER_EDGE                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  slot identifier for stop trigger
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/stopTriggerPars/ioId/SAC_PAR_STOP_TRIGGER_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_STOP_TRIGGER].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_STOP_TRIGGER_SLOT_ID                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  digital input identifier for stop trigger
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/stopTriggerPars/ioId/SAC_PAR_STOP_TRIGGER_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_STOP_TRIGGER].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_STOP_TRIGGER_DIG_IO_NR                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  edge type for stop trigger
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @xmlPath        configuration/inputFunction/stopTriggerPars/SAC_PAR_STOP_TRIGGER_EDGE
 *  @_adminPath     configuration.ioFunction[SAC_STOP_TRIGGER].edgeType
 *  @readOnly       FALSE
 */
#define SAC_PAR_STOP_TRIGGER_EDGE                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @brief  slot identifier for brake
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/outputFunction/brakePars/ioId/SAC_PAR_BRAKE_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_RELEASE_BRAKE].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_BRAKE_SLOT_ID                         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|37))

/**
 *  @brief  digital output identifier for brake
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/outputFunction/brakePars/ioId/SAC_PAR_BRAKE_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_RELEASE_BRAKE].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_BRAKE_DIG_IO_NR                       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|38))

/**
 *  @brief  slot identifier for external drive enable
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/outputFunction/driveEnablePars/ioId/SAC_PAR_EXT_DRIVE_EN_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_EXT_DRIVE_ENABLE].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_EXT_DRIVE_EN_SLOT_ID                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|39))

/**
 *  @brief  digital output identifier for external drive enable
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/outputFunction/driveEnablePars/ioId/SAC_PAR_EXT_DRIVE_EN_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_EXT_DRIVE_ENABLE].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_EXT_DRIVE_EN_DIG_IO_NR                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|40))

/**
 *  @brief  slot identifier for IndraDrive E-Stop
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/eStopPars/ioId/SAC_PAR_INDRA_E_STOP_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_E_STOP].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_INDRA_E_STOP_SLOT_ID                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|41))

/**
 *  @brief  digital output identifier for IndraDrive E-Stop
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/inputFunction/eStopPars/ioId/SAC_PAR_INDRA_E_STOP_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_E_STOP].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_INDRA_E_STOP_DIG_IO_NR                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|42))

/**
 *  @brief  slot identifier for IndraDrive position switch
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/outputFunction/positionSwitchPars/ioId/SAC_PAR_INDRA_POSITION_SWITCH_SLOT_ID
 *  @_adminPath     configuration.ioFunction[SAC_POSITION_SWITCH].ioId.slotId
 *  @readOnly       TRUE
 */
#define SAC_PAR_INDRA_POSITION_SWITCH_SLOT_ID         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|43))

/**
 *  @brief  digital output identifier for IndraDrive position switch
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        configuration/outputFunction/positionSwitchPars/ioId/SAC_PAR_INDRA_POSITION_SWITCH_DIG_IO_NR
 *  @_adminPath     configuration.ioFunction[SAC_POSITION_SWITCH].ioId.digIONr
 *  @readOnly       TRUE
 */
#define SAC_PAR_INDRA_POSITION_SWITCH_DIG_IO_NR       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|44))

/**
 *  @brief  IndraDrive digital I/O active mask
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0xFFFFFFFF
 *  @xmlPath        configuration/ioPars/SAC_PAR_INDRA_IO_ACTIVE_MASK
 *  @_adminPath     configuration.indraIOPars.indraDigIOActMask
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_IO_ACTIVE_MASK                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|45))

/**
 *  @brief  IndraDrive start level mask
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        configuration/ioPars/SAC_PAR_INDRA_START_LEVEL_MASK
 *  @_adminPath     configuration.indraIOPars.indraStartLevelMask
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_START_LEVEL_MASK                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|46))

/**
 *  @brief  Slot identifier for LMS sensor supply
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        configuration/inputFunction/sensorSupplyPars/anInId/SAC_PAR_LMS_SENSOR_SUPPLY_SLOT_ID
 *  @_adminPath     configuration.inputFunction.sensorSupplyPars.anInId.slotId
 *  @readOnly       FALSE
 */
#define SAC_PAR_LMS_SENSOR_SUPPLY_SLOT_ID       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|47))

/**
 *  @brief  Analog input identifier for LMS sensor supply
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @minvalue       0
 *  @maxvalue       7
 *  @defaultvalue   0
 *  @xmlPath        configuration/inputFunction/sensorSupplyPars/anInId/SAC_PAR_LMS_SENSOR_SUPPLY_ANIN_ID
 *  @_adminPath     configuration.inputFunction.sensorSupplyPars.anInId.anInNr
 *  @readOnly       FALSE
 */
#define SAC_PAR_LMS_SENSOR_SUPPLY_ANIN_ID       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|48))

/**
 *  @}
 */

/**
 *  @addtogroup def
 *  @{
 */

/**
 *  @brief  ECG prediction filter frequency, the maximum allowed value is sample frequency * 0.49
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       1.0
 *  @maxvalue       1.0e+12
 *  @defaultvalue   30.0
 *  @xmlPath        motion/ecgPars/SAC_PAR_ECG_PREDICTION_FILTER_FREQ
 *  @_adminPath     motion.ecgPars.ecgPredictionFilterFreq
 *  @readOnly       FALSE
 */
#define SAC_PAR_ECG_PREDICTION_FILTER_FREQ            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_ECGFIL<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  ECG prediction filter, number of samples to be looked ahead
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -2.0
 *  @maxvalue       8.0
 *  @defaultvalue   3.0
 *  @xmlPath        motion/ecgPars/SAC_PAR_ECG_PREDICTION_HORIZON
 *  @_adminPath     motion.ecgPars.ecgPredictionHorizon
 *  @readOnly       FALSE
 */
#define SAC_PAR_ECG_PREDICTION_HORIZON                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_ECGFIL<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @}
 */

/**
 *  @defgroup encoder encoder parameters
 *  @{
 */

/**
 *  @brief  threshold of the SinCos index level
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   2.5
 *  @xmlPath        configuration/axisPars/encoderPars/sincos/SAC_PAR_SINCOS_INDEX_LEVEL_THRESHOLD
 *  @_adminPath     configuration.axisPars.encoderPars.sincos.indexLevelThreshold
 *  @readOnly       FALSE
 */
#define SAC_PAR_SINCOS_INDEX_LEVEL_THRESHOLD          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLPSI<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  minimal SinCos top-top value
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       0.1
 *  @maxvalue       4.0
 *  @defaultvalue   0.5
 *  @xmlPath        configuration/axisPars/encoderPars/sincos/SAC_PAR_SINCOS_MIN_ERROR_LEVEL
 *  @_adminPath     configuration.axisPars.encoderPars.sincos.minErrorLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_SINCOS_MIN_ERROR_LEVEL                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLPSI<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  maximal SinCos top-top value
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       1.0
 *  @maxvalue       7.5
 *  @defaultvalue   1.5
 *  @xmlPath        configuration/axisPars/encoderPars/sincos/SAC_PAR_SINCOS_MAX_ERROR_LEVEL
 *  @_adminPath     configuration.axisPars.encoderPars.sincos.maxErrorLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_SINCOS_MAX_ERROR_LEVEL                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLPSI<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  SinCos interpolation factor per full period
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @minvalue       4
 *  @maxvalue       4096
 *  @defaultvalue   4096
 *  @xmlPath        configuration/axisPars/encoderPars/sincos/SAC_PAR_SINCOS_INTERPOLATION_FACTOR
 *  @_adminPath     configuration.axisPars.encoderPars.sincos.interpolationFactor
 *  @readOnly       FALSE
 */
#define SAC_PAR_SINCOS_INTERPOLATION_FACTOR           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLPSI<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  EnDat clock frequency
 *
 *  @datatype       uint32_t
 *  @unit           [Hz]
 *  @minvalue       100000
 *  @maxvalue       4000000
 *  @defaultvalue   1000000
 *  @xmlPath        configuration/axisPars/encoderPars/endat/SAC_PAR_ENDAT_CLOCK_FREQUENCY
 *  @_adminPath     configuration.axisPars.encoderPars.endat.clockFrequency
 *  @readOnly       FALSE
 */
#define SAC_PAR_ENDAT_CLOCK_FREQUENCY                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLPSI<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  hiperface parity bit
 *
 *  @datatype       SAC_PARITY_BIT
 *  @defaultvalue   SAC_PARITY_ODD
 *  @xmlPath        configuration/axisPars/encoderPars/hiperface/SAC_PAR_HIPERFACE_PARITY_BIT
 *  @_adminPath     configuration.axisPars.encoderPars.hiperface.parityBit
 *  @readOnly       FALSE
 */
#define SAC_PAR_HIPERFACE_PARITY_BIT                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLPSI<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  hiperface communication speed
 *
 *  @datatype       uint32_t
 *  @unit           [Bd]
 *  @minvalue       1
 *  @maxvalue       2147483647
 *  @defaultvalue   9600
 *  @xmlPath        configuration/axisPars/encoderPars/hiperface/SAC_PAR_HIPERFACE_BAUD_RATE
 *  @_adminPath     configuration.axisPars.encoderPars.hiperface.baudRate
 *  @readOnly       FALSE
 */
#define SAC_PAR_HIPERFACE_BAUD_RATE                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLPSI<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  SinCos encoder index polarity
 *
 *  @datatype       NYCE_ACTIVE_STATE
 *  @defaultvalue   NYCE_ACTIVE_LOW
 *  @xmlPath        configuration/axisPars/encoderPars/sincos/SAC_PAR_SINCOS_INDEX_POLARITY
 *  @_adminPath     configuration.axisPars.encoderPars.sincos.polarity
 *  @readOnly       FALSE
 */
#define SAC_PAR_SINCOS_INDEX_POLARITY                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLPSI<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  Glitch suppression time for quadrature and sine/cosine based encoders
 *
 *  @datatype       uint32_t
 *  @unit           [nr of clock ticks of 32ns]
 *  @minvalue       0
 *  @maxvalue       31
 *  @defaultvalue   0
 *  @xmlPath        configuration/axisPars/encoderPars/sincos/SAC_PAR_ENCODER_GLITCH_SUPPRESSION_TIME
 *  @_adminPath     configuration.axisPars.encoderPars.sincos.encoderGlitchSuppressionTime
 *  @readOnly       FALSE
 */
#define SAC_PAR_ENCODER_GLITCH_SUPPRESSION_TIME       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLPSI<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @}
 */

/**
 *  @addtogroup cfg_io
 *  @{
 */

/**
 *  @brief  IndraDrive minimum analog input level
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   -100.0
 *  @xmlPath        configuration/ioPars/SAC_PAR_INDRA_ANIN0_MIN_LEVEL
 *  @_adminPath     configuration.indraIOPars.indraAnIn0MinLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_ANIN0_MIN_LEVEL                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  IndraDrive maximum analog input level
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   100
 *  @xmlPath        configuration/ioPars/SAC_PAR_INDRA_ANIN0_MAX_LEVEL
 *  @_adminPath     configuration.indraIOPars.indraAnIn0MaxLevel
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_ANIN0_MAX_LEVEL                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  IndraDrive digital I/O event mask
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        configuration/ioPars/SAC_PAR_INDRA_IO_EVENT_MASK
 *  @_adminPath     configuration.indraIOPars.indraDigIOEvMask
 *  @readOnly       FALSE
 */
#define SAC_PAR_INDRA_IO_EVENT_MASK                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @}
 */

/**
 *  @addtogroup def
 *  @{
 */

/**
 *  @brief  Force threshold
 *
 *  @datatype       double
 *  @unit           [N]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   100
 *  @xmlPath        configuration/pfcPars/SAC_PAR_PFC_FORCE_THRESHOLD
 *  @_adminPath     configuration.pfcPars.forceThreshold
 *  @readOnly       FALSE
 */
#define SAC_PAR_PFC_FORCE_THRESHOLD                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @}
 */

/**
 *  @defgroup err_handler error handler parameters
 *  @{
 */

/**
 *  @brief  no axis error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_NONE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        -
 *  @_adminPath     edh.errorHandling[SAC_AX_NO_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_NO_ERROR                           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  error handler for axis error cable alarm
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_CABLE_ALARM
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_CABLE_ALARM & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_CABLE_ALARM                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  error handler for axis error position error exceeded
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_POSITION_ERROR_EXCEEDED
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_POSITION_ERROR_EXCEEDED & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_POSITION_ERROR_EXCEEDED        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  error handler for axis error positive software end switch
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_POS_SW_END_SWITCH
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_POS_SW_END_SWITCH & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_POS_SW_END_SWITCH              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  error handler for axis error negative software end switch
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_NEG_SW_END_SWITCH
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_NEG_SW_END_SWITCH & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_NEG_SW_END_SWITCH              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  error handler for axis error steady state error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_STEADY_STATE_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_STEADY_STATE_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_STEADY_STATE_ERROR             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  error handler for axis error spline buffer empty
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_SMOOTH_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_SPLINE_BUFFER_EMPTY
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_SPLINE_BUFFER_EMPTY & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_SPLINE_BUFFER_EMPTY            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  error handler for axis error collision detection
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_COLLISION_DETECTION
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_COLLISION_DETECTION & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_COLLISION_DETECTION            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  error handler for axis error stop axes input
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_SMOOTH_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_STOP_AXES_INPUT
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_STOP_AXES_INPUT & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_STOP_AXES_INPUT           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  error handler for axis error error 0 input
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_ERROR_0_INPUT
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_ERROR_0_INPUT & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_ERROR_0_INPUT                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  error handler for axis error error 1 input
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_ERROR_1_INPUT
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_ERROR_1_INPUT & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_ERROR_1_INPUT                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  error handler for axis error error 2 input
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_ERROR_2_INPUT
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_ERROR_2_INPUT & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_ERROR_2_INPUT                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  error handler for axis error error 3 input
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_ERROR_3_INPUT
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_ERROR_3_INPUT & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_ERROR_3_INPUT                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  error handler for axis error error 4 input
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_ERROR_4_INPUT
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_ERROR_4_INPUT & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_ERROR_4_INPUT                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  error handler for axis error error 5 input
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_ERROR_5_INPUT
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_ERROR_5_INPUT & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_ERROR_5_INPUT                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  error handler for axis error NY4125 and NY4130 specific stop alarm
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_OPEN_LOOP
 *  @minvalue       SAC_ERRH_OPEN_LOOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_STOP_ALARM
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_STOP_ALARM & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_STOP_ALARM                     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  error handler for axis error positive limit switch input
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_POS_LIMIT_SWITCH_INPUT
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_POS_LIMIT_SWITCH_INPUT & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_POS_LIMIT_SWITCH_INPUT         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  error handler for axis error negative limit switch input
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_NEG_LIMIT_SWITCH_INPUT
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_NEG_LIMIT_SWITCH_INPUT & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_NEG_LIMIT_SWITCH_INPUT         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  error handler for axis error peer warning
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_PEER_WARNING
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_PEER_WARNING & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_PEER_WARNING                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  error handler for axis error peer smooth stop
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_PEER_SMOOTH_STOP
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_PEER_SMOOTH_STOP & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_PEER_SMOOTH_STOP               ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  error handler for axis error peer quick stop
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_PEER_QUICK_STOP
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_PEER_QUICK_STOP & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_PEER_QUICK_STOP                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @brief  error handler for axis error peer full stop
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_PEER_FULL_STOP
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_PEER_FULL_STOP & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_PEER_FULL_STOP                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @brief  error handler for axis error peer quick stop, open loop
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_PEER_QSTOP_OPEN_LOOP
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_PEER_QSTOP_OPEN_LOOP & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_PEER_QSTOP_OPEN_LOOP           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  error handler for axis error peer open loop
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_PEER_OPEN_LOOP
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_PEER_OPEN_LOOP & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_PEER_OPEN_LOOP                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  error handler for axis error peer open loop, disable drive
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_PEER_DISABLE_DRIVE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_PEER_DISABLE_DRIVE & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_PEER_DISABLE_DRIVE             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  error handler for axis error peer open loop, disable drive, position lost
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_PEER_POS_CORRUPTED
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_PEER_POS_CORRUPTED & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_PEER_POS_CORRUPTED             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  error handler for axis error peer shutdown
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_COMMUNICATION_LOST
 *  @minvalue       SAC_ERRH_COMMUNICATION_LOST
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_PEER_COMMUNICATION_LOST
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_PEER_COMMUNICATION_LOST & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_PEER_COMMUNICATION_LOST        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  error handler for axis error phase alarm
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_PHASE_ALARM
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_PHASE_ALARM & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_PHASE_ALARM                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  error handler for axis error master direction error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_SMOOTH_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MASTER_DIRECTION_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MASTER_DIRECTION_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MASTER_DIRECTION_ERROR         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  error handler for axis error master position overflow
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_SMOOTH_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MASTER_POSITION_OVERFLOW
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MASTER_POSITION_OVERFLOW & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MASTER_POSITION_OVERFLOW       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  error handler for axis error master position lost
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_SMOOTH_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MASTER_POSITION_LOSS
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MASTER_POSITION_LOSS & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MASTER_POSITION_LOSS           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  error handler for axis error settling time error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_SETTLING_TIME_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_SETTLING_TIME_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_SETTLING_TIME_ERROR            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  error handler for axis error positive servo over voltage
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_POS_SERVO_OVER_VOLTAGE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_POS_SERVO_OVER_VOLTAGE & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_POS_SERVO_OVER_VOLTAGE         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  error handler for axis error positive servo under voltage
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_QUICK_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_POS_SERVO_UNDER_VOLTAGE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_POS_SERVO_UNDER_VOLTAGE & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_POS_SERVO_UNDER_VOLTAGE        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  error handler for axis error negative servo under voltage
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_QUICK_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_NEG_SERVO_UNDER_VOLTAGE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_NEG_SERVO_UNDER_VOLTAGE & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_NEG_SERVO_UNDER_VOLTAGE        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  error handler for axis error negative servo over voltage
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_NEG_SERVO_OVER_VOLTAGE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_NEG_SERVO_OVER_VOLTAGE & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_NEG_SERVO_OVER_VOLTAGE         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  error handler for axis error over temperature
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_OVER_TEMPERATURE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_OVER_TEMPERATURE & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_OVER_TEMPERATURE               ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @brief  error handler for axis error maximum velocity exceeded
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MAX_VELOCITY_EXCEEDED
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MAX_VELOCITY_EXCEEDED & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MAX_VELOCITY_EXCEEDED          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|37))

/**
 *  @brief  error handler for axis error maximum acceleration exceeded
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MAX_ACCELERATION_EXCEEDED
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MAX_ACCELERATION_EXCEEDED & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MAX_ACCELERATION_EXCEEDED      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|38))

/**
 *  @brief  error handler for axis error maximum jerk exceeded
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MAX_JERK_EXCEEDED
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MAX_JERK_EXCEEDED & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MAX_JERK_EXCEEDED              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|39))

/**
 *  @brief  error handler for axis error over current
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_DISABLE_DRIVE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_OVER_CURRENT
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_OVER_CURRENT & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_OVER_CURRENT                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|40))

/**
 *  @brief  error handler for axis error invalid hall sensor
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_INVALID_HALL_SENSOR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_INVALID_HALL_SENSOR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_INVALID_HALL_SENSOR            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|41))

/**
 *  @brief  error handler for axis error communication error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_COMMUNICATION_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_COMMUNICATION_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_COMMUNICATION_ERROR            ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|42))

/**
 *  @brief  error handler for axis error network error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_NETWORK_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_NETWORK_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_NETWORK_ERROR                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|43))

/**
 *  @brief  error handler for axis error marker missed
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MARKER_MISSED
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MARKER_MISSED & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MARKER_MISSED                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|44))

/**
 *  @brief  error handler for axis error maximum current level exceeded
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MAX_CURRENT_LEVEL_EXCEEDED
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MAX_CURRENT_LEVEL_EXCEEDED & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MAX_CURRENT_LEVEL_EXCEEDED     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|45))

/**
 *  @brief  error handler for axis error maximum drive I2t level exceeded
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_DRIVE_MAX_I2T_LEVEL_EXCEEDED
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_DRIVE_MAX_I2T_LEVEL_EXCEEDED & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_DRIVE_MAX_I2T_LEVEL_EXCEEDED   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|46))

/**
 *  @brief  error handler for axis error short circuit
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_DISABLE_DRIVE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_SHORT_CIRCUIT
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_SHORT_CIRCUIT & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_SHORT_CIRCUIT                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|47))

/**
 *  @brief  error handler for axis error EnDat2.2 general encoder error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_GENERAL_ENCODER_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_GENERAL_ENCODER_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_GENERAL_ENCODER_ERROR          ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|48))

/**
 *  @brief  error handler for axis error Rexroth MSM incremental encoder ABSA counter value invalid
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MSM_COUNT_ERROR_1
 *  @_adminPath     edh.errorHandling[SAC_PAR_AX_ERR_MSM_COUNT_ERROR_1 & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MSM_COUNT_ERROR_1              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|49))

/**
 *  @brief  error handler for axis error Rexroth MSM incremental encoder number of edges in AB phase between CS phase edges invalid
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MSM_COUNT_ERROR_2
 *  @_adminPath     edh.errorHandling[SAC_PAR_AX_ERR_MSM_COUNT_ERROR_2 & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MSM_COUNT_ERROR_2              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|50))

/**
 *  @brief  error handler for axis error Rexroth MSM incremental encoder Z-signal error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_OPEN_LOOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MSM_Z_ERROR
 *  @_adminPath     edh.errorHandling[SAC_PAR_AX_ERR_MSM_Z_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MSM_Z_ERROR                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|51))

/**
 *  @brief  error handler for axis error Rexroth MSM incremental encoder CS phase logic error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MSM_CS_ERROR
 *  @_adminPath     edh.errorHandling[SAC_PAR_AX_ERR_MSM_CS_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MSM_CS_ERROR                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|52))

/**
 *  @brief  error handler for axis error maximum motor I2t level exceeded
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MOTOR_MAX_I2T_LEVEL_EXCEEDED
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MOTOR_MAX_I2T_LEVEL_EXCEEDED & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
*/
#define SAC_PAR_AX_ERR_MOTOR_MAX_I2T_LEVEL_EXCEEDED   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|53))

/**
 *  @brief  error handler for axis error Rexroth MSM absolute encoder shaft revolution speed too large when main power SW is turned off
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_OPEN_LOOP
 *  @minvalue       SAC_ERRH_OPEN_LOOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MSM_OVER_SPEED
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MSM_OVER_SPEED & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MSM_OVER_SPEED                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|54))

/**
 *  @brief  error handler for axis error Rexroth MSM absolute encoder shaft revolution speed too large when main power SW is turned on
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_OPEN_LOOP
 *  @minvalue       SAC_ERRH_OPEN_LOOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MSM_FULL_ABSOLUTE_STATUS
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MSM_FULL_ABSOLUTE_STATUS & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MSM_FULL_ABSOLUTE_STATUS       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|55))

/**
 *  @brief  error handler for axis error Rexroth MSM absolute encoder shaft revolution error if main power SW is on
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MSM_COUNT_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MSM_COUNT_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MSM_COUNT_ERROR                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|56))

/**
 *  @brief  error handler for axis error Rexroth MSM absolute encoder multiple revolution counter error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MSM_MULTIPLE_REVOLUTION_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MSM_MULTIPLE_REVOLUTION_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MSM_MULTIPLE_REVOLUTION_ERROR  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|57))

/**
 *  @brief  error handler for axis error Rexroth MSM absolute encoder supply voltage beneath 2.5 volts
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MSM_SYSTEM_DOWN
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MSM_SYSTEM_DOWN & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MSM_SYSTEM_DOWN                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|58))

/**
 *  @brief  error handler for axis error Rexroth MSM and Sanyo Denki multi-turn absolute encoders battery supply voltage beneath ~3.2 volts
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_ENCODER_BATTERY_WARNING
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_ENCODER_BATTERY_WARNING & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_ENCODER_BATTERY_WARNING        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|59))

/**
 *  @brief  error handler for axis error SinCos encoder signal too weak
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_SINCOS_SIGNAL_TOO_WEAK
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_SINCOS_SIGNAL_TOO_WEAK & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_SINCOS_SIGNAL_TOO_WEAK         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|60))

/**
 *  @brief  error handler for axis error SinCos encoder signal too strong
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_SINCOS_SIGNAL_TOO_STRONG
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_SINCOS_SIGNAL_TOO_STRONG & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_SINCOS_SIGNAL_TOO_STRONG       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|61))

/**
 *  @brief  error handler for axis error Encoder communication lost
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_ENCODER_COMMUNICATION_LOST
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_ENCODER_COMMUNICATION_LOST & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_ENCODER_COMMUNICATION_LOST     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|62))

/**
 *  @brief  error handler for axis error maximum axis velocity exceeded
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_SMOOTH_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MAX_AXIS_VELOCITY_EXCEEDED
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MAX_AXIS_VELOCITY_EXCEEDED & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MAX_AXIS_VELOCITY_EXCEEDED     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|63))

/**
 *  @brief  error handler for axis 32 bits setpoint overflow
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_QUICK_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_SETPOINT_OVERFLOW
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_SETPOINT_OVERFLOW & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_SETPOINT_OVERFLOW              ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|64))

/**
 *  @brief  error handler for axis commutation correction error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QSTOP_OPEN_LOOP
 *  @minvalue       SAC_ERRH_SMOOTH_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_COMMUTATION_CORRECTION_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_COMMUTATION_CORRECTION_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_COMMUTATION_CORRECTION_ERROR   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|65))

/**
 *  @brief  error handler for external stepper velocity error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_DISABLE_DRIVE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_EXT_STEPPER_VELOCITY_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_EXT_STEPPER_VELOCITY_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
*/
#define SAC_PAR_AX_ERR_EXT_STEPPER_VELOCITY_ERROR   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|66))

/**
 *  @brief  error handler for sample overrun error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_SAMPLE_OVERRUN
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_SAMPLE_OVERRUN & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_SAMPLE_OVERRUN                 ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|67))

/**
 *  @brief  error handler for 19 bits position error overflow error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_OPEN_LOOP
 *  @minvalue       SAC_ERRH_OPEN_LOOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_POSITION_ERROR_OVERFLOW
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_POSITION_ERROR_OVERFLOW & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_POSITION_ERROR_OVERFLOW        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|68))

/**
 *  @brief  error handler for drive_temperature too high
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_DISABLE_DRIVE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_DRIVE_TEMPERATURE_TOO_HIGH
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_DRIVE_TEMPERATURE_TOO_HIGH & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_DRIVE_TEMPERATURE_TOO_HIGH     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|69))

/**
 *  @brief  error handler for positive drive voltage too high
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_DISABLE_DRIVE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_POS_DRIVE_VOLTAGE_TOO_HIGH
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_POS_DRIVE_VOLTAGE_TOO_HIGH & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_POS_DRIVE_VOLTAGE_TOO_HIGH     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|70))

/**
 *  @brief  error handler for positive drive voltage too low
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_DISABLE_DRIVE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_POS_DRIVE_VOLTAGE_TOO_LOW
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_POS_DRIVE_VOLTAGE_TOO_LOW & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_POS_DRIVE_VOLTAGE_TOO_LOW      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|71))

/**
 *  @brief  error handler for negative drive voltage too low
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_DISABLE_DRIVE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_NEG_DRIVE_VOLTAGE_TOO_LOW
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_NEG_DRIVE_VOLTAGE_TOO_LOW & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_NEG_DRIVE_VOLTAGE_TOO_LOW      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|72))

/**
 *  @brief  error handler for negative drive voltage too high
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_DISABLE_DRIVE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_NEG_DRIVE_VOLTAGE_TOO_HIGH
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_NEG_DRIVE_VOLTAGE_TOO_HIGH & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_NEG_DRIVE_VOLTAGE_TOO_HIGH     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|73))

/**
 *  @brief  error handler for axis error IndraDrive error or fatal warning
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_DISABLE_DRIVE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_INDRA_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_INDRA_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_INDRA_ERROR                    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|74))

/**
 *  @brief  error handler for axis error IndraDrive non fatal warning
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_WARNING
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_INDRA_WARNING
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_INDRA_WARNING & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_INDRA_WARNING                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|75))

/**
 *  @brief  error handler for axis error IndraDrive SERCOS network error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_COMMUNICATION_LOST
 *  @minvalue       SAC_ERRH_COMMUNICATION_LOST
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_SERCOS_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_SERCOS_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_SERCOS_ERROR                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|76))

/**
 *  @brief  error handler for axis error Microware error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_COMMUNICATION_LOST
 *  @minvalue       SAC_ERRH_COMMUNICATION_LOST
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_MICROWARE_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_MICROWARE_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_MICROWARE_ERROR                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|77))

/**
 *  @brief  error handler for axis error Drivelink error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_COMMUNICATION_LOST
 *  @minvalue       SAC_ERRH_COMMUNICATION_LOST
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_DRIVELINK_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_DRIVELINK_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_DRIVELINK_ERROR                ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|78))

/**
 *  @brief  error handler for axis error Drivelink read claim error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_COMMUNICATION_LOST
 *  @minvalue       SAC_ERRH_COMMUNICATION_LOST
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_DL_SYNC_READ_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_DL_SYNC_READ_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_DL_SYNC_READ_ERROR             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|79))

/**
 *  @brief  error handler for axis error NY4120, NY4125 and NY4140 specific disable drive
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_DISABLE_DRIVE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_DISABLE_DRIVE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_DISABLE_DRIVE & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_DISABLE_DRIVE                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|80))

/**
 *  @brief  error handler for user error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_NONE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_USER_ERROR_0
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_USER_ERROR_0 & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_USER_ERROR_0                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|81))

/**
 *  @brief  error handler for user error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_NONE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_USER_ERROR_1
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_USER_ERROR_1 & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_USER_ERROR_1                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|82))

/**
 *  @brief  error handler for user error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_NONE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_USER_ERROR_2
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_USER_ERROR_2 & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_USER_ERROR_2                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|83))

/**
 *  @brief  error handler for user error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_NONE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_USER_ERROR_3
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_USER_ERROR_3 & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_USER_ERROR_3                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|84))

/**
 *  @brief  error handler for user error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_NONE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_USER_ERROR_4
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_USER_ERROR_4 & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_USER_ERROR_4                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|85))

/**
 *  @brief  error handler for user error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_NONE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_USER_ERROR_5
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_USER_ERROR_5 & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_USER_ERROR_5                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|86))

/**
 *  @brief  error handler for user error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_NONE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_USER_ERROR_6
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_USER_ERROR_6 & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_USER_ERROR_6                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|87))

/**
 *  @brief  error handler for user error
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_NONE
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_USER_ERROR_7
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_USER_ERROR_7 & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_USER_ERROR_7                   ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|88))

/**
 *  @brief  error handler for axis error left sensor unexpected active
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_LMS_LEFT_SENSOR_ACTIVE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_LMS_LEFT_SENSOR_ACTIVE & NYCE_INDEX_MASK]
 */
#define SAC_PAR_AX_ERR_LMS_LEFT_SENSOR_ACTIVE         ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|89))

/**
 *  @brief  error handler for axis error left sensor unexpected inactive
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_LMS_LEFT_SENSOR_INACTIVE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_LMS_LEFT_SENSOR_INACTIVE & NYCE_INDEX_MASK]
 */
#define SAC_PAR_AX_ERR_LMS_LEFT_SENSOR_INACTIVE       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|90))

/**
 *  @brief  error handler for axis error middle sensor unexpected active
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_LMS_MIDDLE_SENSOR_ACTIVE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_LMS_MIDDLE_SENSOR_ACTIVE & NYCE_INDEX_MASK]
 */
#define SAC_PAR_AX_ERR_LMS_MIDDLE_SENSOR_ACTIVE       ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|91))

/**
 *  @brief  error handler for axis error middle sensor unexpected inactive
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_LMS_MIDDLE_SENSOR_INACTIVE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_LMS_MIDDLE_SENSOR_INACTIVE & NYCE_INDEX_MASK]
 */
#define SAC_PAR_AX_ERR_LMS_MIDDLE_SENSOR_INACTIVE     ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|92))

/**
 *  @brief  error handler for axis error right sensor unexpected active
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_LMS_RIGHT_SENSOR_ACTIVE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_LMS_RIGHT_SENSOR_ACTIVE & NYCE_INDEX_MASK]
 */
#define SAC_PAR_AX_ERR_LMS_RIGHT_SENSOR_ACTIVE        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|93))

/**
 *  @brief  error handler for axis error right sensor unexpected inactive
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_LMS_RIGHT_SENSOR_INACTIVE
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_LMS_RIGHT_SENSOR_INACTIVE & NYCE_INDEX_MASK]
 */
#define SAC_PAR_AX_ERR_LMS_RIGHT_SENSOR_INACTIVE      ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|94))

/**
 *  @brief  error handler for axis error setpoint unavailable
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_QUICK_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_LMS_SETPOINT_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_LMS_SETPOINT_ERROR & NYCE_INDEX_MASK]
 */
#define SAC_PAR_AX_ERR_LMS_SETPOINT_ERROR             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|95))

/**
 *  @brief  error handler for axis error setpoint unavailable
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_QUICK_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_LMS_CAR_SWITCH_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_LMS_CAR_SWITCH_ERROR & NYCE_INDEX_MASK]
 */
#define SAC_PAR_AX_ERR_LMS_CAR_SWITCH_ERROR           ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|96))

/**
 *  @brief  error handler for axis error gap cannot be closed
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_QUICK_STOP
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_LMS_GAP_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_LMS_GAP_ERROR & NYCE_INDEX_MASK]
 */
#define SAC_PAR_AX_ERR_LMS_GAP_ERROR                  ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|97))

/**
 *  @brief  error handler for axis error sensor supply voltage
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_POS_CORRUPTED
 *  @minvalue       SAC_ERRH_POS_CORRUPTED
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_LMS_SENSOR_SUPPLY_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_LMS_SENSOR_SUPPLY_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_LMS_SENSOR_SUPPLY_ERROR        ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|98))

/**
 *  @brief  error handler for axis error commutation angle
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_DISABLE_DRIVE
 *  @minvalue       SAC_ERRH_DISABLE_DRIVE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_LMS_COMMUTATION_ANGLE_ERROR
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_LMS_COMMUTATION_ANGLE_ERROR & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_LMS_COMMUTATION_ANGLE_ERROR    ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|99))

/**
 *  @brief  error handler for axis error ptp segment buffer overrun
 *
 *  @datatype       SAC_ERROR_HANDLER
 *  @defaultvalue   SAC_ERRH_QUICK_STOP
 *  @minvalue       SAC_ERRH_NONE
 *  @xmlPath        edh/errorHandlingPars/SAC_PAR_AX_ERR_PTP_BUFFER_OVERRUN
 *  @_adminPath     edh.errorHandling[SAC_AX_ERR_PTP_BUFFER_OVERRUN & NYCE_INDEX_MASK]
 *  @readOnly       FALSE
 */
#define SAC_PAR_AX_ERR_PTP_BUFFER_OVERRUN             ((SAC_PAR_ID)(RW|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)|100))

/**
 *  @}
 */

/**
 *  @defgroup udc_pars udc parameters
 *  @{
 */

/**
 *  @brief  UDC parameter 0
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_00
 *  @_adminPath     udc.par[0]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_00                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  UDC parameter 1
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_01
 *  @_adminPath     udc.par[1]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_01                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  UDC parameter 2
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_02
 *  @_adminPath     udc.par[2]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_02                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  UDC parameter 3
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_03
 *  @_adminPath     udc.par[3]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_03                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  UDC parameter 4
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_04
 *  @_adminPath     udc.par[4]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_04                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  UDC parameter 5
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_05
 *  @_adminPath     udc.par[5]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_05                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  UDC parameter 6
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_06
 *  @_adminPath     udc.par[6]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_06                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  UDC parameter 7
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_07
 *  @_adminPath     udc.par[7]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_07                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  UDC parameter 8
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_08
 *  @_adminPath     udc.par[8]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_08                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  UDC parameter 9
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_09
 *  @_adminPath     udc.par[9]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_09                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  UDC parameter 10
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_10
 *  @_adminPath     udc.par[10]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_10                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  UDC parameter 11
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_11
 *  @_adminPath     udc.par[11]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_11                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  UDC parameter 12
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_12
 *  @_adminPath     udc.par[12]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_12                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  UDC parameter 13
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_13
 *  @_adminPath     udc.par[13]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_13                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  UDC parameter 14
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_14
 *  @_adminPath     udc.par[14]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_14                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  UDC parameter 15
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_15
 *  @_adminPath     udc.par[15]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_15                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  UDC parameter 16
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_16
 *  @_adminPath     udc.par[16]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_16                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  UDC parameter 17
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_17
 *  @_adminPath     udc.par[17]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_17                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  UDC parameter 18
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_18
 *  @_adminPath     udc.par[18]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_18                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  UDC parameter 19
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_19
 *  @_adminPath     udc.par[19]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_19                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @brief  UDC parameter 20
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_20
 *  @_adminPath     udc.par[20]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_20                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @brief  UDC parameter 21
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_21
 *  @_adminPath     udc.par[21]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_21                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  UDC parameter 22
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_22
 *  @_adminPath     udc.par[22]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_22                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  UDC parameter 23
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_23
 *  @_adminPath     udc.par[23]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_23                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  UDC parameter 24
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_24
 *  @_adminPath     udc.par[24]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_24                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  UDC parameter 25
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_25
 *  @_adminPath     udc.par[25]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_25                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  UDC parameter 26
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_26
 *  @_adminPath     udc.par[26]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_26                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  UDC parameter 27
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_27
 *  @_adminPath     udc.par[27]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_27                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  UDC parameter 28
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_28
 *  @_adminPath     udc.par[28]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_28                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  UDC parameter 29
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_29
 *  @_adminPath     udc.par[29]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_29                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  UDC parameter 30
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_30
 *  @_adminPath     udc.par[30]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_30                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  UDC parameter 31
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_31
 *  @_adminPath     udc.par[31]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_31                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  UDC parameter 32
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_32
 *  @_adminPath     udc.par[32]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_32                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  UDC parameter 33
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_33
 *  @_adminPath     udc.par[33]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_33                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  UDC parameter 34
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_34
 *  @_adminPath     udc.par[34]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_34                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  UDC parameter 35
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_35
 *  @_adminPath     udc.par[35]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_35                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @brief  UDC parameter 36
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_36
 *  @_adminPath     udc.par[36]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_36                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|37))

/**
 *  @brief  UDC parameter 37
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_37
 *  @_adminPath     udc.par[37]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_37                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|38))

/**
 *  @brief  UDC parameter 38
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_38
 *  @_adminPath     udc.par[38]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_38                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|39))

/**
 *  @brief  UDC parameter 39
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_39
 *  @_adminPath     udc.par[39]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_39                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|40))

/**
 *  @brief  UDC parameter 40
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_40
 *  @_adminPath     udc.par[40]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_40                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|41))

/**
 *  @brief  UDC parameter 41
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_41
 *  @_adminPath     udc.par[41]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_41                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|42))

/**
 *  @brief  UDC parameter 42
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_42
 *  @_adminPath     udc.par[42]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_42                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|43))

/**
 *  @brief  UDC parameter 43
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_43
 *  @_adminPath     udc.par[43]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_43                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|44))

/**
 *  @brief  UDC parameter 44
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_44
 *  @_adminPath     udc.par[44]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_44                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|45))

/**
 *  @brief  UDC parameter 45
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_45
 *  @_adminPath     udc.par[45]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_45                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|46))

/**
 *  @brief  UDC parameter 46
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_46
 *  @_adminPath     udc.par[46]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_46                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|47))

/**
 *  @brief  UDC parameter 47
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_47
 *  @_adminPath     udc.par[47]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_47                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|48))

/**
 *  @brief  UDC parameter 48
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_48
 *  @_adminPath     udc.par[48]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_48                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|49))

/**
 *  @brief  UDC parameter 49
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_49
 *  @_adminPath     udc.par[49]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_49                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|50))

/**
 *  @brief  UDC parameter 50
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_50
 *  @_adminPath     udc.par[50]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_50                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|51))

/**
 *  @brief  UDC parameter 51
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_51
 *  @_adminPath     udc.par[51]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_51                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|52))

/**
 *  @brief  UDC parameter 52
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_52
 *  @_adminPath     udc.par[52]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_52                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|53))

/**
 *  @brief  UDC parameter 53
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_53
 *  @_adminPath     udc.par[53]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_53                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|54))

/**
 *  @brief  UDC parameter 54
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_54
 *  @_adminPath     udc.par[54]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_54                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|55))

/**
 *  @brief  UDC parameter 55
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_55
 *  @_adminPath     udc.par[55]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_55                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|56))

/**
 *  @brief  UDC parameter 56
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_56
 *  @_adminPath     udc.par[56]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_56                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|57))

/**
 *  @brief  UDC parameter 57
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_57
 *  @_adminPath     udc.par[57]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_57                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|58))

/**
 *  @brief  UDC parameter 58
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_58
 *  @_adminPath     udc.par[58]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_58                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|59))

/**
 *  @brief  UDC parameter 59
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_59
 *  @_adminPath     udc.par[59]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_59                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|60))

/**
 *  @brief  UDC parameter 60
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_60
 *  @_adminPath     udc.par[60]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_60                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|61))

/**
 *  @brief  UDC parameter 61
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_61
 *  @_adminPath     udc.par[61]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_61                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|62))

/**
 *  @brief  UDC parameter 62
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_62
 *  @_adminPath     udc.par[62]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_62                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|63))

/**
 *  @brief  UDC parameter 63
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -1.0e+12
 *  @maxvalue       1.0e+12
 *  @defaultvalue   0.0
 *  @xmlPath        udc/SAC_PAR_UDC_63
 *  @_adminPath     udc.par[63]
 *  @readOnly       FALSE
 */
#define SAC_PAR_UDC_63                                ((SAC_PAR_ID)(RW|(SS_UDC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_UDCCTR<<NYCE_FWMODULE_SHIFT)|64))

/**
 *  @}
 */

/**
 *  @}
 */

#endif
