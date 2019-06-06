#pragma once
#include "BaseController.h"
#include "ShopView.h"
#include "Shop.h"
class ShopController :
	public BaseController
{
private:
	ShopView* GetShopView() const;

protected:
	virtual bool OnKeyUp(SDL_Event & e) override;
	virtual bool OnMouseMove(SDL_Event & e) override;
	virtual bool OnMouseButtonUp(SDL_Event & e) override;
public:
	ShopController(ShopView* p_view, Shop* p_model);
	virtual ~ShopController();
	bool HandleSdlEvent(SDL_Event & e) override;

	void Invalidate() override;
};

