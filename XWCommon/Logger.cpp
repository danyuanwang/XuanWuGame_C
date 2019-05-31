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
	const char* singleton_log_file_name = "logfilename.log";

	namespace logging = boost::log;
	namespace src = boost::log::sources;
	namespace expr = boost::log::expressions;
	namespace sinks = boost::log::sinks;
	namespace attrs = boost::log::attributes;
	namespace keywords = boost::log::keywords;
	using severity_level = logging::trivial::severity_level;

	BOOST_LOG_ATTRIBUTE_KEYWORD(line_id, "LineID", unsigned int)
	BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", severity_level)
	BOOST_LOG_ATTRIBUTE_KEYWORD(tag_attr, "Tag", std::string)
	BOOST_LOG_ATTRIBUTE_KEYWORD(scope, "Scope", attrs::named_scope::value_type)
	BOOST_LOG_ATTRIBUTE_KEYWORD(timeline, "Timeline", attrs::timer::value_type)
		
	static src::severity_logger< severity_level > s_logger;

	std::mutex Logger::_singleton_mutex;
	std::unique_ptr<Logger> Logger::ps_logger{ nullptr };

	void my_formatter(logging::record_view const& rec, logging::formatting_ostream& strm)
	{
		
		//strm << expr::format_date_time< boost::posix_time::ptime >("Timeline", "%Y-%m-%d %H:%M:%S");
		strm << logging::extract< attrs::timer::value_type >("Timeline", rec) << "| ";

		// Get the LineID attribute value and put it into the stream
		strm << logging::extract< unsigned int >("LineID", rec) << ": ";

		// The same for the severity level.
		// The simplified syntax is possible if attribute keywords are used.
		strm << "<" << rec[logging::trivial::severity] << "> ";

		strm << "[" << logging::extract< std::string  >("Tag", rec) << "] ";

		// Finally, put the record message to the stream
		strm << rec[expr::smessage];
	}

	void Logger::_init(const char* logfilename)
	{
		s_logger.add_attribute("LineID", attrs::counter< unsigned int >(1));
		s_logger.add_attribute("Timeline", attrs::local_clock());
		s_logger.add_attribute("Tag", attrs::constant< std::string >("XWGame"));

		/*BOOST_LOG_NAMED_SCOPE("named_scope_logging");
		BOOST_LOG_SCOPED_THREAD_ATTR("Timeline", attrs::timer());
*/
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

		sink->set_formatter(&my_formatter);
		//(
		//	expr::stream
		//	//// line id will be written in hex, 8-digits, zero-filled
		//	//<< std::hex << std::setw(8) << std::setfill('0') << expr::attr< unsigned int >("LineID")
		//	//<< ": <" << logging::trivial::severity
		//	//<< "> " << expr::smessage

		//	<< expr::format_date_time< boost::posix_time::ptime >("Timeline", "%Y-%m-%d %H:%M:%S")
		//	<< "|"
		//	<< expr::format("%1%: <%2%> %3%")
		//	% expr::attr< unsigned int >("LineID")
		//	% logging::trivial::severity
		//	% expr::smessage
		//);

		// Register the sink in the logging core
		logging::core::get()->add_sink(sink);


		logging::core::get()->set_filter
		(
			logging::trivial::severity >= 
#if _DEBUG
			logging::trivial::debug
#else
			logging::trivial::info
#endif
		);

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
				ps_logger = std::move(std::unique_ptr<Logger>{ new Logger(singleton_log_file_name) });
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