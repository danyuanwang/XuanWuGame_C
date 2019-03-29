#include"commonstructure.h"
#include "GamePlayRequest.h"
GamePlayRequest::GamePlayRequest(
	GameScenarioTypeEnum scenario,
	GameOjbectTypeEnum from,
	GameOjbectTypeEnum to,
	GameOjbectActionTypeEnum action
):
	_scenario(scenario), 
	_from(from), 
	_to(to), 
	_action(action)
{

}

GamePlayRequest::GamePlayRequest(const char * json)
{
	ptree  propert_tree;
	boost::property_tree::read_json(std::string(json), propert_tree);
}

GamePlayRequest::~GamePlayRequest()
{

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

std::string GamePlayRequest::ToJson()
{
	ptree  pt_elements;
	std::stringstream json;

	PROPERTY_TREE_PUT(pt_elements, _scenario);
	PROPERTY_TREE_PUT(pt_elements, _from);
	PROPERTY_TREE_PUT(pt_elements, _to);
	PROPERTY_TREE_PUT(pt_elements, _action);


	ptree  pt;
	pt.push_back(ptree::value_type(_get_class_name(), pt_elements));
	pt.push_back(ptree::value_type(_get_class_name(), pt_elements));

	boost::property_tree::write_json(json, pt);

	//auto upsc = std::unique_ptr<char>{new char[json]}
	return json.str();
}
