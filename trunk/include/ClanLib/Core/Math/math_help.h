/*
**  ClanLib SDK
**  Copyright (c) 1997-2005 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Harry Storbacka
*/

//! clanCore="Math"
//! header=core.h

#ifndef header_math_help
#define header_math_help

#include "math.h"

//: Math operations on 2D and 3d point and vector structures.
//- !group=Core/Math!
//- !header=core.h!
class CL_MathHelp
{
public:
	//: Converts degrees to radians.
	static double deg_to_rad(double angle) 
	{
		return angle * CL_PI / 180.0;
	}

	//: Converts radians to degrees.
	static double rad_to_deg(double angle)
	{
		return angle * 180.0 / CL_PI;
	}

	//: Converts degrees to radians.
	static float deg_to_rad(float angle) 
	{
		return angle * CL_PI / 180.0f;
	}

	//: Converts radians to degrees.
	static float rad_to_deg(float angle)
	{
		return angle * 180.0f / CL_PI;
	}

	//: Return a point rotated around a hotspot in 2D.
	//param angle_rad: Rotation amount, in radians.
	//param t: Point to rotate.
	//param hotspot: Point to rotate around.
	template<class T, class RotationPoint>
	static T rotate2d(double angle_rad, const T &t, const RotationPoint &hotspot )
	{
		// Move the hotspot to 0,0
		T r(t.x - (T::datatype)(hotspot.x), t.y - (T::datatype)(hotspot.y));
		
		const typename T::datatype c = T::datatype(sqrt(r.x*r.x + r.y*r.y));
	
		const typename T::datatype nw = (typename T::datatype)((typename T::datatype)atan2(r.y, r.x) + ((angle_rad + CL_PI)));
	
		r.x = ((typename T::datatype)(sin(1.5 * CL_PI - nw)) * c) + hotspot.x;
		r.y = -((typename T::datatype)(sin(nw)) * c) + hotspot.y;
		
		return r;
	}

	//: Return a point rotated around an axis in 3D.
	//param angle_rad: Rotation amount, in radians.
	//param t: Point to rotate.
	//param a: Axis to rotate around.
	template<class T, class Axis>
	static T rotate3d(double angle, const T &t, const Axis &a)
	{
		T tmp;

		double s = sin(angle);
		double c = cos(angle);

		tmp.x = t.x*(a.x*a.x*(1-c)+c)     + t.y*(a.x*a.y*(1-c)-a.z*s) + t.z*(a.x*a.z*(1-c)+a.y*s);
		tmp.y = t.x*(a.y*a.x*(1-c)+a.z*s) + t.y*(a.y*a.y*(1-c)+c)     + t.z*(a.y*a.z*(1-c)-a.x*s);
		tmp.z = t.x*(a.x*a.z*(1-c)-a.y*s) + t.y*(a.y*a.z*(1-c)+a.x*s) + t.z*(a.z*a.z*(1-c)+c);

		return tmp;  
	}

	//: Calculate the angle between two vectors in 3D.
	//param t1: first vector used to calculate angle.
	//param t2: Second vector used to calculate angle.
	//return: The angle between the two vectors.
	template<class T1, class T2>
	static typename T1::datatype angle3d(const T1& t1, const T2 &t2 )
	{
		return acos(dot3d(t1,t2)/(length3d(t1)*length3d(t1)));  
	}

	//: Calculate the distance between two points in 2D.
	//param t1: first point.
	//param t2: Second point.
	//return: The distance between the two points.
	template<class T1, class T2>
	static typename T1::datatype distance2d( const T1 &t1, const T2 &t2 )
	{
		return static_cast<typename T1::datatype>(sqrt((t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y)));
	}

	//: Calculate the distance between two points in 3D.
	//param t1: first point.
	//param t2: Second point.
	//return: The distance between the two points.
	template<class T1, class T2>
	static typename T1::datatype distance3d( const T1 &t1, const T2 &t2 )
	{
		return static_cast<typename T1::datatype>(sqrt((t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) + (t1.z-t2.z)*(t1.z-t2.z)));
	}

	//: Calculate the length of a vector in 2D.
	//param t: vector.
	//return: The Length of the vector.
	template<class T>
	static typename T::datatype length2d( const T &t )
	{
		return (typename T::datatype)sqrt(t.x*t.x + t.y*t.y);
	}

	//: Calculate the length of a vector in 3D.
	//param t: vector.
	//return: The Length of the vector.
	template<class T>
	static typename T::datatype length3d( const T &t )
	{
		return (typename T::datatype)sqrt(t.x*t.x + t.y*t.y + t.z*t.z);
	}

	//: Calculate the unit vector of a 2D vector.
	//param t: the vector used to calculate the unit vector.
	//return: unit vector.
	template<class T>
	static T normalize2d( const T &t )
	{
		T R;
		typename T::datatype len = length2d(t);

		if (len != 0)
		{
			R.x = t.x/len;
			R.y = t.y/len;
		}
		
		return R;
	}

	//: Calculate the unit vector of a 3D vector.
	//param t: The vector used to calculate the unit vector.
	//return: Unit vector.
	template<class T>
	static T normalize3d( const T &t )
	{
		T R;
		typename T::datatype len = length3d(t);

		if (len != 0)
		{
			R.x = t.x/len;
			R.y = t.y/len;
			R.z = t.z/len;
		}
		
		return R;
	}

	//: Calculate the dot product of 2D vectors.
	//param t1: First vector.
	//param t1: Second vector.
	//return: Dot product.
	template<class T1, class T2>
	static typename T1::datatype dot2d( const T1 &t1, const T2 &t2 )
	{
	    return static_cast<typename T1::datatype>(t1.x*t2.x + t1.y*t2.y);
	}

	//: Calculate the dot product of 3D vectors.
	//param t1: First vector.
	//param t1: Second vector.
	//return: Dot product.
	template<class T1, class T2>
	static typename T1::datatype dot3d( const T1 &t1, const T2 &t2 )
	{
		return static_cast<typename T1::datatype>(t1.x*t2.x + t1.y*t2.y + t1.z*t2.z);
	}

	//: Return the orthogonal vector of a 2D vector.
	template<class T>
	static T othogonal2d( const T &t)
	{
	    return T(t.y,-t.x);
	}

	//: Calculate the cross product of 3D vectors.
	//param t: First vector.
	//param v: Second vector.
	//return: Cross Product.
	template<class T1, class T2>
	static typename T1::datatype cross3d( const T1 &t, const T2 &v )
	{
		typedef typename T1::datatype dt;

		return T1(t.y * static_cast<dt>(v.z) - t.z * static_cast<dt>(v.y),
		          t.z * static_cast<dt>(v.x) - t.x * static_cast<dt>(v.z),
		          t.x * static_cast<dt>(v.y) - t.y * static_cast<dt>(v.x));
	}

	//: Round a 2D Points x,y values to closest integer value.
	template<class T>
	static T round2d(const T &t)
	{
		T tmp;
		tmp.x = static_cast<typename T::datatype>( static_cast<int>(static_cast<double>(t.x) + 0.5) );
		tmp.y = static_cast<typename T::datatype>( static_cast<int>(static_cast<double>(t.y) + 0.5) );
		return tmp;
	}

	//: Round a 3D Points x,y,z values to closest integer value.
	template<class T>
	static T round3d(const T &t)
	{
		T tmp;
		tmp.x = static_cast<typename T::datatype>( static_cast<int>(static_cast<double>(t.x) + 0.5) );
		tmp.y = static_cast<typename T::datatype>( static_cast<int>(static_cast<double>(t.y) + 0.5) );
		tmp.z = static_cast<typename T::datatype>( static_cast<int>(static_cast<double>(t.z) + 0.5) );
		return tmp;
	}
};

#endif
