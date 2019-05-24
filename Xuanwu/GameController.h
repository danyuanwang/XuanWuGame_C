#pragma once
#include "BaseController.h"

class GameController :
	public BaseController
{
public:
	GameController(BaseView* p_view, ModelObject* p_model);
	virtual ~GameController();
};

