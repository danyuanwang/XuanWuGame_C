#pragma once
#include "ServerBaseController.h"
class ServerCellController :
	public ServerBaseController
{
public:
	ServerCellController(ModelObject* p_model);
	virtual ~ServerCellController();
	void HandleGameRequest(GamePlayRequest& gpr) override;
};

