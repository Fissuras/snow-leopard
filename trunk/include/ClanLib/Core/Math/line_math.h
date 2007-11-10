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
**    Magnus Norddahl
**    (if your name is missing here, please add it)
*/

//! clanCore="Math"
//! header=core.h

#ifndef header_line_math
#define header_line_math

#include "../api_core.h"
#include "point.h"

//: Math operations on 2D lines.
//- !group=Core/Math!
//- !header=core.h!
class CL_API_CORE CL_LineMath
{
 public:
// Operations:
	//: Return the distance from a point to a line.
	//param double x: X coordinate of point.
	//param double y: Y coordinate of point.
	//param CL_Pointd point: The point.
	//param double *line: Pointer to double array with elements {x1,y1,x2,y2}.
	static double distance_to_line(const CL_Pointd &point, double *line);

	static double distance_to_line(double x, double y, double *line);

	//: Return true if two line segments intersect.
	//param double *lineA: First line. Pointer to double array with elements {x1,y1,x2,y2}.
	//param double *lineB: Second line. Pointer to double array with elements {x1,y1,x2,y2}.
	//param bool collinear_intersect: set if a collision is reported when all points are on the same line.
	static bool intersects( double *lineA, double *lineB, bool collinear_intersect=false );

	//: Return true if two line segments are collinear. (All points are on the same line.)
	//param double *lineA: First line. Pointer to double array with elements {x1,y1,x2,y2}.
	//param double *lineB: Second line. Pointer to double array with elements {x1,y1,x2,y2}.
	static bool collinear( double *lineA, double *lineB );

	//: Return the intersection point of two lines.
	//param double *lineA: First line. Pointer to double array with elements {x1,y1,x2,y2}.
	//param double *lineB: Second line. Pointer to double array with elements {x1,y1,x2,y2}.
	static CL_Pointd get_intersection( double *lineA, double *lineB );	

	//: Return [<0, 0, >0] if the Point P is right, on or left of the line trough A,B
	//param double x: x coordinate of the point being tested.
	//param double y: y coordinate of the point being tested.
	//param double *line: The line. A pointer to a double array with the elements {x1,y1,x2,y2}.
	//param double line_x1, line_y1: First point defining the line.
	//param double line_x2, line_y2: Second point defining the line.
	//param CL_Pointd P: Test point.
	//param CL_Pointd A: First point defining the line.
	//param CL_Pointd B: Second point defining the line.
	static double point_right_of_line( double x, double y, double *line );

	static double point_right_of_line( double x, double y, double line_x1, double line_y1, double line_x2, double line_y2 );

	static double point_right_of_line( const CL_Pointd &A, const CL_Pointd &B, const CL_Pointd &P );

	//: Return the midpoint of the line from point A to point B.
	//param CL_Pointd A: point A
	//param CL_Pointd B: point B
	static CL_Pointd midpoint( const CL_Pointd &A, const CL_Pointd &B );

	//: Return the normal vector of the line from point A to point B.
	//param CL_Pointd A: point A
	//param CL_Pointd B: point B
	//param double *line: pointer to line vertices {x1, y1, x2, y2}
	static CL_Pointd normal( const CL_Pointd &A, const CL_Pointd &B );

	static CL_Pointd normal( double x1, double y1, double x2, double y2 );

	static CL_Pointd normal( double *line );

	//: Return the Point on the line from A to B closest to point P
	//param CL_Pointd P: point P
	//param CL_Pointd A: point A
	//param CL_Pointd B: point B
	//param double *line: pointer to line vertices {x1, y1, x2, y2}
	static CL_Pointd closest_point( const CL_Pointd &P, const CL_Pointd &A, const CL_Pointd &B );

	//: Return the relative position (0-1) of the point R on the line from A to B closest to point P
	//param CL_Pointd P: point P
	//param CL_Pointd A: point A
	//param CL_Pointd B: point B
	static double closest_point_relative( const CL_Pointd &P, const CL_Pointd &A, const CL_Pointd &B );
};

#endif
