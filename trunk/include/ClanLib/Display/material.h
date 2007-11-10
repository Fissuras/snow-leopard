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

#ifndef header_material
#define header_material

#if _MSC_VER > 1000
#pragma once
#endif

#include "api_display.h"
#include "../Core/System/sharedptr.h"

class CL_Material_Impl;

//: Material description.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_Material
{
//! Construction:
public:
	//: Constructs a material.
	CL_Material();

	~CL_Material();

//! Attributes:
public:
	//: Returns the ambient intensity of the material.
	void get_ambient(double &red, double &green, double &blue, double &alpha) const;

	//: Returns the diffuse (spread over wide area) intensity of the material.
	void get_diffuse(double &red, double &green, double &blue, double &alpha) const;

	//: Returns the specular (mirror reflective) intensity of the material.
	void get_specular(double &red, double &green, double &blue, double &alpha) const;

	//: Returns the emission of the material.
	void get_emission(double &red, double &green, double &blue, double &alpha) const;

	//: Returns the shininess of the material.
	double get_shininess() const;

//! Operations:
public:
	//: Set the ambient intensity of the material.
	void set_ambient(double red, double green, double blue, double alpha);

	//: Set the diffuse (spread over wide area) intensity of the material.
	void set_diffuse(double red, double green, double blue, double alpha);

	//: Set the specular (mirror reflective) intensity of the material.
	void set_specular(double red, double green, double blue, double alpha);

	//: Set the combined ambient and diffuse intensity of the material.
	void set_ambient_and_diffuse(double red, double green, double blue, double alpha);

	//: Set the emission of the material.
	void set_emission(double red, double green, double blue, double alpha);

	//: Set the shininess of the material.
	void set_shininess(double value);

//! Implementation:
private:
	CL_SharedPtr<CL_Material_Impl> impl;
};

#endif
