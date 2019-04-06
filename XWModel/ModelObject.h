#pragma once
#include"commonstructure.h"
#include "GamePlayRequest.h"

class ModelObject
{
public:
	ModelObject();
	virtual ~ModelObject();

	virtual void TakeRequest(GamePlayRequest & request) = 0;
	virtual ptree& GetPropertyTree(ptree& propert_tree) = 0;
	virtual const char* GetNameForPTree() const = 0;
};

