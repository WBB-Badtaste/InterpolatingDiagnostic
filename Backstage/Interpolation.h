#pragma once

#include "Types.h"
#include <math.h>

//轴参数子集
typedef class ParSet
{
public:
	ParSet():
		  dMaxVel(0.0),
		  dMaxAcc(0.0),
		  dMaxJerk(0.0){}
	double dMaxVel;
	double dMaxAcc;
	double dMaxJerk;
}PAR_SET;

//轴参数集
typedef class AxisPars
{
public:
	PAR_SET axisPars_x;
	PAR_SET axisPars_y;
	PAR_SET axisPars_z;
}AXIS_PARS;

//位置坐标
typedef class Position
{
public:
	Position():
		  dX(0.0),
		  dY(0.0){}
	double dX;
	double dY;
}POS;



/******************************************************

	当前圆弧插补分段算法的Limitations：
		1.在1/4圆前进入匀速圆周运动；
		2.起始点在X轴上。

 *****************************************************/

//圆弧路径描述
typedef class ArcInfo
{
public:
	ArcInfo():
		iSegNum(0),
		iCriteriumTime(0),
		dRadius(0.0){}
	int iSegNum;
	int iCriteriumTime;
	double dRadius;
	POS centerPos;
	POS startPos;
	POS endPos;
	PAR_SET startPars;
	PAR_SET endPars;
}ARC_INFO;

//圆弧插补计算过程量
typedef class ArcInBuffer
{
public:
	ArcInBuffer():dAngVel(0.0){}
	PAR_SET inPars;//匀速圆周运动时，轴的限制参数
	double dAngVel;//匀速圆周运动的角速度
}ARCIN_BUFFER;
	
//根据各个轴参数计算匀速圆周运动的参数
void GetInPars(const AXIS_PARS * const pAxisInfos,const ARC_INFO * const pArcInfo,ARCIN_BUFFER * const pArcInBuffer)
{
	double bufAngVel(0.0);
	pArcInBuffer->dAngVel = pAxisInfos->axisPars_x.dMaxVel / pArcInfo->dRadius;
	bufAngVel = sqrt(pAxisInfos->axisPars_x.dMaxAcc / pArcInfo->dRadius);
	if (pArcInBuffer->dAngVel > bufAngVel) pArcInBuffer->dAngVel = bufAngVel;
	bufAngVel = pow(pAxisInfos->axisPars_x.dMaxJerk / pArcInfo->dRadius,1.0 / 3.0);
	if (pArcInBuffer->dAngVel > bufAngVel) pArcInBuffer->dAngVel = bufAngVel;

	bufAngVel = pAxisInfos->axisPars_y.dMaxVel / pArcInfo->dRadius;
	if (pArcInBuffer->dAngVel > bufAngVel) pArcInBuffer->dAngVel = bufAngVel;
	bufAngVel = sqrt(pAxisInfos->axisPars_y.dMaxAcc / pArcInfo->dRadius);
	if (pArcInBuffer->dAngVel > bufAngVel) pArcInBuffer->dAngVel = bufAngVel;
	bufAngVel = pow(pAxisInfos->axisPars_y.dMaxJerk / pArcInfo->dRadius,1.0 / 3.0);
	if (pArcInBuffer->dAngVel > bufAngVel) pArcInBuffer->dAngVel = bufAngVel;

	pArcInBuffer->inPars.dMaxVel = pArcInfo->dRadius * pArcInBuffer->dAngVel;
	pArcInBuffer->inPars.dMaxAcc = pArcInfo->dRadius * pArcInBuffer->dAngVel * pArcInBuffer->dAngVel;
	pArcInBuffer->inPars.dMaxJerk = pArcInfo->dRadius * pArcInBuffer->dAngVel * pArcInBuffer->dAngVel * pArcInBuffer->dAngVel;
}

//匀速圆周运动前
//返回是否能进入匀速圆周运动
bool GenerateArcSeg_part1(const ARCIN_BUFFER * const pArcInBuffer,const int &iMaxSegSum,int &iPatrSegSum,IN_SEG * const pInSeg)
{

}

//匀速圆周运动时
void GenerateArcSeg_part2()
{

}

//匀速圆周运动后
void GenerateArcSeg_part3()
{

}

//生成圆弧插补分段集合
void GenerateArcSeg(const AXIS_PARS * const pAxisInfos,const ARC_INFO * const pArcInfo,IN_SEG * const pInSeg)
{
	ARCIN_BUFFER arcInBuffer;
	GetInPars(pAxisInfos,pArcInfo,&arcInBuffer);
}