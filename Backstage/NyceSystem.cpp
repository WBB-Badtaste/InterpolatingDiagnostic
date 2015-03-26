#include "StdAfx.h"
#include "NyceSystem.h"

#define _USE_MATH_DEFINES
#include <math.h>


NyceSystem::NyceSystem(const bool &bSim):
							m_status(SYSTEM_NON),
							m_pAxisX(nullptr),
							m_pAxisY1(nullptr),
							m_pAxisY2(nullptr),
							m_pAxisZ(nullptr)
{
	Initialize(bSim);
}

NyceSystem::~NyceSystem(void)
{
	Terminate();
}

bool NyceSystem::Initialize(const bool &bSim)
{
 	if (NyceInit(bSim ? NYCE_SIM : NYCE_NET) == NYCE_OK )
 	{
 		m_status = SYSTEM_INITIALIZED;
 		return true;
 	}
 	else
		return false;
}

bool NyceSystem::Terminate()
{
	if (m_status != SYSTEM_INITIALIZED)
		return false;
	if (DelAllNode() == false)
		return false;
	if (NyceTerm() == NYCE_OK) 
	{
		m_status = SYSTEM_TERMINATED;
		return true;
	}
	else
		return false;
}

bool NyceSystem::AddNode(const string& name)
{
	m_nodeMap[name] = new NyceNode(name);
	return m_nodeMap[name]->Status() == NODE_CONNECTED ? true : false;
}

bool NyceSystem::DelNode(const string& name)
{
	if (m_nodeMap[name]->Status() == AXIS_CONNECTED)
		if (m_nodeMap[name]->Disconnect() != NYCE_OK)
			return false;
	delete m_nodeMap[name];
	m_nodeMap.erase(name);
	return true;
}

bool NyceSystem::DelAllNode()
{
	while (m_nodeMap.size() != 0)
		if (DelNode(m_nodeMap.begin()->first) == false)
			return false;
	return true;
}

SYSTEM_STATUS NyceSystem::Status()
{
	return m_status;
}

unsigned NyceSystem::GetNodeSum()
{
	return m_nodeMap.size();
}

NyceNode* const NyceSystem::GetNode(const string &name)
{
	return m_nodeMap[name];
}

bool NyceSystem::SetInAxis(PCAXIS_INFO pAxis_infos,int sum)
{
	if (m_status != SYSTEM_INITIALIZED ||
		sum > 3 ||
		sum < 2 )
		return false;
	m_pAxisX = m_nodeMap[pAxis_infos->nodeName]->GetAxis(pAxis_infos->axisName);
	m_pAxisY1 = m_nodeMap[(pAxis_infos + 1)->nodeName]->GetAxis((pAxis_infos + 1)->axisName);
//	m_pAxisZ = m_nodeMap[(pAxis_infos + 2)->nodeName]->GetAxis((pAxis_infos + 2)->axisName);
	return true;
}

bool NyceSystem::GetInSeg_Cicle_xy(const IN_INFO * const pInInfo,IN_SED_PRT const pSegments)
{
	IN_SED_PRT ptr(pSegments);
	double dDistance_x(pInInfo->dCurPosX),dDistance_y(pInInfo->dCurPosY);
	double dVel_x(0.0),dVel_y(0.0),dLastVel_x(0.0),dLastVel_y(0.0);
	double dAcc_x(0.0),dAcc_y(0.0),dLastAcc_x(0.0),dLastAcc_y(0.0);
	double dTime(0.0),dTime_x(0.0),dTime_y(0.0);
	double dAngle(0.0);
	double dMaxVel_x(0.0),dMaxAcc_x(0.0),dMaxJerk_x(0.0),dMaxVel_y(0.0),dMaxAcc_y(0.0),dMaxJerk_y(0.0);
	m_pAxisX->GetMotionPars(dMaxVel_x,dMaxAcc_x,dMaxJerk_x);
	m_pAxisY1->GetMotionPars(dMaxVel_y,dMaxAcc_y,dMaxJerk_y);
	dMaxJerk_x *= 0.6;
	dMaxJerk_y *= 0.6;
	/****************************************
	规划前半段的路径
	*****************************************/
	int i = 0;
	for (; i <= pInInfo->iSegAmount / 2.0; ++i)
	{
		ptr = pSegments + i;
		double k = 2.0 / pInInfo->iSegAmount * ((double)i+1.0);
		dAngle = M_PI * k;
		if (i==0)
		{
			dDistance_x = pInInfo->dRadius * (1 - cos(dAngle));
			dDistance_y = pInInfo->dRadius * sin(dAngle);
		}
		else
		{
			dDistance_x = pInInfo->dCurPosX + pInInfo->dRadius * (1 - cos(dAngle)) - (ptr-1)->dPosX;
			dDistance_y = pInInfo->dCurPosY + pInInfo->dRadius * sin(dAngle) - (ptr-1)->dPosY;
		}
		dLastVel_x = dVel_x;
		dLastVel_y = dVel_y;
		dLastAcc_x = dAcc_x;
		dLastAcc_y = dAcc_y;
		GetInSegPars(dDistance_x,dVel_x,dAcc_x,dTime_x,dMaxVel_x,dMaxAcc_x,dMaxJerk_x);
		GetInSegPars(dDistance_y,dVel_y,dAcc_y,dTime_y,dMaxVel_y,dMaxAcc_y,dMaxJerk_y);
		double dNewMaxVel_x(dVel_x),dNewMaxVel_y(dVel_y),dNewMaxAcc_x(dAcc_x),dNewMaxAcc_y(dAcc_y);
//  	if (k - 0.5 == (int)(k - 0.5) )
//  	{
//  		//a = k * pi + pi / 2
//  	}

// 		double buffer(- dAcc_x * tan(dAngle));
// 		if ((buffer >0 && buffer > dNewMaxAcc_y)||
// 			(buffer <0 && buffer < dNewMaxAcc_y))
// 		{
// 			dNewMaxAcc_x = - dAcc_y / tan(dAngle);
// 			dVel_x = dLastVel_x;
// 			dAcc_x = dLastAcc_x;
// 			ModifyInSegPars_A(dDistance_x,dVel_x,dAcc_x,dTime_x,dNewMaxVel_x,dNewMaxAcc_x,dMaxJerk_x);
// 		}
// 		else
// 		{
// 			dNewMaxAcc_y = buffer;
// 			dVel_y = dLastVel_y;
// 			dAcc_y = dLastAcc_y;
// 			ModifyInSegPars_A(dDistance_y,dVel_y,dAcc_y,dTime_y,dNewMaxVel_y,dNewMaxAcc_y,dMaxJerk_y);
// 		}
// 		buffer = dVel_x / tan(dAngle);
// 		if ((buffer >0 && buffer >dNewMaxVel_y)||
// 			(buffer <0 && buffer <dNewMaxVel_y))
// 		{
// 			dNewMaxVel_x = dVel_y * tan(dAngle);
// 			dVel_x = dLastVel_x;
// 			dAcc_x = dLastAcc_x;
// 			ModifyInSegPars_V(dDistance_x,dVel_x,dAcc_x,dTime_x,dNewMaxVel_x,dNewMaxAcc_x,dMaxJerk_x);
// 		}
// 		else
// 		{
// 			dNewMaxVel_y = buffer;
// 			dVel_y = dLastVel_y;
// 			dAcc_y = dLastAcc_y;
// 			ModifyInSegPars_V(dDistance_y,dVel_y,dAcc_y,dTime_y,dNewMaxVel_y,dNewMaxAcc_y,dMaxJerk_y);
// 		}

		if (dTime_x > dTime_y)
		{
			dTime = dTime_x;
			double buffer(dVel_x / tan(dAngle));
			if ((buffer > 0 && buffer > dMaxVel_y)	||
				(buffer < 0 && buffer < -dMaxVel_y)	)
			{
				buffer = dVel_y * tan(dAngle);
				if ((buffer > 0 && buffer > dMaxVel_x)	||
					(buffer < 0 && buffer < -dMaxVel_x)	)
				{
					return false;
				}
				else
				{
					dVel_x = buffer;
					dAcc_x = dMaxJerk_x * dTime;
					if (dAcc_x > dMaxAcc_x)
						dAcc_x = dMaxAcc_x;
				}
			}
			else
			{
				dVel_y = buffer;
				dAcc_y = dMaxJerk_y * dTime;
				if (dAcc_y > dMaxAcc_y)
					dAcc_y = dMaxAcc_y;
			}
		}
		else
		{ 
			dTime = dTime_y;
			double buffer(dVel_y * tan(dAngle));
			if ((buffer > 0 && buffer > dMaxVel_x)	||
				(buffer < 0 && buffer < -dMaxVel_x)	)
			{
				buffer = dVel_x / tan(dAngle);
				if ((buffer > 0 && buffer > dMaxVel_y)	||
					(buffer < 0 && buffer < -dMaxVel_y)	)
				{
					return false;
				}
				else
				{
					dVel_y = buffer;
					dAcc_y = dMaxJerk_y * dTime;
					if (dAcc_y > dMaxAcc_y)
						dAcc_y = dMaxAcc_y;
				}
			}
			else
			{
				dVel_x = buffer;
				dAcc_x = dMaxJerk_x * dTime;
				if (dAcc_x > dMaxAcc_x)
					dAcc_x = dMaxAcc_x;
			}
		}

		//修正加速度
		if (dVel_y == dMaxVel_x)
			dAcc_y = 0;
		if (dVel_x == dMaxVel_x)
			dAcc_x = 0;

		ptr->iNo = i;
		ptr->dTime = dTime;
		ptr->dVelX = dVel_x ;
		ptr->dVelY = dVel_y;
		if (i==0)
		{
			ptr->dPosX = dDistance_x + pInInfo->dCurPosX;
			ptr->dPosY = dDistance_y + pInInfo->dCurPosY;
		}
		else
		{
			ptr->dPosX = dDistance_x + (ptr-1)->dPosX;
			ptr->dPosY = dDistance_y + (ptr-1)->dPosY;
		}
	}
	uint32_t a = 0x1F;
	/****************************************
	规划后半段的路径
	*****************************************/
	bool bParity(pInInfo->iSegAmount % 2 == 1 ? true : false);
	IN_SED_PRT ptrRef(nullptr);
	i--;
	for (int j = 0;i < pInInfo->iSegAmount;i++,j++)
	{ 
		ptr = pSegments + i;
		dAngle = 2.0 * M_PI / pInInfo->iSegAmount * ((double)i+1.0) ;
		ptrRef = bParity ? (ptr - j * 2 - 1) : (ptr - (j + 1) * 2);
		ptr->iNo = i;
		ptr->dTime = (ptrRef + 1)->dTime;//当分段是奇数时会出现时间错误
		ptr->dVelX = -ptrRef->dVelX ;
		ptr->dVelY = ptrRef->dVelY;
		ptr->dPosX = pInInfo->dCurPosX + pInInfo->dRadius * (1 - cos(dAngle));
		ptr->dPosY = pInInfo->dCurPosY + pInInfo->dRadius * sin(dAngle);
	}
	ptr->dVelX = ptr->dVelY = 0;
	return true;
}

bool NyceSystem::GetInSegPars(const double &dDistance,double &dVel, double &dAcc, double &dTime,const double &dMVel,const double &dMAcc,const double &dJerk)
{
	double dMaxJerk(dJerk);
	double dMaxAcc(dMAcc);
	double dMaxVel(dMVel);
	if (dDistance < 0) 
	{
		dMaxJerk = -dMaxJerk;
		dMaxAcc = -dMaxAcc;
		dMaxVel = -dMaxVel;
	}
	double dTime_JerkUniformly(pow(dDistance * 6.0 /dMaxJerk, 1.0 / 3.0 ));//匀加加速时间
	double dTime_Up2MaxAcc((dMaxAcc - dAcc) / dMaxJerk);//达到最大加速度时间
	double dTime_Up2MacVel(sqrt((dMaxVel - dVel) / dMaxJerk * 2.0));//达到最大速度时间
	if (dTime_JerkUniformly > dTime_Up2MaxAcc)
	{ 
		if (dTime_Up2MacVel < dTime_Up2MaxAcc)
		{
			dTime_JerkUniformly = dTime_Up2MacVel;//匀加加速时间修正
			double dDeffDistance(dDistance - dMaxJerk * pow(dTime_JerkUniformly, 3.0) / 6.0);//匀加加速后的剩余距离
			double dTime_VelUniformly(dDeffDistance / dMaxVel);//匀速运动时间
			/****************************************
			运动过程：
			匀加加速+匀速
			末段速度为MAX
			*****************************************/
			dAcc += dMaxJerk * dTime_JerkUniformly;
			dVel = dMaxVel;
			dTime = dTime_JerkUniformly + dTime_VelUniformly;
			return true;
		}
		dTime_JerkUniformly = dTime_Up2MaxAcc;//匀加加速时间修正
		double dDeffDistance(dDistance - dMaxJerk * pow(dTime_JerkUniformly, 3.0) / 6.0);//匀加加速后的剩余距离
		dVel += dMaxJerk * dTime_JerkUniformly * dTime_JerkUniformly / 2.0;//匀加加速后的速度
		double dTime_AccUniformly (sqrt(dDeffDistance * 2.0 / dMaxAcc));//匀加速时间
		double dTime_Up2MacVel((dMaxVel - dVel) / dMaxAcc);//达到最大速度时间
		if (dTime_AccUniformly > dTime_Up2MacVel)
		{
			dTime_AccUniformly = dTime_Up2MacVel;//匀加速时间修正
			dDeffDistance -= dMaxAcc * dTime_AccUniformly * dTime_AccUniformly / 2.0;//匀加速后剩余距离
			double dTime_VelUniformly(dDeffDistance / dMaxVel);//匀速运动时间
			/****************************************
			运动过程：
				匀加加速+匀加速+匀速
			末段加速度为0,
			末段速度为Max
			*****************************************/
			dTime = dTime_JerkUniformly + dTime_AccUniformly + dTime_VelUniformly;

			dAcc = dMAcc;//用在在后面的修正中，不能为0
			dVel = dMaxVel;
			return true;
		}
		/****************************************
		运动过程：
			匀加加速+匀加速
		末段加速度为MAX
		*****************************************/
		dTime = dTime_JerkUniformly + dTime_AccUniformly;
		dAcc = dMaxAcc;
		dVel += dMaxAcc * dTime_AccUniformly;
		return true;
	}
	if (dTime_JerkUniformly > dTime_Up2MacVel)
	{
		dTime_JerkUniformly = dTime_Up2MacVel;//匀加加速时间修正
		double dDeffDistance(dDistance - dMaxJerk * pow(dTime_JerkUniformly, 3.0) / 6.0);//匀加加速后的剩余距离
		double dTime_VelUniformly(dDeffDistance / dMaxVel);//匀速运动时间
		/****************************************
		运动过程：
			匀加加速+匀速
		末段速度为MAX
		*****************************************/
		dTime = dTime_JerkUniformly + dTime_VelUniformly;
		dAcc += dMaxJerk * dTime_JerkUniformly;
		dVel = dMaxVel;
		return true;
	}
	/****************************************
	运动过程：
		匀加加速
	*****************************************/
	dTime = dTime_JerkUniformly;
	dAcc += dMaxJerk * dTime_JerkUniformly;
	dVel += dMaxJerk * dTime_JerkUniformly * dTime_JerkUniformly / 2.0;
	return true;
}

bool NyceSystem::ModifyInSegPars_A(const double &dDistance,double &dVel,double &dAcc, double &dTime,const double &dMVel,const double &dMAcc,const double &dJerk)
{
	double dMaxJerk(dJerk);
	if(dDistance < 0)
		dMaxJerk = -dMaxJerk;
	double dTime_JerkUniformly((dMAcc - dAcc) / dMaxJerk);//匀加加速时间
	double dDist(dDistance - dJerk * pow(dTime_JerkUniformly,3.0) / 6.0);//匀加加速后剩余距离
	dVel += dMaxJerk * dTime_JerkUniformly * dTime_JerkUniformly / 2.0;//匀加加速后的速度
 #ifdef DEBUG
 	if ((dDist <0 && dVel >0) ||
 		(dDist >0 && dVel <0) )
 		return false;
 #endif
	double dTime_AccUniformly(sqrt(dDist * 2.0 / dMAcc));//匀加速时间
	double dTimeUp2MaxVel((dMVel-dVel) / dMAcc);//加速到最大速度时间
	if (dTimeUp2MaxVel < dTime_AccUniformly)
	{
		dTime_AccUniformly = dTimeUp2MaxVel;//匀加速时间修正
		dDist -= 0.5 * dMAcc * dTime_AccUniformly * dTime_AccUniformly;//匀加速后剩余路程
		double dTime_VelUniformly(dDist / dMVel);//匀速运动时间
		dAcc = dMAcc;
		dVel = dMVel;
		dTime = dTime_JerkUniformly + dTime_AccUniformly + dTime_VelUniformly;
		return true;
	}
	dAcc = dMAcc;
	dTime = dTime_JerkUniformly + dTime_AccUniformly;
	dVel += dMAcc * dTime_AccUniformly;
	return true;
}

bool NyceSystem::ModifyInSegPars_V(const double &dDistance,double &dVel,double &dAcc, double &dTime,const double &dMVel,const double &dMAcc,const double &dJerk)
{
	double dTime_JerkUniformly((dMAcc - dAcc) / dJerk);
	double dTime_AccUniformly((dMVel - dVel - dJerk * dTime_JerkUniformly * dTime_JerkUniformly / 2.0) / dMAcc);
	double dDist(dDistance - dJerk * pow(dTime_JerkUniformly,3.0) / 6.0 - dMAcc * dTime_AccUniformly * dTime_AccUniformly / 2.0);
#ifdef DEBUG
	if ((dDist <0 && dVel >0) ||
		(dDist >0 && dVel <0) )
		return false;
#endif
	double dTime_VelUniformly(dDist / dMVel);
	dVel = dMVel;
	dAcc = dMAcc;
	dTime = dTime_JerkUniformly + dTime_AccUniformly + dTime_VelUniformly;
	return true;
}

// 旧算法
// bool NyceSystem::GetInSeg_Cicle_xy(const double *dCurX, const double *dCurY, const double *dRadius,IN_SED_PRT const pSegments,const int * segSum)
// {
// 	IN_SED_PRT ptr(pSegments);
// 	double dDistance_x(*dCurX),dDistance_y(*dCurY),dVel_x(0.0),dVel_y(0.0),dTime(0.0),dTime_x(0.0),dTime_y(0.0),dAcc_x(0.0),dAcc_y(0.0);
// 	double dAngle(0.0),dLastVel_x(0.0),dLastVel_y(0.0);
// 	double dMaxVel_x(0.0),dMaxAcc_x(0.0),dMaxJerk_x(0.0),dMaxVel_y(0.0),dMaxAcc_y(0.0),dMaxJerk_y(0.0);
// 	m_pAxisX->GetMovePars(dMaxVel_x,dMaxAcc_x,dMaxJerk_x);
// 	m_pAxisY->GetMovePars(dMaxVel_y,dMaxAcc_y,dMaxJerk_y);
// 	/****************************************
// 	规划前半段的路径
// 	*****************************************/
// 	int i = 0;
// 	for (; i <= *segSum / 2.0; ++i)
// 	{
// 		ptr = pSegments + i;
// 		dAngle = 2.0 * M_PI / (*segSum) * ((double)i+1.0) ;
// 		if (i==0)
// 		{
// 			dDistance_x = *dRadius - *dRadius * cos(dAngle);
// 			dDistance_y = *dRadius * sin(dAngle);
// 		}
// 		else
// 		{
// 			dDistance_x = *dCurX + *dRadius - *dRadius * cos(dAngle) - (ptr-1)->dPosX;
// 			dDistance_y = *dCurY + *dRadius * sin(dAngle) - (ptr-1)->dPosY;
// 		}
// 		dLastVel_x = dVel_x;
// 		dLastVel_y = dVel_y;
// 		GetInSegPars(dDistance_x,dVel_x,dAcc_x,dTime_x,dMaxVel_x,dMaxAcc_x,dMaxJerk_x);
// 		GetInSegPars(dDistance_y,dVel_y,dAcc_y,dTime_y,dMaxVel_y,dMaxAcc_y,dMaxJerk_y);
// 		if (dTime_x > dTime_y)
// 		{
// 			dTime = dTime_x;
// 			double buffer(dVel_x / tan(dAngle));
// 			if ((buffer > 0 && buffer > dMaxVel_y)	||
// 				(buffer < 0 && buffer < -dMaxVel_y)	)
// 			{
// 				buffer = dVel_y * tan(dAngle);
// 				if ((buffer > 0 && buffer > dMaxVel_x)	||
// 					(buffer < 0 && buffer < -dMaxVel_x)	)
// 				{
// 					return false;
// 				}
// 				else
// 				{
// 					dVel_x = buffer;
// 					dAcc_x = dMaxJerk_x * dTime;
// 					if (dAcc_x > dMaxAcc_x)
// 						dAcc_x = dMaxAcc_x;
// 				}
// 			}
// 			else
// 			{
// 				dVel_y = buffer;
// 				dAcc_y = dMaxJerk_y * dTime;
// 				if (dAcc_y > dMaxAcc_y)
// 					dAcc_y = dMaxAcc_y;
// 			}
// 		}
// 		else
// 		{ 
// 			dTime = dTime_y;
// 			double buffer(dVel_y * tan(dAngle));
// 			if ((buffer > 0 && buffer > dMaxVel_x)	||
// 				(buffer < 0 && buffer < -dMaxVel_x)	)
// 			{
// 				buffer = dVel_x / tan(dAngle);
// 				if ((buffer > 0 && buffer > dMaxVel_y)	||
// 					(buffer < 0 && buffer < -dMaxVel_y)	)
// 				{
// 					return false;
// 				}
// 				else
// 				{
// 					dVel_y = buffer;
// 					dAcc_y = dMaxJerk_y * dTime;
// 					if (dAcc_y > dMaxAcc_y)
// 						dAcc_y = dMaxAcc_y;
// 				}
// 			}
// 			else
// 			{
// 				dVel_x = buffer;
// 				dAcc_x = dMaxJerk_x * dTime;
// 				if (dAcc_x > dMaxAcc_x)
// 					dAcc_x = dMaxAcc_x;
// 			}
// 		}
// 		ptr->iNo = i;
// 		ptr->dTime = dTime;
// 		ptr->dVelX = dVel_x ;
// 		ptr->dVelY = dVel_y;
// 		if (i==0)
// 		{
// 			ptr->dPosX = dDistance_x + *dCurX;
// 			ptr->dPosY = dDistance_y + *dCurY;
// 		}
// 		else
// 		{
// 			ptr->dPosX = dDistance_x + (ptr-1)->dPosX;
// 			ptr->dPosY = dDistance_y + (ptr-1)->dPosY;
// 		}
// 	}
// 	/****************************************
// 	规划后半段的路径
// 	*****************************************/
// 	bool bParity(*segSum % 2 == 1 ? true : false);
// 	IN_SED_PRT ptrRef(nullptr);
// 	i--;
// 	for (int j = 0;i<*segSum;i++,j++)
// 	{
// 		ptr = pSegments + i;
// 		dAngle = 2.0 * M_PI / (*segSum) * ((double)i+1.0) ;
// 		ptrRef = bParity ? (ptr - j * 2 - 1) : (ptr - (j + 1) * 2);
// 		ptr->iNo = i;
// 		ptr->dTime = (ptrRef + 1)->dTime;//当分段是奇数时会出现时间错误
// 		ptr->dVelX = -ptrRef->dVelX ;
// 		ptr->dVelY = ptrRef->dVelY;
// 		ptr->dPosX = *dCurX + *dRadius - *dRadius * cos(dAngle); 
// 		ptr->dPosY = *dCurY + *dRadius * sin(dAngle);
// 	}
// 	ptr->dVelX = ptr->dVelY = 0;
// 	return true;
// }




// bool NyceSystem::GetInSegPars(const double &dDistance,double &dVel, double &dAcc, double &dTime,const double &dMVel,const double &dMAcc,const double &dMJerk)
// {
// 	double dMaxJerk(dMJerk);
// 	double dMaxAcc(dMAcc);
// 	double dMaxVel(dMVel);
// 	if (dDistance <= 0) 
// 	{
// 		dMaxJerk = -dMaxJerk;
// 		dMaxAcc = -dMaxAcc;
// 		dMaxVel = -dMaxVel;
// 	}
// 	double dTime_JerkUniformly(pow(dDistance * 6.0 /dMaxJerk, 1.0 / 3.0 ));//匀加加速时间
// 	double dTime_Up2MaxAcc((dMaxAcc - dAcc) / dMaxJerk);//达到最大加速度时间
// 	if (dTime_JerkUniformly > dTime_Up2MaxAcc)
// 	{ 
// 		dTime_JerkUniformly = dTime_Up2MaxAcc;//匀加加速时间修正
// 		double dDeffDistance(dDistance - dMaxJerk * pow(dTime_JerkUniformly, 3.0) / 6.0);//匀加加速后的剩余距离
// 		dVel += dMaxJerk * dTime_JerkUniformly * dTime_JerkUniformly / 2.0;//匀加加速后的速度
// 		double dTime_AccUniformly (sqrt(dDeffDistance * 2.0 / dMaxAcc));//匀加速时间
// 		double dTime_Up2MacVel((dMaxVel - dVel) / dMaxAcc);//达到最大速度时间
// 		if (dTime_AccUniformly > dTime_Up2MacVel)
// 		{
// 			dTime_AccUniformly = dTime_Up2MacVel;//匀加速时间修正
// 			dDeffDistance -= dMaxAcc * dTime_AccUniformly * dTime_AccUniformly / 2.0;//匀加速后剩余距离
// 			double dTime_VelUniformly(dDeffDistance / dMaxVel);//匀速运动时间
// 			/****************************************
// 			运动过程：
// 				匀加加速+匀加速+匀速
// 			末段加速度为0,
// 			末段速度为Max
// 			*****************************************/
// 			dTime = dTime_JerkUniformly + dTime_AccUniformly + dTime_VelUniformly;
// 			dAcc = 0;
// 			dVel = dMaxVel;
// 			return true;
// 		}
// 		/****************************************
// 		运动过程：
// 			匀加加速+匀加速
// 		末段加速度为MAX
// 		*****************************************/
// 		dTime = dTime_JerkUniformly + dTime_AccUniformly;
// 		dAcc = dMaxAcc;
// 		dVel += dMaxAcc * dTime_AccUniformly;
// 		return true;
// 	}
// 	double dTime_Up2MacVel(sqrt((dMaxVel - dVel) / dMaxJerk * 2.0));//达到最大速度时间
// 	if (dTime_JerkUniformly > dTime_Up2MacVel)
// 	{
// 		dTime_JerkUniformly = dTime_Up2MacVel;//匀加加速时间修正
// 		double dDeffDistance(dDistance - dMaxJerk * pow(dTime_JerkUniformly, 3.0) / 6.0);//匀加加速后的剩余距离
// 		double dTime_VelUniformly(dDeffDistance / dMaxVel);//匀速运动时间
// 		/****************************************
// 		运动过程：
// 			匀加加速+匀速
// 		末段速度为MAX
// 		*****************************************/
// 		dTime = dTime_JerkUniformly + dTime_VelUniformly;
// 		dAcc += dMaxJerk * dTime_JerkUniformly;
// 		dVel = dMaxVel;
// 		return true;
// 	}
// 	/****************************************
// 	运动过程：
// 		匀加加速
// 	*****************************************/
// 	dTime = dTime_JerkUniformly;
// 	dAcc += dMaxJerk * dTime_JerkUniformly;
// 	dVel += dMaxJerk * dTime_JerkUniformly * dTime_JerkUniformly / 2.0;
// 	return true;
// }




bool NyceSystem::MoveInterpolating(IN_SED_PRT pSegments,const int &iSum,const bool &bAbsolute = true)
{
	if (m_pAxisX == nullptr ||
		m_pAxisY1 == nullptr )
		return false;
	SAC_CUB_PARS cubSpline_x[200],cubSpline_y[200] ;
	ZeroMemory(cubSpline_x,200);
	ZeroMemory(cubSpline_y,200);
	int i=0;
	for (;i < iSum ;++i)
	{
		cubSpline_x[i].splineId = (uint32_t)((pSegments + i)->iNo);
		cubSpline_x[i].position = (pSegments + i)->dPosX;
		cubSpline_x[i].time = (pSegments + i)->dTime;
		cubSpline_x[i].velocity = (pSegments + i)->dVelX;
		cubSpline_x[i].generateEvent = FALSE;

		cubSpline_y[i].splineId = (uint32_t)((pSegments + i)->iNo);
		cubSpline_y[i].position = (pSegments + i)->dPosY;
		cubSpline_y[i].time = (pSegments + i)->dTime;
		cubSpline_y[i].velocity = (pSegments + i)->dVelY;
		cubSpline_y[i].generateEvent = FALSE;

		if ( bAbsolute )
		{
			cubSpline_x[i].positionReference = SAC_ABSOLUTE;
			cubSpline_y[i].positionReference = SAC_ABSOLUTE;
		}
		else
		{
			cubSpline_x[i].positionReference = SAC_RELATIVE;
			cubSpline_y[i].positionReference = SAC_RELATIVE;
		}
	}

	SAC_AXIS axis[2];
	axis[0] =m_pAxisX->m_id;
	axis[1] =m_pAxisY1->m_id;
	uint32_t groundId;
	if (MacDefineSyncGroup(axis,2,&groundId) != NYCE_OK)
		return false;
	if (!m_pAxisX->SetInPars(cubSpline_x,iSum))
		return false;
	if (!m_pAxisY1->SetInPars(cubSpline_y,iSum))
		return false;
	if (!m_pAxisX->MoveInterpolating())
		return false;
	if (!m_pAxisY1->MoveInterpolating())
		return false;
	if (MacStartSyncGroup(groundId,MAC_SYNC_MOTION) != NYCE_OK)
		return false;
	if (MacDeleteSyncGroup(groundId) != NYCE_OK)
		return false;
	return true;
}

bool NyceSystem::RocksGantryInitialize(GANTRY_INFO *pGantryInfo)
{
	if (m_status != SYSTEM_INITIALIZED )
		return false;
	m_pAxisX	= m_nodeMap[pGantryInfo->sNodeName]->GetAxis(pGantryInfo->sAxisName_x);
	m_pAxisY1	= m_nodeMap[pGantryInfo->sNodeName]->GetAxis(pGantryInfo->sAxisName_y1);
	m_pAxisY2	= m_nodeMap[pGantryInfo->sNodeName]->GetAxis(pGantryInfo->sAxisName_y2);
	m_pAxisZ	= m_nodeMap[pGantryInfo->sNodeName]->GetAxis(pGantryInfo->sAxisName_z);
	m_rockMech.dof [0] = TRUE;//x
	m_rockMech.dof [1] = TRUE;//y
	m_rockMech.dof [2] = TRUE;//z
	m_rockMech.dof [3] = FALSE;
	m_rockMech.dof [4] = FALSE;
	m_rockMech.dof [5] = FALSE;
	m_rockMech.nrOfJoints = 4;
	m_rockMech.jointAxisId[0] = m_pAxisX->m_id;
	m_rockMech.jointAxisId[1] = m_pAxisY1->m_id;
  	m_rockMech.jointAxisId[2] = m_pAxisY2->m_id;
  	m_rockMech.jointAxisId[3] = m_pAxisZ->m_id; 

	if (RocksMechCreate(&m_rockMech) != NYCE_OK)
		return false;
	return true;
}

bool NyceSystem::RocksGantryTerminal()
{
	if (RocksMechDelete(&m_rockMech) != NYCE_OK)
		return false;
	return true;
}

bool NyceSystem::InitalizeRocksTrajCirclePars(POS &center,double &dTime,ROCKS_TRAJ_SINE_ACC_CIRCLE_PARS &rocksTrajCirclePars)
{
	double dPosX, dVelX(0.0), dAccX(0.0), dJerkX(0.0);
	double dPosY1,dVelY1(0.0),dAccY1(0.0),dJerkY1(0.0);
	double dPosY2,dVelY2(0.0),dAccY2(0.0),dJerkY2(0.0);
	double dPosZ, dVelZ(0.0), dAccZ(0.0), dJerkZ(0.0);
	if (!m_pAxisX ->GetMotionPars(dVelX,dAccX,dJerkX)	 ||
		!m_pAxisY1->GetMotionPars(dVelY1,dAccY1,dJerkY1) ||
		!m_pAxisY2->GetMotionPars(dVelY2,dAccY2,dJerkY2) ||
		!m_pAxisZ ->GetMotionPars(dVelZ,dAccZ,dJerkZ)	 ||
		!m_pAxisX ->GetPosition(&dPosX)					 ||
		!m_pAxisY1->GetPosition(&dPosY1)				 ||
		!m_pAxisY2->GetPosition(&dPosY2)				 ||
		!m_pAxisZ ->GetPosition(&dPosZ)					 )
		return false;

//  	if (RocksKinGantryPosition(&m_rockMech,rocksTrajCirclePars.startPos) != NYCE_OK)
//  		return false;
	if (RocksKinCartesianPosition(&m_rockMech,rocksTrajCirclePars.startPos) != NYCE_OK)
		return false;
	rocksTrajCirclePars.center[0]			  = center.dX;
	rocksTrajCirclePars.center[1]			  = center.dY;
	rocksTrajCirclePars.angle				  = -M_PI * 2.0 ;
	rocksTrajCirclePars.plane				  = ROCKS_PLANE_XY;
	rocksTrajCirclePars.maxVelocity			  = 300;//min(min(min(dVelX,dVelY1),dVelY2),dVelZ);
	rocksTrajCirclePars.maxAcceleration		  = 1000;//min(min(min(dAccX,dAccY1),dAccY2),dAccZ);
	rocksTrajCirclePars.splineTime			  = 0.01;
	rocksTrajCirclePars.maxNrOfSplines		  = 0;
	rocksTrajCirclePars.pPositionSplineBuffer = NULL;
	rocksTrajCirclePars.pVelocitySplineBuffer = NULL;
	
	return true;
}

bool NyceSystem::RocksGantryArcInterpolation(POS &center,double &dTime)
{
/*	ROCKS_TRAJ_SINE_ACC_CIRCLE_PARS rocksTrajCirclePars;*/
	 
	ROCKS_KIN_INV_PARS kinInvPars;
	for (int i=0;i<ROCKS_MECH_MAX_NR_OF_JOINTS;++i)
	{
		kinInvPars.pJointPositionBuffer[i] = NULL;
		kinInvPars.pJointVelocityBuffer[i] = NULL;
	}
	ROCKS_TRAJ_SEGMENT_START_PARS myTrajSegStartPars;
	myTrajSegStartPars.splineTime = 0.01;
	if (RocksKinCartesianPosition(&m_rockMech,myTrajSegStartPars.startPos) != NYCE_OK)
		return false;
	myTrajSegStartPars.maxNrOfSplines = 0;
	myTrajSegStartPars.pPositionSplineBuffer = NULL;
	myTrajSegStartPars.pVelocitySplineBuffer = NULL;

	if (RocksTrajSegmentStart(&m_rockMech,&myTrajSegStartPars) != NYCE_OK)
		return false;

	ROCKS_TRAJ_SEGMENT_ARC_PARS myTrajSegArcPars;
	myTrajSegArcPars.center[0] = center.dX;
	myTrajSegArcPars.center[1] = center.dY;
	myTrajSegArcPars.endPos[0] = 300;
	myTrajSegArcPars.endPos[1] = 0;
	myTrajSegArcPars.positiveAngle = TRUE;
	myTrajSegArcPars.endVelocity = 300;
	myTrajSegArcPars.plane = ROCKS_PLANE_XY;
	myTrajSegArcPars.maxAcceleration = 1000; 
	myTrajSegArcPars.originOffset.r.x = M_PI_4;
	myTrajSegArcPars.originOffset.r.y = 0;
	myTrajSegArcPars.originOffset.r.z = 0;
	myTrajSegArcPars.originOffset.t.x = 0;
	myTrajSegArcPars.originOffset.t.y = 0;
	myTrajSegArcPars.originOffset.t.z = 0;

	if (RocksTrajSegmentArc(&m_rockMech,&myTrajSegArcPars) != NYCE_OK)
		return false;

	myTrajSegArcPars.center[0] = center.dX;
	myTrajSegArcPars.center[1] = center.dY;
	myTrajSegArcPars.endPos[0] = 0;
	myTrajSegArcPars.endPos[1] = 0;
	myTrajSegArcPars.positiveAngle = TRUE;
	myTrajSegArcPars.endVelocity = 0;
	myTrajSegArcPars.plane = ROCKS_PLANE_XY;
	myTrajSegArcPars.maxAcceleration = 1000; 
	myTrajSegArcPars.originOffset.r.x = M_PI_4;
	myTrajSegArcPars.originOffset.r.y = 0;
	myTrajSegArcPars.originOffset.r.z = 0;
	myTrajSegArcPars.originOffset.t.x = 0;
	myTrajSegArcPars.originOffset.t.y = 0;
	myTrajSegArcPars.originOffset.t.z = 0;

	if (RocksTrajSegmentArc(&m_rockMech,&myTrajSegArcPars) != NYCE_OK)
		return false;

// 	if (!InitalizeRocksTrajCirclePars(center,dTime,rocksTrajCirclePars))
// 		return false;
// 	if (RocksTrajSineAccCircle(&m_rockMech,&rocksTrajCirclePars)   != NYCE_OK )
// 		return false;
// 	if (RocksKinDefineGantry(&m_rockMech,ROCKS_GANTRY_Y)		   != NYCE_OK )
// 		return false;
// 	if (RocksKinInverseGantry(&m_rockMech,&kinInvPars)			   != NYCE_OK )
// 		return false;
	if (RocksKinInverseCartesian(&m_rockMech,&kinInvPars)		   != NYCE_OK )
		return false;

// 	if (SacClearInterpolantBuffer(m_rockMech.jointAxisId[2])	   != NYCE_OK)
// 		return false;
#ifdef _DEBUG
	NYCE_STATUS status = RocksStream(&m_rockMech); 
	if (status!= NYCE_OK)
	{
		string str = NyceGetStatusString(status);
		return false;
	}
#else
	if (RocksStream(&m_rockMech)								   != NYCE_OK )
		return false;
#endif



// 	if (RocksStreamSynchronize(&m_rockMech,SAC_INDEFINITE) != NYCE_OK )
// 		return false;
// 

	return true;
}

// bool NyceSystem::RocksGantryArcInterpolation(POS &center,double &dTime)
// {
// 	SineAcc(100, 100, 0, 0, 0, 0, 50, 500);
// // 	SineAcc(-30, -10, 0, 0, 0, 0, 5, 50);
// // 	SineAcc(30, 10, 0, 0, 0, 0, 5, 50);
// // 	SineAcc(-30, -10, 0, 0, 0, 0, 5, 50);
// 	return true;
// }
// 
// NYCE_STATUS NyceSystem::SineAcc(double endPos0, double endPos1, double endPos2, double endPos3, double endPos4, double endPos5, double  maxVel, double maxAcc)
// {
// 	int			i;
// 	NYCE_STATUS	nyceStatus;
// 	ROCKS_TRAJ_SINE_ACC_PTP_PARS	rockPtpPars;
// 	ROCKS_KIN_INV_PARS				kinInvParBuf;
// 
// 	if (RocksMechCreate(&m_rockMech) != NYCE_OK)
// 		return false;
// 
// 	if (RocksKinDefineGantry(&m_rockMech,ROCKS_GANTRY_Y)		   != NYCE_OK )
// 		return false;
// 
// 	// get Start Positions in world Coordinates
// 	nyceStatus = RocksKinGantryPosition(&m_rockMech, rockPtpPars.startPos);
//  
// 	rockPtpPars.splineTime				= 0.1;
// 	rockPtpPars.endPos[0]				= endPos0;
// 	rockPtpPars.endPos[1]				= endPos1;
// 	rockPtpPars.endPos[2]				= endPos2;
// 	rockPtpPars.endPos[3]				= endPos3;
// 	rockPtpPars.endPos[4]				= endPos4;
// 	rockPtpPars.endPos[5]				= endPos5;
// 	rockPtpPars.maxVelocity				= maxVel;
// 	rockPtpPars.maxAcceleration			= maxAcc;
// 	rockPtpPars.maxNrOfSplines			= 0;
// 	rockPtpPars.pVelocitySplineBuffer	= NULL;
// 	rockPtpPars.pPositionSplineBuffer	= NULL;
// 	//
// 	// Create trajectory
// 	nyceStatus = RocksTrajSineAccPtp(&m_rockMech, &rockPtpPars);
//  
// 	//
// 	// Convert to joint splines 
// 	for (i=0; i<ROCKS_MECH_MAX_NR_OF_JOINTS; i++)
// 	{
// 		kinInvParBuf.pJointPositionBuffer[i] = NULL;
// 		kinInvParBuf.pJointVelocityBuffer[i] = NULL;
// 	}
// 	nyceStatus = RocksKinInverseGantry(&m_rockMech,&kinInvParBuf);
//  
// 	//
// 	//  stream it
// 	nyceStatus = RocksStream(&m_rockMech);
// 	string str = NyceGetStatusString(nyceStatus);
// /*	nyceStatus = RocksStreamSynchronize (&m_rockMech, 30);*/
// 	
// 	if (RocksMechDelete(&m_rockMech) != NYCE_OK)
// 		return false;
// 
// 	return(nyceStatus);
// }



