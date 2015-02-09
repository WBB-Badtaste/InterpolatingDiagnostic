/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2009-2012
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000
//    Component Name: hostsw
//    Subsystem Name: sim
//    %full_filespec:    simapi.h`70.1.5.1.2:incl:1 % (SYNERGY INFO, do not change)
//
//    Description   : Public interface to the SIM subsystem
*/

#ifndef __SIMAPI_H__
#define __SIMAPI_H__

/*-----------------------------------------------------------------------
 * GLOBAL INCLUDES
 *-----------------------------------------------------------------------*/
#include "n4k_deprecated.h" //lint !e451
#include "nycedefs.h"

#ifdef NT
#pragma pack(push)
#pragma pack() //use default
#endif


/**
 * @defgroup sim Simulation (SIM)
 *
 * A NYCe4000 application can be executed in simulation mode. This means that all application software
 * can be executed without hardware. Additional functions, declared
 * in this header file, simulate digital and analog node inputs. 
 *
 * @{
 */

/**
 * @defgroup sim_configuration Configuration
 *
 * These functions configure the simulated environment.
 *
 */

/**
 * @defgroup sim_node_level Node
 *
 * These functions simulate the environment at the node level.
 *
 */

/**
 * @defgroup sim_drive_level Drive
 *
 * These functions simulate the environment at the drive level.
 *
 */

/**
 * @defgroup sim_indra_drive_level IndraDrive
 *
 * These functions simulate the environment at the IndraDrive level.
 *
 */

/**
 * @defgroup sim_axis_level Axis
 *
 * These functions simulate the environment at the axis level.
 *
 */

/**
 * @defgroup sim_sdc Serial Data Channel
 *
 * These functions simulate the Serial Data Channel.
 *
 */

/**
 * @defgroup sim_conversion Conversion
 *
 * The functions within this module convert strings to enumeration values and vice versa.
 *
 */

/*-----------------------------------------------------------------------
 * GLOBAL DEFINES
 *-----------------------------------------------------------------------*/

#ifdef __cplusplus
    extern "C" {
#endif

/* If SIMAPI is defined, the functions are exported, otherwise they are imported */
#ifdef SIM
#define SIM_EXPORT __declspec(dllexport)
#else
#define SIM_EXPORT __declspec(dllimport)
#endif


typedef uint32_t   SIM_NODE;        /**< Node identifier. */

#define SIM_INVALID_ID (SIM_NODE)NYCE_MAX_NR_OF_NODES   /**< The invalid node id identifier */


/*-----------------------------------------------------------------------
 * GLOBAL DATA TYPES
 *-----------------------------------------------------------------------*/

/**
 *  @ingroup sim_sdc
 *
 *  This enumeration defines serial data channel memory block identifiers.
 */
typedef enum sim_sdc_memory_block_id
{
    SIM_SDC_ENDAT_OPERATING_STATUS,           
    SIM_SDC_ENDAT_MANUFACTURER_PARS1,        
    SIM_SDC_ENDAT_MANUFACTURER_PARS2,        
    SIM_SDC_ENDAT_MANUFACTURER_PARS3,       
    SIM_SDC_ENDAT_OPERATING_PARS,           
    SIM_SDC_ENDAT_OEM_BLOCK1,               
    SIM_SDC_ENDAT_OEM_BLOCK2,               
    SIM_SDC_ENDAT_OEM_BLOCK3,               
    SIM_SDC_ENDAT_COMPENSATION_VALUES,

    SIM_SDC_MAX_NR_OF_MEMORY_BLOCK_IDS      /**< @_nrOfEnumValues */

} SIM_SDC_MEMORY_BLOCK_ID;


/**
 *  @ingroup sim_sdc
 *
 *  This enumeration defines all serial data channel communication errors.
 */
typedef enum sim_sdc_communication_error
{
    SIM_SDC_NO_COMMUNICATION_ERROR = 0,
    SIM_SDC_CRC_ERROR,
    SIM_SDC_TIMEOUT_ERROR,

    SIM_SDC_MAX_NR_OF_COMMUNICATION_ERRORS  /**< @_nrOfEnumValues */

} SIM_SDC_COMMUNICATION_ERROR;

/**
 *  @ingroup sim_sdc
 *
 *   This enumeration defines all serial data channel port identifiers.
 */
typedef enum sim_sdc_port_id
{
    SIM_SDC_PORT0 = 0,
    SIM_SDC_PORT1,

    SIM_SDC_MAX_NR_OF_PORTS         /**< @_nrOfEnumValues */

} SIM_SDC_PORT_ID;

/**
    Digital I/O state.
*/
typedef enum dig_io_state
{
    IO_STATE_LOW = 0,
    IO_STATE_HIGH

} DIG_IO_STATE;

/**
    Color of a led on a simulated board.
*/
typedef enum led_color
{
    LED_OFF = 0,
    LED_RED,
    LED_GREEN,
    LED_ORANGE

} LED_COLOR;

/**
    Structure containing the color of both leds on a a simulated board.
*/
typedef struct led_status
{
    LED_COLOR leftLED;
    LED_COLOR rightLED;

} LED_STATUS;

/**
    Simulated possible axis alarms
*/
typedef enum sim_axis_alarm
{
    SIM_CABLE_ALARM                 = 1,
    SIM_PHASE_ALARM                 = 2,
    SIM_HALL_SENSOR_INVALID         = 4

} SIM_AXIS_ALARM;

/**
    Structure containing the simulated axis currents.
*/
typedef struct sim_axis_current
{
    double          id;
    double          iq;

} SIM_AXIS_CURRENT;


/**
 *  This structure identifies a simulated SERCOS device. 
 *
 *  Currently supported SERCOS devices are the IndraDrive C Advanced and IndraDrive Cs, 
 *  which can be simulated in the NYCe4000 simulation.
 *  Simulated IndraDrives are defined in an ordered list, which resembles the SERCOS network for a 
 *  given SERCOS III Master module (NY4150).
 *  The SERCOS III Master module is identified using the slotId member. 
 *  The SERCOS device is identified using the deviceId member.
 */
typedef struct sim_sercos_device_id
{
    NYCE_SLOT_ID    slotId;     /**< The slot id of the SERCOS III Master module to which this SERCOS device is attached. */
    uint32_t        deviceId;   /**< The zero based index of the simulated SERCOS device. */

}SIM_SERCOS_DEVICE_ID;


/**
 *  The state of an IndraDrive.
 */
typedef enum sim_indra_drive_state
{
    SIM_INDRA_DRIVE_STATE_PM,   /**< PM state: Parameter Mode (also final startup state in simulation). 
                                     No axis is currently configured for the IndraDrive.*/
    SIM_INDRA_DRIVE_STATE_BB,   /**< bb state: drive is not locked and drive power off. */
    SIM_INDRA_DRIVE_STATE_AB,   /**< Ab state: drive is not locked and drive power is on. */
    SIM_INDRA_DRIVE_STATE_AF,   /**< AF state: drive is locked (implies that the drive power is on). */
    SIM_INDRA_DRIVE_STATE_ERROR /**< Error state: the IndraDrive has a fatal error or fatal warning. */

} SIM_INDRA_DRIVE_STATE;


/**
    Structure containing the input data.
*/
typedef struct sim_plant_input
{
    int32_t         setpointDisplacements;
    float           ctrlOut;
    float           sampleTime;

} SIM_PLANT_INPUT;

/**
    Structure containing the input state.
*/
typedef struct sim_plant_state
{
    /** Axis position in [increments].
      * Not necessarily an integral value.
      * This member contains the previous position on callback entry.
      * Update this member with the new axis position. */
    double  position;

    /** Velocity of the axis in [increments/s].
      * When the plant handler function is called, this member contains the previous velocity.
      * Update this member with the new axis velocity. */
    double  velocity;

    /** If this flag is FALSE on callback entry, the firmware is armed for latching the index position.
      * Set this value to TRUE when the index position is reached and set indexCounter to the latched index position. */
    BOOL    indexLatched;
   
    /** Voltage level of the simulated index pulse on SinCos encoders. Set this flag to TRUE when the axis position is inside the  
      * boundaries of the index pulse. */
    BOOL indexActive; 

    /** The axis position in [increments] when the index occurred.
      * Note that the returned index position should be in the range from the previous position 
      * to the new returned axis position position */
    int32_t indexCounter;

    /** Bits 0..3 are flags for S0S90 Markers 0..3. The bits are set when the marker position has been crossed.  */
    uint32_t s0s90MarkersDetected;

} SIM_PLANT_STATE;

/**
    Structure containing the input constants.
*/
typedef struct sim_plant_const
{
    double          km;
    double          mass;
    double          damping;

} SIM_PLANT_CONST;

/**
 *  @brief  Prototype for a position callback function.
 *
 *  With this function it is possible to implement user-defined behavior for a simulation axis.
 *
 *  @param[in]     nodeNr       Node number.
 *  @param[in]     pAxisUnit    Axis unit.
 *  @param[in]     pPlantInput  Axis input data.
 *  @param[in,out] pPlantState  Axis state.
 */
typedef void (*SIM_PLANT_HANDLER)(uint32_t                  nodeNr,
                                  const NYCE_AXIS_UNIT_ID   *pAxisUnit,
                                  const SIM_PLANT_INPUT     *pPlantInput,
                                  SIM_PLANT_STATE           *pPlantState);


/*-----------------------------------------------------------------------
 * EXPORTED FUNCTIONAL PROTOTYPES
 *-----------------------------------------------------------------------*/


/**
 *
 * @ingroup sim_node_level
 * @brief SimAttachNode
 *
 * This function adds a node to the simulated network.
 * The configuration of this node is contained in the file with the
 * name pFileName. This file contains the name of the flash-image,
 * the EEProm image and the number and type of the mounted drive modules.
 *
 * @param [in] pFileName                       - Name of the file that contains
 *                                               the node configuration.
 * @param [in] nodeNr                          - Number of the node inside the
 *                                               configuration file.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimAttachNode(const char    *pFileName, 
                                              uint32_t      nodeNr);



/**
 *
 * @ingroup sim_node_level
 * @brief SimDetachNode
 *
 * This function removes a node from the simulated network.
 *
 * @param [in] nodeId                         - Id of the node inside the simulated.
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDetachNode(SIM_NODE nodeId);



/**
 *
 * @ingroup sim_node_level
 * @brief SimGetNrOfNodes
 *
 * This function gets the number of simulated nodes that are present in the network.
 *
 * @param [out] pNrOfNodes                      - Number of nodes that are available in the network.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetNrOfNodes(uint32_t *pNrOfNodes);



/**
 *
 * @ingroup sim_node_level
 * @brief SimGetNodeName
 *
 * This function gets the name of a simulated node that is present in the network.
 *
 * @param [in]  nodeNr                          - Number of the node to get the name from.
 * @param [out] nodeName                        - size(NYCE_MAX_NAME_LENGTH); Name of the node.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetNodeName(uint32_t nodeNr,
                                               char     nodeName[]);



/**
 *
 * @ingroup sim_node_level
 * @brief SimConnect
 *
 * This function establishes a logical connection between a running simulated node and a calling client.
 *
 * @param [in]  nodeName                    - The name of the node.
 *
 * @param [out] pNodeId                     - Node id.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimConnect(const char   *nodeName,
                                           SIM_NODE     *pNodeId);


/**
 *
 * @ingroup sim_node_level
 * @brief SimDisconnect
 *
 * This function removes a logical connection between a running simulated node and a calling client.
 *
 * @param [in]  nodeId                      - Node id.
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDisconnect(SIM_NODE  nodeId);


/**
 *
 * @ingroup sim_node_level
 * @brief SimGetNrOfUnits
 *
 * This function gets the number of physical units mounted into the slots. It does
 * not say anything about the positions of the units in the slots.
 *
 * @param [in] nodeId                       - The node id to get the number of units of.
 *
 * @param [out] pNrOfUnits                  - Number of physical units that are mounted in
 *                                            the slots.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetNrOfUnits(SIM_NODE    nodeId,
                                                uint32_t    *pNrOfUnits);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimGetUnitType
 *
 * This function gets the unit type of a unit at a specified slot position.
 *
 * @param [in] nodeId                           - The node id to get the unit type on.
 * @param [in] slotId                           - Id of the slot to get the unit type on.
 *
 * @param [out] pUnitType                       - Type of the unit at the specified slot position
 *                                                or NYCE_NO_UNIT if empty.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetUnitType(SIM_NODE         nodeId,
                                               NYCE_SLOT_ID     slotId,
                                               NYCE_UNIT_TYPE   *pUnitType);


/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLGetNrOfSercosDevices
 *
 * This function gets the number of connected SERCOS devices for a given SERCOS III Master module.
 *
 * @param [in] nodeId                           - The node id which has the SERCOS III Master module.
 * @param [in] slotId                           - The slot id for the SERCOS III Master module.
 *
 * @param [out] pNrOfSercosDevices              - The returned number of connected SERCOS devices.
 *                                                   
 * @remarks None
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLGetNrOfSercosDevices(SIM_NODE          nodeId,
                                                          NYCE_SLOT_ID      slotId,
                                                          uint32_t          *pNrOfSercosDevices);

/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLGetSercosDeviceType
 *
 * This function gets the device type of a specified SERCOS device.
 *
 * @param [in] nodeId                           - The node id to which the SERCOS device is connected.
 * @param [in] sercosDeviceId                   - The SERCOS device connection. 
 *
 * @param [out] pSercosDeviceType               - The returned SERCOS device type of the specified device.
 *                                                   
 * @remarks None
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLGetSercosDeviceType(SIM_NODE                   nodeId,
                                                         SIM_SERCOS_DEVICE_ID       sercosDeviceId,   
                                                         NYCE_SERCOS_DEVICE_TYPE    *pSercosDeviceType);

/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLGetIndraDriveState
 *
 * This function gets the state of an IndraDrive. 
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 *
 * @param [out] pIndraDriveState                - The returned state of the IndraDrive.
 * 
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLGetIndraDriveState(SIM_NODE                nodeId,
                                                        SIM_SERCOS_DEVICE_ID    sercosDeviceId,
                                                        SIM_INDRA_DRIVE_STATE   *pIndraDriveState);


/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLGetDigitalInput
 *
 * This function gets the state of a given digital input of an IndraDrive.
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 * @param [in] digIONr                          - Specifies the digital IO.
 *
 * @param [out] pInputState                     - The returned state of the digital input.
 *                                                   
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLGetDigitalInput(SIM_NODE                   nodeId,
                                                     SIM_SERCOS_DEVICE_ID       sercosDeviceId,
                                                     NYCE_DIG_IO_NR             digIONr,
                                                     DIG_IO_STATE               *pInputState);

/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLSetDigitalInput
 *
 * This function sets the state for a given digital input of an IndraDrive.
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 * @param [in] digIONr                          - Specifies the digital IO.
 * @param [in] inputState                       - The new state for the digital input.
 *                                                   
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLSetDigitalInput(SIM_NODE                   nodeId,
                                                     SIM_SERCOS_DEVICE_ID       sercosDeviceId,
                                                     NYCE_DIG_IO_NR             digIONr,
                                                     DIG_IO_STATE               inputState);


/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLGetDigitalOutput
 *
 * This function gets the state of a given digital output of an IndraDrive.
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 * @param [in] digIONr                          - Specifies the digital IO.
 *
 * @param [out] pOutputState                    - The returned state of the digital output.
 *                                                   
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLGetDigitalOutput(SIM_NODE                   nodeId,
                                                      SIM_SERCOS_DEVICE_ID       sercosDeviceId,
                                                      NYCE_DIG_IO_NR             digIONr,
                                                      DIG_IO_STATE               *pOutputState);



/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLGetAnalogInput
 *
 * This function gets the voltage of a given analog input of an IndraDrive.
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 * @param [in] anInNr                           - Specifies the analog input.
 *
 * @param [out] pInputVoltage                   - The returned voltage of the analog input.
 *                                                   
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLGetAnalogInput(SIM_NODE                   nodeId,
                                                    SIM_SERCOS_DEVICE_ID       sercosDeviceId,
                                                    uint32_t                   anInNr,
                                                    double                     *pInputVoltage);

/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLSetAnalogInput
 *
 * This function sets the value for a given analog input of an IndraDrive.
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 * @param [in] anInNr                           - Specifies the analog input.
 * @param [in] inputVoltage                     - The new value for the analog input.
 *                                                   
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLSetAnalogInput(SIM_NODE                   nodeId,
                                                    SIM_SERCOS_DEVICE_ID       sercosDeviceId,
                                                    uint32_t                   anInNr,
                                                    double                     inputVoltage);


/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLGetAnalogOutput
 *
 * This function gets the voltage of a given analog output of an IndraDrive.
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 * @param [in] anOutNr                          - Specifies the analog output.
 *
 * @param [out] pOutputVoltage                  - The returned voltage of the analog output.
 *                                                   
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLGetAnalogOutput(SIM_NODE                   nodeId,
                                                     SIM_SERCOS_DEVICE_ID       sercosDeviceId,
                                                     uint32_t                   anOutNr,
                                                     double                     *pOutputVoltage);


/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLGetAxisCurrent
 *
 * This function gets the drive and quiescent current of an IndraDrive.
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 *
 * @param [out] pAxisCurrent                    - The returned drive and quiescent current of the IndraDrive.
 * 
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLGetAxisCurrent(SIM_NODE                   nodeId,
                                                    SIM_SERCOS_DEVICE_ID       sercosDeviceId,
                                                    SIM_AXIS_CURRENT           *pAxisCurrent);


/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLSetAxisCurrent
 *
 * This function sets the drive and quiescent current for a given IndraDrive.
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 * @param [in] pAxisCurrent                     - The new drive and quiescent current.
 * 
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLSetAxisCurrent(SIM_NODE                   nodeId,
                                                    SIM_SERCOS_DEVICE_ID       sercosDeviceId,
                                                    const SIM_AXIS_CURRENT     *pAxisCurrent);


/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLGetIndraDriveErrorCode
 *
 * This function gets the current error code of an IndraDrive. 
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 *
 * @param [out] pErrorCode                      - The returned error code of the IndraDrive.
 * 
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLGetIndraDriveErrorCode(SIM_NODE                nodeId,
                                                            SIM_SERCOS_DEVICE_ID    sercosDeviceId,
                                                            uint32_t                *pErrorCode);


/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLSetIndraDriveErrorCode
 *
 * This function sets an error code for an IndraDrive. 
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 * @param [in] errorCode                        - The new error code for the IndraDrive. Use zero to clear the error.
 * 
 * @remarks The IndraDrive error code can only be changed if the state of the IndraDrive is not @ref SIM_INDRA_DRIVE_STATE_PM.
 *          If the state is @ref SIM_INDRA_DRIVE_STATE_PM, the error SIM_ERR_INVALID_INDRADRIVE_STATE will be returned.
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLSetIndraDriveErrorCode(SIM_NODE                nodeId,
                                                            SIM_SERCOS_DEVICE_ID    sercosDeviceId,
                                                            uint32_t                errorCode);



/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLGetDrivePowerState
 *
 * This function gets the state of the drive power of an IndraDrive. 
 * The power can be enabled or disabled. 
 * If the power is disabled, the IndraDrive can not enter the Ab or AF state.
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 *
 * @param [out] pDrivePowerEnabled              - The returned state of the drive power. 
 *                                                If it is FALSE then the drive power is disabled. Otherwise the 
 *                                                drive power is enabled.
 * 
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLGetDrivePowerState(SIM_NODE              nodeId, 
                                                        SIM_SERCOS_DEVICE_ID  sercosDeviceId,
                                                        BOOL                  *pDrivePowerEnabled);


/**
 *
 * @ingroup sim_indra_drive_level
 * @brief SimDLSetDrivePowerState
 *
 * This function enables or disables the drive power of an IndraDrive. 
 * If the power is disabled, the IndraDrive can not enter the Ab or AF state.
 *
 * @param [in] nodeId                           - The node id to which the IndraDrive is connected.
 * @param [in] sercosDeviceId                   - The IndraDrive connection. 
 * @param [in] enableDrivePower                 - The new state for the drive power. 
 *                                                If it is FALSE then the drive power will be disabled. Otherwise the drive 
 *                                                power will be enabled.
 * 
 * @remarks None
 *
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDLSetDrivePowerState(SIM_NODE              nodeId, 
                                                        SIM_SERCOS_DEVICE_ID  sercosDeviceId,
                                                        BOOL                  enableDrivePower);


/**
 *
 * @ingroup sim_drive_level
 * @brief SimGetDigitalInput
 *
 * This function gets a digital input level (low or high).
 *
 * @param [in] nodeId                           - The node id to get the input on.
 * @param [in] digIOId                          - Specification of the IO to get.
 *
 * @param [out] pInputState                     - Variable where the input state will be stored.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetDigitalInput(SIM_NODE             nodeId,
                                                   NYCE_DIGITAL_IO_ID   digIOId,
                                                   DIG_IO_STATE         *pInputState);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimSetDigitalInput
 *
 * This function sets a digital input to a specified level (low or high).
 *
 * @param [in] nodeId                           - The node id to set the input on.
 * @param [in] digIOId                          - Specification of the IO to set.
 *
 * @param [in] inputState                       - State to set.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimSetDigitalInput(SIM_NODE             nodeId,
                                                   NYCE_DIGITAL_IO_ID   digIOId,
                                                   DIG_IO_STATE         inputState);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimGetDigitalOutput
 *
 * This function gets the level of a digital output (low or high).
 *
 * @param [in] nodeId                           - The node id to get the output on.
 * @param [in] digIOId                          - Specification of the IO to get.
 *
 * @param [out] pOutputState                    - Variable where the output state will be stored.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetDigitalOutput(SIM_NODE            nodeId,
                                                    NYCE_DIGITAL_IO_ID  digIOId,
                                                    DIG_IO_STATE        *pOutputState);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimGetAnalogInput
 *
 * This function gets the voltage of an analog input.
 *
 * @param [in] nodeId                           - The node id to set the input on.
 * @param [in] analogInId                       - Specification of the IO to get the input on.
 *
 * @param [out] pInputVoltage                   - Variable where the voltage to get is stored.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetAnalogInput(SIM_NODE          nodeId,
                                                  NYCE_ANALOG_IN_ID analogInId,
                                                  double            *pInputVoltage);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimSetAnalogInput
 *
 * This function sets an analog input to a specified voltage.
 *
 * @param [in] nodeId                           - The node id to set the input on.
 * @param [in] analogInId                       - Specification of the IO to set the input on.
 * @param [in] inputVoltage                     - Voltage to set.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimSetAnalogInput(SIM_NODE          nodeId,
                                                  NYCE_ANALOG_IN_ID analogInId,
                                                  double            inputVoltage);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimGetAnalogOutput
 *
 * This function gets the voltage of an analog output.
 *
 * @param [in] nodeId                           - The node id to get the output on.
 * @param [in] analogOutId                      - Specification of the IO to get the output on.
 *
 * @param [out] pOutputVoltage                  - Variable where the output voltage will be stored.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetAnalogOutput(SIM_NODE             nodeId,
                                                   NYCE_ANALOG_OUT_ID   analogOutId,
                                                   double               *pOutputVoltage);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimGetLedStatus
 *
 * This function gets the status of the two leds on the frontpanel of the MCU module.
 *
 * @param [in] nodeId                           - The node id to get the ledstatus on.
 *
 * @param [out] pLedStatus                      - Variable where the led status will be stored.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetLedStatus(SIM_NODE    nodeId,
                                                LED_STATUS  *pLedStatus);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimGetDriveLedColor
 *
 * This function gets the color of the led on the frontpanel of the drive module.
 *
 * @param [in] nodeId                           - The node id to get the led color on.
 * @param [in] slotId                           - The slot id of the drive.
 *
 * @param [out] pLedColor                       - Variable where the led color will be stored.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetDriveLedColor(SIM_NODE     nodeId,
                                                    NYCE_SLOT_ID slotId,
                                                    LED_COLOR    *pLedColor);


/**
 *
 * @ingroup sim_node_level
 * @brief SimSetServiceInput
 *
 * This function sets the service input to a specified level (high or low).
 *
 * @param [in] nodeId                           - The node id to set the input on.
 * @param [in] inputState                       - State to set.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimSetServiceInput(SIM_NODE      nodeId,
                                                   DIG_IO_STATE  inputState);



/**
 *
 * @ingroup sim_node_level
 * @brief SimSetStopAxesInput
 *
 * This function sets the stop axes input to a specified level (high or low).
 *
 * @param [in] nodeId                           - The node id to set the stop axes input on.
 * @param [in] inputState                       - State to set.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimSetStopAxesInput(SIM_NODE       nodeId,
                                                    DIG_IO_STATE   inputState);



/**
 *
 * @ingroup sim_axis_level
 * @brief SimSetAxisAlarm
 *
 * This function sets an alarm conditions for a specific axis.
 *
 * @param [in] nodeId                           - The node id to set the alarms on.
 * @param [in] axisUnit                         - The axis unit to set the alarms on.
 * @param [in] alarmMask                        - Mask of alarms to set.
 *
 *
 * @remarks multiple SIM_AXIS_ALARM alarms combined in the mask with an "or" operation.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimSetAxisAlarm(SIM_NODE            nodeId,
                                                NYCE_AXIS_UNIT_ID   axisUnit,
                                                uint32_t            alarmMask);



/**
 *
 * @ingroup sim_axis_level
 * @brief SimClearAxisAlarm
 *
 * This function clears the alarm conditions for a specific axis.
 *
 * @param [in] nodeId                           - The node id to clear the alarms on.
 * @param [in] axisUnit                         - The axis unit to clear the alarms on.
 * @param [in] alarmMask                        - Mask of alarms to clear.
 *
 *
 * @remarks multiple SIM_AXIS_ALARM alarms combined in the mask with an "or" operation.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimClearAxisAlarm(SIM_NODE          nodeId,
                                                  NYCE_AXIS_UNIT_ID axisUnit,
                                                  uint32_t          alarmMask);



/**
 *
 * @ingroup sim_axis_level
 * @brief SimSetAxisCurrent
 *
 * This function sets the axis current to a specified value for the selected axis.
 *
 * @param [in] nodeId                           - The node id to set the axis current on.
 * @param [in] axisUnit                         - The axis unit to set the axis current on.
 * @param [in] pAxisCurrent                     - Current to set.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimSetAxisCurrent(SIM_NODE          nodeId,
                                                  NYCE_AXIS_UNIT_ID axisUnit,
                                                  const SIM_AXIS_CURRENT    *pAxisCurrent);



/**
 *
 * @ingroup sim_axis_level
 * @brief SimGetAxisCurrent
 *
 * This function gets the axis current for the selected axis. Note that this function
 * will return zero if the axis current has not been set previously. The simulation
 * software does not attempt to calculate a real current. The Set/Get AxisCurrent
 * functions are only available to be able to generate overcurrent situations by
 * setting the current above the allowed maximum as is specified when initializing
 * the axis.
 *
 * @param [in] nodeId                           - The node id to get the axis current from.
 * @param [in] axisUnit                         - The axis unit to get the axis current from.
 *
 * @param [out] pAxisCurrent                    - Variable where the axis current will be stored.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetAxisCurrent(SIM_NODE          nodeId,
                                                  NYCE_AXIS_UNIT_ID axisUnit,
                                                  SIM_AXIS_CURRENT  *pAxisCurrent);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimSetDriveVoltage
 *
 * This function sets the drive voltages to a specified values for the selected slot.
 *
 * @param [in] nodeId                           - The node id to set the servo voltage on.
 * @param [in] slotId                           - Id of the slot to apply voltages on.
 * @param [in] driveVoltagePos                  - Positive voltage to set.
 * @param [in] driveVoltageNeg                  - Negative voltage to set.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimSetDriveVoltage(SIM_NODE     nodeId,
                                                   NYCE_SLOT_ID slotId,
                                                   double       driveVoltagePos,
                                                   double       driveVoltageNeg);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimGetDriveVoltage
 *
 * This function gets the drive voltages from the selected slot.
 *
 * @param [in]  nodeId                          - The node id to get the drive voltage on.
 * @param [in]  slotId                          - Id of the slot to get the voltages from.
 * @param [out] pDriveVoltagePos                - Positive voltage to get.
 * @param [out] pDriveVoltageNeg                - Negative voltage to get.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetDriveVoltage(SIM_NODE     nodeId,
                                                   NYCE_SLOT_ID slotId,
                                                   double       *pDriveVoltagePos,
                                                   double       *pDriveVoltageNeg);

/**
 *
 * @ingroup sim_drive_level
 * @brief SimSetDriveTemperature
 *
 * This function sets the drive temperature to a specified value for the selected drive.
 *
 * @param [in] nodeId                           - The node id to set the drive temperature on.
 * @param [in] slotId                           - Id of the slot to set the drive temperature on.
 * @param [in] driveTemperature                 - Temperature to set.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimSetDriveTemperature(SIM_NODE     nodeId,
                                                       NYCE_SLOT_ID slotId,
                                                       double       driveTemperature);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimGetDriveTemperature
 *
 * This function gets the drive temperature for the selected drive. Note that this
 * function will return zero if the drive temperature has not been set previously.
 * The simulation software does not attempt to calculate/estimate a temperature. The
 * Set/GetDriveTemperature functions are only available to be able to generate
 * temperature error situations by setting the temperature out of the allowed bounds
 * as are specified when initializing the node.
 *
 * @param [in] nodeId                       - The node id to get the drive temperature on.
 * @param [in] slotId                       - slotId in the node to get the drive temperature on.
 *
 * @param [out] pDriveTemperature           - Variable where the drive temperature will be stored.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetDriveTemperature(SIM_NODE     nodeId,
                                                       NYCE_SLOT_ID slotId,
                                                       double       *pDriveTemperature);



/**
 *
 * @ingroup sim_axis_level
 * @brief SimDefineServoPositionCallback
 *
 * With this function it is possible to register a user-defined function for generating
 * servo position based on a given setpoint position. When the function is not specified,
 * or specified with both dllName and functionName as NULL, the default motor model will be
 * used.
 *
 * The prototype for the exported callback function must be in the form:
 *
 * __declspec(dllexport) uint32_t f(uint32_t setpointPosition);
 *
 * typedef void (*SIM_PLANT_HANDLER)(uint32                 nodeNr,
 *                                   NYCE_AXIS_UNIT_ID      axisUnit,
 *                                   const SIM_PLANT_INPUT *pPlantInput,
 *                                   SIM_PLANT_OUTPUT      *pPlantOutput);
 *
 * @param [in] nodeId                       - The node id to register the position callback on.
 * @param [in] axisUnit                     - The axis unit to register the position callback on.
 * @param [in] dllName                      - Name of the dll that contains the callback function.
 * @param [in] functionName                 - Name of the callback function in the dll.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimDefineServoPositionCallback(SIM_NODE             nodeId,
                                                               NYCE_AXIS_UNIT_ID    axisUnit,
                                                               const char           *dllName,
                                                               const char           *functionName);



/**
 *
 * @ingroup sim_axis_level
 * @brief SimSetDefaultMotorModel
 *
 * With this function it is possible to set the default motor model.
 *
 * @param [in] nodeId                           - The node id.
 * @param [in] axisUnit                         - The axis unit.
 * @param [in] pPlantConst                      - The plant constants for the default motor handling.
 *
 * @remarks When km or mass (of struct pPlantConst) is set to 0.0 the rule axis position is setpoint position is applied.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimSetDefaultMotorModel(SIM_NODE                nodeId,
                                                        NYCE_AXIS_UNIT_ID       axisUnit,
                                                        const SIM_PLANT_CONST   *pPlantConst);


/**
 *
 * @ingroup sim_node_level
 * @brief SimGetMcuUnitType
 *
 * This function gets the MCU unit type of specified node.
 *
 * @param [in] nodeId                           - The node id to get the MCU unit type on.
 *
 * @param [out] pMcuUnitType                    - MCU unit type of the specified node
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimGetMcuUnitType(SIM_NODE           nodeId,
                                                  NYCE_MCU_UNIT_TYPE *pMcuUnitType);

/**
 *
 * @ingroup sim_configuration
 * @brief SimCreateNodeFlashFile
 *
 * This function creates a flashfile for a node that will be used in simulation. The flashfile will be initialized with
 * the supplied nodename and a sample frequency of 2 kHz.
 *
 * @param [in] pNodeName                        - Name of the node to store in the flashfile.
 * @param [in] pFileName                        - Name of the file to be created.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimCreateNodeFlashFile(const char *pNodeName,
                                                       const char *pFileName);



/**
 *
 * @ingroup sim_configuration
 * @brief SimCreateNodeEepromFile
 *
 * This function creates a eeprom file for a node that will be used in simulation.
 * The eeprom file will be initialized with default parameters.
 *
 * @param [in] mcuUnitType                     - MCU unit type.
 * @param [in] pFileName                       - Name of the file to be created.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimCreateNodeEepromFile(NYCE_MCU_UNIT_TYPE mcuUnitType,
                                                        const char         *pFileName);



/**
 *
 * @ingroup sim_drive_level
 * @brief SimAspiDefineSlaveCallbacks
 *
 * This function will bind the user defined callback functions, which must
 * be available in the specified DLL.
 *
 * lpszOnMasterWriteFuncName is the function name of the function which
 * should be called by the simulated node when it writes data to the aSPI
 * slave during a MasterWrite cycle. This is initiated by a NhiWriteaSPIData
 * call. The called function gets the sent data and may use it as needed.
 * If this parameter is NULL, no callback will be performed when calling
 * NhiWriteaSPIData.
 *
 * lpszOnMasterReadFuncName is the function name of the function which
 * should be called by the simulated node when it needs to read data from
 * the aSPI slave during a MasterRead cycle. This is initiated by a
 * NhiStartReadaSPIData. The called function needs to provide data back to
 * the caller. If this parameter is NULL, no callback will be performed when
 * calling NhiStartReadaSPIData. In that case the data returned by
 * NhiReadaSPIData is undefined. If both callback functions are NULL, the
 * DLL will be unloaded. This does not mean that the DLL is truly unloaded
 * from the EXE, because the same DLL may be used by other aSPI ports.
 *
 * The callback functions must have the following prototypes:
 *
 * void __declspec(dllexport) __stdcall yourFunctionName(  const char* dataBuffer,
 *                                                         int32_t nBits )
 * is called during the MasterWrite cycle.
 *
 * void __declspec(dllexport) __stdcall yourFunctionName(  char* dataBuffer,
 *                                                         int32_t nBits)
 * is called during the MasterRead cycle.
 *
 * @param [in] nodeId                           - The node id to set the aSPI callbacks.
 * @param [in] slotId                           - SlotId in the node to set the aSPI callbacks.
 * @param [in] aspiPortNr                       - Portnr of the aSPI port in a slot.
 * @param [in] szDllModuleName                  - Name of the dll that contains the callback function.
 * @param [in] szOnMasterWriteFuncName          - Name of the StartWriteAspiData callback function in the dll.
 * @param [in] szOnMasterReadFuncName           - Name of the StartReadAspiData callback function in the dll.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimAspiDefineSlaveCallbacks( SIM_NODE       nodeId,
                                                             NYCE_SLOT_ID   slotId,
                                                             uint32_t       aspiPortNr,
                                                             const char     *szDllModuleName,
                                                             const char     *szOnMasterWriteFuncName,
                                                             const char     *szOnMasterReadFuncName );



/**
 *
 * @ingroup sim_drive_level
 * @brief SimAspiSlaveSendData
 *
 * This will send data to a node's aSPI port. The data must be given through
 *                 dataBuffer and must be (at least) nBits long. Because the master specifies
 *                 the actual data size (by the port's configuration).
 *
 * @param [in] nodeId                           - The node to set the aSPI callbacks.
 * @param [in] slotId                           - SlotId in the node to set the aSPI callbacks.
 * @param [in] aspiPortNr                       - Portnr of the aSPI port in a slot [0-1].
 * @param [in] dataBuffer                       - array of chars containing the data.
 * @param [in] nBits                            - number of bits that need to be send to the node.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimAspiSlaveSendData( SIM_NODE      nodeId,
                                                      NYCE_SLOT_ID  slotId,
                                                      uint32_t      aspiPortNr,
                                                      const char    *dataBuffer,
                                                      int32_t       nBits );



/**
 *
 * @ingroup sim_configuration
 * @brief SimXmlGetNrOfNodes
 *
 * This function gets the number of nodes that are present in the configuration file.
 *
 * @param [in]  pFileName                       - Name of the file that contains the node configuration.
 * @param [out] pNrOfNodes                      - Number of nodes that are available in the network.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimXmlGetNrOfNodes(const char   *pFileName,
                                                   uint32_t     *pNrOfNodes);



/**
 *
 * @ingroup sim_configuration
 * @brief SimXmlGetNodeName
 *
 * This function gets the name of a node that is present in the configuration file.
 *
 * @param [in]  pFileName                       - Name of the file that contains the node configuration.
 * @param [in]  nodeNr                          - Number of the node to get the name from.
 * @param [out] nodeName                        - size(NYCE_MAX_NAME_LENGTH); Name of the node.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimXmlGetNodeName(const char    *pFileName,
                                                  uint32_t      nodeNr,
                                                  char          nodeName[]);



/**
 *
 * @ingroup sim_configuration
 * @brief SimXmlGetNodeFlashFileName
 *
 * This function gets the name of a node flash file that is present in the configuration file.
 *
 * @param [in]  pFileName                       - Name of the file that contains the node configuration.
 * @param [in]  nodeNr                          - Number of the node to get the name from.
 * @param [out] flashfile                       - size(260); Name of the flash file.
 *
 *
 * @remarks pFlashfile can be of length MAX_PATH = 260 chars.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimXmlGetNodeFlashFileName(const char    *pFileName,
                                                           uint32_t      nodeNr,
                                                           char          flashfile[]);


/**
 *
 * @ingroup sim_configuration
 * @brief SimXmlGetNodeEepromFileName
 *
 * This function gets the name of a node eeprom file that is present in the configuration file.
 *
 * @param [in]  pFileName                       - Name of the file that contains the node configuration.
 * @param [in]  nodeNr                          - Number of the node to get the name from.
 * @param [out] eepromfile                      - size(260); Name of the eeprom file.
 *
 *
 * @remarks pEepromfile can be of length MAX_PATH = 260 chars.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimXmlGetNodeEepromFileName(const char    *pFileName,
                                                            uint32_t      nodeNr,
                                                            char          eepromfile[]);


/**
 *
 * @ingroup sim_configuration
 * @brief SimXmlGetNodeMcuUnitType
 *
 * This function gets the MCU type of the node, specified by the node number, 
 * that is present in the specified configuration file.
 *
 * @param [in]  pFileName                       - Name of the file that contains the node configuration.
 * @param [in]  nodeNr                          - Number of the node to get the MCU unit type from
 * @param [out] pMcuUnitType                    - MCU unit type.
 *
 *
 * @remarks None.
 */
SIM_EXPORT NYCE_STATUS NYCE_API SimXmlGetNodeMcuUnitType(const char         *pFileName,
                                                         uint32_t            nodeNr,
                                                         NYCE_MCU_UNIT_TYPE *pMcuUnitType);
/**
*
* @ingroup sim_sdc
* @brief SimSdcSetData
*
* This function sets the data which is synchronous read from the serial data channel in simulation.
*
* @param [in] nodeId                       - Node identifier.
* @param [in] slotId                       - Slot identifier.
* @param [in] portId                       - Port identifier.
* @param [in] data                         - Data used for serial data channel simulation.
*
*
* @remarks None.
*/
SIM_EXPORT NYCE_STATUS NYCE_API SimSdcSetData(SIM_NODE          nodeId,
                                              NYCE_SLOT_ID      slotId,
                                              SIM_SDC_PORT_ID   portId,
                                              uint32_t          data);

/**
*
* @ingroup sim_sdc
* @brief SimSdcGetData
*
* This function gets the data of the serial data channel simulation.
*
* @param [in] nodeId                       - Node identifier.
* @param [in] slotId                       - Slot identifier.
* @param [in] portId                       - Port identifier.
* @param [out] pData                       - Pointer to store the data used for simulation.
*
*
* @remarks None.
*/
SIM_EXPORT NYCE_STATUS NYCE_API SimSdcGetData(SIM_NODE          nodeId,
                                              NYCE_SLOT_ID      slotId,
                                              SIM_SDC_PORT_ID   portId,
                                              uint32_t          *pData);

/**
*
* @ingroup sim_sdc
* @brief SimSdcSetCommunicationError
*
* This function sets the communication error for the serial data channel simulation.
*
* @param [in] nodeId                       - Node identifier.
* @param [in] slotId                       - Slot identifier.
* @param [in] portId                       - Port identifier.
* @param [in] error                        - Communication error used for serial data channel simulation.
*
*
* @remarks None.
*/
SIM_EXPORT NYCE_STATUS NYCE_API SimSdcSetCommunicationError(SIM_NODE                    nodeId,
                                                            NYCE_SLOT_ID                slotId,
                                                            SIM_SDC_PORT_ID             portId,
                                                            SIM_SDC_COMMUNICATION_ERROR error);

/**
*
* @ingroup sim_sdc
* @brief SimSdcGetCommunicationError
*
* This function gets the communication error of the serial data channel simulation.
*
* @param [in] nodeId                       - Node identifier.
* @param [in] slotId                       - Slot identifier.
* @param [in] portId                       - Port identifier.
* @param [out] pError                      - Pointer to store the communication error 
*                                            used for serial data channel simulation.
*
*
* @remarks None.
*/
SIM_EXPORT NYCE_STATUS NYCE_API SimSdcGetCommunicationError(SIM_NODE                     nodeId,
                                                            NYCE_SLOT_ID                 slotId,
                                                            SIM_SDC_PORT_ID              portId,
                                                            SIM_SDC_COMMUNICATION_ERROR  *pError);

/**
*
* @ingroup sim_sdc
* @brief SimSdcSetMemory
*
* This function sets the memory on the serial data channel device used for simulation.
*
* @param [in] nodeId                       - Node identifier.
* @param [in] slotId                       - Slot identifier.
* @param [in] portId                       - Port identifier.
* @param [in] blockId                      - Memory block identifier.
* @param [in] address                      - Memory address.
* @param [in] data                         - Data to write to the serial data channel device memory. 
*
*
* @remarks None.
*/
SIM_EXPORT NYCE_STATUS NYCE_API SimSdcSetMemory(SIM_NODE                    nodeId,
                                                NYCE_SLOT_ID                slotId,
                                                SIM_SDC_PORT_ID             portId,
                                                SIM_SDC_MEMORY_BLOCK_ID     blockId,
                                                uint32_t                    address,
                                                uint16_t                    data);

/**
*
* @ingroup sim_sdc
* @brief SimSdcGetMemory
*
* This function gets the memory of the serial data channel device used for simulation.
*
* @param [in] nodeId                       - Node identifier.
* @param [in] slotId                       - Slot identifier.
* @param [in] portId                       - Port identifier.
* @param [in] blockId                      - Memory block identifier.
* @param [in] address                      - Memory address.
* @param [out] pData                       - Pointer to store the memory of the 
*                                            serial data channel device.
*
*
* @remarks None.
*/
SIM_EXPORT NYCE_STATUS NYCE_API SimSdcGetMemory(SIM_NODE                    nodeId,
                                                NYCE_SLOT_ID                slotId,
                                                SIM_SDC_PORT_ID             portId,
                                                SIM_SDC_MEMORY_BLOCK_ID     blockId,
                                                uint32_t                    address,
                                                uint16_t                    *pData);



#ifdef __cplusplus
    }
#endif

/** @} */

#ifdef NT
#pragma pack(pop)
#endif

#endif /* __SIMAPI_H__ */
