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

#ifndef header_css_document
#define header_css_document

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"
#include "../System/sharedptr.h"
#include <vector>

class CL_IODevice;
class CL_VirtualFileSystem;
class CL_CSSImport;
class CL_CSSRuleSet;
class CL_CSSDocument_Impl;

//: Cascading Style Sheet (CSS) document.
//- <p>Document class for cascading style sheets (CSS).  Provides access to
//- all import directives and rule sets available in a CSS document.</p>
//- !group=Core/CSS!
//- !header=core.h!
class CL_API_CORE CL_CSSDocument
{
//! Construction:
public:
	//: Constructs a cascading style sheet document.
	CL_CSSDocument();

	~CL_CSSDocument();

//! Attributes:
public:
	//: Retrieves all CSS import directives.
	std::vector<CL_CSSImport> &get_imports();

	//: Retrieves all CSS rule set descriptions.
	std::vector<CL_CSSRuleSet> &get_rulesets();

//! Operations:
public:
	//: Find rule sets that match a given element.
	//- <p>The syntax of element is the same as specifying contextual elements
	//- in a CSS selector, i.e. 'body div.class a#id:link'.</p>
	//- <p>The returned list is sorted with the most preferred ruleset returned
	//- first in the list.</p>
	std::vector<CL_CSSRuleSet> select(const CL_StringRef &element);

	//: Add CSS import directive to document.
	void add_import(CL_CSSImport import);

	//: Add CSS rule set to document.
	void add_ruleset(CL_CSSRuleSet ruleset);

	//: Remove CSS import directive from document.
	void remove_import(CL_CSSImport import);

	//: Remove CSS rule set from document.
	void remove_ruleset(CL_CSSRuleSet ruleset);

	//: Load CSS document from an input source.
	void load(const CL_StringRef &path, CL_IODevice &input);

	//: Save CSS document to an input source.
	void save(CL_IODevice &output);

//! Implementation:
private:
	CL_SharedPtr<CL_CSSDocument_Impl> impl;
};

#endif
