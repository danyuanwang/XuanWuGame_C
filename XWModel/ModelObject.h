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
	unsigned long GetModelObjectID() { return _id; };
protected:

	static unsigned long s_id_counter;

	unsigned long _id;
};

