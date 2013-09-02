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