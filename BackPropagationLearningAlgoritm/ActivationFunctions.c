#include "ActivationFunctions.h"

double LogisticActivationFunction(double arg)
{
	return 1 / (1 + exp( - LOGISTIC_ALPHA * arg));
}


double FirstDerivativeOfLogActivationFunction(double arg)
{
	double fValue = LogisticActivationFunction(arg);
	return LOGISTIC_ALPHA * fValue * (1 - fValue);
}


//Computes value of activation function hyperbolic tan.
double HyperbolicTanActFunction(double arg)
{
	return TAN_ALPHA * tanh(arg * TAN_BETA);
}


//Computes the first derivative of activation function hyperbolic tan
double FirstDerivativeOfHyperbolicTanActivationFunction(double arg)
{
	double fValue = HyperbolicTanActFunction(arg);
	return (TAN_BETA * (TAN_ALPHA - fValue) * (TAN_ALPHA + fValue))/TAN_ALPHA;
}