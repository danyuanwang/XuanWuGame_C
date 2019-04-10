#include "Board.h"
#include "DataModel.h"

Board::Board()
{
	_up_map = std::unique_ptr<Map>{ new Map() };
}


Board::~Board()
{

}


ptree & Board::GetPropertyTree(ptree & property_tree)
{
	_property_tree.clear();

	{
		ptree pt_element;
		_property_tree.add_child(
			QUOTES(_up_map),
			_up_map->GetPropertyTree(pt_element)
		);
	}

	property_tree.push_back(
		ptree::value_type(
			GetNameForPTree(),
			_property_tree
		)
	);
	return property_tree;
}

void Board::OnIterateCallback(std::string key, std::string value, int level)
{
	throw std::logic_error("not implemented");
}

void Board::UpdateByPropertyTree(ptree& propert_tree)
{
	throw std::logic_error("not implemented");
}
