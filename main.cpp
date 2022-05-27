//TODO: Make a basic Neural Network for XOR 
// Add Forward Propogation 
// Add Backward Propogation
// Gradient Decent
// input layer 2
// hidden layer 3
// output layer 1

#include<bits/stdc++.h>
#include "Matrix.hpp"
#include "ops.hpp"
#include "nn.hpp"
#include "activations.hpp"

using namespace std;

int main(){
	Matrix* inputs = createMatrix(4,2);
	Matrix* outputs = createMatrix(4,1); 
	inputs->entries[0][0] = 0;
	inputs->entries[0][1] = 0; 
	inputs->entries[1][0] = 0; 
	inputs->entries[1][1] = 1; 
	inputs->entries[2][0] = 1; 
	inputs->entries[2][1] = 0; 
	inputs->entries[3][0] = 1; 
	inputs->entries[3][1] = 1;

	outputs->entries[0][0] = 0;
	outputs->entries[1][0] = 1; 
	outputs->entries[2][0] = 1; 
	outputs->entries[3][0] = 0; 

	NN* network= createNetwork(2, 3, 1, 0.4);
	cout<<"training starting"<<endl;
	for(int j = 0; j<100; j++){
		for(int i = 0; i<inputs->rows; i++){
			Matrix* m = createMatrix(2,1);
			m->entries[0][0] = inputs->entries[i][0];
			m->entries[0][1] = inputs->entries[i][1];
			Matrix* o = createMatrix(1,1);
			o->entries[0][0] = outputs->entries[i][0];
			networkTrain(network, m, o);
		}
	}
	
	for(int i = 0; i<inputs->rows; i++){
		Matrix* test = createMatrix(2,1);
		test->entries[0][0] = inputs->entries[i][0];
		test->entries[1][0] = inputs->entries[i][1];
		Matrix* predict = networkPredict(network, test);
		matrixPrint(predict);
		matrixFree(test);
	}	
}

