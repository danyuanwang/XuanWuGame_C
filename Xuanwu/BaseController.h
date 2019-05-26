#pragma once
#include "SDL_events.h"
#include"BaseView.h"
#include"ModelObject.h"

class BaseController
{
protected:
	BaseView* _p_view; //no ownership
	ModelObject* _p_model; //no ownership
	bool _focus_captured;
	virtual bool OnKeyDown(SDL_Event & e);
	virtual bool OnKeyUp(SDL_Event & e);
	virtual bool OnMouseMove(SDL_Event & e);
	virtual bool OnMouseButtonDown(SDL_Event & e);
	virtual bool OnMouseButtonUp(SDL_Event & e);
	virtual bool OnMouseWheel(SDL_Event & e);

public:
	BaseController(BaseView* p_view, ModelObject* p_model);
	virtual ~BaseController();

	//return false meaning not having been processed
	virtual bool HandleSdlEvent(SDL_Event & e) = 0;
	virtual void CaptureFocus(bool captured);
	virtual BaseController* GetFocusedController() const;

};

