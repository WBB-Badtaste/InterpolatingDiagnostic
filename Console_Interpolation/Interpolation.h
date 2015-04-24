#pragma once

#include "Types.h"
#include <process.h>
#include <math.h>
#include <string>
//#include "../gsl/gsl_poly.h"

#define LEVEL 7.0

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

	double fac1 = Factorial(LEVEL - 1.0);
	double fac2 = Factorial(LEVEL);

	const double &cdVelS(pArcPars->startStatus.motionStatus.dVel);
	const double &cdVelE(pArcPars->endStatus.motionStatus.dVel);
	const double &cdMaxVel(pArcPars->dMaxVel);
	const double &cdAngle(pArcPars->dAngle);
	const double &cdSplineTime(pArcPars->dSplineTime);
	/*********************************************

		注意：
			允许始末速度大于Vmax，Vmax是一个基准值

	 *********************************************/
 	const double cdRadius(sqrt(pow(pArcPars->centerPos.dX - pArcPars->startStatus.position.dX,2.0) + pow(pArcPars->centerPos.dY -pArcPars->startStatus.position.dY,2.0) + pow(pArcPars->centerPos.dZ - pArcPars->startStatus.position.dZ,2.0)));
	const double cdDistance(cdAngle * cdRadius);
	const double cdDiffVelAcc(cdMaxVel - cdVelS);
	const double cdDiffVelDec(cdVelE - cdMaxVel);
 	const double cdKAcc(cdDiffVelAcc > 0 ? pArcPars->dExtraVel : -pArcPars->dExtraVel);
 	const double cdKDec(cdDiffVelDec > 0 ? pArcPars->dExtraVel : -pArcPars->dExtraVel);

	double dTimeAcc(pow(cdDiffVelAcc * fac1 / cdKAcc, 1.0 / (LEVEL - 1.0)));
	double dTimeUin(0.0);
	double dTimeDec(pow(cdDiffVelDec * fac1 / cdKDec, 1.0 / (LEVEL - 1.0)));

	/***********************************

		注意：
			这里的加速过程是合速度匀加加加加速
			加速度由用户决定

	 ***********************************/

	double cdDisAcc(cdVelS * dTimeAcc + cdKAcc * pow(dTimeAcc, LEVEL) /  fac2);
	double cdDisDec(cdMaxVel * dTimeDec + cdKDec * pow(dTimeDec, LEVEL) /  fac2);
 	if (cdDisAcc + cdDisDec > cdDistance)
	{
		
		/*****************************************************

			不能达到最大速度，调整时间
				解方程组：Vs*T1+0.5*A1*T1^2=Ve*T2-0.5*A2*T2^2
								   Vs+A1*T1=Ve-A2*T2

		 *****************************************************/
		const double cdF1(cdKDec / cdKAcc);
		const double cdF2(cdVelE - cdVelS);
		double dSol1(0.0),dSol2(0.0);
		int res = 0;
//		int res = gsl_poly_solve_quadratic((1.0 + cdF1) * cdKDec * 0.5, cdF1 * cdVelS + cdF1 * cdF2 + cdVelE, cdVelS / cdKAcc * cdF2 + cdF2 * cdF2 / cdKAcc *0.5, &dSol1, &dSol2);
		if (res == 0) return false;//无解
		if (res == 1) dTimeDec = dSol1;
		if (res == 2) dTimeDec = dSol1 > 0 ? dSol1 : dSol2;
		dTimeAcc = (cdVelE - cdVelS - cdKDec * dTimeDec) / cdKAcc;
	}
	else
		dTimeUin = (cdDistance - cdDisAcc - cdDisDec) / cdMaxVel;

	const double dUinformTimePoint(dTimeAcc);
	const double dDecelerateTimePoint(dTimeAcc + dTimeUin);
	const double dCompleteTimePoint(dTimeAcc + dTimeUin + dTimeDec);
	const double dUinformPosition(cdDisAcc);
	const double dDeceleratePosition(cdDistance - cdDisDec);
	const double dCompletePosition(cdDistance); 
	/****************************************

		注意：
			iPathSegSum由double显式转换成int时，
			可能出现一个较大的误差。现在将可容
			忍的误差阈值设置成0.05s，超过此值
			将多加一段。

	 ****************************************/
	const double dPathSegSum(dCompleteTimePoint / cdSplineTime);
	iPathSegSum = dPathSegSum == (int)dPathSegSum ? ((int)dPathSegSum + 1) : ((int)dPathSegSum + 2);
	 
	pPathSeg = new PATH_SEG[iPathSegSum];
	int index = 0;
	for (;index < iPathSegSum - 1; ++index)
	{
		double dPassTime((double)index * cdSplineTime);
		PATH_SEG *pSeg(pPathSeg + index);
		if (dPassTime <= dUinformTimePoint)
		{
			pSeg->dPosition = cdVelS * dPassTime + cdKAcc * pow(dPassTime, LEVEL) /  fac2;
			pSeg->dVelocity = cdVelS + cdKAcc * pow(dPassTime, LEVEL - 1.0) / fac1;
			continue;
		}
		if (dPassTime <= dDecelerateTimePoint)
		{
			double dUniformTime(dPassTime - dUinformTimePoint);
			pSeg->dPosition = dUinformPosition + cdMaxVel * dUniformTime;
			pSeg->dVelocity = cdMaxVel;
			continue;
		}
		if (dPassTime <= dCompleteTimePoint)
		{
			double dDecelerateTime(dPassTime - dDecelerateTimePoint);
			pSeg->dPosition = dDeceleratePosition + (cdMaxVel * dDecelerateTime + cdKDec * pow(dDecelerateTime, LEVEL) / fac2);
			pSeg->dVelocity = cdMaxVel + cdKDec * pow(dDecelerateTime, LEVEL - 1.0) /  fac1;
			continue;
		}
		return false;//算法错误，不可能出现大于dCompleteTimePoint的情况		
	}
	PATH_SEG *pSeg(pPathSeg + index);
	pSeg->dPosition = dCompletePosition;
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
		pCubPars->generateEvent = FALSE;

		file<<"    pos_x:"<<setw(10)<<pCubPars->position<<"    vel_x:"<<setw(10)<<pCubPars->velocity;

		pCubPars = pInfo->pCubPars_y + index;
		pCubPars->splineId = index;
		pCubPars->position = posY + dRadius * sin(dAngle);
		pCubPars->positionReference = SAC_ABSOLUTE;
		pCubPars->time = 0.1;
		pCubPars->velocity = pSeg->dVelocity * cos(dAngle);
		pCubPars->generateEvent = FALSE;

		file<<"    pos_y:"<<setw(10)<<pCubPars->position<<"    vel_y:"<<setw(10)<<pCubPars->velocity<<endl;

	}

	file.close();

	HANDLE h=(HANDLE)_beginthreadex(NULL,0,StreamThread,pInfo,0,NULL);
	
	return true;
} 


