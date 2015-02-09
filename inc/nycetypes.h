/*
 *  BOSCH REXROTH
 *
 *  Copyright (c) Bosch Rexroth AG 2011
 *  Internet: http://www.boschrexroth.com
 *
 *  Product Name:   NYCe4000
 *  Component Name: HOSTSW
 *  Subsystem Name: NYCE
 *  %full_filespec: nycetypes.h`17:incl:1 %
 */
/**
 *  @file
 *  @brief headerfile containing datatypes and defines for NYCE.
 */
#ifndef __NYCETYPES_H__
#define __NYCETYPES_H__

#include "n4k_basictypes.h"

#ifdef NT
#pragma pack(push)
#pragma pack() //use default
#endif


/**
 *  @addtogroup nyce
 *  @{
 */

/**
 *  The maximum size of a string, defining the name of a
 *  node or an axis. String length is defined including a zero terminator.
 */
#define NYCE_MAX_NAME_LENGTH 16

/**
 *  The maximum size of a string representation of error-number and enum type returned
 *  by functions.
 */
#define NYCE_MAX_STRING_LENGTH 48

/**
 *  Maximum number of clients per node, as well as the maximum number of clients per axis.
 *  A client of an axis/node, is a process that connects the axis/node.
 */
#define NYCE_MAX_NR_OF_CLIENTS 16

/**
 *  Maximum number of nodes in the NYCe4000 system. This number does not include the host.
 */
#define NYCE_MAX_NR_OF_NODES 62

/**
 * Maximum number of axes that can be handled in a NYCe4000 system
 */
#define NYCE_MAX_NR_OF_AXES 128

/**
 *  Maximum number of axes on a NYCe4000 node.
 */
#define NYCE_MAX_NR_OF_AXES_PER_NODE 12

/**
 *  Maximum number of coil axis configurations on a NYCe4000 node.
 */
#define NYCE_MAX_NR_OF_COIL_CONFIGURATIONS_PER_NODE (NYCE_MAX_NR_OF_AXES_PER_NODE + 2)

/**
 *  Maximum unit number of axis.
 */
#define NYCE_MAX_UNIT_NR 511

/** 
 *  @brief  Maximum number of traceable variables per node.
 *
 *  @remarks 
 *      Note that both Variable Set and Trace functionalities use trace data from the node. 
 *      This means that Variable Set and Trace share the same trace resources on the node.
 */
#define NYCE_TRACE_MAX_NR_OF_VARS_PER_NODE 64

/** 
 *  @brief  Maximum number of nodes which can be used for trace and variable set.
 *
 *  @remarks 
 *      A node needs one 1394 isochronous channel for sending its trace data.
 */
#define NYCE_MAX_NR_OF_ISOCHRONOUS_CHANNELS 4

/** 
 *  @brief  Maximum number of variables which an application can define for trace.
 */
#define NYCE_TRACE_MAX_NR_OF_VARS (NYCE_MAX_NR_OF_ISOCHRONOUS_CHANNELS*NYCE_TRACE_MAX_NR_OF_VARS_PER_NODE)


/** 
 *  @brief  The size of the Variable Set. 
 */
#define NYCE_VAR_SET_SIZE         NYCE_TRACE_MAX_NR_OF_VARS

/**
 *  @brief  Maximum number of high speed data (HSD) trace variables that can be selected per axis.
 */
#define NYCE_TRACE_MAX_NR_OF_HSD_VARS_PER_AXIS 2

/** maximum number of broadcasting ECG masters */
#define NYCE_MAX_NR_OF_BC_MASTERS  4

#define NYCE_MAX_NR_OF_ECG_CAM_TABLES_PER_NODE 32    /**< Maximum number of cam tables per node. */

/* These definitions are used as dummy output values and for administration purposes. */
#define NYCE_NO_PAR_ID  RO  /**< Not a valid parId */
#define NYCE_NO_VAR_ID  RW  /**< Not a valid varId */


#define NYCE_MAX_NR_OF_ERROR_GROUPS 16   /**< Maximum number of error groups. */
#define NYCE_MAX_NR_OF_SYNC_GROUPS 16    /**< Maximum number of sync groups. */

/** maximum samples per seconds, used to calculate the sample time */
#define NYCE_MAX_SAMPLES_PER_SECOND          8000

#define NYCE_MAX_NR_OF_SEQUENCES             128
#define NYCE_MAX_NR_OF_ACTIVE_SEQUENCES      8
#define NYCE_MAX_SEQ_FILE_NAME               244
#define NYCE_MAX_SEQ_DBG_NR_OF_CHARS         20 /**< Maximum number of char's in a sequence debug event message */

/**
 *  This enumeration contains the possible sequence area types
 */
typedef enum nyce_seq_area_type 
{
    NYCE_SEQ_AREA_NON,                              /**< no area type defined          */
    NYCE_SEQ_AREA_SEQUENCE,                         /**< area used for sequences       */
    NYCE_SEQ_AREA_UDSX,                             /**< area used for UDSX            */
    NYCE_SEQ_AREA_SHARED_DATA                       /**< area used for shared data     */
} NYCE_SEQ_AREA_TYPE; 


#define NYCE_MAX_NR_OF_SPLINE_SEGMENTS_WRITE        16  /**< Maximum number of spline segments that can be written with the function SacWriteCubicIntBuffer. */
#define NYCE_MAX_NR_OF_BUFFERED_SPLINE_SEGMENTS     256 /**< Maximum number of spline segments which can be added to the spline buffer */
#define NYCE_MAX_NR_OF_FORCE_SEGMENTS_WRITE         16  /**< Maximum number of force segments that can be written with the function SacPfcWriteForceProfile. */

/** Maximum number of auto tweak feedforward values (2700 points * 12 axes * 4 bytes = +/- 128kb */
#define NYCE_MAX_NR_OF_TWEAK_POSITIONS       2700

/** maximum number of sensor linearization look-up-table points (2700 points * 12 axes * 4 bytes = +/- 128kb */
#define NYCE_MAX_LIN_LUT_POINTS_PER_AXIS     2700

/** maximum sizes used for aspi interfaces */
#define NYCE_MAX_ASPI_DATA_SIZE              256
#define NYCE_MAX_ASPI_ARRAY_SIZE             (NYCE_MAX_ASPI_DATA_SIZE / 8)   


/** maximum data size in number of bytes, used to save user data in flash */
#define NYCE_MAX_USER_DATA_FLASH_SIZE        240

/** maximum temperature */
#define NYCE_MAX_TEMPERATURE_LIMIT           105.0F

/** product name string length */
#define NYCE_PRODUCT_NAME_STRING_LENGTH      8
/** serial string length */
#define NYCE_SERIAL_STRING_LENGTH            16

/** Maximum number of latch sets per node */
#define NYCE_MAX_NR_OF_LATCH_SETS_PER_NODE      4

/** Maximum number of variables per latch set */
#define NYCE_MAX_NR_OF_VARIABLES_PER_LATCH_SET  12

/** maximum number of IndraDrives */
#define NYCE_MAX_NR_OF_INDRADRIVES           8

/** Maximum number of parameters per UDC */
#define NYCE_MAX_NR_OF_UDC_PARS 64

/** Maximum number of trace vars per UDC */
#define NYCE_MAX_NR_OF_UDC_TRACE_VARS 8

/** Maximum number of user errors */
#define NYCE_MAX_NR_OF_USER_ERRORS 8 

/** All user errors */
#define ALL_USER_ERRORS -1 

/** Maximum IndraDrive motor text type size */
#define NYCE_MAX_MOTOR_TEXT_TYPE_SIZE 80

#define NYCE_MAX_SENSORS_PER_COIL   3  

#define NYCE_MAX_NR_OF_SLOTS  (NYCE_SLOT4 + 1)


/**
 *  This enumeration contains the possible MCU firmware types
 */
typedef enum nyce_firmware_type
{
    NYCE_FIRMWARE_NONE = 0,
    NYCE_FIRMWARE_STANDARD,         /**< MCU firmware STANDARD (Does not support LMS axis) */
    NYCE_FIRMWARE_LMS,              /**< MCU firmware LMS (Does not support STANDARD axis) */
    NYCE_FIRMWARE_UDC,              /**< MCU firmware UDC (Does not support LMS axis) */ 
    NYCE_FIRMWARE_LAST              /**< @_nrOfEnumValues */
} NYCE_FIRMWARE_TYPE;


#define NYCE_SHA1_SIZE 20
#define NYCE_FIRMWARE_DESCRIPTION_SIZE 72

/**
*
* This describes the firmware_info struct which is used by SysGetFirmwareInfo.
*
*/

typedef struct nyce_firmware_info
{
    NYCE_FIRMWARE_TYPE      fwType;                                          /**< NONE, STD, UDC, LMS */
    uint8_t                 firmwareId[NYCE_SHA1_SIZE];                      /**< firmware sha1 */
    char                    description[NYCE_FIRMWARE_DESCRIPTION_SIZE];     /**< 'FW_TYPE firmware by [USER] branded [TIMESTAMP]' */ 

} NYCE_FIRMWARE_INFO;




/**
 *  This enumeration contains the possible MCU unit types
 */
typedef enum nyce_mcu_unit_type
{
    NYCE_NY4110 = 0,                    /**< NY4110 MCU unit */
    NYCE_NY4112 = 2,                    /**< NY4112 MCU unit */
    NYCE_LAST_MCU_UNIT                  /**< @_nrOfEnumValues */
} NYCE_MCU_UNIT_TYPE;

/** for internal use only */
#define NYCE_FIRST_MCU_UNIT  NYCE_NY4110


/**
 *  This enumeration contains the possible unit types
 */
typedef enum nyce_unit_type
{
    NYCE_NO_UNIT = -1,
    NYCE_NY4120  = 0,
    NYCE_NY4130  = 1,
    NYCE_NY4140  = 2,
    NYCE_NY4150  = 3,
/*  not used     = 4, */
    NYCE_NY4125  = 5,
    NYCE_LAST_UNIT        /**< @_invalidEnumValue */
} NYCE_UNIT_TYPE;

/**
 *  This enumeration holds the types of the expansion modules
 */
typedef enum nyce_expansion_module_type
{
    NYCE_NO_EXPANSION_MODULE = 0,
    NYCE_NY4199
} NYCE_EXPANSION_MODULE_TYPE;


/** Error codes received with error events (SAC_EV_ERRH_XXX) */
typedef uint32_t NYCE_ERROR_CODE;


/** NYCE_NODE_STATUS represents the state of a node. Used mainly during start-up */
typedef enum nyce_node_status
{
    NODE_STATUS_BL_ENABLING_FLASH, /**< never seen on the host */
    NODE_STATUS_BL_ENABLING_DSP,   /**< never seen on the host */
    NODE_STATUS_BL_WAITING_FOR_DOWNLOAD_COMMAND,
    NODE_STATUS_BL_DOWNLOADING,
    NODE_STATUS_FW_INITIALIZING,
    NODE_STATUS_FW_NORMAL_OPERATION,
    NODE_STATUS_BL_PROGRAMMING,
    NODE_STATUS_ERROR,
    NODE_STATUS_FW_DOWNLOADING,
    NODE_STATUS_FW_PROGRAMMING,
    NODE_STATUS_BL_ERASING,
    NODE_STATUS_FW_ERASING,
    NODE_STATUS_BL_MCU_EEPROM_DATA_CORRUPT,
    NODE_STATUS_FW_FLASH_CONFIGURATION_INCONSISTENT,
    NODE_STATUS_FW_MCU_CONFIGURATION_INCONSISTENT,
    NODE_STATUS_FW_WRONG_DRIVE_HW_ERROR,
    NODE_STATUS_FW_WRONG_DRIVE_GW_ERROR,
    NODE_STATUS_FW_WRONG_MICROWARE_ERROR,
    NODE_STATUS_FW_WRONG_SERCON_GW_ERROR,
    NODE_STATUS_DRIVELINK_ERROR,
    NODE_STATUS_BL_WAITING_FOR_DIAGNOSTIC_UPLOAD, /**< For internal diagnostic purposes only */
    NODE_STATUS_HW_GW_FW_INCONSISTENT
} NYCE_NODE_STATUS;

/** Version structure */
#ifdef NT
#pragma pack(push)
#pragma pack(4) // 32-bit/64-bit compatible
#endif
typedef struct nyce_version_type
{
    uint32_t   major;
    uint32_t   minor;
    uint32_t   micro;
    uint32_t   buildNr;

} NYCE_VERSION_TYPE;
#ifdef NT
#pragma pack(pop)
#endif


/** Serial structure */
typedef uint8_t NYCE_SERIAL_NUMBER[NYCE_SERIAL_STRING_LENGTH + 1];

/** 
 *  This enumeration defines the possible ids (axis or node id) addressed via
 *  the NYCE_ID structure
 */
typedef enum nyce_id_type
{
    SAC_ID_TYPE = 0,
    NHI_ID_TYPE = 1,
    SYS_ID_TYPE = 2,
/*  not used    = 3, */
    SEQ_ID_TYPE = 4
} NYCE_ID_TYPE;

/**
 *  The NYCE_ID is a generic way for addressing axes, nodes or the system.
 */
typedef struct nyce_id
{
    NYCE_ID_TYPE  type;
    uint32_t      id;

} NYCE_ID;

typedef uint32_t NYCE_EVENT;

/**
 *  This struct contains the event data for the change of state of a digital
 *  I/O register. In the ioMask the relevant bits are set, for which a change
 *  has been detected. In addition, the ioStatus field gives the actual value
 *  of the I/O status register of the relevant slot.
 */
typedef struct nyce_dig_io_change_of_state
{
    uint32_t    ioMask;     /**< mask containing relevant bits changed */
    uint32_t    ioStatus;   /**< status of relevant IO register */

} NYCE_DIG_IO_CHANGE_OF_STATE;


/**
 *  This enum defines the possible transitions between levels defined for an
 *  analogue input value.
 */
typedef enum nyce_level_transition
{
    NO_TRANS,
    NEG_TO_AREA,
    AREA_TO_NEG,
    POS_TO_AREA,
    AREA_TO_POS,
    NEG_TO_POS,
    POS_TO_NEG
} NYCE_LEVEL_TRANSITION;

typedef enum nyce_digital_io_level
{
    NYCE_INACTIVE_LEVEL = 0,    /**< I/O is inactive */
    NYCE_ACTIVE_LEVEL   = 1     /**< I/O is active */
} NYCE_DIGITAL_IO_LEVEL;


/**
 *  This struct contains an indication of the level transition detected for an
 *  analogue input and the actual value of the input in Volt.
 */
typedef struct nyce_level_crossing_data
{
    NYCE_LEVEL_TRANSITION   trans;
    float                   anInValue;

} NYCE_LEVEL_CROSSING_DATA;


/**
 *  This struct contains sequence event data or sequence debug string
 *  of a sequence event, if the dbgString is not null terminated then the
 *  rest of the debug message will come in the next event.
 */
typedef union nyce_sequence_event_data
{
    int32_t                 eventLong;
    char                    dbgString[NYCE_MAX_SEQ_DBG_NR_OF_CHARS];

} NYCE_SEQUENCE_EVENT_DATA;


/**
 *  This struct contains node number, area id and sequence event data
 *  of a sequence event
 */
typedef struct nyce_sequence_data
{
    NYCE_SEQUENCE_EVENT_DATA    eventData;
    uint16_t                    nodeId;
    uint16_t                    areaId;
     
} NYCE_SEQUENCE_DATA;


/**
 *  This struct contains an indication of the force threshold transition detected
 *  and the actual force value in Newton.
 */
typedef struct nyce_force_threshold_data
{
    NYCE_LEVEL_TRANSITION   trans;
    float                   actForce;

} NYCE_FORCE_THRESHOLD_DATA;

typedef struct nyce_lms_setp_stopped_data
{
    uint32_t                carrierIndex;
    int32_t                 position;

} NYCE_LMS_SETP_STOPPED_DATA;

typedef struct nyce_lms_car_jogging_data
{
    uint32_t                carrierIndex;
    float                   velocity;

} NYCE_LMS_CAR_JOGGING_DATA;

typedef struct nyce_lms_car_index_data
{
    uint32_t                carrierIndex;
    uint32_t                sensorIndex[ NYCE_MAX_SENSORS_PER_COIL ];

} NYCE_LMS_CAR_INDEX_DATA;


/**
 *  This union contains all possible event data.
 */
typedef union nyce_event_data
{
    NYCE_DIG_IO_CHANGE_OF_STATE uDigIOChangeOfState;
    NYCE_LEVEL_CROSSING_DATA    uAnInLevelCrossing;
    NYCE_STATUS                 uStatus;
    NYCE_ERROR_CODE             uErrorCode;
    NYCE_DIGITAL_IO_LEVEL       uDigIOLevel;
    int32_t                     uEventLong;
    uint32_t                    uEventUlong;
    double                      uEventDouble;
    float                       uEventFloat;
    uint32_t                    uEventUlongArray[6];
    BOOL                        uHomeSuccessful;
    uint32_t                    uEventLogging[2];
    int16_t                     uEventShortArray[4];
    NYCE_SEQUENCE_DATA          uSequence;
    NYCE_FORCE_THRESHOLD_DATA   uForceThreshold;
    NYCE_LMS_SETP_STOPPED_DATA  uSetpStopped;
    NYCE_LMS_CAR_JOGGING_DATA   uCarJogging;
    NYCE_LMS_CAR_INDEX_DATA     uCarIndex;

} NYCE_EVENT_DATA;


/**
 *  This enumeration is used as argument of the NyceInit function, to indicate that the NYCe4000
 *  software either runs in simulation mode, or by communicating via the network.
 */
typedef enum nyce_network_type
{
    NYCE_SIM,                   /**< Use the simulation network */
    NYCE_NET,                   /**< Use the preferred network */
    NYCE_ETH,                   /**< Use the Ethernet network */
    NYCE_FIWI                   /**< Use the IEEE 1394b network */
} NYCE_NETWORK_TYPE;

/* Definition of IO ranges */
#define DIGIN_BASE      0       /**< digital  inputs in IO status register bit  0..23 */
#define DIGOUT_BASE     24      /**< digital outputs in IO status register bit 24..31 */

/**
 *  The definition of digital I/O numbers.
 */
typedef enum nyce_dig_io_nr
{
    NYCE_NO_DIGIO = -1,         /**< if no io specified */
    NYCE_DIGIN0 = DIGIN_BASE,   /**< 24V Hall sensor 0A input or 24V input*/
    NYCE_DIGIN1,                /**< 24V Hall sensor 0B input or 24V input*/
    NYCE_DIGIN2,                /**< 24V Hall sensor 0C input or 24V input*/
    NYCE_DIGIN3,                /**< 24V input */
    NYCE_DIGIN4,                /**< 24V Hall sensor 1A input or 24V input*/
    NYCE_DIGIN5,                /**< 24V Hall sensor 1B input or 24V input*/
    NYCE_DIGIN6,                /**< 24V Hall sensor 1C input or 24V input*/
    NYCE_DIGIN7,                /**< 24V input */
    NYCE_DIGIN8,                /**< 24V input, only available on NY4125 and NY4130 */
    NYCE_DIGIN9,                /**< 24V input, only available on NY4125 and NY4130 */
    NYCE_DIGIN10,               /**< 24V input, only available on NY4125; reserved for stop alarm axis unit 0 on NY4130 */
    NYCE_DIGIN11,               /**< 24V input, only available on NY4125; reserved for stop alarm axis unit 1 on NY4130 */
    NYCE_FASTIN0,               /**< fast 24V input */
    NYCE_FASTIN1,               /**< fast 24V input; reserved for stop alarm axis unit 0-4 on NY4125 */
    NYCE_DIG5VIN0A,             /**< general purpose 5V TTL input; on NY4120 also 5V Hall sensor 0A or ASPI clock 0 */
    NYCE_DIG5VIN0B,             /**< general purpose 5V TTL input; on NY4120 also 5V Hall sensor 0B or ASPI strobe 0 */
    NYCE_DIG5VIN0C,             /**< general purpose 5V TTL input; on NY4120 also 5V Hall sensor 0C or ASPI data 0 */
    NYCE_DIG5VIN1A,             /**< general purpose 5V TTL input; only available on NY4120, NY4125 and NY4130; on NY4120 also 5V Hall sensor 1A or ASPI clock 1 */
    NYCE_DIG5VIN1B,             /**< general purpose 5V TTL input; only available on NY4120, NY4125 and NY4130; on NY4120 also 5V Hall sensor 1B or ASPI strobe 1 */
    NYCE_DIG5VIN1C,             /**< general purpose 5V TTL input, only available on NY4120 and NY4130; on NY4120 also 5V Hall sensor 1C or ASPI data 1 */
    NYCE_SPAREIN0,              /**< reserved */
    NYCE_SPAREIN1,              /**< reserved */
    NYCE_SPAREIN2,              /**< reserved */
    NYCE_SPAREIN3,              /**< reserved */
    NYCE_DIGOUT0 = DIGOUT_BASE, /**< 24V output */
    NYCE_DIGOUT1,               /**< 24V output */
    NYCE_DIGOUT2,               /**< 24V output; only available on NY4120, NY4125 and NY4130 */
    NYCE_DIGOUT3,               /**< 24V output; only available on NY4120, NY4125 and NY4130 */
    NYCE_FASTOUT0,              /**< fast 24V output */
    NYCE_FASTOUT1,              /**< fast 24V output */
    NYCE_SPAREOUT0,             /**< reserved */
    NYCE_SPAREOUT1              /**< reserved */
} NYCE_DIG_IO_NR;



/* Definitions for digital I/O masks, which are used to address I/O-s within the
 * digital I/O registers.
 */
#define NYCE_DIGIN0_MASK    ( 1 << NYCE_DIGIN0 )
#define NYCE_DIGIN1_MASK    ( 1 << NYCE_DIGIN1 )
#define NYCE_DIGIN2_MASK    ( 1 << NYCE_DIGIN2 )
#define NYCE_DIGIN3_MASK    ( 1 << NYCE_DIGIN3 )
#define NYCE_DIGIN4_MASK    ( 1 << NYCE_DIGIN4 )
#define NYCE_DIGIN5_MASK    ( 1 << NYCE_DIGIN5 )
#define NYCE_DIGIN6_MASK    ( 1 << NYCE_DIGIN6 )
#define NYCE_DIGIN7_MASK    ( 1 << NYCE_DIGIN7 )
#define NYCE_DIGIN8_MASK    ( 1 << NYCE_DIGIN8 )
#define NYCE_DIGIN9_MASK    ( 1 << NYCE_DIGIN9 )
#define NYCE_DIGIN10_MASK   ( 1 << NYCE_DIGIN10 )
#define NYCE_DIGIN11_MASK   ( 1 << NYCE_DIGIN11 )
#define NYCE_FASTIN0_MASK   ( 1 << NYCE_FASTIN0 )
#define NYCE_FASTIN1_MASK   ( 1 << NYCE_FASTIN1 )
#define NYCE_DIG5VIN0A_MASK ( 1 << NYCE_DIG5VIN0A )
#define NYCE_DIG5VIN0B_MASK ( 1 << NYCE_DIG5VIN0B )
#define NYCE_DIG5VIN0C_MASK ( 1 << NYCE_DIG5VIN0C )
#define NYCE_DIG5VIN1A_MASK ( 1 << NYCE_DIG5VIN1A )
#define NYCE_DIG5VIN1B_MASK ( 1 << NYCE_DIG5VIN1B )
#define NYCE_DIG5VIN1C_MASK ( 1 << NYCE_DIG5VIN1C )
#define NYCE_SPAREIN0_MASK  ( 1 << NYCE_SPAREIN0 )
#define NYCE_SPAREIN1_MASK  ( 1 << NYCE_SPAREIN1 )
#define NYCE_SPAREIN2_MASK  ( 1 << NYCE_SPAREIN2 )
#define NYCE_SPAREIN3_MASK  ( 1 << NYCE_SPAREIN3 )

#define NYCE_DIGOUT0_MASK   ( 1 << NYCE_DIGOUT0 )
#define NYCE_DIGOUT1_MASK   ( 1 << NYCE_DIGOUT1 )
#define NYCE_DIGOUT2_MASK   ( 1 << NYCE_DIGOUT2 )
#define NYCE_DIGOUT3_MASK   ( 1 << NYCE_DIGOUT3 )
#define NYCE_FASTOUT0_MASK  ( 1 << NYCE_FASTOUT0 )
#define NYCE_FASTOUT1_MASK  ( 1 << NYCE_FASTOUT1 )
#define NYCE_SPAREOUT0_MASK ( 1 << NYCE_SPAREOUT0 )
#define NYCE_SPAREOUT1_MASK ( 1 << NYCE_SPAREOUT1 )

#define NYCE_DIGIN_ALL  0x00FFFFFF
#define NYCE_DIGOUT_ALL 0xFF000000
#define NYCE_IO_ALL     (NYCE_DIGIN_ALL|NYCE_DIGOUT_ALL)


/** This structure contains the parameters to uniquely address a digital input or output on a node. */
typedef struct nyce_digital_io_id
{
    NYCE_SLOT_ID    slotId;     /**< specifies a slot of the node */
    NYCE_DIG_IO_NR  digIONr;    /**< specifies the digital input or output on the control unit contained in the slot */

} NYCE_DIGITAL_IO_ID;

/** This structures contains the parameters to uniquely address an analog input on a node. */
typedef struct nyce_analog_in_id
{
    NYCE_SLOT_ID slotId;        /**< specifies a slot of the node */
    int32_t      anInNr;        /**< specifies the analog input on the control unit contained in the slot */

} NYCE_ANALOG_IN_ID;

/** This structure contains the parameters to uniquely address an analog output on a node. */
typedef struct nyce_analog_out_id
{
    NYCE_SLOT_ID slotId;        /**< specifies a slot of the node */
    int32_t      anOutNr;       /**< specifies the analog output on the control unit contained in the slot */

} NYCE_ANALOG_OUT_ID;


/**
 *  This structure contains the parameters to uniquely address an axis unit on a node.
 *
 *  Axis units are numbered 0, 1, 2, ... . The maximum value of axisUnitNr depends on the type
 *  of control unit applied.
 */
typedef struct nyce_axis_unit_id
{
  NYCE_SLOT_ID  slotId;         /**< specifies a slot of the node */
  int32_t       axisUnitNr;     /**< specifies the axis unit on the control unit contained in the specified  slot */

} NYCE_AXIS_UNIT_ID;

typedef enum nyce_active_state
{
    NYCE_ACTIVE_LOW = 0,            /**< active at low voltage */
    NYCE_ACTIVE_HIGH = 1            /**< active at high voltage */
} NYCE_ACTIVE_STATE;

typedef enum nyce_edge_type
{
    NYCE_EDGE_NONE = 0,  /**< no trigger detection */
    NYCE_EDGE_RISING,    /**< trigger detection when input goes from inactive to active */
    NYCE_EDGE_FALLING,   /**< trigger detection when input goes from active to inactive */
    NYCE_EDGE_ANY,       /**< trigger detection when input goes from active to inactive or inactive to active */
    NYCE_LEVEL_ACTIVE,   /**< level detection when input is active, only used with start/stop triggers */
    NYCE_LEVEL_INACTIVE  /**< level detection when input is inactive, only used with start/stop triggers */
} NYCE_EDGE_TYPE;

typedef enum nyce_digout_action
{
    NYCE_RESET,   /**< output is adjusted to low voltage */
    NYCE_SET,     /**< output is adjusted to high voltage */
    NYCE_HOLD,    /**< output is not changed */
    NYCE_TOGGLE   /**< output is toggled */
} NYCE_DIGOUT_ACTION;


/* SERCOS-III definitions */

/**
 *  Known SERCOS-III devices
 */
typedef enum nyce_sercos_device_type
{
    NYCE_NO_SERCOS_DEVICE = -1,     /**< Not a SERCOS-III device */
    NYCE_INDRADRIVE_ADVANCED,       /**< IndraDrive advanced */
    NYCE_INDRADRIVE_CS,             /**< IndraDrive Cs */
    NYCE_LAST_SERCOS_DEVICE         /**< @_invalidEnumValue */
} NYCE_SERCOS_DEVICE_TYPE;

/**
 *  SERCOS-III network status
 */
typedef enum nyce_sercos_network_status
{
    NYCE_SERCOS_NETWORK_DETECTING_NETWORK,
    NYCE_SERCOS_NETWORK_ENTER_CP0_FAILED,
    NYCE_SERCOS_NETWORK_DOUBLE_ADDRESS,
    NYCE_SERCOS_NETWORK_RING_NOT_CLOSED,
    NYCE_SERCOS_NETWORK_TOO_MANY_DEVICES,
    NYCE_SERCOS_NETWORK_INITIALIZING_NETWORK,
    NYCE_SERCOS_NETWORK_ENTER_CP1_FAILED,
    NYCE_SERCOS_NETWORK_INITIALIZING_DEVICES,
    NYCE_SERCOS_NETWORK_ENTER_CP2_FAILED,
    NYCE_SERCOS_NETWORK_ENTER_CP3_FAILED,
    NYCE_SERCOS_NETWORK_ENTER_CP4_FAILED,
    NYCE_SERCOS_NETWORK_UNKNOWN_DEVICE_DETECTED,
    NYCE_SERCOS_NETWORK_READY,
    NYCE_SERCOS_NETWORK_WAITING_FOR_AXES_IDLE
} NYCE_SERCOS_NETWORK_STATUS;

/**
 *  SERCOS-III device status
 */
typedef enum nyce_sercos_device_status
{
    NYCE_SERCOS_DEVICE_INITIALIZING,
    NYCE_SERCOS_DEVICE_NORMAL_OPERATION,
    NYCE_SERCOS_DEVICE_WRONG_FIRMWARE_VERSION,
    NYCE_SERCOS_DEVICE_CLOSED_LOOP_PACKAGE_NOT_LOADED,
    NYCE_SERCOS_DEVICE_INITIALIZATION_FAILED
} NYCE_SERCOS_DEVICE_STATUS;


//end group nyce
/**
 * @}
 */

/**
 * @ingroup nyce_variable_set
 *
 * The output of the function NyceReadVariableSetElement, which supplies information
 * on the "i-th" variable in the set ( 0 = i < NYCE_VAR_SET_SIZE). The information
 * consists of the NYCE_ID of the axis or node and the variable id. In addition, the
 * struct contains the last known variable value.
 */
typedef struct nyce_var_set_element
{
    NYCE_ID         nyceId;     /**< axis or node id */
    uint32_t        variableId; /**< SAC or NHI var id */
    double          value;

} NYCE_VAR_SET_ELEMENT;


/**
 * @defgroup nyce_variable_trace Variable Trace
 *
 * The NYCE subsystem includes functionality for definition and access variable trace
 * buffers. Variable trace buffers contain history of a number of variables. The actual
 * content of the trace buffer is managed by the subsystems that are the holder of the
 * variables, like explained in the previous section. 
 *
 *  @{
 */

typedef enum nyce_trace_state
{
    NYCE_TRACE_IDLE,     /**< Trace is not defined. This is the Initial state. NyceDeleteTrace */
    NYCE_TRACE_READY,    /**< Trace is defined and trace buffer contents is not changed. */
    NYCE_TRACE_RUNNING,  /**< Trace is active and trace buffer is being filled with trace data. */
    NYCE_TRACE_STOPPING, /**< A stop command has been issued, but the delay has not expired yet. */
    NYCE_TRACE_ERROR     /**< A fatal error has occurred. Call NyceResetTraceError to reset and enter the NYCE_TRACE_READY state. */
} NYCE_TRACE_STATE;

/**
 * Defines the trace configuration when the trace is defined.
 * 
 */
typedef struct nyce_trace_definition
{
    uint32_t        maxNrOfVars;      /**< The maximum number of variables to trace. A trace sample in the trace buffer will have this size.*/
    uint32_t        bufferSize;       /**< The maximum number of trace samples which can be stored while tracing. */
    uint32_t        sampleFrequency;  /**< The sample frequency, in Hz, at which trace samples are stored in the buffer.
                                           This may be zero, in which case the trace frequency is determined by the 
                                           fastest updating selected variable, or the fastest running node in the network if no
                                           variables are selected. The actual used frequency can be determined by the 
                                           trace info. As soon as the trace is started, this frequency will not change, 
                                           even when the trace is stopped and data is available in the trace buffer. 
                                           Only when the trace buffer is cleared by selecting other variables the actual used 
                                           frequency will be determined automatically again.
                                           If sampleFrequency is non-zero, it may be one of the following values:
                                           1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 
                                           2000, 4000, 8000, 16000 or 32000 Hz*/
                                           

} NYCE_TRACE_DEFINITION;

/**
 * The output of the function NyceGetTraceElement and NycegetLocalTraceElements, which 
 * supplies information on a trace variable in the buffer, stored at a specific index. 
 * The information consists of the index, a variable id and NYCE_ID of the axis or node 
 * on which the traced variable is located.
 */
typedef struct nyce_trace_element
{
    uint32_t        varIndex;   /**< Index of this variable in the list of selected variables. */
    NYCE_ID         nyceId;     /**< Id of the connected axis or node. */
    uint32_t        varId;      /**< SAC or NHI variable id as an unsigned int. */

} NYCE_TRACE_ELEMENT;


/**
 * Specifies the returned elements by NyceGetGlobalTraceElements.  
 *
 * Because this function can return trace elements of other applications, it will identify the axis or node 
 * using a system node number and axis number. If the axis number is -1, the variable is a node (NHI) variable.
 * You can get a node connection, using SysGetNodeName and NhiConnect using this node name.
 * To get an axis connection, in case the axis number is not -1, you must first get the axis name,
 * using NhiGetAxisName and then connect to the axis with SacConnect using the axis name.
 */
typedef struct nyce_global_trace_element
{
    uint32_t        sysNodeNumber;      /**< The system node number for this variable. */
    int32_t         axisNumber;         /**< The axis number for this variable. If -1, the variable is a node variable. */
    uint32_t        varId;              /**< SAC or NHI variable id as an unsigned int. */

} NYCE_GLOBAL_TRACE_ELEMENT;


/**
 * This enumeration defines the error codes, which can be active for a trace client. 
 * The order of enumeration comprehends the severity: if an error occurs of a higher 
 * severity than the current active error, it will overrule the current error. 
 */
typedef enum nyce_trace_error_code
{
    NYCE_TRACE_ERR_NONE = 0,                    /**< No error active  */
    NYCE_TRACE_ERR_HSD_INVALID,                 /**< non-fatal, trace samples are received which contain invalid values for HSD variables */
    NYCE_TRACE_ERR_VARIABLE_LOST,               /**< non-fatal, the node does not send data for a traced variable */
    NYCE_TRACE_ERR_NODE_OUT_OF_SYNC,            /**< fatal: timing of trace data from different nodes can not be related with respect to each other */
    NYCE_TRACE_ERR_SAMPLES_LOST,                /**< fatal: trace data is lost because the system (PC) can not retrieve and store it in time */
    NYCE_TRACE_ERR_NODE_PACKET_CORRUPT,         /**< fatal: a corrupt isochronous trace packet is received */
    NYCE_TRACE_ERR_NODE_PACKET_LOST,            /**< fatal: an isochronous trace packet from a node is lost */
    NYCE_TRACE_ERR_NODE_ISOCH_BUF_UNDERRUN,     /**< fatal: the isochronous packet communication on the node experienced a buffer underrun */
    NYCE_TRACE_ERR_ISOCH_COMMUNICATION_LOST,    /**< fatal: no isochronous communication */
    NYCE_TRACE_ERR_BUSRESET_OCCURED,            /**< fatal: a bus reset occurred */
    NYCE_TRACE_ERR_NODE_LOST                    /**< fatal: a node is disconnected */

} NYCE_TRACE_ERROR_CODE;


/**
 * This structure defines all state information for the trace client.
 */
typedef struct nyce_trace_info
{
    NYCE_TRACE_STATE        state;              /**< The state of the trace. If this is NYCE_TRACE_IDLE, all other members are invalid. */
    uint32_t                maxNrOfVars;        /**< The maximum number of variables which can be added to the trace. This value is specified by NyceDefineTrace. */
    uint32_t                bufferSize;         /**< The maximum number of trace samples that can be buffered in the trace buffer. This value is specified by NyceDefineTrace. */
    uint32_t                nrOfVars;           /**< The number of selected trace variables. This can be zero to maxNrOfVars. */
    double                  traceSampleTime;    /**< The duration, in seconds, of one trace sample. It is the inverse of the sampleFrequency as specified when the trace was defined*/
    uint64_t                timeCounter;        /**< The total number of received trace samples since the trace was started. Note that this can be larger than bufferSize. */
    uint32_t                nrOfValidSamples;   /**< The actual number of valid trace samples available in the trace buffer. This will never be larger than bufferSize. */
    uint64_t                triggerTime;        /**< The trace time counter value at the moment when the stop trace command was issued. This information is only valid in the NYCE_TRACE_STOPPING and NYCE_TRACE_READY states. */
    NYCE_TRACE_ERROR_CODE   errorCode;          /**< The current trace error code. */
} NYCE_TRACE_INFO;

//end group nyce_variable_trace
/**
 *  @}
 */


#ifdef NT
#pragma pack(pop)
#endif


#endif //__NYCETYPES_H__
