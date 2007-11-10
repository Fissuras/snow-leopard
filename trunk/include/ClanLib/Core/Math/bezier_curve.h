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
*/

//! clanCore="Math"
//! header=core.h

#ifndef header_bezier_curve
#define header_bezier_curve

#include "../api_core.h"
#include "../System/sharedptr.h"
#include <vector>

class CL_BezierCurve_Impl;
class CL_Pointd;

//: Bezier curve generator.
//- !group=Core/Math!
//- !header=core.h!
class CL_API_CORE CL_BezierCurve
{
//! Construction:
public:
	//: Constructs a bezier curve generator.
	CL_BezierCurve();

	virtual ~CL_BezierCurve();

//! Attributes:
public:
	//: Returns the control points of the bezier.
	std::vector<CL_Pointd> get_control_points() const;

//! Operations:
public:
	//: Adds a control point to bezier.
	void add_control_point(double x, double y);

	void add_control_point(const CL_Pointd &);

	//: Generates points on the bezier curve.
	std::vector<CL_Pointd> generate_curve_points(double split_angle_deg);

	//: Get a point on the bezier curve.
	CL_Pointd get_point_relative(double pos_0_to_1) const;

//! Implementation:
private:
	CL_SharedPtr<CL_BezierCurve_Impl> impl;
};

#endif
