#pragma once
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <sstream>
#include<string>

class GZip
{
public:
	GZip();
	virtual ~GZip();

	std::string Compress(const char* pdata, int count);
	std::string Compress(const std::string& data);

	std::string Decompress(const std::string& data);
	std::string Decompress(const char* pdata, int count);
	int GetCompressionLevel();
};
