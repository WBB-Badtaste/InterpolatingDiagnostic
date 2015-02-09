#pragma once

#include "NyceNode.h"

using namespace std;

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
 	const NyceNode* const			GetNode(const string&);
private:
	SYSTEM_STATUS					m_status;
	map<string, NyceNode*>			m_nodeMap;
};

