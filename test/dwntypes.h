/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2013
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: DWN
 *  %full_filespec: dwntypes.h`6:incl:1 %
 */
/**
 *  @file
 *  @brief  headerfile containing datatypes and defines for DWN.
 */
#ifndef __DWNTYPES_H__
#define __DWNTYPES_H__

#include "nycedefs.h"

#ifdef NT
#pragma pack(push)
#pragma pack() //use default
#endif


/**
 *  @defgroup dwn Download (DWN)
 *
 *  The download api offers functions to download flash data like firmware, microware or gateware to the nodes,
 *  and upload flash data to a file.
 *
 *  @{
 */

/**
 *  @defgroup dwn_flash_data_handling Flash Data Handling
 *
 *  @brief  Transporting data to and from flash.
 *
 * @{
 */

/**
 *  @brief  Flash data type.
 */
typedef enum dwn_flash_data_type
{
    /* Don't change the enumeration order to ensure backwards compatibility */
    DWN_FLASH_ALL,              /**< All flash data */
    DWN_FLASH_CONFIG_DATA,      /**< Node and axis configuration data */
    DWN_FLASH_SEQ_BOOTSTRAP,    /**< Sequence flash bootstrap */
    DWN_FLASH_SEQ_USER_DATA,    /**< Sequence flash user data */
    DWN_FLASH_NHI_USER_DATA,    /**< NHI flash user data */
    DWN_FLASH_AUTOTWEAK_DATA,   /**< Autotweak data */
    DWN_FLASH_BOOTLOADER,       /**< Bootloader */
    DWN_FLASH_FIRMWARE,         /**< Firmware */
    DWN_FLASH_NODE_GATEWARE     /**< Node gatewares */

} DWN_FLASH_DATA_TYPE;

/** @} */



/**
 *  @defgroup dwn_firmware_gateware Bootloader / Firmware / Gateware
 *
 *  The function DwnEraseGateware removes the drive gateware image from the node
 *  after which another drive gateware image can be downloaded using
 *  \ref DwnDownloadGateware. After the updated drive gateware is downloaded to
 *  the node, \ref DwnDownloadFirmware should be called to download the
 *  accompanying firmware file.
 */



/**
 *  @defgroup dwn_microware_sercongateware Microware / SerconGateware
 *
 *  The function DwnDownloadMicroware downloads the microware and
 *  the function DwnDownloadSerconGateware downloads the SERCON100M FPGA image
 *  into the flash memory of the NY4150 module.
 */



/**
 *  @defgroup dwn_miscellaneous Miscellaneous
 *
 *  @{
 */

/**
 *  @brief  Upgrade type.
 */
typedef enum dwn_upgrade_type
{
    /* Don't change the enumeration order to ensure backwards compatibility */
    DWN_UPGRADE_ALL,            /**< Upgrade all versions */
    DWN_UPGRADE_MICRO,          /**< Upgrade micro versions only */
    DWN_UPGRADE_MINOR,          /**< Upgrade minor and micro versions only */
    DWN_UPGRADE_MAJOR           /**< Upgrade major, minor and micro versions only */

} DWN_UPGRADE_TYPE;

/** @} */



/**
 *  @defgroup dwn_conversion Conversion
 *
 *  The functions within this module convert strings to enumeration values and vice versa.
 */

/** @} */

#ifdef NT
#pragma pack(pop)
#endif

#endif // __DWNTYPES_H__
