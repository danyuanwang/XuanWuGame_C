#include"commonstructure.h"
#include "GamePlayRequest.h"

GamePlayRequest::GamePlayRequest()
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
	if (!key.empty() && level == 0)
	{
		AddKeyValue(key, value);
	}
}

GamePlayRequest::~GamePlayRequest()
{
	_property_tree.clear();
}

GameScenarioTypeEnum GamePlayRequest::GetScenarioType()
{
	return GetKeyValue<GameScenarioTypeEnum>(QUOTES(scenario));
}

GameOjbectTypeEnum GamePlayRequest::GetFromType()
{
	return GetKeyValue<GameOjbectTypeEnum>(QUOTES(scenario));
}

GameOjbectTypeEnum GamePlayRequest::GetToType()
{
	return GetKeyValue<GameOjbectTypeEnum>(QUOTES(scenario));
}

GameOjbectActionTypeEnum GamePlayRequest::GetActionType()
{
	return GetKeyValue<GameOjbectActionTypeEnum>(QUOTES(scenario));
}

void GamePlayRequest::SetScenario(GameScenarioTypeEnum scenario)
{
	PROPERTY_TREE_PUT(_property_tree, scenario);
}

void GamePlayRequest::SetFromObject(GameOjbectTypeEnum from)
{
	PROPERTY_TREE_PUT(_property_tree, from);
}

void GamePlayRequest::SetToObject(GameOjbectTypeEnum to)
{
	PROPERTY_TREE_PUT(_property_tree, to);
}

void GamePlayRequest::SetActionType(GameOjbectActionTypeEnum action)
{
	PROPERTY_TREE_PUT(_property_tree, action);

}

void GamePlayRequest::_init_property_tree()
{
	_property_tree.clear();
}

std::string GamePlayRequest::ToJson()
{
	std::stringstream json;

	boost::property_tree::write_json(json, _property_tree);

	return json.str();
}

void GamePlayRequest::AddKeyValue(const std::string & key, const std::string & value)
{
	_property_tree.put(key, value);
}

void GamePlayRequest::AddKeyValue(const char * key, const char * value)
{
	_property_tree.put(key, value);
}

std::string GamePlayRequest::GetKeyValue(const std::string & key)
{
	return	_property_tree.get(key, "");
}