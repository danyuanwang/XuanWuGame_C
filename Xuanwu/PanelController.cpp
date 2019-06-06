#include "PanelController.h"
#include "MineController.h"
#include "CellController.h"
#include "ShopController.h"
#include <typeinfo>

PanelController::PanelController(PanelView* p_view, Panel* p_model) :
	BaseController(p_view, p_model)
{
	_p_focused_controller = nullptr;

	Invalidate();
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

	if (_p_focused_controller)
	{
		PanelScale* p_scale = const_cast<PanelScale*>(GetPanelModel()->GetScale());
		p_scale->TakeDataObject(const_cast<const ModelObject *>(_p_focused_controller->GetModel()));
	}
}

void PanelController::Invalidate()
{
	BaseController::Invalidate();
}

Panel * PanelController::GetPanelModel()
{
	return static_cast<Panel*>(_p_model);
}

PanelView * PanelController::GetPanelView()
{
	return static_cast<PanelView *>(_p_view);
}
