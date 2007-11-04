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

std::string point::toString()
{
	return boost::lexical_cast<std::string>((x)) + "," + boost::lexical_cast<std::string>(y);
}