#pragma once
#include "BaseController.h"
#include "Board.h"
#include "BoardView.h"

class BoardController :
	public BaseController
{
private:
	BoardView* GetBoardView() ;
	Board* GetBoardModel() ;

protected:
	virtual bool OnKeyUp(SDL_Event & e) override;
	virtual bool OnMouseMove(SDL_Event & e) override;
	virtual bool OnMouseButtonUp(SDL_Event & e) override;

public:
	BoardController(BoardView* p_view, Board* p_model);
	virtual ~BoardController();

};

