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
	auto sp_data_header = std::shared_ptr<char>(new char[NetPackMsg::GetHeaderSize() + 1]);
	std::memset(sp_data_header.get(), 0, NetPackMsg::GetHeaderSize() + 1);

	boost::asio::async_read(_socket,
		boost::asio::buffer(sp_data_header.get(), NetPackMsg::GetHeaderSize()),
		boost::asio::transfer_at_least(NetPackMsg::GetHeaderSize()),
		[this, sp_data_header](boost::system::error_code ec, std::size_t bytes_transferred)
		{
			if (!ec)
			{
				auto sp_read_message = std::shared_ptr<NetPackMsg>(new NetPackMsg());

				if(sp_read_message->SetHeader((const void*)sp_data_header.get())>0)
				{
					boost::asio::async_read(
						_socket,
						boost::asio::buffer(sp_read_message->GetBody(), sp_read_message->GetBodyLength()),
						boost::asio::transfer_at_least(sp_read_message->GetBodyLength()),
						[this, sp_read_message](boost::system::error_code ec, std::size_t bytes_transferred)
						{
							if (!ec)
							{

#if _DEBUG
								std::cout << __FUNCTION__ << " : " << sp_read_message->GetBodyLength() << " vs " << bytes_transferred << " : " << std::endl;
								std::cout << std::string{ (const char*)sp_read_message->GetContent() } << std::endl;
#endif
								if (_p_netMsgCallback != nullptr)
								{
									_p_netMsgCallback->OnReceivedMsgCallback(sp_read_message.get());
								}

								ReadAsync();

							}

						});
				}
				else
				{
					ReadAsync();
				}

			}
			return 0;
		});

	return 0;
}

int TcpNetPackMsgHandler::WriteAsync(NetPackMsg* p_netmsg)
{
	boost::asio::async_write(_socket,
		boost::asio::buffer(p_netmsg->GetBuffer(), p_netmsg->GetBufferLength()),
		boost::asio::transfer_at_least(p_netmsg->GetBufferLength()),
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