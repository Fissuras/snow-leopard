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
**    Kenneth Gangstø
*/

//! clanDisplay="Display"
//! header=display.h

#ifndef header_program_object
#define header_program_object

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/Text/string_types.h"
#include "../Core/IOData/virtual_directory.h"
#include "graphic_context.h"

class CL_ShaderObject;
class CL_ProgramAttribute;
class CL_ProgramUniform;
class CL_ProgramObject_Impl;
class CL_GraphicContext;
class CL_ResourceManager;

//: OpenGL Program Object
//- !group=Display/Display!
//- !header=display.h!
//- <p>The shader objects that are to be used by programmable stages of
//- OpenGL are collected together to form a program object. CL_ProgramObject
//- is ClanLib's C++ interface to OpenGL program objects.</p>
//- <p>To construct a program object programatically, the procedure is
//- as follows:</p>
//- <pre>
//- CL_ShaderObject vertex_shader(cl_shadertype_vertex, vertex_glsl_sourcecode);
//- CL_ShaderObject fragment_shader(cl_shadertype_fragment, fragment_glsl_sourcecode);
//- CL_ProgramObject program;
//- program.attach(vertex_shader);
//- program.attach(fragment_shader);
//- program.link();
//- </pre>
//- <p>For more information about program objects, see the OpenGL 2.0
//- specification at <a href="http://www.opengl.org">www.opengl.org</a>. Documentation
//- about the OpenGL Shader Language (GLSL) is also available from www.opengl.org.</p>
class CL_API_DISPLAY CL_ProgramObject
{
//! Construction:
public:
	//: Construct OpenGL program object.
	//param resource_id: Name of program object resource.
	//param vdir: Virtual directory holding the file to load.
	CL_ProgramObject();
	
	CL_ProgramObject(CL_GraphicContext &gc);

	static CL_ProgramObject load(CL_GraphicContext &gc, const CL_StringRef &resource_id, CL_ResourceManager *resman);

	static CL_ProgramObject load(CL_GraphicContext &gc, const CL_StringRef &vertex_filename, const CL_StringRef &fragment_filename, CL_VirtualDirectory &directory);

	static CL_ProgramObject load(CL_GraphicContext &gc, const CL_StringRef &fragment_filename, CL_VirtualDirectory &directory);

	static CL_ProgramObject load_and_link(CL_GraphicContext &gc, const CL_StringRef &vertex_filename, const CL_StringRef &fragment_filename, CL_VirtualDirectory &directory);

	static CL_ProgramObject load_and_link(CL_GraphicContext &gc, const CL_StringRef &fragment_filename, CL_VirtualDirectory &directory);

	virtual ~CL_ProgramObject();

//! Attributes:
public:
	//: Returns true if the Program object is a dummy
	bool is_null() const;

	//: Returns the OpenGL program object handle.
	unsigned int get_handle() const;

	//: Returns the shaders attached to the program object.	
	std::vector<CL_ShaderObject> get_shaders() const;

	//: Returns the current info log for the program object.
	CL_String get_info_log() const;
	
	//: Returns the count of active attributes.
	int get_attribute_count() const;
	
	//: Returns the active attributes.
	std::vector<CL_ProgramAttribute> get_attributes() const;
	
	//: Returns the location of a named active attribute.
	int get_attribute_location(const CL_StringRef &name) const;
	
	//: Returns the count of active uniform variables.
	int get_uniform_count() const;

	//: Returns the active uniforms.
	std::vector<CL_ProgramUniform> get_uniforms() const;

	//: Returns the location of a named uniform variable.
	int get_uniform_location(const CL_StringRef &name) const;
	
//! Operations:
public:
	//: Add shader to program object.
	void attach(const CL_ShaderObject &obj);

	//: Remove shader from program object.
	void detach(const CL_ShaderObject &obj);

	//: Bind attribute to specific location.
	//- <p>This function must be called before linking.</p>
	void bind_attribute_location(int index, const CL_StringRef &name);

	//: Link program.
	//- <p>If the linking fails, get_info_log() will return the link log.</p>
	bool link();

	//: Validate program.
	//- <p>If the validation fails, get_info_log() will return the validation log.</p>
	bool validate();

	//: Set uniform variable(s).
	void set_uniform(const CL_StringRef &name, int);
	void set_uniform(const CL_StringRef &name, int, int);
	void set_uniform(const CL_StringRef &name, int, int, int);
	void set_uniform(const CL_StringRef &name, int, int, int, int);
	void set_uniform(const CL_StringRef &name, int size, int count, int *data);
	void set_uniform(const CL_StringRef &name, float);
	void set_uniform(const CL_StringRef &name, float, float);
	void set_uniform(const CL_StringRef &name, float, float, float);
	void set_uniform(const CL_StringRef &name, float, float, float, float);
	void set_uniform(const CL_StringRef &name, int size, int count, float *data);

	//: Set uniform matrices.
	void set_uniform_matrix(const CL_StringRef &name, int size, int count, bool transpose, float *data);

//! Implementation:
private:
	CL_SharedPtr<CL_ProgramObject_Impl> impl;
};

#endif
