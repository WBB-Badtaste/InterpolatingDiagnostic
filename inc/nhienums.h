/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2014
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: support
 *  Subsystem Name: deh
 *
 *  THIS FILE IS AUTOMATICALLY GENERATED BY
 *  generate_enum_conversion.py
 *  MANUAL MODIFICATIONS WILL BE OVERWRITTEN!!!
 */
/**
 *  @file
 *  @brief  Enum conversion functions for nhi.
 *  
 *  For every enum in the nhi subsystem the following type to string conversion functions exist:
 *  - "<TYPE>ToString(TYPE)"            Convert the given value of "<TYPE>" to its exact string representation.
 *  - "<TYPE>ToUserString(TYPE)"        Convert the given value of "<TYPE>" to a human readable string.
 *  - "<TYPE>ToDescription(TYPE)"       Convert the given value of "<TYPE>" to a descriptive string.
 *  - "<TYPE>FromString(string, TYPE)"  Convert the given string to value of "<TYPE>".
 *  - "<TYPE>IsValid(TYPE)"             Checks if the given value of "<TYPE>" is valid.
 */

#ifndef __NHIENUMS_H__
#define __NHIENUMS_H__

#include "nhiapi.h"

#ifndef DEH_EXPORT
    #ifdef WIN32
        #define DEH_EXPORT __declspec(dllimport)
    #else
        #define DEH_EXPORT
    #endif
#endif

#ifdef __cplusplus
extern "C" {
#endif
/**
 *  @addtogroup nhi_conversion
 *  @{
 */

//  NHI_LATCH_SET_STATE Conversion routines

/**
 *  @brief      Convert type NHI_LATCH_SET_STATE to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiLatchSetStateToString(NHI_LATCH_SET_STATE value);

/**
 *  @brief      Convert type NHI_LATCH_SET_STATE to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiLatchSetStateToUserString(NHI_LATCH_SET_STATE value);

/**
 *  @brief      Convert type NHI_LATCH_SET_STATE to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiLatchSetStateToDescription(NHI_LATCH_SET_STATE value);

/**
 *  @brief      Convert the given string to an NHI_LATCH_SET_STATE.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_LATCH_SET_STATE.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_LATCH_SET_STATE.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiLatchSetStateFromString(const char* string, NHI_LATCH_SET_STATE* pValue);

/**
 *  @brief      Check if value is a valid NHI_LATCH_SET_STATE.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_LATCH_SET_STATE.
 *  @retval     FALSE   value is not a valid NHI_LATCH_SET_STATE.
 */
DEH_EXPORT BOOL NhiLatchSetStateIsValid(NHI_LATCH_SET_STATE value);


//  NHI_SYNC_REQUEST Conversion routines

/**
 *  @brief      Convert type NHI_SYNC_REQUEST to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSyncRequestToString(NHI_SYNC_REQUEST value);

/**
 *  @brief      Convert type NHI_SYNC_REQUEST to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSyncRequestToUserString(NHI_SYNC_REQUEST value);

/**
 *  @brief      Convert type NHI_SYNC_REQUEST to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiSyncRequestToDescription(NHI_SYNC_REQUEST value);

/**
 *  @brief      Convert the given string to an NHI_SYNC_REQUEST.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_SYNC_REQUEST.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_SYNC_REQUEST.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiSyncRequestFromString(const char* string, NHI_SYNC_REQUEST* pValue);

/**
 *  @brief      Check if value is a valid NHI_SYNC_REQUEST.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_SYNC_REQUEST.
 *  @retval     FALSE   value is not a valid NHI_SYNC_REQUEST.
 */
DEH_EXPORT BOOL NhiSyncRequestIsValid(NHI_SYNC_REQUEST value);


//  NHI_GATEWARE_VARIANT Conversion routines

/**
 *  @brief      Convert type NHI_GATEWARE_VARIANT to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiGatewareVariantToString(NHI_GATEWARE_VARIANT value);

/**
 *  @brief      Convert type NHI_GATEWARE_VARIANT to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiGatewareVariantToUserString(NHI_GATEWARE_VARIANT value);

/**
 *  @brief      Convert type NHI_GATEWARE_VARIANT to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiGatewareVariantToDescription(NHI_GATEWARE_VARIANT value);

/**
 *  @brief      Convert the given string to an NHI_GATEWARE_VARIANT.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_GATEWARE_VARIANT.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_GATEWARE_VARIANT.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiGatewareVariantFromString(const char* string, NHI_GATEWARE_VARIANT* pValue);

/**
 *  @brief      Check if value is a valid NHI_GATEWARE_VARIANT.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_GATEWARE_VARIANT.
 *  @retval     FALSE   value is not a valid NHI_GATEWARE_VARIANT.
 */
DEH_EXPORT BOOL NhiGatewareVariantIsValid(NHI_GATEWARE_VARIANT value);


//  NHI_DIGOUT_TYPE Conversion routines

/**
 *  @brief      Convert type NHI_DIGOUT_TYPE to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiDigoutTypeToString(NHI_DIGOUT_TYPE value);

/**
 *  @brief      Convert type NHI_DIGOUT_TYPE to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiDigoutTypeToUserString(NHI_DIGOUT_TYPE value);

/**
 *  @brief      Convert type NHI_DIGOUT_TYPE to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiDigoutTypeToDescription(NHI_DIGOUT_TYPE value);

/**
 *  @brief      Convert the given string to an NHI_DIGOUT_TYPE.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_DIGOUT_TYPE.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_DIGOUT_TYPE.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiDigoutTypeFromString(const char* string, NHI_DIGOUT_TYPE* pValue);

/**
 *  @brief      Check if value is a valid NHI_DIGOUT_TYPE.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_DIGOUT_TYPE.
 *  @retval     FALSE   value is not a valid NHI_DIGOUT_TYPE.
 */
DEH_EXPORT BOOL NhiDigoutTypeIsValid(NHI_DIGOUT_TYPE value);


//  NHI_ADC_DIMENSION Conversion routines

/**
 *  @brief      Convert type NHI_ADC_DIMENSION to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiAdcDimensionToString(NHI_ADC_DIMENSION value);

/**
 *  @brief      Convert type NHI_ADC_DIMENSION to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiAdcDimensionToUserString(NHI_ADC_DIMENSION value);

/**
 *  @brief      Convert type NHI_ADC_DIMENSION to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiAdcDimensionToDescription(NHI_ADC_DIMENSION value);

/**
 *  @brief      Convert the given string to an NHI_ADC_DIMENSION.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_ADC_DIMENSION.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_ADC_DIMENSION.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiAdcDimensionFromString(const char* string, NHI_ADC_DIMENSION* pValue);

/**
 *  @brief      Check if value is a valid NHI_ADC_DIMENSION.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_ADC_DIMENSION.
 *  @retval     FALSE   value is not a valid NHI_ADC_DIMENSION.
 */
DEH_EXPORT BOOL NhiAdcDimensionIsValid(NHI_ADC_DIMENSION value);


//  NHI_LATCH_ID Conversion routines

/**
 *  @brief      Convert type NHI_LATCH_ID to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiLatchIdToString(NHI_LATCH_ID value);

/**
 *  @brief      Convert type NHI_LATCH_ID to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiLatchIdToUserString(NHI_LATCH_ID value);

/**
 *  @brief      Convert type NHI_LATCH_ID to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiLatchIdToDescription(NHI_LATCH_ID value);

/**
 *  @brief      Convert the given string to an NHI_LATCH_ID.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_LATCH_ID.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_LATCH_ID.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiLatchIdFromString(const char* string, NHI_LATCH_ID* pValue);

/**
 *  @brief      Check if value is a valid NHI_LATCH_ID.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_LATCH_ID.
 *  @retval     FALSE   value is not a valid NHI_LATCH_ID.
 */
DEH_EXPORT BOOL NhiLatchIdIsValid(NHI_LATCH_ID value);


//  NHI_DIGIN_COUNTER_ID Conversion routines

/**
 *  @brief      Convert type NHI_DIGIN_COUNTER_ID to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiDiginCounterIdToString(NHI_DIGIN_COUNTER_ID value);

/**
 *  @brief      Convert type NHI_DIGIN_COUNTER_ID to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiDiginCounterIdToUserString(NHI_DIGIN_COUNTER_ID value);

/**
 *  @brief      Convert type NHI_DIGIN_COUNTER_ID to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiDiginCounterIdToDescription(NHI_DIGIN_COUNTER_ID value);

/**
 *  @brief      Convert the given string to an NHI_DIGIN_COUNTER_ID.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_DIGIN_COUNTER_ID.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_DIGIN_COUNTER_ID.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiDiginCounterIdFromString(const char* string, NHI_DIGIN_COUNTER_ID* pValue);

/**
 *  @brief      Check if value is a valid NHI_DIGIN_COUNTER_ID.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_DIGIN_COUNTER_ID.
 *  @retval     FALSE   value is not a valid NHI_DIGIN_COUNTER_ID.
 */
DEH_EXPORT BOOL NhiDiginCounterIdIsValid(NHI_DIGIN_COUNTER_ID value);


//  NHI_ASPI_PORT_ID Conversion routines

/**
 *  @brief      Convert type NHI_ASPI_PORT_ID to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiAspiPortIdToString(NHI_ASPI_PORT_ID value);

/**
 *  @brief      Convert type NHI_ASPI_PORT_ID to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiAspiPortIdToUserString(NHI_ASPI_PORT_ID value);

/**
 *  @brief      Convert type NHI_ASPI_PORT_ID to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiAspiPortIdToDescription(NHI_ASPI_PORT_ID value);

/**
 *  @brief      Convert the given string to an NHI_ASPI_PORT_ID.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_ASPI_PORT_ID.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_ASPI_PORT_ID.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiAspiPortIdFromString(const char* string, NHI_ASPI_PORT_ID* pValue);

/**
 *  @brief      Check if value is a valid NHI_ASPI_PORT_ID.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_ASPI_PORT_ID.
 *  @retval     FALSE   value is not a valid NHI_ASPI_PORT_ID.
 */
DEH_EXPORT BOOL NhiAspiPortIdIsValid(NHI_ASPI_PORT_ID value);


//  NHI_ASPI_PORT_TYPE Conversion routines

/**
 *  @brief      Convert type NHI_ASPI_PORT_TYPE to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiAspiPortTypeToString(NHI_ASPI_PORT_TYPE value);

/**
 *  @brief      Convert type NHI_ASPI_PORT_TYPE to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiAspiPortTypeToUserString(NHI_ASPI_PORT_TYPE value);

/**
 *  @brief      Convert type NHI_ASPI_PORT_TYPE to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiAspiPortTypeToDescription(NHI_ASPI_PORT_TYPE value);

/**
 *  @brief      Convert the given string to an NHI_ASPI_PORT_TYPE.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_ASPI_PORT_TYPE.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_ASPI_PORT_TYPE.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiAspiPortTypeFromString(const char* string, NHI_ASPI_PORT_TYPE* pValue);

/**
 *  @brief      Check if value is a valid NHI_ASPI_PORT_TYPE.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_ASPI_PORT_TYPE.
 *  @retval     FALSE   value is not a valid NHI_ASPI_PORT_TYPE.
 */
DEH_EXPORT BOOL NhiAspiPortTypeIsValid(NHI_ASPI_PORT_TYPE value);


//  NHI_ASPI_STATE Conversion routines

/**
 *  @brief      Convert type NHI_ASPI_STATE to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiAspiStateToString(NHI_ASPI_STATE value);

/**
 *  @brief      Convert type NHI_ASPI_STATE to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiAspiStateToUserString(NHI_ASPI_STATE value);

/**
 *  @brief      Convert type NHI_ASPI_STATE to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiAspiStateToDescription(NHI_ASPI_STATE value);

/**
 *  @brief      Convert the given string to an NHI_ASPI_STATE.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_ASPI_STATE.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_ASPI_STATE.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiAspiStateFromString(const char* string, NHI_ASPI_STATE* pValue);

/**
 *  @brief      Check if value is a valid NHI_ASPI_STATE.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_ASPI_STATE.
 *  @retval     FALSE   value is not a valid NHI_ASPI_STATE.
 */
DEH_EXPORT BOOL NhiAspiStateIsValid(NHI_ASPI_STATE value);


//  NHI_ECG_CAM_TYPE Conversion routines

/**
 *  @brief      Convert type NHI_ECG_CAM_TYPE to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiEcgCamTypeToString(NHI_ECG_CAM_TYPE value);

/**
 *  @brief      Convert type NHI_ECG_CAM_TYPE to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiEcgCamTypeToUserString(NHI_ECG_CAM_TYPE value);

/**
 *  @brief      Convert type NHI_ECG_CAM_TYPE to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiEcgCamTypeToDescription(NHI_ECG_CAM_TYPE value);

/**
 *  @brief      Convert the given string to an NHI_ECG_CAM_TYPE.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_ECG_CAM_TYPE.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_ECG_CAM_TYPE.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiEcgCamTypeFromString(const char* string, NHI_ECG_CAM_TYPE* pValue);

/**
 *  @brief      Check if value is a valid NHI_ECG_CAM_TYPE.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_ECG_CAM_TYPE.
 *  @retval     FALSE   value is not a valid NHI_ECG_CAM_TYPE.
 */
DEH_EXPORT BOOL NhiEcgCamTypeIsValid(NHI_ECG_CAM_TYPE value);


//  NHI_SDC_CHANNEL_ID Conversion routines

/**
 *  @brief      Convert type NHI_SDC_CHANNEL_ID to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcChannelIdToString(NHI_SDC_CHANNEL_ID value);

/**
 *  @brief      Convert type NHI_SDC_CHANNEL_ID to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcChannelIdToUserString(NHI_SDC_CHANNEL_ID value);

/**
 *  @brief      Convert type NHI_SDC_CHANNEL_ID to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcChannelIdToDescription(NHI_SDC_CHANNEL_ID value);

/**
 *  @brief      Convert the given string to an NHI_SDC_CHANNEL_ID.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_SDC_CHANNEL_ID.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_SDC_CHANNEL_ID.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiSdcChannelIdFromString(const char* string, NHI_SDC_CHANNEL_ID* pValue);

/**
 *  @brief      Check if value is a valid NHI_SDC_CHANNEL_ID.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_SDC_CHANNEL_ID.
 *  @retval     FALSE   value is not a valid NHI_SDC_CHANNEL_ID.
 */
DEH_EXPORT BOOL NhiSdcChannelIdIsValid(NHI_SDC_CHANNEL_ID value);


//  NHI_SDC_PORT_ID Conversion routines

/**
 *  @brief      Convert type NHI_SDC_PORT_ID to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcPortIdToString(NHI_SDC_PORT_ID value);

/**
 *  @brief      Convert type NHI_SDC_PORT_ID to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcPortIdToUserString(NHI_SDC_PORT_ID value);

/**
 *  @brief      Convert type NHI_SDC_PORT_ID to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcPortIdToDescription(NHI_SDC_PORT_ID value);

/**
 *  @brief      Convert the given string to an NHI_SDC_PORT_ID.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_SDC_PORT_ID.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_SDC_PORT_ID.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiSdcPortIdFromString(const char* string, NHI_SDC_PORT_ID* pValue);

/**
 *  @brief      Check if value is a valid NHI_SDC_PORT_ID.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_SDC_PORT_ID.
 *  @retval     FALSE   value is not a valid NHI_SDC_PORT_ID.
 */
DEH_EXPORT BOOL NhiSdcPortIdIsValid(NHI_SDC_PORT_ID value);


//  NHI_SDC_MEMORY_BLOCK_ID Conversion routines

/**
 *  @brief      Convert type NHI_SDC_MEMORY_BLOCK_ID to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcMemoryBlockIdToString(NHI_SDC_MEMORY_BLOCK_ID value);

/**
 *  @brief      Convert type NHI_SDC_MEMORY_BLOCK_ID to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcMemoryBlockIdToUserString(NHI_SDC_MEMORY_BLOCK_ID value);

/**
 *  @brief      Convert type NHI_SDC_MEMORY_BLOCK_ID to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcMemoryBlockIdToDescription(NHI_SDC_MEMORY_BLOCK_ID value);

/**
 *  @brief      Convert the given string to an NHI_SDC_MEMORY_BLOCK_ID.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_SDC_MEMORY_BLOCK_ID.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_SDC_MEMORY_BLOCK_ID.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiSdcMemoryBlockIdFromString(const char* string, NHI_SDC_MEMORY_BLOCK_ID* pValue);

/**
 *  @brief      Check if value is a valid NHI_SDC_MEMORY_BLOCK_ID.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_SDC_MEMORY_BLOCK_ID.
 *  @retval     FALSE   value is not a valid NHI_SDC_MEMORY_BLOCK_ID.
 */
DEH_EXPORT BOOL NhiSdcMemoryBlockIdIsValid(NHI_SDC_MEMORY_BLOCK_ID value);


//  NHI_SDC_STATE Conversion routines

/**
 *  @brief      Convert type NHI_SDC_STATE to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcStateToString(NHI_SDC_STATE value);

/**
 *  @brief      Convert type NHI_SDC_STATE to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcStateToUserString(NHI_SDC_STATE value);

/**
 *  @brief      Convert type NHI_SDC_STATE to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcStateToDescription(NHI_SDC_STATE value);

/**
 *  @brief      Convert the given string to an NHI_SDC_STATE.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_SDC_STATE.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_SDC_STATE.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiSdcStateFromString(const char* string, NHI_SDC_STATE* pValue);

/**
 *  @brief      Check if value is a valid NHI_SDC_STATE.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_SDC_STATE.
 *  @retval     FALSE   value is not a valid NHI_SDC_STATE.
 */
DEH_EXPORT BOOL NhiSdcStateIsValid(NHI_SDC_STATE value);


//  NHI_SDC_COMMUNICATION_ERROR Conversion routines

/**
 *  @brief      Convert type NHI_SDC_COMMUNICATION_ERROR to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcCommunicationErrorToString(NHI_SDC_COMMUNICATION_ERROR value);

/**
 *  @brief      Convert type NHI_SDC_COMMUNICATION_ERROR to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcCommunicationErrorToUserString(NHI_SDC_COMMUNICATION_ERROR value);

/**
 *  @brief      Convert type NHI_SDC_COMMUNICATION_ERROR to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcCommunicationErrorToDescription(NHI_SDC_COMMUNICATION_ERROR value);

/**
 *  @brief      Convert the given string to an NHI_SDC_COMMUNICATION_ERROR.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_SDC_COMMUNICATION_ERROR.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_SDC_COMMUNICATION_ERROR.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiSdcCommunicationErrorFromString(const char* string, NHI_SDC_COMMUNICATION_ERROR* pValue);

/**
 *  @brief      Check if value is a valid NHI_SDC_COMMUNICATION_ERROR.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_SDC_COMMUNICATION_ERROR.
 *  @retval     FALSE   value is not a valid NHI_SDC_COMMUNICATION_ERROR.
 */
DEH_EXPORT BOOL NhiSdcCommunicationErrorIsValid(NHI_SDC_COMMUNICATION_ERROR value);


//  NHI_SDC_INITIALIZE_STATE Conversion routines

/**
 *  @brief      Convert type NHI_SDC_INITIALIZE_STATE to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcInitializeStateToString(NHI_SDC_INITIALIZE_STATE value);

/**
 *  @brief      Convert type NHI_SDC_INITIALIZE_STATE to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcInitializeStateToUserString(NHI_SDC_INITIALIZE_STATE value);

/**
 *  @brief      Convert type NHI_SDC_INITIALIZE_STATE to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API NhiSdcInitializeStateToDescription(NHI_SDC_INITIALIZE_STATE value);

/**
 *  @brief      Convert the given string to an NHI_SDC_INITIALIZE_STATE.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                     string is successfully converted to a valid NHI_SDC_INITIALIZE_STATE.
 *  @retval     NHI_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     NHI_ERR_UNKNOWN_ENUM_STRING string could not be converted to NHI_SDC_INITIALIZE_STATE.
 */
DEH_EXPORT NYCE_STATUS NYCE_API NhiSdcInitializeStateFromString(const char* string, NHI_SDC_INITIALIZE_STATE* pValue);

/**
 *  @brief      Check if value is a valid NHI_SDC_INITIALIZE_STATE.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid NHI_SDC_INITIALIZE_STATE.
 *  @retval     FALSE   value is not a valid NHI_SDC_INITIALIZE_STATE.
 */
DEH_EXPORT BOOL NhiSdcInitializeStateIsValid(NHI_SDC_INITIALIZE_STATE value);


/**
 *  @}
 */
#ifdef __cplusplus
}
#endif

#endif
