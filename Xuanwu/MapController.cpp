#include "MapController.h"
#include "BuildCastleCommand.h"

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

	{
		result = (_up_shop_controller)->HandleSdlEvent(e);
		if (result)
		{
			_p_focused_controller = _up_shop_controller.get();
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
				if ((*itr)->GetCellType() != CellType_River && (*itr)->GetCellType() != CellType_Water)
				{
					BuildCastleCommand cmd{(*itr)->GetRowIndex(),(*itr)->GetColIndex()};
					cmd.Execute();
				}
				break;
			}
		}
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
			std::unique_ptr<MineController> p_mine_controller{new MineController(p_mine_view, const_cast<Mine*>(GetMapModel()->GetMine(index)))};
			_mine_controllers.push_back(std::move(p_mine_controller));
		}
		else
		{
			_mine_controllers[i]->Invalidate();
		}
	}

	ShopView* p_shop_view = (GetMapView()->_up_shop.get());
	if (_up_shop_controller.get() == nullptr)
	{
		_up_shop_controller = std::move(std::unique_ptr<ShopController>{ new ShopController(p_shop_view, const_cast<Shop*>(GetMapModel()->GetShop())) });
	}
	else
	{
		_up_shop_controller->Invalidate();
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
}

MapView * MapController::GetMapView() const
{
	return static_cast<MapView *>(_p_view);
}

Map * MapController::GetMapModel() const
{
	return static_cast<Map *>(_p_model);
}



