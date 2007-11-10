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

#ifndef header_ear_clip_triangulator
#define header_ear_clip_triangulator

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"
#include "../System/sharedptr.h"
#include "../Math/point.h"
#include <vector>

//- !group=Core/Math!
//- !header=core.h!
class CL_EarClipTriangulator_Triangle
{
public:
	double x1,y1,x2,y2,x3,y3;
};

class CL_EarClipTriangulator_Impl;
class CL_EarClipResult;

//: Polygon orientations.
//- !group=Core/Math!
//- !header=core.h!
enum CL_PolygonOrientation
{
	cl_clockwise,
	cl_counter_clockwise
};

//: Ear-clipping triangulator.
//- !group=Core/Math!
//- !header=core.h!
class CL_EarClipTriangulator
{
//! Construction:
public:
	//: Constructs a triangulator.
	CL_EarClipTriangulator();

	virtual ~CL_EarClipTriangulator();

//! Attributes:
public:
	//: Returns the vertices used in polygon.
	std::vector<CL_Pointd> get_vertices();

//! Operations:
public:
	//: Add vertex to polygon path.
	void add_vertex(double x, double y);

	void add_vertex(const CL_Pointd &p);

	//: Remove all vertices from triangulator.
	void clear();

	//: Set polygon orientation.
	void set_orientation( CL_PolygonOrientation orientation );

	//: Perform triangulation.
	CL_EarClipResult triangulate();

	//: Mark beginning of a polygon hole.
	void begin_hole();

	//: Mark ending of a polygon hole.
	void end_hole();

//! Implementation:
private:
	CL_SharedPtr<CL_EarClipTriangulator_Impl> impl;
};

#endif
