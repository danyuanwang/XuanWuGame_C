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
