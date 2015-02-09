/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2009-2012
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000
//    Component Name: HOSTSW
//    Subsystem Name: NHI
//    %full_filespec:    nhiapi.h`104:incl:1 % (SYNERGY INFO, do not change)
//
//    Description   : Public interface to the NHI subsystem
*/

#ifndef __NHIAPI_H__
#define __NHIAPI_H__

/*-----------------------------------------------------------------------
 *  GLOBAL INCLUDES
 *-----------------------------------------------------------------------*/
#include "n4k_deprecated.h" //lint !e451
#include "nhitypes.h"

/*-----------------------------------------------------------------------
 *  GLOBAL DEFINES
 *-----------------------------------------------------------------------*/

/**
 *  @addtogroup nhi
 *
 *  @{
 */

/*-----------------------------------------------------------------------
 *  EXPORTED FUNCTIONAL PROTOTYPES
 *-----------------------------------------------------------------------*/

/* If NHI is defined, the functions are exported, otherwise they are imported */
#ifdef NHI_EXPORT
#undef NHI_EXPORT
#endif

#ifdef NT
#ifdef NHI
#define NHI_EXPORT __declspec(dllexport)
#else
#define NHI_EXPORT __declspec(dllimport)
#endif
#else
#define NHI_EXPORT
#endif


#ifdef __cplusplus
extern "C" {
#endif



/**
 *  @ingroup nhi_state_transitions
 *
 *  @brief   Open a connection handle to a node.
 *
 *  @param [in]  pNodeName   Node name.
 *  @param [out] pNodeId     Node connection handle.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiConnect(const char *pNodeName,
                                           NHI_NODE   *pNodeId);



/**
 *  @ingroup nhi_state_transitions
 *
 *  @brief Close the connection handle to the node.
 *
 *  @param [in]  nodeId      Node connection handle.
 *
 *  @remarks Closing the connection handle includes clearing all event enrolments for this node.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiDisconnect(NHI_NODE nodeId);



/**
 *  @ingroup nhi_state_transitions
 *
 *  @brief Initialize the node with parameters from flash or from a file on the host.
 *
 *  Initialize the node with the node parameter and define the axes as specified in the configuration file
 *  or from flash (use NHI_USE_FLASH).
 *
 *  An error or warning code returned by this function can be related to a specific NHI parameter identifier.
 *  Details about the error are logged and can be retrieved using the Deh logging functions or by using the NYCeLogger.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [in]  pFileName   Node configuration filename or NHI_USE_FLASH.
 *
 *  @retval NYCE_OK
 *  @retval CFG_ERR_INITIALIZE_INTERRUPTED            - Initialize was interrupted, because another process performed an NhiInitialize during the execution of this call.
 *  @retval CFG_ERR_AXIS_IN_USE                       - One or more axes are not IDLE.
 *  @retval CFG_WRN_UNFINISHED_INITIALIZE_INTERRUPTED - This initialize interrupted the NhiInitialize of another process.
 *  @retval CFG_WRN_PARAMETER_DEFAULT_USED            - One or more parameters are missing in the node configuration file. Default values are used for these parameters.
 *  @retval CFG_WRN_PARAMETER_NOT_SUPPORTED           - The node configuration file contains parameter settings that are not used in the specified node configuration.
 *
 *  @remarks The NYCeConfigurator will show all warnings/errors during initialize in a message box.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiInitialize(NHI_NODE   nodeId,
                                              const char *pFileName);



/**
 *  @ingroup nhi_state_transitions
 *
 *  @brief Reset a node. This implies that it restarts the firmware by execution of the boot software.
 *
 *  @param [in]  nodeId      Node connection handle.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiResetNode(NHI_NODE nodeId);



/**
 *  @ingroup nhi_miscellaneous
 *
 *  @brief Retrieve the version number of the NHI subsystem.
 *
 *  @param [out] pVersion   NHI library version.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetVersion(NYCE_VERSION_TYPE *pVersion);



/**
 *  @ingroup nhi_miscellaneous
 *
 *  @brief Retrieve the versions of the Gateware, Hardware, Firmware and Hostware.
 *
 *  @param [in]  nodeId   Node connection handle.
 *  @param [out] pInfo    Structure which contains all node version data
 *
 *  @remarks This function retrieves all information about node  software and hardware versions.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetVersionInfo(NHI_NODE         nodeId,
                                         NHI_VERSION_INFO *pInfo);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Add an axis to the node.
 *
 *  The name of the axis is used by the SAC subsystem to connect the axis.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [in]  pAxisName   Name of the axis.
 *  @param [out] pAxisNr     Axis number on the node.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiAddAxis(NHI_NODE    nodeId,
                                           const char  *pAxisName,
                                           uint32_t    *pAxisNr);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Delete an axis from the node.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [in]  axisNr      Axis number on the node.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiDeleteAxis(NHI_NODE  nodeId,
                                              uint32_t  axisNr);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Change the current axis name to a new axis name.
 *
 *  @param [in] nodeId       Node connection handle.
 *  @param [in] axisNr       Axis number on the node.
 *  @param [in] pNewAxisName Axis name.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSetAxisName(NHI_NODE     nodeId,
                                               uint32_t     axisNr,
                                               const char   *pNewAxisName);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Retrieve the current axis name.
 *
 *  @param [in]  nodeId         Node connection handle.
 *  @param [in]  axisNr         Axis number on the node
 *  @param [out] axisName       size(NYCE_MAX_NAME_LENGTH); Character array to store the name in.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetAxisName(NHI_NODE     nodeId,
                                               uint32_t     axisNr,
                                               char         axisName[]);



/**
 *  @ingroup nhi_digital_io
 *
 *  @brief Read a single digital I/O.
 *
 *  @param [in]  nodeId          Node connection handle.
 *  @param [in]  digIOId         Digital IO identifier.
 *  @param [out] pDigIOStatus    Digital IO status.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiReadDigitalIO(NHI_NODE           nodeId,
                                                 NYCE_DIGITAL_IO_ID digIOId,
                                                 uint32_t           *pDigIOStatus);



/**
 *  @ingroup nhi_digital_io
 *
 *  @brief Read the digital I/O status register.
 *
 *  @param [in]  nodeId          Node connection handle.
 *  @param [in]  slotId          Node slot identifier.
 *  @param [out] pDigIOStatus    Status of all digital IO.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiReadDigitalIORegister(NHI_NODE       nodeId,
                                                         NYCE_SLOT_ID   slotId,
                                                         uint32_t       *pDigIOStatus);



/**
 *  @ingroup nhi_analog_io
 *
 *  @brief Write a value to the specified analog output.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [in]  anOutId     Analog output identifier.
 *  @param [in]  anOutValue  Analog output value.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiWriteAnalogOutput(NHI_NODE           nodeId,
                                                     NYCE_ANALOG_OUT_ID anOutId,
                                                     double             anOutValue);



/**
 *  @ingroup nhi_variables
 *
 *  @brief Read the actual value of a variable within a node.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [in]  varId       Node variable identifier.
 *  @param [out] pVarValue   Value of the variable.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiReadVariable(NHI_NODE   nodeId,
                                                NHI_VAR_ID varId,
                                                double     *pVarValue);



/**
 *  @ingroup nhi_variables
 *
 *  @brief  Add a node variable to the NYCE variable set
 *
 *      This function adds a node variable to the NYCE variable set and returns its 
 *      position in the variable set.
 *
 *  @param [in]     nodeId          Node connection handle.
 *  @param [in]     varId           Node variable identifier.
 *  @param [out]    pVariableIndex  Returned index of the variable in the variable set.
 *  
 *  @return         A NYCE_STATUS code.
 *
 *  @retval         NHI_ERR_INVALID_NODE_ID                 The node id is invalid.
 *  @retval         NHI_ERR_INVALID_PARAMETER               The variable id is invalid.
 *  @retval         NHI_ERR_INVALID_OUTPUT_ARGUMENT         pVariableIndex is NULL.
 *  @retval         TRACE_WRN_VARIABLE_ALREADY_SELECTED     The variable was already added.
 *  @retval         TRACE_ERR_MAX_NR_OF_VARS_REACHED        The maximum number of variables which can be added to the variable set 
 *                                                          has been reached.
 *  @retval         TRACE_ERR_MAX_NR_OF_NODES_REACHED       The maximum number of nodes which can be used by trace and variable set 
 *                                                          has been reached.
 * 
 *  @remarks
 *      Only up to NYCE_MAX_NR_OF_ISOCHRONOUS_CHANNELS defined number of nodes can be used system wide by the trace 
 *      and variable set functionality together.
 *
 *  @see NyceDeleteVariableFromSet
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiAddVariableToSet(NHI_NODE    nodeId,
                                                    NHI_VAR_ID  varId,
                                                    uint32_t    *pVariableIndex);



/**
 *  @ingroup nhi_variables
 *
 *  @brief  Add a node variable to the NYCE trace.
 *
 *      This function adds a node variable to the NYCE trace and returns its
 *      position in a trace sample.
 *
 *  @param [in]     nodeId         Node connection handle.
 *  @param [in]     varId          Node variable identifier.
 *  @param [out]    pVariableIndex Returned index of the variable in a trace sample.
 *  
 *  @return         A NYCE_STATUS code.
 *
 *  @retval         NHI_ERR_INVALID_NODE_ID                 The node id is invalid.
 *  @retval         NHI_ERR_INVALID_PARAMETER               The variable id is invalid.
 *  @retval         NHI_ERR_INVALID_OUTPUT_ARGUMENT         pVariableIndex is NULL.
 *  @retval         TRACE_WRN_VARIABLE_ALREADY_SELECTED     The variable was already added.
 *  @retval         TRACE_ERR_INVALID_STATE                 The trace state is invalid. It must be NYCE_TRACE_READY or NYCE_TRACE_ERROR.
 *  @retval         TRACE_ERR_MAX_NR_OF_VARS_REACHED        The maximum number of variables which can be added to trace was already reached.
 *  @retval         TRACE_ERR_MAX_NR_OF_NODES_REACHED       The maximum number of nodes which can be used by trace and variable set 
 *                                                          has been reached.
 * 
 *  @remarks
 *      This function can only be called in the NYCE_TRACE_READY or NYCE_TRACE_ERROR trace state.
 *
 *      Only up to NYCE_MAX_NR_OF_ISOCHRONOUS_CHANNELS defined number of nodes can be used system wide by the trace 
 *      and variable set functionality together.
 *
 *  @see NyceDeleteVariableFromTrace
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiAddVariableToTrace(NHI_NODE      nodeId,
                                                      NHI_VAR_ID    varId,
                                                      uint32_t*     pVariableIndex);



/**
 *  @ingroup nhi_variables
 *
 *  @brief Reset the variable NHI_VAR_SAMPLE_DURATION_MAX of a node.
 *
 *  @param [in]  nodeId  Node connection handle.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiResetMaxSampleDuration(NHI_NODE nodeId);


/**
 *  @ingroup nhi_parameters
 *
 *  @brief Retrieve the maximum and minimum value of a node parameter.
 *
 *  A valid value for a parameter lies between or is equal to the boundaries indicated by
 *  the maximum and minimum value.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [in]  parId       Node parameter identifier.
 *  @param [out] pMaxValue    Maximum parameter value.
 *  @param [out] pMinValue    Minimum parameter value.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetParameterBounds(NHI_NODE   nodeId,
                                                      NHI_PAR_ID parId,
                                                      double     *pMaxValue,
                                                      double     *pMinValue);


/**
 *  @ingroup nhi_parameters
 *
 *  @brief Read the actual value of the specified parameter on a node.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [in]  parId       Node parameter identifier.
 *  @param [out] pParValue   Parameter value.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiReadParameter(NHI_NODE   nodeId,
                                                 NHI_PAR_ID parId,
                                                 double     *pParValue);



/**
 *  @ingroup nhi_parameters
 *
 *  @brief Write a value to the specified parameter on a node.
 *
 *  @param [in]  nodeId     Node connection handle.
 *  @param [in]  parId      Node parameter identifier.
 *  @param [in]  parValue   parameter value.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiWriteParameter(NHI_NODE   nodeId,
                                                  NHI_PAR_ID parId,
                                                  double     parValue);


/**
 *  @ingroup nhi_parameters
 *
 *  @brief Save the parameters to flash such that these parameters can be used at startup of the system.
 *
 *  @param [in] nodeId   Node connection handle.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSaveToFlash(NHI_NODE nodeId);



/**
 *  @ingroup nhi_parameters
 *
 *  @brief Save the parameters to a file such that these parameters can be downloaded to the firmware.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [in]  pFileName   Parameter configuration filename.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiUpload(NHI_NODE   nodeId,
                                          const char *pFileName);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Save user data to flash.
 *
 *  The data can be defined by the user and is restricted to
 *  a maximum of NYCE_MAX_USER_DATA_FLASH_SIZE bytes.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [in]  nrOfBytes   Number of bytes to save
 *  @param [in]  userData    size(nrOfBytes); Data to save.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiWriteUserDataToFlash(NHI_NODE    nodeId,
                                                        int32_t     nrOfBytes,
                                                        const char  userData[]);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Read user data from flash.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [in]  nrOfBytes   Number of bytes to read.
 *  @param [out] userData    size(nrOfBytes); Databuffer to store read data.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiReadUserDataFromFlash(NHI_NODE   nodeId,
                                                         int32_t    nrOfBytes,
                                                         char       userData[]);



/**
 *  @ingroup nhi_events
 *
 *  @brief Define an event enrolment handler function.
 *
 *  This function determines how the receipt of an event generated by the unit on a node identified
 *  by the nodeId will subsequently be handled by the client. The user defined handler is specified
 *  in the handler parameter for the event indicated by eventId. For every event, multiple separate
 *  handles can be installed.  The order of execution is the same as the order in which they are defined.
 *  When an event is raised, the user defined handler is called with the parameters as defined in
 *  NYCE_EVENT_HANDLER. The parameter eventId indicates the type of the event, the parameter eventData
 *  contains additional information about the event that occurred.
 *
 *  @param [in] nodeId           Node connection handle.
 *  @param [in] eventId          Node event identifier.
 *  @param [in] handler          Event handler.
 *  @param [in] pUserDataWord    User data.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiDefineEventEnrolment(NHI_NODE           nodeId,
                                                        NYCE_EVENT         eventId,
                                                        NYCE_EVENT_HANDLER handler,
                                                        void               *pUserDataWord);



/**
 *  @ingroup nhi_events
 *
 *  @brief Detach the enrolment handler function with the eventId for the node identified
 *  by the nodeId.
 *
 *  @param [in] nodeId           Node connection handle.
 *  @param [in] eventId          Node event identifier.
 *  @param [in] handler          Event handler.
 *  @param [in] pUserDataWord    User data.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiDeleteEventEnrolment(NHI_NODE           nodeId,
                                                        NYCE_EVENT         eventId,
                                                        NYCE_EVENT_HANDLER handler,
                                                        void               *pUserDataWord);



/**
 *  @ingroup nhi_miscellaneous
 *
 *  @brief Retrieve the number of connected clients to the node.
 *
 *  @param [in]  nodeId          Node connection handle.
 *  @param [out] pNrOfClients    Number of clients connected.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetNrOfClients(NHI_NODE  nodeId,
                                                  uint32_t  *pNrOfClients);



/**
 *  @ingroup nhi_miscellaneous
 *
 *  @brief Retrieve the name of the node.
 *
 *  @param [in] nodeId   Node connection handle.
 */
NHI_EXPORT const char* NYCE_API NhiGetNodeName(NHI_NODE nodeId);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Retrieve MCU unit type.
 *
 *  @param [in]  nodeId          Node connection handle.
 *  @param [out] pMcuUnitType    MCU unit type.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetMcuUnitType(NHI_NODE           nodeId,
                                                  NYCE_MCU_UNIT_TYPE *pMcuUnitType);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Retrieve the MCU serial number.
 *
 *  @param [in]  nodeId          Node connection handle.
 *  @param [out] pSerialNumber   Node serial number.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetMcuSerialNumber(NHI_NODE              nodeId,
                                                      NYCE_SERIAL_NUMBER    *pSerialNumber);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Retrieve the number of used drive slots.
 *
 *  The returned number shows the actual connected number of drive slots.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [out] pNrOfSlots  Number of slots physically connected to a drive.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetNrOfSlots(NHI_NODE    nodeId,
                                                uint32_t    *pNrOfSlots);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Retrieve the drive type which is in the specified slot position.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [in]  slotId      Node slot identifier.
 *  @param [out] pUnitType   Drive unit type.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetUnitType(NHI_NODE      nodeId,
                                               NYCE_SLOT_ID  slotId,
                                               NYCE_UNIT_TYPE *pUnitType);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Retrieve the serial number of the drive in the specified slot.
 *
 *  @param [in]  nodeId          Node connection handle.
 *  @param [in]  slotId          Node Slot identifier.
 *  @param [out] pSerialNumber   Serial number.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetUnitSerialNumber(NHI_NODE             nodeId,
                                                       NYCE_SLOT_ID         slotId,
                                                       NYCE_SERIAL_NUMBER   *pSerialNumber);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Retrieve the axes defined on a node.
 *
 *  The number of defined axes together with an array containing the axis numbers of the defined axes are retrieved.
 *  The array is filled from index 0 to (pNrOfAxes - 1) where pNrOfAxes is at most NYCE_MAX_NR_OF_AXES_PER_NODE.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [out] pNrOfAxes   Number of axes.
 *  @param [out] axesNrs     size(NYCE_MAX_NR_OF_AXES_PER_NODE); Array containing the axis numbers.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetDefinedAxes(NHI_NODE  nodeId,
                                                  uint32_t  *pNrOfAxes,
                                                  uint32_t  axesNrs[]);



/**
 *  @ingroup nhi_configuration
 *
 *  @brief Retrieve the number of defined axes on the node.
 *
 *  @param [in]  nodeId      Node connection handle.
 *  @param [out] pNrOfAxes   Number of axes.
 *
 *  @see NhiGetDefineAxes to retrieve the axes numbers.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetNrOfAxes(NHI_NODE nodeId,
                                               uint32_t *pNrOfAxes);



/**
 *  @ingroup nhi_hardware
 *
 *  @brief Retrieve the number of defined digital inputs.
 *
 *  @param [in]  unitType        Drive unit type.
 *  @param [out] pNrOfDigInputs  Number of digital inputs.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetNrOfDigitalInputs(NYCE_UNIT_TYPE   unitType,
                                                        uint32_t        *pNrOfDigInputs);



/**
 *  @ingroup nhi_hardware
 *
 *  @brief Retrieve the number of defined digital outputs.
 *
 *  @param [in]  unitType        Drive unit type.
 *  @param [out] pNrOfDigOutputs Number of digital outputs.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetNrOfDigitalOutputs(NYCE_UNIT_TYPE  unitType,
                                                         uint32_t       *pNrOfDigOutputs);



/**
 *  @ingroup nhi_hardware
 *
 *  @brief Retrieve the number of defined analog inputs.
 *
 *  @param [in]  unitType        Drive unit type.
 *  @param [out] pNrOfAnInputs   Number of analog inputs.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetNrOfAnalogInputs(NYCE_UNIT_TYPE    unitType,
                                                       uint32_t         *pNrOfAnInputs);



/**
 *  @ingroup nhi_hardware
 *
 *  @brief Retrieve the number of defined analog outputs.
 *
 *  @param [in]  unitType        Drive unit type.
 *  @param [out] pNrOfAnOutputs  Number of analog outputs.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetNrOfAnalogOutputs(NYCE_UNIT_TYPE   unitType,
                                                        uint32_t        *pNrOfAnOutputs);



/**
 *  @ingroup nhi_hardware
 *
 *  @brief Retrieve the number of axisUnits.
 *
 *  @param [in]  unitType        Drive unit type.
 *  @param [out] pNrOfAxisUnits  Number of axis units.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetNrOfAxisUnits(NYCE_UNIT_TYPE   unitType,
                                                    uint32_t        *pNrOfAxisUnits);



/**
 *  @ingroup nhi_conversion
 *
 *  @brief Retrieve the event identifier that represents the NHI event string.
 *
 *  @param [in]  pEventString    Node event string representation.
 *  @param [out] pEventId        Event identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetEventEnum(const char *pEventString,
                                                NYCE_EVENT *pEventId);



/**
 *  @ingroup nhi_conversion
 *
 *  @brief Retrieve the event string that represents the NHI event identifier.
 *
 *  @param [in] eventId  Node event identifier
 */
NHI_EXPORT const char* NYCE_API NhiGetEventString(NYCE_EVENT eventId);



/**
 *  @ingroup nhi_conversion
 *
 *  @brief Retrieve the parameter identifier that represents the NHI parameter string.
 *
 *  @param [in]  pParString  Node parameter string representation.
 *  @param [out] pParId      Parameter identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetParIdEnum(const char *pParString,
                                                NHI_PAR_ID *pParId);



/**
 *  @ingroup nhi_conversion
 *
 *  @brief Retrieve the parameter string that represents the NHI parameter identifier.
 *
 *  @param [in] parId    Node parameter identifier.
 */
NHI_EXPORT const char* NYCE_API NhiGetParIdString(NHI_PAR_ID parId);



/**
 *  @ingroup nhi_conversion
 *
 *  @brief Retrieve the variable identifier that represents  the NHI variable string.
 *
 *  @param [in] pVarString   Node variable string representation.
 *  @param [out] pVarId      Variable identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetVarIdEnum(const char    *pVarString,
                                                NHI_VAR_ID    *pVarId);



/**
 *  @ingroup nhi_conversion
 *
 *  @brief Retrieve the variable string that represents the NHI variable identifier.
 *
 *  @param [in] varId    Node variable identifier.
 */
NHI_EXPORT const char* NYCE_API NhiGetVarIdString(NHI_VAR_ID varId);



/**
 *  @ingroup nhi_conversion
 *
 *  @brief Retrieve the unit type that represents the MCU unit type string.
 *
 *  @param [in]  pMcuUnitString  MCU unit type string representation.
 *  @param [out] pMcuUnitType    MCU unit type.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetMcuUnitTypeEnum(const char         *pMcuUnitString,
                                                      NYCE_MCU_UNIT_TYPE *pMcuUnitType);



/**
 *  @ingroup nhi_conversion
 *
 *  @brief Retrieve the unit type string that represents the MCU unit type identifier.
 *
 *  @param [in] mcuUnitType  MCU unit type identifier
 */
NHI_EXPORT const char* NYCE_API NhiGetMcuUnitTypeString(NYCE_MCU_UNIT_TYPE mcuUnitType);



/**
 *  @ingroup nhi_conversion
 *
 *  @brief Retrieve the unit type identifier that represents the drive unit type string.
 *
 *  @param [in] pUnitTypeString  Drive unit type string representation.
 *  @param [out] pUnitType       Drive unit type.
 */
 NHI_EXPORT NYCE_STATUS NYCE_API NhiGetUnitTypeEnum(const char    *pUnitTypeString,
                                                    NYCE_UNIT_TYPE *pUnitType);



/**
 *  @ingroup nhi_conversion
 *
 *  @brief Retrieve the unit type string that represents the drive variable identifier.
 *
 *  @param [in] unitType Drive unit type.
 */
NHI_EXPORT const char* NYCE_API NhiGetUnitTypeString(NYCE_UNIT_TYPE unitType);



/**
 *  @ingroup nhi_digital_io
 *
 *  @brief Define the active level for a digital input or output.
 *
 *  @param [in] nodeId       Node connection handle.
 *  @param [in] digIOId      Digital IO identifier.
 *  @param [in] activeState  Active level.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiDefineDigitalIOActiveState(NHI_NODE           nodeId,
                                                              NYCE_DIGITAL_IO_ID digIOId,
                                                              NYCE_ACTIVE_STATE  activeState);



/**
 *  @ingroup nhi_counters
 *
 *  @brief Define a digital input counter.
 *
 *  The counter value is initialized to zero.
 *
 *  @param [in]  nodeId             Node connection handle.
 *  @param [in]  slotId             Node slot identifier.
 *  @param [in]  counterId          Drive counter identifier.
 *  @param [in]  digIONr            Drive digital IO number.
 *  @param [in]  edgeType           Digital IO edge type.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiDefineDigitalInputCounter(NHI_NODE             nodeId,
                                                             NYCE_SLOT_ID         slotId,
                                                             NHI_DIGIN_COUNTER_ID counterId,
                                                             NYCE_DIG_IO_NR       digIONr,
                                                             NYCE_EDGE_TYPE       edgeType);



/**
 *  @ingroup nhi_counters
 *
 *  @brief Retrieve the definition of a specific digital input counter.
 *
 *  @param [in]  nodeId             Node connection handle.
 *  @param [in]  slotId             Node slot identifier.
 *  @param [in]  counterId          Drive counter identifier.
 *  @param [out] pDigIONr           Drive digital IO number.
 *  @param [out] pEdgeType          Digital IO edge type.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetDigitalInputCounter(NHI_NODE             nodeId,
                                                          NYCE_SLOT_ID         slotId,
                                                          NHI_DIGIN_COUNTER_ID counterId,
                                                          NYCE_DIG_IO_NR       *pDigIONr,
                                                          NYCE_EDGE_TYPE       *pEdgeType);



/**
 *  @ingroup nhi_counters
 *
 *  @brief Delete a specific digital input counter.
 *
 *  The counter value is set equal to -1.
 *
 *  @param [in] nodeId              Node connection handle.
 *  @param [in] slotId              Node slot identifier.
 *  @param [in] counterId           Drive counter identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiDeleteDigitalInputCounter(NHI_NODE             nodeId,
                                                             NYCE_SLOT_ID         slotId,
                                                             NHI_DIGIN_COUNTER_ID counterId);



/**
 *  @ingroup nhi_counters
 *
 *  @brief Start counting edges for a specific digital input counter.
 *
 *  Counting always starts from zero.
 *
 *  @param [in] nodeId              Node connection handle.
 *  @param [in] slotId              Node slot identifier.
 *  @param [in] counterId           Drive counter identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiStartDigitalInputCounter(NHI_NODE             nodeId,
                                                            NYCE_SLOT_ID         slotId,
                                                            NHI_DIGIN_COUNTER_ID counterId);



/**
 *  @ingroup nhi_counters
 *
 *  @brief Stop counting edges for a specific digital input counter.
 *
 *  The counter value is held until counting is restarted or until the counter is deleted.
 *
 *  @param [in] nodeId           Node connection handle.
 *  @param [in] slotId           Node slot identifier
 *  @param [in] counterId        Drive counter identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiStopDigitalInputCounter(NHI_NODE             nodeId,
                                                           NYCE_SLOT_ID         slotId,
                                                           NHI_DIGIN_COUNTER_ID counterId);



/**
 *  @ingroup nhi_latches
 *
 *  @brief Define a digital input as latch.
 *
 *  @param [in] nodeId       Node connection handle.
 *  @param [in] slotId       Node slot identifier.
 *  @param [in] latchPars    Latch configuration.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiDefineLatch(NHI_NODE       nodeId,
                                               NYCE_SLOT_ID   slotId,
                                               NHI_LATCH_PARS latchPars);



/**
 *  @ingroup nhi_latches
 *
 *  @brief Delete a digital input as latch.
 *
 *  @param [in] nodeId       Node connection handle.
 *  @param [in] slotId       Node slot identifier.
 *  @param [in] latchId      Node latch identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiDeleteLatch(NHI_NODE       nodeId,
                                               NYCE_SLOT_ID   slotId,
                                               NHI_LATCH_ID   latchId);



/**
 *  @ingroup nhi_latches
 *
 *  @brief Retrieve the defined latches and accompanying parameters.
 *
 *  @param [in]  nodeId              Node connection handle.
 *  @param [in]  slotId              Node slot identifier.
 *  @param [out] pNrOfDefinedLatches Number of defined latches
 *  @param [out] latchPars           size(NHI_NR_OF_LATCHES); usedSize(pNrOfDefinedLatches); Array with latch configuration.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetDefinedLatches(NHI_NODE       nodeId,
                                                     NYCE_SLOT_ID   slotId,
                                                     uint32_t       *pNrOfDefinedLatches,
                                                     NHI_LATCH_PARS latchPars[]);



/**
 *  @ingroup nhi_digital_io
 *
 *  @brief Define the type of output and related parameters.
 *
 *  @param [in] nodeId       Node connection handle.
 *  @param [in] digIOId      Digital IO identifier.
 *  @param [in] digOutType   Digital output type.
 *  @param [in] digOutPars   Digital output configuration.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiDefineDigitalOutputType(NHI_NODE           nodeId,
                                                           NYCE_DIGITAL_IO_ID digIOId,
                                                           NHI_DIGOUT_TYPE    digOutType,
                                                           NHI_DIGOUT_PARS    digOutPars);



/**
 *  @ingroup nhi_digital_io
 *
 *  @brief Retrieve the digital output type with digital output parameters.
 *
 *  @param [in]  nodeId          Node connection handle.
 *  @param [in]  digIOId         Digital IO identifier.
 *  @param [out] pDigOutType     Digital output type.
 *  @param [out] pDigOutPars     Digital output configuration.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetDigitalOutputType(NHI_NODE nodeId,
                                                        NYCE_DIGITAL_IO_ID digIOId,
                                                        NHI_DIGOUT_TYPE *pDigOutType,
                                                        NHI_DIGOUT_PARS *pDigOutPars);



/**
 *  @ingroup nhi_digital_io
 *
 *  @brief Set a digital output.
 *
 *  Depending on the type of output, this implies the following behavior:
 *  -    Output type STATE: The output is set to a constant level, the active state.
 *  -    Output type PULSE: The output is set to the active state.
 *       After the pulse time the output is made inactive again.
 *       If the output is set during the active state of the PULSE output, the pulse effectively restarts.
 *  -    Output type PWM: The output is set to the active state. After the on-delay, a block wave signal is
 *       set on the output with the specified frequency and duty cycle. If the output is set during the active
 *       state of the PWM output, the "set" effectively restarts with a new on-delay.
 *
 *  @param [in] nodeId       Node connection handle.
 *  @param [in] digIOId      Digital IO identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSetDigitalOutput(NHI_NODE           nodeId,
                                                    NYCE_DIGITAL_IO_ID digIOId);



/**
 *  @ingroup nhi_digital_io
 *
 *  @brief Clear a digital output.
 *
 *  This means that the output is set to the inactive state.
 *
 *  @param [in] nodeId       Node connection handle.
 *  @param [in] digIOId      Digital IO identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiClearDigitalOutput(NHI_NODE           nodeId,
                                                      NYCE_DIGITAL_IO_ID digIOId);



/**
 *  @ingroup nhi_digital_io
 *
 *  @brief Invert a digital output of type NYCE_DIGOUT_STATE.
 *
 *  For other output types, the function has no effect.
 *
 *  @param [in] nodeId       Node connection handle.
 *  @param [in] digIOId      Digital IO identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiToggleDigitalOutput(NHI_NODE           nodeId,
                                                       NYCE_DIGITAL_IO_ID digIOId);



/**
 *  @ingroup nhi_aspi
 *
 *  @brief Configure an ASPI port.
 *
 *  The function is only executed in the NHI_ASPI_NOT_CONFIGURED or NHI_ASPI_INACTIVE state.
 *
 *  @param [in] nodeId           Node connection handle.
 *  @param [in] slotId           Node slot identifier.
 *  @param [in] portId           ASPI port identifier.
 *  @param [in] pConfigPars      ASPI configuration.
 *
 *  @remarks After successful configuration, the state is always NHI_ASPI_INACTIVE.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSetASPIConfiguration(NHI_NODE                     nodeId,
                                                        NYCE_SLOT_ID                 slotId,
                                                        NHI_ASPI_PORT_ID             portId,
                                                        const NHI_ASPI_CONFIG_PARS  *pConfigPars);



/**
 *  @ingroup nhi_aspi
 *
 *  @brief Start a write cycle on an ASPI port.
 *
 *  The function is only executed if the port type is NHI_ASPI_MASTER_WRITE, and in addition, the port state is NHI_ASPI_INACTIVE.
 *  The latter results in an asynchronous error. The data to be transmitted is contained in array aspiData[].
 *  The number of bits to be transmitted is set during configuration. If N is the number of bits,
 *  the first bit transmitted is the most significant bit (bit 7) of aspiData[(N-1)/8]. The last bit
 *  transmitted is bit 8*((N+7)/8) -N of aspiData[0].
 *
 *  @param [in] nodeId       Node connection handle.
 *  @param [in] slotId       Node slot identifier.
 *  @param [in] portId       ASPI port identifier.
 *  @param [in] aspiDataSize Number of bits to write.
 *  @param [in] aspiData     size(aspiDataSize); Data to write.
 *
 *  @remarks After successful termination of this function, the ASPI state changes to NHI_ASPI_ACTIVE
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiStartWriteASPIData(NHI_NODE          nodeId,
                                                      NYCE_SLOT_ID      slotId,
                                                      NHI_ASPI_PORT_ID  portId,
                                                      int32_t           aspiDataSize,
                                                      const char        aspiData[]);



/**
 *  @ingroup nhi_aspi
 *
 *  @brief Start a read cycle on an ASPI port.
 *
 *  The function is only executed if the port type is NHI_ASPI_MASTER_READ and in addition, the port state is NHI_ASPI_INACTIVE,
 *  OR if the port type is NHI_ASPI_SLAVE_READ and the port state is NHI_ASPI_PENDING. If the port type is invalid, but the state is not,
 *  the function results in an asynchronous error.
 *
 *  @param [in] nodeId       Node connection handle.
 *  @param [in] slotId       Node slot identifier.
 *  @param [in] portId       ASPI port identifier.
 *
 *  @remarks After successful termination of this function, the ASPI state changes to NHI_ASPI_ACTIVE
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiStartReadASPIData(NHI_NODE         nodeId,
                                                     NYCE_SLOT_ID     slotId,
                                                     NHI_ASPI_PORT_ID portId);



/**
 *  @ingroup nhi_aspi
 *
 *  @brief Retrieve the last data read via a "read" port.
 *
 *  The data can only be retrieved if the port is in the NHI_ASPI_INACTIVE state. The data received is copied to array aspiData[].
 *  The number of bits received has been set during configuration. If N is the number of bits,
 *  the first bit received is stored in the most significant bit (bit 7) of aspiData[(N-1)/8].
 *  The last bit received is stored in bit 8*((N+7)/8) -N of aspiData[0]. The remaining bits
 *  of aspiData[0] as well as the contents of aspiData[i] with i greater than (N-1)/8 is undefined.
 *
 *  @param [in]  nodeId          Node connection handle.
 *  @param [in]  slotId          Node slot identifier.
 *  @param [in]  portId          ASPI port identifier.
 *  @param [in]  aspiNrOfBytes   Number of bytes to read
 *  @param [out] aspiData        size(aspiNrOfBytes); Data read.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetASPIData(NHI_NODE         nodeId,
                                               NYCE_SLOT_ID     slotId,
                                               NHI_ASPI_PORT_ID portId,
                                               int32_t          aspiNrOfBytes,
                                               char             aspiData[]);



/**
 *  @ingroup nhi_events
 *
 *  @brief Synchronize the application with the specified request.
 *
 *  @param [in] nodeId       Node connection handle.
 *  @param [in] slotId       Node slot identifier.
 *  @param [in] requestId    Node sync request identifier.
 *  @param [in] timeOut      Timeout (use NHI_INDEFINITE to wait forever) [s].
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSynchronize(NHI_NODE         nodeId,
                                               NYCE_SLOT_ID     slotId,
                                               NHI_SYNC_REQUEST requestId,
                                               double           timeOut);

/**
 *  @ingroup nhi_expansion_module
 *
 *  @brief Retrieve the type of the expansion module and its encoder signal range.
 *
 *  Compatible with NY4120, NY4130 or NY4140 drive module.
 *  If no expansion module is found, the signal range will be 0 Vtt and the expansion module
 *  will be set to NYCE_NO_EXPANSION_MODULE.
 *
 *  @param [in]  nodeId          Node connection handle.
 *  @param [in]  slotId          Node slot identifier.
 *  @param [out] pModuleType     Expansion module type.
 *  @param [out] pSignalRange    Signal range.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetExpansionModule(NHI_NODE                      nodeId,
                                                      NYCE_SLOT_ID                  slotId,
                                                      NYCE_EXPANSION_MODULE_TYPE    *pModuleType,
                                                      double                        *pSignalRange);

/**
 *  @ingroup nhi_configuration
 *
 *  @brief Retrieve the status of the SERCOS network.
 *
 *  Status for all devices connected to the  NY4150 SERCOS III Master module and the number of IndraDrives in the SERCOS network.
 *  For every detected IndraDrive the drive unit number, device type and device status is retrieved.
 *
 *  @param [in]  nodeId          Node connection handle.
 *  @param [out] pSercosNetwork  SERCOS III network status.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetIndraDrives(NHI_NODE              nodeId,
                                                  NHI_SERCOS_NETWORK    *pSercosNetwork);

/**
 *  @ingroup nhi_configuration
 *
 *  @brief Wait on SERCOS network ready.
 *
 *  Wait until all IndraDrives in the SERCOS network, connected to the NY4150 SERCOS III Master module, are ready.
 *
 *  @param [in] nodeId   Node connection handle.
 *  @param [in] timeOut  Timeout (use NHI_INDEFINITE to wait forever) [s].
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiWaitOnSercosNetworkReady(NHI_NODE nodeId,
                                                            double   timeOut);

/**
 *  @ingroup nhi_miscellaneous
 *
 *  @brief Enable/disable node context logging.
 *
 *  @param [in] nodeId   Node connection handle.
 *  @param [in] enable   TRUE = enable, FALSE = disable
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiEnableContextLogging(NHI_NODE          nodeId,
                                                        BOOL              enable);

/**
 *  @ingroup nhi_miscellaneous
 *
 *  @brief  Get context logging statistics.
 *
 *  @param [in]  nodeId             Node connection handle.
 *  @param [out] pStats             Context logging statistics.
 */
NHI_EXPORT NYCE_STATUS NhiGetContextLoggingStats(NHI_NODE                      nodeId, 
                                                 NHI_CONTEXT_LOGGING_STATS*    pStats);

/**
 *  @ingroup nhi_miscellaneous
 *
 *  @brief Retrieve node context logging.
 *
 *  Node context logging will be stopped.
 *
 *  @param [in]  nodeId             Node connection handle.
 *  @param [in]  nrOfElements       Number of NHI_CONTEXT_LOG items pContextLogBuffer can hold.
 *  @param [out] contextLogBuffer   size(nrOfElements); Buffer with retrieved context logging.
 *  @param [out] pNrOfLogsRead      Number of context logs read.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetContextLogging(NHI_NODE          nodeId,
                                                     uint32_t          nrOfElements,
                                                     NHI_CONTEXT_LOG   contextLogBuffer[],
                                                     uint32_t          *pNrOfLogsRead);

/**
 *  @ingroup nhi_miscellaneous
 *
 *  @brief Save node context logging to file in CSV format.
 *
 *  Node context logging will be stopped.
 *
 *  @param [in]  nodeId             Node connection handle.
 *  @param [in]  pFileName          FileName to save logging to.
 *  @param [in]  appendFile         TRUE = append to file, FALSE = create new file.
 *  @param [out] pNrOfLogsRead      Number of context logs read.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSaveContextLoggingToFile(NHI_NODE          nodeId,
                                                            const char        *pFileName,
                                                            BOOL              appendFile,
                                                            uint32_t          *pNrOfLogsRead);




/**
 *  @ingroup nhi_variable_latch_set
 *
 *  @brief Add an NHI variable to a latch set.
 *
 *  @param [in]  nodeId        Node connection handle.
 *  @param [in]  latchSetId    Latch set identifier.
 *  @param [in]  varId         NHI Variable to add.
 *  @param [out] pIndex        Returned index, at which this variable is added in the latch set.
 *                             Using this index, the value can be located in the returned array
 *                             of latched values returned by \ref NhiReadLatchSetValues.
 *
 *  @remarks
 *  Adding variables is only allowed in the NHI_LATCH_SET_STATE_IDLE state.
 *  There are \ref NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE sets per node.
 *  The latchSetId must be in the range [0..NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE-1].
 *  There may be \ref NYCE_MAX_NR_OF_VARIABLES_PER_LATCH_SET variables in one latch set. When
 *  more variables are needed, you can use more latch sets using the same event condition
 *  when activating.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiAddVarToLatchSet(NHI_NODE    nodeId,
                                                    uint32_t    latchSetId,
                                                    NHI_VAR_ID  varId,
                                                    uint32_t   *pIndex);

/**
 *  @ingroup nhi_variable_latch_set
 *
 *  @brief Clear the latch set.
 *
 *  All variables are removed from the set and the latch set state becomes NHI_LATCH_SET_STATE_IDLE.
 *
 *  @param [in] nodeId        Node connection handle.
 *  @param [in] latchSetId    Latch set identifier.
 *
 *  @remarks
 *  There are \ref NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE sets per node.
 *  The latchSetId must be in the range [0..NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE-1].
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiClearLatchSet(NHI_NODE  nodeId,
                                                 uint32_t  latchSetId);

/**
 *  @ingroup nhi_variable_latch_set
 *
 *  @brief Clear all latch sets on the node.
 *
 *  @param [in] nodeId        Node connection handle.
 *
 *  @remarks
 *  There are \ref NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE sets per node.
 *  The latchSetId must be in the range [0..NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE-1]
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiClearAllLatchSets(NHI_NODE nodeId);


/**
 *  @ingroup nhi_variable_latch_set
 *
 *  @brief Retrieve the number of variables which are defined in a set.
 *
 *  @param [in]  nodeId            Node connection handle.
 *  @param [in]  latchSetId        Latch set identifier.
 *  @param [out] pNrOfVariables    Number of variables.
 *
 *  @remarks
 *  There are \ref NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE sets per node.
 *  The latchSetId must be in the range [0..NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE-1].
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetLatchSetNrOfVars(NHI_NODE   nodeId,
                                                       uint32_t   latchSetId,
                                                       uint32_t  *pNrOfVariables);

/**
 *  @ingroup nhi_variable_latch_set
 *
 *  @brief Retrieve the latch set state.
 *
 *  @param [in]  nodeId            Node connection handle.
 *  @param [in]  latchSetId        Latch set identifier.
 *  @param [out] pLatchSetState    state of the latch set.
 *
 *  @remarks
 *  There are \ref NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE sets per node.
 *  The latchSetId must be in the range [0..NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE-1]
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiGetLatchSetState(NHI_NODE              nodeId,
                                                    uint32_t              latchSetId,
                                                    NHI_LATCH_SET_STATE  *pLatchSetState);

/**
 *  @ingroup nhi_variable_latch_set
 *
 *  @brief Activate a latch set using a node event.
 *
 *  The state will become NHI_LATCH_SET_STATE_ARMED. When the given event is triggered,
 *  the variables are all latched at once after which the state will be NHI_LATCH_SET_STATE_READY.
 *
 *  @param [in] nodeId            Node connection handle.
 *  @param [in] latchSetId        Latch set identifier.
 *  @param [in] eventId           Node event identifier.
 *
 *  @remarks
 *  The latch set must be in the NHI_LATCH_SET_STATE_IDLE when this function is called.
 *  There are \ref NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE sets per node.
 *  The latchSetId must be in the range [0..NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE-1]
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiActivateLatchSet(NHI_NODE   nodeId,
                                                    uint32_t   latchSetId,
                                                    NYCE_EVENT eventId);

/**
 *  @ingroup nhi_variable_latch_set
 *
 *  @brief Deactivate a latch.
 *
 *  The state will become NHI_LATCH_SET_STATE_IDLE.
 *
 *  @param [in] nodeId            Node connection handle.
 *  @param [in] latchSetId        Latch set identifier.
 *
 *  @remarks
 *  The latch set must be in the NHI_LATCH_SET_STATE_ARMED or NHI_LATCH_SET_STATE_READY
 *  when this function is called.
 *  There are \ref NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE sets per node.
 *  The latchSetId must be in the range [0..NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE-1]
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiDeactivateLatchSet(NHI_NODE  nodeId,
                                                      uint32_t  latchSetId);

/**
 *  @ingroup nhi_variable_latch_set
 *
 *  @brief Retrieve the latched values if the latch occurred.
 *
 *  @param [in]   nodeId              Node connection handle.
 *  @param [in]   latchSetId          Latch set identifier.
 *  @param [out]  arrValues           size(arraySize); Array containing the values of the latched variables.
 *  @param [in]   arraySize           Size of the number of allocated elements in arrValues.
 *  @param [out]  pActualNrOfValues   Actual number of returned values in arrValues.
 *
 *  @remarks
 *  The latch set must be in the NHI_LATCH_SET_STATE_READY state when this function is called.
 *  The array arrValues must be pre-allocated. Its allocated size (in elements) is defined by arraySize.
 *  Using the index which is returned when a variable is added you can identify the correct
 *  value with the correct variable.
 *  There are \ref NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE sets per node.
 *  The latchSetId must be in the range [0..NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE-1]
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiReadLatchSetValues(NHI_NODE   nodeId,
                                                      uint32_t   latchSetId,
                                                      double     arrValues[],
                                                      uint32_t   arraySize,
                                                      uint32_t  *pActualNrOfValues);



/**
 *  @ingroup nhi_sdc
 *
 *  @brief Customer specific function.
 *
 *  @param [in]   nodeId              Node connection handle.
 *  @param [in]   slotId              Node slot identifier.
 *  @param [in]   portId              SDC port identifier.
 *  @param [in]   sdcId               SDC channel identifier.
 *  @param [in]   clockFrequency      clock frequency [Hz].
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSdcInitialize(NHI_NODE nodeId,
                                                 NYCE_SLOT_ID slotId,
                                                 NHI_SDC_PORT_ID portId,
                                                 NHI_SDC_CHANNEL_ID sdcId,
                                                 uint32_t clockFrequency);

/**
 *  @ingroup nhi_sdc
 *
 *  @brief Customer specific function.
 *
 *  @param [in]   nodeId      Node connection handle.
 *  @param [in]   sdcId       SDC identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSdcShutdown(NHI_NODE nodeId,
                                               NHI_SDC_CHANNEL_ID sdcId);

/**
 *  @ingroup nhi_sdc
 *
 *  @brief Customer specific function.
 *
 *  @param [in]   nodeId      Node connection handle.
 *  @param [in]   sdcId       SDC identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSdcStartReceivingSyncData(NHI_NODE nodeId,
                                                             NHI_SDC_CHANNEL_ID sdcId);

/**
 *  @ingroup nhi_sdc
 *
 *  @brief Customer specific function.
 *
 *  @param [in]   nodeId      Node connection handle.
 *  @param [in]   sdcId       SDC identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSdcStopReceivingSyncData(NHI_NODE nodeId,
                                                            NHI_SDC_CHANNEL_ID sdcId);

/**
 *  @ingroup nhi_sdc
 *
 *  @brief Customer specific function.
 *
 *  @param [in]   nodeId      Node connection handle.
 *  @param [in]   sdcId       SDC identifier.
 *  @param [in]   blockId     SDC memory block identifier.
 *  @param [in]   address     address to read from.
 *  @param [out]  pData       Data read.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSdcReadMemory(NHI_NODE nodeId,
                                                 NHI_SDC_CHANNEL_ID sdcId,
                                                 NHI_SDC_MEMORY_BLOCK_ID blockId,
                                                 uint32_t address,
                                                 uint32_t *pData);
/**
 *  @ingroup nhi_sdc
 *
 *  @brief Customer specific function.
 *
 *  @param [in]   nodeId      Node connection handle.
 *  @param [in]   sdcId       SDC identifier.
 *  @param [in]   blockId     SDC memory block identifier.
 *  @param [in]   address     address to write to.
 *  @param [in]   data        Data to write.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSdcWriteMemory(NHI_NODE nodeId,
                                                  NHI_SDC_CHANNEL_ID sdcId,
                                                  NHI_SDC_MEMORY_BLOCK_ID blockId,
                                                  uint32_t address,
                                                  uint32_t data);
/**
 *
 *  @ingroup nhi_sdc
 *  @brief Customer specific function.
 *
 *  @param [in]   nodeId      Node connection handle.
 *  @param [in]   sdcId       SDC identifier.
 *  @param [out]  pError      Error code.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSdcGetGeneralError(NHI_NODE nodeId,
                                                      NHI_SDC_CHANNEL_ID sdcId,
                                                      uint32_t *pError);

/**
 *
 *  @ingroup nhi_sdc
 *  @brief Customer specific function.
 *
 *  @param [in]   nodeId      Node connection handle.
 *  @param [in]   sdcId       SDC identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSdcReset(NHI_NODE nodeId,
                                            NHI_SDC_CHANNEL_ID sdcId);

/**
 *  @ingroup nhi_sdc
 *
 *  @brief Customer specific function.
 *
 *  @param [in]   nodeId      Node connection handle.
 *  @param [in]   sdcId       SDC identifier.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiSdcClearError(NHI_NODE nodeId,
                                                 NHI_SDC_CHANNEL_ID sdcId);



/**
 *  @ingroup nhi_camming
 *
 *  @brief Define memory to store cam tables.
 *
 *  @param [in]   nodeId                  Node connection handle.
 *  @param [in]   nrOfTables              Number of elements in camTableDefinitions.
 *  @param [in]   camTableDefinitions     size(nrOfTables); Array of cam table definitions.
 *
 *  @remarks
 *  The total memory for cam tables is available statically, with a fixed maximum size, in the firmware.
 *  This function claims a memory area from the table memory of the defined sizes and types for the issued tables.
 *  When this results in an overflow of the total memory, this function returns a memory overflow error.
 *  This function can be called several times as long as the specified table ids are not yet defined for the node.
 *
 *  camTableDefinitions is an array of cam table definitions, where each element defines the properties of a single table.
 *  The function may be called for several times in succession, as long as the tableIds specified in camTables are unique,
 *  and the total number of tables does not exceed the maximal number of tables.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiEcgDefineCamMemory(NHI_NODE                      nodeId,
                                                      uint32_t                      nrOfTables,
                                                      const NHI_ECG_CAM_TABLE_DEF   camTableDefinitions[]);

/**
 *  @ingroup nhi_camming
 *
 *  @brief Delete the memory definition to store cam tables.
 *
 *  @param [in]   nodeId      Node connection handle.
 *
 *  @remarks
 *  The total memory for all allocated cam tables on a node is freed.
 *  The memory can only be released when no axes on the node are camming
 *  (which implies that a table is currently in use).
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiEcgDeleteCamMemory(NHI_NODE  nodeId);

/**
 *  @ingroup nhi_camming
 *
 *  @brief Download a cam table to the node.
 *
 *  @param [in]   nodeId      Node connection handle.
 *  @param[in]    pCamTable   Structure that holds the camming table.
 *
 *  @remarks
 *  The cam table data defined by camTable will be downloaded for table pCamTable->tableId
 *  to the previously allocated cam table memory.
 *  Any existing cam table data in the table memory will be overwritten.
 *
 *  If the cam table on the node is currently in use, an error is returned.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiEcgDownloadCamTable(NHI_NODE 		        nodeId,
                                                       const NHI_ECG_CAM_TABLE  *pCamTable);

/**
 *  @ingroup nhi_camming
 *
 *  @brief Download a cam table from an XML file to the node.
 *
 *  @param [in]   nodeId      Node connection handle.
 *  @param [in]   tableId     Cam table identifier.
 *                           The table must be allocated previously using NhiEcgDefineCamMemory.
 *  @param [in]   pFileName   The file name of the XML file.
 *
 *  @remarks
 *  The cam table data will be read from the XML file defined by pFileName
 *  and will be downloaded to the cam table memory, defined by tableId.
 *  Any existing cam table data in the table memory will be overwritten.
 *
 *  If the cam table on the node is currently in use, an error is returned.
 */
NHI_EXPORT NYCE_STATUS NYCE_API NhiEcgDownloadCamTableFromFile(NHI_NODE     nodeId,
                                                               uint32_t     tableId,
                                                               const char*  pFileName);



#ifdef __cplusplus
    }
#endif

/** @} */

#endif /* __NHIAPI_H__ */
