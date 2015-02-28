#pragma once

using namespace std;

typedef struct axis_move_pars 
{
	double dMaxVel;
	double dMaxAcc;
	double dMaxJerk;
}AXIS_MOVE_PARS;

class NyceAxis
{
public:
	NyceAxis(const string&);
	~NyceAxis(void);

	AXIS_STATUS		Status();
	bool			Connect();
	bool			Disconnect();
	bool			Align();
	bool			Home();
	bool			Reset();
	bool			MoveInterpolating();
	bool			GetStatus(SAC_STATE *state);
	bool			GetPosition(double *);
	bool			SetHomePars(const double &dMaxSpeed, const double &dMaxAcc, const double &dMaxJerk);
	bool			GetHomePars(double &dMaxSpeed,  double &dMaxAcc,  double &dMaxJerk);
	bool			GetMovePars(double &dMaxSpeed,  double &dMaxAcc,  double &dMaxJerk);
	/******************************************************************************
    ����岹�������ز���
    =====================================
    Arguments:
        dDistance	(in)		�˶�����
		dCurVel		(in)		��ǰ�ٶ�
		dCurAcc		(in)		��ǰ���ٶ�
		dTime		(out)		����ʱ��
		dNextAcc	(out)		��ĩ���ٶ�
		dNextVel	(out)		��ĩ�ٶ�
    Return value:
    TRUE on success, FALSE on failure.
	******************************************************************************/
	bool			GetInSegPars(const double &dDistance,double &dVel, double &dAcc, double &dTime);
	/******************************************************************************
    ����岹�������ز���
    =====================================
    Arguments:
        dDistance	(in)		�˶�����
		dCurVel		(in)		��ǰ�ٶ�
		dCurAcc		(in)		��ǰ���ٶ�
		dTime		(out)		����ʱ��
		dNextAcc	(out)		��ĩ���ٶ�
		dNextVel	(out)		��ĩ�ٶ�
    Return value:
    TRUE on success, FALSE on failure.
	******************************************************************************/
	bool			ModifySpeed(double &dRefSpeed,double &dOwnSpeed,const double &dAngle);
	const string				m_name;
	SAC_AXIS					m_id;
	AXIS_STATUS					m_status;
	SAC_CONFIGURE_AXIS_PARS		m_configure_pars;
	SAC_HOME_PARS				m_home_pars;
	AXIS_MOVE_PARS				m_move_pars;
private:
	
};


 

