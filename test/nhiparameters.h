/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2012
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: NHI
 *  %full_filespec:  nhiparameters.h`18:incl:2 %
 */
/**
 *  @file
 *  @brief  All parameters for a node.
 */

#ifndef __NHIPARAMETERS_H__
#define __NHIPARAMETERS_H__

#include "n4k_deprecated.h" //lint !e451
#include "n4k_basictypes.h"

/**
 * @addtogroup nhi_parameters
 * @{
 */

/** Node parameter ID type. */
typedef uint32_t NHI_PAR_ID;

/**
 *  @defgroup node_parameters Node parameters
 *  @{
 */

/**
 *  @brief  Node sample time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.000125
 *  @maxvalue       0.001
 *  @defaultvalue   0.001
 *  @xmlPath        PARAMETERS/NHI_PAR_NODE_SAMPLE_TIME
 *  @_adminPath     nodePars.node_sample_time
 *  @readOnly       FALSE
 */
#define NHI_PAR_NODE_SAMPLE_TIME                      ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLMCU<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  Stop all axes input signal polarity.
 *
 *  @datatype       NYCE_ACTIVE_STATE
 *  @defaultvalue   NYCE_ACTIVE_HIGH
 *  @xmlPath        PARAMETERS/NHI_PAR_NODE_STOP_AXES_POLARITY
 *  @_adminPath     nodePars.stop_axes_polarity
 *  @readOnly       FALSE
 */
#define NHI_PAR_NODE_STOP_AXES_POLARITY               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLMCU<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Service input signal polarity.
 *
 *  @datatype       NYCE_ACTIVE_STATE
 *  @defaultvalue   NYCE_ACTIVE_HIGH
 *  @xmlPath        PARAMETERS/NHI_PAR_NODE_SERVICE_POLARITY
 *  @_adminPath     nodePars.service_polarity
 *  @readOnly       FALSE
 */
#define NHI_PAR_NODE_SERVICE_POLARITY                 ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLMCU<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Enable soft-core high speed data tracing.
 *
 *  @datatype       BOOL
 *  @defaultvalue   FALSE
 *  @xmlPath        PARAMETERS/NHI_PAR_NODE_HSD_ENABLE
 *  @_adminPath     nodePars.hsd_enable
 *  @readOnly       FALSE
 */
#define NHI_PAR_NODE_HSD_ENABLE                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_BOOL<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLMCU<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  If the duration of sample is larger than specified by NHI_PAR_NODE_SAMPLE_TIME, the sample overrun count increases by 1.
 *
 *  The sample overrun count starts counting at 1.
 *
 *  @datatype       uint32_t
 *  @unit           [-]
 *  @minvalue       2
 *  @maxvalue       3
 *  @defaultvalue   2
 *  @xmlPath        PARAMETERS/NHI_PAR_NODE_SAMPLE_OVERRUN_THRESHOLD
 *  @_adminPath     nodePars.node_sample_overrun_threshold
 *  @readOnly       FALSE
 */
#define NHI_PAR_NODE_SAMPLE_OVERRUN_THRESHOLD         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EDHCHECK<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @}
 */

/**
 *  @defgroup sdc_parameters Serial Data Channel parameters
 *  @{
 */

/**
 *  @brief  Serial data channel port ID.
 *
 *  @datatype       NHI_SDC_PORT_ID
 *  @defaultvalue   NHI_SDC_NO_PORT
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL0/NHI_PAR_SDC_PORT_ID_CHANNEL0
 *  @_adminPath     sdcPars[0].portId
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_PORT_ID_CHANNEL0                  ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  Serial data channel port ID.
 *
 *  @datatype       NHI_SDC_PORT_ID
 *  @defaultvalue   NHI_SDC_NO_PORT
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL1/NHI_PAR_SDC_PORT_ID_CHANNEL1
 *  @_adminPath     sdcPars[1].portId
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_PORT_ID_CHANNEL1                  ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Serial data channel port ID.
 *
 *  @datatype       NHI_SDC_PORT_ID
 *  @defaultvalue   NHI_SDC_NO_PORT
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL2/NHI_PAR_SDC_PORT_ID_CHANNEL2
 *  @_adminPath     sdcPars[2].portId
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_PORT_ID_CHANNEL2                  ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Serial data channel port ID.
 *
 *  @datatype       NHI_SDC_PORT_ID
 *  @defaultvalue   NHI_SDC_NO_PORT
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL3/NHI_PAR_SDC_PORT_ID_CHANNEL3
 *  @_adminPath     sdcPars[3].portId
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_PORT_ID_CHANNEL3                  ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Serial data channel slot ID.
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL0/NHI_PAR_SDC_SLOT_ID_CHANNEL0
 *  @_adminPath     sdcPars[0].slotId
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_SLOT_ID_CHANNEL0                  ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Serial data channel slot ID.
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL1/NHI_PAR_SDC_SLOT_ID_CHANNEL1
 *  @_adminPath     sdcPars[1].slotId
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_SLOT_ID_CHANNEL1                  ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|5))

/**
 *  @brief  Serial data channel slot ID.
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL2/NHI_PAR_SDC_SLOT_ID_CHANNEL2
 *  @_adminPath     sdcPars[2].slotId
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_SLOT_ID_CHANNEL2                  ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Serial data channel slot ID.
 *
 *  @datatype       NYCE_SLOT_ID
 *  @defaultvalue   NO_SLOT
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL3/NHI_PAR_SDC_SLOT_ID_CHANNEL3
 *  @_adminPath     sdcPars[3].slotId
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_SLOT_ID_CHANNEL3                  ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Serial data channel clock frequency.
 *
 *  @datatype       uint32_t
 *  @unit           [Hz]
 *  @minvalue       1000000
 *  @maxvalue       4000000
 *  @defaultvalue   0
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL0/NHI_PAR_SDC_CLOCK_FREQUENCY_CHANNEL0
 *  @_adminPath     sdcPars[0].clockFrequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_CLOCK_FREQUENCY_CHANNEL0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  Serial data channel clock frequency.
 *
 *  @datatype       uint32_t
 *  @unit           [Hz]
 *  @minvalue       1000000
 *  @maxvalue       4000000
 *  @defaultvalue   0
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL1/NHI_PAR_SDC_CLOCK_FREQUENCY_CHANNEL1
 *  @_adminPath     sdcPars[1].clockFrequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_CLOCK_FREQUENCY_CHANNEL1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  Serial data channel clock frequency.
 *
 *  @datatype       uint32_t
 *  @unit           [Hz]
 *  @minvalue       1000000
 *  @maxvalue       4000000
 *  @defaultvalue   0
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL2/NHI_PAR_SDC_CLOCK_FREQUENCY_CHANNEL2
 *  @_adminPath     sdcPars[2].clockFrequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_CLOCK_FREQUENCY_CHANNEL2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Serial data channel clock frequency.
 *
 *  @datatype       uint32_t
 *  @unit           [Hz]
 *  @minvalue       1000000
 *  @maxvalue       4000000
 *  @defaultvalue   0
 *  @xmlPath        SERIAL_DATA_CHANNELS/CHANNEL3/NHI_PAR_SDC_CLOCK_FREQUENCY_CHANNEL3
 *  @_adminPath     sdcPars[3].clockFrequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_SDC_CLOCK_FREQUENCY_CHANNEL3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_MCU_SLOT<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLSDC<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @}
 */

/**
 *  @defgroup drive_parameters Drive parameters
 *  @{
 */

/**
 *  @brief  IO event mask.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_IO_EVENT_MASK_SLOT0
 *  @_adminPath     slot[0].slotPars.io_event_mask
 *  @readOnly       FALSE
 */
#define NHI_PAR_IO_EVENT_MASK_SLOT0                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  IO event mask.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_IO_EVENT_MASK_SLOT1
 *  @_adminPath     slot[1].slotPars.io_event_mask
 *  @readOnly       FALSE
 */
#define NHI_PAR_IO_EVENT_MASK_SLOT1                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  IO event mask.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_IO_EVENT_MASK_SLOT2
 *  @_adminPath     slot[2].slotPars.io_event_mask
 *  @readOnly       FALSE
 */
#define NHI_PAR_IO_EVENT_MASK_SLOT2                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  IO event mask.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_IO_EVENT_MASK_SLOT3
 *  @_adminPath     slot[3].slotPars.io_event_mask
 *  @readOnly       FALSE
 */
#define NHI_PAR_IO_EVENT_MASK_SLOT3                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  IO event mask.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_IO_EVENT_MASK_SLOT4
 *  @_adminPath     slot[4].slotPars.io_event_mask
 *  @readOnly       FALSE
 */
#define NHI_PAR_IO_EVENT_MASK_SLOT4                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_ULONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|0))

/**
 *  @brief  Minimum value for analog input 0.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   -100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_ANIN0_MIN_SLOT0
 *  @_adminPath     slot[0].slotPars.anin0_min
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_MIN_SLOT0                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Minimum value for analog input 0.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   -100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_ANIN0_MIN_SLOT1
 *  @_adminPath     slot[1].slotPars.anin0_min
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_MIN_SLOT1                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Minimum value for analog input 0.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   -100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_ANIN0_MIN_SLOT2
 *  @_adminPath     slot[2].slotPars.anin0_min
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_MIN_SLOT2                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Minimum value for analog input 0.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   -100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_ANIN0_MIN_SLOT3
 *  @_adminPath     slot[3].slotPars.anin0_min
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_MIN_SLOT3                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Minimum value for analog input 0.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   -100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_ANIN0_MIN_SLOT4
 *  @_adminPath     slot[4].slotPars.anin0_min
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_MIN_SLOT4                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|1))

/**
 *  @brief  Maximum value for analog input 0.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_ANIN0_MAX_SLOT0
 *  @_adminPath     slot[0].slotPars.anin0_max
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_MAX_SLOT0                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Maximum value for analog input 0.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_ANIN0_MAX_SLOT1
 *  @_adminPath     slot[1].slotPars.anin0_max
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_MAX_SLOT1                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Maximum value for analog input 0.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -100
 *  @maxvalue       100
 *  @defaultvalue   100
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_ANIN0_MAX_SLOT2
 *  @_adminPath     slot[2].slotPars.anin0_max
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_MAX_SLOT2                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Maximum value for analog input 0.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -100
 *  @maxvalue       100
 *  @defaultvalue   100
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_ANIN0_MAX_SLOT3
 *  @_adminPath     slot[3].slotPars.anin0_max
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_MAX_SLOT3                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Maximum value for analog input 0.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -100
 *  @maxvalue       100
 *  @defaultvalue   100
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_ANIN0_MAX_SLOT4
 *  @_adminPath     slot[4].slotPars.anin0_max
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_MAX_SLOT4                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|2))

/**
 *  @brief  Minimum value for analog input 1.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   -100
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_ANIN1_MIN_SLOT0
 *  @_adminPath     slot[0].slotPars.anin1_min
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_MIN_SLOT0                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Minimum value for analog input 1.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -100
 *  @maxvalue       100
 *  @defaultvalue   -100
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_ANIN1_MIN_SLOT1
 *  @_adminPath     slot[1].slotPars.anin1_min
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_MIN_SLOT1                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Minimum value for analog input 1.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -100
 *  @maxvalue       100
 *  @defaultvalue   -100
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_ANIN1_MIN_SLOT2
 *  @_adminPath     slot[2].slotPars.anin1_min
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_MIN_SLOT2                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Minimum value for analog input 1.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -100
 *  @maxvalue       100
 *  @defaultvalue   -100
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_ANIN1_MIN_SLOT3
 *  @_adminPath     slot[3].slotPars.anin1_min
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_MIN_SLOT3                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Minimum value for analog input 1.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       -100
 *  @maxvalue       100
 *  @defaultvalue   -100
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_ANIN1_MIN_SLOT4
 *  @_adminPath     slot[4].slotPars.anin1_min
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_MIN_SLOT4                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|3))

/**
 *  @brief  Maximum value for analog input 1.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_ANIN1_MAX_SLOT0
 *  @_adminPath     slot[0].slotPars.anin1_max
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_MAX_SLOT0                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Maximum value for analog input 1.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_ANIN1_MAX_SLOT1
 *  @_adminPath     slot[1].slotPars.anin1_max
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_MAX_SLOT1                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Maximum value for analog input 1
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_ANIN1_MAX_SLOT2
 *  @_adminPath     slot[2].slotPars.anin1_max
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_MAX_SLOT2                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Maximum value for analog input 1.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_ANIN1_MAX_SLOT3
 *  @_adminPath     slot[3].slotPars.anin1_max
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_MAX_SLOT3                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Maximum value for analog input 1.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @defaultvalue   100
 *  @minvalue       -100
 *  @maxvalue       100
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_ANIN1_MAX_SLOT4
 *  @_adminPath     slot[4].slotPars.anin1_max
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_MAX_SLOT4                       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_EVHEVT<<NYCE_FWMODULE_SHIFT)|4))

/**
 *  @brief  Analog-digital conversion dimension for analog input 0.
 *
 *  @datatype       NHI_ADC_DIMENSION
 *  @defaultvalue   NHI_VOLTAGE
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_ANIN0_ADC_DIMENSION_SLOT0
 *  @_adminPath     slot[0].slotPars.anin0_adc_dimension
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_ADC_DIMENSION_SLOT0             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Analog-digital conversion dimension for analog input 0.
 *
 *  @datatype       NHI_ADC_DIMENSION
 *  @defaultvalue   NHI_VOLTAGE
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_ANIN0_ADC_DIMENSION_SLOT1
 *  @_adminPath     slot[1].slotPars.anin0_adc_dimension
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_ADC_DIMENSION_SLOT1             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Analog-digital conversion dimension for analog input 0.
 *
 *  @datatype       NHI_ADC_DIMENSION
 *  @defaultvalue   NHI_VOLTAGE
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_ANIN0_ADC_DIMENSION_SLOT2
 *  @_adminPath     slot[2].slotPars.anin0_adc_dimension
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_ADC_DIMENSION_SLOT2             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Analog-digital conversion dimension for analog input 0.
 *
 *  @datatype       NHI_ADC_DIMENSION
 *  @defaultvalue   NHI_VOLTAGE
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_ANIN0_ADC_DIMENSION_SLOT3
 *  @_adminPath     slot[3].slotPars.anin0_adc_dimension
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_ADC_DIMENSION_SLOT3             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Analog-digital conversion dimension for analog input 0.
 *
 *  @datatype       NHI_ADC_DIMENSION
 *  @defaultvalue   NHI_VOLTAGE
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_ANIN0_ADC_DIMENSION_SLOT4
 *  @_adminPath     slot[4].slotPars.anin0_adc_dimension
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN0_ADC_DIMENSION_SLOT4             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|6))

/**
 *  @brief  Analog-digital conversion dimension for analog input 1.
 *
 *  @datatype       NHI_ADC_DIMENSION
 *  @defaultvalue   NHI_VOLTAGE
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_ANIN1_ADC_DIMENSION_SLOT0
 *  @_adminPath     slot[0].slotPars.anin1_adc_dimension
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_ADC_DIMENSION_SLOT0             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Analog-digital conversion dimension for analog input 1.
 *
 *  @datatype       NHI_ADC_DIMENSION
 *  @defaultvalue   NHI_VOLTAGE
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_ANIN1_ADC_DIMENSION_SLOT1
 *  @_adminPath     slot[1].slotPars.anin1_adc_dimension
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_ADC_DIMENSION_SLOT1             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Analog-digital conversion dimension for analog input 1.
 *
 *  @datatype       NHI_ADC_DIMENSION
 *  @defaultvalue   NHI_VOLTAGE
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_ANIN1_ADC_DIMENSION_SLOT2
 *  @_adminPath     slot[2].slotPars.anin1_adc_dimension
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_ADC_DIMENSION_SLOT2             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Analog-digital conversion dimension for analog input 1.
 *
 *  @datatype       NHI_ADC_DIMENSION
 *  @defaultvalue   NHI_VOLTAGE
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_ANIN1_ADC_DIMENSION_SLOT3
 *  @_adminPath     slot[3].slotPars.anin1_adc_dimension
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_ADC_DIMENSION_SLOT3             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Analog-digital conversion dimension for analog input 1.
 *
 *  @datatype       NHI_ADC_DIMENSION
 *  @defaultvalue   NHI_VOLTAGE
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_ANIN1_ADC_DIMENSION_SLOT4
 *  @_adminPath     slot[4].slotPars.anin1_adc_dimension
 *  @readOnly       FALSE
 */
#define NHI_PAR_ANIN1_ADC_DIMENSION_SLOT4             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|7))

/**
 *  @brief  Digital IO active mask.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0xFFFFFFFF
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DIGITAL_IO_ACTIVE_MASK_SLOT0
 *  @_adminPath     slot[0].slotPars.digital_io_active_mask
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGITAL_IO_ACTIVE_MASK_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  Digital IO active mask.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0xFFFFFFFF
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DIGITAL_IO_ACTIVE_MASK_SLOT1
 *  @_adminPath     slot[1].slotPars.digital_io_active_mask
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGITAL_IO_ACTIVE_MASK_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  Digital IO active mask.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0xFFFFFFFF
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DIGITAL_IO_ACTIVE_MASK_SLOT2
 *  @_adminPath     slot[2].slotPars.digital_io_active_mask
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGITAL_IO_ACTIVE_MASK_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  Digital IO active mask.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0xFFFFFFFF
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DIGITAL_IO_ACTIVE_MASK_SLOT3
 *  @_adminPath     slot[3].slotPars.digital_io_active_mask
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGITAL_IO_ACTIVE_MASK_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  Digital IO active mask.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0xFFFFFFFF
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DIGITAL_IO_ACTIVE_MASK_SLOT4
 *  @_adminPath     slot[4].slotPars.digital_io_active_mask
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGITAL_IO_ACTIVE_MASK_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|8))

/**
 *  @brief  Digital input counter 0 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_IO_NR_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER0].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER0_IO_NR_SLOT0            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  Digital input counter 0 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_IO_NR_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER0].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER0_IO_NR_SLOT1            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  Digital input counter 0 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_IO_NR_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER0].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER0_IO_NR_SLOT2            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  Digital input counter 0 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_IO_NR_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER0].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER0_IO_NR_SLOT3            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  Digital input counter 0 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_IO_NR_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER0].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER0_IO_NR_SLOT4            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|9))

/**
 *  @brief  Digital input counter 1 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_IO_NR_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER1].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER1_IO_NR_SLOT0            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Digital input counter 1 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_IO_NR_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER1].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER1_IO_NR_SLOT1            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Digital input counter 1 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_IO_NR_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER1].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER1_IO_NR_SLOT2            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Digital input counter 1 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_IO_NR_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER1].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER1_IO_NR_SLOT3            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Digital input counter 1 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_IO_NR_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER1].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER1_IO_NR_SLOT4            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|10))

/**
 *  @brief  Digital input counter 2 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_IO_NR_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER2].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER2_IO_NR_SLOT0            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  Digital input counter 2 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_IO_NR_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER2].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER2_IO_NR_SLOT1            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  Digital input counter 2 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_IO_NR_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER2].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER2_IO_NR_SLOT2            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  Digital input counter 2 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_IO_NR_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER2].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER2_IO_NR_SLOT3            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  Digital input counter 2 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_IO_NR_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER2].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER2_IO_NR_SLOT4            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|11))

/**
 *  @brief  Digital input counter 3 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_IO_NR_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER3].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER3_IO_NR_SLOT0            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  Digital input counter 3 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_IO_NR_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER3].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER3_IO_NR_SLOT1            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  Digital input counter 3 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_IO_NR_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER3].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER3_IO_NR_SLOT2            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  Digital input counter 3 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_IO_NR_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER3].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER3_IO_NR_SLOT3            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  Digital input counter 3 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_IO_NR_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER3].digIONr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER3_IO_NR_SLOT4            ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|12))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_EDGE_TYPE_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER0].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER0_EDGE_TYPE_SLOT0        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_EDGE_TYPE_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER0].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER0_EDGE_TYPE_SLOT1        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_EDGE_TYPE_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER0].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER0_EDGE_TYPE_SLOT2        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_EDGE_TYPE_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER0].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER0_EDGE_TYPE_SLOT3        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_EDGE_TYPE_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER0].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER0_EDGE_TYPE_SLOT4        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|13))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_EDGE_TYPE_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER1].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER1_EDGE_TYPE_SLOT0        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_EDGE_TYPE_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER1].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER1_EDGE_TYPE_SLOT1        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_EDGE_TYPE_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER1].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER1_EDGE_TYPE_SLOT2        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_EDGE_TYPE_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER1].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER1_EDGE_TYPE_SLOT3        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_EDGE_TYPE_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER1].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER1_EDGE_TYPE_SLOT4        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|14))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_EDGE_TYPE_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER2].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER2_EDGE_TYPE_SLOT0        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_EDGE_TYPE_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER2].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER2_EDGE_TYPE_SLOT1        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_EDGE_TYPE_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER2].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER2_EDGE_TYPE_SLOT2        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_EDGE_TYPE_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER2].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER2_EDGE_TYPE_SLOT3        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_EDGE_TYPE_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER2].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER2_EDGE_TYPE_SLOT4        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|15))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_EDGE_TYPE_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER3].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER3_EDGE_TYPE_SLOT0        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_EDGE_TYPE_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER3].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER3_EDGE_TYPE_SLOT1        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_EDGE_TYPE_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER3].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER3_EDGE_TYPE_SLOT2        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_EDGE_TYPE_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER3].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER3_EDGE_TYPE_SLOT3        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  Digital input counter edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_EDGE_TYPE_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER3].edgeType
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_COUNTER3_EDGE_TYPE_SLOT4        ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|16))

/**
 *  @brief  Digital input counter 0 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_EVENT_VALUE_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER0].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER0_EV_VALUE_SLOT0         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  Digital input counter 0 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_EVENT_VALUE_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER0].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER0_EV_VALUE_SLOT1         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  Digital input counter 0 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_EVENT_VALUE_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER0].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER0_EV_VALUE_SLOT2         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  Digital input counter 0 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_EVENT_VALUE_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER0].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER0_EV_VALUE_SLOT3         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  Digital input counter 0 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER0/NHI_PAR_DIGIN_COUNTER0_EVENT_VALUE_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER0].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER0_EV_VALUE_SLOT4         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|17))

/**
 *  @brief  Digital input counter 1 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_EVENT_VALUE_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER1].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER1_EV_VALUE_SLOT0         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  Digital input counter 1 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_EVENT_VALUE_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER1].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER1_EV_VALUE_SLOT1         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  Digital input counter 1 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_EVENT_VALUE_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER1].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER1_EV_VALUE_SLOT2         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  Digital input counter 1 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_EVENT_VALUE_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER1].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER1_EV_VALUE_SLOT3         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  Digital input counter 1 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER1/NHI_PAR_DIGIN_COUNTER1_EVENT_VALUE_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER1].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER1_EV_VALUE_SLOT4         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|18))

/**
 *  @brief  Digital input counter 2 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_EVENT_VALUE_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER2].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER2_EV_VALUE_SLOT0         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  Digital input counter 2 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_EVENT_VALUE_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER2].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER2_EV_VALUE_SLOT1         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  Digital input counter 2 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_EVENT_VALUE_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER2].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER2_EV_VALUE_SLOT2         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  Digital input counter 2 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_EVENT_VALUE_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER2].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER2_EV_VALUE_SLOT3         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  Digital input counter 2 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER2/NHI_PAR_DIGIN_COUNTER2_EVENT_VALUE_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER2].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER2_EV_VALUE_SLOT4         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|19))

/**
 *  @brief  Digital input counter 3 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_EVENT_VALUE_SLOT0
 *  @_adminPath     slot[0].counterPars[NHI_DIGIN_COUNTER3].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER3_EV_VALUE_SLOT0         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @brief  Digital input counter 3 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_EVENT_VALUE_SLOT1
 *  @_adminPath     slot[1].counterPars[NHI_DIGIN_COUNTER3].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER3_EV_VALUE_SLOT1         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @brief  Digital input counter 3 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_EVENT_VALUE_SLOT2
 *  @_adminPath     slot[2].counterPars[NHI_DIGIN_COUNTER3].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER3_EV_VALUE_SLOT2         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @brief  Digital input counter 3 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_EVENT_VALUE_SLOT3
 *  @_adminPath     slot[3].counterPars[NHI_DIGIN_COUNTER3].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER3_EV_VALUE_SLOT3         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @brief  Digital input counter 3 value.
 *
 *  @datatype       int32_t
 *  @unit           [-]
 *  @defaultvalue   -1
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_COUNTERS/COUNTER3/NHI_PAR_DIGIN_COUNTER3_EVENT_VALUE_SLOT4
 *  @_adminPath     slot[4].counterPars[NHI_DIGIN_COUNTER3].eventValue
 *  @readOnly       FALSE
 */
#define NHI_PAR_DIGIN_COUNTER3_EV_VALUE_SLOT4         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|20))

/**
 *  @brief  Digital input latch 0 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_LATCHES/LATCH_0/NHI_PAR_DIGIN_LATCH0_IO_NR_SLOT0
 *  @_adminPath     slot[0].latchPars[NHI_LATCH_0].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH0_IO_NR_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @brief  Digital input latch 0 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_LATCHES/LATCH_0/NHI_PAR_DIGIN_LATCH0_IO_NR_SLOT1
 *  @_adminPath     slot[1].latchPars[NHI_LATCH_0].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH0_IO_NR_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @brief  Digital input latch 0 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_LATCHES/LATCH_0/NHI_PAR_DIGIN_LATCH0_IO_NR_SLOT2
 *  @_adminPath     slot[2].latchPars[NHI_LATCH_0].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH0_IO_NR_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @brief  Digital input latch 0 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_LATCHES/LATCH_0/NHI_PAR_DIGIN_LATCH0_IO_NR_SLOT3
 *  @_adminPath     slot[3].latchPars[NHI_LATCH_0].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH0_IO_NR_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @brief  Digital input latch 0 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_LATCHES/LATCH_0/NHI_PAR_DIGIN_LATCH0_IO_NR_SLOT4
 *  @_adminPath     slot[4].latchPars[NHI_LATCH_0].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH0_IO_NR_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|21))

/**
 *  @brief  Digital input latch 0 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_LATCHES/LATCH_0/NHI_PAR_DIGIN_LATCH0_EDGE_TYPE_SLOT0
 *  @_adminPath     slot[0].latchPars[NHI_LATCH_0].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH0_EDGE_TYPE_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  Digital input latch 0 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_LATCHES/LATCH_0/NHI_PAR_DIGIN_LATCH0_EDGE_TYPE_SLOT1
 *  @_adminPath     slot[1].latchPars[NHI_LATCH_0].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH0_EDGE_TYPE_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  Digital input latch 0 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_LATCHES/LATCH_0/NHI_PAR_DIGIN_LATCH0_EDGE_TYPE_SLOT2
 *  @_adminPath     slot[2].latchPars[NHI_LATCH_0].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH0_EDGE_TYPE_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  Digital input latch 0 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_LATCHES/LATCH_0/NHI_PAR_DIGIN_LATCH0_EDGE_TYPE_SLOT3
 *  @_adminPath     slot[3].latchPars[NHI_LATCH_0].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH0_EDGE_TYPE_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  Digital input latch 0 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_LATCHES/LATCH_0/NHI_PAR_DIGIN_LATCH0_EDGE_TYPE_SLOT4
 *  @_adminPath     slot[4].latchPars[NHI_LATCH_0].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH0_EDGE_TYPE_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|22))

/**
 *  @brief  Digital input latch 1 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_LATCHES/LATCH_1/NHI_PAR_DIGIN_LATCH1_IO_NR_SLOT0
 *  @_adminPath     slot[0].latchPars[NHI_LATCH_1].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH1_IO_NR_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  Digital input latch 1 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_LATCHES/LATCH_1/NHI_PAR_DIGIN_LATCH1_IO_NR_SLOT1
 *  @_adminPath     slot[1].latchPars[NHI_LATCH_1].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH1_IO_NR_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  Digital input latch 1 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_LATCHES/LATCH_1/NHI_PAR_DIGIN_LATCH1_IO_NR_SLOT2
 *  @_adminPath     slot[2].latchPars[NHI_LATCH_1].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH1_IO_NR_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  Digital input latch 1 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_LATCHES/LATCH_1/NHI_PAR_DIGIN_LATCH1_IO_NR_SLOT3
 *  @_adminPath     slot[3].latchPars[NHI_LATCH_1].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH1_IO_NR_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  Digital input latch 1 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_LATCHES/LATCH_1/NHI_PAR_DIGIN_LATCH1_IO_NR_SLOT4
 *  @_adminPath     slot[4].latchPars[NHI_LATCH_1].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH1_IO_NR_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|23))

/**
 *  @brief  Digital input latch 1 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_LATCHES/LATCH_1/NHI_PAR_DIGIN_LATCH1_EDGE_TYPE_SLOT0
 *  @_adminPath     slot[0].latchPars[NHI_LATCH_1].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH1_EDGE_TYPE_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  Digital input latch 1 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_LATCHES/LATCH_1/NHI_PAR_DIGIN_LATCH1_EDGE_TYPE_SLOT1
 *  @_adminPath     slot[1].latchPars[NHI_LATCH_1].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH1_EDGE_TYPE_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  Digital input latch 1 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_LATCHES/LATCH_1/NHI_PAR_DIGIN_LATCH1_EDGE_TYPE_SLOT2
 *  @_adminPath     slot[2].latchPars[NHI_LATCH_1].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH1_EDGE_TYPE_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  Digital input latch 1 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_LATCHES/LATCH_1/NHI_PAR_DIGIN_LATCH1_EDGE_TYPE_SLOT3
 *  @_adminPath     slot[3].latchPars[NHI_LATCH_1].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH1_EDGE_TYPE_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  Digital input latch 1 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_LATCHES/LATCH_1/NHI_PAR_DIGIN_LATCH1_EDGE_TYPE_SLOT4
 *  @_adminPath     slot[4].latchPars[NHI_LATCH_1].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH1_EDGE_TYPE_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|24))

/**
 *  @brief  Digital input latch 2 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_LATCHES/LATCH_2/NHI_PAR_DIGIN_LATCH2_IO_NR_SLOT0
 *  @_adminPath     slot[0].latchPars[NHI_LATCH_2].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH2_IO_NR_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  Digital input latch 2 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_LATCHES/LATCH_2/NHI_PAR_DIGIN_LATCH2_IO_NR_SLOT1
 *  @_adminPath     slot[1].latchPars[NHI_LATCH_2].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH2_IO_NR_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  Digital input latch 2 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_LATCHES/LATCH_2/NHI_PAR_DIGIN_LATCH2_IO_NR_SLOT2
 *  @_adminPath     slot[2].latchPars[NHI_LATCH_2].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH2_IO_NR_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  Digital input latch 2 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_LATCHES/LATCH_2/NHI_PAR_DIGIN_LATCH2_IO_NR_SLOT3
 *  @_adminPath     slot[3].latchPars[NHI_LATCH_2].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH2_IO_NR_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  Digital input latch 2 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_LATCHES/LATCH_2/NHI_PAR_DIGIN_LATCH2_IO_NR_SLOT4
 *  @_adminPath     slot[4].latchPars[NHI_LATCH_2].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH2_IO_NR_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|25))

/**
 *  @brief  Digital input latch 2 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_LATCHES/LATCH_2/NHI_PAR_DIGIN_LATCH2_EDGE_TYPE_SLOT0
 *  @_adminPath     slot[0].latchPars[NHI_LATCH_2].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH2_EDGE_TYPE_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  Digital input latch 2 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_LATCHES/LATCH_2/NHI_PAR_DIGIN_LATCH2_EDGE_TYPE_SLOT1
 *  @_adminPath     slot[1].latchPars[NHI_LATCH_2].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH2_EDGE_TYPE_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  Digital input latch 2 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_LATCHES/LATCH_2/NHI_PAR_DIGIN_LATCH2_EDGE_TYPE_SLOT2
 *  @_adminPath     slot[2].latchPars[NHI_LATCH_2].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH2_EDGE_TYPE_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  Digital input latch 2 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_LATCHES/LATCH_2/NHI_PAR_DIGIN_LATCH2_EDGE_TYPE_SLOT3
 *  @_adminPath     slot[3].latchPars[NHI_LATCH_2].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH2_EDGE_TYPE_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  Digital input latch 2 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_LATCHES/LATCH_2/NHI_PAR_DIGIN_LATCH2_EDGE_TYPE_SLOT4
 *  @_adminPath     slot[4].latchPars[NHI_LATCH_2].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH2_EDGE_TYPE_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|26))

/**
 *  @brief  Digital input latch 3 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_LATCHES/LATCH_3/NHI_PAR_DIGIN_LATCH3_IO_NR_SLOT0
 *  @_adminPath     slot[0].latchPars[NHI_LATCH_3].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH3_IO_NR_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  Digital input latch 3 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_LATCHES/LATCH_3/NHI_PAR_DIGIN_LATCH3_IO_NR_SLOT1
 *  @_adminPath     slot[1].latchPars[NHI_LATCH_3].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH3_IO_NR_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  Digital input latch 3 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_LATCHES/LATCH_3/NHI_PAR_DIGIN_LATCH3_IO_NR_SLOT2
 *  @_adminPath     slot[2].latchPars[NHI_LATCH_3].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH3_IO_NR_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  Digital input latch 3 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_LATCHES/LATCH_3/NHI_PAR_DIGIN_LATCH3_IO_NR_SLOT3
 *  @_adminPath     slot[3].latchPars[NHI_LATCH_3].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH3_IO_NR_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  Digital input latch 3 IO number.
 *
 *  @datatype       NYCE_DIG_IO_NR
 *  @defaultvalue   NYCE_DIGIN0
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_LATCHES/LATCH_3/NHI_PAR_DIGIN_LATCH3_IO_NR_SLOT4
 *  @_adminPath     slot[4].latchPars[NHI_LATCH_3].dig_io_nr
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH3_IO_NR_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|27))

/**
 *  @brief  Digital input latch 3 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT0/DIG_INPUT_LATCHES/LATCH_3/NHI_PAR_DIGIN_LATCH3_EDGE_TYPE_SLOT0
 *  @_adminPath     slot[0].latchPars[NHI_LATCH_3].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH3_EDGE_TYPE_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  Digital input latch 3 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT1/DIG_INPUT_LATCHES/LATCH_3/NHI_PAR_DIGIN_LATCH3_EDGE_TYPE_SLOT1
 *  @_adminPath     slot[1].latchPars[NHI_LATCH_3].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH3_EDGE_TYPE_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  Digital input latch 3 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT2/DIG_INPUT_LATCHES/LATCH_3/NHI_PAR_DIGIN_LATCH3_EDGE_TYPE_SLOT2
 *  @_adminPath     slot[2].latchPars[NHI_LATCH_3].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH3_EDGE_TYPE_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  Digital input latch 3 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT3/DIG_INPUT_LATCHES/LATCH_3/NHI_PAR_DIGIN_LATCH3_EDGE_TYPE_SLOT3
 *  @_adminPath     slot[3].latchPars[NHI_LATCH_3].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH3_EDGE_TYPE_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  Digital input latch 3 edge type.
 *
 *  @datatype       NYCE_EDGE_TYPE
 *  @defaultvalue   NYCE_EDGE_NONE
 *  @minvalue       NYCE_EDGE_NONE
 *  @maxvalue       NYCE_EDGE_ANY
 *  @xmlPath        SLOTS/SLOT4/DIG_INPUT_LATCHES/LATCH_3/NHI_PAR_DIGIN_LATCH3_EDGE_TYPE_SLOT4
 *  @_adminPath     slot[4].latchPars[NHI_LATCH_3].edge_type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGIN_LATCH3_EDGE_TYPE_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|28))

/**
 *  @brief  Digital output 0 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_TYPE_SLOT0
 *  @_adminPath     slot[0].digoutPars[0].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_TYPE_SLOT0                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  Digital output 0 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_TYPE_SLOT1
 *  @_adminPath     slot[1].digoutPars[0].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_TYPE_SLOT1                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  Digital output 0 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_TYPE_SLOT2
 *  @_adminPath     slot[2].digoutPars[0].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_TYPE_SLOT2                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  Digital output 0 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_TYPE_SLOT3
 *  @_adminPath     slot[3].digoutPars[0].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_TYPE_SLOT3                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  Digital output 0 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_TYPE_SLOT4
 *  @_adminPath     slot[4].digoutPars[0].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_TYPE_SLOT4                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|29))

/**
 *  @brief  Digital output 0 pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_PULSE_TIME_SLOT0
 *  @_adminPath     slot[0].digoutPars[0].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_PULSE_TIME_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  Digital output 0 pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_PULSE_TIME_SLOT1
 *  @_adminPath     slot[1].digoutPars[0].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_PULSE_TIME_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  Digital output 0 pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_PULSE_TIME_SLOT2
 *  @_adminPath     slot[2].digoutPars[0].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_PULSE_TIME_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  Digital output 0 pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_PULSE_TIME_SLOT3
 *  @_adminPath     slot[3].digoutPars[0].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_PULSE_TIME_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  Digital output 0 pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_PULSE_TIME_SLOT4
 *  @_adminPath     slot[4].digoutPars[0].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_PULSE_TIME_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|30))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_ON_DELAY_SLOT0
 *  @_adminPath     slot[0].digoutPars[0].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_ON_DELAY_SLOT0                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_ON_DELAY_SLOT1
 *  @_adminPath     slot[1].digoutPars[0].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_ON_DELAY_SLOT1                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_ON_DELAY_SLOT2
 *  @_adminPath     slot[2].digoutPars[0].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_ON_DELAY_SLOT2                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_ON_DELAY_SLOT3
 *  @_adminPath     slot[3].digoutPars[0].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_ON_DELAY_SLOT3                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_ON_DELAY_SLOT4
 *  @_adminPath     slot[4].digoutPars[0].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_ON_DELAY_SLOT4                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|31))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_FREQUENCY_SLOT0
 *  @_adminPath     slot[0].digoutPars[0].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_FREQUENCY_SLOT0               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_FREQUENCY_SLOT1
 *  @_adminPath     slot[1].digoutPars[0].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_FREQUENCY_SLOT1               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_FREQUENCY_SLOT2
 *  @_adminPath     slot[2].digoutPars[0].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_FREQUENCY_SLOT2               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_FREQUENCY_SLOT3
 *  @_adminPath     slot[3].digoutPars[0].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_FREQUENCY_SLOT3               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_FREQUENCY_SLOT4
 *  @_adminPath     slot[4].digoutPars[0].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_FREQUENCY_SLOT4               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|32))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_DUTY_CYCLE_SLOT0
 *  @_adminPath     slot[0].digoutPars[0].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_DUTY_CYCLE_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_DUTY_CYCLE_SLOT1
 *  @_adminPath     slot[1].digoutPars[0].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_DUTY_CYCLE_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_DUTY_CYCLE_SLOT2
 *  @_adminPath     slot[2].digoutPars[0].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_DUTY_CYCLE_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_DUTY_CYCLE_SLOT3
 *  @_adminPath     slot[3].digoutPars[0].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_DUTY_CYCLE_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT0/NHI_PAR_DIGOUT0_DUTY_CYCLE_SLOT4
 *  @_adminPath     slot[4].digoutPars[0].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT0_DUTY_CYCLE_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|33))

/**
 *  @brief  Digital output 1 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_TYPE_SLOT0
 *  @_adminPath     slot[0].digoutPars[1].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_TYPE_SLOT0                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  Digital output 1 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_TYPE_SLOT1
 *  @_adminPath     slot[1].digoutPars[1].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_TYPE_SLOT1                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  Digital output 1 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_TYPE_SLOT2
 *  @_adminPath     slot[2].digoutPars[1].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_TYPE_SLOT2                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  Digital output 1 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_TYPE_SLOT3
 *  @_adminPath     slot[3].digoutPars[1].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_TYPE_SLOT3                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  Digital output 1 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_TYPE_SLOT4
 *  @_adminPath     slot[4].digoutPars[1].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_TYPE_SLOT4                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|34))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_PULSE_TIME_SLOT0
 *  @_adminPath     slot[0].digoutPars[1].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_PULSE_TIME_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_PULSE_TIME_SLOT1
 *  @_adminPath     slot[1].digoutPars[1].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_PULSE_TIME_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_PULSE_TIME_SLOT2
 *  @_adminPath     slot[2].digoutPars[1].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_PULSE_TIME_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_PULSE_TIME_SLOT3
 *  @_adminPath     slot[3].digoutPars[1].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_PULSE_TIME_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_PULSE_TIME_SLOT4
 *  @_adminPath     slot[4].digoutPars[1].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_PULSE_TIME_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|35))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_ON_DELAY_SLOT0
 *  @_adminPath     slot[0].digoutPars[1].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_ON_DELAY_SLOT0                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_ON_DELAY_SLOT1
 *  @_adminPath     slot[1].digoutPars[1].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_ON_DELAY_SLOT1                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_ON_DELAY_SLOT2
 *  @_adminPath     slot[2].digoutPars[1].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_ON_DELAY_SLOT2                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_ON_DELAY_SLOT3
 *  @_adminPath     slot[3].digoutPars[1].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_ON_DELAY_SLOT3                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_ON_DELAY_SLOT4
 *  @_adminPath     slot[4].digoutPars[1].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_ON_DELAY_SLOT4                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|36))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_FREQUENCY_SLOT0
 *  @_adminPath     slot[0].digoutPars[1].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_FREQUENCY_SLOT0               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|37))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_FREQUENCY_SLOT1
 *  @_adminPath     slot[1].digoutPars[1].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_FREQUENCY_SLOT1               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|37))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_FREQUENCY_SLOT2
 *  @_adminPath     slot[2].digoutPars[1].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_FREQUENCY_SLOT2               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|37))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_FREQUENCY_SLOT3
 *  @_adminPath     slot[3].digoutPars[1].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_FREQUENCY_SLOT3               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|37))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_FREQUENCY_SLOT4
 *  @_adminPath     slot[4].digoutPars[1].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_FREQUENCY_SLOT4               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|37))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_DUTY_CYCLE_SLOT0
 *  @_adminPath     slot[0].digoutPars[1].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_DUTY_CYCLE_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|38))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_DUTY_CYCLE_SLOT1
 *  @_adminPath     slot[1].digoutPars[1].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_DUTY_CYCLE_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|38))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_DUTY_CYCLE_SLOT2
 *  @_adminPath     slot[2].digoutPars[1].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_DUTY_CYCLE_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|38))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_DUTY_CYCLE_SLOT3
 *  @_adminPath     slot[3].digoutPars[1].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_DUTY_CYCLE_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|38))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT1/NHI_PAR_DIGOUT1_DUTY_CYCLE_SLOT4
 *  @_adminPath     slot[4].digoutPars[1].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT1_DUTY_CYCLE_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|38))

/**
 *  @brief  Digital output 2 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_TYPE_SLOT0
 *  @_adminPath     slot[0].digoutPars[2].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_TYPE_SLOT0                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|39))

/**
 *  @brief  Digital output 2 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_TYPE_SLOT1
 *  @_adminPath     slot[1].digoutPars[2].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_TYPE_SLOT1                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|39))

/**
 *  @brief  Digital output 2 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_TYPE_SLOT2
 *  @_adminPath     slot[2].digoutPars[2].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_TYPE_SLOT2                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|39))

/**
 *  @brief  Digital output 2 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_TYPE_SLOT3
 *  @_adminPath     slot[3].digoutPars[2].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_TYPE_SLOT3                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|39))

/**
 *  @brief  Digital output 2 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_TYPE_SLOT4
 *  @_adminPath     slot[4].digoutPars[2].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_TYPE_SLOT4                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|39))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_PULSE_TIME_SLOT0
 *  @_adminPath     slot[0].digoutPars[2].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_PULSE_TIME_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|40))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_PULSE_TIME_SLOT1
 *  @_adminPath     slot[1].digoutPars[2].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_PULSE_TIME_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|40))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_PULSE_TIME_SLOT2
 *  @_adminPath     slot[2].digoutPars[2].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_PULSE_TIME_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|40))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_PULSE_TIME_SLOT3
 *  @_adminPath     slot[3].digoutPars[2].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_PULSE_TIME_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|40))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_PULSE_TIME_SLOT4
 *  @_adminPath     slot[4].digoutPars[2].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_PULSE_TIME_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|40))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_ON_DELAY_SLOT0
 *  @_adminPath     slot[0].digoutPars[2].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_ON_DELAY_SLOT0                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|41))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_ON_DELAY_SLOT1
 *  @_adminPath     slot[1].digoutPars[2].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_ON_DELAY_SLOT1                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|41))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_ON_DELAY_SLOT2
 *  @_adminPath     slot[2].digoutPars[2].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_ON_DELAY_SLOT2                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|41))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_ON_DELAY_SLOT3
 *  @_adminPath     slot[3].digoutPars[2].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_ON_DELAY_SLOT3                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|41))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_ON_DELAY_SLOT4
 *  @_adminPath     slot[4].digoutPars[2].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_ON_DELAY_SLOT4                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|41))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_FREQUENCY_SLOT0
 *  @_adminPath     slot[0].digoutPars[2].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_FREQUENCY_SLOT0               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|42))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_FREQUENCY_SLOT1
 *  @_adminPath     slot[1].digoutPars[2].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_FREQUENCY_SLOT1               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|42))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_FREQUENCY_SLOT2
 *  @_adminPath     slot[2].digoutPars[2].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_FREQUENCY_SLOT2               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|42))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_FREQUENCY_SLOT3
 *  @_adminPath     slot[3].digoutPars[2].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_FREQUENCY_SLOT3               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|42))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_FREQUENCY_SLOT4
 *  @_adminPath     slot[4].digoutPars[2].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_FREQUENCY_SLOT4               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|42))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_DUTY_CYCLE_SLOT0
 *  @_adminPath     slot[0].digoutPars[2].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_DUTY_CYCLE_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|43))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_DUTY_CYCLE_SLOT1
 *  @_adminPath     slot[1].digoutPars[2].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_DUTY_CYCLE_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|43))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_DUTY_CYCLE_SLOT2
 *  @_adminPath     slot[2].digoutPars[2].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_DUTY_CYCLE_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|43))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_DUTY_CYCLE_SLOT3
 *  @_adminPath     slot[3].digoutPars[2].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_DUTY_CYCLE_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|43))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT2/NHI_PAR_DIGOUT2_DUTY_CYCLE_SLOT4
 *  @_adminPath     slot[4].digoutPars[2].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT2_DUTY_CYCLE_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|43))

/**
 *  @brief  Digital output 3 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_TYPE_SLOT0
 *  @_adminPath     slot[0].digoutPars[3].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_TYPE_SLOT0                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|44))

/**
 *  @brief  Digital output 3 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_TYPE_SLOT1
 *  @_adminPath     slot[1].digoutPars[3].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_TYPE_SLOT1                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|44))

/**
 *  @brief  Digital output 3 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_TYPE_SLOT2
 *  @_adminPath     slot[2].digoutPars[3].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_TYPE_SLOT2                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|44))

/**
 *  @brief  Digital output 3 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_TYPE_SLOT3
 *  @_adminPath     slot[3].digoutPars[3].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_TYPE_SLOT3                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|44))

/**
 *  @brief  Digital output 3 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_TYPE_SLOT4
 *  @_adminPath     slot[4].digoutPars[3].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_TYPE_SLOT4                    ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|44))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_PULSE_TIME_SLOT0
 *  @_adminPath     slot[0].digoutPars[3].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_PULSE_TIME_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|45))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_PULSE_TIME_SLOT1
 *  @_adminPath     slot[1].digoutPars[3].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_PULSE_TIME_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|45))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_PULSE_TIME_SLOT2
 *  @_adminPath     slot[2].digoutPars[3].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_PULSE_TIME_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|45))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_PULSE_TIME_SLOT3
 *  @_adminPath     slot[3].digoutPars[3].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_PULSE_TIME_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|45))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_PULSE_TIME_SLOT4
 *  @_adminPath     slot[4].digoutPars[3].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_PULSE_TIME_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|45))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_ON_DELAY_SLOT0
 *  @_adminPath     slot[0].digoutPars[3].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_ON_DELAY_SLOT0                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|46))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_ON_DELAY_SLOT1
 *  @_adminPath     slot[1].digoutPars[3].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_ON_DELAY_SLOT1                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|46))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_ON_DELAY_SLOT2
 *  @_adminPath     slot[2].digoutPars[3].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_ON_DELAY_SLOT2                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|46))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_ON_DELAY_SLOT3
 *  @_adminPath     slot[3].digoutPars[3].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_ON_DELAY_SLOT3                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|46))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_ON_DELAY_SLOT4
 *  @_adminPath     slot[4].digoutPars[3].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_ON_DELAY_SLOT4                ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|46))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_FREQUENCY_SLOT0
 *  @_adminPath     slot[0].digoutPars[3].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_FREQUENCY_SLOT0               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|47))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_FREQUENCY_SLOT1
 *  @_adminPath     slot[1].digoutPars[3].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_FREQUENCY_SLOT1               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|47))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_FREQUENCY_SLOT2
 *  @_adminPath     slot[2].digoutPars[3].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_FREQUENCY_SLOT2               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|47))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_FREQUENCY_SLOT3
 *  @_adminPath     slot[3].digoutPars[3].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_FREQUENCY_SLOT3               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|47))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_FREQUENCY_SLOT4
 *  @_adminPath     slot[4].digoutPars[3].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_FREQUENCY_SLOT4               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|47))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_DUTY_CYCLE_SLOT0
 *  @_adminPath     slot[0].digoutPars[3].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_DUTY_CYCLE_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|48))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_DUTY_CYCLE_SLOT1
 *  @_adminPath     slot[1].digoutPars[3].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_DUTY_CYCLE_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|48))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_DUTY_CYCLE_SLOT2
 *  @_adminPath     slot[2].digoutPars[3].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_DUTY_CYCLE_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|48))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_DUTY_CYCLE_SLOT3
 *  @_adminPath     slot[3].digoutPars[3].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_DUTY_CYCLE_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|48))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/DIGOUT3/NHI_PAR_DIGOUT3_DUTY_CYCLE_SLOT4
 *  @_adminPath     slot[4].digoutPars[3].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_DIGOUT3_DUTY_CYCLE_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|48))

/**
 *  @brief  Fast digital output 0 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_TYPE_SLOT0
 *  @_adminPath     slot[0].digoutPars[4].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_TYPE_SLOT0                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|49))

/**
 *  @brief  Fast digital output 0 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_TYPE_SLOT1
 *  @_adminPath     slot[1].digoutPars[4].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_TYPE_SLOT1                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|49))

/**
 *  @brief  Fast digital output 0 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_TYPE_SLOT2
 *  @_adminPath     slot[2].digoutPars[4].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_TYPE_SLOT2                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|49))

/**
 *  @brief  Fast digital output 0 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_TYPE_SLOT3
 *  @_adminPath     slot[3].digoutPars[4].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_TYPE_SLOT3                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|49))

/**
 *  @brief  Fast digital output 0 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_TYPE_SLOT4
 *  @_adminPath     slot[4].digoutPars[4].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_TYPE_SLOT4                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|49))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0000001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_PULSE_TIME_SLOT0
 *  @_adminPath     slot[0].digoutPars[4].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_PULSE_TIME_SLOT0             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|50))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0000001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_PULSE_TIME_SLOT1
 *  @_adminPath     slot[1].digoutPars[4].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_PULSE_TIME_SLOT1             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|50))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0000001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_PULSE_TIME_SLOT2
 *  @_adminPath     slot[2].digoutPars[4].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_PULSE_TIME_SLOT2             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|50))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0000001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_PULSE_TIME_SLOT3
 *  @_adminPath     slot[3].digoutPars[4].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_PULSE_TIME_SLOT3             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|50))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0000001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_PULSE_TIME_SLOT4
 *  @_adminPath     slot[4].digoutPars[4].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_PULSE_TIME_SLOT4             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|50))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_ON_DELAY_SLOT0
 *  @_adminPath     slot[0].digoutPars[4].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_ON_DELAY_SLOT0               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|51))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_ON_DELAY_SLOT1
 *  @_adminPath     slot[1].digoutPars[4].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_ON_DELAY_SLOT1               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|51))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_ON_DELAY_SLOT2
 *  @_adminPath     slot[2].digoutPars[4].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_ON_DELAY_SLOT2               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|51))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_ON_DELAY_SLOT3
 *  @_adminPath     slot[3].digoutPars[4].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_ON_DELAY_SLOT3               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|51))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_ON_DELAY_SLOT4
 *  @_adminPath     slot[4].digoutPars[4].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_ON_DELAY_SLOT4               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|51))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_FREQUENCY_SLOT0
 *  @_adminPath     slot[0].digoutPars[4].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_FREQUENCY_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|52))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_FREQUENCY_SLOT1
 *  @_adminPath     slot[1].digoutPars[4].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_FREQUENCY_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|52))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_FREQUENCY_SLOT2
 *  @_adminPath     slot[2].digoutPars[4].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_FREQUENCY_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|52))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_FREQUENCY_SLOT3
 *  @_adminPath     slot[3].digoutPars[4].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_FREQUENCY_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|52))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_FREQUENCY_SLOT4
 *  @_adminPath     slot[4].digoutPars[4].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_FREQUENCY_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|52))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_DUTY_CYCLE_SLOT0
 *  @_adminPath     slot[0].digoutPars[4].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_DUTY_CYCLE_SLOT0             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|53))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_DUTY_CYCLE_SLOT1
 *  @_adminPath     slot[1].digoutPars[4].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_DUTY_CYCLE_SLOT1             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|53))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_DUTY_CYCLE_SLOT2
 *  @_adminPath     slot[2].digoutPars[4].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_DUTY_CYCLE_SLOT2             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|53))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_DUTY_CYCLE_SLOT3
 *  @_adminPath     slot[3].digoutPars[4].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_DUTY_CYCLE_SLOT3             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|53))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/FASTOUT0/NHI_PAR_FASTOUT0_DUTY_CYCLE_SLOT4
 *  @_adminPath     slot[4].digoutPars[4].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT0_DUTY_CYCLE_SLOT4             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|53))

/**
 *  @brief  Fast digital output 1 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_TYPE_SLOT0
 *  @_adminPath     slot[0].digoutPars[5].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_TYPE_SLOT0                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|54))

/**
 *  @brief  Fast digital output 1 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_TYPE_SLOT1
 *  @_adminPath     slot[1].digoutPars[5].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_TYPE_SLOT1                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|54))

/**
 *  @brief  Fast digital output 1 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_TYPE_SLOT2
 *  @_adminPath     slot[2].digoutPars[5].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_TYPE_SLOT2                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|54))

/**
 *  @brief  Fast digital output 1 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_TYPE_SLOT3
 *  @_adminPath     slot[3].digoutPars[5].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_TYPE_SLOT3                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|54))

/**
 *  @brief  Fast digital output 1 type.
 *
 *  @datatype       NHI_DIGOUT_TYPE
 *  @defaultvalue   NHI_DIGOUT_STATE
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_TYPE_SLOT4
 *  @_adminPath     slot[4].digoutPars[5].type
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_TYPE_SLOT4                   ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_LONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|54))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_PULSE_TIME_SLOT0
 *  @_adminPath     slot[0].digoutPars[5].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_PULSE_TIME_SLOT0             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|55))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_PULSE_TIME_SLOT1
 *  @_adminPath     slot[1].digoutPars[5].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_PULSE_TIME_SLOT1             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|55))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_PULSE_TIME_SLOT2
 *  @_adminPath     slot[2].digoutPars[5].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_PULSE_TIME_SLOT2             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|55))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_PULSE_TIME_SLOT3
 *  @_adminPath     slot[3].digoutPars[5].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_PULSE_TIME_SLOT3             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|55))

/**
 *  @brief  Digital output pulse time.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.00001
 *  @maxvalue       10.0
 *  @defaultvalue   0.00001
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_PULSE_TIME_SLOT4
 *  @_adminPath     slot[4].digoutPars[5].pars.pulseTime
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_PULSE_TIME_SLOT4             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|55))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_ON_DELAY_SLOT0
 *  @_adminPath     slot[0].digoutPars[5].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_ON_DELAY_SLOT0               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|56))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_ON_DELAY_SLOT1
 *  @_adminPath     slot[1].digoutPars[5].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_ON_DELAY_SLOT1               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|56))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_ON_DELAY_SLOT2
 *  @_adminPath     slot[2].digoutPars[5].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_ON_DELAY_SLOT2               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|56))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_ON_DELAY_SLOT3
 *  @_adminPath     slot[3].digoutPars[5].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_ON_DELAY_SLOT3               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|56))

/**
 *  @brief  Delay before PWM starts.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       10.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_ON_DELAY_SLOT4
 *  @_adminPath     slot[4].digoutPars[5].pars.pwmPars.onDelay
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_ON_DELAY_SLOT4               ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|56))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_FREQUENCY_SLOT0
 *  @_adminPath     slot[0].digoutPars[5].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_FREQUENCY_SLOT0              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|57))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_FREQUENCY_SLOT1
 *  @_adminPath     slot[1].digoutPars[5].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_FREQUENCY_SLOT1              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|57))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_FREQUENCY_SLOT2
 *  @_adminPath     slot[2].digoutPars[5].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_FREQUENCY_SLOT2              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|57))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_FREQUENCY_SLOT3
 *  @_adminPath     slot[3].digoutPars[5].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_FREQUENCY_SLOT3              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|57))

/**
 *  @brief  PWM frequency.
 *
 *  @datatype       double
 *  @unit           [Hz]
 *  @minvalue       0.1
 *  @maxvalue       10000.0
 *  @defaultvalue   0.1
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_FREQUENCY_SLOT4
 *  @_adminPath     slot[4].digoutPars[5].pars.pwmPars.frequency
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_FREQUENCY_SLOT4              ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|57))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT0/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_DUTY_CYCLE_SLOT0
 *  @_adminPath     slot[0].digoutPars[5].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_DUTY_CYCLE_SLOT0             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|58))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT1/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_DUTY_CYCLE_SLOT1
 *  @_adminPath     slot[1].digoutPars[5].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_DUTY_CYCLE_SLOT1             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|58))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT2/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_DUTY_CYCLE_SLOT2
 *  @_adminPath     slot[2].digoutPars[5].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_DUTY_CYCLE_SLOT2             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|58))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT3/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_DUTY_CYCLE_SLOT3
 *  @_adminPath     slot[3].digoutPars[5].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_DUTY_CYCLE_SLOT3             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|58))

/**
 *  @brief  PWM duty cycle.
 *
 *  @datatype       double
 *  @unit           [%]
 *  @minvalue       0.0
 *  @maxvalue       100.0
 *  @defaultvalue   50.0
 *  @xmlPath        SLOTS/SLOT4/DIG_OUTPUT_CONFIG/FASTOUT1/NHI_PAR_FASTOUT1_DUTY_CYCLE_SLOT4
 *  @_adminPath     slot[4].digoutPars[5].pars.pwmPars.dutyCycle
 *  @readOnly       TRUE
 */
#define NHI_PAR_FASTOUT1_DUTY_CYCLE_SLOT4             ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT<<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|58))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN0_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN0]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN0_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|59))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN0_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN0]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN0_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|59))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN0_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN0]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN0_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|59))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN0_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN0]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN0_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|59))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN0_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN0]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN0_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|59))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN1_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN1]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN1_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|60))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN1_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN1]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN1_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|60))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN1_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN1]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN1_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|60))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN1_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN1]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN1_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|60))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN1_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN1]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN1_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|60))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN2_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN2]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN2_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|61))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN2_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN2]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN2_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|61))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN2_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN2]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN2_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|61))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN2_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN2]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN2_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|61))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN2_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN2]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN2_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|61))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN3_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN3]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN3_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|62))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN3_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN3]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN3_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|62))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN3_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN3]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN3_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|62))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN3_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN3]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN3_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|62))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN3_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN3]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN3_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|62))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN4_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN4]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN4_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|63))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN4_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN4]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN4_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|63))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN4_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN4]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN4_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|63))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN4_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN4]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN4_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|63))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN4_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN4]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN4_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|63))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN5_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN5]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN5_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|64))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN5_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN5]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN5_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|64))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN5_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN5]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN5_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|64))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN5_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN5]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN5_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|64))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN5_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN5]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN5_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|64))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN6_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN6]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN6_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|65))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN6_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN6]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN6_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|65))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN6_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN6]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN6_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|65))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN6_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN6]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN6_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|65))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN6_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN6]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN6_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|65))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN7_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN7]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN7_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|66))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN7_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN7]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN7_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|66))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN7_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN7]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN7_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|66))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN7_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN7]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN7_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|66))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN7_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN7]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN7_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|66))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN8_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN8]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN8_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|67))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN8_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN8]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN8_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|67))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN8_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN8]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN8_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|67))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN8_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN8]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN8_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|67))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN8_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN8]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN8_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|67))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN9_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN9]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN9_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|68))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN9_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN9]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN9_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|68))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN9_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN9]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN9_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|68))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN9_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN9]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN9_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|68))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN9_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN9]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN9_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|68))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN10_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN10]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN10_SLOT0         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|69))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN10_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN10]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN10_SLOT1         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|69))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN10_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN10]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN10_SLOT2         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|69))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN10_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN10]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN10_SLOT3         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|69))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN10_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN10]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN10_SLOT4         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|69))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN11_SLOT0
 *  @_adminPath     slot[0].slotPars.debounce_period[NYCE_DIGIN11]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN11_SLOT0         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|70))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN11_SLOT1
 *  @_adminPath     slot[1].slotPars.debounce_period[NYCE_DIGIN11]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN11_SLOT1         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|70))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN11_SLOT2
 *  @_adminPath     slot[2].slotPars.debounce_period[NYCE_DIGIN11]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN11_SLOT2         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|70))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN11_SLOT3
 *  @_adminPath     slot[3].slotPars.debounce_period[NYCE_DIGIN11]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN11_SLOT3         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|70))

/**
 *  @brief  Digital input debounce period.
 *
 *  @datatype       double
 *  @unit           [s]
 *  @minvalue       0.0
 *  @maxvalue       0.2
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_DEBOUNCE_PERIOD_DIGIN11_SLOT4
 *  @_adminPath     slot[4].slotPars.debounce_period[NYCE_DIGIN11]
 *  @readOnly       FALSE
 */
#define NHI_PAR_DEBOUNCE_PERIOD_DIGIN11_SLOT4         ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|70))

/**
 *  @brief  Nominal drive voltage.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       0.0
 *  @maxvalue       160.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_POS_NOMINAL_DRIVE_VOLTAGE_SLOT0
 *  @_adminPath     slot[0].posNominalServoVoltage
 *  @readOnly       FALSE
 */
#define NHI_PAR_POS_NOMINAL_DRIVE_VOLTAGE_SLOT0       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|71))

/**
 *  @brief  Nominal drive voltage.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       0.0
 *  @maxvalue       160.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_POS_NOMINAL_DRIVE_VOLTAGE_SLOT1
 *  @_adminPath     slot[1].posNominalServoVoltage
 *  @readOnly       FALSE
 */
#define NHI_PAR_POS_NOMINAL_DRIVE_VOLTAGE_SLOT1       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|71))

/**
 *  @brief  Nominal drive voltage.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       0.0
 *  @maxvalue       160.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_POS_NOMINAL_DRIVE_VOLTAGE_SLOT2
 *  @_adminPath     slot[2].posNominalServoVoltage
 *  @readOnly       FALSE
 */
#define NHI_PAR_POS_NOMINAL_DRIVE_VOLTAGE_SLOT2       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|71))

/**
 *  @brief  Nominal drive voltage.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       0.0
 *  @maxvalue       160.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_POS_NOMINAL_DRIVE_VOLTAGE_SLOT3
 *  @_adminPath     slot[3].posNominalServoVoltage
 *  @readOnly       FALSE
 */
#define NHI_PAR_POS_NOMINAL_DRIVE_VOLTAGE_SLOT3       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|71))

/**
 *  @brief  Nominal drive voltage.
 *
 *  @datatype       double
 *  @unit           [V]
 *  @minvalue       0.0
 *  @maxvalue       160.0
 *  @defaultvalue   0.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_POS_NOMINAL_DRIVE_VOLTAGE_SLOT4
 *  @_adminPath     slot[4].posNominalServoVoltage
 *  @readOnly       FALSE
 */
#define NHI_PAR_POS_NOMINAL_DRIVE_VOLTAGE_SLOT4       ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|71))

/**
 *  @brief  Drive over temperature limit.
 *
 *  @datatype       double
 *  @unit           [deg C], 0.0=disable
 *  @minvalue       0.0
 *  @maxvalue       105.0
 *  @defaultvalue   90.0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_OVER_TEMPERATURE_LIMIT_SLOT0
 *  @_adminPath     slot[0].overTemperatureLimit
 *  @readOnly       FALSE
 */
#define NHI_PAR_OVER_TEMPERATURE_LIMIT_SLOT0          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|72))

/**
 *  @brief  Drive over temperature limit.
 *
 *  @datatype       double
 *  @unit           [deg C], 0.0=disable
 *  @minvalue       0.0
 *  @maxvalue       105.0
 *  @defaultvalue   90.0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_OVER_TEMPERATURE_LIMIT_SLOT1
 *  @_adminPath     slot[1].overTemperatureLimit
 *  @readOnly       FALSE
 */
#define NHI_PAR_OVER_TEMPERATURE_LIMIT_SLOT1          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|72))

/**
 *  @brief  Drive over temperature limit.
 *
 *  @datatype       double
 *  @unit           [deg C], 0.0=disable
 *  @minvalue       0.0
 *  @maxvalue       105.0
 *  @defaultvalue   90.0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_OVER_TEMPERATURE_LIMIT_SLOT2
 *  @_adminPath     slot[2].overTemperatureLimit
 *  @readOnly       FALSE
 */
#define NHI_PAR_OVER_TEMPERATURE_LIMIT_SLOT2          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|72))

/**
 *  @brief  Drive over temperature limit.
 *
 *  @datatype       double
 *  @unit           [deg C], 0.0=disable
 *  @minvalue       0.0
 *  @maxvalue       105.0
 *  @defaultvalue   90.0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_OVER_TEMPERATURE_LIMIT_SLOT3
 *  @_adminPath     slot[3].overTemperatureLimit
 *  @readOnly       FALSE
 */
#define NHI_PAR_OVER_TEMPERATURE_LIMIT_SLOT3          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|72))

/**
 *  @brief  Drive over temperature limit.
 *
 *  @datatype       double
 *  @unit           [deg C], 0.0=disable
 *  @minvalue       0.0
 *  @maxvalue       105.0
 *  @defaultvalue   90.0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_OVER_TEMPERATURE_LIMIT_SLOT4
 *  @_adminPath     slot[4].overTemperatureLimit
 *  @readOnly       FALSE
 */
#define NHI_PAR_OVER_TEMPERATURE_LIMIT_SLOT4          ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_FLOAT <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLCUIO<<NYCE_FWMODULE_SHIFT)|72))

/**
 *  @brief  Digital IO mask to start motion.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        SLOTS/SLOT0/PARAMETERS/NHI_PAR_NODE_START_LEVEL_MASK_SLOT0
 *  @_adminPath     slot[0].nodeStartLevelMask
 *  @readOnly       FALSE
 */
#define NHI_PAR_NODE_START_LEVEL_MASK_SLOT0           ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT0<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|73))

/**
 *  @brief  Digital IO mask to start motion.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        SLOTS/SLOT1/PARAMETERS/NHI_PAR_NODE_START_LEVEL_MASK_SLOT1
 *  @_adminPath     slot[1].nodeStartLevelMask
 *  @readOnly       FALSE
 */
#define NHI_PAR_NODE_START_LEVEL_MASK_SLOT1           ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT1<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|73))

/**
 *  @brief  Digital IO mask to start motion.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        SLOTS/SLOT2/PARAMETERS/NHI_PAR_NODE_START_LEVEL_MASK_SLOT2
 *  @_adminPath     slot[2].nodeStartLevelMask
 *  @readOnly       FALSE
 */
#define NHI_PAR_NODE_START_LEVEL_MASK_SLOT2           ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT2<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|73))

/**
 *  @brief  Digital IO mask to start motion.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        SLOTS/SLOT3/PARAMETERS/NHI_PAR_NODE_START_LEVEL_MASK_SLOT3
 *  @_adminPath     slot[3].nodeStartLevelMask
 *  @readOnly       FALSE
 */
#define NHI_PAR_NODE_START_LEVEL_MASK_SLOT3           ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT3<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|73))

/**
 *  @brief  Digital IO mask to start motion.
 *
 *  @datatype       BITFIELD(NYCE_DIG_IO_NR)
 *  @defaultvalue   0
 *  @xmlPath        SLOTS/SLOT4/PARAMETERS/NHI_PAR_NODE_START_LEVEL_MASK_SLOT4
 *  @_adminPath     slot[4].nodeStartLevelMask
 *  @readOnly       FALSE
 */
#define NHI_PAR_NODE_START_LEVEL_MASK_SLOT4           ((NHI_PAR_ID)(RW|(SS_NHI<<NYCE_SUBSYS_SHIFT)|(NYCE_SLOT4<<NYCE_SLOT_SHIFT)|(FW_ULONG <<NYCE_FWTYPE_SHIFT)|(FW_SAME<<NYCE_FWDIM_SHIFT)|(FWM_CMLAXIO<<NYCE_FWMODULE_SHIFT)|73))

/**
 *  @}
 */

/**
 * @}
 */

#endif
