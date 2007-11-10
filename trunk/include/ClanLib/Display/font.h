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

//! clanDisplay="Display"
//! header=display.h

#ifndef header_font
#define header_font

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "graphic_context.h"
#include "pixel_buffer.h"

class CL_FontProvider;
class CL_Font_Impl;

//: Font class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_Font
{
//! Construction:
public:
	//: Constructs a font.
	CL_Font();

	CL_Font(
		CL_GraphicContext context,
		const CL_StringRef &typeface_name,
		int height = 0,
		int average_width = 0,
		double escapement = 0.0,
		double orientation = 0.0,
		int weight = 0,
		bool italic = false,
		bool underline = false,
		bool strikeout = false,
		bool fixed_pitch = false);

	CL_Font(const CL_Font &copy);

	~CL_Font();

//! Attributes:
public:
	//: Retrieves the font provider.
	CL_FontProvider *get_provider();

//! Operations:
public:

//! Implementation:
private:
	CL_SharedPtr<CL_Font_Impl> impl;
};

//: Font pixel buffer format (holds a pixel buffer containing a glyph)
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_FontPixelBuffer
{
public:
	CL_FontPixelBuffer() : glyph(0), empty_buffer(true), offset(0,0), increment(0,0) { };

	//: Glyph this pixel buffer refers to. 0 = Glyph if not valid
	int glyph;

	//: True when the pixel buffer is empty
	bool empty_buffer;

	//: The pixel buffer containing the glyph
	CL_PixelBuffer buffer;

	//: Offset to draw the font to buffer
	//- For example:
	//- x = pos_x + pixelbuffer.offset.x
	//- y = pos_y + pixelbuffer.offset.y
	CL_Point offset;

	//: Increment to draw the next glyph
	//- For example:
	//- pos_x += pixelbuffer.increment.x;
	//- pos_y += pixelbuffer.increment.y;
	CL_Point increment;
};

#endif
