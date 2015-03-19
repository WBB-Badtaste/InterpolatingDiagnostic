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
	if (SacConnect(m_name.c_str(), &m_id)	!= NYCE_OK )
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
// 	if (SacShutdown(m_id)									!= NYCE_OK ||
// 		SacSynchronize( m_id, SAC_REQ_SHUTDOWN, 1.0 )		!= NYCE_OK )
// 		return false;
// 	if (SacInitialize( m_id, SAC_USE_FLASH )				!= NYCE_OK ||
// 		SacSynchronize( m_id, SAC_REQ_INITIALIZE, 1.0 )		!= NYCE_OK )
// 		return false;
	if (SacReset( m_id)										!= NYCE_OK ||
		SacSynchronize( m_id, SAC_REQ_RESET, 1.0 )			!= NYCE_OK )
		return false;
// 	if (SacGetAxisConfiguration( m_id, &m_configure_pars )	!= NYCE_OK )
// 		return false;
	if (/*m_configure_pars.motorType										== SAC_BRUSHLESS_AC_MOTOR &&*/
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
		SacSynchronize( m_id, SAC_REQ_LOCK, 1.0 )	!= NYCE_OK )
		return false;
	return true;
}

bool NyceAxis::SetHomePars(const double &dMaxSpeed, const double &dMaxAcc, const double &dMaxJerk)
{
	if (m_status != AXIS_CONNECTED)
		return false;
	SAC_HOME_PARS home_pars;
	home_pars.velocity = dMaxSpeed;
	home_pars.jerk = dMaxJerk;
	home_pars.acceleration = dMaxAcc;
	if (SacWriteHomePars(m_id, &home_pars) != NYCE_OK)
		return false;
	return true;
}

bool NyceAxis::GetHomePars(double &dMaxSpeed, double &dMaxAcc, double &dMaxJerk)
{
	if (m_status != AXIS_CONNECTED)
		return false;
	SAC_HOME_PARS home_pars;
	if (SacReadHomePars(m_id,&home_pars) != NYCE_OK)
		return false;
	dMaxSpeed	= home_pars.velocity;
	dMaxAcc		= home_pars.acceleration;
	dMaxJerk	= home_pars.jerk;
	return  true;
}

bool NyceAxis::SetMotionPars(const double &dMaxSpeed, const double &dMaxAcc, const double &dMaxJerk)
{
	if (m_status != AXIS_CONNECTED												   ||
		SacWriteParameter(m_id,SAC_PAR_MAX_VEL_NORMAL_MODE,dMaxSpeed)	!= NYCE_OK ||
		SacWriteParameter(m_id,SAC_PAR_MAX_ACC_NORMAL_MODE,dMaxAcc)		!= NYCE_OK ||
		SacWriteParameter(m_id,SAC_PAR_MAX_JERK_NORMAL_MODE,dMaxJerk)	!= NYCE_OK )
		return false;
	return true;
}

bool NyceAxis::GetMotionPars(double &dMaxSpeed, double &dMaxAcc, double &dMaxJerk)
{
	if (m_status != AXIS_CONNECTED												   ||
		SacReadParameter(m_id,SAC_PAR_MAX_VEL_NORMAL_MODE,&dMaxSpeed)	!= NYCE_OK ||
		SacReadParameter(m_id,SAC_PAR_MAX_ACC_NORMAL_MODE,&dMaxAcc)		!= NYCE_OK ||
		SacReadParameter(m_id,SAC_PAR_MAX_JERK_NORMAL_MODE,&dMaxJerk)	!= NYCE_OK )
		return false;
	return  true;
}
bool NyceAxis::SetStopPars(const double &dMaxAcc)
{
	if (m_status != AXIS_CONNECTED										   ||
		SacWriteParameter(m_id,SAC_PAR_QUICKSTOP_ACC,dMaxAcc)	!= NYCE_OK )
		return false;
	return true;
}
bool NyceAxis::GetStopPars(double &dMaxAcc)
{
	if (m_status != AXIS_CONNECTED										   ||
		SacReadParameter(m_id,SAC_PAR_QUICKSTOP_ACC,&dMaxAcc)	!= NYCE_OK )
		return false;
	return true;
}
bool NyceAxis::Home()
{
	if (m_status != AXIS_CONNECTED)
		return false;
	SAC_STATE state(SAC_NO_STATE);
	for (int i = 0; i<3; ++i)
		if (GetStatus(&state)	== true			&& 
			state				== SAC_READY	&&
			SacHome(m_id)		== NYCE_OK		&&
			SacSynchronize( m_id, SAC_REQ_HOMING_COMPLETED, 1.0 ) == NYCE_OK )
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

bool NyceAxis::SetInPars(SAC_CUB_PARS inPars[],const int &iSum)
{
	if( SacClearInterpolantBuffer(m_id)				!= NYCE_OK )
		return false;
	SAC_CUB_PARS *p = inPars;
	for (int sum(iSum);sum>0;sum -= 16)
	{
		if (sum > 16)
		{
			if(SacWriteCubicIntBuffer(m_id,16,p) !=NYCE_OK)
				return false;
		}
		else
		{
			if(SacWriteCubicIntBuffer(m_id,sum,p) !=NYCE_OK)
				return false;
		}
		p += 16;
	}
	
	return true; 
}

bool NyceAxis::MoveInterpolating()
{
	if (SacStartInterpolation(m_id) != NYCE_OK )
		return false;
	return true;
}

