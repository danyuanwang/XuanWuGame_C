#pragma once
#include "ServerBaseController.h"
class ServerArmyController :
	public ServerBaseController
{
public:
	ServerArmyController(ModelObject* p_model);
	virtual ~ServerArmyController();
	void HandleGameRequest(GamePlayRequest& gpr) override;
};

