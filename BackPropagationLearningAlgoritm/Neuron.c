#include "Neuron.h"
#include "Helpers.h"
#include "Types.h"

Neuron* CreateNeuron(uint inputDimension, ActivationFunctionPtr actFunction)
{
	Neuron* newNeuron = ALLOC_OBJ(Neuron);
	uint i;

	newNeuron->actFunction = actFunction;
	newNeuron->InputDimension = inputDimension;
	newNeuron->LastOutput = 0;
	newNeuron->LastSumValue = 0;
	newNeuron->LastLocalGradValue = 0;
	newNeuron->Bias = NEXT_DOUBLE();

	newNeuron->Weights = ALLOC_ARRAY(double, inputDimension);
	for(i = 0; i < inputDimension; i++)
	{
		newNeuron->Weights[i] = NEXT_DOUBLE();
	}

	return newNeuron;
}


void Adder(Neuron* neuron, double* inputVector)
{
	uint i;

	neuron->LastSumValue = 0;
	for(i = 0; i < neuron->InputDimension; i++)
	{
		neuron->LastSumValue += inputVector[i] * neuron->Weights[i];
	}
	neuron->LastSumValue += neuron->Bias;
}


double ComputeNeuronOutput(Neuron* neuron, double* inputVector)
{
	Adder(neuron, inputVector);
	neuron->LastOutput = neuron->actFunction(neuron->LastSumValue);
	return neuron->LastOutput;
}


void DisposeNeuron(Neuron* neuron)
{
	free(neuron->Weights);
	free(neuron);
}