#pragma once
#include "GamePlayRequest.h"
#include "Map.h"
#include "Panel.h"
#include <memory>
#include "DataModel.h"

class Board :public ModelObject
{
public:
	Board();
	~Board();

	ptree&  GetPropertyTree();
	const char* GetNameForPTree() const override { return "Board"; }
	void UpdateByPropertyTree(const ptree& propert_tree) override;

	const Map* GetMap() const;
	const Panel* GetPanel() const;

private:
	std::unique_ptr<Map> _up_map;
	std::unique_ptr<Panel> _up_panel;

};

