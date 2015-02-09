/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2014
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: rocks
 *
 *  %full_filespec: rocksseq.h`9:incl:2 %
 */
/**
 *  @file
 *  @brief  This file contains the communication interface of NYCeRocks client/server.
 */

#ifndef __ROCKSSEQ_H__
#define __ROCKSSEQ_H__


#ifdef NT
    #ifndef ROCKS_SEQ_EXPORT
        #define ROCKS_SEQ_EXPORT __declspec(dllimport)
    #endif
#else
    #ifdef ROCKS_SEQ_EXPORT
    #undef ROCKS_SEQ_EXPORT
    #endif
    #define ROCKS_SEQ_EXPORT
#endif

/**
 * @defgroup rocksseq Rocks Sequence API (ROCKSSEQ)
 *
 * External interface of Rocks sequence library.
 *
 * @{
 */

#define ROCKS_SRV_MAX_NR_OF_MECHANISMS_PER_NODE   8

#define ROCKS_SRV_MAX_NR_OF_ARGS     100

#define ROCKS_SRV_OWNED_BY_CLIENT    444
#define ROCKS_SRV_OWNED_BY_SERVER    555

/**
 *  @brief Union type for one argument in a NYCeRocks command block.
 */
typedef union rocks_srv_arg
{
    int32_t         iType;
    float           fType;
    uint32_t        uiType;
    BOOL            bType;
    char            cType;
} ROCKS_SRV_ARG;

/**
 *  @brief Command block structure which holds communication data for the NYCeRocks Client/Server communication.
 */
typedef struct rocks_srv_comm_block
{
    uint32_t        owner;                          /**< Defines the owner (client or server) of this command block */
    uint32_t        cmd;                            /**< Command identifier */
    uint32_t        tag;                            /**< Internal use only */
    int32_t         area;                           /**< Area number of the originator */
    uint32_t        nrArgs;                         /**< Number of used arguments in arg[] */
    ROCKS_SRV_ARG   arg[ROCKS_SRV_MAX_NR_OF_ARGS];  /**< Arguments */
} ROCKS_SRV_COMM_BLOCK;

/**
 *  @brief Command block structure which holds the command (request) data and the response data.
 */
typedef struct rocks_interface
{
    ROCKS_SRV_COMM_BLOCK  command;
    ROCKS_SRV_COMM_BLOCK  response;
}ROCKS_INTERFACE;


#define ROCKS_SRV_COMM_FIELD_SIZE          4
#define ROCKS_SRV_COMM_OFFSET_OWNER        0
#define ROCKS_SRV_COMM_OFFSET_CMD          (ROCKS_SRV_COMM_OFFSET_OWNER  + ROCKS_SRV_COMM_FIELD_SIZE)
#define ROCKS_SRV_COMM_OFFSET_TAG          (ROCKS_SRV_COMM_OFFSET_CMD    + ROCKS_SRV_COMM_FIELD_SIZE)
#define ROCKS_SRV_COMM_OFFSET_AREA         (ROCKS_SRV_COMM_OFFSET_TAG    + ROCKS_SRV_COMM_FIELD_SIZE)
#define ROCKS_SRV_COMM_OFFSET_NRARGS       (ROCKS_SRV_COMM_OFFSET_AREA   + ROCKS_SRV_COMM_FIELD_SIZE)
#define ROCKS_SRV_COMM_OFFSET_ARG          (ROCKS_SRV_COMM_OFFSET_NRARGS + ROCKS_SRV_COMM_FIELD_SIZE)


#define ROCKS_SRV_COMM_MECH_CREATE                          100
#define ROCKS_SRV_COMM_MECH_DELETE                          101
#define ROCKS_SRV_COMM_MECH_DEFINE_SYNC_GROUP               102
#define ROCKS_SRV_COMM_MECH_START_SYNC_GROUP                103
#define ROCKS_SRV_COMM_MECH_DELETE_SYNC_GROUP               104
#define ROCKS_SRV_COMM_MECH_DEFINE_PROBE                    105
#define ROCKS_SRV_COMM_MECH_DELETE_PROBE                    106
#define ROCKS_SRV_COMM_MECH_ACTIVATE_PROBE                  107
#define ROCKS_SRV_COMM_MECH_GET_PROBE_STATUS                108
#define ROCKS_SRV_COMM_MECH_GET_PROBE_POSITION              109

#define ROCKS_SRV_COMM_TRAJ_SINE_ACC_PTP                    201
#define ROCKS_SRV_COMM_TRAJ_SINE_ACC_CIRCLE                 202

#define ROCKS_SRV_COMM_TRAJ_CUBIC_PTP                       210
#define ROCKS_SRV_COMM_TRAJ_CUBIC_CIRCLE                    211
#define ROCKS_SRV_COMM_TRAJ_CUBIC_SEPERATE_JOINT_SPEED      212

#define ROCKS_SRV_COMM_TRAJ_SEGM_START                      220
#define ROCKS_SRV_COMM_TRAJ_SEGM_LINE                       221
#define ROCKS_SRV_COMM_TRAJ_SEGM_ARC                        222

#define ROCKS_SRV_COMM_TRAJ_LOAD_PATH                       300
#define ROCKS_SRV_COMM_TRAJ_GET_PATH                        301

#define ROCKS_SRV_COMM_KIN_MOVE_ORIGIN                      1000
#define ROCKS_SRV_COMM_KIN_RESET_ORIGIN                     1001

#define ROCKS_SRV_COMM_KIN_INVERSE_CARTESIAN                1100
#define ROCKS_SRV_COMM_KIN_FORWARD_CARTESIAN                1101
#define ROCKS_SRV_COMM_KIN_CART_POS                         1102

#define ROCKS_SRV_COMM_KIN_INVERSE_GANTRY                   1200
#define ROCKS_SRV_COMM_KIN_FORWARD_GANTRY                   1201
#define ROCKS_SRV_COMM_KIN_GANTRY_POS                       1202
#define ROCKS_SRV_COMM_KIN_DEFINE_GANTRY                    1205

#define ROCKS_SRV_COMM_STREAM                               2000
#define ROCKS_SRV_COMM_STREAM_RELEASE_GROUP                 2001
#define ROCKS_SRV_COMM_STREAM_SYNCHRONIZE                   2002


#ifdef __cplusplus
extern "C"
{
#endif


/**
 *  @brief  Send a NYCeRocks command to the NYCeRocks server sequence.
 *
 *  @param [in]     pMech   Identifies the mechanism.
 *  @param [in,out] pCmd    Command input data.
 *                          Note: This function fills also some members of pCmd.
 *  @param [out]    pRsp    Command output data.
 *
 *  @return     A NYCE_STATUS return code.
 *              NYCE_OK is the command completed successfully.
 */
ROCKS_SEQ_EXPORT NYCE_STATUS RocksSrvSendCommand(ROCKS_MECH* pMech, ROCKS_SRV_COMM_BLOCK* pCmd, ROCKS_SRV_COMM_BLOCK* pRsp);

#ifdef __cplusplus
}
#endif

/** @} */

#endif
