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

#ifndef header_vertex_array_buffer
#define header_vertex_array_buffer

#include "../Core/System/sharedptr.h"
#include "../Display/graphic_context.h"
#include "../Display/api_display.h"

//: Vertex Array Buffer usage enum
//- !group=Display/Display Target Interface!
//- !header=display.h!
enum CL_BufferUsage
{
	cl_usage_stream_draw,
	cl_usage_stream_read,
	cl_usage_stream_copy,
	cl_usage_static_draw,
	cl_usage_static_read,
	cl_usage_static_copy,
	cl_usage_dynamic_draw,
	cl_usage_dynamic_read,
	cl_usage_dynamic_copy
};

//: Vertex Array Buffer access enum
//- !group=Display/Display Target Interface!
//- !header=display.h!
enum CL_BufferAccess
{
	cl_access_read_only,
	cl_access_write_only,
	cl_access_read_write
};

class CL_VertexArrayBufferProvider;
class CL_VertexArrayBuffer_Impl;

//: Vertex Array Buffer
//- !group=Display/Display Target Interface!
//- !header=display.h!
class CL_API_DISPLAY CL_VertexArrayBuffer
{
//! Construction:
public:
	//: Constructs a vertex array buffer.
	CL_VertexArrayBuffer();

	CL_VertexArrayBuffer(CL_GraphicContext gc, int size, CL_BufferUsage usage = cl_usage_static_draw);

	CL_VertexArrayBuffer(CL_GraphicContext gc, void *data, int size, CL_BufferUsage usage = cl_usage_static_draw);

	virtual ~CL_VertexArrayBuffer();

//! Attributes:
public:
	//: Retrieves a pointer to the mapped buffer.
	void *get_data();

	CL_VertexArrayBufferProvider *get_provider() const;

//! Operations:
public:
	//: Handle comparison operator.
	bool operator==(const CL_VertexArrayBuffer &other) const;

	//: Maps vertex buffer into system memory.
	void lock(CL_BufferAccess access);

	//: Unmaps vertex buffer.
	void unlock();

	//: Uploads data to vertex array buffer.
	void upload_data(int offset, void *data, int size);

//! Implementation:
private:
	CL_SharedPtr<CL_VertexArrayBuffer_Impl> impl;
};

#endif
