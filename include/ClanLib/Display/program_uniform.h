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

#ifndef header_program_uniform
#define header_program_uniform

#include "../Core/System/sharedptr.h"

#include "api_display.h"

class CL_ProgramUniform_Impl;


//: OpenGL program object uniform variable.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_ProgramUniform
{
//! Construction:
public:
	//: Constructs a program uniform.
	//param name: Uniform name.
	//param size: Size of uniform.
	//param type: OpenGL uniform type.
	CL_ProgramUniform();
	
	CL_ProgramUniform(const CL_StringRef &name, int size, int type);

	~CL_ProgramUniform();

//! Attributes:
public:
	//: Get uniform name.
	const CL_StringRef &get_name() const;

	//: Get uniform OpenGL type.
	int get_type() const;

	//: Get uniform size.
	int get_size() const;
	
//! Operations:
public:

//! Implementation:
private:
	CL_SharedPtr<CL_ProgramUniform_Impl> impl;
};

#endif
