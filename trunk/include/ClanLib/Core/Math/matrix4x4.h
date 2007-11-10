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
*/

//! clanCore="Math"
//! header=core.h

#ifndef header_matrix4x4
#define header_matrix4x4

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"

//: 4x4 Matrix.
//- !group=Core/Math!
//- !header=core.h!
class CL_API_CORE CL_Matrix4x4
{
//! Construction:
public:
	//: Constructs a 4x4 matrix.
	//param identity: When true, initial matrix will be the identity matrix. If false, initial will be null matrix.
	//param matrix[16]: Initial matrix.
	CL_Matrix4x4(bool identity = false);

	CL_Matrix4x4(const CL_Matrix4x4 &copy);

	CL_Matrix4x4(double *matrix);

	CL_Matrix4x4(float *matrix);

	static CL_Matrix4x4 frustum(double left, double right, double bottom, double top, double z_near, double z_far);

	static CL_Matrix4x4 perspective(
		double field_of_view_y_degrees,
		double aspect,
		double z_near,
		double z_far);

	static CL_Matrix4x4 ortho(double left, double right, double bottom, double top, double z_near, double z_far);

	static CL_Matrix4x4 ortho_2d(double left, double right, double bottom, double top);

	static CL_Matrix4x4 rotate(double angle_degrees, double x, double y, double z, bool normalize = true);

	static CL_Matrix4x4 scale(double x, double y, double z);

	static CL_Matrix4x4 translate(double x, double y, double z);

	static CL_Matrix4x4 look_at(
		double eye_x, double eye_y, double eye_z,
		double center_x, double center_y, double center_z,
		double up_x, double up_y, double up_z);

//! Attributes:
public:
	double matrix[16];

	//: Operator that returns the matrix as a double[16] array.
	operator double const*() const { return matrix; }

	//: Operator that returns the matrix as a double[16] array.
	operator double *() { return matrix; }

	//: Operator that returns the matrix cell at the given index.
	double &operator[](int i) { return matrix[i]; }

	//: Operator that returns the matrix cell at the given index.
	const double &operator[](int i) const { return matrix[i]; }

	//: Operator that returns the matrix cell at the given index.
	double &operator[](unsigned int i) { return matrix[i]; }

	//: Operator that returns the matrix cell at the given index.
	const double &operator[](unsigned int i) const { return matrix[i]; }

	//: Returns the x coordinate for the point (0,0,0) multiplied with this matrix.
	double get_origin_x() const;

	//: Returns the y coordinate for the point (0,0,0) multiplied with this matrix.
	double get_origin_y() const;

	//: Returns the z coordinate for the point (0,0,0) multiplied with this matrix.
	double get_origin_z() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_Matrix4x4 &operator =(const CL_Matrix4x4 &copy);

	//: Equality operator.
	bool operator==(const CL_Matrix4x4 &other);

	//: Not-equal operator.
	bool operator!=(const CL_Matrix4x4 &other);

	//: Multiply two matrices.
	CL_Matrix4x4 multiply(const CL_Matrix4x4 &matrix);

//! Implementation:
private:
};

#endif
