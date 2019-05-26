#include "Panel.h"



Panel::Panel()
{
	_up_scale = std::unique_ptr<PanelScale>{ new PanelScale() };
	_up_action = std::unique_ptr<PanelAction>{ new PanelAction() };

}


Panel::~Panel()
{
}

ptree & Panel::GetPropertyTree()
{
	_property_tree.clear();
	ptree pt_scale;
	{
		pt_scale.push_back(
			ptree::value_type(
				_up_scale->GetNameForPTree(),
				_up_scale->GetPropertyTree()
			)
		);
	}

	_property_tree.add_child(
		QUOTES(_up_scale),
		pt_scale
	);

	ptree pt_action;
	{
		pt_action.push_back(
			ptree::value_type(
				_up_action->GetNameForPTree(),
				_up_action->GetPropertyTree()
			)
		);
	}

	_property_tree.add_child(
		QUOTES(_up_action),
		pt_action
	);	return _property_tree;
}

void Panel::UpdateByPropertyTree(const ptree & propert_tree)
{
	_property_tree = propert_tree.get_child(GetNameForPTree());
	_up_scale->UpdateByPropertyTree(_property_tree.get_child(QUOTES(_up_scale)));
	_up_action->UpdateByPropertyTree(_property_tree.get_child(QUOTES(_up_action)));
}

const char * Panel::GetNameForPTree() const
{
	return "Panel";
}

const PanelAction * Panel::GetAction()
{
	return _up_action.get();
}

const PanelScale * Panel::GetScale()
{
	return _up_scale.get();
}
