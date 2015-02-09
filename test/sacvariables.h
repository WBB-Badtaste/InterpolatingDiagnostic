/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2011-2012
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: SAC
 *  %full_filespec: sacvariables.h`22:incl:1 %
 */
/**
 *  @file
 *  @brief  All variables for an axis.
 */

#ifndef __SACVARIABLES_H__
#define __SACVARIABLES_H__

#include "n4k_deprecated.h" //lint !e451
#include "n4k_basictypes.h"


/**
 * @addtogroup sac_variables
 * @{
 */

/** Axis variable ID type. */
typedef uint32_t SAC_VAR_ID;

/**
 *  @defgroup axis_variables Axis variables
 *  @{
 */

/**
 *  @brief  Axis position
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_AXIS_POS                              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Axis velocity
 *
 *  @datatype       double
 *  @unit           [pu/s]
 */
#define SAC_VAR_AXIS_VEL                              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Setpoint position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_SETPOINT_POS                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Setpoint displacement.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_SETPOINT_DISPL                        ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Setpoint velocity.
 *
 *  @datatype       double
 *  @unit           [pu/s]
 */
#define SAC_VAR_SETPOINT_VEL                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  Setpoint acceleration.
 *
 *  @datatype       double
 *  @unit           [pu/s^2]
 */
#define SAC_VAR_SETPOINT_ACC                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Setpoint jerk.
 *
 *  @datatype       double
 *  @unit           [pu/s^3]
 */
#define SAC_VAR_SETPOINT_JERK                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Setpoint snap.
 *
 *  @datatype       double
 *  @unit           [pu/s^4]
 */
#define SAC_VAR_SETPOINT_SNAP                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  State of the axis controller.
 *
 *  @datatype       CTR_STATE
 */
#define SAC_VAR_CONTROLLER_STATE                      ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  The current position error.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_POSITION_ERROR                        ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Maximum position error (within current state during normal operation).
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_MAX_POS_ERROR                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  Settling time.
 *
 *  @datatype       double
 *  @unit           [s]
 */
#define SAC_VAR_SETTLING_TIME                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  Controller output.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_CONTROLLER_OUT                        ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  Integrator value.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_INTEGRATOR                            ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  Overshoot (absolute value of current position error).
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_OVERSHOOT                             ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  The axis is in a homed state.
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_HOMED                                 ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  Status of homing procedure.
 *
 *  @datatype       SPG_HOME_STATE
 */
#define SAC_VAR_HOME_STATUS                           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  Position is at or beyond positive end switch.
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_POS_ENDSW_REACHED                     ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  Position is at or beyond negative end switch.
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_NEG_ENDSW_REACHED                     ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  Probe 0 position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_PROBE0_POS                            ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @brief  Probe 1 position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_PROBE1_POS                            ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @brief  Probe 2 position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_PROBE2_POS                            ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  Probe 3 position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_PROBE3_POS                            ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  Probe 0 status.
 *
 *  state_bit: 0 = inactive    1 = active
 *  latch_bit: 0 = not latched 1 = latched
 *
 *  @datatype       BITFIELD(PROBE_STATE_BIT|PROBE_LATCH_BIT)
 */
#define SAC_VAR_PROBE0_STATUS                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  Probe 1 status.
 *
 *  state_bit: 0 = inactive    1 = active
 *  latch_bit: 0 = not latched 1 = latched
 *
 *  @datatype       BITFIELD(PROBE_STATE_BIT|PROBE_LATCH_BIT)
 */
#define SAC_VAR_PROBE1_STATUS                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  Probe 2 status.
 *
 *  state_bit: 0 = inactive    1 = active
 *  latch_bit: 0 = not latched 1 = latched
 *
 *  @datatype       BITFIELD(PROBE_STATE_BIT|PROBE_LATCH_BIT)
 */
#define SAC_VAR_PROBE2_STATUS                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  Probe 3 status.
 *
 *  state_bit: 0 = inactive    1 = active
 *  latch_bit: 0 = not latched 1 = latched
 *
 *  @datatype       BITFIELD(PROBE_STATE_BIT|PROBE_LATCH_BIT)
 */
#define SAC_VAR_PROBE3_STATUS                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  SAC error code.
 *
 *  @datatype       NYCE_ERROR_CODE
 */
#define SAC_VAR_ERROR_WORD                            ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  Axis state.
 *
 *  @datatype       SAC_STATE
 */
#define SAC_VAR_STATE                                 ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  The currently active test signal type.
 *
 *  @datatype       CTR_TSG_TYPE
 */
#define SAC_VAR_TSG_ACTIVE_TYPE                       ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  The number of periods of the currently or lastly active type of test signal generator.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define SAC_VAR_TSG_PERIOD_COUNTER                    ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  The number of spline segments buffered at the control unit.
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define SAC_VAR_SPLINE_SEGMENTS_BUFFERED              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  Identification number of current spline segment.
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define SAC_VAR_SPLINE_CURRENT_ID                     ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  Actual proportional gain.
 *
 *  @datatype       double
 *  @unit           [cout/pu]
 */
#define SAC_VAR_ACTUAL_P_GAIN                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_PER_INC<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  Actual integral gain.
 *
 *  @datatype       double
 *  @unit           [rad/s]
 */
#define SAC_VAR_ACTUAL_I_GAIN                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  Actual derivative gain.
 *
 *  @datatype       double
 *  @unit           [cout*s/pu]
 */
#define SAC_VAR_ACTUAL_D_GAIN                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_PER_INC<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @brief  Home position in old motor coordinates.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_HOMED_OLD_POSITION                    ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|37))

/**
 *  @brief  Feed override status.
 *
 *  @datatype       SPG_FOV_STATUS
 */
#define SAC_VAR_FEED_OVERRIDE_STATUS                  ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|38))

/**
 *  @brief  Actual feed override factor.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_ACTUAL_FEED_OVERRIDE                  ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|39))

/**
 *  @brief  The current setpoint generation mode.
 *
 *  @datatype       SAC_SPG_STATE
 */
#define SAC_VAR_SPG_STATE                             ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|40))

/**
 *  @brief  Current SAC error handler.
 *
 *  @datatype       SAC_ERROR_HANDLER
 */
#define SAC_VAR_ERROR_HANDLER                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|41))

/**
 *  @brief  Setpoint direction.
 *
 *  1 = positive direction, -1 = negative direction, 0 = axis is stopped (undefined)
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_SETPOINT_DIRECTION                    ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|42))

/**
 *  @brief  Setpoint generation phase.
 *
 *  @datatype       SPG_PHASE
 */
#define SAC_VAR_SETPOINT_PHASE                        ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|43))

/**
 *  @brief  Last target position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_PTP_LAST_TARGET_POSITION              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|44))

/**
 *  @brief  Last maximum allowed velocity on a point-to-point.
 *
 *  @datatype       double
 *  @unit           [pu/s]
 */
#define SAC_VAR_PTP_LAST_MAXIMUM_VELOCITY             ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|45))

/**
 *  @brief  Last jogging target velocity.
 *
 *  @datatype       double
 *  @unit           [pu/s]
 */
#define SAC_VAR_JOG_LAST_TARGET_VELOCITY              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|46))

/**
 *  @brief  Controller output before test signal injection.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_CTR_OUT_BEFORE_TEST_SIG_ADD           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|47))

/**
 *  @brief  Get the index pulse status on an axis with S00S90 or SinCos sensor.
 *
 *  For S00S90 or SinCos type sensors TRUE is returned incase the index pulse
 *  is active and FALSE otherwise.
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_S0S90_INDEX                           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|48))

/**
 *  @brief  Drive current.
 *
 *  @datatype       double
 *  @unit           [A]
 */
#define SAC_VAR_DRIVE_CURRENT                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|49))

/**
 *  @brief  Quiescent current.
 *
 *  @datatype       double
 *  @unit           [A]
 */
#define SAC_VAR_QUIESCENT_CURRENT                     ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|50))

/**
 *  @brief  Drive positive voltage.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_SERVO_VOLTAGE                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|51))

/**
 *  @brief  Drive negative voltage.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_SERVO_VOLTAGE_NEG                     ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|52))

/**
 *  @brief  Drive temperature.
 *
 *  @datatype       double
 *  @unit           [deg C]
 */
#define SAC_VAR_DRIVE_TEMPERATURE                     ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|53))

/**
 *  @brief  Test signal generator value using injection at setpoint.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_TSG_SETPOINT_INPUT_VALUE              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|54))

/**
 *  @brief  Test signal generator value using injection at controller out with open loop configuration.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_TSG_OPEN_LOOP_INPUT_VALUE             ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|55))

/**
 *  @brief  Test signal generator value using injection at controller out with closed loop configuration.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_TSG_CLOSED_LOOP_INPUT_VALUE           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|56))

/**
 *  @brief  Motor is aligned.
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_BLAC_ALIGNED                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|57))

/**
 *  @brief  Returns the overcurrent status.
 *
 *  The overcurrent status is a 2-bit value that indicates the HW shortcircuit condition
 *  of an axis in bit 0 and the SW over current status in bit 1.
 *
 *  @datatype       BITFIELD(HW_SHORT_CIRCUIT_STATE_BIT|SW_OVER_CURRENT_STATE_BIT)
 */
#define SAC_VAR_OVER_CURRENT_STATUS                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|58))

/**
 *  @brief  System is in service mode.
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_SERVICE_MODE_ACTIVE                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|59))

/**
 *  @brief  The number of samples passed since start of settling.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define SAC_VAR_SETTLING_COUNTER                      ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|60))

/**
 *  @brief  Camming and gearing master displacement.
 *
 *  @datatype       int32_t
 *  @unit           [pu]
 */
#define SAC_VAR_ECG_MASTER_DISPLACEMENT               ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|61))

/**
 *  @brief  Camming and gearing master position.
 *
 *  @datatype       int32_t
 *  @unit           [pu]
 */
#define SAC_VAR_ECG_MASTER_POSITION                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|62))

/**
 *  @brief  Camming and gearing predicted master position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_ECG_PRED_MASTER_POSITION              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|63))

/**
 *  @brief  Stop alarm is set active.
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_STOP_ALARM_ACTIVE                     ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|64))

/**
 *  @brief  Position sensor encoder power is enabled.
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_ENCODER_POWER_ENABLED                 ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|65))

/**
 *  @brief  Nonlin axis position (LMS carrier).
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_NONLIN_AXIS_POS                       ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|66))

/**
 *  @brief  Nonlin setpoint position (LMS carrier).
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_NONLIN_SETPOINT_POS                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|67))

/**
 *  @brief  Bitmask to filter resolved (reset) error indications.
 *
 *  The 0-bits in the mask are ignored in error recovery mode.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 */
#define SAC_VAR_RECOVER_MODE_STATUS                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|68))

/**
 *  @brief  The SAC_PAR_ID of the offending parameter reported with error SAC_ERR_INVALID_PARAMETER.
 *
 *  @datatype       SAC_PAR_ID
 */
#define SAC_VAR_ID_OF_INVALID_PAR                     ((SAC_VAR_ID)(RW| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|69))

/**
 *  @brief  State of axis alignment procedure.
 *
 *  @datatype       CTR_WNS_STATE
 */
#define SAC_VAR_MOVE_CURRENT_ANGLE_STATE              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|70))

/**
 *  @brief   Axis commutation angle.
 *
 *  @datatype       double
 *  @unit           [rad]
 */
#define SAC_VAR_COMMUTATION_ANGLE                     ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|71))

/**
 *  @brief  The I2t (ampere-squared-seconds) overload protection measure.
 *
 *  To protect the drive against overload conditions a method is implemented
 *  that monitors the transient overload energy flowing in the drive. The measure
 *  used for this is "I squared t". An error event is generated if this measure is exceeded.
 *  The maximal allowed I2t value is a drive characteristic and can be set as an axis parameter.
 *  The parameter depends on max ratings of used FETs, diodes etc.
 *  This mechanism is only implemented in NY4120 and NY4140.
 *
 *  @datatype       double
 *  @unit           [A^2*s]
 */
#define SAC_VAR_DRIVE_I2T_CRITERION_VALUE             ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|72))

/**
 *  @brief  The position sensor interface (S00/S90) secondary counter value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define SAC_VAR_SECONDARY_COUNTER_VALUE               ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|77))

/**
 *  @brief  The position sensor interface (S00/S90) secondary counter delta.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define SAC_VAR_SECONDARY_COUNTER_DISPLACEMENT        ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|78))

/**
 *  @brief  The number of data bits used in EnDat encoder communication.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define SAC_VAR_ENDAT_NR_OF_POSITION_DATA_BITS        ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|79))

/**
 *  @brief  The error ID of the first error encountered on an axis.
 *
 *  @datatype       NYCE_ERROR_CODE
 */
#define SAC_VAR_ERROR_FIRST_DETECTED                  ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|80))

/**
 *  @brief  Commutation correction enabled status
 *
 *  The commutation correction is a offset on the standard commutation that can be applied
 *  in the context of a Wake 'n Shake procedure. The value of this offset is calculated
 *  on the basis of the direction of axis rotation and the number of pole pairs.
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_COMMUTATION_CORRECTION_ENABLED        ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|81))

/**
 *  @brief  The amount of auto tweak compensation.
 *
 *  This is position dependent and relates to feedforward tables.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_TWEAK_COMPENSATION                    ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|82))

/**
 *  @brief  IndraDrive error code.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define SAC_VAR_INDRA_ERROR                           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|85))

/**
 *  @brief  IndraDrive digital I/O status.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 */
#define SAC_VAR_INDRA_DIG_IO_STATUS                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|86))

/**
 *  @brief  IndraDrive analog input 0.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_INDRA_AN_IN0_VALUE                    ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|87))

/**
 *  @brief  IndraDrive analog output 0.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_INDRA_AN_OUT0_VALUE                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|88))

/**
 *  @brief  IndraDrive analog output 1.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_INDRA_AN_OUT1_VALUE                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|89))

/**
 *  @brief  IndraDrive amplifier temperature.
 *
 *  @datatype       double
 *  @unit           [deg C]
 */
#define SAC_VAR_INDRA_DRIVE_TEMPERATURE               ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|90))

/**
 *  @brief  IndraDrive motor temperature.
 *
 *  @datatype       double
 *  @unit           [deg C]
 */
#define SAC_VAR_INDRA_MOTOR_TEMPERATURE               ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|91))

/**
 *  @brief  The modulo range used on the IndraDrive position indication (for rotary axes).
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_INDRA_POSITION_RANGE                  ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|92))

/**
 *  @brief  IndraDrive motor type with encoder memory.
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_INDRA_MOTOR_WITH_ENCODER_MEMORY       ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|93))

/**
 *  @brief  Amplitude for angle acquisition.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_INDRA_TEST_SIGNAL_AMPLITUDE           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|94))

/**
 *  @brief  Test frequency for angle acquisition.
 *
 *  @datatype       double
 *  @unit           [Hz]
 */
#define SAC_VAR_INDRA_TEST_SIGNAL_FREQUENCY           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|95))

/**
 *  @brief  The SAC parameter ID associated with warning SAC_WRN_PARAMETER_VALUE_CHANGED.
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define SAC_VAR_ID_OF_PAR_VALUE_CHANGED               ((SAC_VAR_ID)(RW| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|96))

/**
 *  @brief  Actual force sensor output.
 *
 *  @datatype       double
 *  @unit           [N]
 */
#define SAC_VAR_PFC_ACTUAL_FORCE                      ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|97))

/**
 *  @brief  Average force sensor output.
 *
 *  @datatype       double
 *  @unit           [N]
 */
#define SAC_VAR_PFC_AVERAGE_FORCE                     ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|98))

/**
 *  @brief  Force setpoint.
 *
 *  @datatype       double
 *  @unit           [N]
 */
#define SAC_VAR_PFC_FORCE_SETPOINT                    ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|99))

/**
 *  @brief  Force displacement.
 *
 *  This is the result of (force setpoint - average force sensor output) * PFC proportional gain
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_PFC_FORCE_DISPL                       ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|100))

/**
 *  @brief  Disable drive active (for NY4120 / NY4125 / NY4140).
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_DISABLE_DRIVE_ACTIVE                  ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL <<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|101))

/**
 *  @brief  Denormalized actual max integrator level.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_ACTUAL_MAX_INTEGRATOR_LEVEL           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|102))

/**
 *  @brief  Maximum positive saturation level of the position controller output.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_ACTUAL_POS_SATURATION_LEVEL           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|103))

/**
 *  @brief  Maximum negative saturation level of the position controller output.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_ACTUAL_NEG_SATURATION_LEVEL           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|104))

/**
 *  @brief  Feedforward setpoint.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_SETPOINT_FEEDFORWARD                  ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|105))

/**
 *  @brief  Feedworward adjustment.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_FEEDFORWARD_ADJUSTMENT                ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|106))

/**
 *  @brief  Raw setpoint.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_RAW_SETPOINT_POS                      ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|107))

/**
 *  @brief  Setpoint adjustment.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_SETPOINT_ADJUSTMENT                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|108))

/**
 *  @brief  The I2t overload protection criterion value.
 *
 *  To protect the connected motor against overload conditions a method is
 *  implemented that monitors the transient overload current flowing into
 *  the motor. The measure used for this is "I squared t". An error event
 *  is generated if this criterion exceeds a maximum value.
 *  The maximal criterion value is SAC_PAR_MOTOR_MAX_OVERLOAD_FACTOR.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_MOTOR_I2T_CRITERION_VALUE             ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|109))

/**
 *  @brief  Encoder properties.
 *
 *  multiturn_reset_supported_bit: 0 = SacResetMultiTurnCounter not supported 1 = SacResetMultiTurnCounter supported
 *
 *  @datatype       BITFIELD(MULTITURN_RESET_SUPPORTED_BIT)
 */
#define SAC_VAR_ENCODER_PROPERTIES                    ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME  <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|110))

/**
 *  @}
 */


/**
 *  @defgroup lms_variables LMS variables.
 *  @{
 */

/**
 *  @brief  Left sensor sine signal.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_LEFT_SENSOR_SIN                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|123))

/**
 *  @brief  Middle sensor sine signal.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_MIDDLE_SENSOR_SIN                 ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|124))

/**
 *  @brief  Right sensor sine signal.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_RIGHT_SENSOR_SIN                  ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|125))

/**
 *  @brief  Left sensor cosine signal.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_LEFT_SENSOR_COS                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|126))

/**
 *  @brief  Middle sensor cosine signal.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_MIDDLE_SENSOR_COS                 ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|127))

/**
 *  @brief  Right sensor cosine signal.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_RIGHT_SENSOR_COS                  ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|128))

/**
 *  @brief  Left sensor index.
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define SAC_VAR_LMS_LEFT_SENSOR_INDEX                 ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|129))

/**
 *  @brief  Middle sensor index.
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define SAC_VAR_LMS_MIDDLE_SENSOR_INDEX               ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|130))

/**
 *  @brief  Right sensor index.
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define SAC_VAR_LMS_RIGHT_SENSOR_INDEX                ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|131))

/**
 *  @brief  Left sensor position.
 *      If CPA (carrier position adjustment) enabled, the adjusted left sensor position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_LMS_LEFT_SENSOR_POSITION              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|132))

/**
 *  @brief  Middle sensor position.
 *      If CPA (carrier position adjustment) enabled, the adjusted middle sensor position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_LMS_MIDDLE_SENSOR_POSITION            ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|133))

/**
 *  @brief  Right sensor position.
 *      If CPA (carrier position adjustment) enabled, the adjusted right sensor position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_LMS_RIGHT_SENSOR_POSITION             ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|134))

/**
 *  @brief  Left sensor status (a bitfield).
 *
 *  @datatype       BITFIELD(SAC_LMS_SENSOR_BITS)
 *
 */
#define SAC_VAR_LMS_LEFT_SENSOR_STATUS                ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|135))

/**
 *
 *  @brief  Middle sensor status (a bitfield).
 *
 *  @datatype       BITFIELD(SAC_LMS_SENSOR_BITS)
 *
 */
#define SAC_VAR_LMS_MIDDLE_SENSOR_STATUS              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|136))

/**
 *  @brief  Right sensor status (a bitfield).
 *
 *  @datatype       BITFIELD(SAC_LMS_SENSOR_BITS)
 *
 */
#define SAC_VAR_LMS_RIGHT_SENSOR_STATUS               ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|137))

/**
 *  @brief  Left sensor angle.
 *
 *  @datatype       double
 *  @unit           [rad]
 */
#define SAC_VAR_LMS_LEFT_SENSOR_ANGLE                 ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|138))

/**
 *  @brief  Middle sensor angle.
 *
 *  @datatype       double
 *  @unit           [rad]
 */
#define SAC_VAR_LMS_MIDDLE_SENSOR_ANGLE               ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|139))

/**
 *  @brief  Right sensor angle.
 *
 *  @datatype       double
 *  @unit           [rad]
 */
#define SAC_VAR_LMS_RIGHT_SENSOR_ANGLE                ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|140))

/**
 *  @brief  Left sensor sine correction.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_LEFT_SENSOR_SIN_CORR              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|141))

/**
 *  @brief  Middle sensor sine correction.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_MIDDLE_SENSOR_SIN_CORR            ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|142))

/**
 *  @brief  Right sensor sine correction.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_RIGHT_SENSOR_SIN_CORR             ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|143))

/**
 *  @brief  Left sensor cosine correction.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_LEFT_SENSOR_COS_CORR              ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|144))

/**
 *  @brief  Middle sensor cosine correction.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_MIDDLE_SENSOR_COS_CORR            ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|145))

/**
 *  @brief  Right sensor cosine correction.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_RIGHT_SENSOR_COS_CORR             ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|146))

/**
 *  @brief  Left measured commutation offset.
 *
 *  @datatype       double
 *  @unit           [rad]
 */
#define SAC_VAR_LMS_LEFT_MEAS_COMMUT_OFFSET           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|147))

/**
 *  @brief  Middle measured commutation offset.
 *
 *  @datatype       double
 *  @unit           [rad]
 */
#define SAC_VAR_LMS_MIDDLE_MEAS_COMMUT_OFFSET         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|148))

/**
 *  @brief  Right measured commutation offset.
 *
 *  @datatype       double
 *  @unit           [rad]
 */
#define SAC_VAR_LMS_RIGHT_MEAS_COMMUT_OFFSET          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|149))

/**
 *  @brief  Sensor supply negative value.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_SENSOR_SUPPLY_NEG_VALUE           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|150))

/**
 *  @brief  Sensor supply positive value.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_LMS_SENSOR_SUPPLY_POS_VALUE           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|151))

/**
 *  @brief  Control carrier index.
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define SAC_VAR_LMS_CONTROL_CARRIER_INDEX             ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|152))

/**
 *  @brief  Left sensor raw position.
 *      If CPA (carrier position adjustment) enabled, the not adjusted left sensor position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_LMS_LEFT_SENSOR_RAW_POSITION          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|153))

/**
 *  @brief  Middle sensor raw position.
 *      If CPA (carrier position adjustment) enabled, the not adjusted middle sensor position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_LMS_MIDDLE_SENSOR_RAW_POSITION        ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|154))

/**
 *  @brief  Right sensor raw position.
 *      If CPA (carrier position adjustment) enabled, the not adjusted right sensor position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_LMS_RIGHT_SENSOR_RAW_POSITION         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_INC    <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|155))

/**
 *  @}
 */

/**
 *  @defgroup hsd_variables High Speed Data tracing variables
 *  @{
 */

/**
 *  @brief  Hsd analog input.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_HSD_ANALOG_INPUT                        ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|( FWM_GENSTATUS <<NYCE_FWMODULE_SHIFT)|187))

/**
 *  @brief  Hsd axis position.
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_HSD_AXIS_POS                            ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_INC<<NYCE_FWDIM_SHIFT)|( FWM_GENSTATUS <<NYCE_FWMODULE_SHIFT)|188))

/**
 *  @brief  Hsd current position error.
 *
 *  @datatype       double
 *
 *  @unit           [pu]
 */
#define SAC_VAR_HSD_POSITION_ERROR                      ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_INC<<NYCE_FWDIM_SHIFT)|( FWM_GENSTATUS <<NYCE_FWMODULE_SHIFT)|189))

/**
 *  @brief  Hsd test signal.
 *
 *  @datatype       double
 *  @unit           [cout or pu]
 */
#define SAC_VAR_HSD_TEST_SIGNAL                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|( FWM_GENSTATUS <<NYCE_FWMODULE_SHIFT)|190))

/**
 *  @brief  Hsd controller out.
 *
 *  @datatype       double
 *  @unit           [cout]
 */
#define SAC_VAR_HSD_CONTROLLER_OUT                      ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|( FWM_GENSTATUS <<NYCE_FWMODULE_SHIFT)|191))

/**
 *  @brief  Hsd sincos sine.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_HSD_SINCOS_SINE                         ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|( FWM_GENSTATUS <<NYCE_FWMODULE_SHIFT)|192))

/**
 *  @brief  Hsd sincos cosine.
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_HSD_SINCOS_COSINE                       ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|( FWM_GENSTATUS <<NYCE_FWMODULE_SHIFT)|193))

 /**
 *  @brief  Hsd pvl cycle counter.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_HSD_PVL_CYCLE_COUNTER                   ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|( FWM_GENSTATUS <<NYCE_FWMODULE_SHIFT)|194))



/**
 *  @}
 */


/**
 *  @defgroup udc_variables User Definable Control trace variables
 *  @{
 */

/**
 *  @brief  UDC trace variable 0.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDC_TRACE_0                           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|203))

/**
 *  @brief  UDC trace variable 1.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDC_TRACE_1                           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|204))

/**
 *  @brief  UDC trace variable 2.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDC_TRACE_2                           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|205))

/**
 *  @brief  UDC trace variable 3.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDC_TRACE_3                           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|206))

/**
 *  @brief  UDC trace variable 4.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDC_TRACE_4                           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|207))

/**
 *  @brief  UDC trace variable 5.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDC_TRACE_5                           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|208))

/**
 *  @brief  UDC trace variable 6.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDC_TRACE_6                           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|209))

/**
 *  @brief  UDC trace variable 7.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDC_TRACE_7                           ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|210))

/**
 *  @brief  UDSX trace variable 0.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDSX_TRACE_0                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|211))

/**
 *  @brief  UDSX trace variable 1.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDSX_TRACE_1                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|212))

/**
 *  @brief  UDSX trace variable 2.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDSX_TRACE_2                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|213))

/**
 *  @brief  UDSX trace variable 3.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDSX_TRACE_3                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|214))

/**
 *  @brief  UDSX trace variable 4.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDSX_TRACE_4                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|215))

/**
 *  @brief  UDSX trace variable 5.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDSX_TRACE_5                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|216))

/**
 *  @brief  UDSX trace variable 6.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDSX_TRACE_6                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|217))

/**
 *  @brief  UDSX trace variable 7.
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_UDSX_TRACE_7                          ((SAC_VAR_ID)(RO| (SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|218))

/**
 *  @}
 */


/**
 *  @defgroup async_variables Asynchronous Axis variables.
 *
 *  Asynchronous variables can not be traced or added to a variable set.
 *
 *  @{
 */

/**
 *  @brief  Controller output for tweak.
 *
 *  @datatype       double
 *  @unit           [cout]
 *
 *  @remark         Asynchronous operation: value returned in GEN_VAR_ASYNCHRONOUS_VARIABLE
 */
#define SAC_ASV_CTR_OUTPUT_FOR_TWEAK                  ((SAC_VAR_ID)(RO|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  Coil current A.
 *
 *  @datatype       double
 *  @unit           [A]
 *
 *  @remark         Asynchronous operation: value returned in GEN_VAR_ASYNCHRONOUS_VARIABLE
 */
#define SAC_ASV_COIL_CURRENT_A                        ((SAC_VAR_ID)(RO|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Coil current B.
 *
 *  @datatype       double
 *  @unit           [A]
 *
 *  @remark         Asynchronous operation: value returned in GEN_VAR_ASYNCHRONOUS_VARIABLE
 */
#define SAC_ASV_COIL_CURRENT_B                        ((SAC_VAR_ID)(RO|(SS_SAC<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME   <<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @}
 */


/**
 * @}
 */

#endif
