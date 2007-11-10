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

#ifndef header_vertex_array_buffer_provider
#define header_vertex_array_buffer_provider

#include "vertex_array_buffer.h"

//: Vertex Array Buffer provider.
//- !group=Display/Display Target Interface!
//- !header=display.h!
class CL_API_DISPLAY CL_VertexArrayBufferProvider
{
//! Construction:
public:
	virtual ~CL_VertexArrayBufferProvider() { }

	//: Constructs a vertex array buffer.
	virtual void create(int size, CL_BufferUsage usage) = 0;

	virtual void create(void *data, int size, CL_BufferUsage usage) = 0;

	//: Destroys the vertex array buffer provider.
	virtual void destroy()=0;

//! Attributes:
public:
	//: Retrieves a pointer to the mapped buffer.
	virtual void *get_data() = 0;

//! Operations:
public:
	//: Maps vertex buffer into system memory.
	virtual void lock(CL_BufferAccess access) = 0;

	//: Unmaps vertex buffer.
	virtual void unlock() = 0;

	//: Uploads data to vertex array buffer.
	virtual void upload_data(int offset, void *data, int size) = 0;

//! Implementation:
private:
};

#endif
