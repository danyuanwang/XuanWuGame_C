#pragma once
#include"NetStructure.h"
#include "NetMsgCallback.h"

class  NetPackMsgHandler :
	public std::enable_shared_from_this<NetPackMsgHandler>
{
public:
	virtual  ~NetPackMsgHandler();

	virtual int ReadAsync() = 0;
	virtual int WriteAsync(std::unique_ptr<NetPackMsg>  up_message) = 0;
	virtual void CloseSocket() = 0;

	static NetPackMsgHandler* CreateNetPackMsgHandler(tcp::socket socket);
	static NetPackMsgHandler* CreateNetPackMsgHandler(udp::socket socket) { throw E_NOTIMPL; }

	void SetMsgCallback(NetMsgCallback* up_netMsgCallback);
protected:
	NetPackMsgHandler();


	char _data_header[TCP_DATA_HEADER_SIZE + 1] = "";
	int _header_len = TCP_DATA_HEADER_SIZE;
	int _package_len;
	int _message_len;

	NetMsgCallback* _p_netMsgCallback; //using ordinary pointer means no ownership.

};