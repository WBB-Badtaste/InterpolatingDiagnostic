/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2009
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000
//    Component Name: SUPPORT
//    Subsystem Name: DEH
//    %full_filespec:    dehapi.h`31.1.11:incl:1 % (SYNERGY INFO, do not change)
//
//    Description   : Public interface to the deh subsystem
*/

#ifndef __DEHAPI_H__
#define __DEHAPI_H__

#include "nycedefs.h"
#include "dehtypes.h"

#ifndef DEH_EXPORT
    #ifdef WIN32
        #define DEH_EXPORT __declspec(dllimport)
    #else
        #define DEH_EXPORT
    #endif
#endif

#ifdef NT
#pragma pack(push)
#pragma pack() //use default
#endif

#ifdef __cplusplus
extern "C"
{
#endif


/**
 * @addtogroup deh
 *
 * @{
 */

/**
 * @addtogroup deh_logging
 *
 * @{
 */

/*-----------------------------------------------------------------------
 * EXPORTED FUNCTIONAL PROTOTYPES
 *-----------------------------------------------------------------------
 */
/**
 *  @brief  Prototype for log functions.
 *
 *  With a function matching this prototype it is possible to implement a custom log function.
 *  The log function receives the log source, type and log message.
 *  Call DehSetLogFunction() to use this custom logging.
 *
 *  @param[in]  subsystem   the subsystem the message belongs to.
 *  @param[in]  logType     type of message.
 *  @param[in]  msg         message to log.
*/
typedef void (*DEH_LOG_FUNC)(NYCE_SUBSYSTEM subsystem,
                             DEH_LOG_TYPE   logType,
                             const char*     msg);

/* Logging API */

/**
 * @brief Enable or disable logging for a specific subsystem of the NYCe4000 Software.
 *
 * @param [in]  processId   defines the process for which the settings are meant.
 * @param [in]  subSystem   defines the subsystem of which the settings are. This value can also be SS_USR for application specific logging.
 * @param [in]  mask        defines which types of messages should be active for logging.
 *
 * @remarks None.
 */
DEH_EXPORT NYCE_STATUS NYCE_API DehSetSSLoggingMask(uint32_t        processId, 
                                                    NYCE_SUBSYSTEM  subSystem, 
                                                    uint32_t        mask);

/**
 * @brief Retrieve the actual logging setting for a specific subsystem of the NYCe4000 Software.
 *
 * @param [in]  processId   defines the process.
 * @param [in]  subSystem   defines the subsystem of which the settings are. 
 * @param [out] pMask       actual logging setting of messages.
 *
 * @remarks None.
 */
DEH_EXPORT NYCE_STATUS NYCE_API DehGetSSLoggingMask(uint32_t        processId, 
                                                    NYCE_SUBSYSTEM  subSystem, 
                                                    uint32_t*       pMask);

/**
 * @brief Enable or disable logging for all subsystems of the NYCe4000 Software.
 *
 * @param [in]  processId   defines the process for which the settings are meant.
 * @param [in]  mask        defines which types of messages should be active for logging.
 *
 * @remarks None.
 */
DEH_EXPORT NYCE_STATUS NYCE_API DehSetLoggingMask(uint32_t  processId,
                                                  uint32_t  mask);

/**
 * 
 * @brief Retrieve the actual logging setting of the NYCe4000 Software.
 *
 * @param [in]  processId   defines the process.
 * @param [out] pMask       actual logging setting of messages.
 *
 * @remarks None.
 */
DEH_EXPORT NYCE_STATUS NYCE_API DehGetLoggingMask(uint32_t  processId,
                                                  uint32_t* pMask);

/**
 * @brief Retrieve the next logging string.
 *
 * @param [out]  logNr  number of the returned string.
 * @param [out]  data   size(DEH_MAX_LOGMSG_SIZE); a preallocated buffer of at least DEH_MAX_LOGMSG_SIZE bytes. Here the logging message is stored.
 *
 * @remarks None.
 */
DEH_EXPORT NYCE_STATUS NYCE_API DehGetLoggingData(uint32_t* logNr,
                                                  char      data[]);

/**
 *  @brief  Log a message.
 *
 *  @param[in] subSystem    the subSystem the message belongs to.
 *  @param[in] logType      type of message.
 *  @param[in] fmt          message format string.
 *  @param[in] ...          additional arguments.
*/
/* lint -printf(3, DehLog) */
DEH_EXPORT void NYCE_API DehLog(NYCE_SUBSYSTEM   subSystem,
                                DEH_LOG_TYPE     logType,
                                const char*      fmt,
                                ... );

/**
 * @brief Enable or disable event logging. 
 *
 * @param [in]  processId   Legacy. Not used anymore.
 * @param [in]  logEvent    defines enable or disable event logging.
 *
 * @remarks     An event is only logged if any application has defined an event enrollment for the event.
 */
DEH_EXPORT NYCE_STATUS NYCE_API DehSetLogEventSetting(uint32_t  processId,
                                                      BOOL      logEvent);

/**
 * @brief Retrieve the current setting for event logging.
 *
 * @param [in]  processId   Legacy. Not used anymore.
 * @param [out] pLogEvent   actual logging setting of event logging.
 *
 * @remarks     An event is only logged if any application has defined an event enrollment for the event.
 */
DEH_EXPORT NYCE_STATUS NYCE_API DehGetLogEventSetting(uint32_t  processId,
                                                      BOOL*     pLogEvent);

/**
 * @brief Set the function pointer in DEH to point to the given log function.
 *
 * @param [in] pfnDehLogFunction   implementation of the log function.
 *
 * @retval  NYCE_OK                     if setting successful.
 * @retval  DEH_ERR_INVALID_PARAMETER   if pfnDehLogFunction is NULL.
 *
 *@remarks
 *      Registered log function will influence the product performance.
 */
DEH_EXPORT NYCE_STATUS NYCE_API DehSetLogFunction(DEH_LOG_FUNC pfnDehLogFunction);

/**
 * @brief Get the current implementation of the log function.
 *
 * @param [out] pfnDehLogFunction   implementation of the log function.
 *
 * @retval  NYCE_OK                             if getting successful.
 * @retval  DEH_ERR_INVALID_OUTPUT_ARGUMENT     if pfnDehLogFunction is NULL.
 */
DEH_EXPORT NYCE_STATUS NYCE_API DehGetLogFunction(DEH_LOG_FUNC* pfnDehLogFunction);

/**
 * @brief Reset the function pointer to point to the default log function in DEH.
 */
DEH_EXPORT void NYCE_API DehResetLogFunction(void);

/** @} */

/** @} */

/* the rest of this file is for internal use only
 */

#ifndef DehLogFunctionEntry
#define DehLogFunctionEntry         DehLogFunctionEntryUSR
#define DehLogPrimaryParameters     DehLogPrimaryParametersUSR
#define DehLogSecondaryParameters   DehLogSecondaryParametersUSR
#define DehLogOutputParameters      DehLogOutputParametersUSR
#define DehLogFunctionExit          DehLogFunctionExitUSR
#define DehLogFunctionExitString    DehLogFunctionExitStringUSR
#define DehLogUserMsg               DehLogUserMsgUSR

/**
 *  @brief  Log function entry (client function logging).
 *
 *  @param[in]  functionName    Name of the function.
 */
DEH_EXPORT void NYCE_API DehLogFunctionEntryUSR(const char *functionName);

/**
 *  @brief  Log primary parameters (client function logging).
 *
 *  @param[in]  format      printf style formatting using elipsis.
 */
/*lint -printf(1,DehLogPrimaryParametersUSR,DehLogSecondaryParametersUSR,DehLogOutputParametersUSR) */
DEH_EXPORT void DehLogPrimaryParametersUSR(const char * format, ...);

/**
 *  @brief  Log secondary parameters (client function logging).
 *
 *  @param[in]  format      printf style formatting using elipsis.
 */
DEH_EXPORT void DehLogSecondaryParametersUSR(const char * format, ...);

/**
 *  @brief  Log output parameters (client function logging).
 *
 *  @param[in]  format      printf style formatting using elipsis.
 */
DEH_EXPORT void DehLogOutputParametersUSR(const char * format, ...);

/**
 *  @brief  Log function exit (client function logging).
 *
 *  @param[in]  functionName    Name of the function.
 *  @param[in]  retStatus       Status of the function.
 */
DEH_EXPORT void NYCE_API DehLogFunctionExitUSR(const char *functionName, NYCE_STATUS retStatus);

/**
 *  @brief  Log function exit (client function logging).
 *
 *  @param[in]  functionName    Name of the function.
 *  @param[in]  retString       Status of the function.
 */
DEH_EXPORT void NYCE_API DehLogFunctionExitStringUSR(const char *functionName, const char *retString);

/**
 *  @brief  Log message (client function logging).
 *
 *  @param[in]  format      printf style formatting using elipsis.
 */
/*lint -printf(1,DehLogUserMsgUSR) */
DEH_EXPORT void DehLogUserMsgUSR(const char * format, ...);
#endif

#ifdef __cplusplus
}
#endif

#ifdef NT
#pragma pack(pop)
#endif

#endif /* __DEHAPI_H__ */
