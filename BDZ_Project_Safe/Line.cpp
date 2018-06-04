#include "stdafx.h"
#include "Line.h"

double Line::calculateDistance() const {
	double dist = 0;
	Queue<Station> lineRoute = train->getRoute();
	int length = lineRoute.getSize();

	for (int i = 0; i < length; i++) {
		if (!(lineRoute.frontData() == *startPoint)) {
			lineRoute.pop();
		}
		else {
			break;
		}
	}
	length = lineRoute.getSize();
	for (int i = 0; i < length - 1 && !(lineRoute.frontData() == *endPoint); i++) {
		Point A = lineRoute.frontData().getCoordinates();
		lineRoute.pop();
		Point B = lineRoute.frontData().getCoordinates();

		dist += getDistance(A, B);
	}

	return dist;
}

Time Line::calculateArrivalTime() {
	int trainSpeed = (train->getSpeed() * 1000 / 3600);
	int dist = (int)(distance * 1000);

	int duration = dist / trainSpeed;

	Time end("00::00::00");
	end.setSeconds(duration % 60);
	duration = duration / 60;
	end.SetMinutes(duration % 60);
	end.SetHour(duration / 60);

	return end;
}

Line::Line() : departure("00::00::00"), arrival("00::00::00") {
	train = NULL;
	startPoint = NULL;
	endPoint = NULL;
	distance = 0;
	
}

Line::Line(Train * train, Station * startPoint, Station * endPoint, Time departure) {
	this->train = train;
	this->startPoint = startPoint;
	this->endPoint = endPoint;
	this->distance = calculateDistance();
	this->departure = departure;
	this->arrival = calculateArrivalTime();
}

double Line::Distance() const {
	return distance;
}
