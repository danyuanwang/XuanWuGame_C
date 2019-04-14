#pragma once
#include "GameModel.h"
class BaseView
{
public:
	BaseView();
	virtual ~BaseView();
	virtual void Draw(const GameModel &game_model) = 0;


};

