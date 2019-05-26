#pragma once
#include "BaseController.h"
#include "Board.h"
#include "BoardView.h"
#include "MapController.h"
#include "PanelController.h"

class BoardController :
	public BaseController
{
private:
	BoardView* GetBoardView();
	Board* GetBoardModel();

	MapController _map_controller;
	PanelController _panel_controller;

	BaseController* _p_captured_controller;

public:
	BoardController(BoardView* p_view, Board* p_model);
	virtual ~BoardController();
	virtual bool HandleSdlEvent(SDL_Event & e) override;

	void Invalidate() override;

};

