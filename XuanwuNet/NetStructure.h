#pragma once
#include <boost/asio.hpp>
#include<memory>

#define MAX_TCP_DATA_BUFFER_SIZE 99999999
#define TCP_DATA_HEADER_SIZE 8
class NetPackMsg
{
public:
		
	NetPackMsg(int length)
	{ 
		_header_length = enum_header_length;
		_body_length = length;
		_length = _body_length + _header_length;
		_p_buffer =  new char[_length];
		_p_header = _p_buffer;
		_p_body = _p_buffer + _header_length;

		_encode_header();
	}

	NetPackMsg(const char* p_message_content)
	{
		_header_length = enum_header_length;
		_body_length = (int)std::strlen(p_message_content) + 1/*the string terminator*/;
		_length = _body_length + _header_length;
		_p_buffer = new char[_length];
		_p_header = _p_buffer;
		_p_body = _p_buffer + _header_length;
		std::strcpy(_p_body, p_message_content);

		_encode_header();

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

		_header_length = netPackMsg._header_length;
		_body_length = netPackMsg._body_length;
		_length = netPackMsg._length;

		_p_buffer = netPackMsg._p_buffer;
		_p_header = netPackMsg._p_header;
		_p_body = netPackMsg._p_body;

		netPackMsg._p_buffer = nullptr;
		netPackMsg._p_header = nullptr;
		netPackMsg._p_body = nullptr;

		netPackMsg._header_length = 0;
		netPackMsg._body_length = 0;
		netPackMsg._length = 0;
	}

	~NetPackMsg() { _destroy(); };

	void* Buffer() { return _p_buffer; }
	int Length() { return _length; }
	void* Header() { return _p_header; }
	int HeaderLen() { return _header_length; }
	void* Body() { return _p_body; }
	int BodyLen() { return _body_length; }

private:
	enum { enum_header_length = TCP_DATA_HEADER_SIZE};

	int _length;
	int _body_length;
	int _header_length;
	char* _p_buffer;
	char* _p_header;
	char* _p_body;

	void _copy(const NetPackMsg& netPackMsg)
	{
		_header_length = netPackMsg._header_length;
		_body_length = netPackMsg._body_length;
		_length = netPackMsg._length;

		if (netPackMsg._length >= 0 && netPackMsg._p_buffer)
		{
			_p_buffer = new char[_length] ;
			std::memcpy(_p_buffer, netPackMsg._p_buffer, _length);
		}

		_p_header = _p_buffer;
		_p_body = _p_buffer + _header_length;
	}

	void _encode_header()
	{
		char header[enum_header_length + 1] = "";
		std::strncpy(header,  std::to_string(_body_length).c_str(), enum_header_length);
		std::memcpy(_p_header, header, enum_header_length);
		_header_length = enum_header_length;
	}

	void _decode_header()
	{
		char header[enum_header_length + 1] = "";
		std::strncat(header, _p_header, enum_header_length);
		_body_length = std::atoi(header);
		_header_length = enum_header_length;
	}

	void _destroy()
	{
		if(_p_buffer) delete _p_buffer;
		_length = 0;
		_p_buffer = nullptr;
		_body_length = 0;
		_p_header = nullptr;
		_p_body = nullptr;
	}
};


using boost::asio::ip::tcp;
using boost::asio::ip::udp;


