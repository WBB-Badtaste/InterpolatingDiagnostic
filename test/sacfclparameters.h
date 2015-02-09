/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2011
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: SAC
 *  %full_filespec: sacfclparameters.h`12:incl:1 %
 */
/**
 *  @file
 *  @brief  All Focus Control Loop parameters for an axis.
 */

#ifndef __SACFCLPARAMETERS_H__
#define __SACFCLPARAMETERS_H__

#include "sacparameters.h"

/**
 * @addtogroup sac_parameters
 * @{
 */

/**
 *  @defgroup fcl Focus Control Loop parameters
 *  @{
 */

/**
 *  @brief  Kp of the Master Controller
 *
 *  @datatype       double
 *  @unit           [cout/pu]
 *  @minvalue       0.0
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.masterCtrl.parKp
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_KP                                ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) |  1))

/**
 *  @brief  Ki of the Master Controller
 *
 *  @datatype       double
 *  @unit           [rad/s]
 *  @minvalue       0.0
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.masterCtrl.parKi
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_KI                                ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) |  2))

/**
 *  @brief  Upper saturation level of the Master Controller
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.masterCtrl.parSatLevelPos
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_POS_SAT_LEVEL                     ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) |  3))

/**
 *  @brief  Lower saturation level of the Master Controller
 *
 *  @datatype       double
 *  @unit           [pu]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.masterCtrl.parSatLevelNeg
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_NEG_SAT_LEVEL                     ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) |  4))

/**
 *  @brief  Rate Limiter of the Master Controller
 *
 *  @datatype       double
 *  @unit           [pu/s]
 *  @minvalue       0.0
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.masterCtrl.satOutValue
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_KR_LIMITER                        ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) |  5))

/**
 *  @brief  Damping factor of sensor S1 low pass filter
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   0.70710678118654752
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.sensor[0].lowPassFilter.damp
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_LPF1_DAMPING                      ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) |  6))

/**
 *  @brief  Damping factor of sensor S2 low pass filter
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   0.70710678118654752
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.sensor[1].lowPassFilter.damp
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_LPF2_DAMPING                      ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) |  7))

/**
 *  @brief  Cutoff frequency of sensor S1 low pass filter
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.0
 *  @maxvalue       4000.0  #0.5 / NHI_PAR_NODE_SAMPLE_TIME.value
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.sensor[0].lowPassFilter.frequency
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_LPF1_FREQ                         ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) |  8))

/**
 *  @brief  Cutoff frequency of sensor S2 low pass filter
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.0
 *  @maxvalue       4000.0  #0.5 / NHI_PAR_NODE_SAMPLE_TIME.value
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.sensor[1].lowPassFilter.frequency
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_LPF2_FREQ                         ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) |  9))

/**
 *  @brief  In-range threshold for sensor S1
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.sensor[0].parLimit
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_S1_LIMIT                          ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 10))

/**
 *  @brief  In-range threshold for sensor S2
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.sensor[1].parLimit
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_S2_LIMIT                          ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 11))

/**
 *  @brief  Offset for sensor S1
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.sensor[0].parOffset
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_S1_OFFSET                         ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 12))

/**
 *  @brief  Offset for sensor S2
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.sensor[1].parOffset
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_S2_OFFSET                         ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 13))

/**
 *  @brief  Threshold for minimum of S1 + S2 to satisfy Focus Signal OK condition
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       0.0
 *  @maxvalue       1.0e+30
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusSignalCondition.parMinSum
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_MIN_SUM                           ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 14))

/**
 *  @brief  Minimum number of DSP samples that SAC_PAR_FCL_MIN_SUM must be satisfied to satisfy Focus Signal OK condition
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @defaultvalue   0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusSignalCondition.parNThreshold
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_N_THRESHOLD                       ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_ULONG<<NYCE_FWTYPE_SHIFT) | 15))

/**
 *  @brief  Offset for Focus Signal
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusSignalCondition.parOffset
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_FOCUS_OFFSET                      ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 16))

/**
 *  @brief  Focus signal gain factor
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   1.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusSignalCondition.parGain
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_FOCUS_GAIN                        ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 17))

/**
 *  @brief  Minimum number of DSP samples that Calibration Inhibit must be active to satisfy Focus Ready condition
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @defaultvalue   0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusRdyCondition.parLThreshold
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_FRDY_L_THRESHOLD                  ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_ULONG<<NYCE_FWTYPE_SHIFT) | 18))

/**
 *  @brief  Minimum number of DSP samples that focus Signal must be within SAC_PAR_FCL_FRDY_FOCUS_THRESHOLD to satisfy Focus Ready condition
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @defaultvalue   0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusRdyCondition.parKThreshold
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_FRDY_K_THRESHOLD                  ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_ULONG<<NYCE_FWTYPE_SHIFT) | 19))

/**
 *  @brief  Threshold for low-pass filtered focus signal for Focus Ready condition
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusRdyCondition.parFocusSignalThreshold
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_FRDY_FOCUS_THRESHOLD              ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 20))

/**
 *  @brief  Damping of the focus signal low-pass filter for Focus Ready condition
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   0.70710678118654752
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusRdyCondition.focusSignalLpFilter.damp
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_FRDY_LPF_DAMPING                  ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 21))

/**
 *  @brief  Cutoff frequency for the focus signal low-pass filter for Focus Ready condition
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.0
 *  @maxvalue       4000.0  #0.5 / NHI_PAR_NODE_SAMPLE_TIME.value.value
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusRdyCondition.focusSignalLpFilter.frequency
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_FRDY_LPF_FREQ                     ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 22))

/**
 *  @brief  Split ratio factor for sensor S1
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   1.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusSignalCondition.parSplitRatio
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_SPLIT_RATIO                       ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 23))

/**
 *  @brief  Calibration enable flag
 *
 *  @datatype       BOOL
 *  @defaultvalue   TRUE
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusCalibration.parEnable
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_CAL_ENABLE                        ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_BOOL <<NYCE_FWTYPE_SHIFT) | 24))

/**
 *  @brief  Calibration inhibit flag
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusCalibration.parInhibit
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_CAL_INHIBIT                       ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_BOOL <<NYCE_FWTYPE_SHIFT) | 25))

/**
 *  @brief  Damping for all applied high-pass filters of the Calibration unit
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   0.70710678118654752
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusCalibration.highPassFilter[0].damp
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_CAL_HPF_DAMPING                   ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 26))

/**
 *  @brief  Cutoff frequency for all applied high-pass filters of the Calibration unit
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.0
 *  @maxvalue       4000.0  #0.5 / NHI_PAR_NODE_SAMPLE_TIME.value
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusCalibration.highPassFilter[0].frequency
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_CAL_HPF_FREQ                      ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 27))

/**
 *  @brief  Damping for all applied low-pass filters of the Calibration unit
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       1.0
 *  @defaultvalue   0.70710678118654752
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusCalibration.lowPassFilter[0].damp
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_CAL_LPF_DAMPING                   ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 28))

/**
 *  @brief  Cutoff frequency for all applied low-pass filters of the Calibration unit
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.0
 *  @maxvalue       4000.0  #0.5 / NHI_PAR_NODE_SAMPLE_TIME.value
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusCalibration.lowPassFilter[0].frequency
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_CAL_LPF_FREQ                      ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 29))

/**
 *  @brief  Upper saturation level of the Calibration
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   2.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusCalibration.parSatLevelPos
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_CAL_POS_SAT_LEVEL                 ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 30))

/**
 *  @brief  Lower saturation level of the Calibration
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       -3.4e+38
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusCalibration.parSatLevelNeg
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_CAL_NEG_SAT_LEVEL                 ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 31))

/**
 *  @brief  Amplitude for the Calibration test signal
 *
 *  @datatype       double
 *  @unit           [-]
 *  @minvalue       0.0
 *  @maxvalue       +3.4e+38
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusCalibration.testSignalData.parAmplitude
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_CAL_TEST_AMPLITUDE                ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 32))

/**
 *  @brief  Frequency for the Calibration test signal
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.0
 *  @maxvalue       4000.0  #0.5 / NHI_PAR_NODE_SAMPLE_TIME.value
 *  @defaultvalue   0.0
 *  @xmlPath        -
 *  @_adminPath     fcl.privateData.focusCalibration.testSignalData.parFrequency
 *  @readOnly       FALSE
 */
#define SAC_PAR_FCL_CAL_TEST_FREQ                     ((SAC_PAR_ID)(RW | ((SS_EXT<<NYCE_SUBSYS_SHIFT)|( FWM_SPGFCL<<NYCE_FWMODULE_SHIFT)) | (FW_FLOAT<<NYCE_FWTYPE_SHIFT) | 33))

/**
 * @}

 */

/**
 * @}
 */

#endif
