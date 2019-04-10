#include "NetStructure.h"

NetPackMsg::NetPackMsg()
{
	_buffer_length = 0;
	_header_length = 0;
	_p_buffer = nullptr;
	_p_header = nullptr;
	_p_body = nullptr;
	_content_length = 0;
	_p_content = nullptr;
}

NetPackMsg::~NetPackMsg()
{
	_destroy();
}

NetPackMsg::NetPackMsg(const NetPackMsg& netPackMsg) :
	NetPackMsg()
{
	_copy(netPackMsg);
}

NetPackMsg& NetPackMsg::operator=(const NetPackMsg& netPackMsg)
{
	_destroy();
	_copy(netPackMsg);
	return *this;
}

NetPackMsg::NetPackMsg(NetPackMsg&& netPackMsg)
{
	_destroy();

	_header_length = netPackMsg._header_length;
	_buffer_length = netPackMsg._buffer_length;
	_content_length = netPackMsg._content_length;

	_p_buffer = netPackMsg._p_buffer;
	_p_header = netPackMsg._p_header;
	_p_body = netPackMsg._p_body;
	_p_content = netPackMsg._p_content;

	netPackMsg._p_buffer = nullptr;
	netPackMsg._p_header = nullptr;
	netPackMsg._p_body = nullptr;
	netPackMsg._p_content = nullptr;

	netPackMsg._header_length = 0;
	netPackMsg._buffer_length = 0;
	netPackMsg._content_length = 0;
}

void* NetPackMsg::GetBuffer()
{
	return _p_buffer;
}

int NetPackMsg::GetBufferLength()
{
	return _buffer_length;
}

const NetPackHeader* NetPackMsg::GetHeader()
{
	return _p_header;
}

int NetPackMsg::SetHeader(const void* pheader_data_from_network)
{
	return _decode_header(pheader_data_from_network);
}

int NetPackMsg::GetHeaderLength()
{
	return _header_length;
}

void* NetPackMsg::GetBody()
{
	return _p_body;
}

int NetPackMsg::GetBodyLength()
{
	return _buffer_length - _header_length;
}

const char* NetPackMsg::GetContent()
{
	if (_p_content == nullptr)
	{
		std::string decompressed = _zipper.Decompress(_p_body, GetBodyLength());
		_content_length = (int)decompressed.size() + 1;
		_p_content = new char[_content_length];
		std::strcpy(_p_content, decompressed.c_str());
	}

	return _p_content;
}


int NetPackMsg::SetConent(const char* p_message_content_raw)
{
	std::string compressed = _zipper.Compress(std::string{ p_message_content_raw });

	if (compressed.size() > MAX_NET_DATA_BUFFER_SIZE) return -1;

	_header_length = sizeof(NetPackHeader);
	_content_length = (int)std::strlen(p_message_content_raw) + 1/*the string terminator*/;
	_p_content = new char[_content_length];
	std::memcpy(_p_content, p_message_content_raw, _content_length);

	_buffer_length = _header_length + (int)compressed.size();

	_p_buffer = new char[_buffer_length];
	_p_header = (NetPackHeader*)_p_buffer;
	_p_body = _p_buffer + _header_length;

	_encode_header();

	std::memcpy(_p_body, compressed.c_str(), compressed.size());

	return  _content_length;
}

int NetPackMsg::GetContentLength()
{
	return _content_length;
}

int NetPackMsg::GetHeaderSize()
{
	return sizeof(NetPackHeader);
}

void NetPackMsg::_copy(const NetPackMsg& netPackMsg)
{
	_header_length = netPackMsg._header_length;
	_buffer_length = netPackMsg._buffer_length;
	_content_length = netPackMsg._content_length;

	if (netPackMsg._buffer_length >= 0 && netPackMsg._p_buffer)
	{
		_p_buffer = new char[_buffer_length];
		std::memcpy(_p_buffer, netPackMsg._p_buffer, _buffer_length);
	}

	if (netPackMsg._content_length >= 0 && netPackMsg._p_content)
	{
		_p_content = new char[_content_length];
		std::memcpy(_p_content, netPackMsg._p_content, _content_length);
	}

	_p_header = (NetPackHeader*)_p_buffer;
	_p_body = _p_buffer + _header_length;
}

int NetPackMsg::_encode_header()
{
	_p_header->body_len = boost::endian::native_to_big(uint16_t(_buffer_length - _header_length));
	_p_header->compression = _zipper.GetCompressionLevel();
	_p_header->version = NET_PACK_FORMAT_VER;
	_p_header->offset = boost::endian::native_to_big((std::uint16_t)(_p_body - _p_buffer));
	_p_header->reserved = boost::endian::native_to_big((uint32_t)0);

	_crc_result.process_bytes(_p_header, sizeof(NetPackHeader) - sizeof(NetPackHeader::checksum));
	_p_header->checksum = boost::endian::native_to_big((uint32_t)_crc_result.checksum());

	return sizeof(NetPackHeader);
}

int NetPackMsg::_decode_header(const void* pheader_data)
{
	/*verify the header data*/
	NetPackHeader* pheader = (NetPackHeader*)pheader_data;
	_crc_result.process_bytes(pheader_data, sizeof(NetPackHeader) - sizeof(NetPackHeader::checksum));
	int checksum = boost::endian::big_to_native((uint32_t)pheader->checksum);
	if (_crc_result.checksum() != checksum) return -1;

	int body_length = boost::endian::big_to_native((uint16_t)pheader->body_len);
	if (body_length > MAX_NET_DATA_BUFFER_SIZE) return -1;

	int compression = pheader->compression;
	if (compression != _zipper.GetCompressionLevel()) return -1;

	int offset = boost::endian::big_to_native((uint16_t)pheader->offset);
	if (offset != sizeof(NetPackHeader)) return -1;

	int version = pheader->version;
	if (version != NET_PACK_FORMAT_VER) return -1;

	int reserved = boost::endian::big_to_native((uint32_t)pheader->reserved);

	int header_length = offset;
	if (!_p_buffer) delete _p_buffer;
	_header_length = header_length;
	_buffer_length = _header_length + body_length;
	_p_buffer = new char[_buffer_length];
	_p_header = (NetPackHeader*)_p_buffer;
	std::memcpy(_p_header, pheader_data, _header_length);
	_p_body = _p_buffer + _header_length;

	/*delete the content so it will be rebuilt from body*/
	if (_p_content) delete _p_content;

	_p_header->body_len = (pheader->body_len);
	_p_header->compression = boost::endian::big_to_native(pheader->compression);
	_p_header->offset = boost::endian::big_to_native(pheader->offset);
	_p_header->version = boost::endian::big_to_native(pheader->version);
	_p_header->reserved = boost::endian::big_to_native(pheader->reserved);

	return sizeof(NetPackHeader);
}

void NetPackMsg::_destroy()
{
	if (_p_buffer) delete _p_buffer;
	_buffer_length = 0;
	_p_buffer = nullptr;
	_p_header = nullptr;
	_p_body = nullptr;
	_header_length = 0;

	if (_p_content) delete _p_content;
	_p_content = nullptr;
	_content_length = 0;

}

