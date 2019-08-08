#pragma once
#include "BaseView.h"
class ShopView :
	public BaseView
{
public:
	ShopView(int x, int y, int container_x, int container_y, int width, int height,int margin_x, int margin_y);
	virtual ~ShopView();
	void Draw(const GameEngine *p_game_engine) override;
	void Invalidate(const ModelObject *p_game_model) override;
};

