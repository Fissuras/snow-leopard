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

#ifndef header_base64_encoder
#define header_base64_encoder

#include "../api_core.h"
#include "../System/sharedptr.h"

class CL_DataBuffer;
class CL_Base64Encoder_Impl;

//: Base64 encoder class.
//- !group=Core/Math!
//- !header=core.h!
class CL_API_CORE CL_Base64Encoder
{
//! Construction:
public:
	//: Constructs a base64 encoder.
	CL_Base64Encoder();
	
//! Attributes:
public:
	//: Returns the data in encoded form.
	CL_DataBuffer &get_result();

//! Operations:
public:
	//: Resets the encoder.
	void reset();

	//: Feeds the encoder with more data.
	void feed(const void *data, int size, bool append_result = true);

	//: Ends the base64 encoding.
	void finalize(bool append_result = true);

	//: Base64 encodes data and returns it as an 8 bit string.
	static CL_String8 encode(const void *data, int size);
	
	static CL_String8 encode(const CL_StringRef8 &data);
	
	static CL_String8 encode(const CL_DataBuffer &data);

//! Implementation:
private:
	CL_SharedPtr<CL_Base64Encoder_Impl> impl;
};

#endif
