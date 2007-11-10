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
**    Kenneth Gangstø
**    Magnus Norddahl
*/

//! clanDisplay="Display"
//! header=display.h

#ifndef header_texture_group
#define header_texture_group

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/Math/size.h"

class CL_Subtexture;
class CL_TextureGroup_Impl;
class CL_GraphicContext;

//: Texture grouping class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_TextureGroup
{
//! Enumerations:
public:
	//: Texture allocation policy.
	enum TextureAllocationPolicy
	{
		create_new_texture,
		search_previous_textures
	};

//! Construction:
public:
	//: Constructs a texture.
	CL_TextureGroup(CL_GraphicContext context, const CL_Size &texture_sizes);
	
	~CL_TextureGroup();

//! Attributes:
public:
	//: Returns the amount of sub-textures allocated in group.
	int get_subtexture_count() const;

	//: Returns the amount of sub-textures for a specific texture index.
	int get_subtexture_count(unsigned int texture_index) const;

	//: Returns the amount of textures used by group.
	int get_texture_count() const;

	//: Returns the texture allocation policy.
	TextureAllocationPolicy get_texture_allocation_policy() const;

//! Operations:
public:
	//: Allocate space for another sub texture.
	CL_Subtexture add(CL_GraphicContext context, const CL_Size &size);

	//: Set the texture allocation policy.
	void set_texture_allocation_policy(TextureAllocationPolicy policy);

//! Implementation:
private:
	CL_SharedPtr<CL_TextureGroup_Impl> impl;
};

#endif
