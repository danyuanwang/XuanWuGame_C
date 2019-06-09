#pragma once
#include "ModelObject.h"
#include "GameEngine.h"
class BaseView
{
protected:
	int _x; //inner
	int _y; //inner
	int _width; //inner
	int _height; // inner
	int _margin_x; 
	int _margin_y;
	bool _high_lighted;

public:
	BaseView(int x, int y, int width, int height, int margin_x, int margin_y );
	virtual ~BaseView();
	virtual void Draw(const GameEngine *p_game_engine) = 0;
	virtual bool intercepts(int mouse_x, int mouse_y) const;

	virtual void HighLight(bool high_lighted);

	virtual void Invalidate(const ModelObject *p_game_model) = 0;

};