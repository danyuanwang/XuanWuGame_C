#pragma once
#include "BaseController.h"
#include "Board.h"
#include "BoardView.h"

class BoardController :
	public BaseController
{
private:
	BoardView* GetBoardView() const;
	Board* GetBoardModel() const;

public:
	BoardController(BoardView* p_view, Board* p_model);
	virtual ~BoardController();
};

