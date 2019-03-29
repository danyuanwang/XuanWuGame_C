#pragma once
#include <boost/asio.hpp>
#include<memory>

class NetPackMsg
{
public:
	NetPackMsg(int length) :_length(length) 
	{ 
		_p_data_buffer =  new char[_length]; 
	}

	NetPackMsg(const char* c_str)
	{
		_length = (int)std::strlen(c_str) + 1/*the string terminator*/;
		_p_data_buffer = new char[_length];
		std::strcpy(_p_data_buffer, c_str); 
	}

	NetPackMsg(const NetPackMsg& netPackMsg)
	{ 
		_copy(netPackMsg);
	}

	NetPackMsg& operator=(const NetPackMsg& netPackMsg)
	{
		_destroy();
		_copy(netPackMsg);
	}

	NetPackMsg(NetPackMsg&& netPackMsg)
	{
		_destroy();
		_length = netPackMsg._length;
		_p_data_buffer = netPackMsg._p_data_buffer;

		netPackMsg._length = 0;
		netPackMsg._p_data_buffer = nullptr;
	}

	~NetPackMsg() { _destroy(); };

	void* Data() { return _p_data_buffer; }
	int Length() { return _length; }

private:
	int _length;
	char* _p_data_buffer;

	void _copy(const NetPackMsg& netPackMsg)
	{
		_length = netPackMsg._length;
		if (netPackMsg._length >= 0 && netPackMsg._p_data_buffer)
		{
			_p_data_buffer = new char[_length] ;
			std::memcpy(_p_data_buffer, netPackMsg._p_data_buffer, _length);
		}

	}

	void _destroy()
	{
		if(_p_data_buffer) delete _p_data_buffer;
		_length = 0;
		_p_data_buffer = nullptr;
	}
};


using boost::asio::ip::tcp;
using boost::asio::ip::udp;

#define MAX_TCP_DATA_BUFFER_SIZE  1024 * 1024 //TODO: what is the best size, or should we use dynamic size
#define TCP_DATA_HEADER_SIZE  4

