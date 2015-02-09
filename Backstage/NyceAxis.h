#pragma once

using namespace std;

class NyceAxis
{
public:
	NyceAxis(const string&);
	~NyceAxis(void);

	AXIS_STATUS		Status();
	bool			Connect();
	bool			Disconnect();
private:
	const string	m_name;
	SAC_AXIS		m_id;
	AXIS_STATUS		m_status;
};

