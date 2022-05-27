// Basic library for linear algebra
#include <vector>
#pragma once

typedef struct {
	std::vector<std::vector<double>> entries;
	int rows;
	int columns;
}Matrix; 

Matrix* createMatrix(int rows, int columns);
void matrixFill(Matrix* m, int n);
void matrixFree(Matrix* m);
void matrixPrint(Matrix* m);
Matrix* copy(Matrix* m);
void matrixSave(Matrix* m, char* file_string);
Matrix* matrixLoad(char* file_string);
void matrixRandom(Matrix* m, int n);
int matrixArgmax(Matrix* m);
Matrix* matrixFlatten(Matrix* m, int axis);



