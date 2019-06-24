#pragma once
#include "ServerBaseController.h"
class ServerPlayerController :
	public ServerBaseController
{
public:
	ServerPlayerController(ModelObject* p_model);
	virtual ~ServerPlayerController();
	void HandleGameRequest(GamePlayRequest& gpr) override;
};

