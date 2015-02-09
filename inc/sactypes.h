/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2012
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: SAC
 *  %full_filespec: sactypes.h`24:incl:1 %
 */
/**
 *  @file
 *  @brief  Headerfile containing datatypes and defines for SAC.
 */
#ifndef __SACTYPES_H__
#define __SACTYPES_H__ 

#include "nycetypes.h"
#include "sacvariables.h"

#ifdef NT
#pragma pack(push)
#pragma pack() //use default
#endif


/**
 *  @defgroup sac Single Axis Control (SAC)
 *
 *  The SAC library contains all functionality needed to control a single axis 
 *
 *  @{
 */

#define SAC_INDEFINITE ((double)-1)     /**< The time-out value that will result in an indefinite suspension */


/**
 *  Use this define to initialize from flash.
 *  @see    SacInitialize
 */
#define SAC_USE_FLASH "UseFlash"

#define SAC_MAX_NR_OF_LATCHED_POSITIONS   128   /**< Maximum number of positions that can be latched */

#define SAC_MAX_NR_OF_SINGLE_SHOT_LOADABLE 16   /**< Maximum number of single shot markers that can be defined with function SacDefineSingleShotMarkers */

#define SAC_MAX_NR_OF_SINGLE_SHOT_MARKERS 128   /**< Maximum number of single shot markers that can be defined per axis */
#define SAC_MAX_NR_OF_PERMANENT_MARKERS    16   /**< Maximum number of permanent markers that can be defined per axis */
#define SAC_MAX_NR_OF_REPETITIVE_MARKERS    2   /**< Maximum number of repetitive markers that can be defined per axis */

#define SAC_MAX_NR_OF_FORCE_SEGMENTS       16   /**< Maximum number of force segments that can be written with the function SacPfcWriteForceSegment. */


#define SAC_MAX_NR_OF_SENSORS               3   /**< Maximum number of sensors per coil that can be handled in a NYCe4000 lms system */


typedef uint32_t   SAC_AXIS;        /**< Axis identifier */

#define SAC_INVALID_ID (SAC_AXIS)NYCE_MAX_NR_OF_AXES    /**< The invalid axis id identifier */

#define MAC_INVALID_SYNC_GROUP_ID NYCE_MAX_NR_OF_SYNC_GROUPS /**< The invalid MAC sync group id identifier */

/**
 *  Bitmask for the SAC_VAR_ENCODER_PROPERTIES variable indicating whether the encoder supports the SacResetMultiTurnCounter function.
 */
#define MULTITURN_RESET_SUPPORTED_BIT (1 << 0)

/**
 *  positive or negative direction
 */
typedef enum sac_direction
{
    SAC_DIR_NEGATIVE = -1,
    SAC_DIR_POSITIVE = 1
} SAC_DIRECTION;


/**
 *  @defgroup sac_parameters Parameters
 *
 *  \ref SacReadParameter and \ref SacWriteParameter access single SAC parameters. 
 *  \ref SacReadParameterSet and \ref SacWriteParameterSet access  SAC parameters sets. 
 *  Parameters sets contain several coherent parameters. All available 
 *  parameters are enumerated in the enumeration \ref SAC_PARAM_SET_ID. For this 
 *  enumeration following convention holds. All structure names of the 
 *  parameters sets are equal to the enumerations without the suffix _ID, 
 *  e.g. the function \ref SacWriteParameter expects for the parameterset 
 *  ID \ref SAC_CONTROLLER_PID_PARS_ID a pointer to a structure of type 
 *  \ref SAC_CONTROLLER_PID_PARS. All SAC parameters can be stored into flash 
 *  on the node. It is also possible to upload the current SAC parameters 
 *  to an xml-file on the host.
 */


/**
 *  @defgroup sac_variables Variables
 * 
 *  The function SacReadVariable reads the actual value of a variable of 
 *  an axis. The functions \ref SacAddVariableToSet, \ref SacAddVarToLatchSet, \ref SacAddVariableToTrace 
 *  return as output argument the index on which the variable can be found 
 *  in the set or trace. This index should also be used as function argument 
 *  for deleting the variable from a set or trace. Variable sets and traces 
 *  are explained in more detail in section \ref nyce_variable_set and 
 *  \ref nyce_variable_trace. Variable latch sets are explained in more detail 
 *  in section \ref nhi_variable_latch_set.
 */


/**
 *  @defgroup sac_variable_latch_set Variable Latch Sets
 *
 *  A variable latch set is a set of axis and node variables which values are latched
 *  when a specific event occurs. A limited number of sets are available per node.
 *  A set on a node is identified by an index number. Using \ref NhiAddVarToLatchSet
 *  and \ref SacAddVarToLatchSet you can add variables to a set. 
 *  Using \ref NhiActivateLatchSet and \ref SacActivateLatchSet a set is armed. When a 
 *  set is armed, it will latch the variable values when the specified event occurs.
 *  The latched values can then be read by \ref NhiReadLatchSetValues 
 */


/**
 *  @defgroup sac_events_and_actions Events and Actions
 */


/**
 *  @defgroup sac_configuration Configuration
 *
 *  For every axis, the axis type, the position sensor interface 
 *  and motor interface must be configured.
 */


/**
 *  @defgroup sac_state_transitions State Transitions
 */


/**
 *  @defgroup sac_function_io Function I/O
 *
 *  Digital I/O can be configured as motion specific I/O. The function 
 *  \ref SacDefineFunctionIO defines a digital input or output for a specific 
 *  I/O function. \ref SacGetFunctionIO, retrieves the digital I/O that is 
 *  coupled to a specific I/O function and \ref SacDeleteFunctionIO deletes a 
 *  specific I/O function. The active state of the digital I/Os are determined 
 *  by the settings in \ref nhi (see section \ref nhi_digital_io).
 */


/**
 *  @defgroup sac_error_and_service_handling Error and Service Handling
 *
 *  For each axis or a group of axes it is possible to detect and handle several
 *  errors. This error detection and handling functionality offers the possibility
 *  to set the criteria for error detection (parameters) and to attach an error 
 *  handler to each error defined.
 */


/**
 *  @defgroup sac_motion Motion
 */


/**
 *  @defgroup sac_electronic_gearing Electronic Gearing
 *
 *  By means of electronic gearing it is possible to move a motion axis (the slave axis)
 *  as a function of the position of another axis (the master axis), in such a way that 
 *  the velocity of the slave axis is proportional to the velocity of the master axis by
 *  a factor, called the gearing ratio. The master position may either be a setpoint or
 *  a servo position of any type of axis; the slave position is always a setpoint position.
 */


/**
 *  @defgroup sac_spline Spline
 *
 *  With the splining functionality, it is possible to build up a path from 
 *  a number of small segments. The axis controller computes a smooth profile 
 *  through the consecutive segments that are fed to it. A segment is defined 
 *  by its end-position, the velocity at that end-position and the travelling 
 *  time to reach that end-position in combination with a continuity requirement 
 *  for the position and velocity at the start of the segment. At each segment 
 *  the spline profile is described by a third order polynomial of time. At the 
 *  junction points of consecutive segments continuity of velocity is guaranteed 
 *  (Hermite splines). The velocity at these positions does not have to be zero.
 */


/**
 *  @defgroup sac_synchronize_groups Synchronize Groups
 *
 *  The Multi-Axis synchronization functionality offers the user the possibility
 *  to synchronize the start of certain actions on a group of axes. The 
 *  synchronization groups are defined by the user. Actions that may be
 *  synchronized this way are the start of a movement and the modification of
 *  the feed override.
 */


/**
 *  @defgroup sac_test_generator Test Generator
 *
 *  The test signal generation functionality is used to inject test signals in
 *  the control loop of the motion controller. With these test signals, the 
 *  dynamical behavior of the motion controller and/or the mechanics can be 
 *  observed. The test signals can be injected at different points of the motion
 *  controller.
 */


/**
 *  @defgroup sac_output_triggers Output Triggers
 *
 *  The output trigger functionality sets, resets or toggles an output when a 
 *  specific event occurs. The events can be any sensible SAC event.
 */


/**
 *  @defgroup sac_latches Latches
 */


/**
 *  @defgroup sac_markers Markers
 */


/**
 *  @defgroup sac_monitor Monitor
 *
 *  The monitor functionality can be used to put the value of a variable 
 *  continuously on an analog output. This output is updated with each 
 *  sample period of the axis controller. The function \ref SacStartMonitor 
 *  starts a monitor. The user has to specify which variable he wants to 
 *  observe and the scaling/offset that have to be applied before putting 
 *  the value on the analog output. The function \ref SacStopMonitor stops a 
 *  monitor.
 */


/**
 *  @defgroup sac_autotweak Autotweak
 *
 *  The control loop in the NYCe4000 is based on feedback and feedforward. 
 *  In general it can be stated that control performance increases when 
 *  less feedback is required. This is intuitively clear when one realizes 
 *  that an error is necessary to have feedback, so first there must be an 
 *  error before the feedback part of the controller is activated. Ideal 
 *  feedforward avoids the establishment of an error.
 */


/**
 *  @defgroup sac_lms_sensors LMS Sensors
 *
 *  The carrier position in an LMS system is measured by means of sensors. 
 *  Data and events related to carrier position and movement are detected and  
 *  stored for each sensor. 
 */


/**
 *  @defgroup sac_sensor_linearization Sensor Linearization
 *
 *  A scale used on an encoder is always of limited accuracy. This is unfortunate
 *  in itself, but fortunately the accuracy errors are very reproducible while 
 *  using the same scale. This allows us to compensate in software for 
 *  inaccuracies in the used scale. A typical example is a linear motor with a 
 *  linear scale.
 */


/**
 *  @defgroup sac_commutation_correction Commutation Correction
 *
 *  By means of commutation correction it is possible to correct the commutation offset of one axis 
 *  depending on the position of another axis.
 */


/**
 *  @defgroup sac_udc User Defined Controller
 */


/**
 *  @defgroup sac_position_force_control Position Force Control
 *
 *  With the position force control functionality, it is possible to configure 
 *  the force sensor output and to write the force segments into a force segment
 *  buffer. The force segments in the buffer are executed by a new setpoint
 *  generator with SPG state SAC_SPG_PFC. A force segment consists of a ramp part
 *  and a plateau part. The ramp part is defined by its end-force and the time to 
 *  reach that end-force. The plateau part is defined by the time to keep the force
 *  at the level which has been reached at the end of the ramp.
 */


/**
 *  @defgroup sac_miscellaneous Miscellaneous
 */


/**
 *  @defgroup sac_conversion Conversion
 *
 *  The functions within this module convert strings to enumeration values and vice versa.
 */

/**
 *  @ingroup sac_configuration
 *  Sac HALL sensor set enum 
 */
typedef enum sac_hall_sensor_set
{
    SAC_HALL_SENSOR_DIGIN = 0,  /**< Use inputs NYCE_DIGINy */
    SAC_HALL_SENSOR_RS422       /**< Use inputs NYCE_DIG5VINxA,B and C */
} SAC_HALL_SENSOR_SET;

/**
 *  @ingroup sac_function_io
 */
typedef enum sac_io_function
{
    SAC_NONE = -1,         /**< Input or output: no function */
    SAC_AREA_SENSOR,       /**< Input: area sensor */
    SAC_LATCH_0,           /**< Input: latch 0 */
    SAC_LATCH_1,           /**< Input: latch 1 */
    SAC_LATCH_2,           /**< Input: latch 2 */
    SAC_LATCH_3,           /**< Input: latch 3 */
    SAC_POS_LIMIT_SWITCH,  /**< Input: positive limit switch */
    SAC_NEG_LIMIT_SWITCH,  /**< Input: negative limit switch */
    SAC_ERROR_0,           /**< Input: error 0 */
    SAC_ERROR_1,           /**< Input: error 1 */
    SAC_ERROR_2,           /**< Input: error 2 */
    SAC_ERROR_3,           /**< Input: error 3 */
    SAC_ERROR_4,           /**< Input: error 4 */
    SAC_ERROR_5,           /**< Input: error 5 */
    SAC_START_TRIGGER,     /**< Input: start trigger */
    SAC_STOP_TRIGGER,      /**< Input: stop trigger */
    SAC_E_STOP,            /**< Input: E-Stop of IndraDrive */
    SAC_RELEASE_BRAKE,     /**< Output: release brake */
    SAC_EXT_DRIVE_ENABLE,  /**< Output: external drive enable */
    SAC_POSITION_SWITCH    /**< Output: position switch of IndraDrive */
} SAC_IO_FUNCTION;

/**
 *  @ingroup sac_function_io
 */
#define SAC_IO_FUNCTION_LAST SAC_POSITION_SWITCH

/**
 *  @ingroup sac_configuration
 */
typedef enum sac_axis_type
{
    SAC_NO_AXIS = -1,
    SAC_VIRTUAL_AXIS = 0,
    SAC_SENSOR_AXIS,
    SAC_OPEN_LOOP_AXIS,
    SAC_STEPPER_AXIS,
    SAC_SENSING_STEPPER_AXIS,
    SAC_SERVO_AXIS,
    SAC_COIL_AXIS,
    SAC_INDRA_BLAC_AXIS
} SAC_AXIS_TYPE;

/**
 *  @ingroup sac_configuration
 */
#define SAC_AXIS_TYPE_LAST SAC_INDRA_BLAC_AXIS

/**
 *  @ingroup sac_configuration
 */
typedef enum sac_motor_type
{
    SAC_NO_MOTOR               = 0,
    SAC_STEPPER_MOTOR          = 1,
    SAC_DC_MOTOR               = 2,
    SAC_BRUSHLESS_AC_MOTOR     = 3,
    SAC_BRUSHLESS_DC_MOTOR     = 4,
    SAC_EXTERNAL_DRIVE         = 5,
/*  not used                   = 6, */
    SAC_COIL_DRIVE             = 7,
    SAC_COIL_INDRADRIVE        = 8,
    SAC_INDRA_BLAC_MOTOR       = 9,
/*  not used                   = 10, */
    SAC_EXTERNAL_STEPPER_MOTOR = 11

} SAC_MOTOR_TYPE;

/**
 *  @ingroup sac_configuration
 */
#define SAC_MOTOR_TYPE_LAST SAC_EXTERNAL_STEPPER_MOTOR

/**
 *  @ingroup sac_configuration
 *  position sensor types
 */
typedef enum sac_position_sensor_type
{
    SAC_NO_POSITION_SENSOR    = 0,
    SAC_ANALOGUE_IN           = 1,
    SAC_S00_S90               = 2,
    SAC_S00_S90_WITHOUT_INDEX = 3,
    SAC_MSM_ABSOLUTE          = 4,
    SAC_MSM_INCREMENTAL       = 5,
    SAC_SIN_COS               = 6,
    SAC_DUAL_SIN_COS          = 7,
    SAC_TRIPLE_SIN_COS        = 8,
    SAC_ENDAT_21              = 9,
    SAC_ENDAT_22              = 10,
    SAC_HIPERFACE             = 11,
    SAC_SANYO_DENKI_ABSOLUTE  = 12  /**< PA035C and PA035S Sanyo Denki absolute encoders */
} SAC_POSITION_SENSOR_TYPE;

/**
 *  @ingroup sac_configuration
 */
#define SAC_POSITION_SENSOR_TYPE_LAST SAC_SANYO_DENKI_ABSOLUTE

/**
 *  @ingroup sac_error_and_service_handling
 *
 *  enumeration which holds the encoder errors for EnDat2.2 and Sanyo Denki encoders
 */
typedef enum sac_encoder_error
{
    SAC_NO_ENCODER_ERROR = 0,                  /**< EnDat2.2 and Sanyo Denki encoders */
    SAC_ENCODER_LIGHT_UNIT_FAILURE,            /**< EnDat2.2 encoders */
    SAC_ENCODER_SIGNAL_AMPLITUDE_TOO_LOW,      /**< EnDat2.2 encoders */
    SAC_ENCODER_POSITION_CALCULATION_ERROR,    /**< EnDat2.2 encoders */
    SAC_ENCODER_OVER_VOLTAGE,                  /**< EnDat2.2 encoders */
    SAC_ENCODER_UNDER_VOLTAGE,                 /**< EnDat2.2 encoders */
    SAC_ENCODER_EXCESSIVE_CURRENT_CONSUMPTION, /**< EnDat2.2 encoders */
    SAC_ENCODER_BATTERY_ALARM,                 /**< EnDat2.2 and Sanyo Denki encoders */
    SAC_ENCODER_MULTI_TURN_ERROR,              /**< Sanyo Denki encoders */
    SAC_ENCODER_SINGLE_TURN_ERROR,             /**< Sanyo Denki encoders */
    SAC_ENCODER_OVER_SPEED,                    /**< Sanyo Denki encoders */
    SAC_ENCODER_OVER_TEMPERATURE               /**< Sanyo Denki encoders */
} SAC_ENCODER_ERROR;

/**
 *  @ingroup sac_configuration
 *  sincos encoder pars
 */
typedef struct sac_sincos_encoder_pars
{
    double      indexLevelThreshold;      /**< index level threshold in [V] */
    double      minErrorLevel;            /**< minimum error level in [V] */
    double      maxErrorLevel;            /**< maximum error level in [V] */
    uint32_t    interpolationFactor;      /**< interpolation factor per full period */
    NYCE_ACTIVE_STATE    polarity;        /**< sincos encoder index polarity */
    uint32_t    encoderGlitchSuppressionTime; /**< sincos/s0s90 encoder glitch suppression time in [nr of clock ticks of 32ns] */ 

} SAC_SINCOS_ENCODER_PARS;

/**
 *  @ingroup sac_configuration
 *  endat encoder pars
 */
typedef struct sac_endat_encoder_pars
{
    uint32_t    clockFrequency;           /**< clock frequency of the EnDat encoder [Hz] */

} SAC_ENDAT_ENCODER_PARS;

/**
 *  @ingroup sac_configuration
 *  This enumeration contains the parity bits used with the Hiperface encoder.
 */
typedef enum sac_parity_bit
{
    SAC_PARITY_NONE = 0,
    SAC_PARITY_ODD,
    SAC_PARITY_EVEN
} SAC_PARITY_BIT;

/**
 *  @ingroup sac_configuration
 *  hiperface encoder pars
 */
typedef struct sac_hiperface_encoder_pars
{
    SAC_PARITY_BIT  parityBit;      /**< parity bit used on the encoder interface */
    uint32_t        baudRate;       /**< encoder communication speed [Bd] */

} SAC_HIPERFACE_ENCODER_PARS;

/**
 *  @ingroup sac_configuration
 *  encoder parameters
 */
typedef struct sac_encoder_pars
{
    SAC_SINCOS_ENCODER_PARS    sincos;
    SAC_ENDAT_ENCODER_PARS     endat;
    SAC_HIPERFACE_ENCODER_PARS hiperface;

} SAC_ENCODER_PARS;

/**
 *  @ingroup sac_configuration
 *  current control parameters
 */
typedef struct sac_current_control_pars
{
    double parKp;               /**< proportional gain of current controller */
    double parKi;               /**< integral gain of current controller */
    double maxIntegratorLevel;  /**< maximum contents of the current loop integrator */
    double saturationLevel;     /**< maximum current loop output */

} SAC_CURRENT_CONTROL_PARS;

/**
 *  @ingroup sac_configuration
 */
typedef struct sac_pwm_pars
{
    double      frequency;     /**< pwm frequency */

} SAC_PWM_PARS;

/**
 *  @ingroup sac_configuration
 *  stepper motor commutation parameters
 */
typedef struct sac_stepper_motor_pars
{
    uint32_t    nrOfMicroSteps;           /**< number of microsteps per step */
    double      delayCompensationTime;    /**< adjusts motor current directions to rotation during current loop calculation */ 

} SAC_STEPPER_MOTOR_PARS;

/**
 *  @ingroup sac_configuration
 */
typedef struct sac_brushless_ac_motor_pars
{
    uint32_t    nrOfPolePairs;        /**< number of polepairs */
    double      puPerNrOfPolePairs;   /**< number of encoder position units per number of polepairs */

} SAC_BRUSHLESS_AC_MOTOR_PARS;

/**
 *  @ingroup sac_configuration
 */
typedef struct sac_brushless_dc_motor_pars
{
    SAC_HALL_SENSOR_SET hallSensorSet;
    uint32_t            sixStepCommutation[6]; /**< defines order in which phases are powered */ 

} SAC_BRUSHLESS_DC_MOTOR_PARS;

/**
 *  @ingroup sac_configuration
 */
typedef struct sac_commutation_pars
{
    SAC_STEPPER_MOTOR_PARS             stepper;             /**< structure with stepper motor commutation parameters */ 
    SAC_BRUSHLESS_AC_MOTOR_PARS        brushlessAC;         /**< structure with brushless AC motor commutation parameters */
    SAC_BRUSHLESS_DC_MOTOR_PARS        brushlessDC;         /**< structure with brushless DC motor commutation parameters */

} SAC_COMMUTATION_PARS;

/**
 *  @ingroup sac_configuration
 */
typedef struct sac_external_stepper_pars
{
    double            pulseOnTime;        /**< pulse on time of pulse output in [s] */ 
    double            pulseOffTime;       /**< pulse off time of pulse output in [s] */ 
    double            directionDelayTime; /**< delay time of direction output in [s] */
    NYCE_ACTIVE_STATE pulseLevel;         /**< active level of pulse output */
    NYCE_ACTIVE_STATE directionLevel;     /**< active level of direction output */

} SAC_EXTERNAL_STEPPER_PARS;

/**
 *  @ingroup sac_configuration
 */
typedef struct sac_configure_axis_pars
{
    SAC_AXIS_TYPE             axisType;
    NYCE_AXIS_UNIT_ID         axisUnitId;
    SAC_MOTOR_TYPE            motorType;
    SAC_POSITION_SENSOR_TYPE  positionSensorType;
    SAC_ENCODER_PARS          encoderPars;
    SAC_COMMUTATION_PARS      commutationPars;
    SAC_EXTERNAL_STEPPER_PARS externalStepperPars;

} SAC_CONFIGURE_AXIS_PARS;

/**
 *  @ingroup sac_configuration
 */
typedef enum sac_alignment_mode
{
    SAC_ALIGN_MODE_NONE,                /**< Do not execute alignment procedure */
    SAC_ALIGN_KICK_AND_SWING,           /**< use alignment procedure possibly with large displacement */
    SAC_ALIGN_WAKE_AND_SHAKE,           /**< use alignment with controllable maximum displacement */
    SAC_ALIGN_SET_COMMUTATION_OFFSET,   /**< alignment procedure used when commutation angle at current position is known, e.g. at an end-of-stroke or sensor */
    SAC_ALIGN_ON_ENCODER_POSITION,      /**< alignment procedure on absolute encoder position */
    SAC_ALIGN_CATCH_AND_MOVE,           /**< use alignment for axes against endstop or non-horizontal */
    SAC_ALIGN_INDRA_SATURATION,         /**< saturation alignment procedure of IndraDrive */
    SAC_ALIGN_INDRA_SINE_WAVE,          /**< sine wave alignment procedure of IndraDrive */
    SAC_ALIGN_INDRA_LOCKED,             /**< locked alignment procedure of IndraDrive, to be performed after initianal commissioning of the IndraDrive */
    SAC_ALIGN_PUSH_AND_SETTLE           /**< use alignment procedure possibly with large but smooth displacement */
} SAC_ALIGNMENT_MODE;

/**
 *  @ingroup sac_configuration
 */
typedef struct sac_align_motor_pars
{
    SAC_ALIGNMENT_MODE  mode;
    double              maxControllerOutput;  /**< output used during alignment procedure. @_validIf mode=(SAC_ALIGN_KICK_AND_SWING|SAC_ALIGN_WAKE_AND_SHAKE|SAC_ALIGN_PUSH_AND_SETTLE) */
    double              testSignalTestTime;   /**< pulse time used in wake and shake procedure. @_validIf mode=(SAC_ALIGN_WAKE_AND_SHAKE) */
    double              criticalDisplacement; /**< motion detection threshold displacement used in wake and shake. @_validIf mode=(SAC_ALIGN_WAKE_AND_SHAKE) */
    double              commutationOffset;    /**< commutation angle for SAC_ALIGN_SET_COMMUTATION_OFFSET or commutation offset for SAC_ALIGN_ON_ENCODER_POSITION. @_validIf mode=(SAC_ALIGN_SET_COMMUTATION_OFFSET|SAC_ALIGN_ON_ENCODER_POSITION) */
    double              angleAlpha;           /**< commutation angle at one endstop, typically negative endstop used in catch and move. @_validIf mode=(SAC_ALIGN_CATCH_AND_MOVE) */
    double              angleBeta;            /**< commutation angle at one endstop, typically positive endstop used in catch and move. @_validIf mode=(SAC_ALIGN_CATCH_AND_MOVE) */
    double              distance;             /**< distance to be made during alignment used in catch and move. @_validIf mode=(SAC_ALIGN_CATCH_AND_MOVE) */
    double              deviation;            /**< allowed deviation in between angle move and actual position change, as a percentage of the pole pitch used in catch and move. @_validIf mode=(SAC_ALIGN_CATCH_AND_MOVE) */
    double              rampTime;             /**< time used during phase 1 and 2 used in catch and move. @_validIf mode=(SAC_ALIGN_CATCH_AND_MOVE) */
    double              moveTime;             /**< time used during phase 1 and 3 used in catch and move. @_validIf mode=(SAC_ALIGN_CATCH_AND_MOVE) */
    double              holdTime;             /**< time used during phase 1,2 and 3 used in catch and move. @_validIf mode=(SAC_ALIGN_CATCH_AND_MOVE) */
    double              minCurrentLevel;      /**< max current used during phase 1 used in catch and move. @_validIf mode=(SAC_ALIGN_CATCH_AND_MOVE) */
    double              maxCurrentLevel;      /**< max current used during phase 2 and 3 used in catch and move. @_validIf mode=(SAC_ALIGN_CATCH_AND_MOVE) */
    double              indraTestSignalStartAmplitude;  /**< IndraDrive test signal amplitude for alignment. @_validIf mode=(SAC_ALIGN_INDRA_SATURATION|SAC_ALIGN_INDRA_SINE_WAVE) */
    double              indraTestSignalStartFrequency;  /**< IndraDrive test signal frequency for alignment. @_validIf mode=(SAC_ALIGN_INDRA_SATURATION|SAC_ALIGN_INDRA_SINE_WAVE) */
    double              pushSettleRampTime;   /**< time used during phase 1 in push and settle. @_validIf mode=(SAC_ALIGN_PUSH_AND_SETTLE) */
} SAC_ALIGN_MOTOR_PARS;

/**
 *  @ingroup sac_configuration
 */
typedef struct sac_move_current_angle_pars
{
    double startAngle;
    double stopAngle;
    double currentLevel;
    double rampTime;
    double moveTime;
    double holdTime;

} SAC_MOVE_CURRENT_ANGLE_PARS;

/**
 *  @ingroup sac_configuration
 *  Sac H-bridge state enum 
 */
typedef enum sac_h_bridge_state_at_power_disabled
{
    SAC_H_BRIDGE_OPEN = 0,                /**< H-bridge open */
    SAC_H_BRIDGE_LOW_SIDE_SHORT_CIRCUIT   /**< H-bridge low side short circuited */
} SAC_H_BRIDGE_STATE_AT_POWER_DISABLED;

/**
 *  @ingroup sac_state_transitions
 */
typedef enum sac_move_current_angle_state
{
    SAC_MOVE_CURRENT_ANGLE_STATE_IDLE = 0,
    SAC_MOVE_CURRENT_ANGLE_STATE_INIT,
    SAC_MOVE_CURRENT_ANGLE_STATE_RAMPING,
    SAC_MOVE_CURRENT_ANGLE_STATE_MOVING,
    SAC_MOVE_CURRENT_ANGLE_STATE_HOLDING,
    SAC_MOVE_CURRENT_ANGLE_STATE_DETECT,
    SAC_MOVE_CURRENT_ANGLE_STATE_FIND_ZERO,
    SAC_MOVE_CURRENT_ANGLE_STATE_SWINGING,
    SAC_MOVE_CURRENT_ANGLE_STATE_INITIAL_MOVE,
    SAC_MOVE_CURRENT_ANGLE_STATE_FORCE_TO_ANGLE,
    SAC_MOVE_CURRENT_ANGLE_STATE_MOVE_EXPECTED_ANGLE,
    SAC_MOVE_CURRENT_ANGLE_STATE_CHECK_EXPECTED_DISPLACEMENT,
    SAC_MOVE_CURRENT_ANGLE_STATE_LIMIT_SWITCH_ACTIVE,
    SAC_MOVE_CURRENT_ANGLE_STATE_FINISHING
} SAC_MOVE_CURRENT_ANGLE_STATE;


/**
 *  @ingroup sac_state_transitions
 */
typedef enum sac_state
{
    SAC_MOVING = 0,                 /**< axis initialized, control loop closed,     drive enabled,      setpoint generator active,   brake released, no error */
    SAC_READY,                      /**< axis initialized, control loop closed,     drive enabled,      setpoint generator idle,     brake released, no error */
    SAC_READY_STOPPED,              /**< axis initialized, control loop closed,     drive enabled,      setpoint generator disabled, brake released, non fatal error */
    SAC_FREE,                       /**< axis initialized, control loop open,       drive enabled,      setpoint generator disabled, brake released, no error */
    SAC_FREE_STOPPED,               /**< axis initialized, control loop open,       drive enabled,      setpoint generator disabled, brake released, non fatal error */
    SAC_ERROR,                      /**< axis initialized, control loop disabled,   drive disabled,     setpoint generator disabled, brake applied, fatal error */
    SAC_INACTIVE,                   /**< axis initialized, control loop disabled,   drive disabled,     setpoint generator disabled, brake applied, no error */
    SAC_IDLE,                       /**< axis not initialized, control loop disabled, drive disabled,   setpoint generator disabled, brake applied, no error */
    SAC_NO_STATE                    /**< No state, for internal use only */
} SAC_STATE;

/**
 *  @ingroup sac_state_transitions
 */
typedef enum sac_spg_state
{
    SAC_SPG_DISABLED        = 0,      /**< Set point generator is disabled */
    SAC_SPG_IDLE            = 1,      /**< Performing none of the commands below */
    SAC_SPG_PTPING          = 2,      /**< Perform point-to-point profile */
    SAC_SPG_JOGGING         = 3,      /**< Perform jogging profile */
    SAC_SPG_INTERPOLATING   = 4,      /**< Perform spline interpolating */
    SAC_SPG_GEARING         = 5,      /**< Perform gearing */
    SAC_SPG_CAMMING         = 6,      /**< Perform camming */
    SAC_SPG_SMOOTHSTOPPING  = 7,      /**< Perform stop with smooth stop profile */
    SAC_SPG_QUICKSTOPPING   = 8,      /**< Perform stop with quick stop profile */
    SAC_SPG_FULLSTOPPING    = 9,      /**< Perform stop with full stop profile */
/*  not used                = 10, */
    SAC_SPG_FCL             = 11,     /**< Axis is controlled by FCL */
    SAC_SPG_PFC             = 12,     /**< Perform force segment interpolating */
    SAC_SPG_CARRIER_MTC     = 13,     /**< Perform move carrier starting from current position */
    SAC_SPG_CARRIER_MTI     = 14,     /**< Perform move carrier starting from initial position */
    SAC_SPG_CARRIER_MEV     = 15,     /**< Perform move carrier starting from initial position */
                                      /**< with end velocity */
    SAC_SPG_CARRIER_PRF     = 16,     /**< Perform move carrier starting from current position */
                                      /**< along profile */
    SAC_SPG_CARRIER_STP     = 17,     /**< Perform stop carrier movement */
    SAC_SPG_CARRIER_QST     = 18,     /**< Perform quick stop carrier movement */

    SAC_LAST_SPG_STATE      = 19      /**< @_nrOfEnumValues */
} SAC_SPG_STATE;

/**
 *  @ingroup sac_parameters
 */
typedef enum sac_home_mode
{
    SAC_HOME_MODE_AXIS_POS,                       /**< define home "axis position", no move */
    SAC_HOME_MODE_SETPOINT_POS,                   /**< define home "setpoint position", no move */
    SAC_HOME_MODE_POS_ENCODER,                    /**< define home "position encoder", no move */

    SAC_HOME_MODE_INDEX_ONLY,                     /**< home search "index only" */
    SAC_HOME_MODE_AREA_ONLY,                      /**< home search "area only" */
    SAC_HOME_MODE_INDEX_AREA,                     /**< home search "index and area" */
    SAC_HOME_MODE_END_OF_STROKE,                  /**< home search "end of stroke" */

    SAC_HOME_MODE_AREA_NEAR_EOS,                  /**< home search "area near end of stroke" */
    SAC_HOME_MODE_INDEX_NEAR_EOS,                 /**< home search "index near end of stroke" */
    SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS,         /**< home search "index and area near end of stroke" */

    SAC_HOME_MODE_LIMIT_SWITCH_ONLY,              /**< home search "limit switch only" */
    SAC_HOME_MODE_INDEX_LIMIT_SWITCH,             /**< home search "index and limit switch" */
    SAC_HOME_MODE_LIMIT_SWITCH_NEAR_EOS,          /**< home search "limit switch near end of stroke" */
    SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS,    /**< home search "index and limit switch near end of stroke" */
    SAC_HOME_MODE_HERE,                           /**< define home "here", no move */

    SAC_HOME_MODE_INDEX_ONLY_DBL,                 /**< home search "index only, double sided" */
    SAC_HOME_MODE_INDEX_AREA_DBL,                 /**< home search "index and area, double sided" */
    SAC_HOME_MODE_INDEX_NEAR_EOS_DBL,             /**< home search "index near end of stroke, double sided" */   
    SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS_DBL,     /**< home search "index and area near end of stroke, double sided" */
    SAC_HOME_MODE_INDEX_LIMIT_SWITCH_DBL,         /**< home search "index and limit switch, double sided" */
    SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS_DBL /**< home search "index and limit switch near end of stroke, double sided" */

} SAC_HOME_MODE;


/**
 *  @ingroup sac_parameters
 */
typedef enum sac_inversion
{
    SAC_INVERT = -1,        /**< invert the signal */
    SAC_NO_INVERT = 1       /**< do not invert the signal */
} SAC_INVERSION;


/**
 *  @ingroup sac_parameters
 */
typedef enum sac_eos_criterion
{
    SAC_POSITION_ERROR = 1, /**< position error criterion used */
    SAC_CONTROLLER_LEVEL    /**< controller output criterion used */
} SAC_EOS_CRITERION;

/**
 *  @ingroup sac_parameters
 */
typedef struct sac_home_pars
{
    SAC_HOME_MODE     mode;
    double            offset;               /**< value of home position after home procedure.                       @_validIf mode=(SAC_HOME_MODE_AXIS_POS|SAC_HOME_MODE_SETPOINT_POS|SAC_HOME_MODE_POS_ENCODER|
                                                                                                                                    SAC_HOME_MODE_INDEX_ONLY|SAC_HOME_MODE_AREA_ONLY|SAC_HOME_MODE_INDEX_AREA|SAC_HOME_MODE_LIMIT_SWITCH_ONLY|SAC_HOME_MODE_INDEX_LIMIT_SWITCH|SAC_HOME_MODE_INDEX_ONLY_DBL|SAC_HOME_MODE_INDEX_AREA_DBL|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_DBL|
                                                                                                                                    SAC_HOME_MODE_END_OF_STROKE|SAC_HOME_MODE_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS|SAC_HOME_MODE_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS_DBL) */
    double            velocity;             /**< velocity during home movement.                                     @_validIf mode=(SAC_HOME_MODE_INDEX_ONLY|SAC_HOME_MODE_AREA_ONLY|SAC_HOME_MODE_INDEX_AREA|SAC_HOME_MODE_LIMIT_SWITCH_ONLY|SAC_HOME_MODE_INDEX_LIMIT_SWITCH|SAC_HOME_MODE_INDEX_ONLY_DBL|SAC_HOME_MODE_INDEX_AREA_DBL|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_DBL|
                                                                                                                                    SAC_HOME_MODE_END_OF_STROKE|SAC_HOME_MODE_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS|SAC_HOME_MODE_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS_DBL) */
    double            acceleration;         /**< acceleration during home movement.                                 @_validIf mode=(SAC_HOME_MODE_INDEX_ONLY|SAC_HOME_MODE_AREA_ONLY|SAC_HOME_MODE_INDEX_AREA|SAC_HOME_MODE_LIMIT_SWITCH_ONLY|SAC_HOME_MODE_INDEX_LIMIT_SWITCH|SAC_HOME_MODE_INDEX_ONLY_DBL|SAC_HOME_MODE_INDEX_AREA_DBL|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_DBL|
                                                                                                                                    SAC_HOME_MODE_END_OF_STROKE|SAC_HOME_MODE_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS|SAC_HOME_MODE_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS_DBL) */
    double            jerk;                 /**< jerk during home movement.                                         @_validIf mode=(SAC_HOME_MODE_INDEX_ONLY|SAC_HOME_MODE_AREA_ONLY|SAC_HOME_MODE_INDEX_AREA|SAC_HOME_MODE_LIMIT_SWITCH_ONLY|SAC_HOME_MODE_INDEX_LIMIT_SWITCH|SAC_HOME_MODE_INDEX_ONLY_DBL|SAC_HOME_MODE_INDEX_AREA_DBL|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_DBL|
                                                                                                                                    SAC_HOME_MODE_END_OF_STROKE|SAC_HOME_MODE_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS|SAC_HOME_MODE_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS_DBL) */
    SAC_EOS_CRITERION eosCriterion;         /**< End of stroke criterion.                                           @_validIf mode=(SAC_HOME_MODE_END_OF_STROKE|SAC_HOME_MODE_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS_DBL) */
    double            eosPosCriterion;      /**< position error threshold value for end of stroke detection.        @_validIf mode=(SAC_HOME_MODE_END_OF_STROKE|SAC_HOME_MODE_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS_DBL)&
                                                                                                                              eosCriterion=(SAC_POSITION_ERROR) */
    double            eosContrCriterion;    /**< controller output threshold value for end of stroke detection.     @_validIf mode=(SAC_HOME_MODE_END_OF_STROKE|SAC_HOME_MODE_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS_DBL)&
                                                                                                                              eosCriterion=(SAC_CONTROLLER_LEVEL) */
    double            eosOutput;            /**< open loop output used after end of stroke detection.               @_validIf mode=(SAC_HOME_MODE_END_OF_STROKE|SAC_HOME_MODE_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS|SAC_HOME_MODE_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS_DBL) */
    double            eosOpenLoopTime;      /**< time to maintain open loop output after end of stroke detection.   @_validIf mode=(SAC_HOME_MODE_END_OF_STROKE|SAC_HOME_MODE_AREA_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS|SAC_HOME_MODE_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS|SAC_HOME_MODE_INDEX_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_ON_AREA_NEAR_EOS_DBL|SAC_HOME_MODE_INDEX_LIMIT_SWITCH_NEAR_EOS_DBL) */

} SAC_HOME_PARS;


/**
 *  @ingroup sac_motion
 */
typedef enum sac_reference
{
    SAC_ABSOLUTE, /**< Absolute position: destination */
    SAC_RELATIVE  /**< Relative position: displacement */
} SAC_REFERENCE;


/**
 *  @ingroup sac_motion
 */
typedef struct sac_ptp_pars
{
    double        position;             /**< end position for absolute ptp movement, displacement for relative ptp movement [pu] */  
    double        velocity;             /**< maximum velocity during ptp movement [pu/s] */
    double        acceleration;         /**< maximum acceleration during ptp movement [pu/s^2] */
    double        jerk;                 /**< maximum jerk during ptp movement [pu/s^3] */
    SAC_REFERENCE positionReference;

} SAC_PTP_PARS;


/**
 *  @ingroup sac_motion
 */
typedef struct sac_jog_pars
{
   double        velocity;              /**< maximum velocity during jog movement [pu/s] */
   double        acceleration;          /**< maximum acceleration during jog movement [pu/s^2] */
   double        jerk;                  /**< maximum jerk during jog movement [pu/s^3] */

} SAC_JOG_PARS;


/**
 *  @ingroup sac_motion
 */
typedef struct sac_cub_pars
{
    double          position;             /**< end position for absolute spline segment, displacement during relative spline segment [pu] */
    double          velocity;             /**< end velocity of spline segment [pu/s] */
    double          time;                 /**< duration of sline segment */
    SAC_REFERENCE   positionReference;    
    BOOL            generateEvent;        /**< generate event at start of segment */  
    uint32_t        splineId;             /**< possibility to give unique identifier to spline which is retrieved during a spline event */

} SAC_CUB_PARS;


/**
 *  @ingroup sac_motion
 */
typedef struct sac_feed_override_pars
{
    double feedOverride;    /**< required feedoverride level */
    double transitionTime;  /**< allowed time to go to the new feedoverride level */

} SAC_FEED_OVERRIDE_PARS;


/**
 *  @ingroup sac_parameters
 */
typedef struct sac_smoothstop_pars
{
    double acceleration; /**< deceleration during smoothstop [pu/s^2] */
    double jerk;         /**< jerk during smoothstop [pu/s^3] */ 

} SAC_SMOOTHSTOP_PARS;


/**
 *  @ingroup sac_parameters
 */
typedef struct sac_quickstop_pars
{
    double acceleration; /**< deceleration during quickstop [pu/s^2] */

} SAC_QUICKSTOP_PARS;


/**
 *  @ingroup sac_synchronize_groups
 *  Multi-Axis synchronization action.
 */
typedef enum mac_sync_action
{
    MAC_FIRST_SYNC_ACTION = 0,               /**< @_invalidEnumValue */
    MAC_SYNC_MOTION,                         /**< synchronized start of a motion command */
    MAC_SYNC_FEED_OVERRIDE,                  /**< synchronized activation of feed override */
    MAC_SYNC_SMOOTH_STOP,                    /**< synchronized activation of smooth stop */
    MAC_SYNC_QUICK_STOP,                     /**< synchronized activation of quick stop */
    MAC_SYNC_FULL_STOP,                      /**< synchronized activation of full stop */
    MAC_LAST_SYNC_ACTION                     /**< @_nrOfEnumValues */
} MAC_SYNC_ACTION;


/**
 *  @ingroup sac_electronic_gearing
 */
typedef enum sac_ecg_position_source
{
    SAC_ECG_AXIS_POSITION,     /**< use axis position */
    SAC_ECG_SETPOINT_POSITION  /**< use setpoint position */
} SAC_ECG_POSITION_SOURCE;


/**
 *  @ingroup sac_electronic_gearing
 */
typedef struct sac_ecg_master
{
    SAC_AXIS                axisId;
    SAC_ECG_POSITION_SOURCE masterPosSource;

} SAC_ECG_MASTER;


/**
 *  @ingroup sac_electronic_gearing
 */
typedef enum sac_ecg_lock_mode
{
    SAC_ECG_LOCK_MAS_ABS_SLAVE_ABS = 0, /**< Both master and slave positions are specified as absolute positions. */
    SAC_ECG_LOCK_MAS_ABS_SLAVE_REL,     /**< The master position is specified as an absolute position. The slave position is specified as a relative position. */
    SAC_ECG_LOCK_MAS_ABS_SLAVE_AUTO,    /**< The master position is specified an absolute position. */
                                        /**< The specified slave end position is not used and will be determined by the controller. */
    SAC_ECG_LOCK_MAS_REL_SLAVE_ABS,     /**< The master position is specified as a relative position. The slave position is specified as an absolute position. */
    SAC_ECG_LOCK_MAS_REL_SLAVE_REL,     /**< Both master and slave positions are specified as relative positions. */
    SAC_ECG_LOCK_MAS_REL_SLAVE_AUTO     /**< The master position is specified as a relative position. */
                                        /**< The specified slave end position is not used and will be determined by the controller. */
} SAC_ECG_LOCK_MODE;


/**
 *  @ingroup sac_electronic_gearing
 */
typedef struct sac_ecg_lock_gear_pars
{
    double              ratio;          /**< Velocity ratio (gear ratio) between master and slave. Defined as vel(slave)/vel(master).*/
    double              masterEndPos;   /**< Master axis position where the transition profile finishes and the gear ratio is stable. */ 
                                        /**< The lockMode parameter defines whether this is a relative displacement or an absolute position. */
    double              slaveEndPos;    /**< Slave axis position where the transition profile finishes and the gear ratio is stable. */
                                        /**< The lockMode parameter defines whether this is a relative displacement, */
                                        /**< an absolute position. This parameter is not used if the xxx_SLAVE_AUTO lock mode is specified. */
    SAC_ECG_LOCK_MODE   lockMode;       /**< Defines how to interpret masterEndPos and slaveEndPos. */

} SAC_ECG_LOCK_GEAR_PARS;

/**
 *  @ingroup sac_electronic_gearing
 */
typedef struct sac_ecg_lock_cam_pars
{
    uint32_t            tableId;        /**< User defined cam table identifier. */
    double              masterTablePos; /**< Table master position in the cam table, which defines the table position to be reached after the transition profile and where actual camming will start. */ 
    double              masterEndPos;   /**< Master axis position where the transition profile finishes and the cam function will be followed. */ 
                                        /**< The lockMode parameter defines whether this is a relative displacement or an absolute position. */
    double              slaveEndPos;    /**< Slave axis position where the transition profile finishes and the cam function will be followed. */
                                        /**< The lockMode parameter defines whether this is a relative displacement, */
                                        /**< an absolute position. This parameter is not used if the xxx_SLAVE_AUTO lock mode is specified. */
    SAC_ECG_LOCK_MODE   lockMode;       /**< Defines how to interpret masterEndPos and slaveEndPos. */

} SAC_ECG_LOCK_CAM_PARS;

/**
 *  @ingroup sac_electronic_gearing
 */
typedef struct sac_ecg_shift_cam_table_pars
{
    double              tableShift;     /**< Amount of table shift in the master direction. */ 
    double              masterEndPos;   /**< End position of the master axis over which the table shift will be executed. */
                                        /**< The reference parameter defines whether this is a relative displacement or an absolute position. */
    SAC_REFERENCE       reference;      /**< Defines how to interpret masterEndPos. */
      
} SAC_ECG_SHIFT_CAM_TABLE_PARS;


/**
 *  @ingroup sac_test_generator
 */
typedef enum sac_test_signal_type
{
    SAC_TEST_SIGNAL_NONE = 0,    /**< see below */
    SAC_TEST_SIGNAL_BLOCK_WAVE,  /**< block wave test signal */
    SAC_TEST_SIGNAL_SINE_WAVE,   /**< sine wave test signal */
    SAC_TEST_SIGNAL_SAW_TOOTH,   /**< saw tooth test signal */
    SAC_TEST_SIGNAL_PRBS,        /**< pseudo-random bit sequence test signal */
    SAC_TEST_SIGNAL_RANDOM_NOISE /**< random noise test signal */
} SAC_TEST_SIGNAL_TYPE;


/**
 *  @ingroup sac_test_generator
 */
typedef struct sac_test_signal_blk_pars
{
    double frequency;       /**< frequency of blockwave [Hz] */ 

} SAC_TEST_SIGNAL_BLK_PARS;


/**
 *  @ingroup sac_test_generator
 */
typedef struct sac_test_signal_sin_pars
{
    double frequency;   /**< frequency of sinewave [Hz] */

} SAC_TEST_SIGNAL_SIN_PARS;


/**
 *  @ingroup sac_test_generator
 */
typedef struct sac_test_signal_swt_pars
{
    double frequency;   /**< frequency of sawtooth [Hz] */

} SAC_TEST_SIGNAL_SWT_PARS;


/**
 *  @ingroup sac_test_generator
 */
typedef struct sac_test_signal_prb_pars
{
    double time;        /**< duration of pseudo random binary noise signal */

} SAC_TEST_SIGNAL_PRB_PARS;


/**
 *  @ingroup sac_test_generator
 */
typedef struct sac_test_signal_rnd_pars
{
    double      time; /**< duration of random noise signal */
    uint32_t    seed; /**< used to create first noise output */

} SAC_TEST_SIGNAL_RND_PARS;


/**
 *  @ingroup sac_test_generator
 */
typedef union sac_test_signal_function_pars
{
    SAC_TEST_SIGNAL_BLK_PARS blk;   /**< blockwave */
    SAC_TEST_SIGNAL_SIN_PARS sin;   /**< sinewave */
    SAC_TEST_SIGNAL_SWT_PARS saw;   /**< sawtooth */
    SAC_TEST_SIGNAL_PRB_PARS prb;   /**< pseudo random binary noise */
    SAC_TEST_SIGNAL_RND_PARS rnd;   /**< random noise */

} SAC_TEST_SIGNAL_FUNCTION_PARS;


/**
 *  @ingroup sac_test_generator
 */
typedef enum sac_test_signal_inject_point_id
{
    SAC_TEST_SIGNAL_INJ_NONE,        /**< no addition */
    SAC_TEST_SIGNAL_INJ_SETPOINT,    /**< add to setpoint position */
    SAC_TEST_SIGNAL_INJ_OL_OUTPUT,   /**< add to open loop controller output */
    SAC_TEST_SIGNAL_INJ_CL_OUTPUT    /**< add to closed loop controller output */
} SAC_TEST_SIGNAL_INJECT_POINT_ID;


/**
 *  @ingroup sac_test_generator
 */
typedef struct sac_test_signal_pars
{
    SAC_TEST_SIGNAL_TYPE            testSignalType;
    SAC_TEST_SIGNAL_FUNCTION_PARS   testSignalFunctionPars;
    double                          amplitudeScaling;           /**< maximum signal level */
    double                          offset;                     /**< output offset */
    int32_t                         nrOfPeriods;                /**< number of periods in testsignal */
    SAC_TEST_SIGNAL_INJECT_POINT_ID testSignalInjectPointId;    

} SAC_TEST_SIGNAL_PARS;

/**
 *  @ingroup sac_parameters
 */
typedef enum sac_controller_type
{
    SAC_CTR_PVL_ON_DRV,     /**< position loop is located in drive */
    SAC_CTR_PVL_ON_MCU,     /**< position loop is located in MCU */
    SAC_CTR_UDC_0,          /**< user definable controller structure with identifier 0 */
    SAC_CTR_UDC_1,          /**< user definable controller structure with identifier 1 */
    SAC_CTR_UDC_2,          /**< user definable controller structure with identifier 2 */
    SAC_CTR_UDC_3,          /**< user definable controller structure with identifier 3 */
    SAC_CTR_UDC_4,          /**< user definable controller structure with identifier 4 */
    SAC_CTR_UDC_5,          /**< user definable controller structure with identifier 5 */
    SAC_CTR_UDC_6,          /**< user definable controller structure with identifier 6 */
    SAC_CTR_UDC_7,          /**< user definable controller structure with identifier 7 */
    SAC_CTR_UDC_8,          /**< user definable controller structure with identifier 8 */
    SAC_CTR_UDC_9           /**< user definable controller structure with identifier 9 */
} SAC_CONTROLLER_TYPE;

/**
 *  @ingroup sac_parameters
 */
typedef struct sac_controller_type_pars
{
    SAC_CONTROLLER_TYPE controllerType;

} SAC_CONTROLLER_TYPE_PARS;

/**
 *  @ingroup sac_parameters
 */
typedef enum sac_velocity_estimation_method
{
    SAC_VEL_EST_LAGRANGE2,          /**< calculate velocity from 3 samples using determined different weighfactors for the 3 samples */
    SAC_VEL_EST_DERIVATIVE_SAMPLE   /**< derive over user defined number of samples all samples have the same weight factor */
} SAC_VELOCITY_ESTIMATION_METHOD;

/**
 *  @ingroup sac_parameters
 */
typedef enum sac_integrator_switch_off_mode
{
    SAC_INTEGRATOR_RESET_AND_DISABLE,   /**< reset and disable the integrator when the velocity exceeds the threshold velocity */
    SAC_INTEGRATOR_HOLD                 /**< hold the integrator buffer on his actual value when the velocity exceeds the threshold velocity */
} SAC_INTEGRATOR_SWITCH_OFF_MODE;

/**
 *  @ingroup sac_parameters
 */
typedef enum sac_ff_addition_point
{
    SAC_FF_BEFORE_NOTCH,                /**< feedforward is added before the notch filters */
    SAC_FF_AFTER_NOTCH                  /**< feedforward is added after the notch filters */
} SAC_FF_ADDITION_POINT;

/**
 *  @ingroup sac_parameters
 */
typedef struct sac_controller_pid_pars
{
    double                          parKp;                       /**< proportional gain of position controller */
    double                          parKv;                       /**< derivative gain of position controller */
    double                          parKi;                       /**< integral gain of position controller */
    double                          parKfv;                      /**< viscous friction feedforward gain */
    double                          parKfa;                      /**< acceleration feedforward gain */
    double                          parKfj;                      /**< jerk feedforward gain */
    double                          parKfst;                     /**< gravity feedforward gain */
    double                          parKfc;                      /**< coulomb friction feedforward gain */
    SAC_VELOCITY_ESTIMATION_METHOD  velocityEstimationMethod;
    int32_t                         nrOfSamples;                 /**< numbers of samples used for SAC_VEL_EST_DERIVATIVE_SAMPLE method */
    double                          thresholdVelocity;           /**< threshold value for integral action */
    SAC_INTEGRATOR_SWITCH_OFF_MODE  integratorSwitchOffMode;     /**< integrator behavior above threshold velocity */
    double                          maxIntegratorLevel;          /**< maximum integrator contents */
    double                          saturationLevel;             /**< maximum positive controller output saturation level */
    double                          saturationMinLevel;          /**< maximum negative controller output saturation level */    
    BOOL                            asymmetricSaturation;        /**< enable asymmetric saturation */ 
    SAC_FF_ADDITION_POINT           ffAdditionPoint;             /**< feedforward addition point, before or after notch filters */

} SAC_CONTROLLER_PID_PARS;


/**
 *  @ingroup sac_parameters
 */
typedef struct sac_controller_filter_pars
{
    BOOL   lowPassEnabled;      /**< enable lowpass filter */
    double lowPassFreq;         /**< cutoff frequency lowpass filter */
    double lowPassDamping;      /**< damping lowpass filter */

    BOOL   leadLagEnabled;      /**< enable leadlag filter */
    double leadFreq;            /**< start frequency of lead action */
    double lagFreq;             /**< cutoff frequency of lag action */

    BOOL   notchAEnabled;       /**< enable notch A filter */
    double notchANumFreq;       /**< frequency of numerator of notch A */
    double notchANumDamping;    /**< damping of numerator of notch A */ 
    double notchADenFreq;       /**< frequency of denominator of notch A */
    double notchADenDamping;    /**< damping of denominator of notch A */

    BOOL   notchBEnabled;       /**< enable notch B filter */
    double notchBNumFreq;       /**< frequency of numerator of notch B */
    double notchBNumDamping;    /**< damping of numerator of notch B */ 
    double notchBDenFreq;       /**< frequency of denominator of notch B */
    double notchBDenDamping;    /**< damping of denominator of notch B */

    BOOL   notchCEnabled;       /**< enable notch C filter */
    double notchCNumFreq;       /**< frequency of numerator of notch C */
    double notchCNumDamping;    /**< damping of numerator of notch C */ 
    double notchCDenFreq;       /**< frequency of denominator of notch C */
    double notchCDenDamping;    /**< damping of denominator of notch C */

} SAC_CONTROLLER_FILTER_PARS;


/**
 *  @ingroup sac_parameters
 */
typedef struct sac_error_check_pars
{
    double posSwEndSwitch;              /**< position of positive software limit switch */
    double negSwEndSwitch;              /**< position of negative software limit switch */
    double maxSteadyStateError;         /**< maximum allowable error during READY state */
    double maxDynPosError;              /**< maximum allowable error during MOVING state */
    double maxSettlingTime;             /**< maximum settling time */
    double collisionTimeWindow;         /**< collision error occurs when control out > collisionControllerOutput during collisionTimeWindow and velocity < collisionVelocity */
    double collisionControllerOutput;   /**< collision error occurs when control out > collisionControllerOutput during collisionTimeWindow and velocity < collisionVelocity */
    double collisionVelocity;           /**< collision error occurs when control out > collisionControllerOutput during collisionTimeWindow and velocity < collisionVelocity */
    double maxSpgVelocity;              /**< maximum allowed setpoint velocity */
    double maxSpgAcceleration;          /**< maximum allowed setpoint generation */
    double maxSpgJerk;                  /**< maximum allowed setpoint jerk */
    double posServoOverVoltageLimit;    /**< maximum allowed positive servo voltage [V] */
    double posServoUnderVoltageLimit;   /**< minimum allowed positive servo voltage [V] */
    double negServoUnderVoltageLimit;   /**< minimum allowed negative servo voltage [V] */
    double negServoOverVoltageLimit;    /**< maximum allowed negative servo voltage [V] */
    double maxCurrent;                  /**< maximum allowed value for measured current */
    double driveMaxI2t;                 /**< maximum allowed value for drive I2t level */
    double motorNominalCurrent;         /**< nominal current of the motor (maximum continuous motor current) */
    double motorThermalTimeConstant;    /**< thermal time constant of the motor winding */
    double motorMaxOverloadFactor;      /**< maximum overload factor for the motor current */
    double maxAxisVelocity;             /**< maximum allowed axis velocity */
    BOOL   swSwitchPreCheckEnable;      /**< flag to enable sw end switches precheck */
    double sensorSupply;                /**< sensor supply voltage */

} SAC_ERROR_CHECK_PARS;


/**
 *  @ingroup sac_parameters
 */
typedef struct sac_controller_state_pars
{
    double posReadyWin;         /**< position window to verify settling */
    double velReadyWin;         /**< velocity window to verify settling */
    double timeInReadyWindows;  /**< time necessary to be within pos and vel window before settling */
    double settlingTimeout;     /**< time-out time */   
    double steadyStateDelay;    /**< delay between settling and reaching the READY state */    

} SAC_CONTROLLER_STATE_PARS;


/**
 *  @ingroup sac_parameters
 */
typedef enum sac_dither_type
{
    SAC_DITHER_BLOCK,   /**< block type dither */   
    SAC_DITHER_PHM      /**< pulse height modulation dither */
} SAC_DITHER_TYPE;

/**
 *  @ingroup sac_parameters
 */
typedef struct sac_controller_enhancement_pars
{
    double          ditherFrequency;       /**< dither frequency */
    double          ditherHigh;            /**< maximum positive dither level */
    double          ditherLow;             /**< minimum negative dither level */
    double          ditherDutyCycle;       /**< % high level time within dither period */
    SAC_DITHER_TYPE ditherType;

    BOOL   scmEnable;                      /**< enable SCM */
    double scmResetPos;                    /**< positive limit of range to switch off control */
    double scmResetNeg;                    /**< negative limit of range to switch off control */
    double scmRestartIntPos;               /**< positive limit of range to switch on control */
    double scmRestartIntNeg;               /**< negative limit of range to switch on control */

    double ifcDeadZoneGain;                /**< multiply controller output with this gain when within deadzone */
    double ifcDeadZoneOutputPos;           /**< upper limit of deadzone */
    double ifcDeadZoneOutputNeg;           /**< lower limit of deadzone */

    double pGainAtStandStill;              /**< proportional gain at 0 velocity */
    double pHalfWayVel;                    /**< velocity where actual kp = kp + 0.5 * (pGainAtStandstill - kp) */

    double iGainAtStandStill;              /**< integral gain at 0 velocity */
    double iHalfWayVel;                    /**< velocity where actual ki = ki + 0.5 * (iGainAtStandstill - ki) */

    double dGainAtStandStill;              /**< derivative gain at 0 velocity */
    double dHalfWayVel;                    /**< velocity where actual kv = kv + 0.5 * (dGainAtStandstill - kv) */

    BOOL   cleggEnable;                    /**< reset integral action when error passes 0 level */

    double maxIntegratorLevelAtStandStill; /**< max integrator level at 0 velocity */
    double maxIntegratorLevelHalfWayVel;   /**< velocity where actual max integrator level = max integrator level + 0.5 * */
                                           /**<                                              (maxIntegratorLevelAtStandStill - max integrator level) */

} SAC_CONTROLLER_ENHANCEMENT_PARS;

/**
 *  @ingroup sac_parameters
 */
typedef enum sac_dmf_input
{
    SAC_DMF_INPUT_NONE = 0,             /**< no addition; default */
    SAC_DMF_INPUT_POSITION,             /**< add U1 */
    SAC_DMF_INPUT_CONTROLLER            /**< add U2 */
} SAC_DMF_INPUT;


/**
 *  @ingroup sac_parameters
 */
typedef enum sac_dmf_output
{
    SAC_DMF_OUTPUT_NONE = 0,            /**< no DAC update; default */
    SAC_DMF_OUTPUT_CONTROLLER,          /**< output controller, at PVL */
    SAC_DMF_OUTPUT_CONTR_PLUS_TEST,     /**< output controller + test signal, at PVL */
    SAC_DMF_OUTPUT_POSITION,            /**< output position, at PVL */
    SAC_DMF_OUTPUT_POSITION_ERROR,      /**< output position error, at PVL */
    SAC_DMF_OUTPUT_SPG_POSITION,        /**< output setpoint position, at PVL */

    SAC_DMF_OUTPUT_IA,                  /**< output motor current Ia, at CCL */
    SAC_DMF_OUTPUT_IB,                  /**< output motor current Ib, at CCL */
    SAC_DMF_OUTPUT_ID,                  /**< output transformed motor current Id, at CCL */
    SAC_DMF_OUTPUT_IQ,                  /**< output transformed motor current Iq, at CCL */
    SAC_DMF_OUTPUT_ID_ERROR,            /**< output current error Id, at CCL */
    SAC_DMF_OUTPUT_IQ_ERROR,            /**< output current error Iq, at CCL */
    SAC_DMF_OUTPUT_ID_LOOP_INTEGRATOR,  /**< output integrator Id, at CCL */
    SAC_DMF_OUTPUT_IQ_LOOP_INTEGRATOR,  /**< output integrator Iq, at CCL */
    SAC_DMF_OUTPUT_UA,                  /**< output motor voltage Ua, at CCL */
    SAC_DMF_OUTPUT_UB,                  /**< output motor voltage Ua, at CCL */
    SAC_DMF_OUTPUT_UD,                  /**< output transformed motor voltage Ua, at CCL */
    SAC_DMF_OUTPUT_UQ,                  /**< output transformed motor voltage Ua, at CCL */
    SAC_DMF_OUTPUT_ANGLE                /**< output commutation angle, at CCL */
} SAC_DMF_OUTPUT;

/**
 *  @ingroup sac_parameters
 */
typedef struct sac_controller_dmf_pars 
{
    SAC_DMF_INPUT       dmfInput;               /**< input selection for the frequency response function */
    SAC_DMF_OUTPUT      dmfOutput;              /**< output selection for the drive monitor function */
    double              voltToInput;            /**< ADC input scaling when using the drive monitor function */
    double              outputToVolt;           /**< DAC output scaling when using the drive monitor function */

} SAC_CONTROLLER_DMF_PARS;


/**
 *  @ingroup sac_parameters
 */
typedef struct sac_anti_alias_filter_pars
{
    BOOL                 aafEnable;     /**< enable anti-aliasing filter */

} SAC_ANTI_ALIAS_FILTER_PARS;

/**
 *  @ingroup sac_parameters
 *  Parameter set ID's.
 */
typedef enum sac_param_set_id
{
    SAC_FIRST_PARAM_SET_ID,             /**< @_invalidEnumValue */
    SAC_CONTROLLER_PID_PARS_ID,
    SAC_CONTROLLER_FILTER_PARS_ID,
    SAC_CONTROLLER_DMF_PARS_ID,
    SAC_CONTROLLER_STATE_PARS_ID,
    SAC_CONTROLLER_TYPE_PARS_ID,
    SAC_CONTROLLER_ENHANCEMENT_PARS_ID,
    SAC_ERROR_CHECK_PARS_ID,
    SAC_HOME_PARS_ID,
    SAC_ALIGN_MOTOR_PARS_ID,
    SAC_CURRENT_CONTROL_PARS_ID,
    SAC_PWM_PARS_ID,
    SAC_QUICKSTOP_PARS_ID,
    SAC_SMOOTHSTOP_PARS_ID,
    SAC_LAST_PARAM_SET_ID               /**< @_nrOfEnumValues */
} SAC_PARAM_SET_ID;



/**
 *  @ingroup sac_error_and_service_handling
 */
typedef enum sac_error_handler
{
    SAC_ERRH_NONE,                /**< Severity 0: No error handling */
    SAC_ERRH_WARNING,             /**< Severity 1: Generate a warning */
    SAC_ERRH_SMOOTH_STOP,         /**< Severity 2: Perform smooth stop */
    SAC_ERRH_QUICK_STOP,          /**< Severity 3: Perform quick stop */
    SAC_ERRH_FULL_STOP,           /**< Severity 4: Perform full stop */
    SAC_ERRH_QSTOP_OPEN_LOOP,     /**< Severity 5: Perform quick stop, open loop */
    SAC_ERRH_OPEN_LOOP,           /**< Severity 6: Perform open loop */
    SAC_ERRH_DISABLE_DRIVE,       /**< Severity 7: Perform open loop, disable drive */
    SAC_ERRH_POS_CORRUPTED,       /**< Severity 8: Perform open loop, disable drive, position lost */
    SAC_ERRH_COMMUNICATION_LOST   /**< Severity 9: Perform open loop, disable drive, position lost, recovery shutdown */
} SAC_ERROR_HANDLER;


/**
 *  @ingroup sac_error_and_service_handling
 *  @brief   Structure to configure the service parameters.
 */
typedef struct sac_service_mode_operation_pars
{
    double            maxSpgVelocity;                   /**< velocity constraint in service mode [pu/sec] */
    double            maxSpgAcceleration;               /**< acceleration constraint in service mode [pu/sec2] */
    double            maxSpgJerk;                       /**< jerk constraint in service mode [pu/sec3] */
    double            saturationLevel;                  /**< Maximum positive controller output constraint in service mode. Value 0.0 disables this constraint. [cout] */
    double            saturationMinLevel;               /**< Maximum negative controller output constraint in service mode (Only used when parameter(SAC_PAR_ASYMMETRIC_SATURATION) = TRUE). Value 0.0 disables this constraint. [cout] */

    SAC_ERROR_HANDLER serviceInputErrorHandler;         /**< defines the error handler to be activated when the service input is activated in normal mode */
    SAC_ERROR_HANDLER serviceVelocityErrorHandler;      /**< defines the error handler to be activated when the service constraint on velocity is violated in service mode */
    SAC_ERROR_HANDLER serviceAccelerationErrorHandler;  /**< defines the error handler to be activated when the service constraint on acceleration is violated in service mode */
    SAC_ERROR_HANDLER serviceJerkErrorHandler;          /**< defines the error handler to be activated when the service constraint on jerk is violated in service mode */

} SAC_SERVICE_MODE_OPERATION_PARS;


/**
 *  @ingroup sac_events_and_actions
 */
typedef enum sac_event_action
{
    SAC_AC_NO_ACTION,       /**< Do nothing */
    SAC_AC_FULL_STOP,       /**< Stop movement using 'Full stop' profile */
    SAC_AC_QUICK_STOP,      /**< Stop movement using 'Quick stop' profile */
    SAC_AC_SMOOTH_STOP      /**< Stop movement using 'Smooth stop' profile */
} SAC_EVENT_ACTION;


/**
 *  @ingroup sac_events_and_actions
 */
typedef enum sac_sync_request
{
    SAC_REQ_INITIALIZE,         /**< initialize ready */
    SAC_REQ_ENABLE_POWER,       /**< enable power ready */
    SAC_REQ_ALIGN_MOTOR,        /**< align motor ready */   
    SAC_REQ_LOCK,               /**< lock ready */
    SAC_REQ_MOTION_STARTED,     /**< motion started */
    SAC_REQ_MOTION_STOPPED,     /**< motion stopped */
    SAC_REQ_HOMING_COMPLETED,   /**< homing procedure completed */
    SAC_REQ_OPEN_LOOP,          /**< FREE state reached */
    SAC_REQ_ENABLE_MOTION,      /**< enable motion state reached */
    SAC_REQ_RESET,              /**< reset ready */
    SAC_REQ_SHUTDOWN,           /**< shutdown ready */
    SAC_REQ_AXIS_SETTLED,       /**< settling ready */
    SAC_REQ_AXIS_STEADY,        /**< steady state reached */
    SAC_REQ_MOVE_CURRENT_ANGLE  /**< move current angle ready */
} SAC_SYNC_REQUEST;

/**
 *  @ingroup sac_markers
 */
typedef enum sac_marker_direction
{
    SAC_MARKER_NEGATIVE = -1,   /**< detect marker when passed in negative direction */
    SAC_MARKER_ANY_DIR  = 0,    /**< detect marker when passed in any direction */
    SAC_MARKER_POSITIVE = 1     /**< detect marker when passed in positive direction */
} SAC_MARKER_DIRECTION;

/**
 *  @ingroup sac_markers
 */
typedef struct sac_marker
{
    uint32_t                id;         /**< marker Id */
    double                  position;   /**< marker position */
    SAC_MARKER_DIRECTION    direction;  /**< marker direction */
    NYCE_DIGOUT_ACTION      action;     /**< set, reset, toggle or no action of output when marker detected */
    NYCE_DIGITAL_IO_ID      outputId;   /**< slotId and IONr of output */
    BOOL                    eventFlag;  /**< indicating whether or not an event has to be transmitted when marker detected */

} SAC_MARKER;

/**
 *  @ingroup sac_markers
 */
typedef struct sac_s0s90_marker_statistics
{
    uint32_t nrOfMissedMarkers;  /**< nr of detected S0S90 missed markers */

} SAC_S0S90_MARKER_STATISTICS;

/**
 *  @ingroup sac_markers
 */
typedef struct sac_time_marker
{
    uint32_t            id;         /**< marker Id */
    double              time;       /**< time in seconds before end of movement */
    NYCE_DIGOUT_ACTION  action;     /**< set, reset, toggle or no action of output when marker detected */
    NYCE_DIGITAL_IO_ID  outputId;   /**< slotId and IONr of output */
    BOOL                eventFlag;  /**< indicating whether or not an event has to be transmitted when marker detected */

} SAC_TIME_MARKER;

/**
 *  @ingroup sac_monitor
 */
typedef struct sac_monitor_pars
{
    SAC_VAR_ID           varId;      /**< Variable which has to be monitored */
    double               scaling;    /**< Scaling used on the value of variable before
                                        it is sent to the monitor */
    double               offset;     /**< Offset used for variable before it is sent to
                                        the monitor */

} SAC_MONITOR_PARS;

/**
 *  @ingroup sac_monitor
 */
typedef struct sac_monitor
{
    NYCE_ANALOG_OUT_ID  anOutId;     /**< Slot id and analog id of the output */
    SAC_MONITOR_PARS    monitorPars; /**< Set of monitor parameters */

} SAC_MONITOR;

/**
 *  @ingroup sac_autotweak
 */
typedef enum sac_tweak_mode
{
    SAC_TWEAK_DISABLED = 0,
    SAC_TWEAK_CLOSED_LOOP_STATES_ONLY,
    SAC_TWEAK_CLOSED_LOOP_STATES_AND_FREE_STATE,
    SAC_TWEAK_ALL_POWER_ENABLED_STATES
} SAC_TWEAK_MODE;

/**
 *  @ingroup sac_autotweak
 */
typedef enum sac_tweak_position_source
{
    SAC_TWEAK_AXIS_POSITION,     /**< use axis position */
    SAC_TWEAK_SETPOINT_POSITION  /**< use setpoint position */
} SAC_TWEAK_POSITION_SOURCE;

/**
 *  @ingroup sac_autotweak
 */
typedef enum sac_pos_update_mode
{
    SAC_POS_UPDATE_LINEAR = 0,          /**< Position update mode = linear */
    SAC_POS_UPDATE_MODULO               /**< Position update mode = modulo */
} SAC_POS_UPDATE_MODE;

/**
 *  @ingroup sac_parameters
 */
typedef enum sac_position_unit_type
{
    SAC_POSITION_UNIT,                  /**< unit */
    SAC_POSITION_MICROMETER,            /**< micrometer */
    SAC_POSITION_MILLIMETER,            /**< millimeter */
    SAC_POSITION_METER,                 /**< meter */
    SAC_POSITION_INCH,                  /**< inch */
    SAC_POSITION_DEGREE,                /**< degree */
    SAC_POSITION_RADIAN,                /**< radian */
    SAC_POSITION_REVOLUTION             /**< revolution */
} SAC_POSITION_UNIT_TYPE;


/**
 *  @ingroup sac_autotweak
 */
typedef struct sac_tweak_table
{
    SAC_POS_UPDATE_MODE     updateMode;                                    /**< Position update mode */
    double                  startPosition;                                 /**< Start position [pu] */
    double                  stepSize;                                      /**< Distance between successive tweak positions [pu] */
    int32_t                 tableSize;                                     /**< Total number of feedforward values */
    double                  feedforward[NYCE_MAX_NR_OF_TWEAK_POSITIONS ];  /**< Feedforward values */

} SAC_TWEAK_TABLE;


/**
 *  @ingroup sac_sensor_linearization
 */
typedef int32_t SAC_LIN_LUT_POINT;                                     /**< Sensor Linearization point (linearized) */


/**
 *  @ingroup sac_sensor_linearization
 */
typedef struct sac_lin_lut_table
{
    int32_t             startPosition;                              /**< Start position [inc] */
    int32_t             stepSize;                                   /**< Distance between linearized positions [inc] */
    int32_t             tableSize;                                  /**< Total number of linearized points */
    SAC_LIN_LUT_POINT   point[NYCE_MAX_LIN_LUT_POINTS_PER_AXIS];    /**< linearized points */

} SAC_LIN_LUT_TABLE;

/**
 *  @ingroup sac_commutation_correction
 */
typedef struct sac_commutation_correction_pars
{
    char            correctiveAxisName[ NYCE_MAX_NAME_LENGTH ]; /**< commutation correction corrective axis name */
    SAC_DIRECTION   correctionDir;                              /**< commutation correction direction */
    double          correctionRatio;                            /**< commutation correction ratio */

} SAC_COMMUTATION_CORRECTION_PARS;


/**
 *  @ingroup sac_position_force_control
 */
typedef struct sac_pfc_sensor_config
{
    NYCE_ANALOG_IN_ID forceSensor;        /**< analog input used as force sensor */
    SAC_DIRECTION     sensorDirection;    /**< positive or negative relation between force and sensor output */
    uint32_t          nrOfMeasurements;   /**< number of force sensor measurements used for averaging */ 
    double            nrOfNewtonsPerVolt; /**< scaling factor that defines how many Newtons correspond with 1 Volt */ 

} SAC_PFC_SENSOR_CONFIG;

/**
 *  @ingroup sac_position_force_control
 */
typedef struct sac_pfc_force_segment
{
    uint32_t      segmentNr;              /**< force segment number */
    double        endForce;               /**< end force [N], reached at the end of the ramp time */
    double        rampTime;               /**< ramp time [s] */
    double        plateauTime;            /**< plateau time [s] */
    double        positionRange;          /**< position range [pu] relative to the actual position at start of force segment */
    BOOL          forceControl;           /**< flag indicating whether force or position is controlled */
    BOOL          generateEvent;          /**< flag indicating whether event is generated at start of force segment or not */

} SAC_PFC_FORCE_SEGMENT;


/**
 *  @}
 */

#ifdef NT
#pragma pack(pop)
#endif

#endif // __SACTYPES_H__
