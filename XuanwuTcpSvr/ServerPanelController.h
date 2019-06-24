#pragma once
#include "ServerBaseController.h"
class ServerPanelController :
	public ServerBaseController
{
public:
	ServerPanelController(ModelObject* p_model);
	virtual ~ServerPanelController();
	void HandleGameRequest(GamePlayRequest& gpr) override;
};

