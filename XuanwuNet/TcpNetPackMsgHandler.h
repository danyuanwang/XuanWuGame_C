#pragma once
#include "NetPackMsgHandler.h"
class TcpNetPackMsgHandler :
	public NetPackMsgHandler
{
public:
	TcpNetPackMsgHandler(tcp::socket socket);
	virtual ~TcpNetPackMsgHandler();

	int ReadAsync();
	int WriteAsync(NetPackMsg*  p_message);
	void CloseSocket();

private:
	tcp::socket _socket;
};

