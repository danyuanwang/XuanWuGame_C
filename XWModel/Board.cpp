#include "Board.h"
#include "DataModel.h"

Board::Board()
{
	_up_map = std::move(std::unique_ptr<Map>{ new Map() });
	_up_panel = std::move(std::unique_ptr<Panel>{new Panel()});
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

	ptree pt_panel;
	{
		pt_panel.push_back(
			ptree::value_type(
				_up_panel->GetNameForPTree(),
				_up_panel->GetPropertyTree()
			)
		);
	}

	_property_tree.add_child(
		QUOTES(_up_panel),
		pt_panel
	);

	return _property_tree;
}

void Board::UpdateByPropertyTree(const ptree& propert_tree)
{
	_property_tree = propert_tree.get_child(GetNameForPTree());
	_up_map->UpdateByPropertyTree(_property_tree.get_child(QUOTES(_up_map)));
	_up_panel->UpdateByPropertyTree(_property_tree.get_child(QUOTES(_up_panel)));
}

const Map* Board::GetMap() const {
	return _up_map.get();
}

const Panel * Board::GetPanel() const
{
	return const_cast<const Panel *>(_up_panel.get());
}
