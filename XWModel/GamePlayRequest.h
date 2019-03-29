#pragma once
#include "string"
enum  GameScenarioTypeEnum
{
	GameScenario_Map = 0,
	GameScenario_Shop,
	GameScenario_Chamber,
	GameScenario_GameBoard,
	GameScenario_DrillGround,
	GameScenario_Total_Number,
};

enum  GameOjbectTypeEnum
{
	GameOjbect_Player = 0,
	GameOjbect_Army,
	GameOjbect_GameBoard,
	GameOjbect_Total_Number,
};

enum  GameOjbectActionTypeEnum
{
	GameOjbectAction_Move = 0,
	GameOjbectAction_Fight,
	GameOjbectAction_Mine,
	GameOjbectAction_Buy,
	GameOjbectAction_Sell,

	GameOjbectAction_Restart,
	GameOjbectAction_End,

	GameOjbectAction_Total_Number,
};

class GamePlayRequest
{
public:
	GamePlayRequest(
		GameScenarioTypeEnum scenario, 
		GameOjbectTypeEnum from, 
		GameOjbectTypeEnum to, 
		GameOjbectActionTypeEnum action
	);

	GamePlayRequest(const char* json);

	~GamePlayRequest();

	GameScenarioTypeEnum GetScenarioType();
	GameOjbectTypeEnum GetFromType();
	GameOjbectTypeEnum GetToType();
	GameOjbectActionTypeEnum GetActionType();
	
	std::string ToJson();

private:
	GameScenarioTypeEnum _scenario;
	GameOjbectTypeEnum _from;
	GameOjbectTypeEnum _to;
	GameOjbectActionTypeEnum _action;

	const char* _get_class_name() { return "GamePlayRequest"; }
};

