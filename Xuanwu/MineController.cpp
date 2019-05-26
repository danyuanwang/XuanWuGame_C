#include "MineController.h"



MineController::MineController(MineView* p_view, Mine* p_model):
	BaseController(p_view, p_model)
{
}


MineController::~MineController()
{
}

bool MineController::HandleSdlEvent(SDL_Event & e)
{
	return BaseController::HandleSdlEvent(e);
}

void MineController::Invalidate()
{
	BaseController::Invalidate();

}

MineView * MineController::GetMineView() const
{
	return static_cast<MineView*>(_p_view);
}

bool MineController::OnKeyUp(SDL_Event & e)
{
	return false;
}

bool MineController::OnMouseMove(SDL_Event & e)
{
	return false;
}

bool MineController::OnMouseButtonUp(SDL_Event & e)
{
	return _p_view->intercepts(e.button.x, e.button.y);
}