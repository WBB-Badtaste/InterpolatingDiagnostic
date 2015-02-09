/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2009
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000_SW
//    %full_filespec: nyceextdefs.h`15:incl:1 % (SYNERGY INFO, do not change)
//
//    Description   : Definitions for NYCe4000 extensions
*/
#ifndef __NYCE_FCL_EXTENTIONS_DEFS_H__
#define __NYCE_FCL_EXTENTIONS_DEFS_H__

#include "nycetypes.h"
#include "sacfclparameters.h"
#include "sacfclvariables.h"


/************************************************************************/
/* FCL interface                                                        */
/************************************************************************/

/**
 * @addtogroup ext_fcl
 * @{
 */

/* FCL command error codes. */
#define SAC_FCL_ERR_INTERNAL_ERROR              ((NYCE_STATUS)((NYCE_ERROR_MASK) | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | 1))
#define SAC_FCL_ERR_INVALID_STATE               ((NYCE_STATUS)((NYCE_ERROR_MASK) | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | 2))
#define SAC_FCL_ERR_ENDAT_CHANNEL_IN_USE        ((NYCE_STATUS)((NYCE_ERROR_MASK) | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | 3))
#define SAC_FCL_ERR_INVALID_SENSOR_ID           ((NYCE_STATUS)((NYCE_ERROR_MASK) | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | 4))
#define SAC_FCL_ERR_INVALID_DATA_ID             ((NYCE_STATUS)((NYCE_ERROR_MASK) | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | 5))
#define SAC_FCL_ERR_INVALID_SENSOR_CONFIG       ((NYCE_STATUS)((NYCE_ERROR_MASK) | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | 6))


/* FCL Events. */
#define SAC_EV_FCL_POS_CLIPPED                  ((NYCE_EVENT)( ((SS_EXT<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | 1))
#define SAC_EV_FCL_NEG_CLIPPED                  ((NYCE_EVENT)( ((SS_EXT<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | 2))
#define SAC_EV_FCL_FOCUS_STATE_CHANGED          ((NYCE_EVENT)( ((SS_EXT<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | 3))
#define SAC_EV_FCL_FOCUS_IN_RANGE               ((NYCE_EVENT)( ((SS_EXT<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | 4))
#define SAC_EV_FCL_FOCUS_OUT_OF_RANGE           ((NYCE_EVENT)( ((SS_EXT<<NYCE_SUBSYS_SHIFT)|(NO_SLOT<<NYCE_SLOT_SHIFT)|(FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | 5))

/* FCL axis error codes. Error handlers can be configured for these errors.*/
#define SAC_AX_ERR_FCL_ENDAT_S1_COMMUNICATION_LOST     ((NYCE_ERROR_CODE)((NYCE_ERROR_MASK)|(((SS_EXT<<NYCE_SUBSYS_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)) | 1)))
#define SAC_AX_ERR_FCL_ENDAT_S1_ERROR_BIT              ((NYCE_ERROR_CODE)((NYCE_ERROR_MASK)|(((SS_EXT<<NYCE_SUBSYS_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)) | 2)))
#define SAC_AX_ERR_FCL_ENDAT_S2_COMMUNICATION_LOST     ((NYCE_ERROR_CODE)((NYCE_ERROR_MASK)|(((SS_EXT<<NYCE_SUBSYS_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)) | 3)))
#define SAC_AX_ERR_FCL_ENDAT_S2_ERROR_BIT              ((NYCE_ERROR_CODE)((NYCE_ERROR_MASK)|(((SS_EXT<<NYCE_SUBSYS_SHIFT)|(FWM_EDHHANDLER<<NYCE_FWMODULE_SHIFT)) | 4)))

/* FCL Event data for SAC_EV_FCL_FOCUS_STATE_CHANGED event.*/
#define SAC_FCL_EVDATA_FOCUS_STATE_NOK    0
#define SAC_FCL_EVDATA_FOCUS_STATE_OK     1


/**
 * FCL Event data for SAC_EV_FCL_FOCUS_IN_RANGE and SAC_EV_FCL_FOCUS_OUT_OF_RANGE events.
 */
#define SAC_FCL_EVDATA_SENSOR1 1
#define SAC_FCL_EVDATA_SENSOR2 2


/**
 * Sensor identifiers for diagnose data access.
 */
typedef enum sac_fcl_sensor_id
{
    SAC_FCL_SENSOR_S1 = 1,
    SAC_FCL_SENSOR_S2 = 2
}SAC_FCL_SENSOR_ID;


/**
 * Data identifiers for diagnose data access.
 */
typedef enum sac_fcl_diag_data_id
{
    SAC_FCL_DIAG_DATA_ERROR_BITS = 0,
    SAC_FCL_DIAG_DATA_WORD_0,
    SAC_FCL_DIAG_DATA_WORD_1,
    SAC_FCL_DIAG_DATA_WORD_2,
    SAC_FCL_DIAG_DATA_WORD_3,
    SAC_FCL_DIAG_DATA_WORD_4,
    SAC_FCL_DIAG_DATA_WORD_5,
    SAC_FCL_DIAG_DATA_WORD_6,
    SAC_FCL_DIAG_DATA_WORD_7,
    SAC_FCL_DIAG_DATA_WORD_8,
    SAC_FCL_DIAG_DATA_WORD_9,
    SAC_FCL_DIAG_DATA_WORD_10,
    SAC_FCL_DIAG_DATA_WORD_11,
    SAC_FCL_DIAG_DATA_WORD_12,
    SAC_FCL_DIAG_DATA_WORD_13,
    SAC_FCL_DIAG_DATA_WORD_14,
    SAC_FCL_DIAG_DATA_WORD_15

}SAC_FCL_DIAG_DATA_ID;


/** 
 * FCL state.
 */
typedef enum sac_fcl_state
{
    SAC_FCL_STATE_IDLE = 0,                 /**< FCL is totally inactive. When using EnDat channels, diagnose data can be read in this state. */
    SAC_FCL_STATE_MASTER_INACTIVE = 1,      /**< FCL is processing the sensor inputs, but not generating setpoints. */
    SAC_FCL_STATE_MASTER_ACTIVE   = 2       /**< FCL is fully active. FCL is generating setpoints in a closed loop using inputs S1 and S2. */
}SAC_FCL_STATE;


/** 
 * Sensor input type selection. 
 */
typedef enum sac_fcl_sensor_source_type 
{
    SAC_FCL_SENSOR_SOURCE_AN_IN,            /**< Use analogue input as source of the FCL sensor input. */
    SAC_FCL_SENSOR_SOURCE_ENDAT             /**< Use EnDat interface as source of the FCL sensor input. */
}SAC_FCL_SENSOR_SOURCE_TYPE;



/** 
 * Configuration structure for an FCL sensor input using an EnDat channel.
 */
typedef struct sac_fcl_endat_cfg
{
    NYCE_SLOT_ID    slotId;                 /**< Slot Id for this EnDat channel. */
    int32_t         unitNr;                 /**< Unit on the specified slot which is used for this EnDat channel. Can be 0 or 1. */
    uint32_t        clockFrequency;         /**< EnDat clock frequency. */
}SAC_FCL_ENDAT_CFG;



/** 
 * Configuration for one FCL sensor.
 */
typedef struct sac_fcl_sensor_config
{
    SAC_FCL_SENSOR_SOURCE_TYPE  type;       /**< Specifies which configuration member is used. */
    
    SAC_FCL_ENDAT_CFG           EnDat;      /**< EnDat channel configuration. Used when type is SAC_FCL_SENSOR_SOURCE_ENDAT. */
    NYCE_ANALOG_IN_ID           anIn;       /**< Analogue input configuration. Used when type is SAC_FCL_SENSOR_SOURCE_AN_IN. */

}SAC_FCL_SENSOR_CONFIG;

/** 
 * Complete FCL Configuration structure.
 * FCL will be initialized using this configuration structure.
 */
typedef struct sac_fcl_config
{
    SAC_FCL_SENSOR_CONFIG   S1;                 /**< Sensor 1 configuration. */
    SAC_FCL_SENSOR_CONFIG   S2;                 /**< Sensor 2 configuration. */
    NYCE_DIGITAL_IO_ID      digInInhibit;       /**< Digital input configuration for Inhibit Input. */
    NYCE_DIGITAL_IO_ID      digOutFocusReady;   /**< Digital output for Focus Ready Signal. */
}SAC_FCL_CONFIG;


/**
 * @}
 */

#endif  
