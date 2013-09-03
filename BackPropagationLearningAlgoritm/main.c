#include "StopWatch.h"
#include <stdlib.h>
#include <stdio.h>
#include "SpeedTests.h"
#include "ActivationFunctions.h"
#include "Types.h"
#include "Helpers.h"



void main()
{
	LayerSpeedTest(1000, 443, 1000, HyperbolicTanActFunction);
	system("pause");
}