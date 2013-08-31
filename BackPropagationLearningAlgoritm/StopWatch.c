#include "StopWatch.h"
#include "Types.h"
#include <math.h>
#include <Windows.h>

uint64 GetTime()
{
	LARGE_INTEGER frequency, ticks;
	double timeInSeconds;
	uint64 timeInMilliseconds;

	QueryPerformanceCounter(&ticks);
	QueryPerformanceFrequency(&frequency);

	//Got the time in seconds
	timeInSeconds = (double)ticks.QuadPart / (double)frequency.QuadPart;

	//And moved to milliseconds
	timeInMilliseconds = ((uint64)(floor(timeInSeconds * 1000)));
	
	return timeInMilliseconds;
}


void Reset(StopWatch* stopWatch)
{
	stopWatch->BeginTime = 0;
	stopWatch->EndTime = 0;
	stopWatch->ElapsedMilliseconds = 0;
}


void Start(StopWatch* stopWatch)
{
	stopWatch->BeginTime = GetTime();
}


void Stop(StopWatch* stopWatch)
{
	stopWatch->EndTime = GetTime();
}


void CalcElapsedMilliSeconds(StopWatch* stopWatch)
{
	stopWatch->ElapsedMilliseconds = stopWatch->EndTime - stopWatch->BeginTime;
}


void ToTimeIntervalStruct(StopWatch* stopWatch, TimeInterval* timeInterval)
{
	uint64 milliseconds = stopWatch->ElapsedMilliseconds;

	timeInterval->Hours = milliseconds / 3600000;
	milliseconds %= 3600000;
	timeInterval->Minets = milliseconds / 60000;
	milliseconds %= 60000;
	timeInterval->Seconds = milliseconds / 1000;
	timeInterval->Miliseconds = milliseconds % 1000;
}