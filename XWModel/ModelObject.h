#pragma once
#include"commonstructure.h"
#include "GamePlayRequest.h"

class ModelObject :
	public CommonStructure::PropertyTreeWalker
{
public:
	ModelObject();
	virtual ~ModelObject();

	virtual ptree& GetPropertyTree(ptree& propert_tree) = 0;
	virtual void UpdateByPropertyTree(ptree& propert_tree) = 0;
	virtual std::string ToJson();
	virtual void UpdateByJson(std::string& str_json);
	virtual const char* GetNameForPTree() const = 0;
	unsigned long GetModelObjectID() { return _id; };

protected:

	static unsigned long s_id_counter;
	unsigned long _id;

	ptree _property_tree;
};

