#pragma once
#include "GamePlayRequest.h"
#include "boost\property_tree\ptree.hpp"
#include <memory>

using boost::property_tree::ptree;

class ModelObject
{
public:
	ModelObject();
	virtual ~ModelObject();

	virtual void TakeRequest(GamePlayRequest & request) = 0;
	virtual void GetPropertyTree(ptree& propert_tree) const = 0;
};

