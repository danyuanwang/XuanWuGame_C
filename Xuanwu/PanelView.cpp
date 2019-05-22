#include "PanelView.h"
#include "Settings.h"



PanelView::PanelView()
{
}


PanelView::~PanelView()
{
}

void PanelView::Draw(const ModelObject *p_gamemodel, const GameEngine *p_game_engine)
{
	p_game_engine->DrawRect(GameSettings::MarginOfBoardX, GameSettings::MarginOfBoardY, GameSettings::PanelWidth, GameSettings::PanelHeight, GameSettings::PanelColor);

}
