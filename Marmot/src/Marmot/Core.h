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