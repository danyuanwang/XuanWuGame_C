#pragma once
#include "BaseView.h"
#include "GameModel.h"
class PanelView :
	public BaseView
{
public:
	PanelView();
	virtual ~PanelView();
	void Draw(const ModelObject *p_gamemodel);
};

