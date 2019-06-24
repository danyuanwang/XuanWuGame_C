#pragma once
#include "ServerBaseController.h"
class ServerCastleController :
	public ServerBaseController
{
public:
	ServerCastleController(ModelObject* p_model);
	virtual ~ServerCastleController();
	void HandleGameRequest(GamePlayRequest& gpr) override;
};

