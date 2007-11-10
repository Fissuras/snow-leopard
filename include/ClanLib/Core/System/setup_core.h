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
**    Harry Storbacka
*/

//! clanCore="System"
//! header=core.h

#ifndef header_setup_core
#define header_setup_core

#include "../api_core.h"
#include "thread_local_storage.h"

//: Library initializer class.
//- !group=Core/System!
//- !header=core.h!
class CL_API_CORE CL_SetupCore
{
//! Construction:
public:
	//: Initializes clanCore.
	CL_SetupCore();

	~CL_SetupCore();

//! Operations:
public:
#ifdef WIN32
	//: Set module instance used by ClanLib.
	static void set_instance(HINSTANCE hInstance);
#endif

	CL_ThreadLocalStorage tls;

//! Implementation:
private:
};

#endif
