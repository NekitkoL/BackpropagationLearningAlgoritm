#include "StopWatch.h"
#include <stdlib.h>
#include <stdio.h>
#include "SpeedTests.h"
#include "ActivationFunctions.h"
#include "Types.h"
#include "Helpers.h"



void main()
{
	NETSpeedTest(10000, 443, 5, 2000, HyperbolicTanActFunction);
	system("pause");
}