#ifndef _ACTIVATIONFUNCTIONS_H_
#define _ACTIVATIONFUNCTIONS_H_

#define LOGISTIC_ALPHA 1
#define TAN_ALPHA 1
#define TAN_BETA 1

#include <math.h>

//Computes value of logistic activation function.
double LogisticActivationFunction(double arg);

double FirstDerivativeOfLogActivationFunction(double arg);

//Computes value of activation function hyperbolic tan.
double HyperbolicTanActFunction(double arg);

//Computes the first derivative of activation function hyperbolic tan
double FirstDerivativeOfHyperbolicTanActivationFunction(double arg);

#endif