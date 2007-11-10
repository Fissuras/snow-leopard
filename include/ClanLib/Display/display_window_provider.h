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

//! clanDisplay="Display"
//! header=display.h

#ifndef header_display_window_provider
#define header_display_window_provider

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/System/weakptr.h"
#include "../Core/Text/string_types.h"
#include "../Core/Signals/signal_v0.h"
#include "../Core/Signals/signal_v1.h"
#include "../Core/Signals/signal_v2.h"
#include "../Core/Signals/callback_v1.h"

class CL_Rect;
class CL_Point;
class CL_DisplayWindowDescription;
class CL_DisplayWindowMessage;
class CL_GraphicContext;
class CL_InputContext;
class CL_Timer;

//: Display Window site.
//- !group=Display/Display Target Interface!
//- !header=display.h!
class CL_API_DISPLAY CL_DisplayWindowSite
{
//! Attributes:
public:
	//: Pointer to lost focus signal.
	CL_Signal_v0 *sig_lost_focus;

	//: Pointer to got focus signal.
	CL_Signal_v0 *sig_got_focus;

	//: Pointer to resize signal.
	CL_Signal_v2<int, int> *sig_resize;

	//: Pointer to paint signal.
	CL_Signal_v1<const CL_Rect &> *sig_paint;

	//: Pointer to window close signal.
	CL_Signal_v0 *sig_window_close;

	//: Pointer to window resize callback function.
	CL_Callback_v1<CL_Rect &> *func_window_resize;

	//: Pointer to window message receive callback function.
	CL_Callback_v1<CL_DisplayWindowMessage &> *func_window_message_received;
};

//: Interface for implementing a CL_DisplayWindow target.
//- !group=Display/Display Target Interface!
//- !header=display.h!
class CL_API_DISPLAY CL_DisplayWindowProvider
{
//! Construction:
public:
	virtual ~CL_DisplayWindowProvider() { return; }

//! Attributes:
public:
	//: Returns the position and size of the window frame.
	virtual CL_Rect get_geometry() const = 0;

	//: Returns the drawable area of the window.
	virtual CL_Rect get_viewport() const = 0;

	//: Returns true if window has focus.
	virtual bool has_focus() const = 0;

	//: Returns true if the window is minimized.
	virtual bool is_minimized() const = 0;

	//: Returns true if the window is maximized.
	virtual bool is_maximized() const = 0;

	//: Return the graphic context for the window.
	virtual CL_GraphicContext get_gc() const = 0;

	//: Return the input context for the window.
	virtual CL_InputContext get_ic() const = 0;

#ifdef WIN32
	virtual HWND get_hwnd() const = 0;
#endif

//! Operations:
public:
	//: Convert from window client coordinates to screen coordinates.
	virtual CL_Point client_to_screen(const CL_Point &client) = 0;

	//: Convert from screen coordinates to client coordinates.
	virtual CL_Point screen_to_client(const CL_Point &screen) = 0;

	//: Capture/Release the mouse.
	virtual void capture_mouse(bool capture) = 0;

	//: Destroys the display window provider.
	virtual void destroy() = 0;

	//: Creates window, assigning site and description to provider.
	virtual void create(CL_DisplayWindowSite *site, const CL_DisplayWindowDescription &description) = 0;

	//: Shows the mouse cursor.
	virtual void show_system_cursor() = 0;

	//: Hides the mouse cursor.
	virtual void hide_system_cursor() = 0;

	//: Change window title.
	virtual void set_title(const CL_StringRef &new_title) = 0;

	//: Set window position and size.
	virtual void set_position(const CL_Rect &pos, bool client_area) = 0;

	virtual void set_size(int width, int height, bool client_area) = 0;

	//: Enables or disables a window.
	virtual void set_enabled(bool enable) = 0;

	//: Minimizes the window.
	virtual void minimize() = 0;

	//: Restores the window.
	virtual void restore() = 0;

	//: Maximizes the window.
	virtual void maximize() = 0;

	//: Displays the window in its current size and position.
	virtual void show(bool activate) = 0;

	//: Hides the window.
	virtual void hide() = 0;

	//: Raise window on top of other windows.
	virtual void bring_to_front() = 0;

	//: Flip opengl buffers.
	virtual void flip(int interval) = 0;

	//: Copy a region of the backbuffer to the frontbuffer.
	virtual void update(const CL_Rect &rect) = 0;

	//: Set the window timer
	virtual void set_timer(CL_Timer *timer) = 0;

	//: Stop the window timer
	virtual void kill_timer(CL_Timer *timer) = 0;

//! Implementation:
private:
};

#endif
