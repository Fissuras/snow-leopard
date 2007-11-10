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
**    Mark Page
*/

//! clanDisplay="Display"
//! header=display.h

#ifndef header_timer
#define header_timer

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/Signals/callback_v0.h"

class CL_Timer_Impl;
class CL_DisplayWindowMessage;
class CL_DisplayWindow;

//: Timer class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_Timer
{
//! Construction:
public:
	//: Constructs a timer object.

	CL_Timer();

	CL_Timer(CL_DisplayWindow &window);
	
	~CL_Timer();

//! Attributes:
public:
	//: Returns true if the timer repeats until it is stopped
	bool is_repeating() const;

	//: Returns the current timeout. In milliseconds.
	unsigned int get_timeout() const;

	//: Returns the timer unique id
	unsigned int get_id() const;

//! Events:
public:
	//: void func_expired(const CL_GUIMessage &message)
	CL_Callback_v0 &func_expired();

//! Operations:
public:
	//: Starts the timer. Timeout in milliseconds.
	void start(unsigned int timeout, bool repeat=true);

	//: Stop the timer.
	void stop();

//! Implementation:
private:
	CL_SharedPtr<CL_Timer_Impl> impl;
};

#endif


