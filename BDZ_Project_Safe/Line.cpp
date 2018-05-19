#include "stdafx.h"
#include "Line.h"

double Line::getDistance() const {

	Queue<Station> lineRoute = train->getRoute();
	int length = lineRoute.getSize();

	for (int i = 0; i < length; i++) {
		//if (lineRoute.frontData() == startPoint) {

		//}
	}

	return 0;
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
	this->departure = departure;
	


}
