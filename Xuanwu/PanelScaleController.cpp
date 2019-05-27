#include "PanelScaleController.h"



PanelScaleController::PanelScaleController(PanelScaleView* p_view, ModelObject* p_model) :
	BaseController(p_view, p_model)
{
	Invalidate();
}


PanelScaleController::~PanelScaleController()
{
}

bool PanelScaleController::HandleSdlEvent(SDL_Event & e)
{
	return BaseController::HandleSdlEvent(e);
}

void PanelScaleController::Invalidate()
{
	BaseController::Invalidate();
}
