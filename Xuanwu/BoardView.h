#pragma once
#include "BaseView.h"
#include "MapView.h"
#include "PanelView.h"
#include "GameModel.h"

class BoardView :
	public BaseView
{

public:
	BoardView(int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~BoardView();
	void Draw(const ModelObject *p_game_model, const GameEngine *p_game_engine) override;

	const MapView* GetMapView() const;
	const PanelView* GetPanelView() const;

private:
	MapView _map_view;
	PanelView _panel_view;
	BaseView* _selected_view;

protected:
};

