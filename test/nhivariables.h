/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2011-2012
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: NHI
 *  %full_filespec: nhivariables.h`11.2.4:incl:1 %
 */
/**
 *  @file
 *  @brief  All variables for a node.
 */

#ifndef __NHIVARIABLES_H__
#define __NHIVARIABLES_H__

#include "n4k_deprecated.h" //lint !e451
#include "n4k_basictypes.h"

/**
 * @addtogroup nhi_variables
 * @{
 */

/** Node variable ID type. */
typedef uint32_t NHI_VAR_ID;

/**
 *  @defgroup node_variables Node variables
 *  @{
 */

/**
 *  @brief  Time spent by last sample.
 *
 *  @datatype       double
 *  @unit           [s]
 */
#define NHI_VAR_SAMPLE_DURATION                       ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  Longest time spent by any sample (excluding the initial sample and overruns).
 *
 *  @datatype       double
 *  @unit           [s]
 */
#define NHI_VAR_SAMPLE_DURATION_MAX                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Number is incremented by 1/2/4/8 for 8/4/2/1 Khz loops (step depends on loop frequency).
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define NHI_VAR_SAMPLE_NUMBER                         ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Service input active level detected.
 *
 *  @datatype       BOOL
 */
#define NHI_VAR_SERVICE_INPUT                         ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Stop axes input active level detected.
 *
 *  @datatype       BOOL
 */
#define NHI_VAR_STOP_AXES_INPUT                       ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Pointer to the sequence administration memory location.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_NODE_SQC_MEMORY                       ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLMCU<<NYCE_FWMODULE_SHIFT)|0))


/**
 *  @}
 */

/**
 *  @defgroup nhi_user_variables SQC and UDC user variables
 *  @{
 */

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 0
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_0                                ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 1
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_1                                ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 2
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_2                                ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 3
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_3                                ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 4
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_4                                ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 5
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_5                                ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 6
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_6                                ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 7
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_7                                ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 8
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_8                                ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 9
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_9                                ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 10
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_10                               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 11
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_11                               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 12
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_12                               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 13
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_13                               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 14
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_14                               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  For SQC and UDC user variable tracing - node variable 15
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_NODE_15                               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @}
 */

/**
 *  @brief  Contains the ID of the last processed invalid parameter.
 *
 *  @datatype       NHI_PAR_ID
 */
#define NHI_VAR_ID_OF_INVALID_PAR                     ((NHI_VAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @defgroup nhi_debug debug variables
 *
 *  for internal use only.
 *
 *  @{
 */

/**
 *  @brief  Node debug float value 0
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_FLOAT_VALUE_0                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  Node debug float value 1
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_FLOAT_VALUE_1                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  Node debug float value 2
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_FLOAT_VALUE_2                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  Node debug float value 3
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_FLOAT_VALUE_3                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  Node debug float value 4
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_FLOAT_VALUE_4                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  Node debug float value 5
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_FLOAT_VALUE_5                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  Node debug float value 6
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_FLOAT_VALUE_6                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  Node debug float value 7
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_FLOAT_VALUE_7                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  Node debug int value 0
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_INT_VALUE_0                     ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  Node debug int value 1
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_INT_VALUE_1                     ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  Node debug int value 2
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_INT_VALUE_2                     ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  Node debug int value 3
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_INT_VALUE_3                     ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  Node debug int value 4
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_INT_VALUE_4                     ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  Node debug int value 5
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_INT_VALUE_5                     ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  Node debug int value 6
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_INT_VALUE_6                     ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @brief  Node debug int value 7
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DEBUG_INT_VALUE_7                     ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|37))

/**
 *  @}
 */

/**
 *  @defgroup sdc_variables Serial Data Channel variables
 *  @{
 */

/**
 *  @brief  Serial data channel 0 state
 *
 *  @datatype       NHI_SDC_STATE
 */
#define NHI_VAR_SDC_STATE_CHANNEL0                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|38))

/**
 *  @brief  Serial data channel 1 state
 *
 *  @datatype       NHI_SDC_STATE
 */
#define NHI_VAR_SDC_STATE_CHANNEL1                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|39))

/**
 *  @brief  Serial data channel 2 state
 *
 *  @datatype       NHI_SDC_STATE
 */
#define NHI_VAR_SDC_STATE_CHANNEL2                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|40))

/**
 *  @brief  Serial data channel 3 state
 *
 *  @datatype       NHI_SDC_STATE
 */
#define NHI_VAR_SDC_STATE_CHANNEL3                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|41))

/**
 *  @brief  Serial data channel 0 error
 *
 *  @datatype       NHI_SDC_COMMUNICATION_ERROR
 */
#define NHI_VAR_SDC_COMMUNICATION_ERROR_CHANNEL0      ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|42))

/**
 *  @brief  Serial data channel 1 error
 *
 *  @datatype       NHI_SDC_COMMUNICATION_ERROR
 */
#define NHI_VAR_SDC_COMMUNICATION_ERROR_CHANNEL1      ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|43))

/**
 *  @brief  Serial data channel 2 error
 *
 *  @datatype       NHI_SDC_COMMUNICATION_ERROR
 */
#define NHI_VAR_SDC_COMMUNICATION_ERROR_CHANNEL2      ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|44))

/**
 *  @brief  Serial data channel 3 error
 *
 *  @datatype       NHI_SDC_COMMUNICATION_ERROR
 */
#define NHI_VAR_SDC_COMMUNICATION_ERROR_CHANNEL3      ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|45))

/**
 *  @brief  Serial data channel 0 general error flag
 *
 *  @datatype       BOOL
 */
#define NHI_VAR_SDC_GENERAL_ERROR_DETECTED_CHANNEL0   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|46))

/**
 *  @brief  Serial data channel 1 general error flag
 *
 *  @datatype       BOOL
 */
#define NHI_VAR_SDC_GENERAL_ERROR_DETECTED_CHANNEL1   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|47))

/**
 *  @brief  Serial data channel 2 general error flag
 *
 *  @datatype       BOOL
 */
#define NHI_VAR_SDC_GENERAL_ERROR_DETECTED_CHANNEL2   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|48))

/**
 *  @brief  Serial data channel 3 general error flag
 *
 *  @datatype       BOOL
 */
#define NHI_VAR_SDC_GENERAL_ERROR_DETECTED_CHANNEL3   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|49))

/**
 *  @brief  Serial data channel 0 data
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define NHI_VAR_SDC_SYNCHRONOUS_DATA_CHANNEL0         ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|50))

/**
 *  @brief  Serial data channel 1 data
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define NHI_VAR_SDC_SYNCHRONOUS_DATA_CHANNEL1         ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|51))

/**
 *  @brief  Serial data channel 2 data
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define NHI_VAR_SDC_SYNCHRONOUS_DATA_CHANNEL2         ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|52))

/**
 *  @brief  Serial data channel 3 data
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 */
#define NHI_VAR_SDC_SYNCHRONOUS_DATA_CHANNEL3         ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|53))

/**
 *  @brief  Serial data channel 0 last succesful init substate
 *
 *  Substate within the nhi_sdc_initialize_state
 *
 *  @datatype       NHI_SDC_INITIALIZE_STATE
 */
#define NHI_VAR_SDC_LAST_SUCCESSFUL_INIT_STATE_CHANNEL0 ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|54))

/**
 *  @brief  Serial data channel 1 last succesful init substate
 *
 *  Substate within the nhi_sdc_initialize_state
 *
 *  @datatype       NHI_SDC_INITIALIZE_STATE
 */
#define NHI_VAR_SDC_LAST_SUCCESSFUL_INIT_STATE_CHANNEL1 ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|55))

/**
 *  @brief  Serial data channel 2 last succesful init substate
 *
 *  Substate within the nhi_sdc_initialize_state
 *
 *  @datatype       NHI_SDC_INITIALIZE_STATE
 */
#define NHI_VAR_SDC_LAST_SUCCESSFUL_INIT_STATE_CHANNEL2 ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|56))

/**
 *  @brief  Serial data channel 3 last succesful init substate
 *
 *  Substate within the nhi_sdc_initialize_state
 *
 *  @datatype       NHI_SDC_INITIALIZE_STATE
 */
#define NHI_VAR_SDC_LAST_SUCCESSFUL_INIT_STATE_CHANNEL3 ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|57))

/**
 *  @}
 */

/**
 *  @defgroup drive_variables Drive variables
 *  @{
 */

/**
 *  @brief  Digital IO status slot 0
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 */
#define NHI_VAR_DIG_IO_STATUS_SLOT0                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  Digital IO status slot 1
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 */
#define NHI_VAR_DIG_IO_STATUS_SLOT1                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  Digital IO status slot 2
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 */
#define NHI_VAR_DIG_IO_STATUS_SLOT2                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  Digital IO status slot 3
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 */
#define NHI_VAR_DIG_IO_STATUS_SLOT3                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  Digital IO status slot 4
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 */
#define NHI_VAR_DIG_IO_STATUS_SLOT4                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  Analog in0 value slot 0
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_IN0_VALUE_SLOT0                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Analog in0 value slot 1
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_IN0_VALUE_SLOT1                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Analog in0 value slot 2
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_IN0_VALUE_SLOT2                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Analog in0 value slot 3
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_IN0_VALUE_SLOT3                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Analog in0 value slot 4
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_IN0_VALUE_SLOT4                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Analog in1 value slot 0
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_IN1_VALUE_SLOT0                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Analog in1 value slot 1
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_IN1_VALUE_SLOT1                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Analog in1 value slot 2
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_IN1_VALUE_SLOT2                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Analog in1 value slot 3
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_IN1_VALUE_SLOT3                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Analog in1 value slot 4
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_IN1_VALUE_SLOT4                    ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Digital in counter 0 slot 0
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER0_SLOT0                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Digital in counter 0 slot 1
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER0_SLOT1                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Digital in counter 0 slot 2
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER0_SLOT2                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Digital in counter 0 slot 3
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER0_SLOT3                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Digital in counter 0 slot 4
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER0_SLOT4                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Digital in counter 1 slot 0
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER1_SLOT0                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Digital in counter 1 slot 1
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER1_SLOT1                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Digital in counter 1 slot 2
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER1_SLOT2                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Digital in counter 1 slot 3
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER1_SLOT3                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Digital in counter 1 slot 4
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER1_SLOT4                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Digital in counter 2 slot 0
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER2_SLOT0                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  Digital in counter 2 slot 1
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER2_SLOT1                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  Digital in counter 2 slot 2
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER2_SLOT2                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  Digital in counter 2 slot 3
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER2_SLOT3                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  Digital in counter 2 slot 4
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER2_SLOT4                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  Digital in counter 3 slot 0
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER3_SLOT0                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Digital in counter 3 slot 1
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER3_SLOT1                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Digital in counter 3 slot 2
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER3_SLOT2                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Digital in counter 3 slot 3
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER3_SLOT3                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Digital in counter 3 slot 4
 *
 *  @datatype       int32_t
 *  @unit           [-]
 */
#define NHI_VAR_DIGIN_COUNTER3_SLOT4                  ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Analog out0 value slot 0
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_OUT0_VALUE_SLOT0                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Analog out0 value slot 1
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_OUT0_VALUE_SLOT1                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Analog out0 value slot 2
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_OUT0_VALUE_SLOT2                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Analog out0 value slot 3
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_OUT0_VALUE_SLOT3                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Analog out0 value slot 4
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_OUT0_VALUE_SLOT4                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Analog out1 value slot 0
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_OUT1_VALUE_SLOT0                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  Analog out1 value slot 1
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_OUT1_VALUE_SLOT1                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  Analog out1 value slot 2
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_OUT1_VALUE_SLOT2                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  Analog out1 value slot 3
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_OUT1_VALUE_SLOT3                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  Analog out1 value slot 4
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_AN_OUT1_VALUE_SLOT4                   ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  Drive positive voltage slot 0
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_DRIVE_POS_VOLTAGE_SLOT0               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  Drive positive voltage slot 1
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_DRIVE_POS_VOLTAGE_SLOT1               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  Drive positive voltage slot 2
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_DRIVE_POS_VOLTAGE_SLOT2               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  Drive positive voltage slot 3
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_DRIVE_POS_VOLTAGE_SLOT3               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  Drive positive voltage slot 4
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_DRIVE_POS_VOLTAGE_SLOT4               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  Drive negative voltage slot 0
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_DRIVE_NEG_VOLTAGE_SLOT0               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Drive negative voltage slot 1
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_DRIVE_NEG_VOLTAGE_SLOT1               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Drive negative voltage slot 2
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_DRIVE_NEG_VOLTAGE_SLOT2               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Drive negative voltage slot 3
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_DRIVE_NEG_VOLTAGE_SLOT3               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Drive negative voltage slot 4
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define NHI_VAR_DRIVE_NEG_VOLTAGE_SLOT4               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Drive temperature slot 0
 *
 *  @datatype       double
 *  @unit           [deg C]
 */
#define NHI_VAR_DRIVE_TEMPERATURE_SLOT0               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  Drive temperature slot 1
 *
 *  @datatype       double
 *  @unit           [deg C]
 */
#define NHI_VAR_DRIVE_TEMPERATURE_SLOT1               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  Drive temperature slot 2
 *
 *  @datatype       double
 *  @unit           [deg C]
 */
#define NHI_VAR_DRIVE_TEMPERATURE_SLOT2               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  Drive temperature slot 3
 *
 *  @datatype       double
 *  @unit           [deg C]
 */
#define NHI_VAR_DRIVE_TEMPERATURE_SLOT3               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  Drive temperature slot 4
 *
 *  @datatype       double
 *  @unit           [deg C]
 */
#define NHI_VAR_DRIVE_TEMPERATURE_SLOT4               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|11))


/**
 *  @brief  Gateware variant slot 0
 *
 *  @datatype       NHI_GATEWARE_VARIANT
 */
#define NHI_VAR_GATEWARE_VARIANT_SLOT0               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  Gateware variant slot 1
 *
 *  @datatype       NHI_GATEWARE_VARIANT
 */
#define NHI_VAR_GATEWARE_VARIANT_SLOT1               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  Gateware variant slot 2
 *
 *  @datatype       NHI_GATEWARE_VARIANT
 */
#define NHI_VAR_GATEWARE_VARIANT_SLOT2               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  Gateware variant slot 3
 *
 *  @datatype       NHI_GATEWARE_VARIANT
 */
#define NHI_VAR_GATEWARE_VARIANT_SLOT3               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  Gateware variant slot 4
 *
 *  @datatype       NHI_GATEWARE_VARIANT
 */
#define NHI_VAR_GATEWARE_VARIANT_SLOT4               ((NHI_VAR_ID)(RO|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_GENSTATUS<<NYCE_FWMODULE_SHIFT)|12))


/**
 *  @}
 */

/**
 * @}
 */

#endif
