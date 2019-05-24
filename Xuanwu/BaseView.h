#pragma once
#include "ModelObject.h"
#include "GameEngine.h"
class BaseView
{
protected:
	int _x;
	int _y;
	int _width;
	int _height;
	int _margin_x;
	int _margin_y;

public:
	BaseView(int x, int y, int width, int height, int margin_x, int margin_y );
	virtual ~BaseView();
	virtual void Draw(const ModelObject *p_game_model, const GameEngine *p_game_engine) = 0;
	virtual BaseView* intercepts(int mouse_x, int mouse_y);
};