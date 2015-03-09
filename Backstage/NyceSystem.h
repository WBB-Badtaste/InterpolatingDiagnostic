#pragma once

#include "NyceNode.h"

using namespace std;

typedef struct axis_info
{
	string nodeName;
	string axisName;
}*const PCAXIS_INFO,AXIS_INFO;

typedef struct interpolation_info
{
	double	dCurVelX;		//当前速度X
	double	dCurVelY;		//当前速度Y
	double  dUltVelX;		//最终速度X
	double	dUltVelY;		//最终速度Y
	double	dCurPosX;		//当前位置X
	double	dCurPosY;		//当前位置Y
	double	dRadius;		//圆的半径
	int		iSegAmount;		//段数
	bool	bInverse;		//逆时针移动
	double	dAngleOffset;	//路径绕初始点的顺时针旋转角度
}IN_INFO;

class NyceSystem
{
public:
	NyceSystem(const bool&);
	~NyceSystem(void);

 	SYSTEM_STATUS					Status();
	bool							Initialize(const bool&);
 	bool							Terminate();
 	bool							AddNode(const string&);
 	bool							DelNode(const string&);
 	bool							DelAllNode();
 	unsigned						GetNodeSum();
 	NyceNode* const					GetNode(const string&);
	bool							SetInAxis(PCAXIS_INFO pAxis_infos,int sum);
	bool							GetInSeg_Cicle_xy(const IN_INFO * const pInInfo,IN_SED_PRT const pSegments);
	bool							MoveInterpolating(IN_SED_PRT pSegments,const int &iSum,const bool &bAbsolute);
private:
	SYSTEM_STATUS					m_status;
	map<string, NyceNode*>			m_nodeMap;
	NyceAxis*						m_pAxisX;
	NyceAxis*						m_pAxisY;
	NyceAxis*						m_pAxisZ;

	bool							GetInSegPars(const double &dDistance,double &dVel, double &dAcc, double &dTime,const double &dMVel,const double &dMAcc,const double &dJerk);
	bool							ModifyInSegPars_A(const double &dDistance,double &dVel,double &dAcc, double &dTime,const double &dMVel,const double &dMAcc,const double &dJerk);
	bool							ModifyInSegPars_V(const double &dDistance,double &dVel,double &dAcc, double &dTime,const double &dMVel,const double &dMAcc,const double &dJerk);
};

