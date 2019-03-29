#include <memory>
#include <string>
#include "NetPackMsgHandler.h"
#include "TcpNetPackMsgHandler.h"

NetPackMsgHandler::NetPackMsgHandler()
{
}


NetPackMsgHandler::~NetPackMsgHandler()
{

}

NetPackMsgHandler * NetPackMsgHandler::CreateNetPackMsgHandler(tcp::socket socket )
{
	return new TcpNetPackMsgHandler(std::move(socket));
}

void NetPackMsgHandler::SetMsgCallback(NetMsgCallback* p_netMsgCallback)
{
	_p_netMsgCallback = p_netMsgCallback;
}