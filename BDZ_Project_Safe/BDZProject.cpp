#include "stdafx.h"
#include <iostream>
#include "Queue.h"
#include "Train.h"
#include "Station.h"
#include "Line.h"
#include "QuickTrain.h"
#include "DirectTrain.h"
#include "ExpressTrain.h"
#include "RailwaySchedule.h"

int main() {
	
	Point A(23.564, 45.678);
	Point B(24.344, 45.789);
	Point C(23.543, 45.634);
	Point D(23.421, 46.522);
	Point E(23.999, 46.001);
	/*
	Point F;
	std::cin >> F;
	std::cout << F;

	Station a("a", A, 10);
	Station b("b", B, 1);
	Station c("c", C, 3);
	Station d("d", D, 7);
	Station e("e", E, 6);

	Station f;
	std::cin >> f;
	unsigned int arr[5];
	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 10;
	arr[4] = 10;

	Train train(arr, 5, 100);
	Train t(arr, 5, 200);
	QuickTrain q(arr, 5, 200, 1.5);
	DirectTrain g(arr, 5, 140, 3);

	f.addTrain(&train);
	f.addTrain(&t);
	f.addTrain(&q);
	f.addTrain(&g);
	std::cout << f;

	train.addStation(a);
	train.addStation(b);
	train.addStation(c);
	train.addStation(d);
	train.addStation(e);
	
	Line line(&train, &a, &e, "00::00::00");

	std::cout << line.Distance() << std::endl;
	*/


	Train t;
	std::cin >> t;
	Station s1("Plovdiv", A, 8);
	Station s2("Stara Zagora", B, 8);
	Station s3("Yambol", C, 10);
	Station s4("Burgas", D, 9);
	Station s5("Varna", E, 10);
	t.addStation(s1);
	t.addStation(s2);
	t.addStation(s3);
	t.addStation(s4);
	t.addStation(s5);

	Line l(&t, s1, s2, Time("12::00::00"));

	t.printSchedule();

	return 0;
}

