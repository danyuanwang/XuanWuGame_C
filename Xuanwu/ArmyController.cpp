#include "ArmyController.h"



ArmyController::ArmyController(ArmyView* p_view, Army* p_model)
	:BaseController(p_view, p_model)
{
	Invalidate();
}


ArmyController::~ArmyController()
{
}

ArmyView * ArmyController::GetArmyView() const
{
	return static_cast<ArmyView*>(_p_view);
	;
}

bool ArmyController::OnKeyUp(SDL_Event & e)
{
	return false;
}

bool ArmyController::OnMouseMove(SDL_Event & e)
{
	return false;
}

bool ArmyController::OnMouseButtonUp(SDL_Event & e)
{
	return _p_view->intercepts(e.button.x, e.button.y);
}




bool ArmyController::HandleSdlEvent(SDL_Event & e)
{
	return BaseController::HandleSdlEvent(e);;
}

void ArmyController::Invalidate()
{
	BaseController::Invalidate();
}
