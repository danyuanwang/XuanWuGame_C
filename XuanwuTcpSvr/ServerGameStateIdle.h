#pragma once
#include "ServerGameController.h"
#include "ServerGameState.h"
class ServerGameStateIdle :
	public ServerGameState
{
public:
	ServerGameStateIdle();
	virtual ~ServerGameStateIdle();

	virtual void HandleGameRequest(ServerBaseController* p_controller, GamePlayRequest& gpr) override;

};

