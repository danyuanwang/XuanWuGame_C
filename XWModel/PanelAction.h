#pragma once
#include "ModelObject.h"
class PanelAction :
	public ModelObject
{
public:
	PanelAction();
	virtual ~PanelAction();

	ptree&  GetPropertyTree();
	const char* GetNameForPTree() const override { return "PanelAction"; }
	void UpdateByPropertyTree(const ptree& propert_tree) override;
};

