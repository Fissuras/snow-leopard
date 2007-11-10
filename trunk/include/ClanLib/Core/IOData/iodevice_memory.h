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

//! clanCore="I/O Data"
//! header=core.h

#ifndef header_iodevice_memory
#define header_iodevice_memory

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"
#include "iodevice.h"

class CL_DataBuffer;

//: Memory I/O device.
//- !group=Core/IO Data!
//- !header=core.h!
class CL_API_CORE CL_IODevice_Memory : public CL_IODevice
{
//! Construction:
public:
	//: Constructs a memory I/O device.
	CL_IODevice_Memory();

	CL_IODevice_Memory(CL_DataBuffer &data);

//! Attributes:
public:
	//: Retrieves the data buffer for the memory device.
	const CL_DataBuffer &get_data() const;

	CL_DataBuffer &get_data();

//! Operations:
public:

//! Implementation:
private:
};

#endif
