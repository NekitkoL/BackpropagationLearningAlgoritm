#include "Helpers.h"
#include "Types.h"
#include "Neuron.h"
#include "StopWatch.h"
#include <stdio.h>

void NeuronSpeedTest(uint iterations, uint inputLength, ActivationFunctionPtr actFunction)
{
	Neuron* neuron;
	uint i;
	double* inputVector;
	StopWatch stopWatch;
	TimeInterval timeInterval;

	inputVector = ALLOC_ARRAY(double, inputLength);
	for(i = 0; i < inputLength; i++)
	{
		inputVector[i] = i;
	}

	neuron = CreateNeuron(inputLength, actFunction);

	Reset(&stopWatch);
	Start(&stopWatch);

	for(i = 0; i < iterations; i++)
	{
		ComputeNeuronOutput(neuron, inputVector);
	}

	Stop(&stopWatch);

	ToTimeIntervalStruct(&stopWatch, &timeInterval);

	printf("Milliseconds: %d\n", timeInterval.Miliseconds);
	printf("Seconds: %d\n", timeInterval.Seconds);
	printf("Minets: %d\n", timeInterval.Minets);
	printf("Hours: %d\n", timeInterval.Hours);

}