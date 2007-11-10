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

//! clanDisplay="Display"
//! header=display.h

#ifndef header_rounded_rect
#define header_rounded_rect

#if _MSC_VER > 1000
#pragma once
#endif

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/Math/origin.h"
#include "../Display/graphic_context.h"

class CL_Color;
class CL_Gradient;
class CL_Sized;
class CL_Pointd;
class CL_RoundedRect_Impl;

//: Rounded rects drawing class.
//- !group=Display/Display!
//- !header=display.h!
class CL_RoundedRect
{
//! Construction:
public:
	CL_RoundedRect(CL_Sized size, double rounding_in_pixels=5.0);
	virtual ~CL_RoundedRect();

//! Attributes:
public:
	//: Returns the base rectangle.
	CL_Sized get_size() const;

	//: Returns the width of the rectangle.
	double get_width() const;

	//: Returns the height of the rectangle.
	double get_height() const;

	//: Returns the distance from a corner (in pixels) at which the rounding starts.
	//- This value is used for corners for which no value has been specified separately.
	double get_rounding() const;

	//: Returns the positions of the top-left corners conic bezier control point.
	CL_Pointd get_control_point_tl() const;

	//: Returns the positions of the top-right corners conic bezier control point.
	CL_Pointd get_control_point_tr() const;

	//: Returns the positions of the bottom-left corners conic bezier control point.
	CL_Pointd get_control_point_bl() const;

	//: Returns the positions of the bottom-right corners conic bezier control point.
	CL_Pointd get_control_point_br() const;

	//: Returns the relative offset (0.0-1.0) to the center of the edges connected to the corner.
	CL_Sized get_rounding_top_left() const;

	//: Returns the relative offset (0.0-1.0) to the center of the edges connected to the corner.
	CL_Sized get_rounding_top_right() const;

	//: Returns the relative offset (0.0-1.0) to the center of the edges connected to the corner.
	CL_Sized get_rounding_bottom_left() const;

	//: Returns the relative offset (0.0-1.0) to the center of the edges connected to the corner.
	CL_Sized get_rounding_bottom_right() const;

//! Operations:
public:
	//: Draw the rectangle outline
	void draw(
		CL_GraphicContext gc,
		const CL_Pointd &position, 
		const CL_Colord &color,
		CL_Origin origin=origin_top_left);

	void draw(
		CL_GraphicContext gc,
		const CL_Pointd &position, 
		const CL_Gradient &gradient,
		CL_Origin origin=origin_top_left);

	//: Fill the rectangle
	void fill(
		CL_GraphicContext gc,
		const CL_Pointd &position,
		const CL_Colord &color,
		CL_Origin origin=origin_top_left);

	void fill(
		CL_GraphicContext gc,
		const CL_Pointd &position,
		const CL_Gradient &gradient,
		CL_Origin origin=origin_top_left);

	//: Set the size of the base rectangle
	void set_size(const CL_Sized &size);

	//: Set the position of the top-left corners conic bezier control point.
	void set_control_point_tl(const CL_Pointd &pos);

	//: Set the positions of the top-right corners conic bezier control point.
	void set_control_point_tr(const CL_Pointd &pos);

	//: Set the positions of the bottom-left corners conic bezier control point.
	void set_control_point_bl(const CL_Pointd &pos);

	//: Set the positions of the bottom-right corners conic bezier control point.
	void set_control_point_br(const CL_Pointd &pos);

	//: Set the distance from a corner (in pixels) at which the rounding starts.
	//- This value is used for corners for which no value has been specified separately.
	void set_rounding(double offset_pixels);

	//: Set the relative offset (0.0-1.0) to the center of the edges connected to the corner.
	void set_rounding_top_left(const CL_Sized &offset);

	//: Set the relative offset (0.0-1.0) to the center of the edges connected to the corner.
	void set_rounding_top_right(const CL_Sized &offset);

	//: Set the relative offset (0.0-1.0) to the center of the edges connected to the corner.
	void set_rounding_bottom_left(const CL_Sized &offset);

	//: Set the relative offset (0.0-1.0) to the center of the edges connected to the corner.
	void set_rounding_bottom_right(const CL_Sized &offset);

//! Implementation:
private:
	CL_SharedPtr<CL_RoundedRect_Impl> impl;
};

#endif
