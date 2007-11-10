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

#ifdef CL_FIX_THIS_CODE

//! clanDisplay="Display"
//! header=display.h

#ifndef header_vector_font
#define header_vector_font

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/Math/size.h"
#include "graphic_context.h"
#include "color.h"

class CL_VectorFont_Impl;
class CL_FontMetrics;
class CL_VirtualDirectory;
class CL_StaticTrianglesArray;
class CL_StaticLinesArray;

typedef CL_StaticTrianglesArray CL_GlyphPrimitivesArray;
typedef CL_StaticLinesArray CL_GlyphPrimitivesArrayOutline;

//: Vector font drawing class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_VectorFont
{
//! Construction:
public:
	//: Creates a vector font.
	CL_VectorFont();

	CL_VectorFont(
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

	CL_VectorFont(
		const CL_StringRef &typeface_filename,
		CL_VirtualDirectory &directory,
		int height = 0,
		int average_width = 0,
		double escapement = 0.0,
		double orientation = 0.0,
		int weight = 0,
		bool italic = false,
		bool underline = false,
		bool strikeout = false,
		bool fixed_pitch = false);

	~CL_VectorFont();

//! Attributes:
public:
	//: Retrieves font metrics for vector font.
	CL_FontMetrics get_font_metrics();

//! Operations:
public:
	//: Returns the amount of glyphs used by text.
	int get_glyph_count(const CL_StringRef &text);

	//: Gets the glyph outline for a glyph.
	CL_GlyphPrimitivesArrayOutline get_glyph_outline(int glyph);

	//: Gets the glyph triangles for a glyph.
	CL_GlyphPrimitivesArray get_glyph_triangles(int glyph);

	//: Find glyph indexes and inter-spacing (x,y) values for text.
	void get_glyphs(
		const CL_StringRef &text,
		int *out_glyphs,
		double *out_interspacing_x,
		double *out_interspacing_y);

	//: Draw glyphs on device context.
	void draw_glyphs(
		CL_GraphicContext gc,
		double x,
		double y,
		int *glyphs,
		int length,
		bool filled = true,
		double *interspacing_x = 0,
		double *interspacing_y = 0,
		const CL_Colord &color = CL_Colord::white);

	//: Draw text on device context.
	void draw_text(
		CL_GraphicContext gc,
		double x,
		double y,
		const CL_StringRef &text,
		const CL_Colord &color = CL_Colord::white,
		bool filled = true);

	//: Calculate size requirements for text.
	CL_Sized get_text_size(const CL_StringRef &text);

	CL_Sized get_glyphs_size(int *glyphs, int length);

//! Implementation:
private:
	CL_SharedPtr<CL_VectorFont_Impl> impl;
};

#endif

#endif
