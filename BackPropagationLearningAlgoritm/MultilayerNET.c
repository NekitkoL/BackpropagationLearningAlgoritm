#include "MultilayerNET.h"
#include "Layer.h"
#include "Types.h"
#include "Helpers.h"

int CheckParams(uint LayersCount, uint InputDimension, ActivationFunctionPtr actFunction, uint* layersParams)
{
	if(LayersCount <= 0)
		return 1;
	if(InputDimension <= 0)
		return 1;
	if(actFunction == NULL)
		return 1;
	if(layersParams == NULL)
		return 1;
	else 
		return 0;
}


MultilayerNET* CreateNewMultilayerNET(uint layersCount, uint inputDimension, ActivationFunctionPtr actFunction, uint* layersParams)
{
	uint i;
	MultilayerNET* newNET;

	if(!CheckParams(layersCount, inputDimension, actFunction, layersParams))
	{
		newNET = ALLOC_OBJ(MultilayerNET);

		newNET->InputDimension = inputDimension;
		newNET->LayersCount = layersCount;
		newNET->OutputDimension = layersParams[layersCount-1];
		newNET->Layers = ALLOC_ARRAY(Layer*, layersCount);

		newNET->Layers[0] = CreateLayer(layersParams[0], actFunction, inputDimension);
		for(i = 1; i < newNET->LayersCount; i++)
		{
			newNET->Layers[i] = CreateLayer(layersParams[i], actFunction, newNET->Layers[i-1]->NeuronsCount);
		}
		newNET->LastOutput = newNET->Layers[newNET->LayersCount-1]->LastOutput; // output of NET is output of her last layer

		return newNET;
	}
	else 
		return NULL;
}


int ComputeNETOutput(MultilayerNET* multilayerNET, double* inputVector, uint inputVectorLength)
{
	uint i;

	if(multilayerNET == NULL)
		return 1;
	if(inputVector == NULL)
		return 1;
	if(inputVectorLength != multilayerNET->InputDimension)
		return 1;

	ComputeLayerOutput(multilayerNET->Layers[0], inputVector);
	for(i = 1; i < multilayerNET->LayersCount; i++)
	{
		ComputeLayerOutput(multilayerNET->Layers[i], multilayerNET->Layers[i-1]->LastOutput); 
	}

	return 0;
}


int DisposeNET(MultilayerNET* multilayerNET)
{
	uint i;

	if(multilayerNET != NULL)
	{
		for(i = 0; i < multilayerNET->LayersCount; i++)
		{
			DisposeLayer(multilayerNET->Layers[i]);
		}
		free(multilayerNET->Layers);
		free(multilayerNET);

		return 0;
	} 
	else 
		return 1;
}
