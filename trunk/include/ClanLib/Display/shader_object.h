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
**    Kenneth Gangst�
*/

//! clanDisplay="Display"
//! header=display.h

#ifndef header_shader_object
#define header_shader_object

#include "../Core/System/sharedptr.h"
#include "../Core/IOData/virtual_directory.h"
#include "../Display/graphic_context.h"
#include "../Display/api_display.h"
#include <vector>

class CL_ResourceManager;
class CL_ShaderObject_Impl;

//: Shader Type
//- !group=Display/Display!
//- !header=display.h!
enum CL_ShaderType
{
	cl_shadertype_vertex,
	cl_shadertype_fragment
};

//: Shader Object
//- !group=Display/Display!
//- !header=display.h!
//- <p>The source code that makes up a program that gets executed by one of
//- the programmable stages is encapsulated in one or more shader
//- objects. Shader objects are attached to a program objects to form a
//- programmable setup. CL_ShaderObject is ClanLib's C++ interface to OpenGL
//- shader objects.</p>
class CL_API_DISPLAY CL_ShaderObject
{
//! Construction:
public:
	//: Constructs an OpenGL shader.
	//param type: Shader type. Can be cl_shadertype_vertex or cl_shadertype_fragment.
	//param source: Shader source code, in OpenGL Shader Language (GLSL).
	//param sources: Shader source code as list of strings.
	//param gc_provider: Graphics context in which to create the shader object
	//param resource_id: Name of shader object resource.
	//param resources: Resource Manager providing resource.
	CL_ShaderObject(CL_GraphicContext &gc);

	CL_ShaderObject(CL_GraphicContext &gc, CL_ShaderType type, const CL_StringRef &source);
	
	CL_ShaderObject(CL_GraphicContext &gc, CL_ShaderType type, const std::vector<CL_StringRef> &sources);
	
	static CL_ShaderObject load(CL_GraphicContext &gc, const CL_StringRef &resource_id, CL_ResourceManager *resources);

	static CL_ShaderObject load(CL_GraphicContext &gc, CL_ShaderType type, const CL_StringRef &filename, CL_VirtualDirectory &directory);

	static CL_ShaderObject load_and_compile(CL_GraphicContext &gc, CL_ShaderType type, const CL_StringRef &filename, CL_VirtualDirectory &directory);

	virtual ~CL_ShaderObject();

//! Attributes:
public:
	//: Returns the OpenGL shader handle.
	unsigned int get_handle() const;
	
	//: Gets the shader type.
	CL_ShaderType get_shader_type() const;

	//: Get shader object's info log.
	CL_String get_info_log() const;

	//: Get shader source code.
	CL_String get_shader_source() const;
	
//! Operations:
public:
	//: Handle comparision operator.
	bool operator==(const CL_ShaderObject &other) const;

	//: Compile program.
	//- <p>If the compiling fails, get_info_log() will return the compile log.</p>
	bool compile();

//! Implementation:
private:
	CL_SharedPtr<CL_ShaderObject_Impl> impl;
};

#endif
