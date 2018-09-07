#ifndef WINDOWS_STOPWATCH_H
#define WINDOWS_STOPWATCH_H

//Based on code by Dr. Jim Fawcett

#ifdef linux
#elif defined _APPLE_CC_
#else

#include<Windows.h>

class WindowsStopwatch
{

public:
	WindowsStopwatch();
	void start();
	void stop();
	long gettime();

protected:
	_int64 a, b, f;
};

#endif
#endif

#pragma once
