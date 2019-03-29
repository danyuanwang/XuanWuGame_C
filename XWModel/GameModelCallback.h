#pragma once
class GameModelCallback
{
public:
	GameModelCallback();
	~GameModelCallback();

	virtual int OnGameModelObserverCallback() = 0;
};