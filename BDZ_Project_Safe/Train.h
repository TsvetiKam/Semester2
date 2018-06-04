#ifndef TRAIN_H_
#define TRAIN_H_
#include "Queue.h"
#include "Station.h"
#include <iostream>

class Station;

class Train {
private:

	unsigned int* wagonPlaces;
	unsigned int wagonsCount;
	unsigned int speed;
	Queue<Station> route;
	void erase();
	void copy(const Train& other);
	virtual void print(std::ostream& out) const;
	virtual void read(std::istream& in);

public:

	Train();
	Train(const unsigned int* wagonPlaces, unsigned int wagonsCount, unsigned int speed);
	Train(const Train& other);
	Train& operator=(const Train& other);
	virtual ~Train();

	virtual Train* clone() const;

	Queue<Station> getRoute() const;
	int getSpeed() const;

	void addStation(const Station& s);

	friend std::ostream& operator<<(std::ostream& out, Train& train); // * полиморфизъм
	friend std::istream& operator>>(std::istream& in, Train& train);
};

#endif