/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2012
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: NYCE
 *  %full_filespec:    nyceapi.h`56:incl:1 % (SYNERGY INFO, do not change)
 */
/**
 *  @file
 *  @brief Generic public interface to NYCe4000
 */
#ifndef __NYCEAPI_H__
#define __NYCEAPI_H__

#include "nycedefs.h"
#include "nycetypes.h"

/*!
 * \mainpage NYCe4000
 *
 * This is the software reference manual for the NYCe4000 system. Read the 
 * <A HREF="modules.html">Modules</A> page to get an overview of the 
 * functionality of the NYCe4000 system.
 */

/**
 *  @defgroup nyce NYCe4000 (NYCE)
 *
 *  Generic public interface to NYCe4000
 *
 *  @{
 */

#ifdef __cplusplus
extern "C"
{
#endif

/*-----------------------------------------------------------------------
 * GLOBAL DEFINES
 *-----------------------------------------------------------------------
 */
    /* If NYCE is defined, the functions are exported, otherwise they are imported */
#ifndef NYCE_EXPORT
    #ifdef NYCE
        #define NYCE_EXPORT __declspec(dllexport)
    #else
        #define NYCE_EXPORT __declspec(dllimport)
    #endif
#endif



/*-----------------------------------------------------------------------
 * GLOBAL DATA TYPES
 *-----------------------------------------------------------------------
 */

/* Initialize and Terminate --------------------------------------------------------------------------------*/
/**
 * @defgroup nyce_initialize_and_terminate Initialize and Terminate
 *
 * Any application that uses NYCe4000 API functions must first call the nyce
 * initialization function to initialize the NYCe4000 host software and claim
 * required resources. Likewise, the application must call the nyce termination
 * function to release all claimed resources.
 *
 */

/* Variable Trace --------------------------------------------------------------------------------*/
/**
 * @defgroup nyce_variable_trace Variable Trace
 *
 * The NYCE subsystem includes trace functionality, which allows tracing variables of different 
 * subsystems, for example SAC and NHI. 
 * The trace sample frequency, trace buffer depth and maximum number of traceable variables 
 * per trace sample are specified using a trace definition. After defining the trace, variables can be 
 * added to and removed from the trace definition. 
 * The trace can be started and stopped successively. While the trace is running,
 * data is collected in the trace buffers. When the buffer is full, the oldest data is removed before new 
 * data is stored.
 *
 * Trace data can be retrieved from the trace buffer, even while the trace is running.  
 * Each NYCe4000 process (application) has its own trace definition, but only one trace 
 * definition per process can exist at any given moment. 
 */

/* Variable Set --------------------------------------------------------------------------------*/
/**
 * @defgroup nyce_variable_set Variable Set
 *
 * The NYCE subsystem contains functionality to synchronously read a set of variables from the other 
 * subsystems, for example SAC and NHI. The read values are guaranteed to be time synchronous, that is,
 * from the same sample moment of the nodes. 
 * The variable set is based on the Trace functionality. Therefore, any constraint which applies to 
 * the Trace also applies to the variable set. As a consequence, the variable set functions may return trace 
 * related errors.
 *
 * It is important to understand that the variable set will not return the most recent known 
 * variable values on the nodes. Because the trace system incorporates several buffering levels, a 
 * noticeable latency will occur. The variable set only guarantees that multiple variables are read 
 * at the same time, that is same node sample number, even if multiple nodes are used. When the actual 
 * time of the values is important, the NHI_VAR_NODE_SAMPLE_NUMBER variable can be used in the 
 * variable set.
 * 
 */

/* Exclusive write ----------------------------------------------------------------------------*/
/**
 * @defgroup nyce_excl_write Exclusive Write
 *
 * The NYCE subsystem includes functionality to control write access to the node. 
 * This is done by granting exclusive write access to a single host process. When a host process
 * has obtained this right, other host processes are locked out from initiating write operations.
 *
 */

/* Miscellaneous --------------------------------------------------------------------------------*/
/**
 * @defgroup nyce_miscellaneous Miscellaneous
 *
 */

/* Conversion --------------------------------------------------------------------------------*/
/**
 * @defgroup nyce_conversion Conversion
 *
 * The functions within this module convert strings to enumeration values and vice versa.
 *
 */


/*-----------------------------------------------------------------------
 * GLOBAL FUNCTIONAL PROTOTYPES
 *-----------------------------------------------------------------------
 */
/**
 *  @addtogroup nyce_initialize_and_terminate
 *  @{
 */

/**
 *  @brief  Initialize the Nyce4000 software.
 *
 *  The function initializes all NYCe4000 subsystems. The initialization is refcounted,
 *  meaning that NyceTerm() should be called for every successful call to NyceInit().
 *
 *  The actual used network type is determined in the following order:
 *  - If another application has already initialized NYCE, the networkType parameter is ignored.
 *  - If this is the first application initializing NYCE, the specified networkType will be used.
 *    - If the specified networkType is NYCE_NET, the network will be initialized with NYCE_SIM, NYCE_ETH or NYCE_FIWI if this is the preferred network type.
 *
 *  @param[in]  networkType     The type of network to use.
 *
 *  @retval NYCE_OK
 *  @retval NYCE_WRN_ALREADY_INITIALIZED    NyceInit was already called before.
 *  @retval NYCE_WRN_SIM_USED               Another NYCE application already initialized with NYCE_SIM.
 *  @retval NYCE_WRN_ETH_USED               Another NYCE application already initialized with NYCE_ETH.
 *  @retval NYCE_WRN_FIWI_USED              Another NYCE application already initialized with NYCE_FIWI.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceInit(NYCE_NETWORK_TYPE networkType);


/**
 *  @brief Terminate the NYCe4000 software.
 *
 *  The function terminates all NYCe4000 subsystems.
 *
 *  @retval NYCE_OK
 *  @retval NYCE_ERR_NOT_INITIALIZED        NyceInit() was not called before or NyceTerm() is called more often.
 *  @retval NYCE_WRN_NOT_TERMINATED         NyceInit() is called more often than NyceTerm().
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceTerm(void);


/**
 *  @brief  Retrieve the current initialized network type of the NYCE subsystem.
 *
 *  If the NYCE subsystem is not yet initialized, the preferred network type will be retrieved
 *  from the registry. @see NyceSetPreferredNetworkType().
 *
 *  @param[out] pNetworkType    The current network type.
 *
 *  @retval NYCE_OK
 *  @retval NYCE_WRN_NO_NETWORK_INITIALIZED     The NYCE network is not initialized; the preferred type is retrieved from the registry.
 *  @retval NCS_ERR_INVALID_PARAMETER           pNetworkType is not valid; NULL pointer.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceGetNetworkType(NYCE_NETWORK_TYPE* pNetworkType);


/**
 *  @brief  Set the preferred network type.
 *
 *  Store the preferred network type in the registry. @see NyceGetNetworkType().
 *
 *  @param[in]  networkType             The preferred network type. Note that NYCE_NET is not accepted as preferred type.
 *
 *  @retval NYCE_OK
 *  @retval NCS_ERR_OS_ERROR            Failed to add the preferred type to the registry (check user privileges: local admin rights are needed to write to the registry).
 *  @retval NCS_ERR_INVALID_PARAMETER   The specified networkType is not valid.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceSetPreferredNetworkType(NYCE_NETWORK_TYPE networkType);

/**
 *  @brief  Retrieve the preferred network type.
 *
 *  The preferred network type is retrieved from the registry. @see NyceSetPreferredNetworkType().
 *
 *  @param[out]  pNetworkType           The preferred network type.
 *
 *  @retval NYCE_OK
 *  @retval NCS_ERR_INVALID_PARAMETER   pNetworkType is not valid; NULL pointer.
 *
 *  @remarks    If no network type is stored in the registry, the default network type NYCE_ETH will be returned.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceGetPreferredNetworkType(NYCE_NETWORK_TYPE* pNetworkType);

/** @} */

/**
 *  @addtogroup nyce_miscellaneous
 *  @{
 */

/**
 * @brief Get the version of the NYCE subsystem.
 *
 * This function returns the version of the NYCE subsystem.
 *
 * @param [out] pVersion - pointer to a pre-allocated buffer to store the version (NYCE_VERSION_TYPE)
 *
 * @remarks None.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceGetVersion(NYCE_VERSION_TYPE* pVersion);



/**
 * @brief Check the version of the current running NYCE subsystem against a specific version.
 *
 * This function compares the specified version with the version of the NYCE subsystem.
 *
 * @param [in] pApplVersion - pointer to the version to be checked (NYCE_VERSION_TYPE)
 *
 * @remarks None.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceCheckApplVersion(const NYCE_VERSION_TYPE* pApplVersion);



/** @} */

/**
 *  @addtogroup nyce_variable_set
 *  @{
 */

/**
 * @brief Get the variable id and its value from the variable set.
 *
 * @param [in]  variableIndex       Identifies the variable in the variable set. 
 *                                  The index of a variable is returned when the variable was added to the variable set. 
 *
 * @param [out] pVarSetElement      Pointer to a NYCE_VAR_SET_ELEMENT structure, which receives the variable information
 *                                  and value.
 *                                   
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_ERR_INVALID_VARIABLE_INDEX    No variable exists at the specified variable index or 
 *                                                  the specified index was invalid. 
 *
 * @remarks     
 *      The variable set size is defined by NYCE_VAR_SET_SIZE. 
 *      The specified variable index must be smaller than this maximum. 
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceReadVariableSetElement(uint32_t                variableIndex,
                                                            NYCE_VAR_SET_ELEMENT*   pVarSetElement);



/**
 * @brief Get the values for a range of variables in the variable set.
 *
 * @param [in]  firstIndex      Index of the first variable in the variable set to retrieve.
 *
 * @param [in]  lastIndex       Index of the last variable in the variable set to retrieve.
 *                              Note that lastIndex >= firstIndex must apply and that the returned 
 *                              data includes the variable at lastIndex.
 *
 * @param [out] varValue        size((lastIndex - firstIndex + 1));  Allocated array of doubles, 
 *                              which receives the values of the variables. 
 *                              Its size must be at least lastIndex - firstIndex + 1.
 *                              varValue[0] gets the value of the variable with index 'firstIndex'.
 *                              If no variable exists at a specific location, NYCE_NAN is stored at 
 *                              the corresponding location in this array.
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_ERR_INVALID_VARIABLE_INDEX    one of the specified indexes was invalid. Note that lastIndex
 *                                                  must be larger or equal to firstIndex, and both must be smaller 
 *                                                  than NYCE_VAR_SET_SIZE.
 * @retval      TRACE_ERR_NO_VARIABLES_DEFINED      The specified range does not contain any variable.
 * @retval      TRACE_WRN_NO_VARIABLE_AT_INDEX      At least one location in the specified range does not contain 
 *                                                  a variable, but some other locations do have a variable defined.
 *                                                  This means that the output contains both valid and invalid (NYCE_NAN) data.
 *
 * @remarks     None.
 *
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceReadVariableSet(uint32_t   firstIndex,
                                                     uint32_t   lastIndex,
                                                     double     varValue[]);


/**
 * @brief Removes a variable from the variable set.
 *
 * @param [in]  variableIndex       Index of the variable in the variable set to delete.
 *                                  The index of a variable is returned when a variable is added to the variable set. 
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_ERR_INVALID_VARIABLE_INDEX    No variable exists at the specified variable index or 
 *                                                  a specified index was invalid.
 * @remarks     None.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceDeleteVariableFromSet(uint32_t variableIndex);

/** @} */

/**
 *  @addtogroup nyce_variable_trace
 *  @{
 */

/**
 * @brief Defines the trace using a maximum number of variables, trace sample frequency and buffer depth.
 *
 * @param [in]  pNyceTraceDefinition                Pointer to a NYCE_TRACE_DEFINITION struct, containing the settings for the trace.
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_ERR_INVALID_STATE             The trace state is invalid. It must be NYCE_TRACE_IDLE.
 * @retval      TRACE_ERR_INVALID_FREQUENCY         The specified frequency is invalid. Note that only a limited set of valid 
 *                                                  frequencies is defined, see NYCE_TRACE_DEFINITION.
 * @retval      TRACE_ERR_INVALID_PARAMETER         Some input values are zero.
 * @retval      TRACE_ERR_NR_OF_VARIABLES_TOO_LARGE The specified maximum number of variables is too large.
 * @retval      TRACE_ERR_BUFFER_TOO_LARGE          The buffer size is too large. 
 *                                                  The buffer size can not exceed 512 MByte.
 * @retval      TRACE_ERR_OUT_OF_MEMORY             The trace buffer could not be allocated.
 *  
 * @remarks 
 *      This function can only be called when the trace state is NYCE_TRACE_IDLE.
 *      After a successful trace definition, the trace state changes to NYCE_TRACE_READY.
 *
 *      The trace buffer size is limited to 512 Mbyte. Trace buffers of all processes are allocated in the n4kservice process, 
 *      which may constrain the system global trace buffer allocation of all tracing applications.
 *
 *      Each process can have only one trace defined at any moment. 
 *      Defining the trace:
 *          - Sets the maximum number of variables to trace, which defines the size (in values) of one trace sample.
 *          - Sets the trace buffer depth, which defines the largest number of trace samples that can be stored 
 *            without data being lost while the trace is running. 
 *          - Sets the trace sample frequency, which defines the rate of storing trace samples in the trace buffer. 
 *            The trace frequency can range from 1 Hz up to 32 kHz. When the trace frequency is defined as zero, the 
 *            actual trace frequency is determined automatically and dynamically as being the fastest update frequency 
 *            on the node of the selected trace variables. For HSD (High-Speed Data) variables, this can be up to 32 kHz.
 *            For non-HSD variables, this can be up to 8 kHz.
 *
 *      Variables to be traced are added to the trace using the functions XxxAddVariableToTrace and can be removed from the
 *      trace with the functions XxxDeleteVariableFromTrace in the SAC and NHI subsystem (Xxx = Sac or Nhi).
 *
 *      When variables are added, the trace can be started and stopped and trace data can be retrieved.
 *
 *      Use NyceDeleteTrace to delete the trace. If you want to redefine the trace, you must delete the trace first.
 *
 * @see     NYCE_TRACE_DEFINITION
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceDefineTrace(const NYCE_TRACE_DEFINITION* pNyceTraceDefinition);



/**
 * @brief Start filling the trace buffer with trace samples.
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_ERR_INVALID_STATE             The trace state is invalid. It must be NYCE_TRACE_READY.
 * @retval      TRACE_ERR_NO_VARIABLES_DEFINED      No variables are defined. 
 *
 * @remarks 
 *      This function can only be called in the NYCE_TRACE_READY state. If it succeeds, the 
 *      NYCE_TRACE_RUNNING state is entered.
 *
 *      When the trace is started, the timeCounter of the trace status is reset to zero and the 
 *      trace buffer is emptied, that is, nrOfValidSamples is reset to zero. 
 *      
 *      If the sample frequency in the trace definition is set to zero, the trace frequency is 
 *      determined automatically. In this case, the frequency of the fastest updating variable is 
 *      selected as the trace frequency. The actual used trace frequency is reported by the traceSampleTime 
 *      field in the trace info, and is locked when the trace is started. 
 *      While the trace is running or stopping, or while there is data available in the trace buffer, the 
 *      traceSampleTime is not changed.
 *      If a High-Speed Data variable is selected and its axis is not (yet) configured as 'PVL on the drive', 
 *      the actual trace frequency is forced to 32 kHz if the trace definition used zero for the trace 
 *      frequency. 
 *
 *      While trace is running or stopping, the trace buffer is being filled. The timeCounter of 
 *      the trace info is incremented by one for each stored trace sample.
 *      Also the nrOfValidSamples is incremented, but only up to the specified buffer size.
 *      
 * @see NYCE_TRACE_INFO
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceStartTrace(void);



/**
 * @brief Stop tracing after a specific delay.
 *
 * @param [in]  traceStopDelay          Delay in seconds before trace data collection actually stops.
 *                                      Although it may seem that if the delay is zero, the trace state will be 
 *                                      NYCE_TRACE_READY, it is actually set to NYCE_TRACE_STOPPING.
 *                                      This is due to the several levels of trace buffering. The most recent trace data may 
 *                                      not yet be available in the trace buffer, but is still queued for example 
 *                                      on the node or in the driver.
 *                                  
 *                                      To force the state NYCE_TRACE_READY immediately, specify -1.0 for the delay.
 *                                      The trace stops immediately, discarding any queued trace data, which is not yet available 
 *                                      in the trace buffer.
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_ERR_INVALID_STATE         The trace state is invalid. It must be NYCE_TRACE_RUNNING or NYCE_TRACE_STOPPING.
 * @retval      TRACE_ERR_INVALID_PAARAMETER    The stop delay must be equal or greater then zero, or -1.0.
 *
 * @remarks 
 *      This function can only be called in NYCE_TRACE_STOPPING or NYCE_TRACE_RUNNING state.
 *      If it succeeds, the trace state enters either NYCE_TRACE_STOPPING or NYCE_TRACE_READY.
 *
 *      While the trace state is NYCE_TRACE_STOPPING, data is still collected in the trace buffer.
 *
 *      The triggerTime field in the trace info is set to the value of the timeCounter field,
 *      which it was at the moment the stop command was issued.
 *      
 *      While the trace is in the NYCE_TRACE_STOPPING state, a new stop command can be issued using a new stop delay.  
 *       
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceStopTrace(double traceStopDelay);


/**
 * @brief Get trace data for a specific time interval. 
 *
 * @param [in]  traceTime           Trace time from which to retrieve trace data. This trace time would 
 *                                  correspond to the returned trace sample at traceData[0]. 
 *                                  The trace time is set to zero when the trace is started and counts from then on.
 *
 * @param [in]  nrOfSamples         Number of trace samples (values per variable) to be retrieved. 
 *                                  Also specifies the allocated array size of errorData if errorData is not NULL.
 *
 * @param [in]  dataSize            Minimum allocated length of output array in doubles.
 *
 * @param [out] pFirstSample        The position where the first valid sample is returned in pTraceData if pNrOfValidSamples returned
 *                                  a non-zero value. If pNrOfValidSamples returned zero, pFirstSample is the trace sample where the 
 *                                  first valid sample occurs if the provided pTraceData was large enough, or zero when the specified 
 *                                  time interval has no trace data, that is, the time interval is in the future. 
 *
 * @param [out] pNrOfValidSamples   Integer containing the number of returned valid trace samples in pTraceData.
 *
 * @param [out] pTraceData          size(dataSize); pre-allocated array of at least dataSize doubles. 
 *                                  This buffer stores the traced values.
 *
 * @param [out] pErrorData          size(nrOfSamples); If not NULL, this points to a pre-allocated array of size at least nrOfSamples 
 *                                  to contain trace error code information.
 *                                  This array is filled with the trace error code, which was active at the specific trace sample.
 *                                  This provides some information about the validity of each returned trace sample.
 *                                  If, for example, the error code for a trace sample is NYCE_TRACE_ERR_HSD_INVALID, at least one 
 *                                  HSD variable is traced but has no valid data. Note that it is not possible to determine 
 *                                  *which* HSD variable is valid when multiple HSD variables are traced.
 *                                  If pErrorData is set to NULL, no error code data is returned. Note that the function may still 
 *                                  return warnings, which apply to specific trace error codes. 
 * 
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_WRN_HSD_INVALID               At least one HSD value is invalid. Only if NYCE_OK is returned it is guaranteed that
 *                                                  all returned HSD values are valid. Invalid HSD values are stored as zeros.
 * @retval      TRACE_WRN_VARIABLE_LOST             At least one trace sample contains an invalid value because its variable was absent from 
 *                                                  the node trace data. This has a higher priority than TRACE_WRN_HSD_INVALID.
 * @retval      TRACE_ERR_INVALID_STATE             The trace state is invalid. It may not be NYCE_TRACE_IDLE.
 * @retval      TRACE_ERR_INVALID_PARAMETER         traceTime or nrOfSamples is invalid.
 * @retval      TRACE_ERR_INVALID_OUTPUT_ARGUMENT   A mandatory output argument is NULL. Only pErrorData is optional and can be NULL.
 * @retval      TRACE_ERR_BUFFER_TOO_SMALL          The specified buffer even can not hold one trace sample.
 *
 * @remarks     
 *      The returned data is stored in the pTraceData array. 
 *      Optionally, if pErrorData is not NULL, each error code which applies to its trace 
 *      sample is returned.
 *      This function can be called in any state, except NYCE_TRACE_IDLE.
 *
 *      Trace data is returned as trace samples. One trace sample contains maxNrOfVars doubles.
 *      This maximum number of variables is specified when defining the trace. Each added variable is located at its 
 *      variable index position in a trace sample. This index is returned when the variable was added to trace.
 *
 *      Note that trace data may not yet be available for the requested time interval, or not available anymore 
 *      in the trace buffer, in case the time frame is too far in the past.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceRetrieveTraceBlock(uint64_t    traceTime,
                                                        uint32_t    nrOfSamples,
                                                        uint32_t    dataSize,
                                                        uint32_t*   pFirstSample,
                                                        uint32_t*   pNrOfValidSamples,
                                                        double      pTraceData[],
                                                        NYCE_TRACE_ERROR_CODE pErrorData[]);


/**
 * @brief   Get all available trace data from the trace buffer.
 *
 * @param [in]   dataSize           size of pTraceData array
 *
 * @param [out]  pTraceData         size(dataSize); pointer to pre-allocated buffer to receive block of trace data
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_WRN_HSD_INVALID               At least one HSD value is invalid. Only if NYCE_OK is returned, it is guaranteed that
 *                                                  all returned HSD values are valid.
 * @retval      TRACE_WRN_VARIABLE_LOST             At least one trace sample contains an invalid value because its variable was absent from 
 *                                                  the node trace data.
 * @retval      TRACE_ERR_INVALID_STATE             The trace state is invalid. The trace state must be NYCE_TRACE_READY or NYCE_TRACE_ERROR.
 * @retval      TRACE_ERR_INVALID_PARAMETER         traceTime or nrOfSamples is invalid.
 * @retval      TRACE_ERR_INVALID_OUTPUT_ARGUMENT   A mandatory output argument is NULL. Only pErrrorData is optional and can be NULL.
 * @retval      TRACE_ERR_BUFFER_TOO_SMALL          The specified buffer even can not hold one trace sample.
 *
 * @remarks 
 *      This function can only be called in the NYCE_TRACE_READY or NYCE_TRACE_ERROR state.
 *
 *      Only actual traced data is returned.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceUploadTrace(uint32_t   dataSize,
                                                 double     pTraceData[]);



/**
 * @brief   Get status information about trace.
 *
 * @param [out]   pInfo             Pointer to information data of a trace
 *
 * @return      A NYCE_STATUS code.
 *
 * @remarks None.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceGetTraceInfo(NYCE_TRACE_INFO* pInfo);


/**
 * @brief Get the current trace state.
 *
 * @return      A NYCE_STATUS code.
 *
 * @remarks None.
 */
NYCE_EXPORT NYCE_TRACE_STATE NYCE_API NyceGetTraceState(void);


/**
 * @brief   Try to recover the current trace error. 
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_WRN_ERROR_ACTIVE      An error still exists after this function has executed.
 *
 * @remarks 
 *      Only if after recovery no trace error exists and the error code becomes NYCE_TRACE_ERR_NONE, 
 *      this function returns NYCE_OK.
 *
 *      If the trace state was NYCE_TRACE_ERROR and no fatal error exists after recovery, 
 *      the NYCE_TRACE_READY state is entered.
 *
 *      This function can be called in any trace state.
 *
 * @see NYCE_TRACE_ERROR_CODE 
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceResetTraceError(void);


/**
 * @brief   Remove a variable from the set of traced variables.
 *
 * @param [in]  variableIndex           Index of the variable.
 *                                      The index of a variable is returned when the variable is added to the trace. 
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_ERR_INVALID_VARIABLE_INDEX    No variable exists at the specified index or 
 *                                                  the index was invalid.
 *
 * @remarks 
 *      This function can only be called in the NYCE_TRACE_READY or NYCE_TRACE_ERROR state.
 *
 *      When this function is called, the trace buffer is cleared.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceDeleteVariableFromTrace(uint32_t variableIndex);


/**
 * @brief   Get information about a trace variable, specified by a variable index.
 *
 * @param [in]  variableIndex       Index of the variable..
 *                                  The index of a variable is returned when a variable is added to the trace. 
 *
 * @param [out] pElement            Pointer to trace element data.
 *
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_ERR_INVALID_VARIABLE_INDEX    No variable exists at the specified index or 
 *                                                  the index was invalid.
 * @retval      TRACE_ERR_INVALID_OUTPUT_ARGUMENT   pElement is NULL.
 *
 * @remarks None.
 *      
 * @see     NYCE_TRACE_ELEMENT
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceGetTraceElement(uint32_t            variableIndex, 
                                                     NYCE_TRACE_ELEMENT* pElement);


/**
 * @brief   Get the trace elements (variables) which are defined for the calling process.
 *
 * @param [in]  maxNrOfElements         Number of allocated elements in pElements.
 *
 * @param [out] pElements               size(maxNrOfElements); An allocated array of NYCE_TRACE_ELEMENT, which receives the trace elements.
 *
 * @param [out] pNrOfFilledElements     The actual number of returned elements in pElements.
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_ERR_INVALID_OUTPUT_ARGUMENT   pElements or pNrOfFilledElements is NULL.
 *
 * @remarks 
 *      This function can be called in any trace state, also if the calling process is not a trace client, that is, it has no trace defined.
 *
 * @see     NYCE_TRACE_ELEMENT
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceGetLocalTraceElements(uint32_t           maxNrOfElements, 
                                                           NYCE_TRACE_ELEMENT pElements[],
                                                           uint32_t*          pNrOfFilledElements);

/**
 * @brief   Get the trace elements (variables) which are defined by a specific process or by all processes.
 *
 * @param [in]  processId               Specifies the process for which to get its defined trace elements.
 *                                      If this is zero, the trace elements of all processes are returned.
 *
 * @param [in]  maxNrOfElements         Number of allocated elements in pElements.
 *
 * @param [out] pElements               size(maxNrOfElements); An allocated array of NYCE_GLOBAL_TRACE_ELEMENT, which receives the trace elements.
 *
 * @param [out] pNrOfFilledElements     The actual number of returned elements in pElements.
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_ERR_INVALID_PROCESS_ID        The specified process is non-zero and has not defined a trace.
 * @retval      TRACE_ERR_INVALID_OUTPUT_ARGUMENT   pElements or pNrOfFilledElements is NULL.
 *
 * @remarks     
 *      This function can be called in any state.
 *      
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceGetGlobalTraceElements(uint32_t                  processId,
                                                            uint32_t                  maxNrOfElements, 
                                                            NYCE_GLOBAL_TRACE_ELEMENT pElements[],
                                                            uint32_t*                 pNrOfFilledElements);

/**
 * @brief   De-allocates the trace. 
 *
 * @return      A NYCE_STATUS code.
 *
 * @retval      TRACE_ERR_INVALID_STATE             The trace state is invalid. The trace state must not be NYCE_TRACE_IDLE.
 *
 * @remarks 
 *      This function de-allocates all trace resources of the calling process. The allocated trace buffer and 
 *      trace variables are deleted and the trace state changes to NYCE_TRACE_IDLE.
 *
 *      This function can be called in any trace state, except NYCE_TRACE_IDLE state.
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceDeleteTrace(void);

/** @} */

/**
 *  @addtogroup nyce_miscellaneous
 *  @{
 */

/**
 * @brief Get the textual description of a NYCE_STATUS enumerated value.
 *
 * This function gets the textual description of the status code returned from a function call.
 *
 * @param [in] statusCode    - NYCE_STATUS value returned from a function call.
 *
 * @remarks None.
 */
NYCE_EXPORT const char* NYCE_API NyceGetStatusString(NYCE_STATUS statusCode);



/**
 * @brief Get the textual description of a NYCE_ERROR_CODE enumerated value.
 *
 * This function gets the textual description of the error code received with an event.
 *
 * @param [in] errorCode - NYCE_ERROR_CODE received with an error event
 *
 * @remarks None.
 */
NYCE_EXPORT const char* NYCE_API NyceGetErrorCodeString(NYCE_ERROR_CODE errorCode);



/**
 * @brief Get the textual description of a NYCE_NODE_STATUS enumerated value.
 *
 * This function gets the textual description of the NYCE_NODE_STATUS enumeration.
 *
 * @param [in] status    - NYCE_NODE_STATUS enum
 *
 * @remarks None.
 */
NYCE_EXPORT const char* NYCE_API NyceGetNodeStatusString(NYCE_NODE_STATUS status);



/**
 * @brief Check if a NYCE_STATUS code is not an error.
 *
 * This function is used to check if a return value from a function indicates
 *             success or failure. This is especially convenient for status codes from non
 *             public interfaces which are forwarded to customer applications. These
 *             applications can then simply check by NyceSuccess( retVal )  if the post
 *             condition of the function is satisfied.
 *
 * @param [in] statusCode - NYCE_STATUS value returned from a function call.
 *
 * @remarks None.
 */
NYCE_EXPORT BOOL NYCE_API NyceSuccess(NYCE_STATUS statusCode);



/**
 * @brief Check if a NYCE_STATUS code is an error.
 *
 * This function is used to check if a return value from a function indicates success
 *             or failure. This is especially convenient for status codes from non public interfaces
 *             which are forwarded to customer applications. These applications can then simply check
 *             by NyceError( retVal ) if the return code indicates an error.
 *
 * @param [in] statusCode - NYCE_STATUS value returned from a function call.
 *
 * @remarks None.
 */
NYCE_EXPORT BOOL NYCE_API NyceError(NYCE_STATUS statusCode);

/** @} */

/**
 *  @addtogroup nyce_excl_write
 *  @{
 */

/**
 *  @brief  Request to get exclusive write access
 *
 *  By means of this function, an application can request exclusive write access to 
 *  the NYCe4000 system. One and the same process can successfully put multiple 
 *  requests.
 *
 *  @return NYCE_OK                                       When succesful (exclusive write access granted)
 *  @return NCS_ERR_EXCL_WRITE_DISABLED                   Exclusive write access disabled
 *  @return NCS_ERR_EXCL_WRITE_GRANTED_TO_ANOTHER_PROCESS Exclusive write access granted to another process
 *  @return NCS_ERR_EXCL_WRITE_NOT_GRANTED_TRACE_RUNNING  Another process is using trace functionality
 *
 *  @retval NYCE_STATUS
 *
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceRequestExclWriteAccess(void);


/**
 *  @brief  Release exclusive write access
 *
 *  By means of this function, an application can release exclusive write access
 *  to the NYCe4000 system, if obtained prior to this call. If the exclusive write
 *  access has been released as often as it was requested, write access is available
 *  to all processes again.
 *
 *  @return NYCE_OK                                       When succesful (exclusive write access released)
 *  @return NCS_ERR_EXCL_WRITE_NOT_GRANTED                Exclusive write access has not been granted to any process
 *  @return NCS_ERR_EXCL_WRITE_GRANTED_TO_ANOTHER_PROCESS Exclusive write access granted to another process
 *          
 *  @retval NYCE_STATUS
 *
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceReleaseExclWriteAccess(void);


/**
 *  @brief  Get the id of the process which has the exclusive write access privilege
 *
 *  By means of this function, an application can check if the exclusive write
 *  access privilege has been granted to any process, and if so, the id of this process is
 *  returned as function output.
 *
 *  @param [out] pProcessId                     Id of process which has the exclusive write access
 *                                              privilege, if any, else NO_PROCESS.
 *
 *  @return NYCE_OK                             When succesful (process id was returned)
 *  @return NCS_ERR_EXCL_WRITE_NOT_GRANTED      Exclusive write access has not been granted to any process
 *          
 *  @retval NYCE_STATUS
 *
 */
NYCE_EXPORT NYCE_STATUS NYCE_API NyceGetExclWriteProcess(uint32_t* pProcessId);

/** @} */

#ifdef __cplusplus
    }
#endif

/** @} */

#endif  /* __NYCEAPI_H__ */
