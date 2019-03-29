#include "GameModel.h"
#include<iterator>


GameModel::GameModel()
{

}


GameModel::~GameModel()
{
	
}


void GameModel::TakeRequest(GamePlayRequest& request)
{
	_gameBoard.TakeRequest(request);

	/*for test purpose, need to remove*/
	_notifyUpdate();
}

void GameModel::RegisterObserver(GameModelCallback* p_observerFunc)
{
	_observerVector.push_back(p_observerFunc);
}

void GameModel::GetPropertyTree(ptree & propert_tree) const
{

}

void GameModel::_notifyUpdate()
{
	std::vector< GameModelCallback* >::const_iterator citr;
	for (citr = _observerVector.begin(); citr < _observerVector.end(); citr++) 
	{
		try
		{
			(*citr)->OnGameModelObserverCallback();
		}
		catch (const std::exception&)
		{
			//ignore the error;
		}
	}
}

