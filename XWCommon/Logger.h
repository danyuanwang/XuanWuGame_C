#pragma once
#include <memory>
#include <mutex>
#include <string>
#include <stdarg.h>

namespace XWCommon {
	class Logger
	{
	private:
		void _init(const char* logfilename);

		static std::unique_ptr<Logger> ps_logger;
		static std::mutex _singleton_mutex;

	public:

		Logger();
		Logger(const char* logfilename);
		virtual ~Logger();

		int Print(const char* file_path, int line_no, const char* function, int level, const char* format, ...);
		static Logger* GetSingleton();
	};
}

#define LOGTRACE(e, ...) XWCommon::Logger::GetSingleton()->Print(__FILE__, __LINE__, __func__, 0/*trace*/, e,  __VA_ARGS__)
#define LOGDEBUG(e, ...) XWCommon::Logger::GetSingleton()->Print(__FILE__, __LINE__, __func__, 1/*debug*/, e,  __VA_ARGS__)
#define LOGINFO(e, ...)  XWCommon::Logger::GetSingleton()->Print(__FILE__, __LINE__, __func__, 2/*info*/, e,   __VA_ARGS__)
#define LOGWARN(e, ...)  XWCommon::Logger::GetSingleton()->Print(__FILE__, __LINE__, __func__, 3/*warn*/, e,   __VA_ARGS__)
#define LOGERROR(e, ...) XWCommon::Logger::GetSingleton()->Print(__FILE__, __LINE__, __func__, 4/*error*/, e,  __VA_ARGS__)
#define LOGFATAL(e, ...) XWCommon::Logger::GetSingleton()->Print(__FILE__, __LINE__, __func__, 5/*fatal*/, e,  __VA_ARGS__)

