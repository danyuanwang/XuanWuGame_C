#pragma once
#include "SDL_events.h"
#include"BaseView.h"
#include"ModelObject.h"

class BaseController
{
protected:
	BaseView* _view; //no ownership
	ModelObject* _model; //no ownership

public:
	BaseController(BaseView* p_view, ModelObject* p_model);
	virtual ~BaseController();
	virtual void CheckSdlEvent(SDL_Event & e) = 0;
};

