#include "TcpNetPackMsgHandler.h"
#if _DEBUG
#include <iostream>
#endif

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
	auto sp_data_header = std::shared_ptr<char>(new char[_header_len + 1]);
	std::memset(sp_data_header.get(), 0, _header_len + 1);

	boost::asio::async_read(_socket,
		boost::asio::buffer(sp_data_header.get(), _header_len),
		boost::asio::transfer_at_least(_header_len),
		[this, sp_data_header](boost::system::error_code ec, std::size_t bytes_transferred)
		{
			if (!ec)
			{

				int message_len = std::atoi(sp_data_header.get());

				assert(bytes_transferred == _header_len);
				assert(message_len > _header_len);

#if _DEBUG
				std::cout << __FUNCTION__ << " : " << sp_data_header << " : " << bytes_transferred << " : " << message_len << std::endl;
				//								std::cout << std::string{ (const char*)sp_read_message->Body() } << std::endl;
#endif

				if (message_len < MAX_TCP_DATA_BUFFER_SIZE && message_len > 0)
				{
					auto sp_read_message = std::shared_ptr<NetPackMsg>(new NetPackMsg(message_len));

					boost::asio::async_read(
						_socket,
						boost::asio::buffer(sp_read_message->Body(), message_len),
						boost::asio::transfer_at_least(message_len),
						[this, sp_read_message](boost::system::error_code ec, std::size_t bytes_transferred)
						{
							if (!ec)
							{
								assert(bytes_transferred == sp_read_message->BodyLen());

#if _DEBUG
								std::cout << __FUNCTION__ << " : " << sp_read_message->BodyLen() << " vs " << bytes_transferred << " : " << std::endl;
//								std::cout << std::string{ (const char*)sp_read_message->Body() } << std::endl;
#endif
								if (_p_netMsgCallback != nullptr)
								{
									_p_netMsgCallback->OnReceivedMsgCallback(sp_read_message.get());
								}

								ReadAsync();
							}

						});
				}

			}
			return 0;
		});

	return 0;
}

int TcpNetPackMsgHandler::WriteAsync(NetPackMsg* p_netmsg)
{
	boost::asio::async_write(_socket,
		boost::asio::buffer(p_netmsg->Buffer(), p_netmsg->Length()),
		boost::asio::transfer_at_least(p_netmsg->Length()),
		[this, p_netmsg](boost::system::error_code ec, std::size_t bytes_transferred)
		{
			if (_p_netMsgCallback != nullptr)
			{
				_p_netMsgCallback->OnSentMsgCallback(ec, bytes_transferred);
			}
		});

	return 0;
}

void TcpNetPackMsgHandler::CloseSocket()
{
	_socket.close();
}