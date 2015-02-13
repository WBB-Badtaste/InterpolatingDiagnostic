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

BACKSTAGE_API int WINAPI MoveInterpolating(const double *dCurX, const double *dCurY, const double *dRadius,IN_SED_PRT const pSegments,const int * segSum)
{
	IN_SED_PRT ptr(nullptr);
	double dDistance_x(*dCurX),dDistance_y(*dCurY),dVel_x(0.0),dVel_y(0.0),dTime(0.0),dTime_x(0.0),dTime_y(0.0),dAcc_x(0.0),dAcc_y(0.0);
	const string &nodeName(g_mapNode2Axis.begin()->first);
	const string &axisName_x(g_mapAxis2Node.begin()->first);
	const string &axisName_y((g_mapAxis2Node.begin()++)->first);
	double dAngle(0.0),dLastVel_x(0.0),dLastVel_y(0.0);
	for (int i = 0; i < *segSum; ++i)
	{
		dAngle = 2.0 * M_PI / *segSum * ((double)i + 1.0);
		dDistance_x = *dCurX - *dRadius * cos(dAngle) - dDistance_x;
		dDistance_y = *dCurY + *dRadius * sin(dAngle) - dDistance_y;
		dLastVel_x = dVel_x;
		dLastVel_y = dVel_y;
		g_pNyce->GetNode(nodeName)->GetAxis(axisName_x)->GetInSegPars(dDistance_x,dVel_x,dAcc_x,dTime_x);
		g_pNyce->GetNode(nodeName)->GetAxis(axisName_x)->GetInSegPars(dDistance_y,dVel_y,dAcc_y,dTime_y);
		dTime = dTime_x;
		if (dTime_x > dTime_y)
		{
			dTime = dTime_x;
			dVel_y = dVel_x * atan(dAngle);
			dAcc_y = (dVel_y - dLastVel_y) / dTime;
		}
		if (dTime_y > dTime_x)
		{
			dTime = dTime_y;
			dVel_x = dVel_y * atan(dAngle);
			dAcc_x = (dVel_x - dLastVel_x) / dTime;
		}
		ptr = pSegments + i;
		ptr->iNo = i;
		ptr->dPosX = dDistance_x;
		ptr->dPosY = dDistance_y;
		ptr->dTime = dTime;
		ptr->dVel = sqrt(dVel_x * dVel_x + dVel_y * dVel_y);
	}
	return BACKSTAGE_OK;
}