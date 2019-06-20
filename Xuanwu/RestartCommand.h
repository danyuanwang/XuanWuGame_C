#pragma once
#include "BaseCommand.h"
#include "Settings.h"
class RestartCommand :
	public BaseCommand
{
public:
	RestartCommand();
	virtual ~RestartCommand();
	void Execute();
};

