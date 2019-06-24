#pragma once
#include "ServerBaseController.h"
class ServerShopController :
	public ServerBaseController
{
public:
	ServerShopController(ModelObject* p_model);
	virtual ~ServerShopController();
	void HandleGameRequest(GamePlayRequest& gpr) override;
};

