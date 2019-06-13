#pragma once
class BaseCommand
{
public:
	virtual ~BaseCommand();
	virtual void Execute() = 0;
protected:
	BaseCommand();
};

