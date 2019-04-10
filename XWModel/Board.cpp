#include "Board.h"
#include "DataModel.h"

Board::Board()
{
	_up_map = std::unique_ptr<Map>{ new Map() };
}


Board::~Board()
{

}


ptree & Board::GetPropertyTree()
{
	_property_tree.clear();

	ptree pt_map;
	{
		pt_map.push_back(
			ptree::value_type(
				_up_map->GetNameForPTree(),
			_up_map->GetPropertyTree()
			)
		);
	}

	_property_tree.add_child(
		QUOTES(_up_map),
		pt_map
	);

	return _property_tree;
}

void Board::OnIterateCallback(std::string key, std::string value, int level)
{
	throw std::logic_error("not implemented");
}

void Board::UpdateByPropertyTree(const ptree& propert_tree)
{
	_property_tree = propert_tree.get_child(GetNameForPTree());
	_up_map->UpdateByPropertyTree(_property_tree.get_child(QUOTES(_up_map)));
}
