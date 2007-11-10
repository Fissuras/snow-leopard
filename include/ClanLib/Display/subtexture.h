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

#ifndef header_subtexture
#define header_subtexture

#include "api_display.h"
#include "../Core/System/sharedptr.h"

class CL_Rect;
class CL_Texture;
class CL_Subtexture_Impl;

//: Sub-texture description.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_Subtexture
{
//! Construction:
public:
	//: Constructs a sub texture description.
	CL_Subtexture();

	CL_Subtexture(CL_Texture texture, const CL_Rect &geometry);

	~CL_Subtexture();

//! Attributes:
public:
	//: Returns the texture.
	CL_Texture get_texture();

	//: Returns the part of the texture used by this object.
	CL_Rect get_geometry() const;

//! Operations:
public:

//! Implementation:
private:
	CL_SharedPtr<CL_Subtexture_Impl> impl;
};

#endif
