#ifndef LINE_H_
#define LINE_H_
#include "Train.h"
#include "Station.h"
#include "Time.h"

class Train;
class Station;

class Line {
private:
	Train* train;
	Station* startPoint;
	Station* endPoint;
	Time departure;
	Time arrival;
	double distance;

	double getDistance() const;

public:
	Line();
	Line(Train* train, Station *startPoint, Station *endPoint, Time departure);
};


#endif