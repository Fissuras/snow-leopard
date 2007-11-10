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
**    Magnus Norddahl
**    Mark Page
**    (if your name is missing here, please add it)
*/

//! clanCore="Math"
//! header=core.h

#ifndef header_cl_vector
#define header_cl_vector

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"
#include <iostream>

//: 1D vector
//- !group=Display/Display!
//- !header=display.h!
template<typename Type>
class CL_Vec1
{
public:
	union { Type x; Type s; Type r; };

	CL_Vec1() { }
	CL_Vec1(const Type &p1) : x(p1) { }

//! Attributes:
public:
	//: Rounds all components.
	//- Uses Asymmetric Arithmetic Rounding
	void round() {x = (Type) floor(x+0.5);}

//! Operators:
public:
	const Type &operator[](unsigned int i) const { return ((Type *) this)[i]; }
	Type &operator[](unsigned int i) { return ((Type *) this)[i]; }
	operator Type *() { return (Type *) this; }
	operator Type * const() const { return (Type * const) this; }

	//: += operator.
	void operator += (const CL_Vec1<Type>& vector) { x+= vector.x; }

	//: += operator.
	void operator += ( Type value) { x+= value; }

	//: + operator.
	CL_Vec1<Type> operator + (const CL_Vec1<Type>& vector) const {return CL_Vec1<Type>(vector.x + x);}

	//: + operator.
	CL_Vec1<Type> operator + (Type value) const {return CL_Vec1<Type>(value + x);}

	//: -= operator.
	void operator -= (const CL_Vec1<Type>& vector) { x-= vector.x; }

	//: -= operator.
	void operator -= ( Type value) { x-= value; }

	//: - operator.
	CL_Vec1<Type> operator - (const CL_Vec1<Type>& vector) const {return CL_Vec1<Type>(x - vector.x);}

	//: - operator.
	CL_Vec1<Type> operator - (Type value) const {return CL_Vec1<Type>(x - value);}

	//: *= operator.
	void operator *= (const CL_Vec1<Type>& vector) { x*= vector.x; }

	//: *= operator.
	void operator *= ( Type value) { x*= value; }

	//: * operator.
	CL_Vec1<Type> operator * (const CL_Vec1<Type>& vector) const {return CL_Vec1<Type>(vector.x * x);}

	//: * operator.
	CL_Vec1<Type> operator * (Type value) const {return CL_Vec1<Type>(value * x);}

	//: /= operator.
	void operator /= (const CL_Vec1<Type>& vector) { x/= vector.x; }

	//: /= operator.
	void operator /= ( Type value) { x/= value; }

	//: / operator.
	CL_Vec1<Type> operator / (const CL_Vec1<Type>& vector) const {return CL_Vec1<Type>(x / vector.x);}

	//: / operator.
	CL_Vec1<Type> operator / (Type value) const {return CL_Vec1<Type>(x / value);}

	//: = operator.
	CL_Vec1<Type> &operator = (const CL_Vec1<Type>& vector) { x = vector.x; return *this; }

	//: == operator.
	bool operator == (const CL_Vec1<Type>& vector) const {return ((x == vector.x));}

	//: != operator.
	bool operator != (const CL_Vec1<Type>& vector) const {return ((x != vector.x));}
};

//: 2D vector
//- !group=Display/Display!
//- !header=display.h!
template<typename Type>
class CL_Vec2
{
public:
	union { Type x; Type s; Type r; };
	union { Type y; Type t; Type g; };

	CL_Vec2() { }
	CL_Vec2(const Type &p1, const Type &p2 = 0) : x(p1), y(p2) { }

//! Attributes:
public:

	//: Returns the length (magnitude) of the vector.
	//- <p>Operates in the native datatype</p>
	//return: the length of the vector
#ifdef WIN32
	Type length() const {return (Type) sqrt(double(x*x+y*y));}
#else
	Type length() const {return (Type) sqrt(x*x+y*y);}	// Damm gcc compiler
#endif

	//: Normalizes the vector
	//- <p>Operates in the native datatype</p>
	void normalize();

	//: Dot products this vector with an other vector.
	//- <p>Operates in the native datatype</p>
	//param vector: Second vector used for the dot product.
	//return: The resulting dot product of the two vectors.
	Type dot(const CL_Vec2<Type>& vector) const {return x*vector.x + y*vector.y;}
	
	//: Calculate the angle between this vector and an other vector. (double)
	//param vector: Second vector used to calculate angle.
	//return: The angle between the two vectors.
	double angle(const CL_Vec2<Type>& vector) const;

	//: Calculate the angle between this vector and an other vector. (float)
	//param vector: Second vector used to calculate angle.
	//return: The angle between the two vectors.
	float anglef(const CL_Vec2<Type>& vector) const;

	//: Rounds all components.
	//- Uses Asymmetric Arithmetic Rounding
	void round();

//! Operators:
public:
	const Type &operator[](unsigned int i) const { return ((Type *) this)[i]; }
	Type &operator[](unsigned int i) { return ((Type *) this)[i]; }
	operator Type *() { return (Type *) this; }
	operator Type * const() const { return (Type * const) this; }

	//: += operator.
	void operator += (const CL_Vec2<Type>& vector) { x+= vector.x; y+= vector.y; }

	//: += operator.
	void operator += ( Type value) { x+= value; y+= value; }

	//: + operator.
	CL_Vec2<Type> operator + (const CL_Vec2<Type>& vector) const {return CL_Vec2<Type>(vector.x + x, vector.y + y);}

	//: + operator.
	CL_Vec2<Type> operator + (Type value) const {return CL_Vec2<Type>(value + x, value + y);}

	//: -= operator.
	void operator -= (const CL_Vec2<Type>& vector) { x-= vector.x; y-= vector.y; }

	//: -= operator.
	void operator -= ( Type value) { x-= value; y-= value; }

	//: - operator.
	CL_Vec2<Type> operator - (const CL_Vec2<Type>& vector) const {return CL_Vec2<Type>(x - vector.x, y - vector.y);}

	//: - operator.
	CL_Vec2<Type> operator - (Type value) const {return CL_Vec2<Type>(x - value, y - value);}

	//: *= operator.
	void operator *= (const CL_Vec2<Type>& vector) { x*= vector.x; y*= vector.y; }

	//: *= operator.
	void operator *= ( Type value) { x*= value; y*= value; }

	//: * operator.
	CL_Vec2<Type> operator * (const CL_Vec2<Type>& vector) const {return CL_Vec2<Type>(vector.x * x, vector.y * y);}

	//: * operator.
	CL_Vec2<Type> operator * (Type value) const {return CL_Vec2<Type>(value * x, value * y);}

	//: /= operator.
	void operator /= (const CL_Vec2<Type>& vector) { x/= vector.x; y/= vector.y; }

	//: /= operator.
	void operator /= ( Type value) { x/= value; y/= value; }

	//: / operator.
	CL_Vec2<Type> operator / (const CL_Vec2<Type>& vector) const {return CL_Vec2<Type>(x / vector.x, y / vector.y);}

	//: / operator.
	CL_Vec2<Type> operator / (Type value) const {return CL_Vec2<Type>(x / value, y / value);}

	//: = operator.
	CL_Vec2<Type> &operator = (const CL_Vec2<Type>& vector) { x = vector.x; y = vector.y; return *this; }

	//: == operator.
	bool operator == (const CL_Vec2<Type>& vector) const {return ((x == vector.x) && (y == vector.y));}

	//: != operator.
	bool operator != (const CL_Vec2<Type>& vector) const {return ((x != vector.x) || (y != vector.y));}

};

//: 3D vector
//- !group=Display/Display!
//- !header=display.h!
template<typename Type>
class CL_Vec3
{
public:
	union { Type x; Type s; Type r; };
	union { Type y; Type t; Type g; };
	union { Type z; Type u; Type b; };

	CL_Vec3() { }
	CL_Vec3(const Type &p1, const Type &p2 = 0, const Type &p3 = 0) : x(p1), y(p2), z(p3) { }

//! Attributes:
public:
	//: Returns the length (magnitude) of the vector.
	//- <p>Operates in the native datatype</p>
	//return: the length of the vector (in R^3)
#ifdef WIN32
	Type length() const {return (Type) sqrt(double(x*x+y*y+z*z));}
#else
	Type length() const {return (Type) sqrt(x*x+y*y+z*z);}
#endif
	//: Normalizes the vector
	//- <p>Operates in the native datatype</p>
	void normalize();

	//: Dot products this vector with an other vector.
	//- <p>Operates in the native datatype</p>
	//param vector: Second vector used for the dot product.
	//return: The resulting dot product of the two vectors.
	Type dot(const CL_Vec3<Type>& vector) const {return x*vector.x + y*vector.y + z*vector.z;}
	
	//: Calculate the angle between this vector and an other vector. (double)
	//param vector: Second vector used to calculate angle.
	//return: The angle between the two vectors.
	double angle(const CL_Vec3<Type>& vector) const;

	//: Calculate the angle between this vector and an other vector. (float)
	//param vector: Second vector used to calculate angle.
	//return: The angle between the two vectors.
	float anglef(const CL_Vec3<Type>& vector) const;

	//: Calculate the cross product between this vector and an other vector.
	//- <p>Operates in the native datatype</p>
	//param vector: Second vector used to perform the calculation.
	//return: The cross product of the two vectors.
	CL_Vec3<Type> cross(const CL_Vec3<Type>& vector) const;
	
	//: Rotate vector around an axis (double). Same as glRotated(angle, a);
	//param angle: Angle to rotate (in radians).
	//param axis: Rotation axis.
	//return: The resulting rotated vector.
	CL_Vec3<Type> rotate(double angle, const CL_Vec3<Type>& axis) const;

	//: Rotate vector around an axis (float). Same as glRotatef(angle, a);
	//param angle: Angle to rotate (in radians).
	//param axis: Rotation axis.
	//return: The resulting rotated vector.
	CL_Vec3<Type> rotate(float angle, const CL_Vec3<Type>& axis) const;

	//: Rounds all components.
	//- Uses Asymmetric Arithmetic Rounding
	void round();

//! Operators:
public:
	const Type &operator[](unsigned int i) const { return ((Type *) this)[i]; }
	Type &operator[](unsigned int i) { return ((Type *) this)[i]; }
	operator Type *() { return (Type *) this; }
	operator Type * const() const { return (Type * const) this; }

	//: += operator.
	void operator += (const CL_Vec3<Type>& vector) { x+= vector.x; y+= vector.y; z+= vector.z; }

	//: += operator.
	void operator += ( Type value) { x+= value; y+= value; z+= value; }

	//: + operator.
	CL_Vec3<Type> operator + (const CL_Vec3<Type>& vector) const {return CL_Vec3<Type>(vector.x + x, vector.y + y, vector.z + z);}

	//: + operator.
	CL_Vec3<Type> operator + (Type value) const {return CL_Vec3<Type>(value + x, value + y, value + z);}

	//: -= operator.
	void operator -= (const CL_Vec3<Type>& vector) { x-= vector.x; y-= vector.y; z-= vector.z; }

	//: -= operator.
	void operator -= ( Type value) { x-= value; y-= value; z-= value; }

	//: - operator.
	CL_Vec3<Type> operator - (const CL_Vec3<Type>& vector) const {return CL_Vec3<Type>(x - vector.x, y - vector.y, z - vector.z);}

	//: - operator.
	CL_Vec3<Type> operator - (Type value) const {return CL_Vec3<Type>(x - value, y - value, z - value);}

	//: *= operator.
	void operator *= (const CL_Vec3<Type>& vector) { x*= vector.x; y*= vector.y; z*= vector.z; }

	//: *= operator.
	void operator *= ( Type value) { x*= value; y*= value; z*= value; }

	//: * operator.
	CL_Vec3<Type> operator * (const CL_Vec3<Type>& vector) const {return CL_Vec3<Type>(vector.x * x, vector.y * y, vector.z * z);}

	//: * operator.
	CL_Vec3<Type> operator * (Type value) const {return CL_Vec3<Type>(value * x, value * y, value * z);}

	//: /= operator.
	void operator /= (const CL_Vec3<Type>& vector) { x/= vector.x; y/= vector.y; z/= vector.z; }

	//: /= operator.
	void operator /= ( Type value) { x/= value; y/= value; z/= value; }

	//: / operator.
	CL_Vec3<Type> operator / (const CL_Vec3<Type>& vector) const {return CL_Vec3<Type>(x / vector.x, y / vector.y, z / vector.z);}

	//: / operator.
	CL_Vec3<Type> operator / (Type value) const {return CL_Vec3<Type>(x / value, y / value, z / value);}

	//: = operator.
	CL_Vec3<Type> &operator = (const CL_Vec3<Type>& vector) { x = vector.x; y = vector.y; z = vector.z; return *this; }

	//: == operator.
	bool operator == (const CL_Vec3<Type>& vector) const {return ((x == vector.x) && (y == vector.y) && (z == vector.z));}

	//: != operator.
	bool operator != (const CL_Vec3<Type>& vector) const {return ((x != vector.x) || (y != vector.y) || (z != vector.z));}

};

//: 4D vector
//- !group=Display/Display!
//- !header=display.h!
template<typename Type>
class CL_Vec4
{
public:
	union { Type x; Type s; Type r; };
	union { Type y; Type t; Type g; };
	union { Type z; Type u; Type b; };
	union { Type w; Type v; Type a; };

	CL_Vec4() { }
	CL_Vec4(const Type &p1, const Type &p2 = 0, const Type &p3 = 0, const Type &p4 = 0) : x(p1), y(p2), z(p3), w(p4) { }

//! Attributes:
public:
	//: Returns the length (magnitude) of the vector.
	//- <p>This function does not use the w coordinate of the vector. It only uses
	//- the x,y,z coordinates.</p>
	//- <p>Operates in the native datatype</p>
	//return: the length of the vector (in R^3)
#ifdef WIN32
	Type length() const {return (Type) sqrt(double(x*x+y*y+z*z));}
#else
	Type length() const {return (Type) sqrt(x*x+y*y+z*z);}
#endif
	//: Normalizes the vector (not taking into account the w ordinate!)
	//- <p>Operates in the native datatype</p>
	void normalize();

	//: Dot products this vector with an other vector.
	//- <p>Operates in the native datatype</p>
	//param vector: Second vector used for the dot product.
	//return: The resulting dot product of the two vectors.
	Type dot(const CL_Vec4<Type>& vector) const {return x*vector.x + y*vector.y + z*vector.z;}
	
	//: Calculate the angle between this vector and an other vector. (double)
	//param vector: Second vector used to calculate angle.
	//return: The angle between the two vectors.
	double angle(const CL_Vec4<Type>& vector) const;

	//: Calculate the angle between this vector and an other vector. (float)
	//param vector: Second vector used to calculate angle.
	//return: The angle between the two vectors.
	float anglef(const CL_Vec4<Type>& vector) const;

	//: Calculate the cross product between this vector and an other vector.
	//- <p>Operates in the native datatype</p>
	//param vector: Second vector used to perform the calculation.
	//return: The cross product of the two vectors.
	CL_Vec4<Type> cross(const CL_Vec4<Type>& vector) const;
	
	//: Rotate vector around an axis (double). Same as glRotated(angle, a);
	//param angle: Angle to rotate (in radians).
	//param axis: Rotation axis.
	//return: The resulting rotated vector.
	CL_Vec4<Type> rotate(double angle, const CL_Vec4<Type>& axis) const;

	//: Rotate vector around an axis (float). Same as glRotatef(angle, a);
	//param angle: Angle to rotate (in radians).
	//param axis: Rotation axis.
	//return: The resulting rotated vector.
	CL_Vec4<Type> rotate(float angle, const CL_Vec4<Type>& axis) const;

	//: Rounds all components.
	//- Uses Asymmetric Arithmetic Rounding
	void round();

//! Operators:
public:
	const Type &operator[](unsigned int i) const { return ((Type *) this)[i]; }
	Type &operator[](unsigned int i) { return ((Type *) this)[i]; }
	operator Type *() { return (Type *) this; }
	operator Type * const() const { return (Type * const) this; }

	//: += operator.
	void operator += (const CL_Vec4<Type>& vector) { x+= vector.x; y+= vector.y; z+= vector.z; w+= vector.w; }

	//: += operator.
	void operator += ( Type value) { x+= value; y+= value; z+= value; w+= value; }

	//: + operator.
	CL_Vec4<Type> operator + (const CL_Vec4<Type>& vector) const {return CL_Vec4<Type>(vector.x + x, vector.y + y, vector.z + z, vector.w + w);}

	//: + operator.
	CL_Vec4<Type> operator + (Type value) const {return CL_Vec4<Type>(value + x, value + y, value + z, value + w);}

	//: -= operator.
	void operator -= (const CL_Vec4<Type>& vector) { x-= vector.x; y-= vector.y; z-= vector.z; w-= vector.w; }

	//: -= operator.
	void operator -= ( Type value) { x-= value; y-= value; z-= value; w-= value; }

	//: - operator.
	CL_Vec4<Type> operator - (const CL_Vec4<Type>& vector) const {return CL_Vec4<Type>(x - vector.x, y - vector.y, z - vector.z, w - vector.w);}

	//: - operator.
	CL_Vec4<Type> operator - (Type value) const {return CL_Vec4<Type>(x - value, y - value, z - value, w - value);}

	//: *= operator.
	void operator *= (const CL_Vec4<Type>& vector) { x*= vector.x; y*= vector.y; z*= vector.z; w*= vector.w; }

	//: *= operator.
	void operator *= ( Type value) { x*= value; y*= value; z*= value; w*= value; }

	//: * operator.
	CL_Vec4<Type> operator * (const CL_Vec4<Type>& vector) const {return CL_Vec4<Type>(vector.x * x, vector.y * y, vector.z * z, vector.w * w);}

	//: * operator.
	CL_Vec4<Type> operator * (Type value) const {return CL_Vec4<Type>(value * x, value * y, value * z, value * w);}

	//: /= operator.
	void operator /= (const CL_Vec4<Type>& vector) { x/= vector.x; y/= vector.y; z/= vector.z; w/= vector.w; }

	//: /= operator.
	void operator /= ( Type value) { x/= value; y/= value; z/= value; w/= value; }

	//: / operator.
	CL_Vec4<Type> operator / (const CL_Vec4<Type>& vector) const {return CL_Vec4<Type>(x / vector.x, y / vector.y, z / vector.z, w / vector.w);}

	//: / operator.
	CL_Vec4<Type> operator / (Type value) const {return CL_Vec4<Type>(x / value, y / value, z / value, w / value);}

	//: = operator.
	CL_Vec4<Type> &operator = (const CL_Vec4<Type>& vector) { x = vector.x; y = vector.y; z = vector.z; w = vector.w; return *this; }

	//: == operator.
	bool operator == (const CL_Vec4<Type>& vector) const {return ((x == vector.x) && (y == vector.y) && (z == vector.z) && (w == vector.w));}

	//: != operator.
	bool operator != (const CL_Vec4<Type>& vector) const {return ((x != vector.x) || (y != vector.y) || (z != vector.z) || (w != vector.w));}

};

typedef CL_Vec1<unsigned char> CL_Vec1ub;
typedef CL_Vec1<char> CL_Vec1b;
typedef CL_Vec1<unsigned short> CL_Vec1us;
typedef CL_Vec1<short> CL_Vec1s;
typedef CL_Vec1<unsigned int> CL_Vec1ui;
typedef CL_Vec1<int> CL_Vec1i;
typedef CL_Vec1<float> CL_Vec1f;
typedef CL_Vec1<double> CL_Vec1d;

typedef CL_Vec2<unsigned char> CL_Vec2ub;
typedef CL_Vec2<char> CL_Vec2b;
typedef CL_Vec2<unsigned short> CL_Vec2us;
typedef CL_Vec2<short> CL_Vec2s;
typedef CL_Vec2<unsigned int> CL_Vec2ui;
typedef CL_Vec2<int> CL_Vec2i;
typedef CL_Vec2<float> CL_Vec2f;
typedef CL_Vec2<double> CL_Vec2d;

typedef CL_Vec3<unsigned char> CL_Vec3ub;
typedef CL_Vec3<char> CL_Vec3b;
typedef CL_Vec3<unsigned short> CL_Vec3us;
typedef CL_Vec3<short> CL_Vec3s;
typedef CL_Vec3<unsigned int> CL_Vec3ui;
typedef CL_Vec3<int> CL_Vec3i;
typedef CL_Vec3<float> CL_Vec3f;
typedef CL_Vec3<double> CL_Vec3d;

typedef CL_Vec4<unsigned char> CL_Vec4ub;
typedef CL_Vec4<char> CL_Vec4b;
typedef CL_Vec4<unsigned short> CL_Vec4us;
typedef CL_Vec4<short> CL_Vec4s;
typedef CL_Vec4<unsigned int> CL_Vec4ui;
typedef CL_Vec4<int> CL_Vec4i;
typedef CL_Vec4<float> CL_Vec4f;
typedef CL_Vec4<double> CL_Vec4d;

typedef CL_Vec4<double> CL_Vector;

#endif

