/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2014
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: rocks
 *
 *  %full_filespec: rockstypes.h`14:incl:1 %
 */
/**
 *  @file
 *  @brief  Header file containing type declarations for NYCeRocks.
 */

#ifndef __ROCKSTYPES_H__
#define __ROCKSTYPES_H__


#ifdef NT
#include <windows.h>
#include "seqapi.h"
#endif

#include "sacapi.h"

/**
 * @defgroup rocks NYCeRocks (ROCKS)
 *
 * Robot Control and Kinematics Software is a layer on top of SAC and NHI for trajectory generation and
 * kinematic transformations.
 *
 * @{
 */


/**
 * @defgroup rocks_mechanism Mechanism
 *
 */

/**
 * @defgroup rocks_trajectory_sinacc Trajectory SinAcc
 *
 */

/**
 * @defgroup rocks_trajectory_cubic Trajectory Cubic
 *
 */

/**
 * @defgroup rocks_trajectory_segments Trajectory Segments
 *
 */

/**
 * @defgroup rocks_trajectory_misc Trajectory Miscellaneous
 *
 */

/**
 * @defgroup rocks_kinematics Kinematics Generic
 *
 */

/**
 * @defgroup rocks_kinematics_cartesian Kinematics Cartesian
 *
 */

/**
 * @defgroup rocks_kinematics_gantry Kinematics Gantry
 *
 */

/**
 * @defgroup rocks_streamer Streamer
 *
 */

/**
 * @defgroup rocks_miscellaneous Miscellaneous
 *
 */

/**
 *  @defgroup rocks_conversion Conversion
 *
 *  The functions within this module convert strings to enumeration values and vice versa.
 */


#define ROCKS_MECH_MAX_DOF              6
#define ROCKS_MECH_MAX_NR_OF_JOINTS     10


/**
 *  @brief  Selection of a plane: XY, YZ or ZX.
 */
typedef enum rocks_plane
{
    ROCKS_PLANE_XY = 0,       /**< XY plane */
    ROCKS_PLANE_YZ,           /**< YZ plane */
    ROCKS_PLANE_ZX            /**< ZX plane */
} ROCKS_PLANE;

/**
 *  @brief  Selection of the gantry direction. Either two axes in the X direction or two axes in the Y direction.
 */
typedef enum rocks_gantry_direction
{
    ROCKS_GANTRY_X = 0,       /**< Two gantry axes in the X direction (default) */
    ROCKS_GANTRY_Y            /**< Two gantry axes in the Y direction */
}ROCKS_GANTRY_DIRECTION;

/**
 *  @brief  Movement type coupled to the trajectory type.
 */
typedef enum rocks_move_type
{
    ROCKS_MOVE_TYPE_LINEAR = 0, /**< Linear movement coupled to the PTP and SEGMENTS trajectory types */
    ROCKS_MOVE_TYPE_CIRCULAR,   /**< Circular movement coupled to the CIRCLE and SEGMENTS trajectory types */
    ROCKS_MOVE_TYPE_MIX         /**< Movement with PTP and CIRCLE trajectory types (SEGMENTS) */ 
} ROCKS_MOVE_TYPE;

/**
 *  @brief  Selection of the trajectory type.
 */
typedef enum rocks_traj_type
{
    ROCKS_TRAJ_TYPE_NONE = -1,          /**< No trajectory */
    ROCKS_TRAJ_TYPE_SINE_ACC_PTP = 0,   /**< Linear trajectory type with a sinusoidal shaped acceleration profile */
    ROCKS_TRAJ_TYPE_SINE_ACC_CIRCLE,    /**< Circular trajectory type with a sinusoidal shaped acceleration profile */
    ROCKS_TRAJ_TYPE_CUBIC_PTP,          /**< Linear trajectory type with a cubic profile */
    ROCKS_TRAJ_TYPE_CUBIC_CIRCLE,       /**< Circular trajectory type with a cubic profile */
    ROCKS_TRAJ_TYPE_SEGMENTS            /**< Segments trajectory type */
} ROCKS_TRAJ_TYPE;

/**
 *  @brief  Selection of start or stop simultaneous when the function RocksTrajCubicSeparateJointSpeed is used.
 */
typedef enum rocks_traj_cubic_joint_behavior
{
    ROCKS_START_STOP_SIMULTANEOUS = 0,      /**< All joints start and stop simultaneously (default) */
    ROCKS_START_SIMULTANEOUS,               /**< All joints start simultaneously */
    ROCKS_STOP_SIMULTANEOUS                 /**< All joints stop simultaneously */
} ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR;

/**
 *  @brief  Step on the internal NYCeRocks layered model.
 */
typedef enum rocks_mech_step
{
    ROCKS_MECH_STEP_INITIAL = 0,            /**< Initial step when the mechanism is created */
    ROCKS_MECH_STEP_VALID_PATH,             /**< Trajectory generation successfully completed */
    ROCKS_MECH_STEP_VALID_INV_KINEMATICS    /**< Joint splines successfully generated; possible to stream */
} ROCKS_MECH_STEP;


/**
 *  @brief  3-dimensional vector.
 */
typedef struct rocks_e3_vector
{
    double  x;            /**< 1st coordinate */
    double  y;            /**< 2nd coordinate */
    double  z;            /**< 3rd coordinate */
} ROCKS_E3_VECTOR;


/**
 *  @brief  A pose consists of a 3-dimensional translation vector and a 3-dimensional rotation vector.
 */
typedef struct rocks_pose
{
    ROCKS_E3_VECTOR t;    /**< 3 translation coordinates */
    ROCKS_E3_VECTOR r;    /**< 3 rotation coordinates */
} ROCKS_POSE;


/**
 *  @brief  Parameters of a line trajectory with a sinusoidal shaped acceleration profile.
 */
typedef struct rocks_traj_sine_acc_ptp_pars
{
    double      startPos[ROCKS_MECH_MAX_DOF];   /**< Start position in World Coordinates */
    double      endPos[ROCKS_MECH_MAX_DOF];     /**< End position in World Coordinates */
    double      maxVelocity;                    /**< Path velocity constraint */
    double      maxAcceleration;                /**< Path acceleration constraint */
    double      splineTime;                     /**< Spline time */
    uint32_t    maxNrOfSplines;                 /**< Use 0, or if you want own buffers: number of elements in the user supplied buffers */
    double*     pPositionSplineBuffer;          /**< Use NULL, or if you want own buffers: buffer to store path position segments */
    double*     pVelocitySplineBuffer;          /**< Use NULL, or if you want own buffers: buffer to store path velocity segments */
} ROCKS_TRAJ_SINE_ACC_PTP_PARS;


/**
 *  @brief  Parameters of a circle trajectory with a sinusoidal shaped acceleration profile.
 */
typedef struct rocks_traj_sine_acc_circle_pars
{
    double      startPos[ROCKS_MECH_MAX_DOF];   /**< Start position in World Coordinates */
    double      center[2];                      /**< Center of circular move */
    double      angle;                          /**< CCW angle of circular move */
    ROCKS_PLANE plane;                          /**< Plane of the circular move */
    double      maxVelocity;                    /**< Path velocity constraint */
    double      maxAcceleration;                /**< Path acceleration constraint */
    double      splineTime;                     /**< Spline time */
    uint32_t    maxNrOfSplines;                 /**< Use 0, or if you want own buffers: number of elements in the user supplied buffers */
    double*     pPositionSplineBuffer;          /**< Use NULL, or if you want own buffers: buffer to store path position segments */
    double*     pVelocitySplineBuffer;          /**< Use NULL, or if you want own buffers: buffer to store path velocity segments */
} ROCKS_TRAJ_SINE_ACC_CIRCLE_PARS;


/**
 *  @brief  Parameters of a line trajectory with a cubic profile.
 */
typedef struct rocks_traj_cubic_ptp_pars
{
    double      startPos[ROCKS_MECH_MAX_DOF];   /**< Start position in World Coordinates */
    double      endPos[ROCKS_MECH_MAX_DOF];     /**< End position in World Coordinates */
    double      maxVelocity;                    /**< Path velocity constraint */
    double      maxAcceleration;                /**< Path acceleration constraint */
    double      maxJerk;                        /**< Path jerk constraint */
    uint32_t    maxNrOfSplines;                 /**< Use 0, or if you want own buffers: number of elements in the user supplied buffers */
    double*     pPositionSplineBuffer;          /**< Use NULL, or if you want own buffers: buffer to store path position segments */
    double*     pVelocitySplineBuffer;          /**< Use NULL, or if you want own buffers: buffer to store path velocity segments */
    double*     pTimeSplineBuffer;              /**< Use NULL, or if you want own buffers: buffer to store duration segments */
} ROCKS_TRAJ_CUBIC_PTP_PARS;


/**
 *  @brief  Parameters of a circle trajectory with a cubic profile.
 */
typedef struct rocks_traj_cubic_circle_pars
{
    double      startPos[ROCKS_MECH_MAX_DOF];   /**< Start position in World Coordinates */
    double      center[2];                      /**< Center of circular move */
    double      angle;                          /**< CCW angle of circular move */
    ROCKS_PLANE plane;                          /**< Plane of the circular move */
    double      maxVelocity;                    /**< Path velocity constraint */
    double      maxAcceleration;                /**< Path acceleration constraint */
    double      maxJerk;                        /**< Path jerk constraint */
    uint32_t    maxNrOfSplines;                 /**< Use 0, or if you want own buffers: number of elements in the user supplied buffers */
    double*     pPositionSplineBuffer;          /**< Use NULL, or if you want own buffers: buffer to store path position segments */
    double*     pVelocitySplineBuffer;          /**< Use NULL, or if you want own buffers: buffer to store path velocity segments */
    double*     pTimeSplineBuffer;              /**< Use NULL, or if you want own buffers: buffer to store duration segments */
} ROCKS_TRAJ_CUBIC_CIRCLE_PARS;


/**
 *  @brief  Start parameters of a segment profile.
 */
typedef struct rocks_traj_segment_start_pars
{
    double      splineTime;                     /**< Spline time */
    uint32_t    maxNrOfSplines;                 /**< Use 0, or if you want own buffers: number of elements in the user supplied buffers */
    double*     pPositionSplineBuffer;          /**< Use NULL, or if you want own buffers: buffer to store path position segments */
    double*     pVelocitySplineBuffer;          /**< Use NULL, or if you want own buffers: buffer to store path velocity segments */
    double      startPos[ROCKS_MECH_MAX_DOF];   /**< Start position in World Coordinates */
} ROCKS_TRAJ_SEGMENT_START_PARS;


/**
 *  @brief  Line definition of a segment profile.
 */
typedef struct rocks_traj_segment_line_pars
{
    double      endPos[2];                      /**< End position in World Coordinates (XY XZ or YZ) */
    double      endVelocity;                    /**< End velocity */
    double      maxAcceleration;                /**< Path acceleration constraint */
    ROCKS_PLANE plane;                          /**< Plane of the segment */
    ROCKS_POSE  originOffset;                   /**< Reference frame rotation offsets to be added before the line */
} ROCKS_TRAJ_SEGMENT_LINE_PARS;


/**
 *  @brief  Arc definition of a segment profile.
 */
typedef struct rocks_traj_segment_arc_pars
{
    double      endPos[2];                      /**< End position in 2 world coordinates (XY XZ or YZ) */
    double      center[2];                      /**< Center of the arc (XY XZ or YZ) */
    BOOL        positiveAngle;                  /**< Direction: TRUE=positive (CCW), FALSE=negative (CW) */
    double      endVelocity;                    /**< End velocity */
    double      maxAcceleration;                /**< Path acceleration constraint */
    ROCKS_PLANE plane;                          /**< Plane of the segment */
    ROCKS_POSE  originOffset;                   /**< Reference frame rotation offsets to be added before the arc */
} ROCKS_TRAJ_SEGMENT_ARC_PARS;


/**
 *  @brief  Definition of a joint behavior and constraints when the function RocksTrajCubicSeparateJointSpeed is used.
 */
typedef struct rocks_traj_cubic_joint_info
{
    double     velocity;       /**< Max velocity (only used if jointBehavior not equal to ROCKS_START_STOP_SIMULTANEOUS) */
    double     acceleration;   /**< Max acceleration (only used if jointBehavior not equal to ROCKS_START_STOP_SIMULTANEOUS) */
    double     jerk;           /**< Max jerk or SAC_INDEFINITE for second order (only used if jointBehavior not equal to ROCKS_START_STOP_SIMULTANEOUS) */
    double     baseVelocity;   /**< Base velocity for steppers (only used if jointBehavior not equal to ROCKS_START_STOP_SIMULTANEOUS) */
    ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR jointBehavior;  /**< Default is ROCKS_START_STOP_SIMULTANEOUS */
} ROCKS_TRAJ_CUBIC_JOINT_INFO;


/**
 *  @brief  Parameters of the possible trajectory path types.
 */
typedef union rocks_traj_path_pars
{
    ROCKS_TRAJ_SINE_ACC_PTP_PARS    sineAccPtpPars;     /**< Parameters of a line trajectory with a sinusoidal shaped acceleration profile */
    ROCKS_TRAJ_SINE_ACC_CIRCLE_PARS sineAccCirclePars;  /**< Parameters of a circle trajectory with a sinusoidal shaped acceleration profile */
    ROCKS_TRAJ_CUBIC_PTP_PARS       cubicPtpPars;       /**< Parameters of a line trajectory with a cubic profile */
    ROCKS_TRAJ_CUBIC_CIRCLE_PARS    cubicCirclePars;    /**< Parameters of a circle trajectory with a cubic profile */
    ROCKS_TRAJ_SEGMENT_START_PARS   segmentPars;        /**< Start parameters of a segment profile */
} ROCKS_TRAJ_PATH_PARS;


/**
 *  @brief  Type and parameters of the trajectory path used in the functions RocksTrajGetPath, RocksTrajLoadPath and RocksTrajDeletePath.
 */
typedef struct rocks_traj_path
{
    ROCKS_TRAJ_TYPE      type;  /**< Trajectory type */
    ROCKS_TRAJ_PATH_PARS pars;  /**< Parameters of the possible trajectory path types */
} ROCKS_TRAJ_PATH;


/**
 *  @brief  Definition of buffers for joint splines after inverse kinematic transformation.
 */
typedef struct rocks_kin_inv_pars
{
    double*     pJointPositionBuffer[ROCKS_MECH_MAX_NR_OF_JOINTS];    /**< Use NULL, or if you want own buffers: buffers to store joint position segments */
    double*     pJointVelocityBuffer[ROCKS_MECH_MAX_NR_OF_JOINTS];    /**< Use NULL, or if you want own buffers: buffers to store joint velocity segments */
} ROCKS_KIN_INV_PARS;


// Forward declaration of the rocks_mech struct type.
struct rocks_mech;

/**
 *  @brief  Function type for a function, which applies the inverse kinematics on the current loaded trajectory.
 *  @ingroup rocks_kinematics 
 *
 *  @param[in]  pMech       Pointer to the mechanism.
 *  @param[in]  pKin        If not NULL, this points to a ROCKS_KIN_INV_PARS structure, which defines 
 *                          output buffers for the generated joint splines.
 *                          If pKinPars is NULL, the mechanism will handle spline buffers allocation.
 */
typedef NYCE_STATUS (*ROCKS_APPLY_INVERSE_KIN_FUNC)(struct rocks_mech* pMech, const ROCKS_KIN_INV_PARS* pKin);

/**
 *  @brief  Function type for a function, which applies the forward kinematics on joint positions.
 *  @ingroup rocks_kinematics 
 *
 *  @param[in]  pMech       Pointer to the mechanism.
 *  @param[in]  pJointPos   size(pMech->numJoints); The joint positions.
 *  @param[out] pMechPos    size(ROCKS_MECH_MAX_DOF); The returned world coordinates.
 */
typedef NYCE_STATUS (*ROCKS_APPLY_FORWARD_KIN_FUNC)(struct rocks_mech* pMech, const double pJointPos[], double pMechPos[]);

/**
 *  @brief  Function type for a function, which returns the current mechanism's setpoint position in world coordinates.
 *  @ingroup rocks_kinematics 
 *
 *  @param[in]  pMech       Pointer to the mechanism.
 *  @param[out] pPos        size(ROCKS_MECH_MAX_DOF); The returned position in world coordinates.
 */
typedef NYCE_STATUS (*ROCKS_GET_WORLD_SETPOINT_POS_FUNC)(struct rocks_mech* pMech, double pPos[]);

/**
 *  @brief  Function type for a user defined conversion of a position and velocity of a point on the path.
 *
 *  The user defined function gets the position and velocity of each point on the path, after the reference 
 *  frame correction. The user defined function can modify this position and velocity. This function can be 
 *  used for 2d-compensation or for compensation on more than 2 dimensions.
 *
 *  @param[in]  pPos        Position pose.
 *  @param[in]  pVel        Velocity pose.
 */
typedef void (*ROCKS_KIN_CONVERSION)(ROCKS_POSE* pPos, ROCKS_POSE* pVel);

typedef struct rocks_mech_var
{
    ROCKS_TRAJ_TYPE trajType;                   // current trajectory type
    double*     pPositionSplineBuffer;          // Pointer to buffer to store path position segments
    double*     pVelocitySplineBuffer;          // Pointer to buffer to store path velocity segments
    double*     pTimeSplineBuffer;              // Pointer to buffer to store duration segments

    double*     pJointPositionBufferC[ROCKS_MECH_MAX_NR_OF_JOINTS]; // array of pointers to buffers to store joint position segments
    double*     pJointVelocityBufferC[ROCKS_MECH_MAX_NR_OF_JOINTS]; // array of pointers to buffers to store joint velocity segments

    double      splineTime;                     // spline time
    double      startPos[ROCKS_MECH_MAX_DOF];   // Start position in World Coordinates
    double      endPos[ROCKS_MECH_MAX_DOF];     // End position in World Coordinates
    ROCKS_MOVE_TYPE   moveType;                 // ROCKS_MOVE_TYPE_LINEAR or ROCKS_MOVE_TYPE_CIRCULAR 
    ROCKS_PLANE plane;                          // plane of the circular move
    double      center[2];                      // center of circular move
    double      radius;                         // radius of the circular move
    double      angle;                          // CCW angle of circular move
    uint32_t    usedNrOfSplines;                // number of used splines

    ROCKS_POSE  refFramePose1;                  // translation & rotation of reference frame
    ROCKS_POSE  refFramePose2;                  // translation & rotation of reference frame

    ROCKS_KIN_CONVERSION pForwardCompensation;  // additional forward conversion function;
    ROCKS_KIN_CONVERSION pInverseCompensation;  // additional inverse conversion function;

    struct rocks_mech* pNextInMechGroup;
    uint32_t    mechGroupId;
    uint32_t    streamGroupId;                  // MAC group id
    uint32_t    streamErrGroupId;               // Error Group id
    BOOL        eventHandlerDefined;            // 
    BOOL        eventHandlerEnabled;
    uint32_t    nrOfSplinesSend;                //
    uint32_t    waterMark;                      // used when refilling splines by the streamer

    BOOL        jointInfoEnable;
    ROCKS_TRAJ_CUBIC_JOINT_INFO   jointInfo[ROCKS_MECH_MAX_NR_OF_JOINTS];      // joint info used by cubic trajectories only
    double      jointInfoStartPos[ROCKS_MECH_MAX_NR_OF_JOINTS];
    double      jointInfoSplineTime[ROCKS_MECH_MAX_NR_OF_JOINTS][8];
    BOOL        jointInfoUsed[ROCKS_MECH_MAX_NR_OF_JOINTS];

    uint32_t    maxNrOfSplines;             // Number of elements in the user supplied buffers for segments
    double      lastSegmentEndVel;
    double      lastSplineTime;
    double      lastSegmentEndPos[ROCKS_MECH_MAX_DOF];
    BOOL        pathBuffersAllocated;       // On the host the buffers pPositionSplineBuffer, pVelocitySplineBuffer
    BOOL        jointBuffersAllocated;      // pTimeSplineBuffer and the joint buffers pJointPositionBufferC[], and
                                            // pJointVelocityBufferC[] can be allocated dynamically

    BOOL        checkBeforeStreaming;       // Streamer checks ready status, homing status and start position (default = TRUE) 
    ROCKS_MECH_STEP   mechStep;
    ROCKS_GANTRY_DIRECTION gantryDirection;

#ifdef NT
    SEQ_NODE    seqNodeId;
    HANDLE      seqEvent;
#else
    uint32_t    clientArea;
#endif // NT
    uint32_t    rocksArea;                  // SQC_HOST_NODE or area number of the Rocks sequence
    uint32_t    addrOfRocksInterface;       //
    uint32_t    tag;
    uint32_t    mechNumber;
    double*     pBuffers;                   // pointer to all buffers (only for sequence implementation)
    uint32_t    bufferSize;                 // size of all buffers (only for sequence implementation)
    uint32_t    pvtSize;                    // size per P, V or T buffer (only for sequence implementation)

    ROCKS_APPLY_INVERSE_KIN_FUNC        pApplyInverseKinFunc;  
    ROCKS_APPLY_FORWARD_KIN_FUNC        pApplyForwardKinFunc;  
    ROCKS_GET_WORLD_SETPOINT_POS_FUNC   pGetWorldSetpointPosFunc; 

} ROCKS_MECH_VAR;

/**
 *  @brief  Mechanism definition.
 *
 *  This structure is used by most functions. The user calls the RocksMechCreate function with the 
 *  following fields filled in:
 *  dof            This is an array of 6 booleans. If a value is true, the degree of freedom is used.
 *                 The array elements represent the pose coordinates X, Y, Z, Rx, Ry, Rz respectively. 
 *                 The total degrees of freedom equals the sum of all elements which are set to TRUE.
 *  nrOfJoints     The number of joints in jointAxisId. 
 *                 For a Cartesian mechanism, this must be equal to the total degrees of freedom.
 *                 For a gantry mechanism, this must be equal to the total degrees of freedom + 1.
 *  jointAxisId    The axis ID's of the mechanism joints. 
 *                 The axes need to be connected before the mechanism is created. 
 *                 For a Cartesian mechanism, each joint represents the DOF which is used, i.e. the dof[]
 *                 element which is set to TRUE.
 *  var            Internal mechanism variables.
 */
typedef struct rocks_mech
{
    BOOL            dof[ROCKS_MECH_MAX_DOF];                    /**< Degrees Of Freedom */ 
    uint32_t        nrOfJoints;                                 /**< Number of joints */
    SAC_AXIS        jointAxisId[ROCKS_MECH_MAX_NR_OF_JOINTS];   /**< SAC axis identifiers of the joints */
    ROCKS_MECH_VAR  var;                                        /**< Variables */
} ROCKS_MECH;

/** @} */

#endif // __ROCKSTYPES_H__

