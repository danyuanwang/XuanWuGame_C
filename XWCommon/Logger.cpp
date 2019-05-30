#include "Logger.h"
#include <stdarg.h>
#include <stdio.h>
#include <cstddef>
#include <string>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <boost/core/null_deleter.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/attributes/scoped_attribute.hpp>
#include <boost/log/sources/basic_logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/value_ref.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/phoenix/bind.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>

namespace XWCommon {
	const int max_print_buffer = 1024;
	const char* singleton_log_file_name = "logfilename";

	namespace logging = boost::log;
	namespace src = boost::log::sources;
	namespace expr = boost::log::expressions;
	namespace sinks = boost::log::sinks;
	namespace attrs = boost::log::attributes;
	namespace keywords = boost::log::keywords;

	static src::severity_logger< logging::trivial::severity_level > s_logger;

	void Logger::_init(const char* logfilename)
	{
		// Construct the sink
		typedef sinks::synchronous_sink< sinks::text_ostream_backend > text_sink;
		boost::shared_ptr< text_sink > sink = boost::make_shared< text_sink >();

		if (logfilename != nullptr)
		{
			// Add a stream to write log to
			sink->locked_backend()->add_stream(
				boost::make_shared< std::ofstream >(logfilename));
		}

		// We have to provide an empty deleter to avoid destroying the global stream object
		boost::shared_ptr< std::ostream > stream(&std::clog, boost::null_deleter());
		sink->locked_backend()->add_stream(stream);

		// Register the sink in the logging core
		logging::core::get()->add_sink(sink);
	}


	Logger::Logger() :
		Logger(nullptr)
	{

	}

	Logger::Logger(const char * logfilename)
	{
		_init(logfilename);
	}

	Logger::~Logger()
	{

	}

	int Logger::LogTraceF(const char* fmt, ...)
	{
		int result = 0;
		va_list argp;
		va_start(argp, fmt);

		result = _print(logging::trivial::severity_level::trace, fmt, argp);

		va_end(argp);
		return result;
	}

	int Logger::LogDebugF(const char* fmt, ...)
	{
		int result = 0;
		va_list argp;
		va_start(argp, fmt);
		result = _print(logging::trivial::severity_level::debug, fmt, argp);
		va_end(argp);
		return result;
	}

	int Logger::LogInfoF(const char* fmt, ...)
	{
		int result = 0;
		va_list argp;
		va_start(argp, fmt);
		result = _print(logging::trivial::severity_level::info, fmt, argp);
		va_end(argp);
		return result;
	}

	int Logger::LogWarningF(const char* fmt, ...)
	{
		int result = 0;
		va_list argp;
		va_start(argp, fmt);
		result = _print(logging::trivial::severity_level::warning, fmt, argp);
		va_end(argp);
		return result;
	}

	int Logger::LogErrorF(const char* fmt, ...)
	{
		int result = 0;
		va_list argp;
		va_start(argp, fmt);
		result = _print(logging::trivial::severity_level::error, fmt, argp);
		va_end(argp);
		return result;
	}

	int Logger::LogFatalF(const char* fmt, ...)
	{
		int result = 0;
		va_list argp;
		va_start(argp, fmt);
		result = _print(logging::trivial::severity_level::fatal, fmt, argp);
		va_end(argp);
		return result;
	}

	int Logger::LogTrace(const char * str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::trace) << str;
		return 0;
	}

	int Logger::LogDebug(const char * str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::debug) << str;
		return 0;
	}

	int Logger::LogInfo(const char * str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::info) << str;
		return 0;
	}

	int Logger::LogWarning(const char * str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::warning) << str;
		return 0;
	}

	int Logger::LogError(const char * str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::error) << str;
		return 0;
	}

	int Logger::LogFatal(const char * str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::fatal) << str;
		return 0;
	}

	int Logger::LogTrace(const std::string & str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::trace) << str;

		return 0;
	}

	int Logger::LogDebug(const std::string & str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::debug) << str;

		return 0;
	}

	int Logger::LogInfo(const std::string & str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::info) << str;

		return 0;
	}

	int Logger::LogWarning(const std::string & str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::warning) << str;

		return 0;
	}

	int Logger::LogError(const std::string & str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::error) << str;

		return 0;
	}

	int Logger::LogFatal(const std::string & str)
	{
		BOOST_LOG_SEV(s_logger, logging::trivial::severity_level::fatal) << str;

		return 0;
	}

	Logger * Logger::GetSingleton()
	{
		if (ps_logger.get() == nullptr)
		{
			std::unique_lock<std::mutex> lck(_singleton_mutex);
			if (ps_logger.get() == nullptr)
			{
				ps_logger = std::move(std::unique_ptr<Logger>{ new Logger() });
			}
		}

		return ps_logger.get();
	}

	int Logger::_print(int level, const char* fmt, ...)
	{
		int result = 0;
		char c_buf[max_print_buffer] = "\0";

		va_list argp;
		va_start(argp, fmt);
		result = std::snprintf(c_buf, sizeof(c_buf), fmt, argp);
		va_end(argp);
		auto s_level = (logging::trivial::severity_level)level;

		BOOST_LOG_SEV(s_logger, s_level) << c_buf;
		return result;
	}

}