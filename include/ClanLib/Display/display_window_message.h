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
**    Mark Page
*/

//! clanDisplay="Display"
//! header=display.h

#ifndef header_display_window_message
#define header_display_window_message

#include "api_display.h"
#include "../Core/System/sharedptr.h"

class CL_DisplayWindowMessage_Impl;

#ifndef WIN32
union _XEvent;
typedef struct _CL_XEvent
{
	union _XEvent *xevent;	// Contains XEvent structure. NULL = No event
} CL_XEvent;
#endif

//: Windowing-system message.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_DisplayWindowMessage
{
//! Construction:
public:
	CL_DisplayWindowMessage();

	~CL_DisplayWindowMessage();

//! Attributes:
public:
#ifdef WIN32
	HWND get_hwnd() const;

	UINT get_msg() const;

	WPARAM get_wparam() const;

	LPARAM get_lparam() const;
#else
	const CL_XEvent *get_msg() const;

#endif

	bool has_handled_message() const;

#ifdef WIN32
	LRESULT get_return_value() const;
#endif

//! Operations:
public:
	void set_handled_message(bool handled);

#ifdef WIN32
	void set_return_value(LRESULT value);

	void set_win32_params(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
#else
	//: Note, a copy is not made of this
	void set_x11_params(const CL_XEvent &src_event);
#endif

//! Implementation:
private:
	CL_SharedPtr<CL_DisplayWindowMessage_Impl> impl;
};

#endif

