#pragma once


#include"Core.h"
#include"spdlog/spdlog.h"
#include"spdlog/fmt/ostr.h"

namespace Marmot
{
	class MARMOT_API Log
	{
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	};
}

// Marmot::Log::GetCoreLogger()->warn("Initialized LOG!");
// This is too long, that's why we use Macros 
// also when stripping code for distribution version

#define MM_CORE_ERROR(...) ::Marmot::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MM_CORE_TRACE(...) ::Marmot::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MM_CORE_WARN(...) ::Marmot::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MM_CORE_INFO(...) ::Marmot::Log::GetCoreLogger()->info(__VA_ARGS__)

#define MM_ERROR(...) ::Marmot::Log::GetClientLogger()->error(__VA_ARGS__)
#define MM_TRACE(...) ::Marmot::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MM_WARN(...) ::Marmot::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MM_INFO(...) ::Marmot::Log::GetClientLogger()->info(__VA_ARGS__)