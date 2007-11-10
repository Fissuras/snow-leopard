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

point* point::offset(int ox, int oy)
{
	return new point(x+ox,y+oy);
}

std::string point::toString()
{
	return boost::lexical_cast<std::string>((x)) + "," + boost::lexical_cast<std::string>(y);
}