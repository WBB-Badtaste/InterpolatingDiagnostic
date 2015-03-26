// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

// TODO: reference additional headers your program requires here

#define NT						// Define correct preprocessor macro for NYCe4000 (NT for building WIN32)

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#define WIN32_LEAN_AND_MEAN     // Exclude rarely-used stuff from Windows headers

// Windows Header Files:

#define DEBUG

#include <windows.h>
#include <map>
#include <string>
#include "nyceapi.h"
#include "nhiapi.h"
#include "sacapi.h"
#include "Errors.h"
#include "Types.h"
#include "dehapi.h"
#include "dehenums.h"
#include "dehtypes.h"

#include "rocksenums.h"
#include "Interpolation.h"

