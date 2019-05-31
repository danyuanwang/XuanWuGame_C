#pragma once
#include <memory>
#include <mutex>
#include <string>
#include <stdarg.h>

namespace XWCommon {
	class Logger
	{
	private:
		int _print(int level, const char* format, ...);
		void _init(const char* logfilename);

		static std::unique_ptr<Logger> ps_logger;
		static std::mutex _singleton_mutex;

	public:
		Logger();
		Logger(const char* logfilename);
		virtual ~Logger();

		int LogTraceF(const char* format, ...);
		int LogDebugF(const char* format, ...);
		int LogInfoF(const char* format, ...);
		int LogWarningF(const char* format, ...);
		int LogErrorF(const char* format, ...);
		int LogFatalF(const char* format, ...);

		int LogTrace(const char* str);
		int LogDebug(const char* str);
		int LogInfo(const char* str);
		int LogWarning(const char* str);
		int LogError(const char* str);
		int LogFatal(const char* str);

		int LogTrace(const std::string& str);
		int LogDebug(const std::string& str);
		int LogInfo(const std::string& str);
		int LogWarning(const std::string& str);
		int LogError(const std::string& str);
		int LogFatal(const std::string& str);

		static Logger* GetSingleton();
	};
}