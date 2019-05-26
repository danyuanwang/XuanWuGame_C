#include "MapController.h"

MapController::MapController(MapView* p_view, Map* p_model) :
	BaseController(p_view, p_model)
{
	_p_focused_controller = nullptr;
}

MapController::~MapController()
{

}

bool MapController::HandleSdlEvent(SDL_Event & e)
{
	bool result = false;
	for (auto itr = _mine_controllers.begin(); itr < _mine_controllers.end(); itr++)
	{
		result = (itr)->HandleSdlEvent(e);
		if (result)
		{
			_p_focused_controller = (MineController*)itr._Ptr;
			break;
		}
	}

	if (!result)
	{
		for (auto itr = _cell_controllers.begin(); itr < _cell_controllers.end(); itr++)
		{
			result = (itr)->HandleSdlEvent(e);
			if (result)
			{
				_p_focused_controller = (MineController*)itr._Ptr;
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
	}
}

void MapController::Invalidate()
{
	BaseController::Invalidate();

	_cell_controllers.clear();
	for (int i = 0; i < GetMapView()->_vector_cell.size(); i++)
	{
		CellView* p_cell_view = &(GetMapView()->_vector_cell[i]);
		int index = p_cell_view->GetIndex();
		CellController cell_controller(p_cell_view, const_cast<Cell*>(GetMapModel()->GetCell(index)));
		_cell_controllers.push_back(cell_controller);
	}

	_mine_controllers.clear();
	for (int i = 0; i < GetMapView()->_vector_mine.size(); i++)
	{
		MineView* p_mine_view = &(GetMapView()->_vector_mine[i]);
		int index = p_mine_view->GetIndex();
		MineController mine_controller(p_mine_view, const_cast<Mine*>(GetMapModel()->GetMine(index)));
		_mine_controllers.push_back(mine_controller);
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



