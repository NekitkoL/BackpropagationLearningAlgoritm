#include "Layer.h"
#include "Neuron.h"
#include "Types.h"
#include "Helpers.h"

Layer* CreateLayer(uint neuronsCount, ActivationFunctionPtr actFunction, uint inputDimension)
{
	Layer* newLayer = ALLOC_OBJ(Layer);
	uint i;

	newLayer->InputDimension = inputDimension;
	newLayer->NeuronsCount = neuronsCount;
	newLayer->LastOutput = ALLOC_ARRAY(double, neuronsCount);
	newLayer->Neurons = ALLOC_ARRAY(Neuron*, neuronsCount);

	for(i = 0; i < newLayer->NeuronsCount; i++)
	{
		newLayer->LastOutput[i] = 0;
		newLayer->Neurons[i] = CreateNeuron(newLayer->InputDimension, actFunction);
	}

	return newLayer;
}


void ComputeLayerOutput(Layer* layer, double* inputVector)
{
	uint i;

	for(i = 0; i < layer->NeuronsCount; i++)
	{
		layer->LastOutput[i] = ComputeNeuronOutput(layer->Neurons[i], inputVector);
	}
}


void DisposeLayer(Layer* layer)
{
	uint i;

	free(layer->LastOutput);

	for(i = 0; i < layer->NeuronsCount; i++)
	{
		DisposeNeuron(layer->Neurons[i]);
	}

	free(layer);
}