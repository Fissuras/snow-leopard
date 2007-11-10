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

#ifndef header_frame_buffer_provider
#define header_frame_buffer_provider

#include "api_display.h"
#include "frame_buffer.h"

class CL_RenderBuffer;
class CL_Texture;

//: Interface for implementing a CL_FrameBuffer target.
//- !group=Display/Display Target Interface!
//- !header=display.h!
class CL_API_DISPLAY CL_FrameBufferProvider
{
//! Construction:
public:
	virtual ~CL_FrameBufferProvider() { return; }

//! Attributes:
public:
	virtual CL_Size get_attachment_size(int buffer_id) const = 0;

//! Operations:
public:
	//: Destroys the provider.
	virtual void destroy() = 0;

	virtual void attach_color_buffer(int color_buffer, const CL_RenderBuffer &render_buffer) = 0;

	virtual void attach_color_buffer(int color_buffer, const CL_Texture &texture, int level = 0, int zoffset = 0) = 0;

	virtual void attach_color_buffer(int color_buffer, const CL_Texture &texture, CL_TextureSubtype subtype, int level = 0, int zoffset = 0) = 0;

	virtual void detach_color_buffer(int color_buffer) = 0;

	virtual void attach_stencil_buffer(const CL_RenderBuffer &render_buffer) = 0;

	virtual void detach_stencil_buffer() = 0;

	virtual void attach_depth_buffer(const CL_RenderBuffer &render_buffer) = 0;

	virtual void attach_depth_buffer(const CL_Texture &texture, CL_TextureSubtype subtype, int level = 0, int zoffset = 0) = 0;

	virtual void detach_depth_buffer() = 0;


//! Implementation:
private:
};

#endif
