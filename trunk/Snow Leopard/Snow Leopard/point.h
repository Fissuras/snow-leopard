#ifndef point_h_
#define point_h_
#include <iostream>
#include <math.h>
#include <cmath>

struct point
{
public:
	point::point(double i,double j);
	point::point();
	point point::offsetRect(double ox, double oy);
	point point::offsetPolar(double heading, double distance);
	double x;
	double y;
	std::string point::toString();
};

#endif