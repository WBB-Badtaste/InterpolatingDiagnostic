/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2014
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: SEQ
 *  %full_filespec: seqtypes.h`3:incl:1 %
 */
/**
 *  @file
 *  @brief  Header file containing data types and defines for SEQ.
 */
#ifndef __SEQTYPES_H__
#define __SEQTYPES_H__


/**
 * @defgroup seq Sequencer (SEQ)
 *
 * External interface of Sequencer library
 *
 * @{
 */

/**
 *  @brief  Sequence state
 */
typedef enum seq_state
{
    SEQ_STATE_INACTIVE = 0,                 /**< inactive (not assigned)      */
    SEQ_STATE_INITIALIZING,                 /**< initializing                 */
    SEQ_STATE_ACTIVE,                       /**< active                       */
    SEQ_STATE_BLOCKED,                      /**< waiting on something         */
    SEQ_STATE_FINISHING,                    /**< aborting                     */
    SEQ_STATE_DORMANT                       /**< dormant (going to be blocked)*/

} SEQ_STATE;


/**
 *  @}
 */

#endif
