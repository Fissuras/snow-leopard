#ifndef point_h_
#define point_h_
#include <iostream>

struct point
{
public:
	point::point(int i,int j);
	point::point();
	int x;
	int y;
	std::string point::toString();
};

#endif