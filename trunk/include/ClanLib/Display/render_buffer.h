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

#ifndef header_render_buffer
#define header_render_buffer

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../GL/opengl_wrap.h"

class CL_RenderBuffer;
class CL_GraphicContext;
class CL_RenderBufferProvider;
class CL_RenderBuffer_Impl;

//: Render-buffer object class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_RenderBuffer
{
//! Construction:
public:
	//: Constructs a render buffer.
	CL_RenderBuffer();

	CL_RenderBuffer(CL_GraphicContext context, int width, int height, int format = CL_RGBA);

//! Attributes:
public:
	CL_RenderBufferProvider *get_provider() const;

//! Operations:
public:

//! Implementation:
private:
	CL_SharedPtr<CL_RenderBuffer_Impl> impl;
};

#endif
