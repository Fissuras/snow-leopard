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
**    Kenneth Gangstoe
**    Harry Storbacka
*/

//! clanDisplay="Display"
//! header=display.h

#ifndef header_gradient
#define header_gradient

#if _MSC_VER > 1000
#pragma once
#endif

#include "api_display.h"
#include "color.h"

//: Colorgradient description class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_Gradient
{
//! Construction:
public:
	//: Constructs a color gradient.
	//param top_left: Top left color component.
	//param top_right: Top right color component.
	//param bottom_left: Bottom left color component.
	//param bottom_right: Bottom right color component.
	CL_Gradient()
	{
	}

	CL_Gradient(const CL_Colord &top_left, const CL_Colord &top_right,
		const CL_Colord &bottom_left, const CL_Colord &bottom_right)
	: top_left(top_left), top_right(top_right), bottom_left(bottom_left),
	  bottom_right(bottom_right)
	{
	}

	CL_Gradient(const CL_Colord &first_color, const CL_Colord &second_color)
	: top_left(first_color), top_right(first_color), bottom_left(second_color),
	  bottom_right(second_color)
	{
	}

//! Attributes:
public:
	//: Color of top left corner of gradient.
	CL_Colord top_left;

	//: Color of top right corner of gradient.
	CL_Colord top_right;

	//: Color of bottom left corner of gradient.
	CL_Colord bottom_left;

	//: Color of bottom right corner of gradient.
	CL_Colord bottom_right;

	//: Compares gradient to another one.
	bool operator==(const CL_Gradient &other) const
	{
		return top_left == other.top_left && top_right==other.top_right && 
		       bottom_left == other.bottom_left && bottom_right == bottom_right;
	}

	//: Compares gradient to another one.
	bool operator!=(const CL_Gradient &other) const
	{
		return !(*this == other);
	}
};

#endif
