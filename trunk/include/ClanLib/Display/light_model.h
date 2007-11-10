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

//! clanDisplay="Display"
//! header=display.h

#ifndef header_light_model
#define header_light_model

#if _MSC_VER > 1000
#pragma once
#endif

#include "api_display.h"
#include "../Core/System/sharedptr.h"

class CL_LightModel_Impl;

//: Light model color control
//- !group=Display/Display!
//- !header=display.h!
enum CL_ColorControl
{
	cl_color_control_single_color,
	cl_color_control_separate_specular_color
};

//: Light model description.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_LightModel
{
//! Construction:
public:
	//: Constructs a light model.
	CL_LightModel();

	~CL_LightModel();

//! Attributes:
public:
	//: Returns true if lighting is enabled.
	bool is_lighting_enabled() const;

	//: Returns true if local viewer is enabled.
	bool is_local_viewer() const;

	//: Returns true if two sided materials are being used.
	bool get_two_sided_materials() const;

	//: Returns the current color control being used.
	CL_ColorControl get_color_control() const;

	//: Returns true if flat shading is enabled.
	bool get_flat_shading() const;

	//: Returns the scene global ambient light.
	void get_scene_ambient_light(double &red, double &green, double &blue, double &alpha) const;

//! Operations:
public:
	//: Enables or disables lighting calculations.
	void enable_lighting(bool value);

	//: Enables or disables local viewer light model.
	void set_local_viewer(bool value);

	//: Controls if the lighting model uses different materials for front and back facing faces.
	void set_two_sided_materials(bool value);

	//: Controls how primary and secondary colors are calculated.
	void set_color_control(CL_ColorControl value);

	//: Enables if polygons are to be flat shaded from lighting calculations.
	void set_flat_shading(bool value);

	//: Sets the scene global ambient light.
	void set_scene_ambient_light(double red, double green, double blue, double alpha);

//! Implementation:
private:
	CL_SharedPtr<CL_LightModel_Impl> impl;
};

#endif
