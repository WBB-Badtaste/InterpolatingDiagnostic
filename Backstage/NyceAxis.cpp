#include "StdAfx.h"
#include "NyceAxis.h"
#include "sacapi.h"

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
	if (SacConnect(m_name.c_str(), &m_id) == NYCE_OK)
	{
		m_status = AXIS_CONNECTED;
		return true;
	}
	else
		return false;
}

bool NyceAxis::Disconnect()
{
	if (m_status != AXIS_CONNECTED)
		return false;
	if (SacDisconnect(m_id) == NYCE_OK)
	{
		m_status = AXIS_DISCONNECTED;
		return true;
	}
	else
		return false;
}

AXIS_STATUS NyceAxis::Status()
{
	return m_status;
}
