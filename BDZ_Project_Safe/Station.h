#ifndef STATION_H_
#define STATION_H_
#include "Train.h"
#include "Point.h"
#include <iostream>

class Train;

class Station {
private:
	char* name;
	Point coordinates;
	Train** trains;
	int trainCount;
	int priority;

	void del();
	void copy(const Station& other);
	
public:
	Station();
	Station(const char* name, Point coordinates, int priority);
	Station(const Station& other);
	Station& operator=(const Station& other);
	~Station();

	void addTrain(Train* train);
	void removeTrain(Train* train);

	int getPriority() const;
	const char* getName() const;
	Point getCoordinates() const;

	bool operator==(const Station& other) const;

	friend std::istream& operator>>(std::istream& is, Station& station) ;
	friend std::ostream& operator<<(std::ostream& os, const Station& station);

};

#endif