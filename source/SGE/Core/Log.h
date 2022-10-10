#pragma once
#include "sgepch.h"

#include "Defines.h"
#include "spdlog/spdlog.h"

namespace sge
{
	class SGE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger();
		inline static std::shared_ptr<spdlog::logger>& getClientLogger();

	private:
		~Log() = default;

		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}

#define SGE_CORE_TRACE(...) ::sge::Log::getCoreLogger()->trace(__VA_ARGS__)
#define SGE_CORE_INFO(...) ::sge::Log::getCoreLogger()->info(__VA_ARGS__)
#define SGE_CORE_WARN(...) ::sge::Log::getCoreLogger()->warn(__VA_ARGS__)
#define SGE_CORE_ERROR(...) ::sge::Log::getCoreLogger()->error(__VA_ARGS__)
#define SGE_CORE_FATAL(...) ::sge::Log::getCoreLogger()->fatal(__VA_ARGS__)

#define SGE_TRACE(...) ::sge::Log::getClientLogger()->trace(__VA_ARGS__)
#define SGE_INFO(...) ::sge::Log::getClientLogger()->info(__VA_ARGS__)
#define SGE_WARN(...) ::sge::Log::getClientLogger()->warn(__VA_ARGS__)
#define SGE_ERROR(...) ::sge::Log::getClientLogger()->error(__VA_ARGS__)
#define SGE_FATAL(...) ::sge::Log::getClientLogger()->fatal(__VA_ARGS__)
