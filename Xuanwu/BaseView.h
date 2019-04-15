#pragma once
#include "ModelObject.h"
class BaseView
{
public:
	BaseView();
	virtual ~BaseView();
	virtual void Draw(const ModelObject *p_game_model) = 0;


};

