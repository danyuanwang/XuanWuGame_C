#pragma once
#include "CommonStructure.h"
#include "GamePlayRequest.h"

class ModelObject :
	public CommonStructure::PropertyTreeWalker
{
public:
	ModelObject();
	virtual ~ModelObject();

	virtual ptree& GetPropertyTree() = 0;
	virtual void UpdateByPropertyTree(const ptree& propert_tree) = 0;
	virtual std::string ToJson();
	virtual const char* GetNameForPTree() const = 0;
	unsigned long GetModelObjectID() { return _id; };
	virtual void OnIterateCallback(std::string key, std::string value, int level) override;

protected:

	static unsigned long s_id_counter;
	unsigned long _id;

	ptree _property_tree;
};

