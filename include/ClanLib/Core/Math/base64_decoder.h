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

#ifndef header_base64_decoder
#define header_base64_decoder

#include "../api_core.h"
#include "../System/sharedptr.h"

class CL_DataBuffer;
class CL_Base64Decoder_Impl;

//: Base64 decoder class.
//- !group=Core/Math!
//- !header=core.h!
class CL_API_CORE CL_Base64Decoder
{
//! Construction:
public:
	//: Constructs a base64 decoder.
	CL_Base64Decoder();
	
//! Attributes:
public:
	//: Returns the decoded data.
	CL_DataBuffer &get_result();

//! Operations:
public:
	//: Resets the decoder.
	void reset();

	//: Feeds the decoder with base64 encoded data.
	void feed(const void *data, int size, bool append_result = true);

	//: Decode base64 data and return it in a buffer.
	static CL_DataBuffer decode(const void *data, int size);
	
	static CL_DataBuffer decode(const CL_StringRef8 &data);
	
	static CL_DataBuffer decode(const CL_DataBuffer &data);

//! Implementation:
private:
	CL_SharedPtr<CL_Base64Decoder_Impl> impl;
};

#endif
