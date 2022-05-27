#include "nn.hpp"
#include <bits/stdc++.h>

#define MAXCHAR  1000

NN* createNetwork(int input, int hidden, double learningRate){
	NN* net = (NN*) malloc(sizeof(NeuralNetwork));
	net->input = input;
	net->hidden = hidden;
	net->output = output;
	net->learningRate = learningRate;
	Matrix* hidden_layer = createMatrix(hidden, input);
	Matrix* output_layer = createMatrix(output, hidden);
	matrixRandom(hidden_layer, hidden);
	matrixRandom(output_layer, output);
	net->hiddenWeights = hidden_layer;
	net->outputWeights = output_layer;
	return net;
}

void networkTrain(NN* net, Matrix* input, Matrix* output){
	Matrix* hiddenInputs = dot(net->hiddenWeights, input);
	Matrix* hiddenOutputs = apply(sigmoid, hiddenInputs);
	Matrix* outputInputs = dot(net->outputWeights,hiddenOutputs);
	Matrix outputOutputs = apply(sigmoid, outputInputs);
	Matrix* outputErrors = subtract(output, outputOutputs);
	Matrix* hiddenErrors = dot(transpose(net->outputWeights), outputErrors);

	
}