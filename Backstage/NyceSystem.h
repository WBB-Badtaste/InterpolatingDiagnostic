#pragma once

#include "NyceNode.h"

using namespace std;

typedef struct axis_info
{
	string nodeName;
	string axisName;
}*const PCAXIS_INFO,AXIS_INFO;

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
	bool							GetInSeg_Cicle_xy(const double *dCurX, const double *dCurY, const double *dRadius,IN_SED_PRT const pSegments,const int * segSum);
private:
	SYSTEM_STATUS					m_status;
	map<string, NyceNode*>			m_nodeMap;
	NyceAxis*						m_pAxisX;
	NyceAxis*						m_pAxisY;
	NyceAxis*						m_pAxisZ;

	bool							GetInSegPars(const double &dDistance,double &dVel, double &dAcc, double &dTime,const double &dMVel,const double &dMAcc,const double &dMJerk);
};

