#include "Vector2D.h"
#include <math.h>
#include <iostream>

inline double modulus(double a, double b)
{
int result = static_cast<int>( a / b );
return a - static_cast<double>( result ) * b;
}

#define PI 3.141592654

Vector2D::Vector2D()
{
	x = 0;
	y = 0;
	angle = 0;
	length = 0;
}

Vector2D::Vector2D( double Xin, double Yin )
{
	x = Xin;
	y = Yin;
	angle = atan2(y,x);
	length = sqrt( Xin*Xin + Yin*Yin );
}

Vector2D::~Vector2D()
{
}

void Vector2D::setX( double Xin )
{
	x = Xin;
}

void Vector2D::setY( double Yin )
{
	y = Yin;
}

void Vector2D::setLength( double Lin )
{
	length = Lin;
	x = cos(angle)*length;
	y = sin(angle)*length;

}

void Vector2D::setAngle( double Ain )
{
	angle = modulus(Ain,360.0);
	x = cos(angle)*length;
	y = sin(angle)*length;
}

double Vector2D::getX()
{
	return x;
}

double Vector2D::getY()
{
	return y;
}

double Vector2D::getLength()
{
	return length;
}

double Vector2D::getAngle()
{
	return angle;
}

void Vector2D::operator =(Vector2D aVector)
{
	x = aVector.x;
	y = aVector.y;
	length = aVector.length;
	angle = aVector.angle;
}

Vector2D Vector2D::operator+(Vector2D vector)
{
	x += vector.x;
	y += vector.y;
	return *this;
}