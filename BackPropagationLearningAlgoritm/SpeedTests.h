#ifndef _SPEEDTESTS_H_
#define _SPEEDTESTS_H_

#include "Helpers.h"
#include "Types.h"

void NeuronSpeedTest(uint iterations, uint inputLength, ActivationFunctionPtr actFunction);
void LayerSpeedTest(uint iterations, uint inputLength, uint neuronsCount, ActivationFunctionPtr actFunction);

#endif