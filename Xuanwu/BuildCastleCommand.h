#pragma once
#include "BaseCommand.h"
class BuildCastleCommand :
	public BaseCommand
{
public:
	BuildCastleCommand(int row, int col);
	virtual ~BuildCastleCommand();
	void Execute() override;
private:
	int _col;
	int _row;
};

