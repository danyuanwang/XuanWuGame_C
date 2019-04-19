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
	void Draw(const ModelObject *p_game_model, const GameEngine *p_game_engine);
private:
	MapView _map_view;
	PanelView _panel_view;

};

