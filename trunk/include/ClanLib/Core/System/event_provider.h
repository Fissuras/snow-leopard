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

//! clanCore="System"
//! header=core.h

#ifndef header_event_provider
#define header_event_provider

#include "../api_core.h"

//: OS level event provider.
//- !group=Core/System!
//- !header=core.h!
class CL_API_CORE CL_EventProvider
{
//! Construction:
public:
	virtual ~CL_EventProvider() { return; }

//! Attributes:
public:
#ifdef WIN32
	enum EventType
	{
		type_native
	};
#else
	enum EventType
	{
		type_fd_read,
		type_fd_write,
		type_fd_exception
	};
#endif

	//: Returns the type of event provided.
	virtual EventType get_event_type(int index) = 0;

#ifdef WIN32
	//: Returns the OS handle for the event.
	virtual HANDLE get_event_handle(int index) = 0;
#else
	//: Returns the OS handle for the event.
	virtual int get_event_handle(int index) = 0;
#endif

	//: Returns the number of OS handles relevant for this event.
	virtual int get_num_event_handles() = 0;

//! Operations:
public:
	//: Prepare for OS event waiting.
	virtual bool check_before_wait() { return false; }

	//: Check for flagging after OS event waiting.
	virtual bool check_after_wait(int index) { return true; }

	//: Raise flag.
	virtual bool set() { return false; }

	//: Reset flag.
	virtual bool reset() { return false; }

//! Implementation:
private:
};

#endif
