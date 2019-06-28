#include "ServerMapController.h"
#include "Map.h"



ServerMapController::ServerMapController(ModelObject* p_model)
	: ServerBaseController(p_model)
{
	const Map* p_map_model = static_cast<Map*>(p_model);
	_up_shop = std::move(std::unique_ptr<ServerShopController>{ new ServerShopController(const_cast<Shop*>(p_map_model->GetShop()))});

	for (int i = 0; i < p_map_model->GetTotalCellNumber(); i++)
	{
		_list_cell.push_back(std::move(std::unique_ptr< ServerCellController>{new ServerCellController(const_cast<Cell*>(p_map_model->GetCell(i)))}));
	}
	for (int i = 0; i < p_map_model->GetTotalMineNumber(); i++)
	{
		_list_mine.push_back(std::move(std::unique_ptr< ServerMineController>{new ServerMineController(const_cast<Mine*>(p_map_model->GetMine(i)))}));
	}
	for (int i = 0; i < p_map_model->GetTotalCastleNumber(); i++)
	{
		_list_castle.push_back(std::move(
			std::unique_ptr< ServerCastleController>{new ServerCastleController(const_cast<Castle*>(p_map_model->GetCastle(i)))}
		));
	}
}


ServerMapController::~ServerMapController()
{
}

void ServerMapController::HandleGameRequest(GamePlayRequest & gpr)
{
	switch (gpr.GetActionType())
	{
	case GameObjectAction_BuildCastle:
	{
		int col = gpr.GetKeyValue<int>("col_index");
		int row = gpr.GetKeyValue<int>("row_index");
		auto key = gpr.GetKeyValue("client_name").c_str();
		Map* p_map = static_cast<Map*>(_p_model);
		p_map->AddCastle(row, col, key);
		
		auto server_castle_controller =std::unique_ptr<ServerCastleController>( new ServerCastleController(const_cast <Castle*>(p_map->GetCastle(row, col))));
		_list_castle.push_back(std::move(server_castle_controller));
	}
	default:
		break;
	}

	_up_shop->HandleGameRequest(gpr);
	for (auto itr = _list_cell.begin(); itr != _list_cell.end(); itr++)
	{
		(*itr)->HandleGameRequest(gpr);
	}
	for (auto itr = _list_mine.begin(); itr != _list_mine.end(); itr++)
	{
		(*itr)->HandleGameRequest(gpr);
	}
	for (auto itr = _list_castle.begin(); itr != _list_castle.end(); itr++)
	{
		
		(*itr)->HandleGameRequest(gpr);
	}

}