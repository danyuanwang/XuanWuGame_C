#pragma once
#include "ServerBaseController.h"
class ServerMineController :
	public ServerBaseController
{
public:
	ServerMineController(ModelObject* p_model);
	virtual ~ServerMineController();
	void HandleGameRequest(GamePlayRequest& gpr) override;

};

