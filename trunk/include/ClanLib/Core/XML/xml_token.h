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

//! clanCore="XML"
//! header=core.h

#ifndef header_xml_token
#define header_xml_token

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"
#include "../Text/string_types.h"
#include <vector>
#include <utility>

//: XML token in a XML file.
//- !group=Core/XML!
//- !header=core.h!
class CL_API_CORE CL_XMLToken
{
//! Construction:
public:
	CL_XMLToken() : type(NULL_TOKEN), variant(SINGLE)
	{
	}

//! Attributes:
public:
	enum TokenType
	{
		NULL_TOKEN                     = 0,
		ELEMENT_TOKEN                  = 1,
		TEXT_TOKEN                     = 3,
		CDATA_SECTION_TOKEN            = 4,
		ENTITY_REFERENCE_TOKEN         = 5,
		ENTITY_TOKEN                   = 6,
		PROCESSING_INSTRUCTION_TOKEN   = 7,
		COMMENT_TOKEN                  = 8,
		DOCUMENT_TYPE_TOKEN            = 10,
		NOTATION_TOKEN                 = 12
	};
	
	enum TokenVariant
	{
		BEGIN  = 1,
		END    = 2,
		SINGLE = 3
	};

	// Attribute name/value pair.
	typedef std::pair<CL_StringRef, CL_StringRef> Attribute;

	//: The token type.
	TokenType type;
	
	//: The token variant.
	TokenVariant variant;
	
	//: The name of the token.
	CL_StringRef name;
	
	//: Returns the value of the token.
	CL_StringRef value;

	//: All the attributes attached to the token.
	std::vector<Attribute> attributes;

//! Operations:
public:

//! Implementation:
private:
};

#endif
