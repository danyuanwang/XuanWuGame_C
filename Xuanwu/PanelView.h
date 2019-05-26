#pragma once
#include "BaseView.h"
#include "GameModel.h"
#include "PanelActionView.h"
#include "PanelScaleView.h"

class PanelView :
	public BaseView
{
private:
	PanelActionView _action_view;
	PanelScaleView _scale_view;
public:
	PanelView(int x, int y, int width, int height, int margin_x, int margin_y);
	virtual ~PanelView();
	void Draw( const GameEngine *p_game_engine) override;
	void Invalidate(const ModelObject *p_gamemodel) override;

	PanelActionView* GetActionView() const;
	PanelScaleView* GetScaleView() const;
};

