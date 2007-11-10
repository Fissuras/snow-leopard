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

#ifndef header_buffer_control
#define header_buffer_control

#if _MSC_VER > 1000
#pragma once
#endif

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Display/compare_function.h"

//: Stencil operations	
//- !group=Display/Display 2D!
//- !header=display.h!
enum CL_StencilOp
{
	cl_stencil_keep,
	cl_stencil_zero,
	cl_stencil_replace,
	cl_stencil_incr,
	cl_stencil_decr,
	cl_stencil_invert,
	cl_stencil_incr_wrap,
	cl_stencil_decr_wrap
};

//: Drawing buffers.
enum CL_DrawBuffer
{
	cl_buffer_none,
	cl_buffer_front_left, 
	cl_buffer_front_right, 
	cl_buffer_back_left,
	cl_buffer_back_right,
	cl_buffer_front,
	cl_buffer_back, 
	cl_buffer_left, 
	cl_buffer_right, 
	cl_buffer_front_and_back, 
	cl_buffer_aux0,
	cl_buffer_aux1,
	cl_buffer_aux2,
	cl_buffer_aux3
};

class CL_BufferControl_Impl;

//: Container class for states related to reading, writing and tests performed on buffers.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_BufferControl
{
//! Construction:
public:
	//: Constructs a buffer control description object.
	CL_BufferControl();

	virtual ~CL_BufferControl();

//! Attributes:
public:
	//: Returns true if stencil test is enabled.
	bool is_stencil_test_enabled() const;

	//: Returns the stencil compare function for front facing polygons, points, lines and bitmaps.
	CL_CompareFunction get_stencil_compare_func_front() const;

	//: Returns the stencil compare function for back facing polygons.
	CL_CompareFunction get_stencil_compare_func_back() const;

	//: Returns the stencil compare reference for front facing polygons, points, lines and bitmaps
	int get_stencil_compare_reference_front() const;

	//: Returns the stencil compare reference for back facing polygons.
	int get_stencil_compare_reference_back() const;

	//: Returns the stencil operation to perform when test fails for front facing polygons, points, lines and bitmaps
	CL_StencilOp get_stencil_fail_front() const;

	//: Returns the stencil operation to perform when test fails for back facing polygons.
	CL_StencilOp get_stencil_fail_back() const;
	
	//: Returns the stencil operation to perform when test passes for front facing polygons, points, lines and bitmaps
	CL_StencilOp get_stencil_pass_depth_pass_front() const;

	//: Returns the stencil operation to perform when test passes for back facing polygons.
	CL_StencilOp get_stencil_pass_depth_pass_back() const;

	//: Returns the stencil operation to perform when depth test passes but stencil test fails for front facing polygons, points, lines and bitmaps
	CL_StencilOp get_stencil_pass_depth_fail_front() const;

	//: Returns the stencil operation to perform when depth test passes but stencil test fails for back facing polygons.
	CL_StencilOp get_stencil_pass_depth_fail_back() const;

	//: Returns the stencil comparation mask for front facing polygons, points, lines and bitmaps.
	unsigned char get_stencil_compare_mask_front() const;

	//: Returns the stencil comparation mask for back facing polygons.
	unsigned char get_stencil_compare_mask_back() const;

	//: Returns the stencil write mask for front facing polygons, points, lines and bitmaps.
	unsigned char get_stencil_write_mask_front() const;

	//: Returns the stencil write mask for back facing polygons.
	unsigned char get_stencil_write_mask_back() const;

	//: Returns true if alpha test is enabled.
	bool is_alpha_test_enabled() const;

	//: Returns the alpha test comparation reference value.
	float get_alpha_compare_reference() const;

	//: Returns the alpha test compare function.
	CL_CompareFunction get_alpha_compare_function() const;

	//: Returns true if the depth test is enabled.
	bool is_depth_test_enabled() const;
	
	//: Returns true if depth writing is enabled.
	bool is_depth_write_enabled() const;

	//: Returns the depth test function.
	CL_CompareFunction get_depth_compare_function() const;

	//: Retrieves which color components are write enabled.
	void is_color_write_enabled(bool &red, bool &green, bool &blue, bool &alpha) const;
	
	//: Returns the used draw buffer.
	CL_DrawBuffer get_draw_buffer() const;

//! Operations:
public:
	//: Enables/disables stencil testing.
	void enable_stencil_test(bool enabled);

	//: Set stencil compare function.
	void set_stencil_compare_func(CL_CompareFunction front, CL_CompareFunction back);

	//: Set stencil compare reference values.
	void set_stencil_compare_reference(int front_ref, int back_ref);

	//: Set stencil write masks.
	void set_stencil_write_mask(unsigned char front_facing_mask, unsigned char back_facing_mask);

	//: Set stencil failed test operations.
	void set_stencil_fail(CL_StencilOp front, CL_StencilOp back);

	//: Set stencil passed test operations.
	void set_stencil_pass_depth_pass(CL_StencilOp front, CL_StencilOp back);

	//: Set stencil passed depth test but failed stencil test operations.
	void set_stencil_pass_depth_fail(CL_StencilOp front, CL_StencilOp back);

	//: Set stencil comparation masks.
	void set_stencil_compare_mask(int front_mask, int back_mask);

	//: Enables/disables alpha testing.
	void enable_alpha_test(bool value);

	//: Set alpha comparation reference value.
	void set_alpha_compare_reference(float alpha_compare_reference);

	//: Set alpha test function.
	void set_alpha_compare_function(CL_CompareFunction func);

	//: Enables/disables depth testing.
	void enable_depth_test(bool enabled);

	//: Enables/disables depth writing.
	void enable_depth_write(bool enabled);

	//: Set depth test function.
	void set_depth_compare_function(CL_CompareFunction func);

	//: Enable/disable writing to the color buffer
	void enable_color_write(bool enabled);

	void enable_color_write(bool red, bool green, bool blue, bool alpha);

	//: Set used draw buffer.
	void set_draw_buffer(CL_DrawBuffer buffer);

//! Implementation:
private:
	CL_SharedPtr<CL_BufferControl_Impl> impl;
};

#endif
