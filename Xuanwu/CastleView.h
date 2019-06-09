#pragma once
#include "BaseView.h"
class CastleView :
	public BaseView
{
public:
	CastleView(int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~CastleView();
};

