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
}

void GameModel::RegisterObserver(GameModelObserverCallbackFunc observerFunc)
{
	_observerVector.push_back(observerFunc);
}

void GameModel::GetPropertyTree(ptree & propert_tree) const
{

}

void GameModel::_notifyUpdate()
{
	std::vector< GameModelObserverCallbackFunc>::const_iterator citr;
	for (citr = _observerVector.begin(); citr < _observerVector.end(); citr++) {
		try
		{
			(*citr)(*this);
		}
		catch (const std::exception&)
		{
			//ignore the error;
		}
	}
}

