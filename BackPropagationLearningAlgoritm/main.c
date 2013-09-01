#include "StopWatch.h"
#include <stdlib.h>
#include <stdio.h>
#include "SpeedTests.h"
#include "ActivationFunctions.h"

void StartTests()
{
	NeuronSpeedTest(100000, 1000, HyperbolicTanActFunction);
}

void main()
{
	StartTests();
	system("pause");
}