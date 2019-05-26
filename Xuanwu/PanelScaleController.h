#pragma once
#include "BaseController.h"
#include"PanelScaleView.h"
#include"ModelObject.h"

class PanelScaleController :
	public BaseController
{
public:
	PanelScaleController(PanelScaleView* p_view, ModelObject* p_model);
	virtual ~PanelScaleController();

	bool HandleSdlEvent(SDL_Event & e) override;

};

