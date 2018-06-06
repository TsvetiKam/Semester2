#ifndef DIRECT_TRAIN_H_
#define DIRECT_TRAIN_H_
#include "Train.h"

class DirectTrain : virtual public Train {
protected:
	int priority;

	virtual void print(std::ostream& out) const;
	virtual void read(std::istream& in);
public:
	DirectTrain();
	DirectTrain(const unsigned int* wagonPlaces, unsigned int wagonsCount, double speed, int priority);

	virtual Train* clone() const;

	virtual void addStation(Station& s);

	friend std::ostream& operator<<(std::ostream& out, DirectTrain& train); // * полиморфизъм
	friend std::istream& operator>>(std::istream& in, DirectTrain& train);
};

#endif