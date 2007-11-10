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

#ifndef header_triangle_math
#define header_triangle_math

#include "../api_core.h"

class CL_Pointd;

//: Math operations on triangles.
//- !group=Core/Math!
//- !header=core.h!
class CL_API_CORE CL_TriangleMath
{
//! Operations:
public:
	//: Return true if the point is inside the triangle.
	//param CL_Pointd P: point to test.
	//param double *vertices: Pointer to triangle vertices {x1,y1,x2,y2,x3,y3}.
	static bool point_inside_triangle(const CL_Pointd &P, double *vertices);

	static bool point_inside_triangle(double px, double py, double *vertices);
};

#endif
