#include "activations.hpp"
#include<math.h>
#include "ops.hpp"

double sigmoid(double input){
	return (1.0/(1 + exp(-1*input)));
}

Matrix* softmax(Matrix* m){
	double total = 0;

	for( int i =0 ; i < m->rows; i++){
		for( int j =0 ; j < m->columns; j++){
			total += exp(m->entries[i][j]);
		}
	}

	Matrix* mat = createMatrix(m->rows, m->columns);

	for( int i = 0 ; i < m->rows ; i++){
		for( int j = 0 ; j < m->columns; j++){
			mat->entries[i][j] = exp(m->entries[i][j])/total;
		}
	}

	return mat;
}

Matrix* sigmoidPrime()
