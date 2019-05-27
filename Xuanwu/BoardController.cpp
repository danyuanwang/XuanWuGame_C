#include "BoardController.h"
BoardController::BoardController(BoardView* p_view, Board* p_model) :
	BaseController(p_view, p_model),
	_map_controller(const_cast<MapView*>(GetBoardView()->GetMapView()), const_cast<Map*>(GetBoardModel()->GetMap())),
	_panel_controller(const_cast<PanelView*>(GetBoardView()->GetPanelView()), const_cast<Panel*>(GetBoardModel()->GetPanel()))
{
	_p_captured_controller = false;

	Invalidate();

}


BoardController::~BoardController()
{
}

bool BoardController::HandleSdlEvent(SDL_Event & e)
{
	bool result = _map_controller.HandleSdlEvent(e);
	BaseController* captured_controller = nullptr;
	if (result)
	{
		captured_controller = _map_controller.GetFocusedController();
	}
	else
	{
		result = _panel_controller.HandleSdlEvent(e);
		if (result)
		{
			captured_controller = _panel_controller.GetFocusedController();
		}
	}
	if (captured_controller != nullptr &&captured_controller != _p_captured_controller)
	{
		if(_p_captured_controller) _p_captured_controller->CaptureFocus(false);
		_p_captured_controller = captured_controller;
		_p_captured_controller->CaptureFocus(true);
		_panel_controller.SetFocusedController(_p_captured_controller);
	}

	return result;
}

void BoardController::Invalidate()
{
	BaseController::Invalidate();

	_map_controller.Invalidate();
	_panel_controller.Invalidate();
}


BoardView * BoardController::GetBoardView()
{
	return static_cast<BoardView*>(_p_view);
}

Board * BoardController::GetBoardModel()
{
	return static_cast<Board*>(_p_model);
}
