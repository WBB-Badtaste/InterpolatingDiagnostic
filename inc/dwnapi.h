/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2009
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000
//    Component Name: hostsw
//    Subsystem Name: dwn
//    %full_filespec:    dwnapi.h`21.1.12:incl:1 % (SYNERGY INFO, do not change)
//
//    Description   : External interface of DWN library
*/

#ifndef __DWNAPI_H__
#define __DWNAPI_H__

/*-------------------------------------------------------------------------------------------------
 * GLOBAL INCLUDES
 *-----------------------------------------------------------------------------------------------*/
#include "nycedefs.h"
#include "dwntypes.h"

#ifdef NT
#pragma pack(push)
#pragma pack() //use default
#endif

/**
 *  @addtogroup dwn
 *
 *  @{
 */

/*-------------------------------------------------------------------------------------------------
 * GLOBAL DEFINES
 *-----------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
 * GLOBAL DATA TYPES
 *-----------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------
 * EXPORTED FUNCTIONAL PROTOTYPES
 *-----------------------------------------------------------------------------------------------*/

#ifdef __cplusplus
    extern "C" {
#endif

/* If DWN is defined, the functions are exported, otherwise they are imported */
#ifdef DWN_EXPORT
#undef DWN_EXPORT
#endif

#ifdef DWN
#define DWN_EXPORT __declspec(dllexport)
#else
#define DWN_EXPORT __declspec(dllimport)
#endif

/**
 *
 * @ingroup dwn_miscellaneous
 * @brief DwnGetVersion
 *
 * This function can be used to retrieve the version information of the DWN subsystem.
 *
 * @param [out] pVersion - Pointer to a NYCE_VERSION_TYPE struct where the version information is
 *                     stored on completion.
 *
 * @remarks none
 */
DWN_EXPORT NYCE_STATUS NYCE_API DwnGetVersion(NYCE_VERSION_TYPE *pVersion);


/**
 *
 * @ingroup dwn_firmware_gateware
 * @brief DwnDownloadPrimaryBoot
 *
 *  This function can be used to download a new primary boot image, including DSP
 *  gateware.
 *
 * @param [in] nodeNr           - Number of the node in the network to download the primary boot image to.
 *                                This number is between 0 and the number of nodes in the network - 1.
 *                                The number of nodes in the network is returned by a call to the SYS function
 *                                \ref SysGetNrOfNodes.
 * @param [in] priBootFileName  - Name of the file containing the primary boot image to download.
 *
 * @remarks Use this function with care and only when needed. When the function fails while the download operation
 *          is in progress, the MCU becomes unusable. This function might block the calling thread several seconds.
 */
DWN_EXPORT NYCE_STATUS NYCE_API DwnDownloadPrimaryBoot(uint32_t     nodeNr,
                                                       const char   *priBootFileName);


/**
 *
 * @ingroup dwn_firmware_gateware
 * @brief DwnDownloadFirmware
 *
 *  This function can be used to download a new firmware image to the node.
 *
 * @param [in] nodeNr           - Number of the node in the network to download the firware image to.
 *                                This number is between 0 and the number of nodes in the network - 1.
 *                                The number of nodes in the network is returned by a call to the SYS function
 *                                \ref SysGetNrOfNodes.
 * @param [in] firmwareFileName - Name of the file containing the firmware image to download.
 *
 * @remarks This function might block the calling thread several seconds.
 */
DWN_EXPORT NYCE_STATUS NYCE_API DwnDownloadFirmware(uint32_t    nodeNr,
                                                    const char  *firmwareFileName);



/**
 *
 * @ingroup dwn_firmware_gateware
 * @brief DwnEraseGateware
 *
 *  This function can be used to erase all the drive gateware images on the node.
 *
 * @param [in] nodeNr           - Number of the node in the network to erase all drive gateware images of.
 *                                This number is between 0 and the number of nodes in the network - 1.
 *                                The number of nodes in the network is returned by a call to the SYS function
 *                                \ref SysGetNrOfNodes.
 *
 * @remarks none
 */
DWN_EXPORT NYCE_STATUS NYCE_API DwnEraseGateware(uint32_t nodeNr);



/**
 *
 * @ingroup dwn_firmware_gateware
 * @brief DwnDownloadGateware
 *
 *  This function can be used to download a drive gateware image to a specific bank in
 *          the flash memory of the node.
 *
 * @param [in] nodeNr           - Number of the node in the network to download the gateware image to.
 *                                This number is between 0 and the number of nodes in the network - 1.
 *                                The number of nodes in the network is returned by a call to the SYS function
 *                                \ref SysGetNrOfNodes.
 * @param [in] bankNr           - Specifies the bank number in flash memory, valid bank numbers are 0, 1 and 2.
 * @param [in] gatewareFileName - Name of the file containing the gateware image to download.
 *
 * @remarks The NY4125 gateware image requires 2 banks, thus can only be loaded in bank 0 or 1.
 */
DWN_EXPORT NYCE_STATUS NYCE_API DwnDownloadGateware(uint32_t    nodeNr,
                                                    uint32_t    bankNr,
                                                    const char  *gatewareFileName);

/**
 *
 * @ingroup dwn_firmware_gateware
 * @brief DwnDowngradeFlash
 *
 *  This function can be used to downgrade the flash memory contents to an absolute minimum required.
 *  The only data that is stored in the flash memory is:
 *    - defined primary boot image
 *  After a node reset the flash configuration data is initialized with:
 *    - default node name: NY411x_node
 *    - default sample time: 0.001 s
 *
 * @param [in] nodeNr           - Number of the node in the network to downgrade the flash memory contents of.
 *                                This number is between 0 and the number of nodes in the network - 1.
 *                                The number of nodes in the network is returned by a call to the SYS function
 *                                \ref SysGetNrOfNodes.
 * @param [in] priBootFileName  - Name of the file containing the primary boot image to download.
 *
 * @remarks none
 */
DWN_EXPORT NYCE_STATUS NYCE_API DwnDowngradeFlash(uint32_t      nodeNr,
                                                  const char    *priBootFileName);


/**
 *
 * @ingroup dwn_microware_sercongateware
 * @brief DwnDownloadMicroware
 *
 *  This function can be used to download a new microware image to the NY4150 in the node.
 *
 * @param [in] nodeNr            - Number of the node in the network to download the microware image to.
 *                                This number is between 0 and the number of nodes in the network - 1.
 *                                The number of nodes in the network is returned by a call to the SYS function
 *                                \ref SysGetNrOfNodes.
 * @param [in] microwareFileName - Name of the file containing the microware image to download.
 *
 * @remarks This function might block the calling thread several seconds.
 */
DWN_EXPORT NYCE_STATUS NYCE_API DwnDownloadMicroware(uint32_t    nodeNr,
                                                     const char  *microwareFileName);

/**
 *
 * @ingroup dwn_microware_sercongateware
 * @brief DwnDownloadSerconGateware
 *
 *  This function can be used to download a new SERCON100M FPGA image to the NY4150 in the node.
 *
 * @param [in] nodeNr            - Number of the node in the network to download the SERCON100M FPGA image to.
 *                                This number is between 0 and the number of nodes in the network - 1.
 *                                The number of nodes in the network is returned by a call to the SYS function
 *                                \ref SysGetNrOfNodes.
 * @param [in] sercongatewareFileName - Name of the file containing the SERCON100M FPGA image to download.
 *
 * @remarks This function might block the calling thread several seconds.
 */
DWN_EXPORT NYCE_STATUS NYCE_API DwnDownloadSerconGateware(uint32_t    nodeNr,
                                                          const char  *sercongatewareFileName);

/**
 *  @ingroup dwn_flash_data_handling
 *
 *  @brief Save flash data from flash to file.
 *
 *  @param [in]  sysNodeNr       SYS node number of node to save sequence flash data to.
 *  @param [in]  flashDataType   Flash data type to save.
 *  @param [in]  pFileName       File to save to.
 */
DWN_EXPORT NYCE_STATUS NYCE_API DwnSaveFlashDataTypeToFile(uint32_t sysNodeNr,
                                                           DWN_FLASH_DATA_TYPE flashDataType,
                                                           const char* pFileName);
/**
 *  @ingroup dwn_flash_data_handling
 *
 *  @brief Load flash data from file to flash.
 *
 *  @param [in]  sysNodeNr      SYS node number of node to save sequence flash data to.
 *  @param [in]  flashDataType  Flash data type to load.
 *  @param [in]  pFileName      File to load from.
 */
DWN_EXPORT NYCE_STATUS NYCE_API DwnLoadFlashDataTypeFromFile(uint32_t sysNodeNr,
                                                             DWN_FLASH_DATA_TYPE flashDataType,
                                                             const char* pFileName);

/**
 *  @ingroup dwn_miscellaneous
 *
 *  @brief Check if node is upgradeable.
 *
 *  @param [in]  sysNodeNr                    SYS node number of node to check.
 *  @param [in]  upgradeType                  Upgrade type to check.
 *  @param [in]  upgradeVersion               Upgrade version to be upgraded to.
 *  @param [in]  bCheckAreSequencesRunning    Check for running sequences flag.
 */
DWN_EXPORT NYCE_STATUS NYCE_API DwnIsNodeUpgradeable(uint32_t sysNodeNr,
                                                     DWN_UPGRADE_TYPE upgradeType,
                                                     NYCE_VERSION_TYPE upgradeVersion,
                                                     BOOL bCheckAreSequencesRunning);

#ifdef __cplusplus
    }
#endif

/** @} */

#ifdef NT
#pragma pack(pop)
#endif

#endif /* __DWNAPI_H__ */

