#include "ShopController.h"



ShopView * ShopController::GetShopView() const
{
	return static_cast<ShopView*>(_p_view);
}

bool ShopController::OnKeyUp(SDL_Event & e)
{
	return false;
}

bool ShopController::OnMouseMove(SDL_Event & e)
{
	return false;
}

bool ShopController::OnMouseButtonUp(SDL_Event & e)
{
	return _p_view->intercepts(e.button.x, e.button.y);
}

ShopController::ShopController(ShopView* p_view, Shop* p_model)
	:BaseController(p_view, p_model)
{
	Invalidate();
}


ShopController::~ShopController()
{
}

bool ShopController::HandleSdlEvent(SDL_Event & e)
{
	return BaseController::HandleSdlEvent(e);
}

void ShopController::Invalidate()
{
	BaseController::Invalidate();
}
