#include "PanelActionController.h"



PanelActionController::PanelActionController(PanelActionView* p_view, ModelObject* p_model) :
	BaseController(p_view, p_model)
{
}


PanelActionController::~PanelActionController()
{
}

bool PanelActionController::HandleSdlEvent(SDL_Event & e)
{
	return BaseController::HandleSdlEvent(e);
}
