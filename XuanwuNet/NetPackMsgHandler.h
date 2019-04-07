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
	static NetPackMsgHandler* CreateNetPackMsgHandler(udp::socket socket) { throw E_NOTIMPL; }

	void SetMsgCallback(NetMsgCallback* up_netMsgCallback);
protected:
	NetPackMsgHandler();


	int _header_len = TCP_DATA_HEADER_SIZE;

	NetMsgCallback* _p_netMsgCallback; //using ordinary pointer means no ownership.

};