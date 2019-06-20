#pragma once
#include "ModelObject.h"
class Player :
	public ModelObject
{
public:
	Player(const char*player_identity);
	Player(const ptree& property_tree);
	virtual ~Player();
	ptree&  GetPropertyTree() override;
	const char* GetNameForPTree() const { return "Player"; }
	void UpdateByPropertyTree(const ptree& propert_tree) override;

private:
	std::string _player_identity;
};

