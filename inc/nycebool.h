/*
//    BOSCH REXROTH
//
//    Copyright (c) Bosch Rexroth AG 2009
//    Internet: http://www.boschrexroth.com
//
//    Project Name  : NYCe4000_SW
//    Component Name: HOSTSW
//    Subsystem Name: NYCE
//    %full_filespec:    
//
//    Description   : Generic public interface to NYCe4000 booleans
*/

#ifndef __NYCEBOOL_H__
#define __NYCEBOOL_H__



/** When windows.h is already included or BOOL is already
 *  defined, we have BOOL available.
 *  When BOOL is typedef-ed elsewhere, please define
 *  _NYCE_TYPE_BOOL_AVAILABLE_ as well
 */
#if (defined(_WINDOWS_) | defined(BOOL))
#define _NYCE_TYPE_BOOL_AVAILABLE_
#endif 


/** Typedef BOOL if it is not defined/typedef-ed elsewhere in
 *  NYCe4000
 */
#ifndef _NYCE_TYPE_BOOL_AVAILABLE_
typedef int BOOL;
#define _NYCE_TYPE_BOOL_AVAILABLE_
#endif 

/**  Get a true and false with the correct cast
 */
#ifdef TRUE
#undef TRUE
#endif

#ifdef FALSE
#undef FALSE
#endif

/**  More readable boolean constants
 */
#define TRUE    (BOOL)1
#define FALSE   (BOOL)0


#endif  /* __NYCEBOOL_H__ */
