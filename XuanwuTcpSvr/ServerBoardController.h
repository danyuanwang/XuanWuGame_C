#pragma once
#include "ServerBaseController.h"
#include "ServerMapController.h"
#include "ServerPanelController.h"

class ServerBoardController :
	public ServerBaseController
{
public:
	ServerBoardController(ModelObject* p_model);
	virtual ~ServerBoardController();
	void HandleGameRequest(GamePlayRequest& gpr) override;
	const ServerMapController* GetServerMapController() const;
	const ServerPanelController* GetServerPanelController() const;
private:
	std::unique_ptr<ServerMapController> _up_servermapcontroller;
	std::unique_ptr<ServerPanelController> _up_serverpanelcontroller;
	
};

