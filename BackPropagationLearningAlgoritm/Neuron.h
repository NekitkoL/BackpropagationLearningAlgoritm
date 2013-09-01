#ifndef _NEURON_H_
#define _NEURON_H_

#include "Helpers.h"
#include "Types.h"

typedef struct _neuron 
{
	//Weights of the neuron.
	double* Weights;

	//Offset of the neuron.
	double Bias;

	//The last calculated value of the adder of neuron.
	double LastSumValue;

	//The last calculated value of the neuron's local gradient.
	double LastLocalGradValue;

	//The last calculated value of the neuron's output.
	double LastOutput;

	//The neuron's activation function.
	ActivationFunctionPtr actFunction;

	//Dimension of input vector.
	uint InputDimension;
} Neuron;


void Adder(Neuron* neuron, double* inputVector);
double ComputeNeuronOutput(Neuron* neuron, double* inputVector);
Neuron* CreateNeuron(uint inputDimension, ActivationFunctionPtr actFunction);
void DisposeNeuron(Neuron* neuron);

#endif