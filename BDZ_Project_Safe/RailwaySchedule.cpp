#include "stdafx.h"
#include "RailwaySchedule.h"

void RailwaySchedule::del() {
	for (int i = 0; i < trainCount; i++) {
		delete trains[i];
	}
	delete[] trains;
	delete[stationCount] stations;
	delete[lineCount] lines;
	trains = NULL;
	stations = NULL;
	lines = NULL;
}

void RailwaySchedule::copy(const RailwaySchedule & other) {
	trains = NULL;
	stations = NULL;
	lines = NULL;
	trainCount = 0;
	stationCount = 0;
	lineCount = 0;
	if (other.trains != NULL) {
		this->trains = new Train*[other.trainCount];
		this->trainCount = other.trainCount;
		for (int i = 0; i < trainCount; i++) {
			this->trains[i] = other.trains[i]->clone();
		}
	}
	if (other.stations != NULL) {
		this->stations = new Station[other.stationCount];
		this->stationCount = other.stationCount;
		for (int i = 0; i < stationCount; i++) {
			this->stations[i] = other.stations[i];
		}
	}
	if (other.lines != NULL) {
		this->lines = new Line[other.lineCount];
		this->lineCount = other.lineCount;
		for (int i = 0; i < lineCount; i++) {
			this->lines[i] = other.lines[i];
		}
	}

}

RailwaySchedule::RailwaySchedule() {
	trains = NULL;
	stations = NULL;
	lines = NULL;
	trainCount = 0;
	stationCount = 0;
	lineCount = 0;
}

RailwaySchedule::RailwaySchedule(const RailwaySchedule & other) {
	copy(other);
}

RailwaySchedule & RailwaySchedule::operator=(const RailwaySchedule & other) {
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

RailwaySchedule::~RailwaySchedule() {
	del();
}
