#include "BaseController.h"



BaseController::BaseController(BaseView * p_view, ModelObject * p_model)
	:
	_view(p_view), _model(p_model)
{

}

BaseController::~BaseController()
{
	_view = nullptr;
	_model = nullptr;
}

void BaseController::HandleSdlEvent(SDL_Event & e)
{
	/*
		More event callback can be added following the same pattern. 
	*/
	switch (e.type)
	{
		case SDL_KEYDOWN:
		{ 
			OnKeyDown(e);
			break;
		}
		case SDL_KEYUP:
		{
			OnKeyUp(e);
			break;
		}
		case SDL_MOUSEMOTION:
		{
			OnMouseButtonDown(e);
			break;
		}
		case SDL_MOUSEBUTTONUP:
		{
			OnMouseButtonUp(e);
			break;
		}
		case SDL_MOUSEWHEEL:
		{
			OnMouseWheel(e);
			break;
		}
		default:
		{		
			break;
		}
	}

}

bool BaseController::OnKeyDown(SDL_Event & e) 
{ 
	return true; 
}

bool BaseController::OnKeyUp(SDL_Event & e)
{
	return true;
}

bool BaseController::OnMouseMove(SDL_Event & e)
{
	return true;
}

bool BaseController::OnMouseButtonDown(SDL_Event & e)
{
	return true;
}

bool BaseController::OnMouseButtonUp(SDL_Event & e)
{
	return true;
}

bool BaseController::OnMouseWheel(SDL_Event & e)
{
	return true;
}
