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

#ifndef header_blend_mode
#define header_blend_mode

#if _MSC_VER > 1000
#pragma once
#endif

#include "api_display.h"
#include "../Core/System/sharedptr.h"

class CL_Colord;
class CL_BlendMode_Impl;

//: Blending functions.
//- !group=Display/Display!
//- !header=display.h!
enum CL_BlendFunc
{
	//: source or destination (0, 0, 0, 0)
	cl_blend_zero,

	//: source or destination (1, 1, 1, 1)
	cl_blend_one,

	//: source (Rd, Gd, Bd, Ad)
	cl_blend_dest_color,

	//: destination (Rs, Gs, Bs, As)
	cl_blend_src_color,

	//: source (1, 1, 1, 1) - (Rd, Gd, Bd, Ad)
	cl_blend_one_minus_dest_color,

	//: destination (1, 1, 1, 1) - (Rs, Gs, Bs, As)
	cl_blend_one_minus_src_color,

	//: source or destination (As, As, As, As)
	cl_blend_src_alpha,

	//: source or destination (1, 1, 1, 1) - (As, As, As, As)
	cl_blend_one_minus_src_alpha,

	//: source or destination (Ad, Ad, Ad, Ad)
	cl_blend_dest_alpha,

	//: source or destination (1, 1, 1, 1) - (Ad, Ad, Ad, Ad)
	cl_blend_one_minus_dest_alpha,

	//: source (f, f, f, 1) - f = min(As, 1 - Ad)
	cl_blend_src_alpha_saturate,

	//: source or destination (Rc, Gc, Bc, Ac)
	cl_blend_constant_color,

	//: source or destination (1, 1, 1, 1) - (Rc, Gc, Bc, Ac)
	cl_blend_one_minus_constant_color,

	//: source or destination (Ac, Ac, Ac, Ac)
	cl_blend_constant_alpha,

	//: source or destination (1, 1, 1, 1) - (Ac, Ac, Ac, Ac)
	cl_blend_one_minus_constant_alpha
};

//: Blending equations.
//- !group=Display/Display!
//- !header=display.h!
enum CL_BlendEquation
{
	cl_blend_equation_add,
	cl_blend_equation_subtract,
	cl_blend_equation_reverse_subtract,
	cl_blend_equation_min,
	cl_blend_equation_max,
	cl_blend_equation_logic_op
};

//: Blend mode description.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_BlendMode
{
//! Construction:
public: 
	CL_BlendMode();

	~CL_BlendMode();

//! Attributes:
public:
	//: Returns the constant color used in the blend equations.
	const CL_Colord &get_blend_color() const;

	//: Returns the color blend equation.
	CL_BlendEquation get_blend_equation() const;

	//: Returns the alpha blend equation.
	CL_BlendEquation get_blend_equation_alpha() const;

	//: Returns the source color blend function.
	CL_BlendFunc get_blend_function_src() const;

	//: Returns the destination color blend function.
	CL_BlendFunc get_blend_function_dest() const;

	//: Returns the source alpha blend function.
	CL_BlendFunc get_blend_function_src_alpha() const;

	//: Returns the destination alpha blend function.
	CL_BlendFunc get_blend_function_dest_alpha() const;

	//: Returns true if blending mode is enabled.
	bool is_blend_enabled() const;

//! Operations:
public: 
	//: Enable/Disable blending
	void enable_blending(bool value);

	//: Set the constant color used in the blend equations
	void set_blend_color(const CL_Colord &color); 

	//: Set the constant color used in the blend equations
	void set_blend_equation(CL_BlendEquation color, CL_BlendEquation alpha);

	//: Set the blend functions
	void set_blend_function(CL_BlendFunc src, CL_BlendFunc dest, CL_BlendFunc src_alpha, CL_BlendFunc dest_alpha);

//! Implementation:
private:
	CL_SharedPtr<CL_BlendMode_Impl> impl;
};

#endif
