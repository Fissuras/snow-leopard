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
**    Kenneth Gangstø
**    Harry Storbacka
**    Ken Hirsch
*/

//! clanDisplay="Display"
//! header=display.h

#ifndef header_draw
#define header_draw

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning( disable : 4786)
#endif

#include "api_display.h"
#include "graphic_context.h"

class CL_Colord;
class CL_Pointd;
class CL_Gradient;
struct CL_TexCoordArray;
struct CL_ProgramAttributeArray;

//: Primitives drawing class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_Draw
{
//! Operations:
public:
	//: Draw a point.
	static void point(CL_GraphicContext gc, double x1, double y1, const CL_Colord &color);
	static void point(CL_GraphicContext gc, const CL_Pointd &point, const CL_Colord &color);

	//: Draw a line.
	static void line(CL_GraphicContext gc, double x1, double y1, double x2, double y2, const CL_Colord &color);
	static void line(CL_GraphicContext gc, const CL_Pointd &start, const CL_Pointd &end, const CL_Colord &color);

	//: Draw a box / rectangle.
	static void box(CL_GraphicContext gc, double x1, double y1, double x2, double y2, const CL_Colord &color);
	static void box(CL_GraphicContext gc, const CL_Pointd &start, const CL_Pointd &end, const CL_Colord &color);
	static void box(CL_GraphicContext gc, const CL_Rectd &rect, const CL_Colord &color);

	//: Draw a filled box / rectangle.
	static void fill(CL_GraphicContext gc, double x1, double y1, double x2, double y2, const CL_Colord &color);
	static void fill(CL_GraphicContext gc, const CL_Pointd &start, const CL_Pointd &end, const CL_Colord &color);
	static void fill(CL_GraphicContext gc, const CL_Rectd &rect, const CL_Colord &color);

	//: Draw a textured rectangle.
	static void texture(
		CL_GraphicContext gc,
		const CL_Rectd &rect,
		const CL_Colord &color = CL_Colord::white,
		const CL_Rectd &texture_unit1_coords = CL_Rectd(0.0, 0.0, 1.0, 1.0));

	static void gradient_fill(CL_GraphicContext gc, double x1, double y1, double x2, double y2, const CL_Gradient &color);
	static void gradient_fill(CL_GraphicContext gc, const CL_Pointd &start, const CL_Pointd &end, const CL_Gradient &gradient);
	static void gradient_fill(CL_GraphicContext gc, const CL_Rectd &rect, const CL_Gradient &gradient);

	//: Draw a circle.
	static void circle(CL_GraphicContext gc, double center_x, double center_y, double radius, const CL_Colord &color);
	static void circle(CL_GraphicContext gc, const CL_Pointd &center, double radius, const CL_Colord &color);

	static void gradient_circle(CL_GraphicContext gc, const CL_Pointd &center, double radius, const CL_Gradient &gradient);
	static void gradient_circle(CL_GraphicContext gc, const CL_Pointd &center, const CL_Pointd &centergradient, double radius, const CL_Gradient &gradient);

	//: Draw a triangle.
	static void triangle(CL_GraphicContext gc, const CL_Pointd &a, const CL_Pointd &b, const CL_Pointd &c, const CL_Colord &color);
};

#endif
