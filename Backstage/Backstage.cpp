// Backstage.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "BackstageInterface.h"
//#include "Backstage.h"



BACKSTAGE_API int WINAPI Initialize(const bool bSim)
{
	return 1111;
// 	g_pNyce = new NyceSystem(bSim);
// 	return g_pNyce->Status() == SYSTEM_INITIALIZED ? BACKSTAGE_OK : BACKSTAGE_INITALIZE_FAIL;
}

BACKSTAGE_API int WINAPI Terminate()
{
// 	if(g_pNyce->Terminate() == true)
// 	{
// 		delete g_pNyce;
// 		return BACKSTAGE_OK;
// 	}
// 	else
// 		return BACKSTAGE_TERMINATE_FAIL;
	return 0;
}