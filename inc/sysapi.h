/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2009
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000_SW
//    Component Name: HOSTSW
//    Subsystem Name: SYS
//    %full_filespec:    sysapi.h`49:incl:1 % (SYNERGY INFO, do not change)
//
//    Description   : Public interface to the SYS subsystem
*/

#ifndef __SYSAPI_H__
#define __SYSAPI_H__

#include "nycedefs.h"

#ifdef NT
#pragma pack(push)
#pragma pack() //use default
#endif

/**
 *  @defgroup sys System (SYS)
 *
 *  For the NYCe4000 users it includes an abstraction layer to part of the low level NCS functionality.
 *  The system from a user point of view can be represented as shown in the next figure. Starting at the top
 *  there is the system which controls a machine or robot. The system has properties which can be accessed
 *  through the SYS layer and contains nodes which form the middle layer. A node has properties and I/O
 *  which can be accessed through the NHI layer and has axes which form the bottom layer. An axis has
 *  properties and these can be accessed through the SAC layer.
 *
 *  @{
 */

#ifdef __cplusplus
    extern "C" {
#endif


/**
 * @defgroup sys_events Events
 *
 */

/**
 * @defgroup sys_configuration Configuration
 *
 */

/**
 * @defgroup sys_miscellaneous Miscellaneous
 *
 */



/* If SYS is defined, the functions are exported, otherwise they are imported */
#ifdef SYS
#define SYS_EXPORT __declspec(dllexport)
#else
#define SYS_EXPORT __declspec(dllimport)
#endif


/**
 *  @ingroup sys_miscellaneous
 *
 *  This struct defines the IEEE 1394b diagnostics which can be
 *  retrieved via SysGetFireWireDiagnostics and reset via
 *  SysResetFireWireDiagnostics.
 */
typedef struct sys_firewire_diagnostics
{
    uint32_t    readRequestCount;                   /**< Number of outgoing asynchronous read requests */
    uint32_t    readRequestFailedCount;             /**< Number of failed asynchronous read requests */
    uint32_t    readRequestRetryCount;              /**< Number of read request retries */
    uint32_t    readRetryExceededCount;             /**< Number of failed read requests after retrying exceeded*/

    uint32_t    writeRequestCount;                  /**< Number outgoing asynchronous write requests */
    uint32_t    writeRequestFailedCount;            /**< Number of failed asynchronous write requests */
    uint32_t    writeRequestRetryCount;             /**< Number of write request retries */
    uint32_t    writeRetryExceededCount;            /**< Number of failed write requests after retrying exceeded*/

} SYS_FIREWIRE_DIAGNOSTICS;



/**
 *  @addtogroup sys_configuration
 *
 *  @{
 */

/**
 *  @brief  Retrieve the sample time of the system.
 *
 *  The system sample time is equal to the sample time of the node with the lowest sample time.
 *
 *  @param[out] pSystemSampleTime       System sample time.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetSystemSampleTime(double* pSystemSampleTime);


/**
 *  @brief Retrieve the number of NYCe4000 nodes in the system.
 *
 *  @param[out] pNrOfNodes              Number of nodes.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetNrOfNodes(uint32_t* pNrOfNodes);


/**
 *  @brief  Retrieve the name of a node.
 *
 *  @param[in]  nodeNumber              Index of the node (0..nrOfNodes-1).
 *  @param[out] nodeName                size(NYCE_MAX_NAME_LENGTH); Name of the node.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetNodeName(uint32_t nodeNumber,
                                                      char nodeName[]);


/**
 *  @brief  Set the name of a node.
 *
 *  @param[in]  nodeNumber              Index of the node (0..nrOfNodes-1).
 *  @param[in]  pNodeName               New name for the node.
 *
 *  @remarks    The node name can contain up to NYCE_MAX_NAME_LENGTH
 *              characters including a zero terminator.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysSetNodeName(uint32_t nodeNumber,
                                                      const char* pNodeName);


/**
 *  @brief Retrieve the nodenumber of a node.
 *
 *  @param[in]  pNodeName               Name of the node.
 *  @param[out] pNodeNumber             Index of the node (0..nrOfNodes-1).
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetNodeNumber(const char* pNodeName,
                                                        uint32_t* pNodeNumber);


/**
 *  @brief  Retrieve the IP address of a node.
 *
 *  The returned address has the decimal dotted IPv4 format (a.b.c.d).
 *
 *  @param[in]  nodeNumber              Index of the node (0..nrOfNodes-1).
 *  @param[in]  nodeAddressLength       Buffer size of nodeAddress. A buffer size of 16 is enough to store any IPv4 address.
 *  @param[out] nodeAddress             size(nodeAddressLength); The node IP address.
 *
 *  @retval NYCE_OK                     Function executed successfully.
 *  @retval SYS_ERR_NOT_SUPPORTED       This function is not supported in a NYCE_FIWI network.
 *  @retval SYS_ERR_NODE_DOES_NOT_EXIST The nodeNumber is out of range.
 *  @retval SYS_ERR_INVALID_PARAMETER   The size of the nodeAddress buffer is too small to store the IP address.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetNodeAddress(uint32_t nodeNumber,
                                                         uint32_t nodeAddressLength,
                                                         char nodeAddress[]);


/**
 *  @brief Retrieve information on the firmware of a node.
 *
 *  @param[in]  nodeNumber              Index of the node (0..nrOfNodes-1).
 *  @param[out] pFirmwareInfo           Firmware information.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetFirmwareInfo(uint32_t nodeNumber,
                                                          NYCE_FIRMWARE_INFO* pFirmwareInfo);


/**
 *  @brief  Retrieve the status of a node.
 *
 *  @param[in]  nodeNumber              Index of the node (0..nrOfNodes-1).
 *  @param[out] pStatus                 Status of the node.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetNodeStatus(uint32_t nodeNumber,
                                                        NYCE_NODE_STATUS* pStatus);


/**
 *  @brief  Retrieve the serial number for a node.
 *
 *  @param[in]  nodeNumber              Index of the node (0..nrOfNodes-1).
 *  @param[out] pSerialNumber           Serial number of the node.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetNodeSerialNumber(uint32_t nodeNumber,
                                                              NYCE_SERIAL_NUMBER* pSerialNumber);


/**
 *  @brief  Retrieve the Motion Controller Unit type for a node.
 *
 *  @param[in]  nodeNumber              Index of the node (0..nrOfNodes-1).
 *  @param[out] pMcuType                MCU unit type of the node.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetMcuUnitType(uint32_t nodeNumber,
                                                         NYCE_MCU_UNIT_TYPE* pMcuType);


/**
 *  @brief  Check the system configuration.
 *
 *  This function checks if:
 *   -   node names are valid
 *   -   node names are unique
 *   -   axis names are valid
 *   -   axis names are unique
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysCheckConfiguration(void);


/**
 *  @brief  Retrieve the unit type for a drive in a node.
 *
 *  @param[in]  sysNodeNr               Index of the node (0..nrOfNodes - 1).
 *  @param[in]  slotId                  Slot ID of the drive.
 *  @param[out] pDriveUnitType          Drive unit type.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetDriveUnitType(uint32_t sysNodeNr,
                                                           NYCE_SLOT_ID slotId,
                                                           NYCE_UNIT_TYPE* pDriveUnitType);

/** @} */



/**
 *  @addtogroup sys_events
 *
 *  @{
 */

/**
 *  @brief  Register an event enrolment. When the system-event occurs, the handlerFunction is called.
 *
 *  @param[in] eventId                  Event on which the enrolment is to be defined.
 *  @param[in] handlerFunction          Callback function.
 *  @param[in] pUserData                Data the user can pass to SYS. The userData will be brought
 *                                      back when the enrolment function is called.
 *
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysDefineEventEnrolment(NYCE_EVENT eventId,
                                                               NYCE_EVENT_HANDLER handlerFunction,
                                                               void* pUserData);


/**
 *  @brief  Unregister an event enrolment.
 *
 *  @param[in] eventId                  Event on which the enrolment is to be defined.
 *  @param[in] handlerFunction          Callback function.
 *  @param[in] pUserData                Data the user can pass to SYS. The userData will be brought
 *                                      back when the enrolment function is called.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysDeleteEventEnrolment(NYCE_EVENT eventId,
                                                               NYCE_EVENT_HANDLER handlerFunction,
                                                               void* pUserData);

/** @} */



/**
 *  @addtogroup sys_miscellaneous
 *
 *  @{
 */

/**
 *  @brief  Retrieve the version of the SYS subsystem.
 *
 *  @param[out] pVersion                Version of the SYS subsystem.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetVersion(NYCE_VERSION_TYPE* pVersion);


/**
 *  @brief Reset all nodes synchronized.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysResetNodes(void);


/**
 *  @brief  Resets a node.
 *
 *  @param[in] nodeNumber               Index of the node (0..nrOfNodes-1).
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysResetNode(uint32_t nodeNumber);


/**
 *  @brief  Start or stop blinking the led of a node.
 *
 *  @param[in]  nodeNumber              Index of the node (0..nrOfNodes-1).
 *  @param[in]  blink                   FALSE: stop blinking / TRUE:  start blinking.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysBlinkNode(uint32_t nodeNumber,
                                                    BOOL blink);


/**
 *  @brief  Retrieve IEEE1394b diagnostic information from the HNI driver.
 *
 *  @param[out] pFireWireDiagnostics    IEEE1394b diagnostic information.
 *
 *  @retval NYCE_OK             Function executed successfully.
 *  @retval SYS_ERR_NO_NODES    At least one node must be present to retrieve any diagnostics.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysGetFireWireDiagnostics(SYS_FIREWIRE_DIAGNOSTICS* pFireWireDiagnostics);


/**
 *  @brief  Reset the counters of the firewire diagnostics in the HNI driver.
 *
 *  @retval NYCE_OK             Function executed successfully.
 *  @retval SYS_ERR_NO_NODES    At least one node must be present to change any diagnostics.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysResetFireWireDiagnostics(void);


/**
 *  @brief  Enable or disable the sequence bootstrap.
 *
 *  @param[in]  sysNodeNr               Drive node number (0..nrOfNodes - 1).
 *  @param[in]  enable                  Enable/disable flag.
 */
extern SYS_EXPORT NYCE_STATUS NYCE_API SysEnableSeqBootstrap(uint32_t sysNodeNr,
                                                             BOOL enable);

/** @} */

#ifdef __cplusplus
    }
#endif

/** @} */

#ifdef NT
#pragma pack(pop)
#endif

#endif  /* __SYSAPI_H__ */
