#pragma once
#include "NetPackMsgHandler.h"
class TcpNetPackMsgHandler :
	public NetPackMsgHandler
{
public:
	TcpNetPackMsgHandler(tcp::socket socket);
	virtual ~TcpNetPackMsgHandler();

	int ReadAsync(OnReceivedMsgCallback callback);
	int WriteAsync(std::unique_ptr<NetPackMsg>  up_message, OnSentMsgCallback onSentCallback);
	void CloseSocket();

private:
	tcp::socket _socket;
};

