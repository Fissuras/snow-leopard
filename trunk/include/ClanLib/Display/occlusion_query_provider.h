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

//! clanDisplay="Input"
//! header=display.h

#ifndef header_occlusion_query_provider
#define header_occlusion_query_provider

#if _MSC_VER > 1000
#pragma once
#endif

#include "api_display.h"
#include "../Core/System/sharedptr.h"

//: Occlusion query provider.
//- !group=Display/Display Target Interface!
//- !header=display.h!
class CL_API_DISPLAY CL_OcclusionQueryProvider
{
//! Construction:
public: 
	virtual ~CL_OcclusionQueryProvider() { return; }

//! Attributes:
public:
	//: Returns true if the GPU is ready to return the result.
	virtual bool is_result_ready() const = 0;

	//: Returns the result of the occlusion query.
	virtual int get_result() const = 0;

//! Operations:
public:
	//: Start occlusion query.
	virtual void begin() = 0;

	//: Finish occlusion query.
	virtual void end() = 0;

	//: Create occlusion query object.
	virtual void create() = 0;

	//: Destroy occlusion query provider.
	virtual void destroy() = 0;
	
//! Implementation:
private:
};

#endif
