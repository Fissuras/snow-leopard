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
**    Harry Storbacka
*/

//! clanDisplay="Display"
//! header=display.h

#ifndef header_program_object_provider
#define header_program_object_provider

#include <vector>
class CL_ProgramAttribute;
class CL_ProgramUniform;
class CL_ShaderObject;

//: Program Object provider.
//- !group=Display/Display Target Interface!
//- !header=display.h!
class CL_ProgramObjectProvider
{
//! Construction:
public:
	virtual ~CL_ProgramObjectProvider()
	{
	}

	virtual void destroy()=0;

//! Attributes:
public:
	//: Returns the OpenGL program object handle.
	virtual unsigned int get_handle() const=0;

	//: Returns true if the link succeeded.
	virtual bool get_link_status() const=0;
	
	//: Returns true if validation succeeded.
	virtual bool get_validate_status() const=0;

	//: Returns the current info log for the program object.
	virtual CL_String get_info_log() const=0;
	
	//: Returns the count of active attributes.
	virtual int get_attribute_count() const=0;
	
	//: Returns the shaders used in this program.
	virtual std::vector<CL_ShaderObject> get_shaders() const=0;

	//: Returns the active attributes.
	virtual std::vector<CL_ProgramAttribute> get_attributes() const=0;
	
	//: Returns the location of a named active attribute.
	virtual int get_attribute_location(const CL_StringRef &name) const=0;
	
	//: Returns the count of active uniform variables.
	virtual int get_uniform_count() const=0;

	//: Returns the active uniforms.
	virtual std::vector<CL_ProgramUniform> get_uniforms() const=0;

	//: Returns the location of a named uniform variable.
	virtual int get_uniform_location(const CL_StringRef &name) const=0;

//! Operations:
public:
	//: Add shader to program object.
	virtual void attach(const CL_ShaderObject &obj)=0;

	//: Remove shader from program object.
	virtual void detach(const CL_ShaderObject &obj)=0;

	//: Bind attribute to specific location.
	//- <p>This function must be called before linking.</p>
	virtual void bind_attribute_location(int index, const CL_StringRef &name)=0;

	//: Link program.
	//- <p>If the linking fails, get_link_status() will return false and
	//- get_info_log() will return the link log.</p>
	virtual void link()=0;

	//: Validate program.
	//- <p>If the validation fails, get_validate_status() will return
	//- false and get_info_log() will return the validation log.</p>
	virtual void validate()=0;

	//: Set uniform variable(s).
	virtual void set_uniform(const CL_StringRef &name, int)=0;
	virtual void set_uniform(const CL_StringRef &name, int, int)=0;
	virtual void set_uniform(const CL_StringRef &name, int, int, int)=0;
	virtual void set_uniform(const CL_StringRef &name, int, int, int, int)=0;
	virtual void set_uniform(const CL_StringRef &name, int size, int count, int *data)=0;
	virtual void set_uniform(const CL_StringRef &name, float)=0;
	virtual void set_uniform(const CL_StringRef &name, float, float)=0;
	virtual void set_uniform(const CL_StringRef &name, float, float, float)=0;
	virtual void set_uniform(const CL_StringRef &name, float, float, float, float)=0;
	virtual void set_uniform(const CL_StringRef &name, int size, int count, float *data)=0;

	//: Set uniform matrices.
	virtual void set_uniform_matrix(const CL_StringRef &name, int size, int count, bool transpose, float *data)=0;

//! Implementation:
private:

};

#endif
