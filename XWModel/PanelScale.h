#pragma once
#include "ModelObject.h"
#include "Mine.h"
#include "Cell.h"

class PanelScale :
	public ModelObject
{
private:
	MineType _mine_type;
	CellType _cell_type;

public:
	PanelScale();
	virtual ~PanelScale();

	ptree&  GetPropertyTree();
	const char* GetNameForPTree() const override { return "PanelScale"; }
	void UpdateByPropertyTree(const ptree& propert_tree) override;

	void TakeDataObject(const ModelObject* p_model);

	MineType GetMineType() const;
	CellType GetCellType() const;
};

