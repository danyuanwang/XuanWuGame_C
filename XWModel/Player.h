#pragma once
#include "ModelObject.h"
class Player :
	public ModelObject
{
public:
	Player();
	virtual ~Player();
	const char* GetNameForPTree() const { return "Player"; }

	void TakeRequest(GamePlayRequest & request);
	void GetPropertyTree(ptree& propert_tree) const;
};

