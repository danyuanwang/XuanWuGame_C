#include "GZip.h"
namespace bio = boost::iostreams;

GZip::GZip()
{
}


GZip::~GZip()
{
}


std::string GZip::Compress(const std::string& data)
{

	std::stringstream compressed;
	std::stringstream origin(data);

	bio::filtering_streambuf<bio::input> out;
	out.push(bio::gzip_compressor(bio::gzip_params(GetCompressionLevel())));
	out.push(origin);
	bio::copy(out, compressed);

	return compressed.str();
}

std::string GZip::Compress(const char* pdata, int count)
{
	return Compress(std::string(pdata, count));
}

std::string GZip::Decompress(const std::string& data)
{
	std::stringstream compressed(data);
	std::stringstream decompressed;

	bio::filtering_streambuf<bio::input> out;
	out.push(bio::gzip_decompressor());
	out.push(compressed);
	bio::copy(out, decompressed);

	return decompressed.str();
}

std::string GZip::Decompress(const char* pdata, int count)
{
	return Decompress(std::string(pdata, count));
}

int GZip::GetCompressionLevel()
{
	return bio::gzip::best_compression;
}
