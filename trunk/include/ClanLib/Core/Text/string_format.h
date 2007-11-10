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

//! clanCore="Text"
//! header=core.h

#ifndef header_string_format
#define header_string_format

#include "../api_core.h"
#include <vector>
#include "string_types.h"

//: String formatting class.
//- !group=Core/Text!
//- !header=core.h!
class CL_API_CORE CL_TempStringFormat
{
//! Construction:
public:
	CL_TempStringFormat(const CL_StringRef &format_string);
	
	~CL_TempStringFormat();

//! Attributes:
public:
	const CL_TempString &get_result() const;

//! Operations:
public:
	void set_arg(int index, const CL_StringRef8 &text);

	void set_arg(int index, const CL_StringRef16 &text);
	
	void set_arg(int index, int value, int min_length = 0);

	void set_arg(int index, unsigned int value, int min_length = 0);

	void set_arg(int index, float value);

	void set_arg(int index, double value);

//! Implementation:
private:
	void create_arg(int index, int start, int length);

	CL_TempString string;
	
	struct ArgPosition
	{
		ArgPosition() : start(0), length(0) { }
		ArgPosition(int s, int l) : start(s), length(l) {}
		int start;
		int length;
	};
	
	std::vector<ArgPosition> args;
};

template <class Arg1>
CL_TempString cl_format(const CL_StringRef &format, Arg1 arg1)
{ CL_TempStringFormat f(format); f.set_arg(1, arg1); return f.get_result(); }

template <class Arg1, class Arg2>
CL_TempString cl_format(const CL_StringRef &format, Arg1 arg1, Arg2 arg2)
{ CL_TempStringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); return f.get_result(); }

template <class Arg1, class Arg2, class Arg3>
CL_TempString cl_format(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3)
{ CL_TempStringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); f.set_arg(3, arg3); return f.get_result(); }

template <class Arg1, class Arg2, class Arg3, class Arg4>
CL_TempString cl_format(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4)
{ CL_TempStringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); f.set_arg(3, arg3); f.set_arg(4, arg4); return f.get_result(); }

template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5>
CL_TempString cl_format(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5)
{ CL_TempStringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); f.set_arg(3, arg3); f.set_arg(4, arg4); f.set_arg(5, arg5); return f.get_result(); }

template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6>
CL_TempString cl_format(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6)
{ CL_TempStringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); f.set_arg(3, arg3); f.set_arg(4, arg4); f.set_arg(5, arg5); f.set_arg(6, arg6); return f.get_result(); }

template <class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7>
CL_TempString cl_format(const CL_StringRef &format, Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6, Arg7 arg7)
{ CL_TempStringFormat f(format); f.set_arg(1, arg1); f.set_arg(2, arg2); f.set_arg(3, arg3); f.set_arg(4, arg4); f.set_arg(5, arg5); f.set_arg(6, arg6); f.set_arg(7, arg7); return f.get_result(); }

#endif
