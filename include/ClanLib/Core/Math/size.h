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
**    Kenneth Gangstø
*/

//! clanCore="Math"
//! header=core.h

#ifndef header_size
#define header_size

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"

class CL_Sizef;
class CL_Sized;

//: 2D (width,height) size structure.
//- !group=Core/Math!
//- !header=core.h!
class CL_API_CORE CL_Size
{
//! Construction:
public:
	//: Constructs a size structure.
	//param width: Initial width of size structure.
	//param height: Initial height of size structure.
	//param size: Size structure to construct this one from.
	CL_Size() { return; }

	CL_Size(int width, int height)
	: width(width), height(height) { }

	CL_Size(const CL_Size &s)
	{ width = s.width; height = s.height; }

	explicit CL_Size(const CL_Sizef& s);

	explicit CL_Size(const CL_Sized& s);

//! Attributes:
public:
	//: Size width.
	int width;

	//: Size height.
	int height;

//! Operations:
public:
	//: Size += Size operator.
	CL_Size &operator+=(const CL_Size &s)
	{ width += s.width; height += s.height; return *this; }

	//: Size -= Size operator.
	CL_Size &operator-=(const CL_Size &s)
	{ width -= s.width; height -= s.height; return *this; }
	
	//: Size + Size operator.
	CL_Size operator+(const CL_Size &s) const
	{ return CL_Size(width + s.width, height + s.height); }

	//: Size - Size operator.
	CL_Size operator-(const CL_Size &s) const
	{ return CL_Size(width - s.width, height - s.height); }

	//: Size == Size operator (deep compare).
	bool operator==(const CL_Size &s) const
	{ return (width == s.width) && (height == s.height); }

	//: Size != Size operator (deep compare).
	bool operator!=(const CL_Size &s) const
	{ return (width != s.width) || (height != s.height); }
};

//: 2D (width,height) floating point size structure.
//- !group=Core/Math!
//- !header=core.h!
class CL_Sizef
{
//! Construction:
public:
	//: Constructs a size structure.
	//param width: Initial width of size structure.
	//param height: Initial height of size structure.
	//param size: Size structure to construct this one from.
	CL_Sizef() { return; }

	CL_Sizef(const CL_Size& s) 
		: width((float) s.width),
		  height((float) s.height)
	{}

	CL_Sizef(float width, float height)
	: width(width), height(height) { }

	CL_Sizef(const CL_Sizef &s)
	{ width = s.width; height = s.height; }

//! Attributes:
public:
	//: Size width.
	float width;

	//: Size height.
	float height;

//! Operations:
public:
	//: Size += Size operator.
	CL_Sizef &operator+=(const CL_Sizef &s)
	{ width += s.width; height += s.height; return *this; }

	//: Size -= Size operator.
	CL_Sizef &operator-=(const CL_Sizef &s)
	{ width -= s.width; height -= s.height; return *this; }
	
	//: Size + Size operator.
	CL_Sizef operator+(const CL_Sizef &s) const
	{ return CL_Sizef(width + s.width, height + s.height); }

	//: Size - Size operator.
	CL_Sizef operator-(const CL_Sizef &s) const
	{ return CL_Sizef(width - s.width, height - s.height); }

	//: Size == Size operator (deep compare).
	bool operator==(const CL_Sizef &s) const
	{ return (width == s.width) && (height == s.height); }

	//: Size != Size operator (deep compare).
	bool operator!=(const CL_Sizef &s) const
	{ return (width != s.width) || (height != s.height); }
};

//: 2D (width,height) double floating point size structure.
//- !group=Core/Math!
//- !header=core.h!
class CL_Sized
{
//! Construction:
public:
	//: Constructs a size structure.
	//param width: Initial width of size structure.
	//param height: Initial height of size structure.
	//param size: Size structure to construct this one from.
	CL_Sized() { return; }

	CL_Sized(const CL_Size& s) 
		: width((double) s.width),
		  height((double) s.height)
	{}

	CL_Sized(double width, double height)
	: width(width), height(height) { }

	CL_Sized(const CL_Sized &s)
	{ width = s.width; height = s.height; }

//! Attributes:
public:
	//: Size width.
	double width;

	//: Size height.
	double height;

//! Operations:
public:
	//: Size += Size operator.
	CL_Sized &operator+=(const CL_Sized &s)
	{ width += s.width; height += s.height; return *this; }

	//: Size -= Size operator.
	CL_Sized &operator-=(const CL_Sized &s)
	{ width -= s.width; height -= s.height; return *this; }
	
	//: Size + Size operator.
	CL_Sized operator+(const CL_Sized &s) const
	{ return CL_Sized(width + s.width, height + s.height); }

	//: Size - Size operator.
	CL_Sized operator-(const CL_Sized &s) const
	{ return CL_Sized(width - s.width, height - s.height); }

	//: Size == Size operator (deep compare).
	bool operator==(const CL_Sized &s) const
	{ return (width == s.width) && (height == s.height); }

	//: Size != Size operator (deep compare).
	bool operator!=(const CL_Sized &s) const
	{ return (width != s.width) || (height != s.height); }
};

inline CL_Size::CL_Size(const CL_Sizef& s)
	: width(static_cast<int>(s.width)),
	  height(static_cast<int>(s.height))
{}

inline CL_Size::CL_Size(const CL_Sized& s)
	: width(static_cast<int>(s.width)),
	  height(static_cast<int>(s.height))
{}

#endif
