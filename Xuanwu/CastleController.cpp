#include "CastleController.h"



CastleView * CastleController::GetCastleView() const
{
	return static_cast<CastleView*>(_p_view);
	;
}

bool CastleController::OnKeyUp(SDL_Event & e)
{
	return false;
}

bool CastleController::OnMouseMove(SDL_Event & e)
{
	return false;
}

bool CastleController::OnMouseButtonUp(SDL_Event & e)
{
	return _p_view->intercepts(e.button.x, e.button.y);
}

CastleController::CastleController(CastleView* p_view, Castle* p_model)
	:BaseController(p_view, p_model)
{
	Invalidate();
}


CastleController::~CastleController()
{
}

bool CastleController::HandleSdlEvent(SDL_Event & e)
{
	return BaseController::HandleSdlEvent(e);
}

void CastleController::Invalidate()
{
	BaseController::Invalidate();
}
