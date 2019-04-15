#pragma once
#include "BaseView.h"
#include "MapView.h"
#include "PanelView.h"
#include "GameModel.h"
class BoardView :
	public BaseView
{
public:
	BoardView();
	virtual ~BoardView();
	void Draw(const ModelObject *p_game_model);
private:
	MapView _map_view;
	PanelView _panel_view;

};

