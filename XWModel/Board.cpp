#include "Board.h"
#include "DataModel.h"

Board::Board()
{
	_up_map = std::unique_ptr<Map>{ new Map() };
}


Board::~Board()
{

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
			break;
		}
		case GameOjbectAction_End:
		{
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

ptree & Board::GetPropertyTree(ptree & propert_tree)
{
	ptree pt_element;

	propert_tree.push_back(
		ptree::value_type(
			_up_map->GetNameForPTree(), 
			_up_map->GetPropertyTree(pt_element)
		)
	);
	return propert_tree;
}
