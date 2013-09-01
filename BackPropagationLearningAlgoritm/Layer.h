#ifndef _LAYER_H_
#define _LAYER_H_

#include "Types.h"
#include "Neuron.h"
#include "Helpers.h"

typedef struct _layer 
{
	Neuron** Neurons;
	uint NeuronsCount;
	uint InputDimension;
	double* LastOutput;
} Layer;


Layer* CreateLayer(uint neuronsCount, ActivationFunctionPtr actFunction, uint inputDimension);
void ComputeLayerOutput(Layer* layer, double* inputVector);
void DisposeLayer(Layer* layer);

#endif