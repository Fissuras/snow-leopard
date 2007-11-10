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
**    Harry Storbacka
*/

//! clanDisplay="Display"
//! header=display.h

#ifndef header_render_buffer_provider
#define header_render_buffer_provider

#include "api_display.h"

//: Interface for implementing a CL_RenderBuffer target.
//- !group=Display/Display Target Interface!
//- !header=display.h!
class CL_API_DISPLAY CL_RenderBufferProvider
{
//! Construction:
public:
	virtual ~CL_RenderBufferProvider() {}

//! Attributes:
public:

//! Operations:
public:
	//: Create a render buffer image with the specified dimensions.
	virtual void create(int width, int height, int format) = 0;

	//: Destroys the provider.
	virtual void destroy() = 0;

//! Implementation:
private:
};

#endif
