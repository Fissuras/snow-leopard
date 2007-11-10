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

//! clanDisplay="Input"
//! header=display.h

#ifndef header_input_context
#define header_input_context

#if _MSC_VER > 1000
#pragma once
#endif

#include "api_display.h"
#include "../Core/System/sharedptr.h"

class CL_InputDevice;
class CL_InputContext_Impl;

//- !group=Display/Input!
//- !header=display.h!
class CL_API_DISPLAY CL_InputContext
{
//! Construction:
public:
	//: Constructs an input context.
	CL_InputContext();

	CL_InputContext(const CL_InputContext &copy);

	~CL_InputContext();

//! Attributes:
public:
	//: Returns the number of keyboards available.
	int get_keyboard_count() const;

	//: Returns the number of mice available.
	int get_mouse_count() const;

	//: Returns the number of joysticks available.
	int get_joystick_count() const;

	//: Returns the number of tablets available.
	int get_tablet_count() const;

	//: Returns the input device for the specified keyboard.
	CL_InputDevice &get_keyboard(int keyboard = 0);

	//: Returns the input device for the specified mouse.
	CL_InputDevice &get_mouse(int mouse = 0);

	//: Returns the input device for the specified joystick.
	CL_InputDevice &get_joystick(int joystick = 0);

	//: Returns the input device for the specified tablet.
	CL_InputDevice &get_tablet(int tablet = 0);

	//: Returns the input device with the given devicename
	CL_InputDevice &get_device(const CL_StringRef &device_name);

//! Operations:
public:
	//: Copy assignment operator.
	CL_InputContext &operator =(CL_InputContext &copy);

	//: Removes all devices from this input context.
	void clear();

	//: Adds a new keyboard to the input context.
	void add_keyboard(const CL_InputDevice keyboard);

	//: Adds a new mouse to the input context.
	void add_mouse(const CL_InputDevice mouse);

	//: Adds a new joystick to the input context.
	void add_joystick(const CL_InputDevice joystick);

	//: Adds a new tablet to the input context.
	void add_tablet(const CL_InputDevice tablet);

	//: Process and dispatch messages to signals.
	void process_messages();

	//: Update device
	//param peek_only: Treat as a request to see if an event would occur
	//return: true when the device event has occurred
	bool poll(bool peek_only);

//! Implementation:
private:
	CL_SharedPtr<CL_InputContext_Impl> impl;
};

#endif
