#include "stdafx.h"
#include "Train.h"
#include "Station.h"
#include <iostream>

void Train::erase() {
	delete[] wagonPlaces;
}

void Train::copy(const Train & other) {
	this->speed = other.speed;
	this->route = other.route;
	this->wagonsCount = other.wagonsCount;
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
		out << "Wagon " << i + 1 << " has: " << wagonPlaces[i] << " seats. ";
	}
	
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
}

Train::Train() {
	wagonPlaces = NULL;
	wagonsCount = 0;
	speed = 0;
}

Train::Train(const unsigned int * wagonPlaces, unsigned int wagonsCount, unsigned int speed) {
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

Train::Train(const Train & other) {
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

int Train::getSpeed() const {
	return speed;
}

void Train::addStation(const Station & s) {
	route.push(s);
}

std::ostream & operator<<(std::ostream & out, Train& train) {
	train.print(out);
	return out;
}

std::istream & operator>>(std::istream & in, Train& train) {
	train.read(in);
	return in;
}
