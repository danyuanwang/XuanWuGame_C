#pragma once
#include "ModelObject.h"
#include "GameEngine.h"
class BaseView
{
public:
	BaseView();
	virtual ~BaseView();
	virtual void Draw(const ModelObject *p_game_model, const GameEngine *p_game_engine) = 0;


};

