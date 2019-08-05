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

enum  GameObjectTypeEnum
{
	GameObject_Player = 0,
	GameObject_Army,
	GameObject_GameBoard,
	GameObject_GameModel,

	GameObject_GameView,

	GameObject_Total_Number,
};

enum  GameObjectActionTypeEnum
{
	GameObjectAction_Move = 0,
	GameObjectAction_Fight,
	GameObjectAction_Mine,
	GameObjectAction_Buy,
	GameObjectAction_Sell,
	GameObjectAction_BuildCastle,
	GameObjectAction_Restart,
	GameObjectAction_End,

	GameObjectAction_UpdateView,

	GameObjectAction_UpdateDataModel,

	GameObjectAction_Total_Number,
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
	GameObjectTypeEnum GetFromType();
	GameObjectTypeEnum GetToType();
	GameObjectActionTypeEnum GetActionType();

	void SetScenario(GameScenarioTypeEnum scenario);
	void SetFromObject(GameObjectTypeEnum from);
	void SetToObject(GameObjectTypeEnum to);
	void SetActionType(GameObjectActionTypeEnum action);

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

