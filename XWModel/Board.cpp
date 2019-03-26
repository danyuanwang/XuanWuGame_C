#include "Board.h"


Board::Board()
{

}


Board::~Board()
{

}

void Board::_restartGame()
{
	//restart a new game
	_map = nullptr;

}

void Board::_endGame()
{
	//end a game
	_map = nullptr;

}

void Board::TakeRequest(GamePlayRequest & request)
{
	switch (request.GetToType())
	{
		case GameOjbect_GameBoard:
		{
			switch (request.GetActionType())
			{
				case GameOjbectAction_Restart:
				{
					_restartGame();
					break;
				}
				case GameOjbectAction_End:
				{
					_endGame();
					break;
				}
				default:
				{
					break;
				}
			}
			break;
		}
		default:
		{
			break;
		}
	}
}

void Board::GetPropertyTree(ptree & propert_tree) const
{

}