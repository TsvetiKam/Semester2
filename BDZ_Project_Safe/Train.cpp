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

Queue<Station> Train::getRoute() const {
	return route;
}

int Train::getSpeed() const {
	return speed;
}

void Train::addStation(const Station & s) {
	route.push(s);
}
