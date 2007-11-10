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

//! clanCore="CSS"
//! header=core.h

#ifndef header_css_property
#define header_css_property

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"
#include "../System/sharedptr.h"

class CL_CSSProperty_Impl;

//: Cascading Style Sheet (CSS) property.
//- !group=Core/CSS!
//- !header=core.h!
class CL_API_CORE CL_CSSProperty
{
//! Construction:
public:
	//: Constructs a CSS property.
	CL_CSSProperty();

	~CL_CSSProperty();

//! Attributes:
public:
	//: CSS priorities
	enum Priority
	{
		//: Normal priority.
		priority_normal,

		//: Important priority.
		priority_important
	};

	//: Returns the name of the property.
	const CL_String &get_name() const;

	//: Returns the value of the property.
	const CL_String &get_value() const;

	//: Returns the priority of the property.
	Priority get_priority() const;

//! Operations:
public:
	//: Sets property name.
	void set_name(const CL_String &name);

	//: Sets property value.
	void set_value(const CL_String &value);

	//: Sets property priority.
	void set_priority(Priority priority);

	bool operator ==(const CL_CSSProperty &other) const;

//! Implementation:
private:
	CL_SharedPtr<CL_CSSProperty_Impl> impl;
};

#endif
