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

#ifndef header_element_array_buffer
#define header_element_array_buffer

#include "../Core/System/sharedptr.h"
#include "../Display/graphic_context.h"
#include "../Display/api_display.h"
#include "vertex_array_buffer.h"

class CL_ElementArrayBufferProvider;
class CL_ElementArrayBuffer_Impl;

//: Element Array Buffer
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_ElementArrayBuffer
{
//! Construction:
public:
	//: Constructs a element array buffer.
	CL_ElementArrayBuffer();

	CL_ElementArrayBuffer(CL_GraphicContext gc, int size, CL_BufferUsage usage = cl_usage_static_draw);

	CL_ElementArrayBuffer(CL_GraphicContext gc, void *data, int size, CL_BufferUsage usage = cl_usage_static_draw);

	virtual ~CL_ElementArrayBuffer();

//! Attributes:
public:
	//: Retrieves a pointer to the mapped buffer.
	void *get_data();

	CL_ElementArrayBufferProvider *get_provider() const;

//! Operations:
public:
	//: Handle comparison operator.
	bool operator==(const CL_ElementArrayBuffer &other) const;

	//: Maps element buffer into system memory.
	void lock(CL_BufferAccess access);

	//: Unmaps element buffer.
	void unlock();

	//: Uploads data to element array buffer.
	void upload_data(int offset, void *data, int size);

//! Implementation:
private:
	CL_SharedPtr<CL_ElementArrayBuffer_Impl> impl;
};

#endif
