#include "GZip.h"

GZip::GZip()
{
}


GZip::~GZip()
{
}


std::string GZip::Compress(const std::string& data)
{
	namespace bio = boost::iostreams;

	std::stringstream compressed;
	std::stringstream origin(data);

	bio::filtering_streambuf<bio::input> out;
	out.push(bio::gzip_compressor(bio::gzip_params(bio::gzip::best_compression)));
	out.push(origin);
	bio::copy(out, compressed);

	return compressed.str();
}

std::string GZip::Decompress(const std::string& data)
{
	namespace bio = boost::iostreams;

	std::stringstream compressed(data);
	std::stringstream decompressed;

	bio::filtering_streambuf<bio::input> out;
	out.push(bio::gzip_decompressor());
	out.push(compressed);
	bio::copy(out, decompressed);

	return decompressed.str();
}

