#pragma once
#include "NetStructure.h"

class NetMsgCallback
{
public:
	NetMsgCallback();
	virtual ~NetMsgCallback();

	virtual int OnReceivedMsgCallback(std::unique_ptr<NetPackMsg>  up_message) = 0;
	virtual int OnReceivedMsgCallback(NetPackMsg*  up_message /*ordinary pointer means no ownership transfer*/) = 0;
	virtual int OnSentMsgCallback(boost::system::error_code ec, std::size_t) = 0;

};

