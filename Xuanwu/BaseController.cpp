#include "BaseController.h"



BaseController::BaseController(BaseView * p_view, ModelObject * p_model)
	:
	_p_view(p_view), _p_model(p_model)
{

}

BaseController::~BaseController()
{
	_p_view = nullptr;
	_p_model = nullptr;
}

bool BaseController::HandleSdlEvent(SDL_Event & e)
{
	bool result = false;
	switch (e.type)
	{
	case SDL_KEYDOWN:
	{
		result = OnKeyDown(e);
		break;
	}
	case SDL_KEYUP:
	{
		result = OnKeyUp(e);
		break;
	}
	case SDL_MOUSEBUTTONDOWN:
	{
		if (_p_view != nullptr&&_p_view->intercepts(e.button.x, e.button.y))
		{
			result = OnMouseButtonDown(e);
		}
		break;
	}
	case SDL_MOUSEBUTTONUP:
	{
		if (_p_view != nullptr&&_p_view->intercepts(e.button.x, e.button.y))
		{
			result = OnMouseButtonUp(e);
		}
		break;
	}
	case SDL_MOUSEWHEEL:
	{
		if (_p_view != nullptr&&_p_view->intercepts(e.wheel.x, e.wheel.y))
		{
			result = OnMouseWheel(e);
		}
		break;
	}
	case SDL_MOUSEMOTION:
	{
		if (_p_view != nullptr&&_p_view->intercepts(e.motion.x, e.motion.y))
		{
			result = OnMouseMove(e);
		}
		break;
	}
	default:
	{
		break;
	}
	}
	return result;

}
bool BaseController::OnKeyDown(SDL_Event & e)
{
	switch (e.key.keysym.sym)
	{
	case SDLK_UP:
	{
		break;
	}
	case SDLK_DOWN:
	{
		break;
	}
	case SDLK_LEFT:
	{
		break;
	}
	case SDLK_RIGHT:
	{
		break;
	}
	default:
	{
		break;
	}
	}
	return true;
}

bool BaseController::OnKeyUp(SDL_Event & e)
{
	return false;
}

bool BaseController::OnMouseMove(SDL_Event & e)
{
	return false;
}

bool BaseController::OnMouseButtonDown(SDL_Event & e)
{
	return false;
}

bool BaseController::OnMouseButtonUp(SDL_Event & e)
{
	return false;
}

bool BaseController::OnMouseWheel(SDL_Event & e)
{
	return false;
}

