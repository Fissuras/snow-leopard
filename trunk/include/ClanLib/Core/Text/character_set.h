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

//! clanCore="Text"
//! header=core.h

#ifndef header_character_set
#define header_character_set

#include "../api_core.h"

//: Character set converter interface.
//- !group=Core/Text!
//- !header=core.h!
class CL_API_CORE CL_CharacterSet
{
//! Construction:
public:
	virtual ~CL_CharacterSet() {}

//! Operations:
public:
	//: Convert text from character set to ucs2.
	virtual int to_unicode(
		void *input,
		int input_length,
		unsigned int *output,
		int output_capacity,
		int *output_length) = 0;
	
	//: Convert text from ucs2 into character set.
	virtual int from_unicode(
		unsigned int *input,
		int input_length,
		void *output,
		int output_capacity,
		int *output_length) = 0;

	//: Returns the amount of characters in buffer.
	virtual int get_character_length(
		void *input,
		int input_length) = 0;

	//: Returns the index positions for a number of characters.
	virtual int get_character_indexes(
		void *input,
		int input_length,
		void *output,
		int output_capacity,
		int *output_length) = 0;
};

#endif
