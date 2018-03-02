#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int ** CreateMatrix(int n) {
	int ** matrix = new int *[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[4];
	}
	return matrix;
}
void Print(int **matrix, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Plan " << i + 1 << ": ";
		for (int j = 0; j < 4; j++) {
			cout << setw(5) << matrix[i][j] << " " ;
		}
		cout << endl;
	}
}
void Fill(int **matrix, int n) {
	int price, minutes, mb, sms;

	cout << "/price / minutes / mb / sms /" << endl;

	for (int i = 0; i < n; i++) {
		cout << "Plan " << i + 1 << ": ";

		cin >> price >> minutes >> mb >> sms;

		matrix[i][0] = price;
		matrix[i][1] = minutes;
		matrix[i][2] = mb;
		matrix[i][3] = sms;
	}
}
int ** Filter(int ** matrix, int n, int minutes, int mb, int sms, int &size) {

	int good = 0;

	for (int i = 0; i < n; i++) {
		if (matrix[i][1] >= minutes && matrix[i][2] >= mb && matrix[i][3] >= sms) {
			good++;
		}
	}

	size = good;

	int ** filteredMatrix = CreateMatrix(good);

	int index = 0;

	for (int i = 0; i < n; i++) {
		if (matrix[i][1] >= minutes && matrix[i][2] >= mb && matrix[i][3] >= sms) {
			filteredMatrix[index][0] = matrix[i][0];
			filteredMatrix[index][1] = matrix[i][1];
			filteredMatrix[index][2] = matrix[i][2];
			filteredMatrix[index][3] = matrix[i][3];
			index++;
		}
	}
	
	return filteredMatrix;
}
void Sort(int ** matrix, int n) {

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (matrix[j][0] > matrix[j + 1][0]) {
				int *temp = matrix[j];
				matrix[j] = matrix[j + 1];
				matrix[j + 1] = temp;
			}
		}
	}

}
void Delete(int **matrix, int n) {

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete matrix;

}

int main()
{
	int *plansCount = new int;
	cout << "Number of plans: ";
	cin >> *plansCount;
	cout << endl;

	int ** plans = CreateMatrix(*plansCount);
	Fill(plans, *plansCount);

	cout << endl << "All plans:" << endl;
	Print(plans, *plansCount);
	cout << endl;

	int minutes, mb, sms;

	cout << "Your requirements:" << endl << "/ minutes / mb / sms /: " << endl;
	cin >> minutes >> mb >> sms;

	int size = 0;

	int ** goodPlans = Filter(plans, *plansCount, minutes, mb, sms, size);

	Delete(plans, *plansCount);

	Sort(goodPlans, size);
	cout << "Suitable plans:" << endl;
	Print(goodPlans, size);

	Delete(goodPlans, size);

    return 0;
}

