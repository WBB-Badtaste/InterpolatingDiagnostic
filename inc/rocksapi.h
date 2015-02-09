/*
 *  BOSCH REXROTH
 * 
 *  Copyright (c) Bosch Rexroth AG 2014
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: rocks
 *
 *  %full_filespec: rocksapi.h`18:incl:2 %
 */
/**
 *  @file
 *  @brief  Header file containing the interface of NYCeRocks.
 */

#ifndef __ROCKS_API_H__
#define __ROCKS_API_H__


#include "rockstypes.h"


#ifdef NT
    #ifndef ROCKS_EXPORT
        #define ROCKS_EXPORT __declspec(dllimport)
    #endif 
#else
    #ifdef ROCKS_EXPORT
    #undef ROCKS_EXPORT
    #endif
    #define ROCKS_EXPORT
#endif


#ifdef __cplusplus
extern "C"
{
#endif


/**
 *
 * @ingroup rocks_miscellaneous
 * @brief  Read the used NyceRocks runtime version.
 *
 * @param [out] pRocksVersion  Pointer to version information.
 */
ROCKS_EXPORT NYCE_STATUS RocksGetVersion(NYCE_VERSION_TYPE* pRocksVersion);

/**
 *
 * @ingroup rocks_mechanism
 * @brief  Create mechanism in the current process or sequence.
 *
 * @param [in]  pMech       Identifies the mechanism.
 *
 *
 * @remarks 1) The fields dof, nrOfJoints and jointAxisId needs to be filled in before
 *             creating the mechanism. The field var is maintained by NYCeRocks.
 *
 * @remarks 2) Initializing and locking the axes must be done by the application. Axis state control 
 *             is not handled by the mechanism.
 *
 * @remarks 3) The axes of the mechanism, need to be at the same node.
 *
 * @remarks 4) This function is only available in n4krocks.lib, i.e. not using the NYCeRocks Server Sequence. 
 *             Link with n4krocks.lib.
 */
ROCKS_EXPORT NYCE_STATUS RocksMechCreate(ROCKS_MECH* pMech);

/**
 *
 * @ingroup rocks_mechanism
 * @brief  Create a mechanism which runs in a NYCeRocks Server Sequence.
 *
 * @param [in]  pMech               Identifies the mechanism.
 * @param [in]  pNodeName           Name of the node where NYCeRocks runs.
 * @param [in]  rocksServerArea     Area number where the NYCeRocks Server Sequence runs. 
 *                                  Note that the server sequence must be running when calling this function.
 * @param [in]  dataArea            Area number of the area which will be used for the client/server communication data.
 *
 *
 * @remarks 1) The fields dof, nrOfJoints and jointAxisId needs to be filled in before
 *             creating the mechanism. The field var is maintained by NYCeRocks.
 *
 * @remarks 2) Initializing and locking the axes must be done by the application. Axis state control 
 *             is not managed by the mechanism.
 *
 * @remarks 3) The axes of the mechanism, need to be at the same node.
 *
 * @remarks 4) This function is implemented in n4krocksseq.dll. Link with the import library n4krocksseq.lib.
 *             In order to use the client/server implementation of the NYCeRocks API, link with the 
 *             import library n4krocksclient.lib.
 */
ROCKS_EXPORT NYCE_STATUS RocksMechCreateAtSrvSeq(ROCKS_MECH* pMech, const char* pNodeName, uint32_t rocksServerArea, uint32_t dataArea);

/**
 *
 * @ingroup rocks_mechanism
 * @brief  Delete mechanism.
 *
 * @param [in]  pMech       The mechanism, which must be deleted.
 */
ROCKS_EXPORT NYCE_STATUS RocksMechDelete(ROCKS_MECH* pMech);

/**
 *
 * @ingroup rocks_mechanism
 * @brief  Define a Probe for latching the Mechanism joint positions.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  latchNr     Latch number (0..3).
 *                          The latch number maps on the SAC_IO_FUNCTION enumeration.
 *                          E.g. latchNr 0 matches SAC_LATCH_0, 1 matches SAC_LATCH_1, etc.
 *                          The same latch number will be used for all axes of the mechanism.
 * @param [in]  io          Digital input.
 *                          The digital input needs already be configured as a latch input.
 *
 * @remarks The implementation uses SacDefineFunctionIO functionality.
 */
ROCKS_EXPORT NYCE_STATUS RocksMechDefineProbe(ROCKS_MECH* pMech, uint32_t latchNr, NYCE_DIGITAL_IO_ID io);

/**
 *
 * @ingroup rocks_mechanism
 * @brief  Delete a Probe which was defined with RocksMechDefineProbe.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  latchNr     Latch number (0..3).
 */
ROCKS_EXPORT NYCE_STATUS RocksMechDeleteProbe(ROCKS_MECH* pMech, uint32_t latchNr);

/**
 *
 * @ingroup rocks_mechanism
 * @brief  Activate the Probe.
 * 
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  latchNr     Latch number (0..3).
 */
ROCKS_EXPORT NYCE_STATUS RocksMechActivateProbe(ROCKS_MECH* pMech, uint32_t latchNr);

/**
 *
 * @ingroup rocks_mechanism
 * @brief  Check the probe (active or not, latched or not).
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  latchNr     Latch number (0..3).
 * @param [out] pActive     Indication if the probe is active.
 * @param [out] pLatched    Indication if the probe has latched the mechanism joint positions.
 */
ROCKS_EXPORT NYCE_STATUS RocksMechGetProbeStatus(ROCKS_MECH* pMech, uint32_t latchNr, BOOL* pActive, BOOL* pLatched);

/**
 *
 * @ingroup rocks_mechanism
 * @brief  Check the latched mechanism joint positions.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  latchNr     Latch number (0..3).
 * @param [out] jointPos    size(pMech->numJoints); array of latched joint positions.
 *
 *
 * @remarks The caller must allocate the array to store the joint positions.
 */
ROCKS_EXPORT NYCE_STATUS RocksMechGetProbePosition(ROCKS_MECH* pMech, uint32_t latchNr, double jointPos[]);

/**
 *
 * @ingroup rocks_mechanism
 * @brief  Group mechanisms to start them together.
 *
 * @param [in]  pMech       size(nrOfMechs); array of pointers to mechanisms.
 * @param [in]  nrOfMechs   Number of mechanisms.
 *
 *
 * @remarks Unlike MacDefineSyncGroup you do not get a group id back.
 *          The group is identified by the first mechanism in the group.
 */
ROCKS_EXPORT NYCE_STATUS RocksMechDefineSyncGroup(ROCKS_MECH* pMech[], uint32_t nrOfMechs);

/**
 *
 * @ingroup rocks_mechanism
 * @brief  Start a group mechanisms simultaneously.
 *
 * @param [in]  pMech       Pointer to the first mechanism of the group.
 * @param [in]  syncAction  Synchronization action (one of MAC_SYNC_MOTION, MAC_SYNC_FEED_OVERRIDE, 
 *                          MAC_SYNC_SMOOTH_STOP, MAC_SYNC_QUICK_STOP, MAC_SYNC_FULL_STOP).
 */
ROCKS_EXPORT NYCE_STATUS RocksMechStartSyncGroup(ROCKS_MECH* pMech, MAC_SYNC_ACTION syncAction);

/**
 *
 * @ingroup rocks_mechanism
 * @brief  Delete the group to which the mechanism belong.
 *
 * @param [in]  pMech       Pointer to the first mechanism of the group.
 */
ROCKS_EXPORT NYCE_STATUS RocksMechDeleteSyncGroup(ROCKS_MECH* pMech);

/**
 *
 * @ingroup rocks_trajectory_sinacc
 * @brief  Create a trajectory with a sinusoidal shaped acceleration for a straight line.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pTraj       Line definition.
 *
 *
 * @remarks It is advised to make pTraj->maxSplines equal to 0 and both 
 *          pTraj->pPositionSplineBuffer and pTraj->pVelocitySplineBuffer
 *          equal to NULL. This will force the trajectory generator to allocate
 *          the memory for the path data dynamically.
 */
ROCKS_EXPORT NYCE_STATUS RocksTrajSineAccPtp(ROCKS_MECH* pMech, const ROCKS_TRAJ_SINE_ACC_PTP_PARS* pTraj);

/**
 *
 * @ingroup rocks_trajectory_sinacc
 * @brief  Create a trajectory with a sinusoidal shaped acceleration for a (part of a) circle.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pTraj       Circle definition.
 *
 *
 * @remarks It is advised to make pTraj->maxSplines equal to 0 and both 
 *          pTraj->pPositionSplineBuffer and pTraj->pVelocitySplineBuffer
 *          equal to NULL. This will force the trajectory generator to allocate
 *          the memory for the path data dynamically.
 */
ROCKS_EXPORT NYCE_STATUS RocksTrajSineAccCircle(ROCKS_MECH* pMech, const ROCKS_TRAJ_SINE_ACC_CIRCLE_PARS* pTraj);

/**
 *
 * @ingroup rocks_trajectory_cubic
 * @brief  Create a trajectory with velocity, acceleration and jerk constraints for a straight line.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pTraj       Line definition.
 *
 *
 * @remarks 1) It is advised to make pTraj->maxSplines equal to 0 and both 
 *             pTraj->pPositionSplineBuffer and pTraj->pVelocitySplineBuffer
 *             equal to NULL. This will force the trajectory generator to allocate
 *             the memory for the path data dynamically.
 *
 * @remarks 2) This trajectory generates a maximum of 8 splines. If no separate joint
 *             is used it uses only 7 splines.
 */
ROCKS_EXPORT NYCE_STATUS RocksTrajCubicPtp(ROCKS_MECH* pMech, const ROCKS_TRAJ_CUBIC_PTP_PARS* pTraj);

/**
 *
 * @ingroup rocks_trajectory_cubic
 * @brief  Create a trajectory with velocity, acceleration and jerk constraints for a (part of a) circle.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pTraj       Circle definition.
 *
 *
 * @remarks 1) It is advised to make pTraj->maxSplines equal to 0 and both 
 *             pTraj->pPositionSplineBuffer and pTraj->pVelocitySplineBuffer
 *             equal to NULL. This will force the trajectory generator to allocate
 *             the memory for the path data dynamically.
 *
 * @remarks 2) This trajectory generates a maximum of 8 splines. If no separate joint
 *             is used it uses only 7 splines.
 *
 * @remarks 3) Because only a limited number of splines are used, the circle becomes less
 *             accurate if the angle is increased. The maximum angle is PI radians.
 */
ROCKS_EXPORT NYCE_STATUS RocksTrajCubicCircle(ROCKS_MECH* pMech, const ROCKS_TRAJ_CUBIC_CIRCLE_PARS* pTraj);

/**
 *
 * @ingroup rocks_trajectory_cubic
 * @brief  Increase joint speeds of TrajCubicLine and RocksTrajCubicCircle.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  joint       Joint number of the mechanism.
 * @param [in]  pJointInfo  Joint constraints.
 *
 *
 * @remarks Normally all joints of the mechanism start and end simultaneous.
 *           However, sometimes it is desired to have one or more joints run on
 *           a more optimal speed. With this function you can set the constraints
 *           for this specific joint and determine if it should start simultaneous 
 *           or stop simultaneous with the other joints.
 *           It is a bit contradictory, but if the path calculation causes the joint
 *           to move faster than the constraints in pJointInfo, these constraints are
 *           ignored. The user can lower the path constraints in this case.
 */
ROCKS_EXPORT NYCE_STATUS RocksTrajCubicSeparateJointSpeed(ROCKS_MECH* pMech, uint32_t joint, const ROCKS_TRAJ_CUBIC_JOINT_INFO* pJointInfo);

/**
 *
 * @ingroup rocks_trajectory_segments
 * @brief  Start path trajectory segments.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pTraj       Segment start definition.
 *
 *
 * @remarks 1) It is advised to make pTraj->maxSplines equal to 0 and both 
 *             pTraj->pPositionSplineBuffer and pTraj->pVelocitySplineBuffer
 *             equal to NULL. This will force the trajectory generator to allocate
 *             the memory for the path data dynamically.
 *
 * @remarks 2) This function starts the cascading of line and arc segments. After
 *             this function RocksTrajSegmentLine and RocksTrajSegmentArc calls can be invoked.
 */
ROCKS_EXPORT NYCE_STATUS RocksTrajSegmentStart(ROCKS_MECH* pMech, const ROCKS_TRAJ_SEGMENT_START_PARS* pTraj);

/**
 *
 * @ingroup rocks_trajectory_segments
 * @brief  Add a line segment to the path.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pTraj       Line segment definition.
 */
ROCKS_EXPORT NYCE_STATUS RocksTrajSegmentLine(ROCKS_MECH* pMech, const ROCKS_TRAJ_SEGMENT_LINE_PARS* pTraj);

/**
 *
 * @ingroup rocks_trajectory_segments
 * @brief  Add a arc segment to the path.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pTraj       Arc segment definition.
 */
ROCKS_EXPORT NYCE_STATUS RocksTrajSegmentArc(ROCKS_MECH* pMech, const ROCKS_TRAJ_SEGMENT_ARC_PARS* pTraj);

/**
 *
 * @ingroup rocks_trajectory_misc
 * @brief  Get last generated path splines from the mechanism.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [out] pTraj       Path splines.
 */
ROCKS_EXPORT NYCE_STATUS RocksTrajGetPath(ROCKS_MECH* pMech, ROCKS_TRAJ_PATH* pTraj);

/**
 *
 * @ingroup rocks_trajectory_misc
 * @brief  Load path splines in the mechanism.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pTraj       Path splines.
 */
ROCKS_EXPORT NYCE_STATUS RocksTrajLoadPath(ROCKS_MECH* pMech, const ROCKS_TRAJ_PATH* pTraj);

/**
 *
 * @ingroup rocks_trajectory_misc
 * @brief  Delete the path which was retrieved with RocksTrajGetPath.
 *
 * @param [in]      pMech   Identifies the mechanism.
 * @param [in,out]  pTraj   Path splines.
 */
ROCKS_EXPORT NYCE_STATUS RocksTrajDeletePath(ROCKS_MECH* pMech, ROCKS_TRAJ_PATH* pTraj);

/**
 *
 * @ingroup rocks_kinematics
 * @brief  Translate and rotate the reference frame.
 *
 * The translation and rotation defined in pOrg are added to previous translation and rotation offsets.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pOrg        Origin shift & rotate parameters.
 */
ROCKS_EXPORT NYCE_STATUS RocksKinMoveOrigin(ROCKS_MECH* pMech, const ROCKS_POSE* pOrg);

/**
 *
 * @ingroup rocks_kinematics
 * @brief  Reset the origin to its original position.
 *
 * @param [in]  pMech       Identifies the mechanism.
 */
ROCKS_EXPORT NYCE_STATUS RocksKinResetOrigin(ROCKS_MECH* pMech);

/**
 *
 * @ingroup rocks_kinematics
 * @brief  Apply reference frame in the inverse direction.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pPose       The 6-DOF pose before inverse transformation with the reference frame.
 * @param [out] pPose       The 6-DOF pose after inverse transformation with the reference frame.
 *
 * @remarks This function is normally used by the Kinematic layer and not by the application.
*/
ROCKS_EXPORT NYCE_STATUS RocksKinInverseTransRot(const ROCKS_MECH* pMech, ROCKS_POSE* pPose);

/**
 *
 * @ingroup rocks_kinematics
 * @brief  Apply reference frame in the forward direction.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pPose       The 6-DOF pose before forward transformation with the reference frame.
 * @param [out] pPose       The 6-DOF pose after forward transformation with the reference frame.
 *
 * @remarks This function is normally used by the Kinematic layer and not by the application.
*/
ROCKS_EXPORT NYCE_STATUS RocksKinForwardTransRot(const ROCKS_MECH* pMech, ROCKS_POSE* pPose);

/**
 *
 * @ingroup rocks_kinematics
 * @brief  Set a user defined inverse conversion function.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  fnc         User defined conversion function.
 *
 * @remarks Only one function can be active. To delete the function, specify NULL as the conversion function.
 */
ROCKS_EXPORT NYCE_STATUS RocksKinSetInverseCompensation(ROCKS_MECH* pMech, ROCKS_KIN_CONVERSION fnc);

/**
 *
 * @ingroup rocks_kinematics
 * @brief  Set a user defined forward conversion function
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  fnc         User defined conversion function.
 *
 * @remarks Only one function can be active. To delete the function, specify NULL as the conversion function.
 */
ROCKS_EXPORT NYCE_STATUS RocksKinSetForwardCompensation(ROCKS_MECH* pMech, ROCKS_KIN_CONVERSION fnc);

/**
 *
 * @ingroup rocks_kinematics_cartesian
 * @brief  Generate joint splines for a Cartesian mechanism.
 *
 * @param [in]  pMech       Identifies the mechanism.
 * @param [in]  pKin        Joint buffers.
 *
 * @remarks It is advised to make pKin->pJointPositionBuffer[j] and pKin->pJointVelocityBuffer[j]
 *          equal to NULL for all joints. This will force the kinematics to allocate
 *          the memory dynamically.
 */
ROCKS_EXPORT NYCE_STATUS RocksKinInverseCartesian(ROCKS_MECH* pMech, const ROCKS_KIN_INV_PARS* pKin);

/**
 *
 * @ingroup rocks_kinematics_cartesian
 * @brief  Translate joint coordinates to world coordinates.
 *
 * The length of pJointPos buffer depends on the number of joints in the mechanism. The length of
 * pCartesianPos is always ROCKS_MECH_MAX_DOF.
 *
 * @param [in]  pMech         Identifies the mechanism.
 * @param [in]  jointPos      size(pMech->nrOfJoints); joint coordinates.
 * @param [out] cartesianPos  size(ROCKS_MECH_MAX_DOF); world coordinates.
 */
ROCKS_EXPORT NYCE_STATUS RocksKinForwardCartesian(ROCKS_MECH* pMech, const double jointPos[], double cartesianPos[]);

/**
 *
 * @ingroup rocks_kinematics_cartesian
 * @brief  Translate actual joint coordinates to world coordinates.
 *
 * The length of pCartesianPos is always ROCKS_MECH_MAX_DOF.
 *
 * @param [in]  pMech         Identifies the mechanism.
 * @param [out] cartesianPos  size(ROCKS_MECH_MAX_DOF); world coordinates.
 */
ROCKS_EXPORT NYCE_STATUS RocksKinCartesianPosition(ROCKS_MECH* pMech, double cartesianPos[]);

/**
 *
 * @ingroup rocks_kinematics_gantry
 * @brief  Generate joint splines for a Gantry mechanism.
 *
 * @param [in]  pMech         Identifies the mechanism.
 * @param [in]  pKin          Joint buffers.
 *
 *
 * @remarks It is advised to make pKin->pJointPositionBuffer[j] and pKin->pJointVelocityBuffer[j]
 *          equal to NULL for all joints. This will force the kinematics to allocate
 *          the memory dynamically.
 */
ROCKS_EXPORT NYCE_STATUS RocksKinInverseGantry(ROCKS_MECH* pMech, const ROCKS_KIN_INV_PARS* pKin);

/**
 *
 * @ingroup rocks_kinematics_gantry
 * @brief  Translate joint coordinates to world coordinates.
 *
 * The length of pJointPos buffer depends on the number of joints in the mechanism. The length of
 * pGantryPos is always ROCKS_MECH_MAX_DOF.
 *
 * @param [in]  pMech         Identifies the mechanism.
 * @param [in]  jointPos      size(pMech->nrOfJoints); joint coordinates.
 * @param [out] gantryPos     size(ROCKS_MECH_MAX_DOF); world coordinates.
 */
ROCKS_EXPORT NYCE_STATUS RocksKinForwardGantry(ROCKS_MECH* pMech, const double jointPos[], double gantryPos[]);

/**
 *
 * @ingroup rocks_kinematics_gantry
 * @brief  Translate actual joint coordinates to world coordinates.
 *
 * The length of pGantryPos is always ROCKS_MECH_MAX_DOF.
 *
 * @param [in]  pMech         Identifies the mechanism.
 * @param [out] gantryPos     size(ROCKS_MECH_MAX_DOF); world coordinates.
 */
ROCKS_EXPORT NYCE_STATUS RocksKinGantryPosition(ROCKS_MECH* pMech, double gantryPos[]);

/**
 *
 * @ingroup rocks_kinematics_gantry
 * @brief  Define gantry kinematics.
 *
 * A gantry has two X axes or two Y axes. This function set one of the
 * two. It should be invoked after creating the mechanism, if the
 * mechanism is a gantry. If the direction is ROCKS_GANTRY_X, the joints
 * are X1, X2, Y. It the direction is ROCKS_GANTRY_Y the joints are X, Y1, Y2.
 * After these 3 mandatory joints, additional joints for other DOF can follow.
 *
 * @param [in]  pMech            Identifies the mechanism.
 * @param [in]  gantryDirection  Direction of the gantry.
 */
ROCKS_EXPORT NYCE_STATUS RocksKinDefineGantry(ROCKS_MECH* pMech, ROCKS_GANTRY_DIRECTION gantryDirection);

/**
 *
 * @ingroup rocks_streamer
 * @brief  Start streaming splines of the joint spline buffers to the axes.
 * 
 * Use SacSynchronize of the axes to check if the streaming is finished.
 *
 * @param [in]  pMech           Identifies the mechanism.
 */
ROCKS_EXPORT NYCE_STATUS RocksStream(ROCKS_MECH* pMech);

/**
 *
 * @ingroup rocks_streamer
 * @brief  Release both Mac and Error joint groups created previously by the RocksStream function.
 *
 * @param [in]  pMech           Identifies the mechanism.
 */
ROCKS_EXPORT NYCE_STATUS RocksStreamReleaseGroup(ROCKS_MECH* pMech);

/**
 *
 * @ingroup rocks_streamer
 * @brief  Synchronize on the finished motion of all axes of the mechanism.
 *
 * @param [in]  pMech           Identifies the mechanism.
 * @param [in]  timeout         Timeout value in[s] or SAC_INDEFINITE.
 */
ROCKS_EXPORT NYCE_STATUS RocksStreamSynchronize(ROCKS_MECH* pMech, double timeout);

#ifdef __cplusplus
}
#endif

/** @} */

#endif // __ROCKS_API_H__

