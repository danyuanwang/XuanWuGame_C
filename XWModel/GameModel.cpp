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

void GameModel::BindConnection(ConnectionMgr * p_onnectionMgr)
{
	_p_connectionMgr = p_onnectionMgr;
}

int GameModel::OnReceivedMsgCallback(std::unique_ptr<NetPackMsg> up_message)
{
	return 0;
}

int GameModel::OnReceivedMsgCallback(NetPackMsg * up_message)
{
	return 0;
}

int GameModel::OnSentMsgCallback(boost::system::error_code ec, std::size_t)
{
	return 0;
}
void GameModel::GetPropertyTree(ptree & propert_tree) const
{

}

void GameModel::_notifyUpdate()
{
	GamePlayRequest gr{ GameScenario_DataModel , GameOjbect_GameBoard , GameOjbect_GameView , GameOjbectAction_UpdateView };

	ptree property_tree;
	GetPropertyTree(property_tree);
	gr.Attach(GetClassName(), property_tree);

	NetPackMsg netMsg{ gr.ToJson().c_str() };
	_p_connectionMgr->SendMsg(&netMsg);
}

