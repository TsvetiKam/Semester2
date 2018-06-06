#include "stdafx.h"
#include "Train.h"
#include "Station.h"
#include <iostream>
#include "RailwaySchedule.h"


void Train::erase() {
	delete[] wagonPlaces;
	delete schedule;
	schedule = NULL;
	wagonPlaces = NULL;
}

void Train::copy(const Train & other) {
	this->speed = other.speed;
	this->route = other.route;
	this->wagonsCount = other.wagonsCount;
	if (other.schedule != NULL) {
		schedule = new RailwaySchedule(*other.schedule);
	}
	if (other.wagonsCount > 0) {
		this->wagonPlaces = new unsigned int[wagonsCount];
		for (unsigned int i = 0; i < wagonsCount; i++) {
			this->wagonPlaces[i] = other.wagonPlaces[i];
		}
	}
	else {
		wagonPlaces = NULL;
	}
}

void Train::print(std::ostream & out) const {
	if (!route.isEmpty()) {
		out << "Train from " << route.frontData().getName() << " to " << route.backData().getName() << std::endl;
	}
	out << "Speed: " << speed << " Number of wagons: " << wagonsCount << std::endl;
	for (unsigned int i = 0; i < wagonsCount; i++) {
		out << "		Wagon " << i + 1 << " has: " << wagonPlaces[i] << " seats. " << std::endl;
	}
	out << std::endl;
}

void Train::read(std::istream& in) {
	while (!route.isEmpty()) {
		route.pop();
	}
	std::cout << "Enter train wagon count: ";
	in >> wagonsCount;
	if (wagonPlaces != NULL) {
		delete[] wagonPlaces;
	}
	wagonPlaces = new unsigned int[wagonsCount];
	for (unsigned int i = 0; i < wagonsCount; i++) {
		std::cout << "Enter wagon " << i + 1 << " seats: ";
		in >> wagonPlaces[i];
	}
	std::cout << "Enter train speed: ";
	in >> speed;
	in.ignore();
	std::cout << "Enter depature time in the format of (hh::mm::ss): ";
	char buffer[20] = "";
	in.getline(buffer, 11);
	departure = Time(buffer);
}

Train::Train() {
	wagonPlaces = NULL;
	schedule = new RailwaySchedule;
	wagonsCount = 0;
	speed = 0;
}

Train::Train(const unsigned int * wagonPlaces, unsigned int wagonsCount, double speed) : schedule(new RailwaySchedule()) {
	this->speed = speed;
	this->wagonsCount = wagonsCount;
	if (wagonsCount > 0) {
		this->wagonPlaces = new unsigned int[wagonsCount];
		for (unsigned int i = 0; i < wagonsCount; i++) {
			this->wagonPlaces[i] = wagonPlaces[i];
		}
	}
	else {
		this->wagonPlaces = NULL;
	}
}

Train::Train(const Train & other) : schedule(new RailwaySchedule()) {
	copy(other);
}

Train & Train::operator=(const Train & other) {
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

Train::~Train() {
	erase();
}

Train* Train::clone() const {
	return new Train(*this);
}

Queue<Station> Train::getRoute() const {
	return route;
}

double Train::getSpeed() const {
	return speed;
}

void Train::addStation(Station & s) {
	route.push(s);

	int stationCount = route.getSize();
	Queue<Station> tempRoute = route;
	Station s1;

	if (stationCount > 1) {
		for (int i = 0; i < stationCount - 1; i++) {
			s1 = tempRoute.frontData();
			tempRoute.pop();
			Line l(this, route.frontData(), s1, departure);
			Time t = l.getArrival();

			schedule->addLine(Line(this, s1, s, t));
		}
	}

}

void Train::printSchedule() const {
	schedule->print();
}

std::ostream & operator<<(std::ostream & out, Train& train) {
	train.print(out);
	return out;
}

std::istream & operator>>(std::istream & in, Train& train) {
	train.read(in);
	return in;
}
