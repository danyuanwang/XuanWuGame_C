#pragma once
#include "ModelObject.h"
#include "Mine.h"
#include "Cell.h"
#include "Shop.h"
class PanelScale :
	public ModelObject
{
private:
	MineType _mine_type;
	CellType _cell_type;
	std::string _title;
	std::string _information;

public:
	PanelScale();
	virtual ~PanelScale();

	ptree&  GetPropertyTree();
	const char* GetNameForPTree() const override { return "PanelScale"; }
	void UpdateByPropertyTree(const ptree& propert_tree) override;

	void TakeDataObject(const ModelObject* p_model);

	MineType GetMineType() const;
	CellType GetCellType() const;
	const char* GetTitle() const;
	const char* GetInformation() const;
};