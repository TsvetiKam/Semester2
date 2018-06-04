#include "stdafx.h"
#include "Station.h"
#include <cstring>
#include <iostream>

void Station::del() {
	delete[] name;
	for (int i = 0; i < trainCount; i++) {
		trains[i] = NULL;
	}
}

void Station::copy(const Station & other) {
	this->coordinates = other.coordinates;
	this->priority = other.priority;
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->trainCount = other.trainCount;
	for (int i = 0; i < trainCount; i++) {
		this->trains[i] = other.trains[i]->clone();
	}
}



Station::Station() : coordinates(0,0) {
	name = NULL;
	trains = NULL;
	priority = 1;
	trainCount = 0;
}

Station::Station(const char * name, Point coordinates, int priority) : coordinates(coordinates) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	if (priority >= 1 && priority <= 10) {
		this->priority = priority;
	}
	else {
		std::cout << "Invalid priority." << std::endl;
		this->priority = 1;
	}
	trains = NULL;
	trainCount = 0;
}

Station::Station(const Station & other) {
	copy(other);
}

Station & Station::operator=(const Station & other) {
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

Station::~Station() {
	del();
}

void Station::addTrain(Train* train) {
	Train** temp = trains;
	trains = new Train*[trainCount + 1];
	for (int i = 0; i < trainCount; i++) {
		trains[i] = temp[i];
	}
	trains[trainCount] = train;
	trainCount++;
	delete[] temp;
}

void Station::removeTrain(Train* train) {
	if (trainCount <= 0) {
		std::cout << "There are no trains on this station." << std::endl;
	}
	else {
		int index = 0;
		bool found = false;
		for (int i = 0; i < trainCount; i++) {
			if (trains[i] == train) {
				index = i;
				found = true;
				break;
			}
		}
		if (found) {
			for (int i = index; i < trainCount - 1; i++) {
				std::swap(trains[i], trains[i + 1]);
			}
			trains[trainCount - 1] = NULL;
			trainCount--;
			Train** temp = trains;
			trains = new Train*[trainCount];
			for (int i = 0; i < trainCount; i++) {
				trains[i] = temp[i];
			}
			delete[] temp;
		}
		else {
			std::cout << "No such train is found." << std::endl;
		}
	} 
}

int Station::getPriority() const {
	return priority;
}

const char * Station::getName() const {
	return name;
}

Point Station::getCoordinates() const
{
	return coordinates;
}

bool Station::operator==(const Station & other) const {
	bool result = true;
	if (!(this->coordinates == other.coordinates)) {
		result = false;
	}
	if (this->priority != other.priority) {
		result = false;
	}
	if (!(strcmp(this->name, other.name) == 0)) {
		result = false;
	}
	return result;
}




