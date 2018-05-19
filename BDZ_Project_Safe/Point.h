#ifndef POINT_H_
#define POINT_H_

class Point {
private: 
	double latitude;
	double longitude;
	double lat;
	double lon;
public:
	Point();
	Point(double a, double b);
	double getLatitudeDegrees() const;
	double getLongitudeDegrees() const;
	double getLatitudeRad() const;
	double getLongitudeRad() const;

	friend double getDistance(Point start, Point end);
};

double getDistance(Point start, Point end);

#endif