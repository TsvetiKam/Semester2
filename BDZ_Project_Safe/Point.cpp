#include "stdafx.h"
#include "Point.h"
#include <cmath>

Point::Point() {
	latitude = 0;
	longitude = 0;
	lat = 0;
	lon = 0;
}

Point::Point(double a, double b) {
	lat = a;
	lon = b;
	const double PI = 3.1415926535897;
	latitude = PI * a/180;
	longitude = PI * b/180;
}

double Point::getLatitudeDegrees() const {
	return lat;
}

double Point::getLongitudeDegrees() const {
	return lon;
}

double Point::getLatitudeRad() const {
	return latitude;
}

double Point::getLongitudeRad() const {
	return longitude;
}

double getDistance(Point start, Point end) {
	//Reference https ://www.physicsforums.com/threads/haversine-formula-c-help.734790/
	//https: //en.wikipedia.org/wiki/Great-circle_distance
	const int R = 6371; // Earth radius
	double dLat = abs(end.latitude - start.latitude);
	double dLon = abs(end.longitude - start.longitude);
	double a = (pow(sin(dLat / 2), 2)) + (cos(start.latitude)*cos(end.latitude)*pow(sin(dLon / 2), 2));
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));
	double distance = R * c;

	return distance;
}
