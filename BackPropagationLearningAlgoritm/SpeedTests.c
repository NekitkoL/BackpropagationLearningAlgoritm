#include "Helpers.h"
#include "Types.h"
#include "Neuron.h"
#include "StopWatch.h"
#include "Layer.h"
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

	CalcElapsedMilliSeconds(&stopWatch);
	ToTimeIntervalStruct(&stopWatch, &timeInterval);

	printf("NEURON SPEED TEST:\nPARAMETRS:\n iterations: %d\n input length: %d\n", iterations, inputLength);
	printf("ELAPSED TIME:\n");
	printf(" milliseconds: %d\n", timeInterval.Miliseconds);
	printf(" seconds: %d\n", timeInterval.Seconds);
	printf(" minets: %d\n", timeInterval.Minets);
	printf(" hours: %d\n", timeInterval.Hours);
	printf("\n");

}


void LayerSpeedTest(uint iterations, uint inputLength,uint neuronsCount, ActivationFunctionPtr actFunction)
{
	Layer* layer;
	uint i;
	double* inputVector;
	StopWatch stopWatch;
	TimeInterval timeInterval;

	inputVector = ALLOC_ARRAY(double, inputLength);
	for(i = 0; i < inputLength; i++)
	{
		inputVector[i] = i;
	}

	layer = CreateLayer(neuronsCount, actFunction, inputLength);

	Reset(&stopWatch);
	Start(&stopWatch);

	for(i = 0; i < iterations; i++)
	{
		ComputeLayerOutput(layer, inputVector);
	}

	Stop(&stopWatch);
	CalcElapsedMilliSeconds(&stopWatch);
	ToTimeIntervalStruct(&stopWatch, &timeInterval);

	printf("LAYER SPEED TEST:\nPARAMETRS:\n iterations: %d\n input length: %d\n neuron's count: %d\n", iterations, inputLength, neuronsCount);
	printf("ELAPSED TIME:\n");
	printf(" milliseconds: %d\n", timeInterval.Miliseconds);
	printf(" seconds: %d\n", timeInterval.Seconds);
	printf(" minets: %d\n", timeInterval.Minets);
	printf(" hours: %d\n", timeInterval.Hours);
	printf("\n");
}