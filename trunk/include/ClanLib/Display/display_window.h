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

#ifndef header_display_window
#define header_display_window

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/System/weakptr.h"
#include "../Core/Signals/signal_v0.h"
#include "../Core/Signals/signal_v1.h"
#include "../Core/Signals/signal_v2.h"
#include "../Core/Signals/callback_v1.h"
#include "../Core/Text/string_types.h"
#include "display_target.h"

class CL_Display;
class CL_DisplayMode;
class CL_DisplayWindowDescription;
class CL_GraphicContext;
class CL_InputContext;
class CL_Rect;
class CL_Point;
class CL_DisplayWindowMessage;
class CL_DisplayWindowProvider;
class CL_DisplayWindow_Impl;

//: Top-level window class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_DisplayWindow
{
//! Construction:
public:
	//: Constructs a window.
	//param title: Titlebar text.
	//param width: Width in pixels of window.
	//param height: Height in pixels of window.
	//param start_fullscreen: If true, window will go fullscreen.
	//param allow_resize: If true, window will have resize grabbers and can be resized.
	//param flipping_buffers: Number of flipping buffers in system.
	//param flipping_buffers: Default is that there is a front buffer and a back buffer.
	//param description: Structure that describes how to create the display window.
	//param provider: Display target implementation object.
	//param target: Display target used to create the window.
	CL_DisplayWindow();

	CL_DisplayWindow(
		const CL_StringRef &title,
		int width,
		int height,
		bool start_fullscreen = false,
		bool allow_resize = false,
		int flipping_buffers = 2,
		CL_DisplayTarget target = CL_DisplayTarget());

	CL_DisplayWindow(
		const CL_DisplayWindowDescription &description,
		CL_DisplayTarget target = CL_DisplayTarget());

	CL_DisplayWindow(CL_DisplayWindowProvider *provider);

	~CL_DisplayWindow();

//! Attributes:
public:
	//: Returns the current width of the window.
	int get_width() const;

	//: Returns the current height of the window.
	int get_height() const;

	//: Returns the position and size of the window frame.
	CL_Rect get_geometry() const;

	//: Returns the drawable area of the window.
	CL_Rect get_viewport() const;

	//: Returns true if window is currently running fullscreen.
	bool is_fullscreen() const;

	//: Returns true if window has focus.
	bool has_focus() const;

	//: Return the graphic context for the window.
	CL_GraphicContext get_gc() const;

	//: Return the input context for the window.
	CL_InputContext get_ic() const;

	//: Signal emitted when window lost focus.
	CL_Signal_v0 &sig_lost_focus();

	//: Signal emitted when window gain focus.
	CL_Signal_v0 &sig_got_focus();

	//: Signal emitted when window is resized.
	CL_Signal_v2<int, int> &sig_resize();

	//: Signal emitted when an area of the window is invalidated.
	CL_Signal_v1<const CL_Rect &> &sig_paint();

	//: Signal emitted when window is closed.
	CL_Signal_v0 &sig_window_close();

	//: Callback called when a window is being resized.
	CL_Callback_v1<CL_Rect &> &func_window_resize();

	//: Callback called when a window receives a message from the windowing system.
	CL_Callback_v1<CL_DisplayWindowMessage &> &func_window_message_received();

	//: returns true if this display window is invalid
	bool is_null() const;

	//: returns true if this display window is visible
	bool is_visible() const;

	//: Returns true if the window is minimized.
	bool is_minimized() const;

	//: Returns true if the window is maximized.
	bool is_maximized() const;

	//: returns the display window provider
	CL_DisplayWindowProvider *get_provider() const;

//! Operations:
public:
	//: Convert from window client coordinates to screen coordinates.
	CL_Point client_to_screen(const CL_Point &client);

	//: Convert from screen coordinates to client coordinates.
	CL_Point screen_to_client(const CL_Point &screen);

	//: Capture/Release the mouse.
	void capture_mouse(bool capture);

	//: Change window to running fullscreen mode.
	void set_fullscreen(int width=0, int height=0, int bpp=0, int refresh_rate=0);

	//: Change window to running fullscreen mode.
	void set_fullscreen(const CL_DisplayMode &display_mode);

	//: Change window to running windowed mode.
	void set_windowed();

	//: Change window title.
	void set_title(const CL_StringRef &title);

	//: Set window position and size.
	//param pos: Window position and size.
	//param x: Window x position on desktop.
	//param y: Window y position on desktop.
	void set_position(const CL_Rect &pos, bool client_area);

	void set_position(int x, int y);

	void set_enabled(bool enable);

	void set_visible(bool visible, bool activate);

	//: Resize window.
	//param width: New width of window in pixels.
	//param height: New height of window in pixels.
	void set_size(int width, int height, bool client_area);

	//: Minimizes the window.
	void minimize();

	//: Restores the window.
	void restore();

	//: Maximizes the window.
	void maximize();

	//: Displays the window in its current size and position.
	void show(bool activate = true);

	//: Hides the window.
	void hide();

	//: Raises the window on top of other windows.
	void bring_to_front();

	//: Copy the specified rectangle area from back buffer to front buffer.
	//param rect: Area that should be copied.
	void update(const CL_Rect &rect);

	//: Flip back buffer to front, making changes visible on screen.
	//param interval: Specifies the minimum number of video frames that are displayed before a buffer swap will occur.
	//- <p>The parameter interval specifies the minimum number of video frames
	//- that are displayed before a buffer swap will occur.</p>
	//- <p>A video frame period is the time required by the monitor to display a 
	//- full frame of video data.  In the case of an interlaced monitor,
	//- this is typically the time required to display both the even and odd 
	//- fields of a frame of video data.  An interval set to a value of 2
	//- means that the color buffers will be swapped at most every other video
	//- frame.</p>
	//- <p>If interval is set to a value of 0, buffer swaps are not synchronized
	//- to a video frame.  The interval value is silently clamped to
	//- the maximum implementation-dependent value supported before being
	//- stored.</p>
	//- <p>If interval is set to a value of -1 (the default), then it will use
	//- the buffer swap used for previous flip. If its the first flip, it will
	//- use the system default, which per default is 1.</p>
	void flip(int interval = -1);

	//: Shows the mouse cursor.
	void show_cursor();

	//: Hides the mouse cursor.
	void hide_cursor();

//! Implementation:
private:
	CL_DisplayWindow(CL_WeakPtr<CL_DisplayWindow_Impl> impl);

	CL_SharedPtr<CL_DisplayWindow_Impl> impl;

	friend class CL_Display;
	friend class CL_Timer_Impl;
};

#endif

