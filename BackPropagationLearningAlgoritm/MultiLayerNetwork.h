#ifndef _MULTILAYERNETWORK_H_
#define _MULTILAYERNETWORK_H_

#include "Types.h"
#include "Layer.h"

typedef struct _multiLayerNetwork 
{
	Layer** Layers;
	uint OutputDimension;
	uint inputDimension;
	uint LayersCount;
	double* LastOutput;
} MultiLayerNetwork;

#endif


MultiLayerNetwork* CreateNetwork(ActivationFunctionPtr actFunction,
								 uint layerCount,
								 uint inputDimension,
								 uint* layersParams
								 );

int ComputeNetworkOutput(MultiLayerNetwork* network, double* inputVector, uint inputVectorLength);
int DisposeNetwork(MultiLayerNetwork* network);
int CheckParams(ActivationFunctionPtr actFunction, uint layerCount, uint inputDimension, uint* layersParams);