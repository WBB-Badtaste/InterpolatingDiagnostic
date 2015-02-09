/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2011-2012
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  %full_filespec:  n4k_basictypes.h`18:incl:1 %
 */
/**
 *  @file
 *  @brief  Definition file for basic types in NYCe4000
 *
 *  The types defined here are used in the definitions of parameter ids, variable ids, data ids,
 *  event ids, return codes and asynchronous error codes.
 */
#ifndef __N4K_BASICTYPES_H__
#define __N4K_BASICTYPES_H__

#include "n4k_deprecated.h" //lint !e451
#include "nyceint.h"
#include "nycebool.h"

/**
 * @addtogroup nyce
 * @{
 */
/** The return type for all NYCe4000 API functions. */
typedef uint32_t NYCE_STATUS;

/** The basetype for all NYCe4000 data, parameter, variable, event identifiers. */
typedef uint32_t NYCE_DATA_ID;

/* The bitfield construction of all these ids is internally used
 */

/** The subsystem ids are used in the definition of return codes for each subsystem, including
 *  the asynchronous error return values reported by the firmware. The "hostsw"
 *  component ids also occur in definitions of parameter ids, variable ids and events.
 */
typedef enum nyce_subsystem
{
    SS_NYCE         = 0,  /**< Identifier for NYCE subsystem */
    SS_DWN          = 1,  /**< Identifier for DWN subsystem */
    SS_SYS          = 2,  /**< Identifier for SYS subsystem */
    SS_NHI          = 3,  /**< Identifier for NHI subsystem */
    SS_SAC          = 4,  /**< Identifier for SAC subsystem */
                          /* Empty */
    SS_SEQ          = 6,  /**< Identifier for SEQ subsystem */
    SS_DEH          = 7,  /**< Identifier for DEH subsystem */
    SS_OSAL         = 8,  /**< Identifier for OSAL subsystem */
    SS_NCS          = 9,  /**< Identifier for NCS subsystem */
    SS_NYCESIM      = 10, /**< Identifier for SIM subsystem */
    SS_FAC          = 11, /**< Identifier for FAC subsystem */
    SS_HNI          = 12, /**< Identifier for HNI subsystem */
    SS_TSK          = 13, /**< Identifier for TSK subsystem */
    SS_STD          = 14, /**< Identifier for STD subsystem */
    SS_EDH          = 15, /**< Identifier for EDH subsystem */
    SS_EVH          = 16, /**< Identifier for EVH subsystem */
    SS_SPG          = 17, /**< Identifier for SPG subsystem */
    SS_CTR          = 18, /**< Identifier for CTR subsystem */
    SS_UDC          = 19, /**< Identifier for UDC subsystem */
    SS_PDS          = 20, /**< Identifier for PDS subsystem */
    SS_CML          = 21, /**< Identifier for CML subsystem */
    SS_GEN          = 22, /**< Identifier for GEN subsystem */
    SS_HAL          = 23, /**< Identifier for HAL subsystem */
    SS_NNI          = 24, /**< Identifier for NNI subsystem */
    SS_PPI          = 25, /**< Identifier for PPI subsystem */
    SS_SQC          = 26, /**< Identifier for SQC subsystem */
                          /* Empty */
    SS_UTILS        = 28, /**< Identifier for XML subsystem */
    SS_CM           = 29, /**< Identifier for CM subsystem  */
    SS_CFG          = 30, /**< Identifier for CFG subsystem */
    SS_CUSTOM       = 31, /**< Identifier for client specific subsystem */
    SS_USR          = 32, /**< Identifier for user subsystem */
    SS_CMD          = 33, /**< Identifier for CMD subsystem */
                          /* Empty */
    SS_CMLFLASH     = 36, /**< Identifier for CMLFLASH subsystem */
    SS_EXT          = 37, /**< Identifier for Nyce4000 extensions subsystem */
    SS_SERC         = 38, /**< Identifier for SERC subsystem */
    SS_TRACE        = 39, /**< Identifier for TRACE subsystem */
    SS_ACS          = 40, /**< Identifier for ACS subsystem */
    SS_ROCKS        = 41, /**< Identifier for NYCeRocks subsystem */
    SS_NR_OF_SUBSYS = 42

} NYCE_SUBSYSTEM;


/** This enumeration contains the possible slot ids of a node. The value NYCE_MCU_SLOT is
 *  used to access data on the MCU unit. NYCE_MAX_NR_OF_SLOTS is used for arrays with slot
 *  id as index and for range checking. The definition of NO_SLOT is only used for
 *  definition of parameters, variable, error codes and event ids, which are not NHI related.
 *  NOTE: The sensible enumerator values always match the number within the enumeration name.
 */
typedef enum nyce_slot_id
{
    NYCE_SLOT0 = 0,
    NYCE_SLOT1 = 1,
    NYCE_SLOT2 = 2,
    NYCE_SLOT3 = 3,
    NYCE_SLOT4 = 4,
    NYCE_MCU_SLOT = 8,
    NYCE_INDRA_SLOT = 9,         /**< used for IndraDrive function I/O */
    NO_SLOT = 15                 /**< used for data and event definition */

} NYCE_SLOT_ID;


/** 
 *  This enumeration defines an id for the types used to communicate data between host and
 *  firmware. This implicitly indicates how data must be converted on the host, before and
 *  after transmission to the node.
 */
typedef enum nyce_fw_type
{
    FW_LONG,
    FW_ULONG,
    FW_FLOAT,
    FW_BOOL,
    FW_VAR_SET,
    FW_DOUBLE,
    
    FW_NR_OF_TYPES  /**< @_nrOfEnumValues */

} NYCE_FW_TYPE;


/** The dimensions in which the firmware represents data as far as these dimensions deviate
 *  from dimensions used at host level. This implicitly indicates how data must be converted
 *  on the host, before and after transmission to the node.
 */
typedef enum nyce_dimension_conversion
{
    FW_SAME,        /**< host and firmware use same units */
    FW_INC,         /**< host uses pu, firmware inc */
    FW_PER_INC,     /**< host uses 1/pu, firmware 1/inc */
    FW_NR_OF_DIMS   /**< @_nrOfEnumValues */
} NYCE_DIMENSION_CONVERSION;


/** These definitions are part of the parameter and variable ids, and can be used
 * in the communication software in order to find out which module owns the data
 * transmitted.
 * New definitions should be appended.
 */
typedef enum nyce_fw_module_id
{
    FWM_TSKMAIN     = 0,        /**< identifier of module tskmain.c */
    FWM_TSKINIT     = 1,        /**< identifier of module tskinit.c */
    FWM_TSKCFG      = 2,        /**< identifier of module tskcfg.c */
    FWM_TSKDATA     = 3,        /**< identifier of module tskdata.c */
    FWM_STDMAIN     = 4,        /**< identifier of module stdmain.c */
    FWM_STDADMI     = 5,        /**< identifier of module stdadmi.c */
    FWM_EDHMAIN     = 6,        /**< identifier of module edhmain.c */
    FWM_EDHCHECK    = 7,        /**< identifier of module edhcheck.c */
    FWM_EDHHANDLER  = 8,        /**< identifier of module edhhandler.c */
    FWM_EDHGROUP    = 9,        /**< identifier of module edhgroup.c */
    FWM_EDHSERVICE  = 10,       /**< identifier of module edhservice.c */
    FWM_EVHGEN      = 11,       /**< identifier of module evhgen.c */
    FWM_EVHEVT      = 12,       /**< identifier of module evhevt.c */
    FWM_EVHACT      = 13,       /**< identifier of module evhact.c */
    FWM_EVHGROUP    = 14,       /**< identifier of module evhgroup.c */
    FWM_EVHREQ      = 15,       /**< identifier of module evhreq.c */
    FWM_EVHMRK      = 16,       /**< identifier of module evhmrk.c */
    FWM_SPGMAIN     = 17,       /**< identifier of module spgmain.c */
    FWM_SPGFOV      = 18,       /**< identifier of module spgfov.c */
    FWM_SPGPTP      = 19,       /**< identifier of module spgptp.c */
    FWM_SPGJOG      = 20,       /**< identifier of module spgjog.c */
    FWM_SPGSPL      = 21,       /**< identifier of module spgspl.c */
    FWM_SPGSTP      = 22,       /**< identifier of module spgstp.c */
    FWM_SPGQST      = 23,       /**< identifier of module spgqst.c */
    FWM_SPGHOME     = 24,       /**< identifier of module spghome.c */
    FWM_ECGMAS      = 25,       /**< identifier of module ecgmas.c */
    FWM_ECGGEAR     = 26,       /**< identifier of module ecggear.c */
    FWM_ECGCAM      = 27,       /**< identifier of module ecggear.c */
    FWM_ECGFIL      = 28,       /**< identifier of module ecgfil.c */
    FWM_CTRAXC      = 29,       /**< identifier of module ctraxc.c */
    FWM_CTRPOS      = 30,       /**< identifier of module ctrpos.c */
    FWM_CTRTSG      = 31,       /**< identifier of module ctrtsg.c */
    FWM_CTRSTATE    = 32,       /**< identifier of module ctrstate.c */
    FWM_CTRCLL      = 33,       /**< identifier of module ctrcll.c */
    FWM_CTRWNS      = 34,       /**< identifier of module ctrcll.c */
    FWM_CTRPFC      = 35,       /**< identifier of module ctrpfc.c */
    FWM_CTRPVL      = 36,       /**< identifier of module ctrpvl.c */
    FWM_UDCCTR      = 37,       /**< identifier of module udcctr.c */
    FWM_UDCDATA     = 38,       /**< identifier of module udcdata.c */
    FWM_PDSTRACE    = 39,       /**< identifier of module pdstrace.c */
    FWM_PDSMAS      = 40,       /**< identifier of module pdsmas.c */
    FWM_PDSMON      = 41,       /**< identifier of module pdsmon.c */
    FWM_CMLAXC      = 42,       /**< identifier of module cmlaxc.c */
    FWM_CMLCUIO     = 43,       /**< identifier of module cmlcuio.c */
    FWM_CMLAXIO     = 44,       /**< identifier of module cmlaxio.c */
    FWM_CMLMCU      = 45,       /**< identifier of module cmlmcu.c */
    FWM_GENSAMPLE   = 46,       /**< identifier of module gensample.c */
    FWM_GENSTATUS   = 47,       /**< identifier of module genstatus.c */
    FWM_GENCOM      = 48,       /**< identifier of module gencom.c */
    FWM_GENSUPPORT  = 49,       /**< identifier of module gensupport.c */
    FWM_NNIXISO     = 50,       /**< identifier of module nnixiso.c */
    FWM_NNIXASY     = 51,       /**< identifier of module nnixasy.c */
    FWM_NNIRISO     = 52,       /**< identifier of module nniriso.c */
    FWM_NNIRASY     = 53,       /**< identifier of module nnirasy.c */
    FWM_SQCMAIN     = 54,       /**< identifier of module sqcmain.c */
          /* not used 55 */
    FWM_PPIMAIN     = 56,       /**< identifier of module ppi.c */
    FWM_CTRTWK      = 57,       /**< identifier of module ctrtwk.c */
    FWM_CMLFLASH    = 58,       /**< identifier of module cmlflash.c */
    FWM_CMLPSI      = 59,       /**< identifier of module cmlpsi.c */
    FWM_CMLSDC      = 60,       /**< identifier of module cmlsdc.c */
    FWM_SPGFST      = 61,       /**< identifier of module spgfst.c */
    FWM_SPGFCL      = 62,       /**< identifier of module spgfcl.c */
    FWM_PDSLATCHSET = 63,       /**< identifier of module pdslatchset.c */
    FWM_PDSMAIN     = 64,       /**< identifier of module pdsmain.c */
    FWM_CMLDLC      = 65,       /**< identifier of module cmldlc.c */
    FWM_SPGPFC      = 66,       /**< identifier of module spgpfc.c */
    FWM_SPGCAR      = 67,       /**< identifier of module spgcar.c */
    FWM_NR_OF_FW_MODULES = 68   /**< @_nrOfEnumValues */

} NYCE_FW_MODULE_ID;

/** The definitions of parameter ids, variable ids, data ids, event ids, return codes
 * and asynchronous error codes use the definitions above. Values from the definitions
 * above are shifted and OR-ed to obtain these definitions. The  shift values used
 * are defined below. These definitions are and should be used outside this header file.
 * They are not used inside this header file to improve readability of the defined id-s.
 * When using the shift values defined below, this would result in very long lines.
 * Also, masks are defined to easily extract the information from an id.
 */

#define NYCE_ACCESS_SHIFT   31
#define NYCE_SUBSYS_SHIFT   25
#define NYCE_SLOT_SHIFT     21
#define NYCE_FWTYPE_SHIFT   18
#define NYCE_TEMP_READ_DOUBLE_SHIFT 17
#define NYCE_FWDIM_SHIFT    15
#define NYCE_FWMODULE_SHIFT 8


#define NYCE_ACCESS_MASK      ( (uint32_t) 1 << NYCE_ACCESS_SHIFT   )
#define NYCE_SUBSYS_MASK    ( ( (uint32_t) 1 << NYCE_ACCESS_SHIFT   ) - ( (uint32_t) ( 1 << NYCE_SUBSYS_SHIFT   ) ) )
#define NYCE_SLOT_MASK      ( ( (uint32_t) 1 << NYCE_SUBSYS_SHIFT   ) - ( (uint32_t) ( 1 << NYCE_SLOT_SHIFT     ) ) )
#define NYCE_FWTYPE_MASK    ( ( (uint32_t) 1 << NYCE_SLOT_SHIFT     ) - ( (uint32_t) ( 1 << NYCE_FWTYPE_SHIFT   ) ) )
#define NYCE_FWDIM_MASK     ( ( (uint32_t) 1 << NYCE_FWTYPE_SHIFT   ) - ( (uint32_t) ( 1 << NYCE_FWDIM_SHIFT    ) ) )
#define NYCE_FWMODULE_MASK  ( ( (uint32_t) 1 << NYCE_FWDIM_SHIFT    ) - ( (uint32_t) ( 1 << NYCE_FWMODULE_SHIFT ) ) )
#define NYCE_INDEX_MASK     ( ( (uint32_t) 1 << NYCE_FWMODULE_SHIFT ) - ( (uint32_t)   1 ) )

/**
 *  @brief  Retrieve the NYCE_SLOT_ID from a parameter, variable, data or event ID.
 *
 *  @param[in]  dataId_     parameter, variable, data or event ID.
 *
 *  @return     NYCE_SLOT_ID; The slot specified in dataId_.
 */
#define NYCE_SLOT_ID_FROM_DATA_ID(dataId_) \
    ((NYCE_SLOT_ID)(((dataId_) & NYCE_SLOT_MASK) >> NYCE_SLOT_SHIFT))

/** 
 *  @brief  Retrieve the slot independent parameter, variable, data or event ID.
 *
 *  NYCE_SLOT_MASK is removed from the data ID if NYCE_SLOT_ID_FROM_DATA_ID < NYCE_MCU_SLOT
 *
 *  @param[in]  dataId_     parameter, variable, data or event ID.
 *
 *  @return     dataId_ without NYCE_SLOT_MASK.
 */
#define NYCE_GET_SLOT_INDEPENDENT_DATA_ID(dataId_) \
    ((((dataId_) & (NYCE_MCU_SLOT << NYCE_SLOT_SHIFT)) == 0) ? ((dataId_) & (~NYCE_SLOT_MASK)): (dataId_))

/* Access properties are used for definitions of parameter, variable and data id */
#define RW  0                         /**< Read/write access */
#define RO  (uint32_t)(0x80000000)    /**< Read-only access */

/** Parameter and variable data type specification */
typedef enum nyce_data_type
{
    NYCE_DATA_TYPE_BOOLEAN,     /**< Boolean data type. */
    NYCE_DATA_TYPE_NUMERIC,     /**< Numeric data type. */
    NYCE_DATA_TYPE_ENUMERATED,  /**< Enumerated data type. */
    NYCE_DATA_TYPE_BITFIELD,    /**< Bitfield data type. */
    NYCE_DATA_TYPE_UNSPECIFIED  /**< Invalid data type. */
} NYCE_DATA_TYPE;

/**
* @}
*/

#endif
