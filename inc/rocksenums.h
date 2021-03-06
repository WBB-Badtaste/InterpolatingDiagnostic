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
 *  @brief  Enum conversion functions for rocks.
 *  
 *  For every enum in the rocks subsystem the following type to string conversion functions exist:
 *  - "<TYPE>ToString(TYPE)"            Convert the given value of "<TYPE>" to its exact string representation.
 *  - "<TYPE>ToUserString(TYPE)"        Convert the given value of "<TYPE>" to a human readable string.
 *  - "<TYPE>ToDescription(TYPE)"       Convert the given value of "<TYPE>" to a descriptive string.
 *  - "<TYPE>FromString(string, TYPE)"  Convert the given string to value of "<TYPE>".
 *  - "<TYPE>IsValid(TYPE)"             Checks if the given value of "<TYPE>" is valid.
 */

#ifndef __ROCKSENUMS_H__
#define __ROCKSENUMS_H__

#include "rocksapi.h"

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
 *  @addtogroup rocks_conversion
 *  @{
 */

//  ROCKS_PLANE Conversion routines

/**
 *  @brief      Convert type ROCKS_PLANE to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksPlaneToString(ROCKS_PLANE value);

/**
 *  @brief      Convert type ROCKS_PLANE to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksPlaneToUserString(ROCKS_PLANE value);

/**
 *  @brief      Convert type ROCKS_PLANE to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API RocksPlaneToDescription(ROCKS_PLANE value);

/**
 *  @brief      Convert the given string to an ROCKS_PLANE.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                       string is successfully converted to a valid ROCKS_PLANE.
 *  @retval     ROCKS_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     ROCKS_ERR_UNKNOWN_ENUM_STRING string could not be converted to ROCKS_PLANE.
 */
DEH_EXPORT NYCE_STATUS NYCE_API RocksPlaneFromString(const char* string, ROCKS_PLANE* pValue);

/**
 *  @brief      Check if value is a valid ROCKS_PLANE.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid ROCKS_PLANE.
 *  @retval     FALSE   value is not a valid ROCKS_PLANE.
 */
DEH_EXPORT BOOL RocksPlaneIsValid(ROCKS_PLANE value);


//  ROCKS_GANTRY_DIRECTION Conversion routines

/**
 *  @brief      Convert type ROCKS_GANTRY_DIRECTION to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksGantryDirectionToString(ROCKS_GANTRY_DIRECTION value);

/**
 *  @brief      Convert type ROCKS_GANTRY_DIRECTION to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksGantryDirectionToUserString(ROCKS_GANTRY_DIRECTION value);

/**
 *  @brief      Convert type ROCKS_GANTRY_DIRECTION to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API RocksGantryDirectionToDescription(ROCKS_GANTRY_DIRECTION value);

/**
 *  @brief      Convert the given string to an ROCKS_GANTRY_DIRECTION.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                       string is successfully converted to a valid ROCKS_GANTRY_DIRECTION.
 *  @retval     ROCKS_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     ROCKS_ERR_UNKNOWN_ENUM_STRING string could not be converted to ROCKS_GANTRY_DIRECTION.
 */
DEH_EXPORT NYCE_STATUS NYCE_API RocksGantryDirectionFromString(const char* string, ROCKS_GANTRY_DIRECTION* pValue);

/**
 *  @brief      Check if value is a valid ROCKS_GANTRY_DIRECTION.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid ROCKS_GANTRY_DIRECTION.
 *  @retval     FALSE   value is not a valid ROCKS_GANTRY_DIRECTION.
 */
DEH_EXPORT BOOL RocksGantryDirectionIsValid(ROCKS_GANTRY_DIRECTION value);


//  ROCKS_MOVE_TYPE Conversion routines

/**
 *  @brief      Convert type ROCKS_MOVE_TYPE to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksMoveTypeToString(ROCKS_MOVE_TYPE value);

/**
 *  @brief      Convert type ROCKS_MOVE_TYPE to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksMoveTypeToUserString(ROCKS_MOVE_TYPE value);

/**
 *  @brief      Convert type ROCKS_MOVE_TYPE to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API RocksMoveTypeToDescription(ROCKS_MOVE_TYPE value);

/**
 *  @brief      Convert the given string to an ROCKS_MOVE_TYPE.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                       string is successfully converted to a valid ROCKS_MOVE_TYPE.
 *  @retval     ROCKS_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     ROCKS_ERR_UNKNOWN_ENUM_STRING string could not be converted to ROCKS_MOVE_TYPE.
 */
DEH_EXPORT NYCE_STATUS NYCE_API RocksMoveTypeFromString(const char* string, ROCKS_MOVE_TYPE* pValue);

/**
 *  @brief      Check if value is a valid ROCKS_MOVE_TYPE.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid ROCKS_MOVE_TYPE.
 *  @retval     FALSE   value is not a valid ROCKS_MOVE_TYPE.
 */
DEH_EXPORT BOOL RocksMoveTypeIsValid(ROCKS_MOVE_TYPE value);


//  ROCKS_TRAJ_TYPE Conversion routines

/**
 *  @brief      Convert type ROCKS_TRAJ_TYPE to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksTrajTypeToString(ROCKS_TRAJ_TYPE value);

/**
 *  @brief      Convert type ROCKS_TRAJ_TYPE to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksTrajTypeToUserString(ROCKS_TRAJ_TYPE value);

/**
 *  @brief      Convert type ROCKS_TRAJ_TYPE to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API RocksTrajTypeToDescription(ROCKS_TRAJ_TYPE value);

/**
 *  @brief      Convert the given string to an ROCKS_TRAJ_TYPE.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                       string is successfully converted to a valid ROCKS_TRAJ_TYPE.
 *  @retval     ROCKS_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     ROCKS_ERR_UNKNOWN_ENUM_STRING string could not be converted to ROCKS_TRAJ_TYPE.
 */
DEH_EXPORT NYCE_STATUS NYCE_API RocksTrajTypeFromString(const char* string, ROCKS_TRAJ_TYPE* pValue);

/**
 *  @brief      Check if value is a valid ROCKS_TRAJ_TYPE.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid ROCKS_TRAJ_TYPE.
 *  @retval     FALSE   value is not a valid ROCKS_TRAJ_TYPE.
 */
DEH_EXPORT BOOL RocksTrajTypeIsValid(ROCKS_TRAJ_TYPE value);


//  ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR Conversion routines

/**
 *  @brief      Convert type ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksTrajCubicJointBehaviorToString(ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR value);

/**
 *  @brief      Convert type ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksTrajCubicJointBehaviorToUserString(ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR value);

/**
 *  @brief      Convert type ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API RocksTrajCubicJointBehaviorToDescription(ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR value);

/**
 *  @brief      Convert the given string to an ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                       string is successfully converted to a valid ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR.
 *  @retval     ROCKS_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     ROCKS_ERR_UNKNOWN_ENUM_STRING string could not be converted to ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR.
 */
DEH_EXPORT NYCE_STATUS NYCE_API RocksTrajCubicJointBehaviorFromString(const char* string, ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR* pValue);

/**
 *  @brief      Check if value is a valid ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR.
 *  @retval     FALSE   value is not a valid ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR.
 */
DEH_EXPORT BOOL RocksTrajCubicJointBehaviorIsValid(ROCKS_TRAJ_CUBIC_JOINT_BEHAVIOR value);


//  ROCKS_MECH_STEP Conversion routines

/**
 *  @brief      Convert type ROCKS_MECH_STEP to the exact string representation.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksMechStepToString(ROCKS_MECH_STEP value);

/**
 *  @brief      Convert type ROCKS_MECH_STEP to a human readable string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The human readable string representation of value.
 */
DEH_EXPORT const char* NYCE_API RocksMechStepToUserString(ROCKS_MECH_STEP value);

/**
 *  @brief      Convert type ROCKS_MECH_STEP to a descriptive string.
 *
 *  @param[in]  value   The value to convert.
 *
 *  @return     The description of value.
 */
DEH_EXPORT const char* NYCE_API RocksMechStepToDescription(ROCKS_MECH_STEP value);

/**
 *  @brief      Convert the given string to an ROCKS_MECH_STEP.
 *
 *  @param[in]  string  The string to convert.
 *  @param[out] pValue  The enum value of string.
 *
 *  @retval     NYCE_OK                       string is successfully converted to a valid ROCKS_MECH_STEP.
 *  @retval     ROCKS_ERR_INVALID_PARAMETER   string or pValue is NULL.
 *  @retval     ROCKS_ERR_UNKNOWN_ENUM_STRING string could not be converted to ROCKS_MECH_STEP.
 */
DEH_EXPORT NYCE_STATUS NYCE_API RocksMechStepFromString(const char* string, ROCKS_MECH_STEP* pValue);

/**
 *  @brief      Check if value is a valid ROCKS_MECH_STEP.
 *
 *  @param[in]  value   The value to check.
 *
 *  @retval     TRUE    value is a valid ROCKS_MECH_STEP.
 *  @retval     FALSE   value is not a valid ROCKS_MECH_STEP.
 */
DEH_EXPORT BOOL RocksMechStepIsValid(ROCKS_MECH_STEP value);


/**
 *  @}
 */
#ifdef __cplusplus
}
#endif

#endif
