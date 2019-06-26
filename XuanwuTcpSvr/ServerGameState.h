#pragma once
#include "ServerBaseState.h"
class ServerGameState :
	public ServerBaseState
{
public:
	virtual ~ServerGameState();
	virtual void HandleGameRequest(ServerBaseController *p_controller, GamePlayRequest& gpr) override;

protected :
	ServerGameState();

};

