#pragma once
#include <boost/asio.hpp>
#include<memory>
#include <stdint.h>
#include <boost/endian/conversion.hpp>
#include "GZip.h"
#include <boost/crc.hpp>  // for boost::crc_32_type


#define MAX_NET_DATA_BUFFER_SIZE 65535
#define NET_PACK_FORMAT_VER 1

/*
  The structure for network transfer, the first 8 bytes is header
  |--two bytes---|-------two bytes -------|one byte--|-one byte----|--------reserved------|--------checksum------|
  |--body length-|-------offset-----------|-version--|-compression-|----------------------|----------------------|
  | -----------------------------          body                                                  ----------------|
*/


struct NetPackHeader
{
	std::uint16_t body_len; /**/
	std::uint16_t offset;
	std::uint8_t version;
	std::uint8_t compression; // 0 -- no compression;check zlib.h for more values
	std::uint16_t reserved;
	std::uint32_t checksum;
};


class NetPackMsg
{
public:
	NetPackMsg();


	NetPackMsg(const NetPackMsg& netPackMsg);

	NetPackMsg& operator=(const NetPackMsg& netPackMsg);

	NetPackMsg(NetPackMsg&& netPackMsg);

	~NetPackMsg();

	void* GetBuffer();
	int GetBufferLength();
	const NetPackHeader* GetHeader();
	int SetHeader(const void* pheader_data_from_network);

	int GetHeaderLength();
	void* GetBody();
	int GetBodyLength();
	const char* GetContent();
	int SetConent(const char* p_message_content_raw);
	int GetContentLength();

	static int GetHeaderSize();

private:
	int _buffer_length;
	int _header_length;
	char* _p_buffer;
	NetPackHeader* _p_header;
	char* _p_body;
	int _content_length;
	char* _p_content;
	GZip _zipper;
	boost::crc_32_type  _crc_result;

	void _copy(const NetPackMsg& netPackMsg);

	int _encode_header();

	int _decode_header(const void* pheader_data_from_network);
	void _destroy();

};


using boost::asio::ip::tcp;
using boost::asio::ip::udp;


