#pragma  once

enum AXIS_STATUS
{
	AXIS_NON				= 0,
	AXIS_CONNECTING			= 1,
	AXIS_CONNECTED			= 2,
	AXIS_DISCONNECTING		= 3,
	AXIS_DISCONNECTED		= 4
};

enum NODE_STATUS
{
	NODE_NON				= 0,
	NODE_CONNECTING			= 1,
	NODE_CONNECTED			= 2,
	NODE_DISCONNECTING		= 3,
	NODE_DISCONNECTED		= 4
};

enum SYSTEM_STATUS
{
	SYSTEM_NON				= 0,
	SYSTEM_INITIALIZING		= 1,
	SYSTEM_INITIALIZED		= 2,
	SYSTEM_TERMINATING		= 3,
	SYSTEM_TERMINATED		= 4
};

typedef struct InSeg
{
	int iNo;
	double dPosX;
	double dPosY;
	double dVelX;
	double dVelY;
	double dTime;
}IN_SEG,*IN_SED_PRT;