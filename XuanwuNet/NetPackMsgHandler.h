#pragma once
#include"NetStructure.h"
#include "NetMsgCallback.h"

class  NetPackMsgHandler
{
public:
	virtual  ~NetPackMsgHandler();

	virtual int ReadAsync() = 0;
	virtual int WriteAsync(NetPackMsg*  up_message) = 0;
	virtual void CloseSocket() = 0;

	static NetPackMsgHandler* CreateNetPackMsgHandler(tcp::socket socket);
	static NetPackMsgHandler* CreateNetPackMsgHandler(udp::socket socket) { throw std::logic_error("not implemented"); }

	void SetMsgCallback(NetMsgCallback* up_netMsgCallback);
protected:
	NetPackMsgHandler();

	NetMsgCallback* _p_netMsgCallback; //using ordinary pointer means no ownership.

};