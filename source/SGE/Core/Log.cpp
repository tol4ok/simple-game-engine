#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace sge
{
	std::shared_ptr<spdlog::logger> Log::s_coreLogger;
	std::shared_ptr<spdlog::logger> Log::s_clientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_coreLogger = spdlog::stdout_color_mt("SGE");
		s_coreLogger->set_level(spdlog::level::trace);

		s_clientLogger = spdlog::stdout_color_mt("CLIENT");
		s_clientLogger->set_level(spdlog::level::trace);

		SGE_CORE_TRACE("Log initialized!");
	}

	inline std::shared_ptr<spdlog::logger>& Log::getCoreLogger()
	{
		return s_coreLogger;
	}

	inline std::shared_ptr<spdlog::logger>& Log::getClientLogger()
	{
		return s_clientLogger;
	}
}