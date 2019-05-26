#pragma once
#include "BaseController.h"
#include "PanelView.h"
#include "PanelActionController.h"
#include "PanelScaleController.h"
#include "memory"

class PanelController :
	public BaseController
{
private:
	BaseController* _p_focused_controller;
	std::unique_ptr<PanelActionController> _up_action_ctroller;
	std::unique_ptr< PanelScaleController> _up_scale_controller;

	Panel* GetPanelModel();
	PanelView* GetPanelView();

public:
	PanelController(PanelView* p_view, Panel* p_model);
	virtual ~PanelController();

	virtual bool HandleSdlEvent(SDL_Event & e) override;

	void SetFocusedController(BaseController* p_controller);

	void Invalidate() override;
};

