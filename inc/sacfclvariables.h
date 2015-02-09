/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2011
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: SAC
 *  %full_filespec: sacfclvariables.h`1.1.1:incl:1 %
 */
/**
 *  @file
 *  @brief  All variables for an axis.
 */

#ifndef __SACFCLVARIABLES_H__
#define __SACFCLVARIABLES_H__

#include "sacvariables.h"

/**
 * @addtogroup sac
 * @{
 */

/**
 *  @brief  State of the focus control loop
 *
 *  @datatype       SAC_FCL_STATE
 */
#define SAC_VAR_FCL_STATE                             ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_LONG <<NYCE_FWTYPE_SHIFT) | 128))

/**
 *  @brief  Sensor 1 focus signal
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_FCL_S1                                ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT <<NYCE_FWTYPE_SHIFT) | 129))

/**
 *  @brief  Sensor 2 focus signal
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_FCL_S2                                ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT <<NYCE_FWTYPE_SHIFT) | 130))

/**
 *  @brief  Summation of sensor 1 and 2 signal (S1+S2)
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_FCL_SUM_SIGNAL                        ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT <<NYCE_FWTYPE_SHIFT) | 131))

/**
 *  @brief  Difference of sensor 1 and 2 signals (S2-S1)
 *
 *  @datatype       double
 *  @unit           [V]
 */
#define SAC_VAR_FCL_DIFF_SIGNAL                       ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT <<NYCE_FWTYPE_SHIFT) | 132))

/**
 *  @brief  Processed focus signal (0 = in focus)
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_FCL_FOCUS_SIGNAL                      ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT <<NYCE_FWTYPE_SHIFT) | 133))

/**
 *  @brief  Focus_OK if sensors receive enough light
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_FCL_FOCUS_OK                          ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_BOOL  <<NYCE_FWTYPE_SHIFT) | 134))

/**
 *  @brief  Focus signal is stable and in range   
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_FCL_FOCUS_READY                       ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_BOOL  <<NYCE_FWTYPE_SHIFT) | 135))

/**
 *  @brief  Sensor 1 signal is below the set limit value
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_FCL_S1_IN_RANGE                       ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_BOOL  <<NYCE_FWTYPE_SHIFT) | 136))

/**
 *  @brief  Sensor 2 signal is below the set limit value
 *
 *  @datatype       BOOL
 */
#define SAC_VAR_FCL_S2_IN_RANGE                       ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_BOOL  <<NYCE_FWTYPE_SHIFT) | 137))

/**
 *  @brief  Integratorbuffer value
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_FCL_INTEGRATOR                        ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT <<NYCE_FWTYPE_SHIFT) | 138))

/**
 *  @brief  Lowpass filtered focus signal
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_FCL_FOCUS_SIGNAL_FILT                 ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT <<NYCE_FWTYPE_SHIFT) | 139))

/**
 *  @brief  Focus control loop calibration gain
 *
 *  @datatype       double
 *  @unit           [-]
 */
#define SAC_VAR_FCL_CAL_GAIN                          ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT <<NYCE_FWTYPE_SHIFT) | 140))

/**
 *  @brief  Focus control loop calibration test signal (sine)
 *
 *  @datatype       double
 *  @unit           [pu]
 */
#define SAC_VAR_FCL_CAL_TEST_SIGNAL                   ((SAC_VAR_ID)(RO | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT <<NYCE_FWTYPE_SHIFT) | 141))


/**
 * @}
 */

#endif
