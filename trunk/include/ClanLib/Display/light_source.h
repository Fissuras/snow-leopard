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

#ifndef header_light_source
#define header_light_source

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/Math/cl_vector.h"


class CL_LightSource_Impl;

//: Light Source description.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_LightSource
{
//! Construction:
public:
	//: Constructs a light source container.
	CL_LightSource();

	~CL_LightSource();

//! Attributes:
public:
	//: Returns the intensity distribution of the light.
	//- <p>Only values in the range [0,128] are accepted. The default spot exponent is 0,
	//- resulting in uniform light distribution.</p>
	double get_spot_exponent() const;

	//: Returns the spot cutoff angle (the maximum spread angle of a light source).
	//- <p>The default spot cutoff is 180, resulting in uniform light distribution.</p>
	double get_spot_cutoff() const;

	//: Returns constant attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	double get_constant_attenuation() const;

	//: Returns linear attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	double get_linear_attenuation() const;

	//: Returns quadratic attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	double get_quadratic_attenuation() const;

	//: Returns the ambient (global light) intensity of the light.
	void get_ambient_intensity(double &red, double &green, double &blue, double &alpha) const;

	//: Returns the diffuse (spread over wide area) intensity of the light.
	void get_diffuse_intensity(double &red, double &green, double &blue, double &alpha) const;

	//: Returns the specular (mirror reflective) intensity of the light.
	void get_specular_intensity(double &red, double &green, double &blue, double &alpha) const;

	//: Returns the light position.
	CL_Vector get_position() const;

	//: Returns the light spot direction.
	CL_Vector get_spot_direction() const;

//! Operations:
public:
	//: Sets the intensity distribution of the light.
	//- <p>Only values in the range [0,128] are accepted. The default spot exponent is 0,
	//- resulting in uniform light distribution.</p>
	void set_spot_exponent(double spot_exponent);

	//: Sets the spot cutoff angle (the maximum spread angle of a light source).
	//- <p>The default spot cutoff is 180, resulting in uniform light distribution.</p>
	void set_spot_cutoff(double spot_cutoff);

	//: Sets the constant attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	void set_constant_attenuation(double constant_attenuation);

	//: Sets linear attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	void set_linear_attenuation(double linear_attenuation);

	//: Sets quadratic attenuation of the light.
	//- <p>The default attenuation factors are (1,0,0), resulting in no attenuation.</p>
	void set_quadratic_attenuation(double quadratic_attenuation);

	//: Sets the ambient (global light) intensity of the light.
	void set_ambient_intensity(double red, double green, double blue, double alpha = 1.0);

	//: Sets the diffuse (spread over wide area) intensity of the light.
	void set_diffuse_intensity(double red, double green, double blue, double alpha = 1.0);

	//: Sets the specular (mirror reflective) intensity of the light.
	void set_specular_intensity(double red, double green, double blue, double alpha = 1.0);

	//: Sets the light position.
	//- <p>The position is transformed by the modelview matrix when glLight is called
	//- (just as if it were a point), and it is stored in eye coordinates. If the w
	//- component of the position is 0.0, the light is treated as a directional source.</p>
	//- <p>Diffuse and specular lighting calculations take the lights direction, but not
	//- its actual position, into account, and attenuation is disabled. Otherwise, diffuse
	//- and specular lighting calculations are based on the actual location of the light
	//- in eye coordinates, and attenuation is enabled.</p>
	//- <p>The default position is (0,0,1,0); thus, the default light source is directional,
	//- parallel to, and in the direction of the –z axis.</p>
	void set_position(const CL_Vector &position);

	//: Sets the light spot direction.
	void set_spot_direction(const CL_Vector &spot_direction);

//! Implementation:
private:
	CL_SharedPtr<CL_LightSource_Impl> impl;
};

#endif
