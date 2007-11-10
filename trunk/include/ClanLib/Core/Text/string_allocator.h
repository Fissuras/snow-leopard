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

#ifndef header_string_allocator
#define header_string_allocator

#include "../api_core.h"
#include "../System/sharedptr.h"
#include "string_ref8.h"
#include "string_ref16.h"

class CL_StringAllocator_Impl;

//: Allocate strings in blocks.
//- !group=Core/Text!
//- !header=core.h!
//- <p>This class allows you to efficiently allocate strings. Instead
//- of using the default new operator, this class allocates string data in
//- blocks. The temporary strings returned by the class remain valid as long
//- as the CL_StringAllocator stays valid, or until clear() is called.</p>
class CL_API_CORE CL_StringAllocator
{
//! Construction:
public:
	CL_StringAllocator();
	
	CL_StringAllocator(const CL_StringAllocator &source);
	
	~CL_StringAllocator();

//! Operations:
public:
	CL_StringAllocator &operator =(const CL_StringAllocator &source);

	CL_StringRef8 alloc(const CL_StringRef8 &str);
	
	CL_StringRef8 alloc(const char *str, CL_CharacterSet *char_set = 0);
	
	CL_StringRef8 alloc(
		const char *str,
		CL_StringRef8::size_type length,
		CL_CharacterSet *char_set = 0);
	
	CL_StringRef16 alloc(const CL_StringRef16 &str);
	
	CL_StringRef16 alloc(const wchar_t *str, CL_CharacterSet *char_set = 0);
	
	CL_StringRef16 alloc(
		const wchar_t *str,
		CL_StringRef16::size_type length,
		CL_CharacterSet *char_set = 0);

	CL_StringRef alloc(unsigned int length, CL_CharacterSet *char_set = 0);

	CL_StringRef8 alloc8(unsigned int length, CL_CharacterSet *char_set = 0);

	CL_StringRef16 alloc16(unsigned int length, CL_CharacterSet *char_set = 0);

	void clear();

//! Implementation:
private:
	CL_SharedPtr<CL_StringAllocator_Impl> impl;
};

#endif
