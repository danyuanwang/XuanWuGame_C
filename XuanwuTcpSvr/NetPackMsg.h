#pragma once
#include <boost/asio.hpp>


using boost::asio::ip::tcp;
using boost::asio::ip::udp;

#define MAX_TCP_DATA_BUFFER_SIZE  1024 * 1024 //TODO: what is the best size, or should we use dynamic size
#define TCP_DATA_HEADER_SIZE  4

struct NetPackMsg
{
	int length;
	std::unique_ptr<char> up_data_buffer;
};

typedef int(*OnReceivedMsgCallback)(std::unique_ptr<NetPackMsg>  up_message);
typedef int(*OnSentMsgCallback)(boost::system::error_code ec, std::size_t);

class  NetPackMsgHandler :
	public std::enable_shared_from_this<NetPackMsgHandler>
{
public:
	virtual  ~NetPackMsgHandler();

	virtual int ReadAsync(OnReceivedMsgCallback callback) = 0;
	virtual int WriteAsync(std::unique_ptr<NetPackMsg>  up_message, OnSentMsgCallback onSentCallback) = 0;

	static NetPackMsgHandler* CreateNetPackMsgHandler(tcp::socket socket);
	static NetPackMsgHandler* CreateNetPackMsgHandler(udp::socket socket) { throw E_NOTIMPL; }

protected:
	NetPackMsgHandler();


	char _data_header[TCP_DATA_HEADER_SIZE + 1] = "";
	int _header_len = TCP_DATA_HEADER_SIZE;
	int _package_len;
	int _message_len;
	OnReceivedMsgCallback _onReceivedCallback;
	OnSentMsgCallback _onSentCallback;

};