// Backstage.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "BackstageInterface.h"
#include "Backstage.h"
#include <algorithm>

#define _USE_MATH_DEFINES
#include <math.h>


BACKSTAGE_API int WINAPI Initialize(const bool* const pbSim)
{
 	g_pNyce = new NyceSystem(*pbSim);
 	return g_pNyce->Status() == SYSTEM_INITIALIZED ? BACKSTAGE_OK : BACKSTAGE_INITALIZE_FAIL;
}

BACKSTAGE_API int WINAPI Terminate()
{
 	if(g_pNyce->Terminate() == true)
 	{
		map<string, vector<string>*>::iterator iter;
		while (g_mapNode2Axis.size() >0)
		{
			iter = g_mapNode2Axis.begin();
			delete iter->second;
			g_mapNode2Axis.erase(iter);
		}
		while (g_mapAxis2Node.size()>0)
			g_mapAxis2Node.erase(g_mapAxis2Node.begin());
 		delete g_pNyce;
 		return BACKSTAGE_OK;

 	}
 	else
 		return BACKSTAGE_TERMINATE_FAIL;
}

BACKSTAGE_API int WINAPI AddNode(char* name )
{
	string nodeName(name);
	for (map<string, vector<string>*>::iterator iter = g_mapNode2Axis.begin(); iter != g_mapNode2Axis.end(); ++iter)
		if(nodeName == iter->first)
			return BACKSTAGE_OK;
	if(!g_pNyce->AddNode(nodeName))
		return BACKSTAGE_ADDNODE_FAIL;
	g_mapNode2Axis[nodeName] = new vector<string>;
	return BACKSTAGE_OK;
}

BACKSTAGE_API int WINAPI AddAxis(char* noName,char* axName)
{
	string nodeName(noName),axisName(axName);
	if (AddNode(noName) != BACKSTAGE_OK)
		return BACKSTAGE_ADDAXIS_FAIL;	
	map<string, vector<string>*>::iterator iter = g_mapNode2Axis.find(nodeName);
	if (find(iter->second->begin(),iter->second->end(),axisName) != iter->second->end())
		return BACKSTAGE_OK;
	if (!g_pNyce->GetNode(nodeName)->AddAxis(axName))
		return BACKSTAGE_ADDAXIS_FAIL;
	g_mapNode2Axis[nodeName]->push_back(axisName);
	g_mapAxis2Node[axisName] = nodeName;
	return BACKSTAGE_OK;
}

BACKSTAGE_API int WINAPI AlignAxis(char* name)
{
	string axisName(name);
	if (!g_pNyce->GetNode(g_mapAxis2Node[axisName])->GetAxis(axisName)->Align())
		return BACKSTAGE_ALIGNAXIS_FAIL;
	return BACKSTAGE_OK;
}

BACKSTAGE_API int WINAPI HomeAxis(char* name)
{
	string axisName(name);
	if (!g_pNyce->GetNode(g_mapAxis2Node[axisName])->GetAxis(axisName)->Home())
		return BACKSTAGE_ALIGNAXIS_FAIL;
	return BACKSTAGE_OK;
}

BACKSTAGE_API int WINAPI ResetAxis(char* name)
{
	string axisName(name);
	if (!g_pNyce->GetNode(g_mapAxis2Node[axisName])->GetAxis(axisName)->Reset())
		return BACKSTAGE_ALIGNAXIS_FAIL;
	return BACKSTAGE_OK;
}

BACKSTAGE_API int WINAPI GetAxisPosition(char* name,double *value)
{
	string axisName(name);
	if (!g_pNyce->GetNode(g_mapAxis2Node[axisName])->GetAxis(axisName)->GetPosition(value))
		return BACKSTAGE_GETAXISPOS_FAIL;
	return BACKSTAGE_OK;
}

BACKSTAGE_API int WINAPI GetAxisStatus(char* name,char* pState)
{
	SAC_STATE state;
	string axisName(name);
	if (!g_pNyce->GetNode(g_mapAxis2Node[axisName])->GetAxis(axisName)->GetStatus(&state))
		return BACKSTAGE_GETAXISSTA_FAIL;
	switch(state)
	{
	case SAC_ERROR:
		pState = "SAC_ERROR";
		break;
	case SAC_FREE:
		pState = "SAC_FREE";
		break;
	case SAC_FREE_STOPPED:
		pState = "SAC_FREE_STOPPED";
		break;
	case SAC_IDLE:
		pState = "SAC_IDLE";
		break;
	case SAC_INACTIVE:
		pState = "SAC_INACTIVE";
		break;
	case SAC_MOVING:
		pState = "SAC_MOVING";
		break;
	case SAC_NO_STATE:
		pState = "SAC_NO_STATE";
		break;
	case SAC_READY:
		pState = "SAC_READY";
		break;
	case SAC_READY_STOPPED:
		pState = "SAC_READY_STOPPED";
		break;
	default:
		break;
	}
	return BACKSTAGE_OK;
}

BACKSTAGE_API int WINAPI GetAxisHomePars(char* name, double* pMaxSpeed,double* pMaxAcc,double* pMaxJerk)
{
	string axisName(name);
	if (!g_pNyce->GetNode(g_mapAxis2Node[axisName])->GetAxis(axisName)->GetHomePars(*pMaxSpeed,*pMaxAcc,*pMaxJerk))
		return BACKSTAGE_GETAXISHOMEPARS_FAIL;
	return BACKSTAGE_OK;
}

BACKSTAGE_API int WINAPI SetAxisHomePars(char* name,double dMaxSpeed,double dMaxAcc,double dMaxJerk)
{ 
	string axisName(name);
	if (!g_pNyce->GetNode(g_mapAxis2Node[axisName])->GetAxis(axisName)->SetHomePars(dMaxSpeed,dMaxAcc,dMaxJerk))
		return BACKSTAGE_SETAXISHOMEPARS_FAIL;
	return BACKSTAGE_OK;
}

EXTERN_C BACKSTAGE_API int WINAPI GetAxisMotionPars(char* name, double* dMaxSpeed,double* dMaxAcc,double* dMaxJerk)
{
	string axisName(name);
	if (!g_pNyce->GetNode(g_mapAxis2Node[axisName])->GetAxis(axisName)->GetMotionPars(*dMaxSpeed,*dMaxAcc,*dMaxJerk))
		return BACKSTAGE_GETAXISMOTIONPARS_FAIL;
	return BACKSTAGE_OK;
}
EXTERN_C BACKSTAGE_API int WINAPI SetAxisMotionPars(char* name, double dMaxSpeed,double dMaxAcc,double dMaxJerk)
{
	string axisName(name);
	if (!g_pNyce->GetNode(g_mapAxis2Node[axisName])->GetAxis(axisName)->SetMotionPars(dMaxSpeed,dMaxAcc,dMaxJerk))
		return BACKSTAGE_SETAXISMOTIONPARS_FAIL;
	return BACKSTAGE_OK;
}
EXTERN_C BACKSTAGE_API int WINAPI GetAxisStopPars(char* name, double* dStopAcc)
{
	string axisName(name);
	if (!g_pNyce->GetNode(g_mapAxis2Node[axisName])->GetAxis(axisName)->GetStopPars(*dStopAcc))
		return BACKSTAGE_GETAXISSTOPPARS_FAIL;
	return BACKSTAGE_OK;
}
EXTERN_C BACKSTAGE_API int WINAPI SetAxisStopPars(char* name, double dStopAcc)
{
	string axisName(name);
	if (!g_pNyce->GetNode(g_mapAxis2Node[axisName])->GetAxis(axisName)->SetStopPars(dStopAcc))
		return BACKSTAGE_SETAXISSTOPPARS_FAIL;
	return BACKSTAGE_OK;
}
BACKSTAGE_API int WINAPI GetInSeg_Circle(const double *dCurX, const double *dCurY, const double *dRadius,IN_SED_PRT const pSegments,const int * segSum)
{
	//¡Ÿ ±¥˙¬Î
	if(g_mapAxis2Node.size() < 2)
		return BACKSTAGE_GETINSEG_FAIL;
	AXIS_INFO axisArray[2];
	axisArray[0].nodeName = axisArray[1].nodeName = g_mapNode2Axis.begin()->first;
	axisArray[0].axisName = g_mapAxis2Node.begin()->first;
	axisArray[1].axisName = (++g_mapAxis2Node.begin())->first;
	IN_INFO in_info;
	ZeroMemory(&in_info,sizeof(IN_INFO));
	in_info.dCurPosX = *dCurX;
	in_info.dCurPosY = *dCurY;
	in_info.dRadius = *dRadius;
	in_info.iSegAmount = *segSum;
	if( !g_pNyce->SetInAxis(axisArray,2)				||
		!g_pNyce->GetInSeg_Cicle_xy(&in_info,pSegments)	)
		return BACKSTAGE_GETINSEG_FAIL;
	return BACKSTAGE_OK;
}

BACKSTAGE_API int WINAPI MoveInterpolating(IN_SED_PRT pSegments,const int iSum,const bool bAbsolute = true)
{
	if(!g_pNyce->MoveInterpolating(pSegments,iSum,bAbsolute))
		return BACKSTAGE_MOVEINTERLOPATE_FAIL;
	return BACKSTAGE_OK;
}

BACKSTAGE_API int WINAPI RocksArcInterpolation(char* node,char* axisX,char* axisY1,char* axisY2,char* axisZ,double dCenterX,double dCenterY,double dTime,double dAngle= 0.0)
{
	GANTRY_INFO gantryInfo;
	gantryInfo.sNodeName    = node;
	gantryInfo.sAxisName_x  = axisX;
	gantryInfo.sAxisName_y1 = axisY1;
	gantryInfo.sAxisName_y2 = axisY2;
	gantryInfo.sAxisName_z  = axisZ;
	if (!g_pNyce->RocksGantryInitialize(&gantryInfo))
		return false;
	POS center;
	center.dX = dCenterX;
	center.dY = dCenterY;
	if (!g_pNyce->RocksGantryArcInterpolation(center,dTime))
		return false;
	return BACKSTAGE_OK;
}