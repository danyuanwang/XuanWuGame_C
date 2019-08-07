#include "MapController.h"
#include "BuildCastleCommand.h"
#include "MoveArmyCommand.h"

MapController::MapController(MapView* p_view, Map* p_model) :
	BaseController(p_view, p_model)
{
	_p_focused_controller = nullptr;

	Invalidate();
}

MapController::~MapController()
{

}


bool MapController::HandleSdlEvent(SDL_Event & e)

{
	bool result = false;
	BaseController* p_last_focused_controller = _p_focused_controller;
	int click_pos_row = -1;
	int click_pos_col = -1;
	for (auto itr = _army_controllers.begin(); itr < _army_controllers.end(); itr++)
	{
		result = (*itr)->HandleSdlEvent(e);
		if (result)
		{
			_p_focused_controller = itr._Ptr->get();
			Army *p_army = static_cast<Army*>((*itr)->GetModel());
			click_pos_row = p_army->GetRowIndex();
			click_pos_col = p_army->GetColIndex();
			break;
		}
	}

	if (!result)
	{
		if (_up_shop_controller.get() != nullptr)
		{
			result = (_up_shop_controller)->HandleSdlEvent(e);
			if (result)
			{
				_p_focused_controller = _up_shop_controller.get();
				Shop *p_shop = static_cast<Shop*>((_up_shop_controller)->GetModel());
				click_pos_row = p_shop->GetRowIndex();
				click_pos_col = p_shop->GetColIndex();
			}
		}
	}
	if (!result)
	{
		for (auto itr = _mine_controllers.begin(); itr < _mine_controllers.end(); itr++)
		{
			result = (*itr)->HandleSdlEvent(e);
			if (result)
			{
				_p_focused_controller = itr._Ptr->get();
				Mine *p_mine = static_cast<Mine*>((*itr)->GetModel());
				click_pos_row = p_mine->GetRowIndex();
				click_pos_col = p_mine->GetColIndex();
				break;
			}
		}

	}
	if (!result)
	{
		for (auto itr = _castle_controllers.begin(); itr < _castle_controllers.end(); itr++)
		{
			result = (*itr)->HandleSdlEvent(e);
			if (result)
			{
				_p_focused_controller = itr._Ptr->get();
				Castle *p_castle = static_cast<Castle*>((*itr)->GetModel());
				click_pos_row = p_castle->GetRowIndex();
				click_pos_col = p_castle->GetColIndex();
				break;
			}
		}

	}

	if (!result)
	{
		for (auto itr = _cell_controllers.begin(); itr < _cell_controllers.end(); itr++)
		{
			result = (*itr)->HandleSdlEvent(e);
			if (result)
			{
				_p_focused_controller = itr._Ptr->get();
				Cell *p_cell = static_cast<Cell*>((*itr)->GetModel());
				click_pos_row = p_cell->GetRowIndex();
				click_pos_col = p_cell->GetColIndex();
				if ((*itr)->GetCellType() != CellType_River && (*itr)->GetCellType() != CellType_Water)
				{
					BuildCastleCommand cmd{ (*itr)->GetRowIndex(),(*itr)->GetColIndex() };
					cmd.Execute();
				}
				break;
			}
		}
	}
	//check if the last focus is on a army, if yes, send move command to move the army to the current focused position
	if (p_last_focused_controller != nullptr&& typeid(*p_last_focused_controller) == typeid(ArmyController) && click_pos_col >= 0 && click_pos_row >= 0)
	{
		MoveArmyCommand cmd{
			click_pos_row,
			click_pos_col,
			(p_last_focused_controller)->GetModel()->GetModelObjectID() };
		cmd.Execute();
	}



	return result;
}

BaseController * MapController::GetFocusedController() const
{
	return _p_focused_controller;
}


void MapController::CaptureFocus(bool captured)
{
	_focus_captured = captured;

	if (_p_focused_controller)
	{
		_p_focused_controller->CaptureFocus(captured);

		if (!captured)
		{
			_p_focused_controller = nullptr;
		}
	}
}

void MapController::Invalidate()
{
	BaseController::Invalidate();

	for (int i = 0; i < GetMapView()->_vector_cell.size(); i++)
	{
		CellView* p_cell_view = GetMapView()->_vector_cell[i].get();
		int index = p_cell_view->GetIndex();
		if (_cell_controllers.size() <= i)
		{
			std::unique_ptr<CellController> p_cell_controller{ new  CellController(p_cell_view, const_cast<Cell*>(GetMapModel()->GetCell(index))) };
			_cell_controllers.push_back(std::move(p_cell_controller));
		}
		else
		{
			_cell_controllers[i]->Invalidate();
		}
	}

	for (int i = 0; i < GetMapView()->_vector_mine.size(); i++)
	{
		MineView* p_mine_view = GetMapView()->_vector_mine[i].get();
		int index = p_mine_view->GetIndex();
		if (_mine_controllers.size() <= i)
		{
			std::unique_ptr<MineController> p_mine_controller{ new MineController(p_mine_view, const_cast<Mine*>(GetMapModel()->GetMine(index))) };
			_mine_controllers.push_back(std::move(p_mine_controller));
		}
		else
		{
			_mine_controllers[i]->Invalidate();
		}
	}

	ShopView* p_shop_view = (GetMapView()->_up_shop.get());
	if (p_shop_view != nullptr)
	{
		if (_up_shop_controller.get() == nullptr)
		{
			_up_shop_controller = std::move(std::unique_ptr<ShopController>{ new ShopController(p_shop_view, const_cast<Shop*>(GetMapModel()->GetShop())) });
		}
		else
		{
			_up_shop_controller->Invalidate();
		}
	}

	for (int i = 0; i < GetMapView()->_vector_castle.size(); i++)
	{
		CastleView* p_castle_view = GetMapView()->_vector_castle[i].get();
		int index = p_castle_view->GetIndex();
		if (_castle_controllers.size() <= i)
		{
			std::unique_ptr<CastleController> p_castle_controller{ new CastleController(p_castle_view, const_cast<Castle*>(GetMapModel()->GetCastle(index))) };
			_castle_controllers.push_back(std::move(p_castle_controller));
		}
		else
		{
			_castle_controllers[i]->Invalidate();
		}
	}

	for (int i = 0; i < GetMapView()->_vector_army.size(); i++)
	{
		ArmyView* p_army_view = GetMapView()->_vector_army[i].get();
		int index = p_army_view->GetIndex();
		if (_army_controllers.size() <= i)
		{
			std::unique_ptr<ArmyController> p_army_controller{ new ArmyController(p_army_view, const_cast<Army*>(GetMapModel()->GetArmy(index))) };
			_army_controllers.push_back(std::move(p_army_controller));
		}
		else
		{
			_army_controllers[i]->Invalidate();
		}
	}
}

MapView * MapController::GetMapView() const
{
	return static_cast<MapView *>(_p_view);
}

Map * MapController::GetMapModel() const
{
	return static_cast<Map *>(_p_model);
}



