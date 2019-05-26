#include "PanelScaleController.h"



PanelScaleController::PanelScaleController(PanelScaleView* p_view, ModelObject* p_model) :
	BaseController(p_view, p_model)
{
}


PanelScaleController::~PanelScaleController()
{
}

bool PanelScaleController::HandleSdlEvent(SDL_Event & e)
{
	return BaseController::HandleSdlEvent(e);
}
