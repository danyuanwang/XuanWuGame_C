#pragma once
#include <Vector>
#include <memory>
#include "ModelObject.h"
#include "GamePlayRequest.h"
#include "GameModel.h"
#include "Board.h"
/*
__stdcall is only valid in windows platform, more information is here.
https://docs.microsoft.com/en-us/cpp/cpp/calling-conventions?view=vs-2017
*/
#ifndef WIN32 
#define __stdcall
#endif

class GameModel;

typedef int(__stdcall *GameModelObserverCallbackFunc)(const GameModel& model);

class GameModel:public ModelObject
{
private:
	std::vector<GameModelObserverCallbackFunc> _observerVector;

	void _notifyUpdate();

	Board _gameBoard;

public:
	GameModel();
	~GameModel();

	const char* GetClassName() const { return "GameModel"; }
	void TakeRequest(GamePlayRequest& request);
	void GetPropertyTree(ptree& propert_tree) const;

	void RegisterObserver(GameModelObserverCallbackFunc observerFunc);
};

