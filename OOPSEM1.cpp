#include "stdafx.h"
#include <iostream>

using namespace std;

int** createMatrix(int n, int m) {
	int** matrix = new int*[n];

	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}
	return matrix;

}

void fillMatrix(int** matrix, int n, int m) {
	int *a = new int;
	*a = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = *a;
			*a= *a + 1;
		}
	}
	delete a;
}

int** transpMatrix(int **matrix, int n, int m) {
	int** temp = createMatrix(m, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[j][i] = matrix[i][j];
		}
	}

	return temp;

}

void deleteMatrix(int **matrix, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void printMatrix(int **matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{ 
	int* pRows = new int;
	int* pCol = new int;
	cin >> *pRows >> *pCol;

	int ** matrix = createMatrix(*pRows, *pCol);
	fillMatrix(matrix, *pRows, *pCol);

	int** pMatrix = matrix;

	matrix = transpMatrix(matrix, *pRows, *pCol);

	printMatrix(pMatrix, *pRows, *pCol);
	cout << endl;
	deleteMatrix(pMatrix, *pRows);

	printMatrix(matrix, *pCol, *pRows);

	deleteMatrix(matrix, *pCol);

	delete pRows;
	delete pCol;

    return 0;
}

