#include "TcpNetPackMsgHandler.h"

TcpNetPackMsgHandler::TcpNetPackMsgHandler(tcp::socket socket)
	:_socket(std::move(socket))
{

}



TcpNetPackMsgHandler::~TcpNetPackMsgHandler()
{
	_socket.close();
}


int TcpNetPackMsgHandler::ReadAsync()
{
	/*first, read header to determine the pack size*/
	boost::asio::async_read(_socket,
		boost::asio::buffer(_data_header, _header_len),
		[this](boost::system::error_code ec, std::size_t /*length*/)
	{
		if (!ec)
		{
			_message_len = std::atoi(_data_header);
			if (_message_len < MAX_TCP_DATA_BUFFER_SIZE && _message_len > 0)
			{
				auto up_netmsg = new NetPackMsg(_message_len);
				boost::asio::async_read(_socket,
					boost::asio::buffer(up_netmsg->Body(), _message_len),
					[this, up_netmsg](boost::system::error_code ec, std::size_t length)
				{
					if (!ec && _p_netMsgCallback != nullptr && length == _message_len)
					{
						_p_netMsgCallback->OnReceivedMsgCallback(std::unique_ptr<NetPackMsg>(up_netmsg));
					}
					else
					{
						_message_len = 0;
						_package_len = 0;
					}
				});
			}
		}
		return 0;
	});

	return 0;
}

int TcpNetPackMsgHandler::WriteAsync(std::unique_ptr<NetPackMsg> up_message)
{
	boost::asio::async_write(_socket,
		boost::asio::buffer(up_message->Buffer(), up_message->Length()),
		[this](boost::system::error_code ec, std::size_t length)
	{
		if (!_p_netMsgCallback)
		{
			_p_netMsgCallback->OnSentMsgCallback(ec, length);
		}
	});

	return 0;
}

void TcpNetPackMsgHandler::CloseSocket()
{
	_socket.close();
}