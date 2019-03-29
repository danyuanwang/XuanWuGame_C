#pragma once
#include"ModelObject.h"

class Cell :public ModelObject
{
public:
	Cell();
	~Cell();
	const char* GetClassName() const { return "Cell"; }

	void TakeRequest(GamePlayRequest & request);
	void GetPropertyTree(ptree& propert_tree) const;
};
