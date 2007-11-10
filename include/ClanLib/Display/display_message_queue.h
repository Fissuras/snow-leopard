/*
**  ClanLib SDK
**  Copyright (c) 1997-2007 The ClanLib Team
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

//! clanDisplay="Display"
//! header=display.h

#ifndef display_message_queue
#define display_message_queue

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/System/event.h"

class CL_DisplayMessageQueue_Provider;
class CL_DisplayMessageQueue_Impl;

//: Display Message Queue class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_DisplayMessageQueue
{
//! Operations:
public:
	static bool has_messages();

	//: Make thread sleep until a message arrives on the queue or one of the events is triggered.
	static int wait();

	//: Make thread sleep until a message arrives on the queue.
	static void wait_message();

	//: Process messages on the queue.
	static void process(bool only_first_message = false);

	//: Add a wakeup event.
	static void add_wakeup_event(CL_Event &event);

//! Implementation:
private:
};

#endif
