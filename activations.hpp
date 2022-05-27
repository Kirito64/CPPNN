#pragma once

#include "Matrix.hpp"


double sigmoid(double input);
Matrix* softmax(Matrix* m);
Matrix* sigmoidPrime(Matrix* m);


