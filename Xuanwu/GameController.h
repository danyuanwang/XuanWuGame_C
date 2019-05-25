#pragma once
#include "BaseController.h"
#include "BoardController.h"
#include "GameModel.h"
#include "GameView.h"

class GameController :
	public BaseController
{
private:
	GameView* GetGameView() const;
	GameModel* GetGameModel() const;

	BoardController _boardController;

public:
	GameController(GameView* p_view, GameModel* p_model);
	virtual ~GameController();

	const BoardController* GetBoardController() const;
	bool HandleSdlEvent(SDL_Event & e) override;
};

