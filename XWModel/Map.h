#pragma once
#include"ModelObject.h"
#include<memory>
#include "Cell.h"
#include "Mine.h"
#include "Shop.h"
#include "Castle.h"

class Map :public ModelObject
{
private:
	std::vector<std::unique_ptr<Cell>> _list_cell;
	std::vector< std::unique_ptr<Mine>> _list_mine;
	std::vector<std::unique_ptr<Castle>> _list_castle;
	std::unique_ptr<Shop> _up_shop;
	int _num_of_row;
	int _num_of_col;

	int _num_of_stone_mine;
	int _num_of_iron_mine;
	int _num_of_diamond_mine;
	int _num_of_big_log_mine;
	int _num_of_small_log_mine;
	int _num_of_big_hunt_mine;
	int _num_of_small_hunt_mine;
	int _num_of_gold_mine;

	void _init_map();

	int _rand_in_range(int userBeg, int userEnd)
	{
		std::srand((unsigned int)time(NULL));
		return (std::rand() % ((userEnd - userBeg) + 1)) + userBeg;
	}
	void _generate_mines(std::vector<int> &cell_list, int number_of_mines, MineType minetype);
public:
	Map();
	~Map();
	const char* GetNameForPTree() const { return "Map"; }

	ptree &  GetPropertyTree() override;
	void OnIterateCallback(std::string key, std::string value, int level);
	void UpdateByPropertyTree(const ptree& propert_tree) override;
	const Cell* GetCell(int index) const;
	const Mine* GetMine(int index) const;
	const Shop* GetShop() const;
	const Castle* GetCastle(int index) const;
	int GetTotalCellNumber() const;
	int GetTotalMineNumber() const;
	int GetTotalCastleNumber() const;

	int GetNumberOfCol()const;
	int GetNumberOfRow() const;
	void AddCastle(int row, int col);

	void Reset();
};

