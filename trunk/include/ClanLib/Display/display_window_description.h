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

#ifndef header_display_window_description
#define header_display_window_description

#if _MSC_VER > 1000
#pragma once
#endif

#include "api_display.h"
#include "../Core/Text/string_types.h"
#include "../Core/Math/rect.h"
#include "../Core/System/sharedptr.h"

class CL_DisplayWindow;
class CL_DisplayWindowDescription_Impl;

//: Display window description class.
//- !group=Display/Display!
//- !header=display.h!
//- <p>This class allows you to setup a more advanced description when creating
//- a display window.</p>
class CL_API_DISPLAY CL_DisplayWindowDescription
{
//! Construction:
public:
	//: Constructs a window description with default values.
	CL_DisplayWindowDescription();

	CL_DisplayWindowDescription(const CL_DisplayWindowDescription &copy);

	virtual ~CL_DisplayWindowDescription();

//! Attributes:
public:
	//: Returns the window title stored in the description.
	const CL_String &get_title() const;

	//: Returns true if the window shall be created with decorations.
	bool get_decorations() const;

	//: Returns the size of the window stored in description.
	CL_Size get_size() const;

	//: Returns the initial position of the window.
	CL_Rect get_position() const;

	//: Returns if window should be initially fullscreen.
	bool is_fullscreen() const;

	//: Returns the amount of flipping buffers to be created.
	int get_flipping_buffers() const;

	//: Returns true if window should be resizeable.
	bool get_allow_resize() const;
	
	//: Returns the numbers of bytes per pixel in the window.
	int get_bpp() const;

	//: Returns the refresh rate of the displaymode.
	//- <p>Specifies the frequency, in hertz (cycles per second).
	//- This value is also known as the vertical refresh rate.</p> 
	int get_refresh_rate() const;

#ifdef WIN32
	//: Windows 2000/XP only. Returns true if window is layered.
	bool is_layered() const;

	//: Windows only. Returns the window handle to be used for the window.
	HWND get_handle() const;
#endif

	//: Returns true if a title bar is shown.
	bool has_caption() const;

	//: Returns true if the window is a tool window.
	bool is_tool_window() const;

	//: Returns true if the window is initially visible.
	bool is_visible() const;

	//: Returns true if the window should be placed above all non-topmost windows.
	bool is_topmost() const;

	//: Returns true if the window is drawn with a drop shadow effect.
	bool has_drop_shadow() const;

	//: Returns the window owning this one.
	CL_DisplayWindow get_owner() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_DisplayWindowDescription &operator =(const CL_DisplayWindowDescription &copy);
	
	//: Controls if a title bar is shown or not.
	void show_caption(bool value = true);

	//: Sets if windows should have decorations.
	void set_decorations(bool decorations);

	//: Toggles whether the window is created as initially visible.
	void set_visible(bool value = true);

	//: Sets if the window should be placed above all non-topmost windows.
	void set_topmost(bool value = true);

	//: Flags the window to be a tool window to the windowing system.
	void set_tool_window(bool value = true);

	//: Enables a drop shadow effect on the window.
	void set_drop_shadow(bool value = true);

	//: Specifies another window which owns this one.
	void set_owner_window(const CL_DisplayWindow &owner);

	//: Sets the title of the window.
	void set_title(const CL_String &title);

	//: Sets the size of the window.
	void set_size(const CL_Size &size);

	//: Sets the position of the window.
	void set_position(const CL_Rect &position);

	//: Makes the window initially fullscreen.
	void set_fullscreen(bool fullscreen = true);

	//: Sets the amount of flipping buffers to be used.
	void set_flipping_buffers(int num_buffers = 2);

	//: Sets if windows should be resizable.
	void set_allow_resize(bool allow_resize);
	
	//: Sets the number of bytes per pixel
	void set_bpp(int bpp);

	//: Set the refresh rate of the displaymode.
	//- <p>Specifies the frequency, in hertz (cycles per second).
	//- This value is also known as the vertical refresh rate.</p> 
	void set_refresh_rate(int refresh_rate);

#ifdef WIN32
	//: Windows 2000/XP only. Creates a layered window (complex shaped window).
	void set_layered(bool layered);

	//: Windows only.  Use an existing window handle for the window.
	void set_handle(HWND handle);
#endif

//! Implementation:
private:
	CL_SharedPtr<CL_DisplayWindowDescription_Impl> impl;
};

#endif
