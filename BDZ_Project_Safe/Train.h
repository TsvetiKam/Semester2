#ifndef TRAIN_H_
#define TRAIN_H_
#include "Queue.h"
#include "Station.h"
#include <iostream>
#include "Time.h"

class Line;
class RailwaySchedule;
class Station;

class Train {
private:

	void erase();
	void copy(const Train& other);

protected:

	unsigned int* wagonPlaces;
	unsigned int wagonsCount;
	double speed;
	Queue<Station> route;

	Time departure;

	RailwaySchedule* schedule;

	virtual void print(std::ostream& out) const;
	virtual void read(std::istream& in);

public:

	Train();
	Train(const unsigned int* wagonPlaces, unsigned int wagonsCount, double speed);
	Train(const Train& other);
	Train& operator=(const Train& other);
	virtual ~Train();

	virtual Train* clone() const;

	Queue<Station> getRoute() const;
	double getSpeed() const;

	virtual void addStation(Station& s);

	void printSchedule() const;

	friend std::ostream& operator<<(std::ostream& out, Train& train); // * полиморфизъм
	friend std::istream& operator>>(std::istream& in, Train& train);
};

#endif