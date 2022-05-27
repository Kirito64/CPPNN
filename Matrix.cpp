#include "matrix.hpp"
#include <bits/stdc++.h>
#define MAXCHAR 1000 

using namespace std;

Matrix* createMatrix(int rows, int columns){
	Matrix* matrix = (Matrix*)malloc(sizeof(Matrix*));
	std::vector<vector<double>> entries;
	matrix->rows = rows;
	matrix->columns = columns;

	for(int i = 0; i<rows; i++){
		vector<double> x(columns);
		entries.push_back(x);
	}

	matrix->entries  = entries;

	return matrix;
}

void matrixFill(Matrix* m, int n){
	for(int i = 0; i<m->rows; i++){
		for(int j = 0; j<m->columns; j++){
			m->entries[i][j] = n;
		}
	}
}

void matrixFree(Matrix* m){
	vector<vector<double> >().swap(m->entries);
	free(m);
	m = NULL;
}

void matrixPrint(Matrix* m){
	cout<<"Rows: "<<m->rows<<" Cols: "<<m->columns<<endl;
	for(int i = 0; i<m->rows; i++){
		for(int j = 0; j<m->columns; j++){
			cout<< m->entries[i][j]<< " ";
		}
		cout<< endl;
	}
}

Matrix* matrixCopy(Matrix* m){
	Matrix* copy = createMatrix(m->rows, m->columns);

	for(int i=0; i<m->rows; i++){
		for(int j= 0; j<m->columns; j++){
			copy->entries[i][j] = m->entries[i][j];
		}
	}

	return copy;
}

void matrixSave(Matrix* m, char* filename){
	FILE* f = fopen(filename, "w");
	fprintf(f, "%d\n", m->rows);
	fprintf(f, "%d\n", m->columns);

	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < m->columns; j++){
			fprintf(f, "%.6f\n", m->entries[i][j]);
		}
	}

	cout<<"Successfully saved Matrix to "<<filename<<endl;

	fclose(f);

}

Matrix* matrixLoad(char* filename){
	FILE* file = fopen(filename, "r");
	char entry[MAXCHAR];
	fgets(entry, MAXCHAR, file);
	int rows = atoi(entry);
	fgets(entry, MAXCHAR, file);
	int columns = atoi(entry);

	Matrix* m = createMatrix(rows, columns);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < columns; j++){
			fgets(entry, MAXCHAR, file);
			m->entries[i][j] = strtod(entry, NULL);

		}
	}

	cout<<"Successfully Loaded Saved Matrix"<<endl;
	fclose(file);
	return m;

}

double uniformDistribution(double low, double high){
	double diff = high - low;
	int scale = 10000;
	int scaledDiff = (int)(diff*scale);
	retun low + (1.0* (rand()%scaledDiff)/scale);
}

void matrixRandom(Matrix* m){
	double min = -1.0/sqrt(n);
	double max = 1.0/sqrt(n);

	for(int i = 0; i< m->rows; i++){
		for(int j = 0; j< m->colour; j++){
			m->entries[i][j] = uniformDistribution(min,max);
		}
	}
}

int matrixArgmax(Matrix* m){
	//expects a MX1 matrix

	double max_score = 0;
	int maxidx = 0;

	for (int i = 0; i<m->rows; i++){
		if(m->entries[i][0] > max_score){
			max_score = m->entries[i][0];
			maxidx = i;
		}
	}

	return maxidx;
} 

Matrix* matrixFlatten(Matrix* m, int axis){
	//Axis = 0-> column vector, Axis = 1 -> row vector,

	Matrix* mat;

	if(axis == 0){
		mat = createMatrix(m->rows*m->columns, 1);

	}
	else if(axis == 1){
		mat = ceateMatrix(1, m->columns*m->rows)
	}
	else{
		cout<<"Argumen to matrixFlatten invalid"<<endl;
		exit(EXIT_FAILURE);
	}

	for(int i = 0 i<m->rows; i++){
		for(int j = 0; j < m->column; j++){
			if(axis == 0)
				mat->entries[i*m->columns + j][0] = m->entries[i][j];
			else
				mat->entries[0][i*m->columns + j] = m->entries[i][j];
		}
	}

	return mat;
}


