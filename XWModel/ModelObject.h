#pragma once
#include"commonstructure.h"
#include "GamePlayRequest.h"

class ModelObject
{
public:
	ModelObject();
	virtual ~ModelObject();

	virtual void TakeRequest(GamePlayRequest & request) = 0;
	virtual void GetPropertyTree(ptree& propert_tree) const = 0;
	virtual const char* GetClassName() const = 0;
};

