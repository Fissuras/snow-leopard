#include "point.h"
#include "boost/lexical_cast.hpp"


point::point(int i, int j)
{
	x = i;
	y = j;
}

point::point()
{
}

point* point::offsetRect(int ox, int oy)
{
	return new point(x+ox,y+oy);
}

point* point::offsetPolar(double heading, double distance)
{
	return new point(x,y);
}

std::string point::toString()
{
	return boost::lexical_cast<std::string>((x)) + "," + boost::lexical_cast<std::string>(y);
}