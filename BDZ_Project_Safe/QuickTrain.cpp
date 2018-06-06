#include "stdafx.h"
#include "QuickTrain.h"

void QuickTrain::print(std::ostream & out) const {
	Train::print(out);
	if (coefficient > 1) {
		out << "		This train is " << coefficient << " times faster than normal trains." << std::endl;
	}
	else {
		out << "		This train isn't faster than normal trains." << std::endl;
	}
}

void QuickTrain::read(std::istream & in) {
	Train::read(in);
	std::cout << "Enter coefficient: ";
	in >> coefficient;
	while (coefficient < 1 || coefficient > 3) {
		std::cout << "Coefficient must be between 1 and 3: ";
		in >> coefficient;
	}
	in.ignore();
	speed *= coefficient;
}

QuickTrain::QuickTrain() : Train() {
	coefficient = 1;
}

QuickTrain::QuickTrain(const unsigned int * wagonPlaces, unsigned int wagonsCount, double speed, double coefficient)
						: Train(wagonPlaces, wagonsCount, speed) 
{
	if (coefficient >= 1 && coefficient <= 3) {
		this->speed = speed * coefficient;
		this->coefficient = coefficient;
	}
	else {
		std::cout << coefficient << " is invalid coefficient." << std::endl;
		this->coefficient = 1;
	}
}

Train * QuickTrain::clone() const {
	return new QuickTrain(*this);
}

std::ostream & operator<<(std::ostream & out, QuickTrain & train) {
	train.print(out);
	return out;
}

std::istream & operator>>(std::istream & in, QuickTrain & train) {
	train.read(in);
	return in;
}
