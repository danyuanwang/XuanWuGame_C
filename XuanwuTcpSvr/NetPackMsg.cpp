#include <memory>
#include <string>
#include "NetPackMsg.h"
#include "TcpNetPackMsg.h"

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
