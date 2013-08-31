#ifndef _STOPWATCH_H_
#define _STOPWATCH_H_

#include "Types.h"

typedef struct _stopWatch 
{
	uint64 BeginTime;
	uint64 EndTime;
	uint64 ElapsedMilliseconds;
} StopWatch;


typedef struct _timeInterval
{
	uint64 Miliseconds;
	uint64 Seconds;
	uint64 Minets;
	uint64 Hours;
} TimeInterval;

uint64 GetTime();
void Reset(StopWatch* stopWatch);
void Start(StopWatch* stopWatch);
void Stop(StopWatch* stopWatch);
void CalcElapsedMilliSeconds(StopWatch* stopWatch);
void ToTimeIntervalStruct(StopWatch* stopWatch, TimeInterval* timeInterval);

#endif