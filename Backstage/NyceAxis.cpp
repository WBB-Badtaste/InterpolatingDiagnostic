#include "StdAfx.h"
#include "NyceAxis.h"
#include "sacapi.h"
#include <math.h>

NyceAxis::NyceAxis(const string &name):
								m_name(name),
								m_id(0),
								m_status(AXIS_NON)
{
	Connect();
	m_move_pars.dMaxAcc = 10;
	m_move_pars.dMaxJerk = 10;
	m_move_pars.dMaxVel = 10;
}

NyceAxis::~NyceAxis(void)
{
	if (m_status != AXIS_DISCONNECTED)
		Disconnect();
}

bool NyceAxis::Connect()
{
	if (m_status == AXIS_CONNECTED)
		return true;
	if (SacConnect(m_name.c_str(), &m_id)	!= NYCE_OK ||
		SacReadHomePars(m_id,&m_home_pars)	!= NYCE_OK )
		return false;
	m_status = AXIS_CONNECTED;
	return true;
}

bool NyceAxis::Disconnect()
{
	if (m_status == AXIS_DISCONNECTED)
		return true;
	if (SacDisconnect(m_id) != NYCE_OK)
		return false;
	m_status = AXIS_DISCONNECTED;
	return true;
}

AXIS_STATUS NyceAxis::Status()
{
	return m_status;
}

bool NyceAxis::Align()
{
	if (m_status != AXIS_CONNECTED)
		return false;
	if (SacShutdown(m_id)									!= NYCE_OK ||
		SacSynchronize( m_id, SAC_REQ_SHUTDOWN, 1.0 )		!= NYCE_OK ||
		SacInitialize( m_id, SAC_USE_FLASH )				!= NYCE_OK ||
		SacSynchronize( m_id, SAC_REQ_INITIALIZE, 1.0 )		!= NYCE_OK ||
		SacReset( m_id)										!= NYCE_OK ||
		SacSynchronize( m_id, SAC_REQ_RESET, 1.0 )			!= NYCE_OK ||
		SacGetAxisConfiguration( m_id, &m_configure_pars )	!= NYCE_OK )
		return false;
	if (m_configure_pars.motorType										== SAC_BRUSHLESS_AC_MOTOR &&
		SacAlignMotor(m_id)												!= NYCE_OK ||
		SacSynchronize( m_id, SAC_REQ_ALIGN_MOTOR, SAC_INDEFINITE )		!= NYCE_OK )
		return false;
	if (SacLock(m_id)								!= NYCE_OK ||
		SacSynchronize( m_id, SAC_REQ_LOCK, 1.0 )	!= NYCE_OK )
		return false;
	return true;
}

bool NyceAxis::Reset()
{
	if (m_status != AXIS_CONNECTED)
		return false;
	if (SacReset(m_id)											!= NYCE_OK ||
		SacSynchronize( m_id, SAC_REQ_RESET, SAC_INDEFINITE)	!= NYCE_OK ||
		SacLock( m_id )											!= NYCE_OK ||
		SacSynchronize( m_id, SAC_REQ_LOCK, SAC_INDEFINITE )	!= NYCE_OK )
		return false;
	return true;
}

bool NyceAxis::SetHomePars(const double &dMaxSpeed, const double &dMaxAcc, const double &dMaxJerk)
{
	if (m_status != AXIS_CONNECTED)
		return false;
	if (m_home_pars.velocity	 == dMaxSpeed &&
		m_home_pars.jerk		 == dMaxJerk  &&
		m_home_pars.acceleration == dMaxAcc   )
		return true;
	SAC_HOME_PARS buffer = m_home_pars;
	m_home_pars.velocity = dMaxSpeed;
	m_home_pars.jerk = dMaxJerk;
	m_home_pars.acceleration = dMaxAcc;
	if (SacWriteHomePars(m_id, &m_home_pars) != NYCE_OK)
	{
		m_home_pars = buffer;
		return false;
	}
	return true;
}

bool NyceAxis::GetHomePars(double &dMaxSpeed, double &dMaxAcc, double &dMaxJerk)
{
	if (m_status != AXIS_CONNECTED)
		return false;
	dMaxSpeed	= m_home_pars.velocity;
	dMaxAcc		= m_home_pars.acceleration;
	dMaxJerk	= m_home_pars.jerk;
	return  true;
}

bool NyceAxis::Home()
{
	if (m_status != AXIS_CONNECTED)
		return false;
	SAC_STATE state(SAC_NO_STATE);
	for (int i = 0; i<3; ++i)
		if (GetStatus(&state)	== true			&& 
			state				== SAC_READY	&&
			SacHome(m_id)		== NYCE_OK		)
			return true;
	return false;
}

bool NyceAxis::GetStatus(SAC_STATE *state)
{
	if (m_status != AXIS_CONNECTED)
		return false;
	SAC_SPG_STATE spgState;
	if(SacReadState( m_id, state, &spgState ) != NYCE_OK)
		return false;
	return true;
}

bool NyceAxis::GetPosition(double *value)
{
	if (m_status != AXIS_CONNECTED)
		return false;
	if(SacReadVariable(m_id,SAC_VAR_AXIS_POS,value) != NYCE_OK)
		return false;
	return true;
}

bool NyceAxis::MoveInterpolating()
{
	SAC_JOG_PARS a;
	a.acceleration=1;
	a.jerk=1;
	a.velocity=10;
	if(SacStartJog(m_id,&a) != NYCE_OK)
		return false;
	return true;
}

bool NyceAxis::GetMovePars(double &dMaxSpeed, double &dMaxAcc, double &dMaxJerk)
{
	if (m_status != AXIS_CONNECTED)
		return false;
	// 	dMaxSpeed	= m_move_pars.dMaxVel;
	// 	dMaxAcc		= m_move_pars.dMaxAcc;
	// 	dMaxJerk	= m_move_pars.dMaxJerk;
	dMaxSpeed	= 20;
	dMaxAcc		= 200;
	dMaxJerk	= 2000;
	return true;
}

// bool NyceAxis::GetInSegPars(const double &dDist,double &dVel, double &dAcc, double &dTime)
// {
// 	double dDistance(dDist);
// 	double dMaxJerk(m_move_pars.dMaxJerk * 2.0 / 3.0);
// 	double dMaxAcc(m_move_pars.dMaxAcc);
// 	double dMaxVel(m_move_pars.dMaxVel);
// 	if (dDistance <= 0) 
// 	{
// 		dMaxJerk = -dMaxJerk;
// 		dMaxAcc = -dMaxAcc;
// 		dMaxVel = -dMaxVel;
// 	}
// 	double dTime_JerkUniformly(pow(dDistance * 6.0 /dMaxJerk, 1.0 / 3.0 ));//�ȼӼ���ʱ��
// 	double dTime_Up2MaxAcc((dMaxAcc - dAcc) / dMaxJerk);//�ﵽ�����ٶ�ʱ��
// 	if (dTime_JerkUniformly > dTime_Up2MaxAcc)
// 	{ 
// 		dTime_JerkUniformly = dTime_Up2MaxAcc;//�ȼӼ���ʱ������
// 		double dDeffDistance(dDistance - dMaxJerk * pow(dTime_JerkUniformly, 3.0) / 6.0);//�ȼӼ��ٺ��ʣ�����
// 		dVel += dMaxJerk * dTime_JerkUniformly * dTime_JerkUniformly / 2.0;//�ȼӼ��ٺ���ٶ�
// 		double dTime_AccUniformly (sqrt(dDeffDistance * 2.0 / dMaxAcc));//�ȼ���ʱ��
// 		double dTime_Up2MacVel((dMaxVel - dVel) / dMaxAcc);//�ﵽ����ٶ�ʱ��
// 		if (dTime_AccUniformly > dTime_Up2MacVel)
// 		{
// 			dTime_AccUniformly = dTime_Up2MacVel;//�ȼ���ʱ������
// 			dDeffDistance -= dMaxAcc * dTime_AccUniformly * dTime_AccUniformly / 2.0;//�ȼ��ٺ�ʣ�����
// 			double dTime_VelUniformly(dDeffDistance / dMaxVel);//�����˶�ʱ��
// 			/****************************************
// 			�˶����̣�
// 				�ȼӼ���+�ȼ���+����
// 			ĩ�μ��ٶ�Ϊ0,
// 			ĩ���ٶ�ΪMax
// 			*****************************************/
// 			dTime = dTime_JerkUniformly + dTime_AccUniformly + dTime_VelUniformly;
// 			dAcc = 0;
// 			dVel = dMaxVel;
// 			bool a1 = (dDist < 0 ? dAcc < dMaxAcc : dAcc > dMaxAcc) ||
// 					  (dDist < 0 ? dVel < dMaxVel : dVel > dMaxVel) ;
// 			return true;
// 		}
// 		/****************************************
// 		�˶����̣�
// 			�ȼӼ���+�ȼ���
// 		ĩ�μ��ٶ�ΪMAX
// 		*****************************************/
// 		dTime = dTime_JerkUniformly + dTime_AccUniformly;
// 		dAcc = dMaxAcc;
// 		dVel += dMaxAcc * dTime_AccUniformly;
// 		bool a2 = (dDist < 0 ? dAcc < dMaxAcc : dAcc > dMaxAcc) ||
// 				  (dDist < 0 ? dVel < dMaxVel : dVel > dMaxVel) ;
// 		return true;
// 	}
// 	double dTime_Up2MacVel(sqrt((dMaxVel - dVel) / dMaxJerk * 2.0));//�ﵽ����ٶ�ʱ��
// 	if (dTime_JerkUniformly > dTime_Up2MacVel)
// 	{
// 		dTime_JerkUniformly = dTime_Up2MacVel;//�ȼӼ���ʱ������
// 		double dDeffDistance(dDistance - dMaxJerk * pow(dTime_JerkUniformly, 3.0) / 6.0);//�ȼӼ��ٺ��ʣ�����
// 		double dTime_VelUniformly(dDeffDistance / dMaxVel);//�����˶�ʱ��
// 		/****************************************
// 		�˶����̣�
// 			�ȼӼ���+����
// 		ĩ���ٶ�ΪMAX
// 		*****************************************/
// 		dTime = dTime_JerkUniformly + dTime_VelUniformly;
// 		dAcc += dMaxJerk * dTime_JerkUniformly;
// 		bool a6 = (dDist < 0 ? dAcc < dMaxAcc : dAcc > dMaxAcc) ||
// 			(dDist < 0 ? dVel < dMaxVel : dVel > dMaxVel) ;
// 		dVel = dMaxVel;
// 		bool a3 = (dDist < 0 ? dAcc < dMaxAcc : dAcc > dMaxAcc) ||
// 				  (dDist < 0 ? dVel < dMaxVel : dVel > dMaxVel) ;
// 		return true;
// 	}
// 	/****************************************
// 	�˶����̣�
// 		�ȼӼ���
// 	*****************************************/
// 	dTime = dTime_JerkUniformly;
// 	dAcc += dMaxJerk * dTime_JerkUniformly;
// 	bool a5 = (dDist < 0 ? dAcc < dMaxAcc : dAcc > dMaxAcc) ||
// 				(dDist < 0 ? dVel < dMaxVel : dVel > dMaxVel) ;
// 	dVel += dMaxJerk * dTime_JerkUniformly * dTime_JerkUniformly / 2.0;
// 	bool a4 = (dDist < 0 ? dAcc < dMaxAcc : dAcc > dMaxAcc) ||
// 				(dDist < 0 ? dVel < dMaxVel : dVel > dMaxVel) ;
// 	return true;
// }
// 
// bool NyceAxis::ModifySpeed(double &dRefSpeed,double &dOwnSpeed,const double &dAngle)
// {
// 	double dMaxVel(m_move_pars.dMaxVel);
// 	dOwnSpeed = dRefSpeed * tan(dAngle);
// 	return true;
// }