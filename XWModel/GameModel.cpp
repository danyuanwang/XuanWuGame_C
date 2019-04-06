#include "GameModel.h"
#include<iterator>


GameModel::GameModel()
{
	up_game_board = std::unique_ptr<Board>{ new Board() };
}


GameModel::~GameModel()
{
	
}


void GameModel::TakeRequest(GamePlayRequest& request)
{
	up_game_board->TakeRequest(request);

	/*for test purpose, need to remove*/
	_notifyUpdate();
}

void GameModel::BindConnection(ConnectionMgr * p_onnectionMgr)
{
	_p_connectionMgr = p_onnectionMgr;
}

int GameModel::OnReceivedMsgCallback(std::unique_ptr<NetPackMsg> up_message)
{
	return OnReceivedMsgCallback(up_message.get());
}

int GameModel::OnReceivedMsgCallback(NetPackMsg * p_message)
{
	GamePlayRequest gpr = GamePlayRequest{ (char*)p_message->Body() };
	TakeRequest(gpr);

	return 0;
}

int GameModel::OnSentMsgCallback(boost::system::error_code ec, std::size_t)
{
	return 0;
}

ptree& GameModel::GetPropertyTree(ptree & propert_tree)
{
	ptree pt_ele;

	propert_tree.push_back(
		ptree::value_type(
			up_game_board->GetNameForPTree(), 
			up_game_board->GetPropertyTree(pt_ele)
		)
	);
	return propert_tree;
}

void GameModel::_notifyUpdate()
{
	GamePlayRequest gr;
	gr.SetScenario(GameScenario_DataModel);
	gr.SetFromObject(GameOjbect_GameBoard);
	gr.SetToObject(GameOjbect_GameView);
	gr.SetActionType(GameOjbectAction_UpdateView);

	ptree property_tree;
	GetPropertyTree(property_tree);
	gr.Attach(GetNameForPTree(), property_tree);

	NetPackMsg netMsg{ gr.ToJson().c_str() };
	_p_connectionMgr->SendMsg(&netMsg);
}

