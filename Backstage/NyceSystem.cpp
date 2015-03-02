#include "StdAfx.h"
#include "NyceSystem.h"

#define _USE_MATH_DEFINES
#include <math.h>

NyceSystem::NyceSystem(const bool &bSim):
							m_status(SYSTEM_NON),
							m_pAxisX(nullptr),
							m_pAxisY(nullptr),
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
	m_pAxisY = m_nodeMap[(pAxis_infos + 1)->nodeName]->GetAxis((pAxis_infos + 1)->axisName);
//	m_pAxisZ = m_nodeMap[(pAxis_infos + 2)->nodeName]->GetAxis((pAxis_infos + 2)->axisName);
	return true;
}

bool NyceSystem::GetInSeg_Cicle_xy(const double *dCurX, const double *dCurY, const double *dRadius,IN_SED_PRT const pSegments,const int * segSum)
{
	IN_SED_PRT ptr(pSegments);
	double dDistance_x(*dCurX),dDistance_y(*dCurY),dVel_x(0.0),dVel_y(0.0),dTime(0.0),dTime_x(0.0),dTime_y(0.0),dAcc_x(0.0),dAcc_y(0.0);
	double dAngle(0.0),dLastVel_x(0.0),dLastVel_y(0.0);
	double dMaxVel_x(0.0),dMaxAcc_x(0.0),dMaxJerk_x(0.0),dMaxVel_y(0.0),dMaxAcc_y(0.0),dMaxJerk_y(0.0);
	m_pAxisX->GetMovePars(dMaxVel_x,dMaxAcc_x,dMaxJerk_x);
	m_pAxisY->GetMovePars(dMaxVel_y,dMaxAcc_y,dMaxJerk_y);
	/****************************************
	�滮ǰ��ε�·��
	*****************************************/
	int i = 0;
	for (; i <= *segSum / 2.0; ++i)
	{
		ptr = pSegments + i;
		dAngle = 2.0 * M_PI / (*segSum) * ((double)i+1.0) ;
		if (i==0)
		{
			dDistance_x = *dRadius - *dRadius * cos(dAngle);
			dDistance_y = *dRadius * sin(dAngle);
		}
		else
		{
			dDistance_x = *dCurX + *dRadius - *dRadius * cos(dAngle) - (ptr-1)->dPosX;
			dDistance_y = *dCurY + *dRadius * sin(dAngle) - (ptr-1)->dPosY;
		}
		dLastVel_x = dVel_x;
		dLastVel_y = dVel_y;
		GetInSegPars(dDistance_x,dVel_x,dAcc_x,dTime_x,dMaxVel_x,dMaxAcc_x,dMaxJerk_x);
		GetInSegPars(dDistance_y,dVel_y,dAcc_y,dTime_y,dMaxVel_y,dMaxAcc_y,dMaxJerk_y);
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
		ptr->iNo = i;
		ptr->dTime = dTime;
		ptr->dVelX = dVel_x ;
		ptr->dVelY = dVel_y;
		if (i==0)
		{
			ptr->dPosX = dDistance_x + *dCurX;
			ptr->dPosY = dDistance_y + *dCurY;
		}
		else
		{
			ptr->dPosX = dDistance_x + (ptr-1)->dPosX;
			ptr->dPosY = dDistance_y + (ptr-1)->dPosY;
		}
	}
	/****************************************
	�滮���ε�·��
	*****************************************/
	bool bParity(*segSum % 2 == 1 ? true : false);
	IN_SED_PRT ptrRef(nullptr);
	i--;
	for (int j = 0;i<*segSum;i++,j++)
	{
		ptr = pSegments + i;
		dAngle = 2.0 * M_PI / (*segSum) * ((double)i+1.0) ;
		ptrRef = bParity ? (ptr - j * 2 - 1) : (ptr - (j + 1) * 2);
		ptr->iNo = i;
		ptr->dTime = (ptrRef + 1)->dTime;//���ֶ�������ʱ�����ʱ�����
		ptr->dVelX = -ptrRef->dVelX ;
		ptr->dVelY = ptrRef->dVelY;
		ptr->dPosX = *dCurX + *dRadius - *dRadius * cos(dAngle); 
		ptr->dPosY = *dCurY + *dRadius * sin(dAngle);
	}
	ptr->dVelX = ptr->dVelY = 0;
	return true;
}

// ���㷨
// bool NyceSystem::GetInSeg_Cicle_xy(const double *dCurX, const double *dCurY, const double *dRadius,IN_SED_PRT const pSegments,const int * segSum)
// {
// 	IN_SED_PRT ptr(pSegments);
// 	double dDistance_x(*dCurX),dDistance_y(*dCurY),dVel_x(0.0),dVel_y(0.0),dTime(0.0),dTime_x(0.0),dTime_y(0.0),dAcc_x(0.0),dAcc_y(0.0);
// 	double dAngle(0.0),dLastVel_x(0.0),dLastVel_y(0.0);
// 	double dMaxVel_x(0.0),dMaxAcc_x(0.0),dMaxJerk_x(0.0),dMaxVel_y(0.0),dMaxAcc_y(0.0),dMaxJerk_y(0.0);
// 	m_pAxisX->GetMovePars(dMaxVel_x,dMaxAcc_x,dMaxJerk_x);
// 	m_pAxisY->GetMovePars(dMaxVel_y,dMaxAcc_y,dMaxJerk_y);
// 	/****************************************
// 	�滮ǰ��ε�·��
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
// 	�滮���ε�·��
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
// 		ptr->dTime = (ptrRef + 1)->dTime;//���ֶ�������ʱ�����ʱ�����
// 		ptr->dVelX = -ptrRef->dVelX ;
// 		ptr->dVelY = ptrRef->dVelY;
// 		ptr->dPosX = *dCurX + *dRadius - *dRadius * cos(dAngle); 
// 		ptr->dPosY = *dCurY + *dRadius * sin(dAngle);
// 	}
// 	ptr->dVelX = ptr->dVelY = 0;
// 	return true;
// }

bool NyceSystem::GetInSegPars(const double &dDistance,double &dVel, double &dAcc, double &dTime,const double &dMVel,const double &dMAcc,const double &dMJerk)
{
	double dMaxJerk(dMJerk);
	double dMaxAcc(dMAcc);
	double dMaxVel(dMVel);
	if (dDistance <= 0) 
	{
		dMaxJerk = -dMaxJerk;
		dMaxAcc = -dMaxAcc;
		dMaxVel = -dMaxVel;
	}
	double dTime_JerkUniformly(pow(dDistance * 6.0 /dMaxJerk, 1.0 / 3.0 ));//�ȼӼ���ʱ��
	double dTime_Up2MaxAcc((dMaxAcc - dAcc) / dMaxJerk);//�ﵽ�����ٶ�ʱ��
	if (dTime_JerkUniformly > dTime_Up2MaxAcc)
	{ 
		dTime_JerkUniformly = dTime_Up2MaxAcc;//�ȼӼ���ʱ������
		double dDeffDistance(dDistance - dMaxJerk * pow(dTime_JerkUniformly, 3.0) / 6.0);//�ȼӼ��ٺ��ʣ�����
		dVel += dMaxJerk * dTime_JerkUniformly * dTime_JerkUniformly / 2.0;//�ȼӼ��ٺ���ٶ�
		double dTime_AccUniformly (sqrt(dDeffDistance * 2.0 / dMaxAcc));//�ȼ���ʱ��
		double dTime_Up2MacVel((dMaxVel - dVel) / dMaxAcc);//�ﵽ����ٶ�ʱ��
		if (dTime_AccUniformly > dTime_Up2MacVel)
		{
			dTime_AccUniformly = dTime_Up2MacVel;//�ȼ���ʱ������
			dDeffDistance -= dMaxAcc * dTime_AccUniformly * dTime_AccUniformly / 2.0;//�ȼ��ٺ�ʣ�����
			double dTime_VelUniformly(dDeffDistance / dMaxVel);//�����˶�ʱ��
			/****************************************
			�˶����̣�
				�ȼӼ���+�ȼ���+����
			ĩ�μ��ٶ�Ϊ0,
			ĩ���ٶ�ΪMax
			*****************************************/
			dTime = dTime_JerkUniformly + dTime_AccUniformly + dTime_VelUniformly;
			dAcc = 0;
			dVel = dMaxVel;
			return true;
		}
		/****************************************
		�˶����̣�
			�ȼӼ���+�ȼ���
		ĩ�μ��ٶ�ΪMAX
		*****************************************/
		dTime = dTime_JerkUniformly + dTime_AccUniformly;
		dAcc = dMaxAcc;
		dVel += dMaxAcc * dTime_AccUniformly;
		return true;
	}
	double dTime_Up2MacVel(sqrt((dMaxVel - dVel) / dMaxJerk * 2.0));//�ﵽ����ٶ�ʱ��
	if (dTime_JerkUniformly > dTime_Up2MacVel)
	{
		dTime_JerkUniformly = dTime_Up2MacVel;//�ȼӼ���ʱ������
		double dDeffDistance(dDistance - dMaxJerk * pow(dTime_JerkUniformly, 3.0) / 6.0);//�ȼӼ��ٺ��ʣ�����
		double dTime_VelUniformly(dDeffDistance / dMaxVel);//�����˶�ʱ��
		/****************************************
		�˶����̣�
			�ȼӼ���+����
		ĩ���ٶ�ΪMAX
		*****************************************/
		dTime = dTime_JerkUniformly + dTime_VelUniformly;
		dAcc += dMaxJerk * dTime_JerkUniformly;
		dVel = dMaxVel;
		return true;
	}
	/****************************************
	�˶����̣�
		�ȼӼ���
	*****************************************/
	dTime = dTime_JerkUniformly;
	dAcc += dMaxJerk * dTime_JerkUniformly;
	dVel += dMaxJerk * dTime_JerkUniformly * dTime_JerkUniformly / 2.0;
	return true;
}

bool NyceSystem::MoveInterpolating(IN_SED_PRT pSegments,const int &iSum,const bool &bAbsolute = true)
{
	if (m_pAxisX == nullptr ||
		m_pAxisY == nullptr )
		return false;
	SAC_CUB_PARS *pCubSpline_x = new SAC_CUB_PARS[iSum],*pCubSpline_y = new SAC_CUB_PARS[iSum] ;
	int i=0;
	for (;i < iSum ;++i)
	{
		SAC_CUB_PARS *px = pCubSpline_x + i,*py = pCubSpline_y + i;
		px->splineId = (uint32_t)((pSegments + i)->iNo);
		px->position = (pSegments + i)->dPosX;
		px->time = (pSegments + i)->dTime;
		px->velocity = (pSegments + i)->dVelX;
		px->generateEvent = FALSE;
		py->splineId = (uint32_t)((pSegments + i)->iNo);
		py->position = (pSegments + i)->dPosY;
		py->time = (pSegments + i)->dTime;
		py->velocity = (pSegments + i)->dVelY;
		py->generateEvent = FALSE;
		if ( bAbsolute )
		{
			px->positionReference = SAC_ABSOLUTE;
			py->positionReference = SAC_ABSOLUTE;
		}
		else
		{
			px->positionReference = SAC_RELATIVE;
			py->positionReference = SAC_RELATIVE;
		}
	}
	uint32_t groupId;
	SAC_AXIS axis[2];
	axis[0] = m_pAxisX->m_id;
	axis[1] = m_pAxisY->m_id;
	if ( MacDefineSyncGroup(axis,2,&groupId)		!= NYCE_OK	||
		 !m_pAxisX->SetInPars(pCubSpline_x,iSum)				||
		 !m_pAxisY->SetInPars(pCubSpline_y,iSum)				||
		 MacStartSyncGroup(groupId,MAC_SYNC_MOTION)	!= NYCE_OK	||
		 MacDeleteSyncGroup(groupId)				!= NYCE_OK	)
		 return false;
	delete[] pCubSpline_x;
	delete[] pCubSpline_y;
	return true;
}