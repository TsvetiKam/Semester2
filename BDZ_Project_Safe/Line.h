#ifndef LINE_H_
#define LINE_H_
#include "Station.h"
#include "Train.h"
#include "Time.h"

class Line {
private:
	Train* train;
	Station startPoint;
	Station endPoint;
	Time departure;
	Time arrival;
	double distance;

	double calculateDistance() const;
	Time calculateArrivalTime();

public:
	Line();
	Line(Train* train, Station startPoint, Station endPoint, Time departure);

	Time getArrival() const;
	double Distance() const;

	Station getStartPoint() const;
	Station getEndPoint() const;
};


#endif