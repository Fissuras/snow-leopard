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

#ifndef header_css_ruleset
#define header_css_ruleset

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"
#include "../System/sharedptr.h"
#include <vector>

class CL_CSSSelector;
class CL_CSSProperty;
class CL_CSSRuleSet_Impl;

//: Cascading Style Sheet (CSS) rule set.
//- <p>A CSS rule set is a container for CSS properties and CSS selectors
//- applying to a rule set.</p>
//- !group=Core/CSS!
//- !header=core.h!
class CL_API_CORE CL_CSSRuleSet
{
//! Construction:
public:
	//: Constructs a CSS rule set.
	CL_CSSRuleSet();

	~CL_CSSRuleSet();

//! Attributes:
public:
	//: Returns all CSS selectors defined for this rule set.
	std::vector<CL_CSSSelector> &get_selectors();

	//: Returns all CSS properties for this rule set.
	std::vector<CL_CSSProperty> &get_properties();

//! Operations:
public:
	bool operator ==(const CL_CSSRuleSet &other) const;

	//: Adds a CSS selector to the rule set.
	void add_selector(const CL_CSSSelector &selector);

	//: Adds a CSS property to the rule set.
	void add_property(const CL_CSSProperty &property);

//! Implementation:
private:
	CL_SharedPtr<CL_CSSRuleSet_Impl> impl;
};

#endif
