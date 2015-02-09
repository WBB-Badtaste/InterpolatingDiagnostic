/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2009
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000
//    Component Name: hostsw
//    Subsystem Name: seq
//    %full_filespec:    seqapi.h`58:incl:1 % (SYNERGY INFO, do not change)
//
//    Description   : External interface of SEQ library
*/

#ifndef __SEQAPI_H__
#define __SEQAPI_H__

/*-----------------------------------------------------------------------------------------------
 * GLOBAL INCLUDES
 *-----------------------------------------------------------------------------------------------*/
#include "nycedefs.h"
#include "seqtypes.h"

#ifdef NT
#pragma pack(push)
#pragma pack() //use default
#endif

/**
 * @addtogroup seq
 *
 * @{
 */

/*-----------------------------------------------------------------------------------------------
 * GLOBAL DEFINES
 *-----------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------------
 * GLOBAL DATA TYPES
 *-----------------------------------------------------------------------------------------------*/


/* Miscellaneous --------------------------------------------------------------------------------*/

typedef uint32_t SEQ_NODE;

/**
 *  @brief  A macro to enable clear and 64-bit-compatible casting (void*) -> SEQ_NODE
 *  @param[in]  p   pointer to an address.
 *  @return     The address of the pointer.
 */
#define PtrToSeqNode(p) PtrToUlong(p)

#define SEQ_INVALID_ID  (SEQ_NODE)NYCE_MAX_NR_OF_NODES  /**< The invalid node id identifier */

typedef struct seq_activity_info
{
    SEQ_STATE       seqState;
    int32_t         individualPeriod;
    int32_t         areaNr;
    int32_t         cpuTime;
    int32_t         waitCounter;
    int32_t         eventCounter;
    int32_t         eventData;

} SEQ_ACTIVITY_INFO;

typedef struct seq_schedule_info
{
    int32_t           nrOfActiveSeq;
    uint32_t          defaultPeriod;
    SEQ_ACTIVITY_INFO seqActivityInfo[NYCE_MAX_NR_OF_ACTIVE_SEQUENCES + 1];

} SEQ_SCHEDULE_INFO;


/*-----------------------------------------------------------------------------------------------*
 * EXPORTED FUNCTIONAL PROTOTYPES
 *-----------------------------------------------------------------------------------------------*/

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef SEQ_EXPORT
    #ifdef WIN32
        #define SEQ_EXPORT __declspec(dllimport)
    #else
        #define SEQ_EXPORT
    #endif
#endif


/**
 * @defgroup seq_configuration Configuration
 *
 */

/**
 * @defgroup seq_state_transitions State Transitions
 *
 */

/**
 * @defgroup seq_events Events
 *
 */

/**
 * @defgroup seq_data_handling Data Handling
 *
 */

/**
 * @defgroup seq_miscellaneous Miscellaneous
 *
 */



/**
 *
 * @ingroup seq_state_transitions
 * @brief Open a handle to the node.
 *
 * @param [in]  szNodeName          - Name of the node.
 * @param [out] pSeqNodeId          - Node connection handle.
 *
 * @retval NYCE_OK
 * @retval SEQ_WRN_ALREADY_CONNECTED
 * @retval SEQ_ERR_DUPLICATE_NODENAME
 * @retval SEQ_ERR_MAX_NODES_CONNECTED
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqConnect(const char* szNodeName,
                                           SEQ_NODE*   pSeqNodeId);



/**
 *
 * @ingroup seq_state_transitions
 * @brief Close the handle to the node.
 *
 * @param [in] seqNodeId            - Node connection handle.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval errorcode                - if not successful
 *
 * @remarks Disconnection from the node includes clearing all event enrolments.
 */
 SEQ_EXPORT NYCE_STATUS NYCE_API SeqDisconnect(SEQ_NODE seqNodeId);



/**
 *
 * @ingroup seq_configuration
 * @brief (Re-)define the number of sequence areas available for sequences and the size of each area.
 *
 * Area sizes must be >0 and a multiple of 32
 *
 * @param [in] seqNodeId            - Node connection handle.
 * @param [in] nrOfAreas            - Number of areas.
 * @param [in] areaSizes            - size(nrOfAreas); array of area sizes.
 *
 *
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_INVALID_NR_OF_AREAS
 * @retval SEQ_ERR_INVALID_AREA_SIZE
 * @retval SEQ_ERR_SEQUENCES_RUNNING
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqDefineAreas(SEQ_NODE      seqNodeId,
                                               int32_t       nrOfAreas,
                                               const int32_t areaSizes[]);



/**
 *
 * @ingroup seq_configuration
 * @brief Retrieve the number of defined sequence areas and their sequence area sizes.
 *
 * @param [in]  seqNodeId               - Node connection handle.
 * @param [in]  areaSizeBufferSize      - Maximum number of sequence area sizes that can be retrieved in areaSizeBuffer.
 * @param [out] pNrOfDefinedAreas       - Number of defined areas.
 * @param [out] areaSizeBuffer          - size(areaSizeBufferSize); Buffer that returns up to areaSizeBufferSize sequence area sizes.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval errorcode                    - if not successful
 *
 * @remarks
 * If areaSizeBufferSize >= pNrOfDefinedAreas for all defined sequences the
 * sequence area size will be retrieved.
 *
 * If areaSizeBufferSize < pNrOfDefinedAreas only for the first areaSizeBufferSize
 * sequences the sequence area size will be retrieved.
 *
 * To retrieve the needed areaSizeBufferSize to retrieve all sequence area sizes
 * call SeqGetAreas with areaSizeBufferSize = 0 or areaSizeBuffer = NULL.
 * pNrOfDefinedAreas will return the needed buffer size.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqGetAreas(SEQ_NODE seqNodeId,
                                            int32_t  areaSizeBufferSize,
                                            int32_t* pNrOfDefinedAreas,
                                            int32_t  areaSizeBuffer[]);



/**
 *
 * @ingroup seq_configuration
 * @brief Load a sequence into the designated sequence memory of the node.
 *
 * @param [in] seqNodeId            - Node connection handle.
 * @param [in] areaNr               - Area Number.
 * @param [in] szFileName           - Name of the file.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_INVALID_NAME_LENGTH
 * @retval SEQ_ERR_FILE_OPEN_ERROR
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqLoad(SEQ_NODE    seqNodeId,
                                        int32_t     areaNr,
                                        const char* szFileName);



/**
 *
 * @ingroup seq_configuration
 * @brief Retrieve the filename of a loaded sequence of the node.
 *
 * @param [in]  seqNodeId            - Node connection handle.
 * @param [in]  areaNr               - Area Number.
 * @param [out] fileName             - size(NYCE_MAX_SEQ_FILE_NAME); Name of the file.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval SEQ_WRN_INVALID_FILE_VERSION
 * @retval SEQ_WRN_FILE_NOT_PRESENT
 * @retval SEQ_ERR_NO_SEQUENCE_LOADED
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqGetLoadedFileName(SEQ_NODE seqNodeId,
                                                     int32_t  areaNr,
                                                     char     fileName[]);



/**
 *
 * @ingroup seq_configuration
 * @brief (Re-)define the scheduling period on a node.
 *
 * @param [in] seqNodeId            - Node connection handle.
 * @param [in] period               - Period in seconds.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval errorcode                - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqSetDefaultPeriod(SEQ_NODE seqNodeId,
                                                    double   period);



/**
 *
 * @ingroup seq_configuration
 * @brief (Re-)define the scheduling period on a node for a specific sequence.
 *
 * The sequence should be active (otherwise it is ignored).
 *
 * @param [in] seqNodeId            - Node connection handle.
 * @param [in] areaNr               - Area number.
 * @param [in] period               - Period in seconds.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval errorcode                - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqSetIndividualPeriod(SEQ_NODE seqNodeId,
                                                       int32_t  areaNr,
                                                       double   period);



/**
 *
 * @ingroup seq_miscellaneous
 * @brief Retrieve the current scheduling information of the specified node.
 *
 * @param [in]  seqNodeId           - Node connection handle.
 * @param [out] pSeqInfo            - Scheduler info.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqGetScheduleInfo(SEQ_NODE           seqNodeId,
                                                   SEQ_SCHEDULE_INFO* pSeqInfo);



/**
 *
 * @ingroup seq_state_transitions
 * @brief Activate a sequence on a node.
 *
 * @param [in] seqNodeId            - Node connection handle.
 * @param [in] areaNr               - Area number.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval errorcode                - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqStart(SEQ_NODE seqNodeId,
                                         int32_t  areaNr);



/**
 *
 * @ingroup seq_state_transitions
 * @brief De-activate a sequence on a node.
 *
 * @param [in] seqNodeId            - Node connection handle.
 * @param [in] areaNr               - Area number.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval errorcode                - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqAbort(SEQ_NODE seqNodeId,
                                         int32_t  areaNr);



/**
 *
 * @ingroup seq_configuration
 * @brief Copy sequences to flash. These sequences will load.
 *
 * @param [in] seqNodeId            - Node connection handle.
 * @param [in] nrOfSequences        - Number of sequences.
 * @param [in] areaNrs              - size(nrOfSequences); Area numbers(filled in later).
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_NOT_ENOUGH_MEMORY
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqCreateBootstrap(SEQ_NODE      seqNodeId,
                                                   int32_t       nrOfSequences,
                                                   const int32_t areaNrs[]);



/**
 *
 * @ingroup seq_data_handling
 * @brief Retrieve the actual data from the address, specified by the symbol, from the node.
 *
 * @param [in]  seqNodeId           - Node connection handle.
 * @param [in]  areaNr              - Area number.
 * @param [in]  szSymbol            - Symbol name
 * @param [in]  typeLen             - Length of an item in bytes.
 * @param [in]  nrOfItems           - Number of items.
 * @param [out] pData               - size(typeLen * nrOfItems); Actual data.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval SEQ_ERR_INVALID_SYMBOL
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval SEQ_ERR_NO_SEQUENCE_LOADED
 * @retval SEQ_ERR_INVALID_FILE_VERSION
 * @retval SEQ_ERR_FILE_OPEN_ERROR
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqGetDataBuffer(SEQ_NODE    seqNodeId,
                                                 int32_t     areaNr,
                                                 const char* szSymbol,
                                                 int32_t     typeLen,
                                                 int32_t     nrOfItems,
                                                 void*       pData );



/**
 *
 * @ingroup seq_data_handling
 * @brief Retrieve the actual data from the address, from the node.
 *
 * @param [in]  seqNodeId           - Node connection handle.
 * @param [in]  areaNr              - Area number.
 * @param [in]  address             - Data address.
 * @param [in]  typeLen             - Length of the data in bytes.
 * @param [out] pData               - size(typeLen); Actual data.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqGetAddressData(SEQ_NODE seqNodeId,
                                                  int32_t  areaNr,
                                                  uint32_t address,
                                                  int32_t  typeLen,
                                                  void*    pData);
 


/**
 *
 * @ingroup seq_data_handling
 * @brief Retrieve the actual data from the address, from the node.
 *
 * @param [in]  seqNodeId           - Node connection handle.
 * @param [in]  areaNr              - Area number.
 * @param [in]  address             - Data address.
 * @param [in]  typeLen             - Length of an item in bytes.
 * @param [in]  nrOfItems           - Number of items.
 * @param [out] pData               - size(typeLen * nrOfItems); Actual data.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqGetAddressDataBuffer(SEQ_NODE seqNodeId,
                                                        int32_t  areaNr,
                                                        uint32_t address,
                                                        int32_t  typeLen,
                                                        int32_t  nrOfItems,
                                                        void*    pData);



/**
 *
 * @ingroup seq_data_handling
 * @brief Set the actual data array on the address, specified by the symbol, in the node.
 *
 * @param [in] seqNodeId            - Node connection handle.
 * @param [in] areaNr               - Area number.
 * @param [in] szSymbol             - Symbol name.
 * @param [in] typeLen              - Length of an item/element in bytes.
 * @param [in] nrOfItems            - Number of items.
 * @param [in] pData                - size(typeLen * nrOfItems); Actual data array.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval SEQ_ERR_INVALID_SYMBOL
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval SEQ_ERR_NO_SEQUENCE_LOADED
 * @retval SEQ_ERR_INVALID_FILE_VERSION
 * @retval SEQ_ERR_FILE_OPEN_ERROR
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqSetDataBuffer(SEQ_NODE    seqNodeId,
                                                 int32_t     areaNr,
                                                 const char* szSymbol,
                                                 int32_t     typeLen,
                                                 int32_t     nrOfItems,
                                                 const void* pData);




/**
 *
 * @ingroup seq_data_handling
 * @brief Set the actual data on the address, in the node.
 *
 * @param [in] seqNodeId            - Node connection handle.
 * @param [in] areaNr               - Area number.
 * @param [in] address              - Data address.
 * @param [in] pData                - Actual data.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqSetAddressData(SEQ_NODE    seqNodeId,
                                                  int32_t     areaNr,
                                                  uint32_t    address,
                                                  const void* pData);


/**
 *
 * @ingroup seq_data_handling
 * @brief Set the actual data array on the address, in the node.
 *
 * @param [in] seqNodeId            Node connection handle.
 * @param [in] areaNr               Area number.
 * @param [in] address              Data address.
 * @param [in] typeLen              Length of an item/element in bytes.
 * @param [in] nrOfItems            Number of items.
 * @param [in] pData                size(typeLen * nrOfItems); Actual data array.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqSetAddressDataBuffer(SEQ_NODE    seqNodeId,
                                                        int32_t     areaNr,
                                                        uint32_t    address,
                                                        int32_t     typeLen,
                                                        int32_t     nrOfItems,
                                                        const void* pData);



/**
 *
 * @ingroup seq_data_handling
 * @brief Get the address of the specified data.
 *
 * @param [in]  seqNodeId           Node connection handle.
 * @param [in]  areaNr              Area number.
 * @param [in]  szSymbol            Symbol name.
 * @param [out] pAddress            Address of the data.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval SEQ_ERR_INVALID_SYMBOL
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval SEQ_ERR_NO_SEQUENCE_LOADED
 * @retval SEQ_ERR_INVALID_FILE_VERSION
 * @retval SEQ_ERR_FILE_OPEN_ERROR
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqGetDataAddress(SEQ_NODE    seqNodeId,
                                                  int32_t     areaNr,
                                                  const char* szSymbol,
                                                  uint32_t*   pAddress);



/**
 *
 * @ingroup seq_state_transitions
 * @brief Get the state of a sequence.
 *
 * @param [in]  seqNodeId           Node connection handle.
 * @param [in]  areaNr              Area number.
 * @param [out] pSeqState           Current state.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqGetState(SEQ_NODE   seqNodeId,
                                            int32_t    areaNr,
                                            SEQ_STATE* pSeqState);



/**
 *
 * @ingroup seq_miscellaneous
 * @brief Generate a sequence from a C source file.
 *
 * @param [in] seqNodeId            Node connection handle.
 * @param [in] areaNr               Area number.
 * @param [in] areaType             Area type.
 * @param [in] szSource             Filename of the source code of the sequence.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval SEQ_ERR_INVALID_AREA_TYPE
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval SEQ_ERR_FILE_OPEN_ERROR
 * @retval SEQ_ERR_INVALID_NAME_LENGTH

 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqGenerate(SEQ_NODE           seqNodeId,
                                            int32_t            areaNr,
                                            NYCE_SEQ_AREA_TYPE areaType,
                                            const char*        szSource);



/**
 *
 * @ingroup seq_miscellaneous
 * @brief Calculate the stack length and inspect the stack usage on the node.
 *
 * @param [in]  seqNodeId           Node connection handle.
 * @param [in]  areaNr              Sequence area number.
 * @param [out] pStackLength        Length of the stack.
 * @param [out] pStackUsed          Number of bytes used.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqStackCheck(SEQ_NODE seqNodeId,
                                              int32_t  areaNr,
                                              int32_t* pStackLength,
                                              int32_t* pStackUsed);

/**
 *
 * @ingroup seq_events
 * @brief Define a sequence event enrolment.
 *
 * @param [in]  seqNodeId           Node connection handle.
 * @param [in]  eventId             SEQ event id (SEQ_EV_HOST or SEQ_EV_DBG).
 * @param [in]  handler             Address of the event handler function.
 * @param [in]  pUserData           Pointer which is supplied to the event handler.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval errorcode                - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqDefineEventEnrolment(SEQ_NODE           seqNodeId,
                                                        NYCE_EVENT         eventId,
                                                        NYCE_EVENT_HANDLER handler,
                                                        void*              pUserData);

/**
 *
 * @ingroup seq_events
 * @brief Delete a sequence event enrolment.
 *
 * @param [in]  seqNodeId           Node connection handle.
 * @param [in]  eventId             SEQ event id (SEQ_EV_HOST or SEQ_EV_DBG).
 * @param [in]  handler             Address of the event handler function.
 * @param [in]  pUserData           Pointer which is supplied to the event handler.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval errorcode                - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqDeleteEventEnrolment(SEQ_NODE           seqNodeId,
                                                        NYCE_EVENT         eventId,
                                                        NYCE_EVENT_HANDLER handler,
                                                        void*              pUserData);


/**
 *
 * @ingroup seq_events
 * @brief Send an event to a sequence.
 *
 * @param [in] seqNodeId            Node connection handle.
 * @param [in] areaNr               Area Number.
 * @param [in] eventData            User event data.
 *
 * @retval NYCE_OK
 * @retval SEQ_ERR_INVALID_NODE_ID
 * @retval SEQ_ERR_ILLEGAL_AREA_NR
 * @retval errorcode                - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqSendEvent(SEQ_NODE seqNodeId,
                                             int32_t  areaNr,
                                             int32_t  eventData);


/**
 *
 * @ingroup seq_miscellaneous
 * @brief Get the communication id of the specified node.
 *
 * @param[in]   pNodeName           Name of the node.
 * @param[out]  pSqcComId           Communication number of the node.
 *
 * @retval SEQ_ERR_INVALID_PARAMETER
 * @retval errorcode                    - if not successful
 *
 * @remarks None.
 */
SEQ_EXPORT NYCE_STATUS NYCE_API SeqGetSqcComId(const char* pNodeName,
                                               uint32_t*   pSqcComId);


/**
 *  @defgroup seq_conversion Conversion
 *
 *  The functions within this module convert strings to enumeration values and vice versa.
 */


#ifdef __cplusplus
    }
#endif

/** @} */

#ifdef NT
#pragma pack(pop)
#endif

#endif /* __SEQAPI_H__ */
