#pragma once

#include "Types.h"
#include <process.h>
#include <math.h>
#include <string>
//#include "../gsl/gsl_poly.h"

using namespace std;
//轴参数子集
typedef class MotionStatus
{
public:
	MotionStatus():
		  dVel(0.0),
		  dAcc(0.0),
		  dJerk(0.0){}
	double dVel;
	double dAcc;
	double dJerk;
}MOTION_STATUS;

//位置坐标
typedef class Position
{
public:
	Position():
		  dX(0.0),
		  dY(0.0),
		  dZ(0.0){}
	double dX;
	double dY;
	double dZ;
}POSITION;

//状态信息
typedef class Status
{
public:
	POSITION	 position;
	MotionStatus motionStatus;
}STATUS;

//PathSegmenet
typedef class PathSegment
{
public:
	PathSegment():
	    dPosition(0.0),
		dVelocity(0.0){}
	double dPosition;
	double dVelocity;
}PATH_SEG;

//圆弧路径描述
typedef class ArcPars
{
public:
	ArcPars():
		dSplineTime(0.0),
		dAngle(0.0),
		dMaxVel(0.0),
		dExtraVel(0.0){}
	double dSplineTime;//分段时间间隔
	double dAngle;//算转角度，正为顺时针，负为逆时针
	double dMaxVel;
	double dExtraVel;//速度增益
	POSITION centerPos;
	STATUS startStatus;
	STATUS endStatus;
}ARC_PARS;

//路径指针
static PATH_SEG* pPathSeg(nullptr);
static int iPathSegSum(0);
static ARC_PARS arcPars;

static POSITION center;
static double dRadius;

double Factorial(double x)
{
	double y = 1;
	while (x)
		y *= x--;
	return y;
}

//生成圆弧规划路径
static bool GenerateArcPath(const ARC_PARS * const pArcPars)
{
	if (pArcPars->dExtraVel	  <= 0 ||
		pArcPars->dAngle	  == 0 ||
		pArcPars->dMaxVel	  <= 0 ||
		pArcPars->dSplineTime <= 0 )
		return false;

	const double &cdVelS(pArcPars->startStatus.motionStatus.dVel);
	const double &cdVelE(pArcPars->endStatus.motionStatus.dVel);
	 double dMaxVel(pArcPars->dMaxVel);
	const double &cdAngle(pArcPars->dAngle);
	const double &cdSplineTime(pArcPars->dSplineTime);
	/*********************************************

		注意：
			允许始末速度大于Vmax，Vmax是一个基准值

	 *********************************************/
 	const double cdRadius(sqrt(pow(pArcPars->centerPos.dX - pArcPars->startStatus.position.dX,2.0) + pow(pArcPars->centerPos.dY -pArcPars->startStatus.position.dY,2.0) + pow(pArcPars->centerPos.dZ - pArcPars->startStatus.position.dZ,2.0)));
	const double cdDistance(cdAngle * cdRadius);
	const double cdDiffVelAcc(dMaxVel - cdVelS);
	const double cdDiffVelDec(cdVelE - dMaxVel);
 	const double cdKAcc(cdDiffVelAcc > 0 ? pArcPars->dExtraVel : -pArcPars->dExtraVel);
 	const double cdKDec(cdDiffVelDec > 0 ? pArcPars->dExtraVel : -pArcPars->dExtraVel);

	double dTimeAccOne(pow(cdDiffVelAcc / cdKAcc, 1.0 / 2.0));
	double dTimeAccTwo(pow(cdDiffVelAcc / cdKAcc, 1.0 / 2.0));
	double dTimeUin(0.0);
	double dTimeDecOne(pow(cdDiffVelDec / cdKDec, 1.0 / 2.0));
	double dTimeDecTwo(pow(cdDiffVelDec / cdKDec, 1.0 / 2.0));

	double dMidAAcc(cdKAcc * dTimeAccOne);
	double dMidADec(cdKDec * dTimeDecOne);
	double dMidVAcc(cdVelS + 0.5 * cdKAcc * dTimeAccOne * dTimeAccOne);
	double dMidVDec(dMaxVel + 0.5 * cdKDec * dTimeDecOne * dTimeDecOne);

	double cdDisAcc1(cdVelS * dTimeAccOne + cdKAcc * dTimeAccOne * dTimeAccOne * dTimeAccOne / 6.0);
	double cdDisAcc2(dMidVAcc * dTimeAccTwo + 0.5 * dMidAAcc * dTimeAccTwo * dTimeAccTwo - cdKAcc * dTimeAccTwo * dTimeAccTwo * dTimeAccTwo / 6.0);
	double cdDisDec1(dMaxVel * dTimeDecOne + cdKDec * dTimeDecOne * dTimeDecOne * dTimeDecOne / 6.0);
	double cdDisDec2(dMidVDec * dTimeDecTwo + 0.5 * dMidADec * dTimeDecTwo *dTimeDecTwo - cdKDec * dTimeDecTwo * dTimeDecTwo * dTimeDecTwo / 6.0);
 	if (cdDisAcc1 + cdDisAcc2 + cdDisDec1 + cdDisDec2 > cdDistance)
	{
		;
	}
	else
		dTimeUin = (cdDistance - (cdDisAcc1 + cdDisAcc2 + cdDisDec1 + cdDisDec2)) / dMaxVel;

	const double cdAccelecteMidTimePoint(dTimeAccOne);
	const double cdUinformTimePoint(dTimeAccOne + dTimeAccTwo);
	const double cdDecelerateTimePoint(cdUinformTimePoint + dTimeUin);
	const double cdDecelerateMidTimePoint(cdDecelerateTimePoint + dTimeDecOne);
	const double cdCompleteTimePoint(cdDecelerateMidTimePoint + dTimeDecTwo);

	const double cdAccelecteMidPosition(cdDisAcc1);
	const double cdUinformPosition(cdDisAcc1 + cdDisAcc2);
	const double cdDeceleratePosition(cdUinformPosition + dMaxVel * dTimeUin);
	const double cdDecelerateMidPosition(cdDeceleratePosition + cdDisDec1);
	const double cdCompletePosition(cdDecelerateMidPosition + cdDisDec2); 
	/****************************************

		注意：
			iPathSegSum由double显式转换成int时，
			可能出现一个较大的误差。现在将可容
			忍的误差阈值设置成0.05s，超过此值
			将多加一段。

	 ****************************************/
	const double dPathSegSum(cdCompleteTimePoint / cdSplineTime);
	iPathSegSum = dPathSegSum == (int)dPathSegSum ? ((int)dPathSegSum + 1) : ((int)dPathSegSum + 2);
	 
	pPathSeg = new PATH_SEG[iPathSegSum];
	int index = 0;
	for (;index < iPathSegSum - 1; ++index)
	{
		double dPassTime((double)index * cdSplineTime);
		PATH_SEG *pSeg(pPathSeg + index);
		if (dPassTime <= cdAccelecteMidTimePoint)
		{
			double dAccelecteTimeOne(dPassTime);
			pSeg->dPosition = cdVelS * dAccelecteTimeOne + cdKAcc * dAccelecteTimeOne * dAccelecteTimeOne * dAccelecteTimeOne / 6.0;
			pSeg->dVelocity = cdVelS + 0.5 * cdKAcc * dAccelecteTimeOne * dAccelecteTimeOne;
			continue;
		}
		if (dPassTime <= cdUinformTimePoint)
		{
			double dAccelecteTimeTwo(dPassTime - cdAccelecteMidTimePoint);
			pSeg->dPosition = cdAccelecteMidPosition + dMidVAcc * dAccelecteTimeTwo + 0.5 * dMidAAcc * dAccelecteTimeTwo * dAccelecteTimeTwo - cdKAcc * dAccelecteTimeTwo * dAccelecteTimeTwo * dAccelecteTimeTwo / 6.0;
			pSeg->dVelocity = dMidVAcc + dMidAAcc * dAccelecteTimeTwo - 0.5 * cdKAcc * dAccelecteTimeTwo * dAccelecteTimeTwo;
			continue;
		}
		if (dPassTime <= cdDecelerateTimePoint)
		{
			double dUniformTime(dPassTime - cdUinformTimePoint);
			pSeg->dPosition = cdUinformPosition + dMaxVel * dUniformTime;
			pSeg->dVelocity = dMaxVel;
			continue;
		}
		if (dPassTime <= cdDecelerateMidTimePoint)
		{
			double dDecelerateTimeOne(dPassTime - cdDecelerateTimePoint);
			pSeg->dPosition = cdDeceleratePosition + dMaxVel * dDecelerateTimeOne + cdKDec * dDecelerateTimeOne * dDecelerateTimeOne * dDecelerateTimeOne / 6.0;
			pSeg->dVelocity = dMaxVel + 0.5 * cdKDec * dDecelerateTimeOne * dDecelerateTimeOne;
			continue;
		}
		if (dPassTime <= cdCompleteTimePoint)
		{
			double dDecelerateTimeTwo(dPassTime - cdDecelerateMidTimePoint); 
			pSeg->dPosition = cdDecelerateMidPosition + dMidVDec * dDecelerateTimeTwo + 0.5 * dMidADec * dDecelerateTimeTwo * dDecelerateTimeTwo - cdKDec * dDecelerateTimeTwo * dDecelerateTimeTwo * dDecelerateTimeTwo / 6.0;
			pSeg->dVelocity = dMidVDec + dMidADec * dDecelerateTimeTwo - 0.5 * cdKDec * dDecelerateTimeTwo * dDecelerateTimeTwo;
			continue;
		}
		return false;//算法错误，不可能出现大于cdCompleteTimePoint的情况		
	}
	PATH_SEG *pSeg(pPathSeg + index);
	pSeg->dPosition = cdCompletePosition;
	pSeg->dVelocity = cdVelE;

	dRadius = cdRadius;
	return true;
}

typedef class KinematicsPars
{
public:
	KinematicsPars():
			nrOfJoints(0)
	  {ZeroMemory(jointAxisId,10);}
	uint32_t nrOfJoints;
	uint32_t jointAxisId[10];
}KIN_PARS;

typedef struct StreamThreadInformation
{
	SAC_CUB_PARS *pCubPars_x,*pCubPars_y,*pCubPars_z;
	KIN_PARS kinPars;
}STREAM_TH_INFO;

static unsigned WINAPI StreamThread( LPVOID lpParameter )
{
	STREAM_TH_INFO *pInfo=(STREAM_TH_INFO*)lpParameter;

	uint32_t uGroundId;
	NYCE_STATUS status;
	string strStatus;
	status = MacDefineSyncGroup(pInfo->kinPars.jointAxisId, pInfo->kinPars.nrOfJoints, &uGroundId);
	if (status != NYCE_OK)
	{
		strStatus =NyceGetStatusString(status);
		return false;
	}
	if (SacClearInterpolantBuffer(pInfo->kinPars.jointAxisId[0])							  != NYCE_OK) 
		return false;
	if (SacClearInterpolantBuffer(pInfo->kinPars.jointAxisId[1])							  != NYCE_OK) 
		return false;
	for (int sum = iPathSegSum,i = 0; sum>0; sum -= 16, ++i)
	{
		if (i * 16 > 200)
		break;
		if (sum > 16)
		{
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[0],16,pInfo->pCubPars_x + 16 * i) !=NYCE_OK)
				return false;
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[1],16,pInfo->pCubPars_y + 16 * i) !=NYCE_OK)
				return false;
		}
		else
		{
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[0],sum,pInfo->pCubPars_x + 16 * i) !=NYCE_OK)
				return false;
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[1],sum,pInfo->pCubPars_y + 16 * i) !=NYCE_OK)
				return false;
		}
	}
	if (SacStopInterpolation(pInfo->kinPars.jointAxisId[0]) != NYCE_OK)
		return false;
	if (SacStopInterpolation(pInfo->kinPars.jointAxisId[1]) != NYCE_OK)
		return false;
	if (SacStartInterpolation(pInfo->kinPars.jointAxisId[0]) != NYCE_OK)
		return false;
	if (SacStartInterpolation(pInfo->kinPars.jointAxisId[1]) != NYCE_OK)
		return false;
	if(MacStartSyncGroup(uGroundId,MAC_SYNC_MOTION) != NYCE_OK) 
		return false;
	if(MacDeleteSyncGroup(uGroundId)			    != NYCE_OK) 
		return false;
	
	delete[] pPathSeg;
	delete[] pInfo->pCubPars_x;
	delete[] pInfo->pCubPars_y;
	delete[] pInfo->pCubPars_z;
	delete pInfo;

	return 0;
}

struct dataToEvent
{
	int *pIndex;
	STREAM_TH_INFO *pInfo;
};

void OnInterpolantEvent( NYCE_ID nyceId, NYCE_EVENT eventId, NYCE_EVENT_DATA *pEventData, void *pUserData )
{
	dataToEvent *pData = (dataToEvent *)pUserData;
	int &index(*pData->pIndex);
	STREAM_TH_INFO *pInfo = pData->pInfo;
	bool bBegin = false;
	for (; index < iPathSegSum; index += 16)
	{
		if (index % 96 == 0)
			if (bBegin)
				break;
			else 
				bBegin = true;
		
		if (iPathSegSum - index > 16)
		{
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[0],16,pInfo->pCubPars_x + index) !=NYCE_OK)
				return ;
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[1],16,pInfo->pCubPars_y + index) !=NYCE_OK)
				return ;
		}
		else
		{
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[0],iPathSegSum - index,pInfo->pCubPars_x + index) !=NYCE_OK)
				return ;
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[1],iPathSegSum - index,pInfo->pCubPars_y + index) !=NYCE_OK)
				return ;
			if (SacStopInterpolation(pInfo->kinPars.jointAxisId[0]) != NYCE_OK)
				return ;
			if (SacStopInterpolation(pInfo->kinPars.jointAxisId[1]) != NYCE_OK)
				return ;
		}
	}
}

#include <fstream>
#include <iostream>
#define ADDR "..\\test.txt"

//生成spline
static bool PathConverToSpline(KIN_PARS *const pKinPars)
{
	ofstream file(ADDR);

	STREAM_TH_INFO *pInfo = new STREAM_TH_INFO();
	pInfo->pCubPars_x = new SAC_CUB_PARS[iPathSegSum]();
	pInfo->pCubPars_y = new SAC_CUB_PARS[iPathSegSum]();
	pInfo->pCubPars_z = new SAC_CUB_PARS[iPathSegSum]();
	pInfo->kinPars.jointAxisId[0] = pKinPars->jointAxisId[0];
	pInfo->kinPars.jointAxisId[1] = pKinPars->jointAxisId[1];
	pInfo->kinPars.nrOfJoints = pKinPars->nrOfJoints;
	double posX, posY;
	SacReadVariable(pInfo->kinPars.jointAxisId[0], SAC_VAR_AXIS_POS, &posX);
	SacReadVariable(pInfo->kinPars.jointAxisId[1], SAC_VAR_AXIS_POS, &posY);

	//file<<setfill(0)<<setiosflags(ios::fixed)<<setiosflags(ios::showpos)<<setw(10);
	for (int index = 0; index < iPathSegSum; ++index)
	{
		PATH_SEG *pSeg(pPathSeg + index);
		double dAngle(pSeg->dPosition / dRadius);

		file<<"index:"<<setw(3)<<index<<" angle:"<<setw(8)<<dAngle<<"    pos_e:"<<setiosflags(ios::fixed)<<setw(10)<<pSeg->dPosition<<"    vel_e:"<<setw(10)<<pSeg->dVelocity;

		SAC_CUB_PARS *pCubPars(pInfo->pCubPars_x + index);
		pCubPars->splineId = index;
		pCubPars->position = posX + dRadius - dRadius * cos(dAngle);
		pCubPars->positionReference = SAC_ABSOLUTE;
		pCubPars->time = 0.1;
		pCubPars->velocity = pSeg->dVelocity * sin(dAngle);
		if (index % 96 == 0)
			pCubPars->generateEvent = TRUE;
		else
			pCubPars->generateEvent = FALSE;
			

		file<<"    pos_x:"<<setw(10)<<pCubPars->position<<"    vel_x:"<<setw(10)<<pCubPars->velocity;

		pCubPars = pInfo->pCubPars_y + index;
		pCubPars->splineId = index;
		pCubPars->position = posY + dRadius * sin(dAngle);
		pCubPars->positionReference = SAC_ABSOLUTE;
		pCubPars->time = 0.1;
		pCubPars->velocity = pSeg->dVelocity * cos(dAngle);
		if (index % 96 == 0)
			pCubPars->generateEvent = TRUE;
		else
			pCubPars->generateEvent = FALSE;

		file<<"    pos_y:"<<setw(10)<<pCubPars->position<<"    vel_y:"<<setw(10)<<pCubPars->velocity<<endl;

	}

	file.close();

//	HANDLE h=(HANDLE)_beginthreadex(NULL,0,StreamThread,pInfo,0,NULL);
	
	uint32_t uGroundId;
	NYCE_STATUS status;
	string strStatus;
	status = MacDefineSyncGroup(pInfo->kinPars.jointAxisId, pInfo->kinPars.nrOfJoints, &uGroundId);
	if (status != NYCE_OK)
	{
		strStatus =NyceGetStatusString(status);
		return false;
	}
	if (SacClearInterpolantBuffer(pInfo->kinPars.jointAxisId[0])							  != NYCE_OK) 
		return false;
	if (SacClearInterpolantBuffer(pInfo->kinPars.jointAxisId[1])							  != NYCE_OK) 
		return false;
	int index = 0;
	bool bBegin = false;
	for (; index < iPathSegSum; index += 16)
	{
		if (index % 96 == 0)
			if (bBegin)
				break;
			else
				bBegin = true;

		if (iPathSegSum - index > 16)
		{
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[0],16,pInfo->pCubPars_x + index) !=NYCE_OK)
				return false;
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[1],16,pInfo->pCubPars_y + index) !=NYCE_OK)
				return false;
		}
		else
		{
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[0],iPathSegSum - index,pInfo->pCubPars_x + index) !=NYCE_OK)
				return false;
			if(SacWriteCubicIntBuffer(pInfo->kinPars.jointAxisId[1],iPathSegSum - index,pInfo->pCubPars_y + index) !=NYCE_OK)
				return false;
			if (SacStopInterpolation(pInfo->kinPars.jointAxisId[0]) != NYCE_OK)
				return false;
			if (SacStopInterpolation(pInfo->kinPars.jointAxisId[1]) != NYCE_OK)
				return false;
		}
	}

	dataToEvent data;
	data.pIndex = &index;
	data.pInfo = pInfo;

	if(SacDefineEventEnrolment(pInfo->kinPars.jointAxisId[0], SAC_EV_INTERPOLANT_STARTED, OnInterpolantEvent, (void * )&data) != NYCE_OK)
		return false;
	if (SacStartInterpolation(pInfo->kinPars.jointAxisId[0]) != NYCE_OK)
		return false;
	if (SacStartInterpolation(pInfo->kinPars.jointAxisId[1]) != NYCE_OK)
		return false;
	if(MacStartSyncGroup(uGroundId,MAC_SYNC_MOTION) != NYCE_OK) 
		return false;

	Sleep(100000);
// 	string str;
// 	status = SacSynchronize(pInfo->kinPars.jointAxisId[0], SAC_REQ_MOTION_STOPPED, INFINITE);
// 	if (status != NYCE_OK)
// 	{
// 		str = NyceGetStatusString(status);
// 	}
// 	status = SacSynchronize(pInfo->kinPars.jointAxisId[1], SAC_REQ_MOTION_STOPPED, INFINITE);
// 	if (status != NYCE_OK)
// 	{
// 		str = NyceGetStatusString(status);
// 	}

//  	if(SacSynchronize(pInfo->kinPars.jointAxisId[0], SAC_REQ_MOTION_STOPPED, INFINITE) != NYCE_OK) 
//  		return false;
//  	if(SacSynchronize(pInfo->kinPars.jointAxisId[1], SAC_REQ_MOTION_STOPPED, INFINITE) != NYCE_OK) 
//  		return false;

// 	if(SacDeleteEventEnrolment(pInfo->kinPars.jointAxisId[0], SAC_EV_INTERPOLANT_STARTED, OnInterpolantEvent, NULL) != NYCE_OK)
// 		return false;
// 	if(MacDeleteSyncGroup(uGroundId)			    != NYCE_OK) 
// 		return false;
// 
// 	delete[] pPathSeg;
// 	delete[] pInfo->pCubPars_x;
// 	delete[] pInfo->pCubPars_y;
// 	delete[] pInfo->pCubPars_z;
// 	delete pInfo;

	return true;
} 


