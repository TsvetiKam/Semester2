#include "stdafx.h"
#include "RailwaySchedule.h"

void RailwaySchedule::del() {
	delete[lineCount] lines;
	lines = NULL;
}

void RailwaySchedule::copy(const RailwaySchedule & other) {
	lines = NULL;
	lineCount = 0;
	if (other.lines != NULL) {
		this->lines = new Line[other.lineCount];
		this->lineCount = other.lineCount;
		for (int i = 0; i < lineCount; i++) {
			this->lines[i] = other.lines[i];
		}
	}
}

RailwaySchedule::RailwaySchedule() {
	lines = NULL;
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

void RailwaySchedule::addLine(const Line & l) {
	Line* temp = lines;
	lines = new Line[lineCount + 1];
	for (int i = 0; i < lineCount; i++) {
		lines[i] = temp[i];
	}
	lines[lineCount] = l;
	lineCount++;
	delete[] temp;
}

int RailwaySchedule::getLineCount() const {
	return lineCount;
}

void RailwaySchedule::print() const {
	for (int i = 0; i < lineCount; i++) {
		std::cout << "Line " << i + 1 << ": from " << lines[i].getStartPoint().getName() <<
			" to " << lines[i].getEndPoint().getName() << ", distance: " << lines[i].Distance() <<
			"km, arrival: " << lines[i].getArrival().getHourStr() << "::" <<
			lines[i].getArrival().getMinutesStr() << "::" << lines[i].getArrival().getSecondsStr() << std::endl;
	}
}
