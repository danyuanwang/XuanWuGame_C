#include "TcpNetPackMsgHandler.h"

TcpNetPackMsgHandler::TcpNetPackMsgHandler(tcp::socket socket)
	:_socket(std::move(socket))
{

}



TcpNetPackMsgHandler::~TcpNetPackMsgHandler()
{
}


int TcpNetPackMsgHandler::ReadAsync(OnReceivedMsgCallback callback)
{
	_onReceivedCallback = callback;

	/*first, read header to determine the pack size*/
	auto self(shared_from_this());
	boost::asio::async_read(_socket,
		boost::asio::buffer(_data_header, _header_len),
		[this, self](boost::system::error_code ec, std::size_t /*length*/)
	{
		if (!ec)
		{
			_message_len = std::atoi(_data_header);
			if (_message_len < MAX_TCP_DATA_BUFFER_SIZE && _message_len > 0)
			{
				auto up_netmsg = new NetPackMsg;
				up_netmsg->length = _message_len;
				up_netmsg->up_data_buffer = std::unique_ptr<char>(new char[_message_len]);

				boost::asio::async_read(_socket,
					boost::asio::buffer(up_netmsg->up_data_buffer.get(), _message_len),
					[this, self, up_netmsg](boost::system::error_code ec, std::size_t length)
				{
					if (!ec && !_onReceivedCallback && length == _message_len)
					{
						_onReceivedCallback(std::unique_ptr<NetPackMsg>(up_netmsg));
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

int TcpNetPackMsgHandler::WriteAsync(std::unique_ptr<NetPackMsg> up_message, OnSentMsgCallback onSentCallback)
{
	_onSentCallback = onSentCallback;

	auto self(shared_from_this());
	boost::asio::async_write(_socket,
		boost::asio::buffer(up_message->up_data_buffer.get(), up_message->length),
		[this, self](boost::system::error_code ec, std::size_t length)
	{
		if (!_onSentCallback)
		{
			_onSentCallback(ec, length);
		}
	});

	return 0;
}

void TcpNetPackMsgHandler::CloseSocket()
{
	_socket.close();
}