#pragma once
#include "BaseController.h"
#include "CastleView.h"
#include "Castle.h"
class CastleController :
	public BaseController
{
public:
	CastleController(CastleView* p_view, Castle* p_model);
	virtual ~CastleController();
};

