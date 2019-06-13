#include "MapController.h"
#include "BuildCastleCommand.h"

MapController::MapController(MapView* p_view, Map* p_model) :
	BaseController(p_view, p_model)
{
	_p_focused_controller = nullptr;

	for (int i = 0; i < GetMapView()->_vector_cell.size(); i++)
	{
		CellView* p_cell_view = &(GetMapView()->_vector_cell[i]);
		int index = p_cell_view->GetIndex();
		CellController cell_controller(p_cell_view, const_cast<Cell*>(GetMapModel()->GetCell(index)));
		_cell_controllers.push_back(cell_controller);
	}

	for (int i = 0; i < GetMapView()->_vector_mine.size(); i++)
	{
		MineView* p_mine_view = &(GetMapView()->_vector_mine[i]);
		int index = p_mine_view->GetIndex();
		MineController mine_controller(p_mine_view, const_cast<Mine*>(GetMapModel()->GetMine(index)));
		_mine_controllers.push_back(mine_controller);
	}

	ShopView* p_shop_view = (GetMapView()->_up_shop.get());
	_up_shop_controller = std::move(std::unique_ptr<ShopController>{ new ShopController(p_shop_view, const_cast<Shop*>(GetMapModel()->GetShop())) });

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
			_p_focused_controller = (ShopController*)_up_shop_controller.get();
		}
	}

	if (!result)
	{
		for (auto itr = _mine_controllers.begin(); itr < _mine_controllers.end(); itr++)
		{
			result = (itr)->HandleSdlEvent(e);
			if (result)
			{
				_p_focused_controller = (MineController*)itr._Ptr;
				break;
			}
		}
	}

	if (!result)
	{
		for (auto itr = _cell_controllers.begin(); itr < _cell_controllers.end(); itr++)
		{
			result = (itr)->HandleSdlEvent(e);
			if (result)
			{
				_p_focused_controller = (CellController*)itr._Ptr;
				if (itr->GetCellType() != CellType_River && itr->GetCellType() != CellType_Water)
				{
					BuildCastleCommand cmd{itr->GetRowIndex(),itr->GetColIndex()};
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

	for (auto itr = _cell_controllers.begin(); itr < _cell_controllers.end(); itr++)
	{
		itr->Invalidate();
	}

	for (auto itr = _mine_controllers.begin(); itr < _mine_controllers.end(); itr++)
	{
		itr->Invalidate();
	}

	_up_shop_controller->Invalidate();
}

MapView * MapController::GetMapView() const
{
	return static_cast<MapView *>(_p_view);
}

Map * MapController::GetMapModel() const
{
	return static_cast<Map *>(_p_model);
}



