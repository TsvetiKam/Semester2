#ifndef TRAIN_H_
#define TRAIN_H_
#include "Queue.h"
#include "Station.h"

class Station;

class Train {
private:

	unsigned int* wagonPlaces;
	unsigned int wagonsCount;
	unsigned int speed;
	Queue<Station> route;
	void erase();
	void copy(const Train& other);
public:

	Train();
	Train(const unsigned int* wagonPlaces, unsigned int wagonsCount, unsigned int speed);
	Train(const Train& other);
	Train& operator=(const Train& other);
	~Train();

	Queue<Station> getRoute() const;
	int getSpeed() const;

	void addStation(const Station& s);
};

#endif