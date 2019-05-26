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
	bool _high_lighted;

public:
	BaseView(int x, int y, int width, int height, int margin_x, int margin_y );
	virtual ~BaseView();
	virtual void Draw(const ModelObject *p_game_model, const GameEngine *p_game_engine) = 0;
	virtual bool intercepts(int mouse_x, int mouse_y) const;

	virtual void HighLight(bool high_lighted);
};