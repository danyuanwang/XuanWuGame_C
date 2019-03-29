#pragma once
#include "CommonStructure.h"
#include "string"

enum  GameScenarioTypeEnum
{
	GameScenario_Map = 0,
	GameScenario_Shop,
	GameScenario_Chamber,
	GameScenario_GameBoard,
	GameScenario_DrillGround,

	GameScenario_DataModel,

	GameScenario_Total_Number,
};

enum  GameOjbectTypeEnum
{
	GameOjbect_Player = 0,
	GameOjbect_Army,
	GameOjbect_GameBoard,

	GameOjbect_GameView,

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

	GameOjbectAction_UpdateView,

	GameOjbectAction_Total_Number,
};

class GamePlayRequest : public CommonStructure::PropertyTreeWalker
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

	void Attach(const char* key, ptree pt);

	GameScenarioTypeEnum GetScenarioType();
	GameOjbectTypeEnum GetFromType();
	GameOjbectTypeEnum GetToType();
	GameOjbectActionTypeEnum GetActionType();

	std::string ToJson();

	void OnIterateCallback(std::string key, std::string value, int level);

private:
	GameScenarioTypeEnum _scenario;
	GameOjbectTypeEnum _from;
	GameOjbectTypeEnum _to;
	GameOjbectActionTypeEnum _action;

	ptree  _property_tree;


	const char* _get_class_name() { return "GamePlayRequest"; }
	void _init_property_tree();
};

