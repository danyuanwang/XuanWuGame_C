#include"commonstructure.h"
#include "GamePlayRequest.h"

GamePlayRequest::GamePlayRequest(
	GameScenarioTypeEnum scenario,
	GameOjbectTypeEnum from,
	GameOjbectTypeEnum to,
	GameOjbectActionTypeEnum action
) :
	_scenario(scenario),
	_from(from),
	_to(to),
	_action(action)
{
	_init_property_tree();
}

GamePlayRequest::GamePlayRequest(const char * json)
{
	std::stringstream ss;
	ss << json;
	boost::property_tree::read_json(ss, _property_tree);
	IteratePropertyTree(_property_tree, this);

}

void GamePlayRequest::Attach(const char* key, ptree pt)
{
	_property_tree.push_back(ptree::value_type(key, pt));
}

void GamePlayRequest::OnIterateCallback(std::string key, std::string value, int level)
{
	if (!key.empty())
	{
		MATCH_FROM_PROPERTY_KV(key, value, _scenario, GameScenarioTypeEnum);
		MATCH_FROM_PROPERTY_KV(key, value, _from, GameOjbectTypeEnum);
		MATCH_FROM_PROPERTY_KV(key, value, _to, GameOjbectTypeEnum);
		MATCH_FROM_PROPERTY_KV(key, value, _action, GameOjbectActionTypeEnum);
	}
}

GamePlayRequest::~GamePlayRequest()
{
	_property_tree.clear();
}

GameScenarioTypeEnum GamePlayRequest::GetScenarioType()
{
	return _scenario;
}

GameOjbectTypeEnum GamePlayRequest::GetFromType()
{
	return _from;
}

GameOjbectTypeEnum GamePlayRequest::GetToType()
{
	return _to;
}

GameOjbectActionTypeEnum GamePlayRequest::GetActionType()
{
	return _action;
}

void GamePlayRequest::_init_property_tree()
{
	_property_tree.clear();

	ptree  pt_elements;

	PROPERTY_TREE_PUT(pt_elements, _scenario);
	PROPERTY_TREE_PUT(pt_elements, _from);
	PROPERTY_TREE_PUT(pt_elements, _to);
	PROPERTY_TREE_PUT(pt_elements, _action);

	_property_tree.push_back(ptree::value_type(_get_class_name(), pt_elements));
}

std::string GamePlayRequest::ToJson()
{
	std::stringstream json;

	boost::property_tree::write_json(json, _property_tree);

	return json.str();
}
