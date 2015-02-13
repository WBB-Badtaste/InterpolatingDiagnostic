#include "StdAfx.h"
#include "NyceNode.h"

using namespace std;

NyceNode::NyceNode(const string &name):
								m_name(name),
								m_id(0),
								m_status(NODE_NON)
{
	Connect();
}

NyceNode::~NyceNode(void)
{
	DelAllAxis();
	if (m_status != NODE_DISCONNECTED)
		Disconnect();
}

bool NyceNode::Connect()
{
	if (NhiConnect(m_name.c_str(), &m_id) == NYCE_OK)
	{
		m_status = NODE_CONNECTED;
		return true;
	}
	else
		return false;
}

bool NyceNode::Disconnect()
{
	if (m_status != NODE_CONNECTED)
		return false;
	if (DelAllAxis() == false)
		return false;
	if (NhiDisconnect(m_id) == NYCE_OK)
	{
		m_status = NODE_DISCONNECTED;
		return true;
	}
	else
		return false;
}

NODE_STATUS NyceNode::Status()
{
	return m_status;
}

bool NyceNode::AddAxis(const string &name)
{
	m_axisMap[name] = new NyceAxis(name);
	return m_axisMap[name]->Status()==AXIS_CONNECTED ? true : false;
}

bool NyceNode::DelAxis(const string &name)
{
	if (m_axisMap[name]->Status() == AXIS_CONNECTED)
		if (m_axisMap[name]->Disconnect() != NYCE_OK)
			return false;
	delete m_axisMap[name];
	m_axisMap.erase(name);
	return true;
}

bool NyceNode::DelAllAxis()
{
	while (m_axisMap.size() != 0)
		if (DelAxis(m_axisMap.begin()->first) == false)
			return false;
	return true;
}

unsigned NyceNode::GetAxisSum()
{
	return m_axisMap.size();
}

NyceAxis* const NyceNode::GetAxis(const string& axisName)
{
	return m_axisMap[axisName];
}