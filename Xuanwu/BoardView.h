#pragma once
#include "BaseView.h"
#include "MapView.h"
#include "PanelView.h"
#include "GameModel.h"

class BoardView :
	public BaseView
{

public:
	BoardView(int x, int y, int container_x, int container_y, int width, int height, int margin_x, int margin_y);
	virtual ~BoardView();
	void Draw(const GameEngine *p_game_engine) override;

	const MapView* GetMapView() const;
	const PanelView* GetPanelView() const;

	void Invalidate(const ModelObject *p_game_model) override;

private:
	MapView _map_view;
	PanelView _panel_view;
	BaseView* _selected_view;

protected:
};

