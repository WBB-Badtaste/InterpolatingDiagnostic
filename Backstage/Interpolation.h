#pragma once

#include "Types.h"
#include <math.h>

//������Ӽ�
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

//�������
typedef class AxisPars
{
public:
	PAR_SET axisPars_x;
	PAR_SET axisPars_y;
	PAR_SET axisPars_z;
}AXIS_PARS;

//λ������
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

	��ǰԲ���岹�ֶ��㷨��Limitations��
		1.��1/4Բǰ��������Բ���˶���
		2.��ʼ����X���ϡ�

 *****************************************************/

//Բ��·������
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

//Բ���岹���������
typedef class ArcInBuffer
{
public:
	ArcInBuffer():dAngVel(0.0){}
	PAR_SET inPars;//����Բ���˶�ʱ��������Ʋ���
	double dAngVel;//����Բ���˶��Ľ��ٶ�
}ARCIN_BUFFER;
	
//���ݸ����������������Բ���˶��Ĳ���
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

//����Բ���˶�ǰ
//�����Ƿ��ܽ�������Բ���˶�
bool GenerateArcSeg_part1(const ARCIN_BUFFER * const pArcInBuffer,const int &iMaxSegSum,int &iPatrSegSum,IN_SEG * const pInSeg)
{

}

//����Բ���˶�ʱ
void GenerateArcSeg_part2()
{

}

//����Բ���˶���
void GenerateArcSeg_part3()
{

}

//����Բ���岹�ֶμ���
void GenerateArcSeg(const AXIS_PARS * const pAxisInfos,const ARC_INFO * const pArcInfo,IN_SEG * const pInSeg)
{
	ARCIN_BUFFER arcInBuffer;
	GetInPars(pAxisInfos,pArcInfo,&arcInBuffer);
}