#pragma once

#include "Types.h"

#include "gsl/gsl_poly.h"

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
static POSITION center;
static double dRadius;

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
	const double &cdMaxVel(pArcPars->dMaxVel);
	const double &cdAngle(pArcPars->dAngle);
	const double &cdSplineTime(pArcPars->dSplineTime);
	/*********************************************

		注意：
			允许始末速度大于Vmax，Vmax是一个基准值

	 *********************************************/
 	const double cdRadius(sqrt(pow(pArcPars->centerPos.dX - pArcPars->startStatus.position.dX,2.0) + pow(pArcPars->centerPos.dY -pArcPars->startStatus.position.dY,2.0) + pow(pArcPars->centerPos.dZ - pArcPars->startStatus.position.dZ,2.0)));
	const double cdDistance(cdAngle * cdRadius);
	const double cdDiffVel1(cdMaxVel - cdVelS);
	const double cdDiffVel2(cdVelE - cdMaxVel);
	const double cdAcc1(cdDiffVel1 > 0 ? pArcPars->dExtraVel : -pArcPars->dExtraVel);
	const double cdAcc2(cdDiffVel2 > 0 ? pArcPars->dExtraVel : -pArcPars->dExtraVel);

	double dTime1(cdDiffVel1 / cdAcc1);
	double dTime2(0.0);
	double dTime3(cdDiffVel2 / cdAcc2);

	/***********************************

		注意：
			这里的加速过程是合速度匀加速
			加速度由用户决定

	 ***********************************/
	double cdDis1(cdVelS * dTime1 + 0.5 * cdAcc1 * dTime1 * dTime1);
	double cdDis2(cdMaxVel * dTime2 +0.5 * cdAcc2 * dTime2 * dTime2);
 	if (cdDis1 + cdDis2 > cdDistance)
	{
		/*****************************************************

			不能达到最大速度，调整时间
				解方程组：Vs*T1+0.5*A1*T1^2=Ve*T2-0.5*A2*T2^2
								   Vs+A1*T1=Ve-A2*T2

		 *****************************************************/
		const double cdF1(cdAcc2 / cdAcc1);
		const double cdF2(cdVelE - cdVelS);
		double dSol1(0.0),dSol2(0.0);
		int res = gsl_poly_solve_quadratic((1.0 + cdF1) * cdAcc2 * 0.5, cdF1 * cdVelS + cdF1 * cdF2 + cdVelE, cdVelS / cdAcc1 * cdF2 + cdF2 * cdF2 / cdAcc1 *0.5, &dSol1, &dSol2);
		if (res == 0) return false;//无解
		if (res == 1) dTime3 = dSol1;
		if (res == 2) dTime3 = dSol1 > 0 ? dSol1 : dSol2;
		dTime1 = (cdVelE - cdVelS - cdAcc2 * dTime3) / cdAcc1;
	}
	else
		double dTime3((cdDistance - cdDis1 -cdDis2) / cdMaxVel);

	const double dUinformTimePoint(dTime1);
	const double dDecelerateTimePoint(dTime1 + dTime2);
	const double dCompleteTimePoint(dTime1 + dTime2 + dTime3);
	const double dUinformPosition(cdDis1);
	const double dDeceleratePosition(cdDistance - cdDis2);
	const double dCompletePosition(cdDistance);
	/****************************************

		注意：
			iPathSegSum由double显式转换成int时，
			可能出现一个较大的误差。现在将可容
			忍的误差阈值设置成0.05s，超过此值
			将多加一段。

	 ****************************************/
	const double dPathSegSum(dCompleteTimePoint / cdSplineTime);
	iPathSegSum = (int)dPathSegSum;
	if (dPathSegSum - (double)iPathSegSum >= 0.05)
		++iPathSegSum;
	++iPathSegSum;//算上起始点

	pPathSeg = new PATH_SEG[iPathSegSum];
	int index = 0;
	for (;index < iPathSegSum - 1; ++index)
	{
		double dPassTime((double)index * cdSplineTime);
		PATH_SEG *pSeg(pPathSeg + index);
		if (dPassTime <= dUinformTimePoint)
		{
			pSeg->dPosition = cdVelS * dPassTime + 0.5 * cdAcc1 * dPassTime * dPassTime;
			pSeg->dVelocity = cdVelS + cdAcc1 * dPassTime;
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
			pSeg->dPosition = dCompletePosition - (cdVelE * dDecelerateTime - 0.5 * cdAcc2 * dDecelerateTime * dDecelerateTime);
			pSeg->dVelocity = cdVelE - cdAcc2 * dDecelerateTime;
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
	KIN_PARS *pKinPars;
}STREAM_TH_INFO;

//生成spline
static bool PathConverToSpline(const KIN_PARS *const pKinPars)
{
	STREAM_TH_INFO *pInfo = new STREAM_TH_INFO();
	pInfo->pCubPars_x = new SAC_CUB_PARS[iPathSegSum]();
	pInfo->pCubPars_x = new SAC_CUB_PARS[iPathSegSum]();
	pInfo->pCubPars_x = new SAC_CUB_PARS[iPathSegSum]();
	pInfo->pKinPars = pKinPars;
	for (int index = 0; index < iPathSegSum; ++index)
	{
		double dAngle(pPathSeg[iPathSegSum]->dPosition / dRadius);

	}
	HANDLE h=(HANDLE)_beginthreadex(NULL,0,StreamThread,pInfo,0,NULL);
	
	return true;
} 



static bool StreamStart()
{
	
}

static unsigned WINAPI StreamThread( LPVOID lpParameter )
{
	STREAM_TH_INFO *pInfo=(STREAM_TH_INFO*)lpParameter;

	uint32_t uGroundId;
	MacDefineSyncGroup(pInfo->pKinPars->jointAxisId, pInfo->pKinPars->nrOfJoints, &uGroundId);
	SacClearInterpolantBuffer(pInfo->pKinPars->jointAxisId[0]);
	SacClearInterpolantBuffer(pInfo->pKinPars->jointAxisId[1]);
	MacStartSyncGroup(uGroundId);
	MacDeleteSyncGroup(uGroundId);

	delete[] pPathSeg;
	delete[] pInfo->pCubPars_x;
	delete[] pInfo->pCubPars_y;
	delete[] pInfo->pCubPars_z;
	delete pInfo;
}