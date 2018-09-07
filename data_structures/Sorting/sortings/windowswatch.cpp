#include"windowswatch.h"
#include<exception>

#ifdef linux
#elif defined _APPLE_CC_
#else

WindowsStopwatch::WindowsStopwatch()
{
	b = 0Ul;
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&f) == 0)
		throw std::exception("no high resolution counter on this platform");
	QueryPerformanceCounter((LARGE_INTEGER*)&a);
}

void WindowsStopwatch::start()
{
	::Sleep(0);
	QueryPerformanceCounter((LARGE_INTEGER*)&a);
}

void WindowsStopwatch::stop()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&b);
}

long WindowsStopwatch::gettime()
{
	_int64 d = (b - a);
	_int64 ret_milliseconds;
	ret_milliseconds = (d * 1000UL) / f;
	return ret_milliseconds;
}

#endif