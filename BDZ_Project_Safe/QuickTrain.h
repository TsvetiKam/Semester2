#ifndef QUICK_TRAIN_H_
#define QUICK_TRAIN_H_
#include "Train.h"

class QuickTrain : virtual public Train{
protected:
	double coefficient;

	virtual void print(std::ostream& out) const;
	virtual void read(std::istream& in);

public:

	QuickTrain();
	QuickTrain(const unsigned int * wagonPlaces, unsigned int wagonsCount, double speed, double coefficient);

	virtual Train* clone() const;

	friend std::ostream& operator<<(std::ostream& out, QuickTrain& train); // * полиморфизъм
	friend std::istream& operator>>(std::istream& in, QuickTrain& train);
};


#endif