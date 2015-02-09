#include "StdAfx.h"
#include "NyceSystem.h"

NyceSystem::NyceSystem(const bool &bSim):
							m_status(SYSTEM_NON)
{
	Initialize(bSim);
}

NyceSystem::~NyceSystem(void)
{
	Terminate();
}

bool NyceSystem::Initialize(const bool &bSim)
{
	int a = NyceInit(NYCE_SIM);
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

const NyceNode* const NyceSystem::GetNode(const string &name)
{
	return m_nodeMap[name];
}