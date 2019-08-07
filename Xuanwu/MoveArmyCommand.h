#pragma once
#include "BaseCommand.h"
class MoveArmyCommand :
	public BaseCommand
{
public:
	MoveArmyCommand(int row, int col, unsigned long id);
	virtual ~MoveArmyCommand();
	void Execute() override;
private:
	int _end_col;
	int _end_row;
	unsigned long _army_id;
};

