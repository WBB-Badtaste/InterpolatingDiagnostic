/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2013
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000
//    Component Name: SUPPORT
//    Subsystem Name: DEH
//    %full_filespec:    dehtypes.h`5:incl:1 % (SYNERGY INFO, do not change)
//
//    Description   : Headerfile containing datatypes and defines for DEH.
 */

#ifndef __DEHTYPES_H_
#define __DEHTYPES_H_

/*-------------------------------------------------------------------------------------------------
 * GLOBAL INCLUDES
 *-------------------------------------------------------------------------------------------------
 */
#include "nycedefs.h"

/*-------------------------------------------------------------------------------------------------
 * GLOBAL DEFINES
 *-------------------------------------------------------------------------------------------------
 */

/* 
 * Make sure that the structure alignment is fixed
 */
#ifdef NT
#pragma pack(push)
#pragma pack(1)
#endif /* NT */

/*-----------------------------------------------------------------------
 * GLOBAL DEFINES
 *-----------------------------------------------------------------------
 */

/**
 * @defgroup deh Diagnostics and Error Handling (DEH)
 *
 * DEH offers logging and diagnostic functionality.
 *
 * @{
 */

/**
 * @defgroup deh_logging Logging
 *
 * DEH enables logging of information on function calls and events from NYCe4000 libraries at a selectable level. It also allows application to log strings.
 *
 * @{
 */

#define DEH_MAX_LOGMSG_SIZE         1024 /**< Maximum size in bytes of a message in the logging buffer. The message will be truncated when needed. */

/*-----------------------------------------------------------------------
 * GLOBAL DATA TYPES
 *-----------------------------------------------------------------------
 */
/**
    @brief  the log type that a logging is.
*/
typedef enum deh_log_type
{
    DEH_LOG_ENTRY           = 0x001,    /**< function entry */
    DEH_LOG_PRIPAR          = 0x002,    /**< primary parameters */
    DEH_LOG_SECPAR          = 0x004,    /**< secondary parameters */
    DEH_LOG_OUTPAR          = 0x008,    /**< output parameters */
    DEH_LOG_EXIT            = 0x010,    /**< function exit if the function returns without error  */
    DEH_LOG_ERROR_EXIT      = 0x020,    /**< function exit if the function returns an error */
    DEH_LOG_EVENT           = 0x040,    /**< event */
    DEH_LOG_ERROR           = 0x080,    /**< error */
    DEH_LOG_WARNING         = 0x100,    /**< warning */
    DEH_LOG_INFO            = 0x200,    /**< info */
    DEH_LOG_USER_MSG        = 0x400     /**< user message */

} DEH_LOG_TYPE;

/** @} */



/**
 *  @defgroup deh_conversion Conversion
 *
 *  The functions within this module convert strings to enumeration values and vice versa.
 */

/** @} */

/* 
 * Make sure that the structure alignment is restored
 */
#ifdef NT
#pragma pack(pop)
#endif /* NT */


#endif /*__DEHTYPES_H_*/

/*----- End of Module -----------------------------------------------------*/
