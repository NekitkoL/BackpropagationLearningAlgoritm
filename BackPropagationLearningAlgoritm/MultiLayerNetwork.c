#include "Layer.h"
#include "MultiLayerNetwork.h"
#include "Helpers.h"
#include "Types.h"

int CheckParams(ActivationFunctionPtr actFunction, uint layerCount, uint inputDimension, uint* layersParams)
{
	uint i;

	if(actFunction == NULL)
		return 1;
	if(layerCount < 0)
		return 1;
	if(inputDimension < 0)
		return 1;

	for(i = 0; i < layerCount; i++)
		if(layersParams[i] < 0)
			return 1;

	return 0;
}


MultiLayerNetwork* CreateNetwork(ActivationFunctionPtr actFunction,
								 uint layerCount,
								 uint inputDimension,
								 uint* layersParams
								 )
{
	MultiLayerNetwork* network = NULL;
	uint i;

	if(!CheckParams(actFunction, layerCount, inputDimension, layersParams))
	{
		network->inputDimension = inputDimension;
		network->LayersCount = layerCount;
		network->OutputDimension = layersParams[layerCount - 1];

		network->LastOutput = ALLOC_ARRAY(double, network->OutputDimension);
		network->Layers = ALLOC_ARRAY(Layer*, layerCount);

		network->Layers[0] = CreateLayer(layersParams[0], actFunction, network->inputDimension);
		for(i = 1; i <  network->LayersCount; i++)
		{
			network->Layers[i] = CreateLayer(layersParams[i], actFunction, network->Layers[i-1]->NeuronsCount);
		}
	}

	return network;
}


int DisposeNetwork(MultiLayerNetwork* network) 
{
	uint i;

	if(network == NULL)
		return -1;
	else 
	{
		for(i = 0; i < network->LayersCount; i++)
		{
			DisposeLayer(network->Layers[i]);
		}

		free(network->LastOutput);
		free(network);

		return 0;
	}
}


int ComputeNetworkOutput(MultiLayerNetwork* network, double* inputVector, uint inputVectorLength)
{
	uint i;

	if(network == NULL)
		return -1;
	if(inputVector == NULL)
		return -1;
	if(inputVectorLength != network->inputDimension)
		return -1;

	ComputeLayerOutput(network->Layers[0], inputVector);
	for(i = 1; i < network->LayersCount; i++)
	{
		ComputeLayerOutput(network->Layers[i], network->Layers[i-1]->LastOutput);
	}

	for(i = 0; i < network->OutputDimension; i++)
	{
		network->LastOutput[i] = network->Layers[network->LayersCount-1]->LastOutput[i];
	}

	return 0;
}