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

#ifndef header_font_metrics
#define header_font_metrics

#include "api_display.h"
#include "../Core/System/sharedptr.h"

class CL_FontMetrics_Impl;

//: Font metrics class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_FontMetrics
{
//! Construction:
public:
	//: Constructs a font metrics description.
	CL_FontMetrics();

	CL_FontMetrics(
		double height,
		double ascent=0.0,
		double descent=0.0,
		double external_leading=0.0,
		double average_character_width=0.0,
		double max_character_width=0.0,
		double weight=0.0,
		double overhang=0.0,
		double digitized_aspect_x=0.0,
		double digitized_aspect_y=0.0,
//		double underline_position,
//		double struck_out_position,
		bool italic=false,
		bool underline=false,
		bool struck_out=false,
		bool fixed_pitch=false
	);

	~CL_FontMetrics();

//! Attributes:
public:
	//: Returns the height of the font.
	double get_height() const;

	//: Returns the font ascender.
	double get_ascent() const;

	//: Returns the font descender.
	double get_descent() const;

	//: Returns the amount of leading (space) inside the bounds set by the get_height() function.
	double get_internal_leading() const;

	//: Returns the amount of extra leading (space) that the application adds between rows.
	double get_external_leading() const;

	//: Returns the average width of characters in the font.
	//- <p>The average width is generally defined as the width of the letter x.  The
	//- value does not include the overhang required for bold or italic characters.</p>
	double get_average_character_width() const;

	//: Returns the width of the widest character in the font.
	double get_max_character_width() const;

	//: Returns the weight of the font.
	double get_weight() const;

	//: Returns the extra width per string that may be added to some synthesized fonts.
	double get_overhang() const;

	//: Returns the horizontal aspect of the device for which the font was designed.
	double get_digitized_aspect_x() const;

	//: Returns the vertical aspect of the device for which the font was designed.
	double get_digitized_aspect_y() const;

	//: Returns the value of the first character defined in the font.
	CL_String::CharacterType get_first_char() const;

	//: Returns the value of the last character defined in the font
	CL_String::CharacterType get_last_char() const;

	//: Returns the value of the character to be substituted for characters not in the font.
	CL_String::CharacterType get_default_char() const;

	//: Returns the value of the character that will be used to define word breaks for text justification.
	CL_String::CharacterType get_word_break_char() const;

	//: Returns true if the font is italic.
	bool is_italic() const;

	//: Returns true if the font is underlined.
	bool is_underlined() const;

	//: Returns true if the font is struck out.
	bool is_struck_out() const;

	//: Returns true if the font is a mono space font.
	bool is_fixed_pitch() const;

//! Operations:
public:

//! Implementation:
private:
	CL_SharedPtr<CL_FontMetrics_Impl> impl;
};

#endif
