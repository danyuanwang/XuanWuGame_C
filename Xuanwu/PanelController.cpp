#include "PanelController.h"



PanelController::PanelController(PanelView* p_view, Panel* p_model) :
	BaseController(p_view, p_model)
{
	_p_focused_controller = nullptr;
}


PanelController::~PanelController()
{
}

bool PanelController::HandleSdlEvent(SDL_Event & e)
{
	return false;
}

void PanelController::SetFocusedController(BaseController * p_controller)
{
	_p_focused_controller = p_controller;
}
