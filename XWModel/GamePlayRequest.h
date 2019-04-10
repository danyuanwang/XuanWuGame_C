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
	GameOjbect_GameModel,

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

class GamePlayRequest : 
	public CommonStructure::PropertyTreeWalker
{
public:
	GamePlayRequest();

	GamePlayRequest(const char* json);

	~GamePlayRequest();

	void AddChild(const char* key, ptree pt);
	ptree& GetChild(const char* key);

	GameScenarioTypeEnum GetScenarioType();
	GameOjbectTypeEnum GetFromType();
	GameOjbectTypeEnum GetToType();
	GameOjbectActionTypeEnum GetActionType();

	void SetScenario(GameScenarioTypeEnum scenario);
	void SetFromObject(GameOjbectTypeEnum from);
	void SetToObject(GameOjbectTypeEnum to);
	void SetActionType(GameOjbectActionTypeEnum action);

	std::string ToJson();

	void AddKeyValue(const std::string& key, const std::string& value);
	void AddKeyValue(const char* key, const char* value);

	std::string GetKeyValue(const std::string& key);

	template<typename T>
	T GetKeyValue(const char* key) 
	{
		std::string s_value = GetKeyValue(std::string{ key });
		int i_value = s_value.empty() ? 0 : std::atoi(s_value.c_str());
		return T(i_value);
	}

	void OnIterateCallback(std::string key, std::string value, int level);

private:
	ptree  _property_tree;


	const char* _get_class_name() { return "GamePlayRequest"; }
	void _init_property_tree();
};

