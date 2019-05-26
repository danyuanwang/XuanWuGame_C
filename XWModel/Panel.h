#pragma once
#include "ModelObject.h"
#include "PanelScale.h"
#include "PanelAction.h"

class Panel :
	public ModelObject
{
public:
	Panel();
	virtual ~Panel();

	ptree& GetPropertyTree() override;
	void UpdateByPropertyTree(const ptree& propert_tree) override;
	const char* GetNameForPTree() const override;

	const PanelAction* GetAction();
	const PanelScale* GetScale();

private:
	std::unique_ptr<PanelScale> _up_scale;
	std::unique_ptr<PanelAction> _up_action;

};

