#pragma once
#include <string>
#include <exception>

enum class XW_ERROR_CODE
{
	OK = 0,
	FAILED = -1,
	GE_INIT_FAILED = -2,
	GE_NOT_INITED = -3,
	GE_SDL_BASEPATH_FAILED = -4,
	GE_SDL_WINDOW_CREATION_FAILED = -5,
	GE_SDL_SURFACE_GETTING_FAILED = -6
};

class XuanwuException : public std::exception
{
public:
	XW_ERROR_CODE ErrorCode;

	XuanwuException(XW_ERROR_CODE error, const char* message)
		:std::exception(message)
		, ErrorCode(error)
	{
	}
	XuanwuException(XW_ERROR_CODE error, const std::string& message)
		:XuanwuException(error, message.c_str())
	{
	}
};

#define CHECK_VALUE(value, error, message) if(!value) {throw XuanwuException(error, message);}

