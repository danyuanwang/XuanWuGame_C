#pragma once
#include "ModelObject.h"
class Panel :
	public ModelObject
{
public:
	Panel();
	virtual ~Panel();

	ptree& GetPropertyTree() override;
	void UpdateByPropertyTree(const ptree& propert_tree) override;
	const char* GetNameForPTree() const override;

};

