/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2009
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000_SW
//    Component Name: HOSTSW
//    Subsystem Name: NYCE
//    %full_filespec:    nyceint.h`13:incl:1 % (SYNERGY INFO, do not change)
//
//    Description   : Generic public interface to NYCe4000
*/

#ifndef __NYCEINT_H__
#define __NYCEINT_H__


#if !defined(C67)
#if !defined(NT)
#if !defined(GNUARM)
#if !defined(linux)
#error "Define correct preprocessor macro for NYCe4000 (NT for building WIN32, C67 for building firmware, GNUARM for building microware or linux for building dspproxy)"
#endif
#endif
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

/*-----------------------------------------------------------------------
 * GLOBAL DEFINES
 *-----------------------------------------------------------------------
 */
/* REDEFinition of X bits INTegers on host/firmware InterFace */
#ifndef __INTX_T_REDEF__
#define __INTX_T_REDEF__

#if defined(NT) && (_MSC_VER < 1600) /* on host; Visual Studio 10 (1600) includes stdint */
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;

#if (_MSC_VER >= 1300)               /* on host; Older Visual Studio versions do not understand long long types */
typedef unsigned long long  uint64_t;
#endif

typedef signed char         int8_t;
typedef signed short        int16_t;
typedef int                 int32_t;

#if (_MSC_VER >= 1300)               /* on host; Older Visual Studio versions do not understand long long types */
typedef long long           int64_t;
#endif

/* Integer types capable of holding object pointers */
/* Don't make a fuss if these have already been defined in the same way */
/*lint -save */
/*lint -e761 */

#if defined(_WIN64)
typedef int64_t             intptr_t;
typedef uint64_t            uintptr_t;
#else
typedef int32_t             intptr_t;
typedef uint32_t            uintptr_t;
#endif
/*lint -restore */

typedef int32_t             int_least16_t;

#elif defined(C67) /* on DSP */

typedef signed char     int8_t;
typedef signed short    int16_t;
typedef int             int32_t;

typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned int    uint32_t;

typedef struct _int64_t
{
    uint32_t            lo;
    int32_t             hi;
} int64_t;

typedef struct _uint64_t
{
    uint32_t            lo;
    uint32_t            hi;
} uint64_t;

/* Integer types capable of holding object pointers */
typedef int32_t             intptr_t;
typedef uint32_t            uintptr_t;

typedef int32_t             int_least16_t;

#elif defined(GNUARM) && !defined(linux) /* on ARM */

typedef signed char     int8_t;
typedef signed short    int16_t;
typedef long            int32_t;

typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned long   uint32_t;

typedef struct _uint64_t
{
    uint32_t            lo;
    uint32_t            hi;

} uint64_t;

typedef struct _int64_t
{
    uint32_t            lo;
    int32_t             hi;

} int64_t;

/* Integer types capable of holding object pointers */
typedef int32_t             intptr_t;
typedef uint32_t            uintptr_t;

typedef int32_t             int_least16_t;

#else /* use standard type definitions */
    
#include <stdint.h>

#endif /* NT */

#endif /* __INTX_T_REDEF__ */

#ifdef __cplusplus
}
#endif

#ifdef NT
#pragma pack(pop)
#endif

#endif /* __NYCEINT_H__ */

