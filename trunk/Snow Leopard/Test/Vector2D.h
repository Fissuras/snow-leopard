#ifndef VECTOR2D_H_
#define VECTOR2D_H_
#include <math.h>

class Vector2D
{
private:
	double x,y;
	double angle;
	double length;
	Vector2D( double Xin, double Yin );

public:
	static Vector2D* Vector2D::Rect(double Xin,double Yin)
{
	return new Vector2D(Xin,Yin);
};

static Vector2D* Vector2D::Polar(double angle,double magnitude)
{
	double Xin = cos(angle) * magnitude;
	double Yin = sin(angle) * magnitude;
	return new Vector2D(Xin,Yin);
};

	void setX( double Xin );
	void setY( double Yin );
	void setLength( double Lin );
	void setAngle( double Ain );

	double getX();
	double getY();
	double getLength();
	double getAngle();

	void operator=(Vector2D aVector);
	Vector2D operator+(Vector2D aVector);

	Vector2D();
	~Vector2D();
};



#endif