#include "stdafx.h"
#include "Queue.h"
#include <iostream>
#include "Train.h"
#include "Station.h"
#include "Line.h"
#include  "QuickTrain.h"
#include "DirectTrain.h"
#include "ExpressTrain.h"

int main() {
	
	Point A(23.564, 45.678);
	Point B(24.344, 45.789);
	Point C(23.543, 45.634);
	Point D(23.421, 46.522);
	Point E(23.999, 46.001);

	Station a("a", A, 10);
	Station b("b", B, 1);
	Station c("c", C, 3);
	Station d("d", D, 7);
	Station e("e", E, 6);

	unsigned int arr[5];

	Train train(arr, 5, 100);

	train.addStation(a);
	train.addStation(b);
	train.addStation(c);
	train.addStation(d);
	train.addStation(e);
	
	Line line(&train, &a, &e, "00::00::00");

	std::cout << line.Distance() << std::endl;

	ExpressTrain t; 
	std::cin >> t;
	t.addStation(a);
	t.addStation(b);
	t.addStation(c);
	t.addStation(d);
	t.addStation(e);
	DirectTrain r;
	std::cin >> r;
	t.addStation(a);
	t.addStation(b);
	t.addStation(c);
	t.addStation(d);
	t.addStation(e);
	QuickTrain s;
	std::cin >> s;
	t.addStation(a);
	t.addStation(b);
	t.addStation(c);
	t.addStation(d);
	t.addStation(e);


	Train* trains[4];
	trains[0] = &train;
	trains[1] = &t;
	trains[2] = &r;
	trains[3] = &s;

	for (int i = 0; i < 4; i++) {
		std::cout << *trains[i] << std::endl;
	}



	return 0;

}

