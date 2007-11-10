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
**    Harry Storbacka
*/

#ifndef display_message_queue_provider
#define display_message_queue_provider

#include "../Core/System/event.h"

//: Display target provider message queue interface.
//- !group=Display/Display Target Interface!
//- !header=display.h!
class CL_DisplayMessageQueue_Provider
{
//! Construction:
public:
	virtual ~CL_DisplayMessageQueue_Provider() {};

//! Attributes:
public:
#ifdef WIN32
	virtual bool has_messages() const = 0;
#else
	virtual bool has_messages() = 0;
#endif

//! Operations:
public:
	//: Make thread sleep until a message arrives on the queue or one of the events is triggered.
	virtual int wait() = 0;

	//: Make thread sleep until a message arrives on the queue.
	virtual void wait_message() = 0;

	//: Process messages on the queue.
	virtual void process(bool only_first_message) = 0;

	//: Add a wakeup event.
	virtual void add_wakeup_event(CL_Event &event) = 0;

//! Implementation:
private:
};

#endif
