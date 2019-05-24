#pragma once
#include "SDL_events.h"
#include"BaseView.h"
#include"ModelObject.h"

class BaseController
{
protected:
	BaseView* _view; //no ownership
	ModelObject* _model; //no ownership

	virtual bool OnKeyDown(SDL_Event & e);
	virtual bool OnKeyUp(SDL_Event & e);

	virtual bool OnMouseMove(SDL_Event & e);
	virtual bool OnMouseButtonDown(SDL_Event & e);
	virtual bool OnMouseButtonUp(SDL_Event & e);
	virtual bool OnMouseWheel(SDL_Event & e);

public:
	BaseController(BaseView* p_view, ModelObject* p_model);
	virtual ~BaseController();
	virtual void HandleSdlEvent(SDL_Event & e);
};

