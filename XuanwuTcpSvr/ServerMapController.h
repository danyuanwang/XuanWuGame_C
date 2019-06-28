#pragma once
#include "ServerBaseController.h"
#include "ServerMineController.h"
#include "ServerCellController.h"
#include "ServerCastleController.h"
#include "ServerShopController.h"
class ServerMapController :
	public ServerBaseController
{
public:
	ServerMapController(ModelObject* p_model);
	virtual ~ServerMapController();
	void HandleGameRequest(GamePlayRequest& gpr) override;
	
private:
	std::vector<std::unique_ptr<ServerMineController>>_list_mine;
	std::vector<std::unique_ptr<ServerCellController>>_list_cell;
	std::vector<std::unique_ptr<ServerCastleController>>_list_castle;
	std::unique_ptr<ServerShopController>_up_shop;

};

