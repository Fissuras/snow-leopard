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
**    Kenneth Gangst�
*/

//! clanCore="Text"
//! header=core.h

#ifndef header_console
#define header_console

// 'kbhit' was declared deprecated
#ifdef WIN32
#pragma warning(disable: 4996)
#endif

#include "../api_core.h"
#include "string_format.h"
#include "string_help.h"
#ifdef WIN32
#include <conio.h>
#else
#include <unistd.h>
#endif

//: Console access helper class.
//- !group=Core/Text!
//- !header=core.h!
class CL_Console
{
//! Operations:
public:
	//: Writes text to the console window.
	static void write(const CL_StringRef &text)
	{
	#ifdef WIN32
		CL_TempString8 t = CL_StringHelp::text_to_local8(text);
		DWORD written = 0;
		WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), t.data(), t.length(), &written, 0);
	#else
		::write(1, text.data(), text.length());
	#endif
	}

	template <class Arg1>
	static void write(const CL_StringRef &format, Arg1 arg1)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		write(f.get_result());
	}

	template <class Arg1, class Arg2>
	static void write(const CL_StringRef &format, Arg1 arg1, Arg2 arg2)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		write(f.get_result());
	}

	template <class Arg1, class Arg2, class Arg3>
	static void write(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		f.set_arg(3, arg3);
		write(f.get_result());
	}

	template <class Arg1, class Arg2, class Arg3, class Arg4>
	static void write(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		f.set_arg(3, arg3);
		f.set_arg(4, arg4);
		write(f.get_result());
	}

	template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5>
	static void write(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		f.set_arg(3, arg3);
		f.set_arg(4, arg4);
		f.set_arg(arg5);
		write(f.get_result());
	}

	template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6>
	static void write(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		f.set_arg(3, arg3);
		f.set_arg(4, arg4);
		f.set_arg(arg5);
		f.set_arg(arg6);
		write(f.get_result());
	}

	template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7>
	static void write(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		f.set_arg(3, arg3);
		f.set_arg(4, arg4);
		f.set_arg(arg5);
		f.set_arg(arg6);
		f.set_arg(arg7);
		write(f.get_result());
	}

	//: Writes text to the console window and then advances to a new line.
	static void write_line(const CL_StringRef &text)
	{
		write(text);
	#ifdef WIN32
		write(cl_text("\r\n"));
	#else
		write(cl_text("\n"));
	#endif
	}

	template <class Arg1>
	static void write_line(const CL_StringRef &format, Arg1 arg1)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		write_line(f.get_result());
	}

	template <class Arg1, class Arg2>
	static void write_line(const CL_StringRef &format, Arg1 arg1, Arg2 arg2)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		write_line(f.get_result());
	}

	template <class Arg1, class Arg2, class Arg3>
	static void write_line(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		f.set_arg(3, arg3);
		write_line(f.get_result());
	}

	template <class Arg1, class Arg2, class Arg3, class Arg4>
	static void write_line(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		f.set_arg(3, arg3);
		f.set_arg(4, arg4);
		write_line(f.get_result());
	}

	template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5>
	static void write_line(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		f.set_arg(3, arg3);
		f.set_arg(4, arg4);
		f.set_arg(5, arg5);
		write_line(f.get_result());
	}

	template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6>
	static void write_line(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		f.set_arg(3, arg3);
		f.set_arg(4, arg4);
		f.set_arg(5, arg5);
		f.set_arg(6, arg6);
		write_line(f.get_result());
	}

	template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7>
	static void write_line(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7)
	{
		CL_TempStringFormat f(format);
		f.set_arg(1, arg1);
		f.set_arg(2, arg2);
		f.set_arg(3, arg3);
		f.set_arg(4, arg4);
		f.set_arg(5, arg5);
		f.set_arg(6, arg6);
		f.set_arg(7, arg7);
		write_line(f.get_result());
	}

	//: Block until a key is pressed in the console window.
	static void wait_for_key()
	{
	#ifdef WIN32
		while (!kbhit()) Sleep(250);
	#endif
/*
		write_line("Press any key");
	#ifdef WIN32
		TCHAR buffer[1];
		DWORD written = 0;
		BOOL result = ReadConsole(GetStdHandle(STD_INPUT_HANDLE), buffer, 1, &written, 0);
	#else
		char buffer[1];
		read(0, buffer, 1);
	#endif
*/	}
};

#endif