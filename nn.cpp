#include "nn.hpp"
#include "Matrix.hpp"
#include "activations.hpp"
#include "ops.hpp"
#include <bits/stdc++.h>

#define MAXCHAR  1000

NN* createNetwork(int input, int hidden, int output, double learningRate, int bias){
	NN* net = (NN*) malloc(sizeof(NN*)+100);
	

	net->bias = bias;
	net->input = input+bias;
	net->hidden = hidden;
	net->output = output;
	net->learningRate = learningRate;
	Matrix* hidden_layer = createMatrix(hidden, input+bias);
	Matrix* output_layer = createMatrix(output, hidden);
	matrixRandom(hidden_layer, hidden);
	matrixRandom(output_layer, output);
	net->hiddenWeights = hidden_layer;
	net->outputWeights = output_layer;
	return net;

	
}
void networkTrain(NN* net, Matrix* input, Matrix* output){

	Matrix* x;
	if(net->bias){
		x = createMatrix(input->rows+net->bias, input->columns);
		for(int i = 0; i < input->rows; i++){
			x->entries[i][0] = input->entries[i][0];
		}
		x->entries[input->rows][0] = 1;
		
	}
	else{
		x = input;
	}
	//forward propogation
	Matrix* hiddenInputs = dot(net->hiddenWeights, x);
	Matrix* hiddenOutputs = apply(sigmoid, hiddenInputs);
	Matrix* outputInputs = dot(net->outputWeights,hiddenOutputs);
	Matrix* outputOutputs = apply(sigmoid, outputInputs);

	//Errors 
	Matrix* outputErrors = subtract(output, outputOutputs);
	Matrix* hiddenErrors = dot(transpose(net->outputWeights), outputErrors);

	//Backpropagation output layer
	Matrix* sigmoidprimemat = sigmoidPrime(outputOutputs);
	Matrix* mul = multiply(outputErrors, sigmoidprimemat);
	Matrix* transed = transpose(hiddenOutputs);
	Matrix* dotmat = dot(mul, transed);
	Matrix* scaledMat = scale(net->learningRate, dotmat);
	Matrix* addedMat = add(net->outputWeights, scaledMat);
	
	matrixFree(net->outputWeights);
	net->outputWeights = addedMat;
	
	matrixFree(sigmoidprimemat);
	matrixFree(mul);
	matrixFree(transed);
	matrixFree(dotmat);
	matrixFree(scaledMat);


	//backpropagation hidden layer with
	sigmoidprimemat = sigmoidPrime(hiddenOutputs);
	mul = multiply(hiddenErrors, sigmoidprimemat);
	transed = transpose(x);
	dotmat = dot(mul, transed);
	scaledMat = scale(net->learningRate, dotmat);
	addedMat = add(net->hiddenWeights, scaledMat);

	
	matrixFree(net->hiddenWeights);
	net->hiddenWeights = addedMat;

	matrixFree(sigmoidprimemat);
	matrixFree(mul);
	matrixFree(transed);
	matrixFree(dotmat);
	matrixFree(scaledMat);

	//Free up all the temporary Matrises 
	matrixFree(hiddenInputs);
	matrixFree(hiddenOutputs);
	matrixFree(hiddenErrors);
	matrixFree(outputInputs);
	matrixFree(outputOutputs);
	matrixFree(outputErrors);
}


Matrix* networkPredict(NN* net, Matrix* input){
	Matrix* x;
	if(net->bias){
		x = createMatrix(input->rows+net->bias, input->columns);
		for(int i = 0; i < input->rows; i++){
			x->entries[i][0] = input->entries[i][0];
		}
		x->entries[input->rows][0] = 1;
		
	}
	else{
		x = input;
	}
	Matrix* hiddenInputs = dot(net->hiddenWeights, x);
	Matrix* hiddenOutputs = apply(sigmoid, hiddenInputs);
	Matrix* outputInputs = dot(net->outputWeights,hiddenOutputs);
	Matrix* outputOutputs = apply(sigmoid, outputInputs);
	return outputOutputs;
}	

