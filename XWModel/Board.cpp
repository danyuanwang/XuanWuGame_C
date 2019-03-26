#include "Board.h"
#include "DataModel.h"

Board::Board() :
	_game_title(_dataModel.GetGameScreenTitle()),
	_screen_width(_dataModel.GetGameScreenWidth()),
	_screen_height(_dataModel.GetGameScreenHeight()),
	_screen_margin_x(_dataModel.GetGameScreenMarginX()),
	_screen_margin_y(_dataModel.GetGameScreenMarginY())
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
	PROPERTY_TREE_PUT_VALUE_STRING(propert_tree, GetClassName());
	PROPERTY_TREE_PUT_STRING(propert_tree, _game_title);
	PROPERTY_TREE_PUT(propert_tree, _screen_width);
	PROPERTY_TREE_PUT(propert_tree, _screen_height);
	PROPERTY_TREE_PUT(propert_tree, _screen_margin_x);
	PROPERTY_TREE_PUT(propert_tree, _screen_margin_y);
}
