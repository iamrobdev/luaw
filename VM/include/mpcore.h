#pragma once

#include <cstdio>

#if defined(_WIN32) || defined(_WIN64)
	#define mpWINDOWS
	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX
	#define fwrite_locknt(ptr, size, count, stream) _fwrite_nolock(ptr, size, count, stream)
#elif defined(__linux__) || defined(__gnu_linux__) || defined(__ANDROID__)
	#define mpLINUX
	#define fwrite_locknt(ptr, size, count, stream) fwrite_unlocked(ptr, size, count, stream)
#elif defined(__APPLE__) || defined(__MACH__)
	#define mpAPPLE
	#define fwrite_locknt(ptr, size, count, stream) fwrite(ptr, size, count, stream)
#else
	#define mpOTHER
	#define fwrite_locknt(ptr, size, count, stream) fwrite(ptr, size, count, stream)
#endif