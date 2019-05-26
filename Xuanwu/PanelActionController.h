#pragma once
#include "BaseController.h"
#include"PanelActionView.h"
#include"ModelObject.h"

class PanelActionController :
	public BaseController
{
public:
	PanelActionController(PanelActionView* p_view, ModelObject* p_model);
	virtual ~PanelActionController();

	bool HandleSdlEvent(SDL_Event & e) override;

	void Invalidate() override;

};

