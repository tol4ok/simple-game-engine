#pragma once

#ifdef SGE_PLATFORM_WINDOWS
	#ifdef SGE_BUILD_DLL
		#define SGE_API __declspec(dllexport)
	#else
		#define SGE_API __declspec(dllimport)
	#endif
#endif