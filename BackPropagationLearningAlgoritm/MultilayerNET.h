#ifndef _MULTILAYERNET_H_
#define _MULTILAYERNET_H_

#include "Layer.h"
#include "Types.h"

typedef struct _multilayerNET 
{
	Layer** Layers;
	uint LayersCount;
	uint InputDimension;
	uint OutputDimension;
	double* LastOutput;
} MultilayerNET;

int CheckParams(uint LayersCount, uint InputDimension, ActivationFunctionPtr actFunction, uint* layersParams);
MultilayerNET* CreateNewMultilayerNET(uint layersCount, uint inputDimension, ActivationFunctionPtr actFunction, uint* layersParams);
int ComputeNETOutput(MultilayerNET* multilayerNET, double* inputVector, uint inputVectorLength);
int DisposeNET(MultilayerNET* multilayerNET);

#endif