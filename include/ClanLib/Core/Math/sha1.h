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

//! clanCore="Math"
//! header=core.h

#ifndef header_sha1
#define header_sha1

#include "../api_core.h"
#include "../System/sharedptr.h"

class CL_DataBuffer;
class CL_SHA1_Impl;

//: SHA-1 hash function class.
//- !group=Core/Math!
//- !header=core.h!
class CL_API_CORE CL_SHA1
{
//! Construction:
public:
	//: Constructs a SHA-1 hash generator.
	CL_SHA1();
	
//! Attributes:
public:
	//: Returns the calculated hash.
	CL_String8 get_hash(bool uppercase = false);

	void get_hash(unsigned char out_hash[20]);

//! Operations:
public:
	//: Resets the hash generator.
	void reset();

	//: Adds data to be hashed.
	void add(const void *data, int size);
	
	void add(const CL_DataBuffer &data);

	//: Finalize hash calculation.
	void calculate();

	//: Generate SHA-1 hash from data.
	static CL_String8 hash(const void *data, int size, bool uppercase = false);
	
	static CL_String8 hash(const CL_StringRef8 &data, bool uppercase = false);
	
	static CL_String8 hash(const CL_DataBuffer &data, bool uppercase = false);

	static void hash(const void *data, int size, unsigned char out_hash[20]);
	
	static void hash(const CL_StringRef8 &data, unsigned char out_hash[20]);
	
	static void hash(const CL_DataBuffer &data, unsigned char out_hash[20]);

//! Implementation:
private:
	CL_SharedPtr<CL_SHA1_Impl> impl;
};

#endif
