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