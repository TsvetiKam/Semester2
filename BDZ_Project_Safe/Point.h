#ifndef POINT_H_
#define POINT_H_
#include <iostream>

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
	bool operator==(const Point& other) const;

	friend double getDistance(Point start, Point end);
	friend std::ostream& operator<<(std::ostream& out, const Point& x); 
	friend std::istream& operator>>(std::istream& in, Point& x);
};

double getDistance(Point start, Point end);

#endif