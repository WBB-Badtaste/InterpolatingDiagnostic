#pragma once

#include "NyceAxis.h"

using namespace std;

class NyceNode
{
public:
	NyceNode(const string&);
	~NyceNode(void);

	NODE_STATUS						Status();
	bool							Connect();
	bool							Disconnect();
	bool							AddAxis(const string&);
	bool							DelAxis(const string&);
	bool							DelAllAxis();
	unsigned						GetAxisSum();
	NyceAxis* const					GetAxis(const string&);
private:
	const string					m_name;
	NHI_NODE						m_id;
	NODE_STATUS						m_status;
	map<string, NyceAxis*>			m_axisMap;
};

