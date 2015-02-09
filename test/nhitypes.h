/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2011
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: NHI
 *  %full_filespec: nhitypes.h`10:incl:1 %
 */
/**
 *  @file
 *  @brief  headerfile containing datatypes and defines for NHI.
 */
#ifndef __NHITYPES_H__
#define __NHITYPES_H__

#include "nycedefs.h"

#ifdef NT
#pragma pack(push)
#pragma pack() //use default
#endif


/**
 *  @defgroup nhi Node Hardware Interface (NHI)
 *
 *  Via the NHI library it is possible to access all analog and digital I/O. This implies that all outputs can be set,
 *  and that the actual values of all inputs and outputs can be read. This way general purpose I/O can be addressed.
 *  This is I/O, which has not been configured for a specific function. However, also configured I/O can be
 *  accessed. This offers the application to initialize outputs before they have been actually used, or to overrule
 *  the output behavior dictated by the assigned function.
 *
 *  @{
 */

/**
 *  Use this define to initialize from flash.
 *  @see    NhiInitialize
 */
#define NHI_USE_FLASH "UseFlash"

#define NHI_INDEFINITE ((double)-1)     /**< The time-out value that will result in an indefinite suspension. */

#define NHI_INVALID_ID (NHI_NODE)NYCE_MAX_NR_OF_NODES   /**< The invalid node id identifier */

typedef uint32_t NHI_NODE;  /**< Node connection handle. */

/**
 *  @defgroup nhi_parameters Parameters
 *
 *  \ref NhiReadParameter and \ref NhiWriteParameter access single NHI parameters. All
 *  NHI parameters can be stored in the flash of the concerning node. It is
 *  also possible to upload the current NHI parameters to an XML file on the host.
 *
 */

/**
 *  @defgroup nhi_variables Variables
 *
 *  The function \ref NhiReadVariable reads the actual value of a variable within a
 *  node. The functions \ref NhiAddVariableToSet, \ref NhiAddVarToLatchSet and
 *  \ref NhiAddVariableToTrace return as output argument the index on which
 *  the variable can be found in the set or trace. This index should also be used
 *  as function argument for deleting the variable from a set or trace.
 *  Variable sets and traces are explained in more detail in section \ref nyce_variable_set
 *  on and section \ref nyce_variable_trace. Variable latch sets are explained in more detail
 *  in section \ref nhi_variable_latch_set.
 *
 */

/**
 *  @defgroup nhi_variable_latch_set Variable Latch Sets
 *
 *  A variable latch set is a set of axis and node variables which values are latched
 *  when a specific event occurs. A limited number of sets are available per node.
 *  A set on a node is identified by an index number. Using \ref NhiAddVarToLatchSet
 *  and \ref SacAddVarToLatchSet you can add variables to a set.
 *  Using \ref NhiActivateLatchSet and \ref SacActivateLatchSet a set is armed. When a
 *  set is armed, it will latch the variable values when the specified event occurs.
 *  The latched values can then be read by \ref NhiReadLatchSetValues
 */

/**
 *  @defgroup nhi_events Events
 */

/**
 *  @defgroup nhi_configuration Configuration
 */

/**
 *  @defgroup nhi_state_transitions State Transitions
 */

/**
 *  @defgroup nhi_digital_io Digital I/O
 */

/**
 *  @defgroup nhi_analog_io Analog I/O
 */

/**
 *  @defgroup nhi_latches Latches
 */

/**
 *  @defgroup nhi_counters Counters
 */

/**
 *  @defgroup nhi_hardware Hardware Properties
 */

/**
 *  @defgroup nhi_aspi ASPI Communication Interface
 */

/**
 *  @defgroup nhi_expansion_module Expansion Module
 */

/**
 *  @defgroup nhi_camming Camming
 *
 *  The functions within this module define and delete memory to save camming tables and
 *  to download a camming table.
 */

/**
 *  @defgroup nhi_sdc Serial Data Channel
 */

/**
 *  @defgroup nhi_miscellaneous Miscellaneous
 */

/**
 *  @defgroup nhi_conversion Conversion
 *
 *  The functions within this module convert strings to enumeration values and vice versa.
 */

/**
 *  @ingroup nhi_configuration
 */
typedef struct nhi_sercos_device
{
    uint32_t                    unitNr;             /**< SERCOS address of the device */
    NYCE_SERCOS_DEVICE_TYPE     type;               /**< device type */
    NYCE_SERCOS_DEVICE_STATUS   status;             /**< device status */
} NHI_SERCOS_DEVICE;

/**
 *  @ingroup nhi_configuration
 */
typedef struct nhi_sercos_network
{
    NYCE_SERCOS_NETWORK_STATUS  networkStatus;      /**< status of SERCOS network */
    uint32_t                    nrOfDevices;        /**< number of devices in SERCOS network */
    NHI_SERCOS_DEVICE           device[NYCE_MAX_NR_OF_INDRADRIVES];     /**< device info for each device in SERCOS network */
} NHI_SERCOS_NETWORK;

/**
 *  @ingroup nhi_analog_io
 */
typedef enum nhi_adc_dimension
{
    NHI_VOLTAGE = 0,        /**< enumeration type to set analog input dimension */
    NHI_CURRENT = 1         /**< enumeration type to set analog input dimension */
} NHI_ADC_DIMENSION;

/**
 *  @ingroup nhi_counters
 */
typedef enum nhi_digin_counter_id
{
    NHI_DIGIN_COUNTER0 = 0,
    NHI_DIGIN_COUNTER1,
    NHI_DIGIN_COUNTER2,
    NHI_DIGIN_COUNTER3,
    NHI_NR_OF_DIGIN_COUNTERS        /**< @_nrOfEnumValues */
} NHI_DIGIN_COUNTER_ID;

/**
 *  @ingroup nhi_digital_io
 */
typedef enum nhi_digout_type
{
    NHI_DIGOUT_STATE,   /**< high or low */
    NHI_DIGOUT_PULSE,   /**< only 1 pulse when high */
    NHI_DIGOUT_PWM      /**< blockwave */
} NHI_DIGOUT_TYPE;

/**
 *  @ingroup nhi_digital_io
 */
typedef struct nhi_digout_pwm_pars
{
    double onDelay;           /**< time in seconds */
    double frequency;         /**< frequency in Hz */
    double dutyCycle;         /**< duty cycle in % */

} NHI_DIGOUT_PWM_PARS;

/**
 *  @ingroup nhi_digital_io
 */
typedef union nhi_digout_pars
{
    double               pulseTime;  /**< duration (in s) of a PULSE */
    NHI_DIGOUT_PWM_PARS  pwmPars;    /**< parameters of a PWM output */

} NHI_DIGOUT_PARS;

/**
 *  @ingroup nhi_latches
 */
typedef enum nhi_latch_id
{
    NHI_LATCH_0 = 0,
    NHI_LATCH_1,
    NHI_LATCH_2,
    NHI_LATCH_3,
    NHI_NR_OF_LATCHES       /**< @_nrOfEnumValues */
} NHI_LATCH_ID;

/**
 *  @ingroup nhi_latches
 */
typedef struct nhi_latch_pars
{
    NYCE_DIG_IO_NR  digIONr;            
    NHI_LATCH_ID    latchId;
    NYCE_EDGE_TYPE  edgeType;

} NHI_LATCH_PARS;

/**
 *  @ingroup nhi_aspi
 */
typedef enum nhi_aspi_port_id
{
    NHI_ASPI_PORT0 = 0,
    NHI_ASPI_PORT1,
    NHI_MAX_NR_OF_ASPI_PORTS        /**< @_nrOfEnumValues */
} NHI_ASPI_PORT_ID;

/**
 *  @ingroup nhi_aspi
 */
typedef enum nhi_aspi_port_type
{
    NHI_ASPI_NONE = -1,     /**< for internal use only */
    NHI_ASPI_MASTER_WRITE,
    NHI_ASPI_MASTER_READ,
    NHI_ASPI_SLAVE_READ
} NHI_ASPI_PORT_TYPE;

/**
 *  @ingroup nhi_aspi
 */
typedef struct nhi_aspi_config_pars
{
    NHI_ASPI_PORT_TYPE       portType;
    double                   clockSpeed ;       /**< period time in s */
    NYCE_ACTIVE_STATE        clockActiveState;
    double                   strobePulseTime;   /**< pulse duration in s */
    NYCE_ACTIVE_STATE        strobeActiveState;
    int32_t                  dataSize;          /**< in number of bits */
    NYCE_ACTIVE_STATE        dataActiveState;

} NHI_ASPI_CONFIG_PARS;

/**
 *  @ingroup nhi_aspi
 */
typedef enum nhi_aspi_state
{
    NHI_ASPI_NOT_CONFIGURED,
    NHI_ASPI_INACTIVE,
    NHI_ASPI_PENDING,
    NHI_ASPI_ACTIVE
} NHI_ASPI_STATE;

/**
 *  @ingroup nhi_events
 *  This enumeration defines requests on which it is possible to synchronize for completion in an application.
 */
typedef enum nhi_sync_request
{
    NHI_REQ_READ_READY_PORT0,
    NHI_REQ_WRITE_READY_PORT0,
    NHI_REQ_READ_READY_PORT1,
    NHI_REQ_WRITE_READY_PORT1
} NHI_SYNC_REQUEST;

/**
 *  @ingroup nhi_miscellaneous
 *  This structure contains all information about node software and hardware versions.
 */
typedef struct nhi_version_info
{
    NYCE_VERSION_TYPE mcuVersion;                                       /**< MCU hardware version */
    NYCE_VERSION_TYPE firmwareVersion;                                  /**< MCU firmware version */
    NYCE_VERSION_TYPE gatewareVersion;                                  /**< MCU gateware version */
    uint32_t          slotMask;                                         /**< bit pattern specifying which slots contain a drive module */
    NYCE_VERSION_TYPE driveHwVersion[NYCE_MAX_NR_OF_SLOTS];             /**< Drive module hardware versions */
    NYCE_VERSION_TYPE driveGwVersion[NYCE_MAX_NR_OF_SLOTS];             /**< Drive module gateware versions */
    NYCE_VERSION_TYPE driveMwVersion[NYCE_MAX_NR_OF_SLOTS];             /**< Drive module microware versions (only used by NY4150) */
    NYCE_VERSION_TYPE driveDlSerconVersion[NYCE_MAX_NR_OF_SLOTS];       /**< Drive module SERCON version (only used by NY4150) */

} NHI_VERSION_INFO;

/**
 *  @ingroup nhi_miscellaneous
 *  This type contains the context type.
 */
typedef int32_t NHI_CONTEXT_TYPE;

#define NHI_CONTEXT_UNKNOWN         -3
#define NHI_CONTEXT_SAMPLE          -2
#define NHI_CONTEXT_MAIN            -1
#define NHI_CONTEXT_SEQUENCE_0      0

/**
 *  @ingroup nhi_miscellaneous
 *  This structure contains all information about a node context log.
 */
typedef struct nhi_context_log
{
    NHI_CONTEXT_TYPE    contextType;        /**< Type of the context log. */
    double              contextDuration;    /**< Context log duration in seconds. */
    uint32_t            sampleNr;           /**< Sample number of the context log. */

} NHI_CONTEXT_LOG;

/**
 *  @ingroup nhi_miscellaneous
 *  Statistics of the context logging.
 */
typedef struct nhi_context_logging_stats
{
    BOOL        enabled;            /**< Whether or not the context logging is enabled */
    uint32_t    nrOfLogsFilled;     /**< The number of logs that are filled */
    uint32_t    maxNrOfLogs;        /**< The max number of logs that can be filled */

} NHI_CONTEXT_LOGGING_STATS;

/**
 *
 *  @ingroup nhi_variable_latch_set
 *  Defines the states for a latch set.
 */
typedef enum nhi_latch_set_state
{
    NHI_LATCH_SET_STATE_IDLE = 0,   /**< The latch set is not active and variables may be added */
    NHI_LATCH_SET_STATE_ARMED,      /**< The latch set is activated. The latch will occur when the specified event is triggered. The variable definition can not be changed. */
    NHI_LATCH_SET_STATE_READY       /**< The variables in the latch set are latched and can be read. */
}NHI_LATCH_SET_STATE;


/**
 *  @ingroup nhi_camming
 *  This enumeration holds the camming type.
 */
typedef enum nhi_ecg_cam_type
{
    NHI_ECG_CAM_LINEAR,
    NHI_ECG_CAM_SPLINE
}NHI_ECG_CAM_TYPE;

/**
 *  @ingroup nhi_camming
 *  This structure holds the camming table definitition.
 */
typedef struct nhi_ecg_cam_table_def
{
    uint32_t          tableId;       /**< Table identifier. */
    NHI_ECG_CAM_TYPE  camType;       /**< Cam type. */
    uint32_t          nrOfPoints;    /**< Number of points in the cam table. */

}NHI_ECG_CAM_TABLE_DEF;

/**
 *  @ingroup nhi_camming
 *  This structure holds the camming point.
 */
typedef struct nhi_ecg_cam_point
{
    double  masterPos;     /**< Master position in pu. */
    double  slavePos;      /**< Slave position at the corresponding master position in pu. */
    double  velocityRatio; /**< Derivative of the slave position with respect to the master position, only used if the cam type is "spline" */

}NHI_ECG_CAM_POINT;

/**
 *  @ingroup nhi_camming
 *  This structure holds the camming table.
 */
typedef struct nhi_ecg_cam_table
{
    NHI_ECG_CAM_TABLE_DEF   tableDef;   /**< The cam table definitions. */                 
    NHI_ECG_CAM_POINT*      pPoints;    /**< The points of the cam table. */

}NHI_ECG_CAM_TABLE;

/**
 *  @ingroup nhi_sdc
 *  This enumeration defines all serial data channel identifiers.
 */
typedef enum nhi_sdc_channel_id
{
    NHI_SDC_NO_CHANNEL_ID = -1,
    NHI_SDC_CHANNEL0,
    NHI_SDC_CHANNEL1,
    NHI_SDC_CHANNEL2,
    NHI_SDC_CHANNEL3,
    NHI_SDC_MAX_NR_OF_CHANNELS      /**< @_invalidEnumValue */
} NHI_SDC_CHANNEL_ID;

/**
 *  @ingroup nhi_sdc
 *  This enumeration defines all serial data channel port identifiers.
 */
typedef enum nhi_sdc_port_id
{
    NHI_SDC_NO_PORT = -1,
    NHI_SDC_PORT0,
    NHI_SDC_PORT1,
    NHI_SDC_PORT2,
    NHI_SDC_PORT3,
    NHI_SDC_PORT4,
    NHI_SDC_MAX_NR_OF_PORT_IDS      /**< @_invalidEnumValue */
} NHI_SDC_PORT_ID;

/**
 *  @ingroup nhi_sdc
 *  This enumeration defines serial data channel memory block identifiers.
 */
typedef enum nhi_sdc_memory_block_id
{
    NHI_SDC_ENDAT_OPERATING_STATUS,
    NHI_SDC_ENDAT_MANUFACTURER_PARS1,
    NHI_SDC_ENDAT_MANUFACTURER_PARS2,
    NHI_SDC_ENDAT_MANUFACTURER_PARS3,
    NHI_SDC_ENDAT_OPERATING_PARS,
    NHI_SDC_ENDAT_OEM_BLOCK1,
    NHI_SDC_ENDAT_OEM_BLOCK2,
    NHI_SDC_ENDAT_OEM_BLOCK3,
    NHI_SDC_ENDAT_COMPENSATION_VALUES,
    NHI_SDC_MAX_NR_OF_MEMORY_BLOCK_IDS  /**< @_nrOfEnumValues */
} NHI_SDC_MEMORY_BLOCK_ID;

/**
 *  @ingroup nhi_sdc
 *  This enumeration defines all serial data channel states.
 */
typedef enum nhi_sdc_state
{
    NHI_SDC_IDLE = 0,
    NHI_SDC_INACTIVE,
    NHI_SDC_ASYNC_COMMUNICATION,
    NHI_SDC_SYNC_COMMUNICATION
} NHI_SDC_STATE;


/**
 *  @ingroup nhi_sdc
 *  This enumeration defines all serial data channel communication errors.
 */
typedef enum nhi_sdc_communication_error
{
    NHI_SDC_NO_COMMUNICATION_ERROR = 0,
    NHI_SDC_CRC_ERROR,
    NHI_SDC_TIMEOUT_ERROR
} NHI_SDC_COMMUNICATION_ERROR;


/**
 *  @ingroup nhi_sdc
 *  This enumeration defines all serial data channel states during initializing.
 */
typedef enum nhi_sdc_initialize_state
{
    NHI_SDC_INIT_STATE_IDLE = 0,
    NHI_SDC_INIT_STATE_SET_100KHZ_CLOCK,
    NHI_SDC_INIT_STATE_RESET,
    NHI_SDC_INIT_STATE_CLEAR_ERRORS,
    NHI_SDC_INIT_STATE_GET_NR_OF_BITS,
    NHI_SDC_INIT_STATE_SET_NR_OF_BITS,
    NHI_SDC_INIT_STATE_DELAY_MEASUREMENT,
    NHI_SDC_INIT_STATE_SET_CLOCK_FREQ,
    NHI_SDC_INIT_STATE_INITIALIZED
} NHI_SDC_INITIALIZE_STATE;


/**
 *  @ingroup nhi_configuration
 *  This enumeration defines the nhi gateware types.
 */
typedef enum nhi_gateware_variant
{
    NHI_GATEWARE_STD = 0,
    NHI_GATEWARE_ASPI,
    NHI_GATEWARE_LMS,
    NHI_GATEWARE_UNKNOWN,
    NHI_GATEWARE_EMPTY_SLOT
} NHI_GATEWARE_VARIANT;


/** @} */

#ifdef NT
#pragma pack(pop)
#endif

#endif // __NHITYPES_H__
