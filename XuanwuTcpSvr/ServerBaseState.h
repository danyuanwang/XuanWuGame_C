#pragma once
#include "GamePlayRequest.h"
#include "ServerBaseController.h"

class ServerBaseState
{
public:
	virtual ~ServerBaseState();
	virtual void HandleGameRequest(ServerBaseController *p_controller, GamePlayRequest & gpr) = 0;

protected:
	ServerBaseState();
};

