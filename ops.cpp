#include "ops.hpp"
#include "Matrix.hpp"
#include<math.h>
#include<vector>
#include<iostream>

using namespace std;

int checkDimensions(Matrix* m1, Matrix* m2){
	if(m1->rows == m2->rows && m1->columns == m2->columns)
		return 1;
	else return 0;
}

Matrix* multiply(Matrix* m1, Matrix* m2){

	if(checkDimensions(m1, m2)){
		Matrix* m = createMatrix(m1->rows, m1->columns);
		for(int i = 0; i < m1->rows; i++){
			for(int j = 0; j < m2->columns; j++){
				m->entries[i][j] = m1->entries[i][j]*m2->entries[i][j];
			}
		}
		
		return m;
	}
	else{
		cout<<"Dimension mismatch multiply "<<m1->rows<<" "<<m1->columns<<" "<<m2->rows<<" "<<m2->columns<<endl;
		exit(1);
	}
}

Matrix* add(Matrix* m1, Matrix* m2){
	if(checkDimensions(m1, m2)){
		Matrix* m = createMatrix(m1->rows, m1->columns);
		for(int i = 0; i < m1->rows; i++){
			for(int j = 0; j < m2->columns; j++){
				m->entries[i][j] = m1->entries[i][j]+m2->entries[i][j];
			}
		}
		
		return m;
	}
	else{
		cout<<"Dimension mismatch add "<<m1->rows<<" "<<m1->columns<<" "<<m2->rows<<" "<<m2->columns<<endl;
		exit(1);
	}
}

Matrix* subtract(Matrix* m1, Matrix* m2){
	if(checkDimensions(m1, m2)){
		Matrix* m = createMatrix(m1->rows, m1->columns);
		for(int i = 0; i < m1->rows; i++){
			for(int j = 0; j < m2->columns; j++){
				m->entries[i][j] = m1->entries[i][j]-m2->entries[i][j];
			}
		}
		
		return m;
	}
	else{
		cout<<"Dimension mismatch subtract "<<m1->rows<<" "<<m1->columns<<" "<<m2->rows<<" "<<m2->columns<<endl;
		exit(1);
	}
}

Matrix* dot(Matrix* m1, Matrix* m2){
	
	if(m1->columns == m2->rows){
		Matrix* m = createMatrix(m1->rows, m2->columns);
		for (int i = 0; i < m1->rows; i++) {
			for (int j = 0; j < m2->columns; j++) {
				double sum = 0;
				for (int k = 0; k < m2->rows; k++) {
					sum += m1->entries[i][k] * m2->entries[k][j];
				}
				m->entries[i][j] = sum;
			}
		}
		return m;
	}

	else{
		cout<<"Dimension mismatch dot "<<m1->rows<<" "<<m1->columns<<" "<<m2->rows<<" "<<m2->columns<<endl;
		exit(1);
	}
}


Matrix* scale(double n , Matrix* m){
	Matrix* mat = copyMatrix(m);
	for(int i = 0; i<mat->rows; i++){
		for(int j = 0; j<mat->columns; j++){
			mat->entries[i][j] *= n;
		}
	}

	return mat;
}

Matrix* addScalar(double n , Matrix* m){
	Matrix* mat = copyMatrix(m);
	for(int i = 0; i<mat->rows; i++){
		for(int j = 0; j<mat->columns; j++){
			mat->entries[i][j] += n;
		}
	}

	return mat;
}

Matrix* transpose(Matrix* m) {
	Matrix* mat = createMatrix(m->columns, m->rows);
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->columns; j++) {
			mat->entries[j][i] = m->entries[i][j];
		}
	}
	return mat;
}

Matrix* apply(double (*func)(double), Matrix* m){

	Matrix* mat = copyMatrix(m);
	for(int i = 0; i<m->rows; i++){
		for(int j = 0; j<m->columns; j++){
			mat->entries[i][j] = (*func)(m->entries[i][j]);
		}
	}

	return mat;
}