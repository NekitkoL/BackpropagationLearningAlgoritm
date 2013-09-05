#ifndef _SPEEDTESTS_H_
#define _SPEEDTESTS_H_

#include "Types.h"
#include "Neuron.h"
#include "Layer.h"
#include "Helpers.h"

void NeuronSpeedTest(uint iterations, uint inputLength, ActivationFunctionPtr actFunction);
void LayerSpeedTest(uint iterations, uint inputLength,uint neuronsCount, ActivationFunctionPtr actFunction);
void NETSpeedTest(uint iterations, uint inputLength, uint layersCount, uint neuronsCountInEachLayer, ActivationFunctionPtr actFunction);

#endif