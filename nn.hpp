#pragma once

#include "Matrix.hpp"

typedef struct{
	int input;
	int hidden;
	int output;
	double learningRate;
	Matrix* hiddenWeights;
	Matrix* outputWeights;

} NeuralNetwork;

typedef NeuralNetwork NN;
NN* createNetwork(int input, int hidden, double learningRate);
void networkTrain(NN* net, Matrix* inputdata, Matrix* outputdata);
Matrix* networkPredict(NN* net, Matrix* input);
void networkSave(NN* net, char* filename);
NN* networkLoad(char* filename);