#pragma once

#ifdef MM_PLATFORM_WINDOWS
	#ifdef MM_BUILD_DLL
		#define MARMOT_API __declspec(dllexport)
	#else
		#define MARMOT_API __declspec(dllimport)
	#endif
#else
	#error Marmot only supports Windows!
#endif

#ifdef MM_ENABLE_ASSERTS
	#define MM_ASSERT(x, ...) { if(!(x)) { MM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define MM_CORE_ASSERT(x, ...) { if(!(x)) { MM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MM_ASSERT(x, ...)
	#define MM_CORE_ASSERT(x, ...)
#endif