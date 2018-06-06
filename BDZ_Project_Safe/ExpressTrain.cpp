#include "stdafx.h"
#include "ExpressTrain.h"

void ExpressTrain::print(std::ostream & out) const {
	QuickTrain::print(out);
	out << "		Priority: " << priority << std::endl;
}

void ExpressTrain::read(std::istream & in) {
	QuickTrain::read(in);
	std::cout << "Enter priority: ";
	in >> priority;

	while (priority < 1 || priority > 10) {
		std::cout << "Priority must be between 1 and 10: ";
		in >> priority;
	}
	in.ignore();
}

ExpressTrain::ExpressTrain() : Train(), QuickTrain(), DirectTrain() {
}

ExpressTrain::ExpressTrain(const unsigned int * wagonPlaces, unsigned int wagonsCount, double speed, 
						   double coefficient, int priority) : Train (wagonPlaces, wagonsCount, speed),
						   QuickTrain(wagonPlaces, wagonsCount, speed, coefficient),
						   DirectTrain(wagonPlaces, wagonsCount, speed, priority)	
{
}

Train * ExpressTrain::clone() const {
	return new ExpressTrain(*this);
}

void ExpressTrain::addStation(Station & s) {
	DirectTrain::addStation(s);
}

std::ostream & operator<<(std::ostream & out, ExpressTrain & train) {
	train.print(out);
	return out;
}

std::istream & operator>>(std::istream & in, ExpressTrain & train) {
	train.read(in);
	return in;
}
