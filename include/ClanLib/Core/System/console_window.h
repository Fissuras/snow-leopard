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

#ifndef header_console_window
#define header_console_window

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"

class CL_ConsoleWindow_Generic;

//: Text console window.
//- !group=Core/System!
//- !header=core.h!
//- <p>Note: This class has no effect under Linux.</p>
class CL_API_CORE CL_ConsoleWindow
{
//! Construction:
public:
	//: Console Window constructor.
	//param title: Window title of console window.
	//param width: Columns in console window.
	//param height: Rows in console window.
	CL_ConsoleWindow(
		const CL_StringRef &title,
		int width = 80,
		int height = 25);

	//: Console Window destructor.
	~CL_ConsoleWindow();

//! Operations:
public:
	//: Redirects stdout, stdin and stderr to the console window.
	void redirect_stdio();

	//: Redirects stdout and stderr to filename.
	void redirect_stdio(const CL_StringRef &filename);

	//: Waits until user hits a key.
	void wait_for_key();

	//: Displays 'press any key to close this console window',
	//: and waits until user hits a key.
	void display_close_message();

//! Implementation:
private:
	CL_ConsoleWindow_Generic *impl;
};

#endif
