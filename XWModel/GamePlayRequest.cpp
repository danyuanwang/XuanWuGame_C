#include"CommonStructure.h"
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

void GamePlayRequest::AddChild(const char* key, ptree pt)
{
	_property_tree.push_back(ptree::value_type(key, pt));
}

ptree& GamePlayRequest::GetChild(const char* key)
{
	return _property_tree.get_child(key);
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

GameObjectTypeEnum GamePlayRequest::GetFromType()
{
	return GetKeyValue<GameObjectTypeEnum>(QUOTES(from));
}

GameObjectTypeEnum GamePlayRequest::GetToType()
{
	return GetKeyValue<GameObjectTypeEnum>(QUOTES(to));
}

GameObjectActionTypeEnum GamePlayRequest::GetActionType()
{
	return GetKeyValue<GameObjectActionTypeEnum>(QUOTES(action));
}

void GamePlayRequest::SetScenario(GameScenarioTypeEnum scenario)
{
	PROPERTY_TREE_PUT(_property_tree, scenario);
}

void GamePlayRequest::SetFromObject(GameObjectTypeEnum from)
{
	PROPERTY_TREE_PUT(_property_tree, from);
}

void GamePlayRequest::SetToObject(GameObjectTypeEnum to)
{
	PROPERTY_TREE_PUT(_property_tree, to);
}

void GamePlayRequest::SetActionType(GameObjectActionTypeEnum action)
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