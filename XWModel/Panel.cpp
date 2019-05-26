#include "Panel.h"



Panel::Panel()
{
}


Panel::~Panel()
{
}

ptree & Panel::GetPropertyTree()
{
	_property_tree.clear();
	return _property_tree;
}

void Panel::UpdateByPropertyTree(const ptree & propert_tree)
{
	_property_tree = propert_tree.get_child(GetNameForPTree());
}

const char * Panel::GetNameForPTree() const
{
	return "Panel";
}
