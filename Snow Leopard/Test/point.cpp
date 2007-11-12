#include "point.h"
#include "boost/lexical_cast.hpp"


point::point(double i, double j)
{
	x = i;
	y = j;
}

point::point()
{
}

point point::offsetRect(double ox, double oy)
{
	return point(x+ox,y+oy);
}

point point::offsetPolar(double heading, double distance)
{
	return point(x,y);
}

std::string point::toString()
{
	return boost::lexical_cast<std::string>((x)) + "," + boost::lexical_cast<std::string>(y);
}