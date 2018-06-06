#include "stdafx.h"
#include "DirectTrain.h"

void DirectTrain::print(std::ostream & out) const {
	Train::print(out);
	out << "		Priority: " << priority << std::endl;
}

void DirectTrain::read(std::istream & in) {
	Train::read(in);
	std::cout << "Enter priority: ";
	in >> priority;

	while (priority < 1 || priority > 10) {
		std::cout << "Priority must be between 1 and 10: ";
		in >> priority;
	}
	in.ignore();

}

DirectTrain::DirectTrain() : Train() {
	priority = 1;
}

DirectTrain::DirectTrain(const unsigned int * wagonPlaces, unsigned int wagonsCount, double speed, int priority) : 
						Train(wagonPlaces, wagonsCount, speed)
{
	if (priority >= 1 && priority <= 10) {
		this->priority = priority;
	}
	else {
		std::cout << "Invalid priority." << std::endl;
		this->priority = 1;
	}
}

Train * DirectTrain::clone() const {
	return new DirectTrain(*this);
}

void DirectTrain::addStation(const Station & s) {
	if (priority <= s.getPriority()) {
		Train::addStation(s);
	}
	else {
		std::cout << "This train won't stop at station " << s.getName() << std::endl;
	}
}

std::ostream & operator<<(std::ostream & out, DirectTrain & train) {
	train.print(out);
	return out;
}

std::istream & operator>>(std::istream & in, DirectTrain & train) {
	train.read(in);
	return in;
}
