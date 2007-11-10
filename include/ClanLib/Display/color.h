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

#ifndef header_color
#define header_color

#if _MSC_VER > 1000
#pragma once
#endif

#include "api_display.h"
#include "../Core/Text/string_types.h"
#include <vector>

class CL_PixelFormat;
class CL_Colord;

//: Color description class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_Color
{
//! Construction:
public:
	//: Constructs a color.
	//- <p>Color components are specified in the range 0 to 255.</p>
	//- <p>An alpha value of 0 means complete transparency, while 255 means completely opaque (solid).</p>
	//param red: Red color component.
	//param green: Green color component.
	//param blue: Blue color component.
	//param alpha: Alpha (transparency) color component.
	//param hexstr: The colors rgba components as a hexadecimal string of the format "#rrggbbaa", where the '#' and "aa" parts are optional. 
	CL_Color() : color(0) { return; }

	explicit CL_Color(const CL_Colord&);

	CL_Color(unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha = 255)
		: color((alpha<<24) | (red<<16) | (green<<8) | blue) { return; }

	CL_Color(const CL_StringRef &hexstr);

//! Attributes:
public:
	//: Returns the alpha color component, in the range 0-255.
	unsigned int get_alpha() const { return (color >> 24) & 0xff; }

	//: Returns the red color component, in the range 0-255.
	unsigned int get_red() const { return (color >> 16) & 0xff; }

	//: Returns the green color component, in the range 0-255.
	unsigned int get_green() const { return (color >> 8) & 0xff; }

	//: Returns the blue color component, in the range 0-255.
	unsigned int get_blue() const { return color & 0xff; }


	//: Returns the alpha color component, in the range 0-1.
	double get_alpha_d() const { return double(get_alpha()) / 255.0; }

	//: Returns the red color component, in the range 0-1.
	double get_red_d() const { return double(get_red()) / 255.0; }

	//: Returns the green color component, in the range 0-1.
	double get_green_d() const { return double(get_green()) / 255.0; }

	//: Returns the blue color component, in the range 0-1.
	double get_blue_d() const { return double(get_blue()) / 255.0; }

	//: Color in ARGB8888 format.
	unsigned int color;

// Operations:
public:
	//: Color == Color operator (deep compare)
	bool operator==(const CL_Color &c) const
	{ return (color == c.color); }

	//: Color != Color operator (deep compare)
	bool operator!=(const CL_Color &c) const
	{ return (color != c.color); }

	//: Type conversion operator.
	operator CL_Colord() const;

//! Statics:
public:
	//: <img src="../images/aliceblue-chip.png" width=16 height=16 /> rgb(240, 248, 255).
	static CL_Color aliceblue;

	//: <img src="../images/antiquewhite-chip.png" width=16 height=16 /> rgb(250, 235, 215).
	static CL_Color antiquewhite;

	//: <img src="../images/aqua-chip.png" width=16 height=16 /> rgb( 0, 255, 255).
	static CL_Color aqua;

	//: <img src="../images/aquamarine-chip.png" width=16 height=16 /> rgb(127, 255, 212).
	static CL_Color aquamarine;

	//: <img src="../images/azure-chip.png" width=16 height=16 /> rgb(240, 255, 255).
	static CL_Color azure;

	//: <img src="../images/beige-chip.png" width=16 height=16 /> rgb(245, 245, 220).
	static CL_Color beige;

	//: <img src="../images/bisque-chip.png" width=16 height=16 /> rgb(255, 228, 196).
	static CL_Color bisque;

	//: <img src="../images/black-chip.png" width=16 height=16 /> rgb( 0, 0, 0).
	static CL_Color black;

	//: <img src="../images/blanchedalmond-chip.png" width=16 height=16 /> rgb(255, 235, 205).
	static CL_Color blanchedalmond;

	//: <img src="../images/blue-chip.png" width=16 height=16 /> rgb( 0, 0, 255).
	static CL_Color blue;

	//: <img src="../images/blueviolet-chip.png" width=16 height=16 /> rgb(138, 43, 226).
	static CL_Color blueviolet;

	//: <img src="../images/brown-chip.png" width=16 height=16 /> rgb(165, 42, 42).
	static CL_Color brown;

	//: <img src="../images/burlywood-chip.png" width=16 height=16 /> rgb(222, 184, 135).
	static CL_Color burlywood;

	//: <img src="../images/cadetblue-chip.png" width=16 height=16 /> rgb( 95, 158, 160).
	static CL_Color cadetblue;

	//: <img src="../images/chartreuse-chip.png" width=16 height=16 /> rgb(127, 255, 0).
	static CL_Color chartreuse;

	//: <img src="../images/chocolate-chip.png" width=16 height=16 /> rgb(210, 105, 30).
	static CL_Color chocolate;

	//: <img src="../images/coral-chip.png" width=16 height=16 /> rgb(255, 127, 80).
	static CL_Color coral;

	//: <img src="../images/cornflowerblue-chip.png" width=16 height=16 /> rgb(100, 149, 237).
	static CL_Color cornflowerblue;

	//: <img src="../images/cornsilk-chip.png" width=16 height=16 /> rgb(255, 248, 220).
	static CL_Color cornsilk;

	//: <img src="../images/crimson-chip.png" width=16 height=16 /> rgb(220, 20, 60).
	static CL_Color crimson;

	//: <img src="../images/cyan-chip.png" width=16 height=16 /> rgb( 0, 255, 255).
	static CL_Color cyan;

	//: <img src="../images/darkblue-chip.png" width=16 height=16 /> rgb( 0, 0, 139).
	static CL_Color darkblue;

	//: <img src="../images/darkcyan-chip.png" width=16 height=16 /> rgb( 0, 139, 139).
	static CL_Color darkcyan;

	//: <img src="../images/darkgoldenrod-chip.png" width=16 height=16 /> rgb(184, 134, 11).
	static CL_Color darkgoldenrod;

	//: <img src="../images/darkgray-chip.png" width=16 height=16 /> rgb(169, 169, 169).
	static CL_Color darkgray;

	//: <img src="../images/darkgreen-chip.png" width=16 height=16 /> rgb( 0, 100, 0).
	static CL_Color darkgreen;

	//: <img src="../images/darkgrey-chip.png" width=16 height=16 /> rgb(169, 169, 169).
	static CL_Color darkgrey;

	//: <img src="../images/darkkhaki-chip.png" width=16 height=16 /> rgb(189, 183, 107).
	static CL_Color darkkhaki;

	//: <img src="../images/darkmagenta-chip.png" width=16 height=16 /> rgb(139, 0, 139).
	static CL_Color darkmagenta;

	//: <img src="../images/darkolivegreen-chip.png" width=16 height=16 /> rgb( 85, 107, 47).
	static CL_Color darkolivegreen;

	//: <img src="../images/darkorange-chip.png" width=16 height=16 /> rgb(255, 140, 0).
	static CL_Color darkorange;

	//: <img src="../images/darkorchid-chip.png" width=16 height=16 /> rgb(153, 50, 204).
	static CL_Color darkorchid;

	//: <img src="../images/darkred-chip.png" width=16 height=16 /> rgb(139, 0, 0).
	static CL_Color darkred;

	//: <img src="../images/darksalmon-chip.png" width=16 height=16 /> rgb(233, 150, 122).
	static CL_Color darksalmon;

	//: <img src="../images/darkseagreen-chip.png" width=16 height=16 /> rgb(143, 188, 143).
	static CL_Color darkseagreen;

	//: <img src="../images/darkslateblue-chip.png" width=16 height=16 /> rgb( 72, 61, 139).
	static CL_Color darkslateblue;

	//: <img src="../images/darkslategray-chip.png" width=16 height=16 /> rgb( 47, 79, 79).
	static CL_Color darkslategray;

	//: <img src="../images/darkslategrey-chip.png" width=16 height=16 /> rgb( 47, 79, 79).
	static CL_Color darkslategrey;

	//: <img src="../images/darkturquoise-chip.png" width=16 height=16 /> rgb( 0, 206, 209).
	static CL_Color darkturquoise;

	//: <img src="../images/darkviolet-chip.png" width=16 height=16 /> rgb(148, 0, 211).
	static CL_Color darkviolet;

	//: <img src="../images/deeppink-chip.png" width=16 height=16 /> rgb(255, 20, 147).
	static CL_Color deeppink;

	//: <img src="../images/deepskyblue-chip.png" width=16 height=16 /> rgb( 0, 191, 255).
	static CL_Color deepskyblue;

	//: <img src="../images/dimgray-chip.png" width=16 height=16 /> rgb(105, 105, 105).
	static CL_Color dimgray;

	//: <img src="../images/dimgrey-chip.png" width=16 height=16 /> rgb(105, 105, 105).
	static CL_Color dimgrey;

	//: <img src="../images/dodgerblue-chip.png" width=16 height=16 /> rgb( 30, 144, 255).
	static CL_Color dodgerblue;

	//: <img src="../images/firebrick-chip.png" width=16 height=16 /> rgb(178, 34, 34).
	static CL_Color firebrick;

	//: <img src="../images/floralwhite-chip.png" width=16 height=16 /> rgb(255, 250, 240).
	static CL_Color floralwhite;

	//: <img src="../images/forestgreen-chip.png" width=16 height=16 /> rgb( 34, 139, 34).
	static CL_Color forestgreen;

	//: <img src="../images/fuchsia-chip.png" width=16 height=16 /> rgb(255, 0, 255).
	static CL_Color fuchsia;

	//: <img src="../images/gainsboro-chip.png" width=16 height=16 /> rgb(220, 220, 220).
	static CL_Color gainsboro;

	//: <img src="../images/ghostwhite-chip.png" width=16 height=16 /> rgb(248, 248, 255).
	static CL_Color ghostwhite;

	//: <img src="../images/gold-chip.png" width=16 height=16 /> rgb(255, 215, 0).
	static CL_Color gold;

	//: <img src="../images/goldenrod-chip.png" width=16 height=16 /> rgb(218, 165, 32).
	static CL_Color goldenrod;

	//: <img src="../images/gray-chip.png" width=16 height=16 /> rgb(128, 128, 128).
	static CL_Color gray;

	//: <img src="../images/grey-chip.png" width=16 height=16 /> rgb(128, 128, 128).
	static CL_Color grey;

	//: <img src="../images/green-chip.png" width=16 height=16 /> rgb( 0, 128, 0).
	static CL_Color green;

	//: <img src="../images/greenyellow-chip.png" width=16 height=16 /> rgb(173, 255, 47).
	static CL_Color greenyellow;

	//: <img src="../images/honeydew-chip.png" width=16 height=16 /> rgb(240, 255, 240).
	static CL_Color honeydew;

	//: <img src="../images/hotpink-chip.png" width=16 height=16 /> rgb(255, 105, 180).
	static CL_Color hotpink;

	//: <img src="../images/indianred-chip.png" width=16 height=16 /> rgb(205, 92, 92).
	static CL_Color indianred;

	//: <img src="../images/indigo-chip.png" width=16 height=16 /> rgb( 75, 0, 130).
	static CL_Color indigo;

	//: <img src="../images/ivory-chip.png" width=16 height=16 /> rgb(255, 255, 240).
	static CL_Color ivory;

	//: <img src="../images/khaki-chip.png" width=16 height=16 /> rgb(240, 230, 140).
	static CL_Color khaki;

	//: <img src="../images/lavender-chip.png" width=16 height=16 /> rgb(230, 230, 250).
	static CL_Color lavender;

	//: <img src="../images/lavenderblush-chip.png" width=16 height=16 /> rgb(255, 240, 245).
	static CL_Color lavenderblush;

	//: <img src="../images/lawngreen-chip.png" width=16 height=16 /> rgb(124, 252, 0).
	static CL_Color lawngreen;

	//: <img src="../images/lemonchiffon-chip.png" width=16 height=16 /> rgb(255, 250, 205).
	static CL_Color lemonchiffon;

	//: <img src="../images/lightblue-chip.png" width=16 height=16 /> rgb(173, 216, 230).
	static CL_Color lightblue;

	//: <img src="../images/lightcoral-chip.png" width=16 height=16 /> rgb(240, 128, 128).
	static CL_Color lightcoral;

	//: <img src="../images/lightcyan-chip.png" width=16 height=16 /> rgb(224, 255, 255).
	static CL_Color lightcyan;

	//: <img src="../images/lightgoldenrodyellow-chip.png" width=16 height=16 /> rgb(250, 250, 210).
	static CL_Color lightgoldenrodyellow;

	//: <img src="../images/lightgray-chip.png" width=16 height=16 /> rgb(211, 211, 211).
	static CL_Color lightgray;

	//: <img src="../images/lightgreen-chip.png" width=16 height=16 /> rgb(144, 238, 144).
	static CL_Color lightgreen;

	//: <img src="../images/lightgrey-chip.png" width=16 height=16 /> rgb(211, 211, 211).
	static CL_Color lightgrey;

	//: <img src="../images/lightpink-chip.png" width=16 height=16 /> rgb(255, 182, 193).
	static CL_Color lightpink;

	//: <img src="../images/lightsalmon-chip.png" width=16 height=16 /> rgb(255, 160, 122).
	static CL_Color lightsalmon;

	//: <img src="../images/lightseagreen-chip.png" width=16 height=16 /> rgb( 32, 178, 170).
	static CL_Color lightseagreen;

	//: <img src="../images/lightskyblue-chip.png" width=16 height=16 /> rgb(135, 206, 250).
	static CL_Color lightskyblue;

	//: <img src="../images/lightslategray-chip.png" width=16 height=16 /> rgb(119, 136, 153).
	static CL_Color lightslategray;

	//: <img src="../images/lightslategrey-chip.png" width=16 height=16 /> rgb(119, 136, 153).
	static CL_Color lightslategrey;

	//: <img src="../images/lightsteelblue-chip.png" width=16 height=16 /> rgb(176, 196, 222).
	static CL_Color lightsteelblue;

	//: <img src="../images/lightyellow-chip.png" width=16 height=16 /> rgb(255, 255, 224).
	static CL_Color lightyellow;

	//: <img src="../images/lime-chip.png" width=16 height=16 /> rgb( 0, 255, 0).
	static CL_Color lime;

	//: <img src="../images/limegreen-chip.png" width=16 height=16 /> rgb( 50, 205, 50).
	static CL_Color limegreen;

	//: <img src="../images/linen-chip.png" width=16 height=16 /> rgb(250, 240, 230).
	static CL_Color linen;

	//: <img src="../images/magenta-chip.png" width=16 height=16 /> rgb(255, 0, 255).
	static CL_Color magenta;

	//: <img src="../images/maroon-chip.png" width=16 height=16 /> rgb(128, 0, 0).
	static CL_Color maroon;

	//: <img src="../images/mediumaquamarine-chip.png" width=16 height=16 /> rgb(102, 205, 170).
	static CL_Color mediumaquamarine;

	//: <img src="../images/mediumblue-chip.png" width=16 height=16 /> rgb( 0, 0, 205).
	static CL_Color mediumblue;

	//: <img src="../images/mediumorchid-chip.png" width=16 height=16 /> rgb(186, 85, 211).
	static CL_Color mediumorchid;

	//: <img src="../images/mediumpurple-chip.png" width=16 height=16 /> rgb(147, 112, 219).
	static CL_Color mediumpurple;

	//: <img src="../images/mediumseagreen-chip.png" width=16 height=16 /> rgb( 60, 179, 113).
	static CL_Color mediumseagreen;

	//: <img src="../images/mediumslateblue-chip.png" width=16 height=16 /> rgb(123, 104, 238).
	static CL_Color mediumslateblue;

	//: <img src="../images/mediumspringgreen-chip.png" width=16 height=16 /> rgb( 0, 250, 154).
	static CL_Color mediumspringgreen;

	//: <img src="../images/mediumturquoise-chip.png" width=16 height=16 /> rgb( 72, 209, 204).
	static CL_Color mediumturquoise;

	//: <img src="../images/mediumvioletred-chip.png" width=16 height=16 /> rgb(199, 21, 133).
	static CL_Color mediumvioletred;

	//: <img src="../images/midnightblue-chip.png" width=16 height=16 /> rgb( 25, 25, 112).
	static CL_Color midnightblue;

	//: <img src="../images/mintcream-chip.png" width=16 height=16 /> rgb(245, 255, 250).
	static CL_Color mintcream;

	//: <img src="../images/mistyrose-chip.png" width=16 height=16 /> rgb(255, 228, 225).
	static CL_Color mistyrose;

	//: <img src="../images/moccasin-chip.png" width=16 height=16 /> rgb(255, 228, 181).
	static CL_Color moccasin;

	//: <img src="../images/navajowhite-chip.png" width=16 height=16 /> rgb(255, 222, 173).
	static CL_Color navajowhite;

	//: <img src="../images/navy-chip.png" width=16 height=16 /> rgb( 0, 0, 128).
	static CL_Color navy;

	//: <img src="../images/oldlace-chip.png" width=16 height=16 /> rgb(253, 245, 230).
	static CL_Color oldlace;

	//: <img src="../images/olive-chip.png" width=16 height=16 /> rgb(128, 128, 0).
	static CL_Color olive;

	//: <img src="../images/olivedrab-chip.png" width=16 height=16 /> rgb(107, 142, 35).
	static CL_Color olivedrab;

	//: <img src="../images/orange-chip.png" width=16 height=16 /> rgb(255, 165, 0).
	static CL_Color orange;

	//: <img src="../images/orangered-chip.png" width=16 height=16 /> rgb(255, 69, 0).
	static CL_Color orangered;

	//: <img src="../images/orchid-chip.png" width=16 height=16 /> rgb(218, 112, 214).
	static CL_Color orchid;

	//: <img src="../images/palegoldenrod-chip.png" width=16 height=16 /> rgb(238, 232, 170).
	static CL_Color palegoldenrod;

	//: <img src="../images/palegreen-chip.png" width=16 height=16 /> rgb(152, 251, 152).
	static CL_Color palegreen;

	//: <img src="../images/paleturquoise-chip.png" width=16 height=16 /> rgb(175, 238, 238).
	static CL_Color paleturquoise;

	//: <img src="../images/palevioletred-chip.png" width=16 height=16 /> rgb(219, 112, 147).
	static CL_Color palevioletred;

	//: <img src="../images/papayawhip-chip.png" width=16 height=16 /> rgb(255, 239, 213).
	static CL_Color papayawhip;

	//: <img src="../images/peachpuff-chip.png" width=16 height=16 /> rgb(255, 218, 185).
	static CL_Color peachpuff;

	//: <img src="../images/peru-chip.png" width=16 height=16 /> rgb(205, 133, 63).
	static CL_Color peru;

	//: <img src="../images/pink-chip.png" width=16 height=16 /> rgb(255, 192, 203).
	static CL_Color pink;

	//: <img src="../images/plum-chip.png" width=16 height=16 /> rgb(221, 160, 221).
	static CL_Color plum;

	//: <img src="../images/powderblue-chip.png" width=16 height=16 /> rgb(176, 224, 230).
	static CL_Color powderblue;

	//: <img src="../images/purple-chip.png" width=16 height=16 /> rgb(128, 0, 128).
	static CL_Color purple;

	//: <img src="../images/red-chip.png" width=16 height=16 /> rgb(255, 0, 0).
	static CL_Color red;

	//: <img src="../images/rosybrown-chip.png" width=16 height=16 /> rgb(188, 143, 143).
	static CL_Color rosybrown;

	//: <img src="../images/royalblue-chip.png" width=16 height=16 /> rgb( 65, 105, 225).
	static CL_Color royalblue;

	//: <img src="../images/saddlebrown-chip.png" width=16 height=16 /> rgb(139, 69, 19).
	static CL_Color saddlebrown;

	//: <img src="../images/salmon-chip.png" width=16 height=16 /> rgb(250, 128, 114).
	static CL_Color salmon;

	//: <img src="../images/sandybrown-chip.png" width=16 height=16 /> rgb(244, 164, 96).
	static CL_Color sandybrown;

	//: <img src="../images/seagreen-chip.png" width=16 height=16 /> rgb( 46, 139, 87).
	static CL_Color seagreen;

	//: <img src="../images/seashell-chip.png" width=16 height=16 /> rgb(255, 245, 238).
	static CL_Color seashell;

	//: <img src="../images/sienna-chip.png" width=16 height=16 /> rgb(160, 82, 45).
	static CL_Color sienna;

	//: <img src="../images/silver-chip.png" width=16 height=16 /> rgb(192, 192, 192).
	static CL_Color silver;

	//: <img src="../images/skyblue-chip.png" width=16 height=16 /> rgb(135, 206, 235).
	static CL_Color skyblue;

	//: <img src="../images/slateblue-chip.png" width=16 height=16 /> rgb(106, 90, 205).
	static CL_Color slateblue;

	//: <img src="../images/slategray-chip.png" width=16 height=16 /> rgb(112, 128, 144).
	static CL_Color slategray;

	//: <img src="../images/slategrey-chip.png" width=16 height=16 /> rgb(112, 128, 144).
	static CL_Color slategrey;

	//: <img src="../images/snow-chip.png" width=16 height=16 /> rgb(255, 250, 250).
	static CL_Color snow;

	//: <img src="../images/springgreen-chip.png" width=16 height=16 /> rgb( 0, 255, 127).
	static CL_Color springgreen;

	//: <img src="../images/steelblue-chip.png" width=16 height=16 /> rgb( 70, 130, 180).
	static CL_Color steelblue;

	//: <img src="../images/tan-chip.png" width=16 height=16 /> rgb(210, 180, 140).
	static CL_Color tan;

	//: <img src="../images/teal-chip.png" width=16 height=16 /> rgb( 0, 128, 128).
	static CL_Color teal;

	//: <img src="../images/thistle-chip.png" width=16 height=16 /> rgb(216, 191, 216).
	static CL_Color thistle;

	//: <img src="../images/tomato-chip.png" width=16 height=16 /> rgb(255, 99, 71).
	static CL_Color tomato;

	//: <img src="../images/turquoise-chip.png" width=16 height=16 /> rgb( 64, 224, 208).
	static CL_Color turquoise;

	//: <img src="../images/violet-chip.png" width=16 height=16 /> rgb(238, 130, 238).
	static CL_Color violet;

	//: <img src="../images/wheat-chip.png" width=16 height=16 /> rgb(245, 222, 179).
	static CL_Color wheat;

	//: <img src="../images/white-chip.png" width=16 height=16 /> rgb(255, 255, 255).
	static CL_Color white;

	//: <img src="../images/whitesmoke-chip.png" width=16 height=16 /> rgb(245, 245, 245).
	static CL_Color whitesmoke;

	//: <img src="../images/yellow-chip.png" width=16 height=16 /> rgb(255, 255, 0).
	static CL_Color yellow;

	//: <img src="../images/yellowgreen-chip.png" width=16 height=16 /> rgb(154, 205, 50).
	static CL_Color yellowgreen;

	//: rgba(0, 0, 0, 0).
	static CL_Color transparent;

	//: Find and returns the static color matching a string.
	//param name: Name of color to match, eg. "blue".
	//return: Reference to matching static color, or transparent (rgba(0,0,0,0)) if there was no match.
	static CL_Color find_color(const CL_StringRef &name);
	
	//: Returns the names of static colors defined.
	static std::vector<CL_String8> &get_names();

//! Operations:
public:
	//: Set alpha color component, in the range 0-255.
	void set_alpha(unsigned int value) { color = (color & 0x00ffffff) | (value << 24); }

	//: Set red color component, in the range 0-255.
	void set_red(unsigned int value) { color = (color & 0xff00ffff) | (value << 16); }

	//: Set green color component, in the range 0-255.
	void set_green(unsigned int value) { color = (color & 0xffff00ff) | (value << 8); }

	//: Set blue color component, in the range 0-255.
	void set_blue(unsigned int value) { color = (color & 0xffffff00) | value; }


	//: Set alpha color component, in the range 0-1.
	void set_alpha_d(double value) { set_alpha((unsigned int) (value*255)); }

	//: Set red color component, in the range 0-1.
	void set_red_d(double value) { set_red((unsigned int) (value*255)); }

	//: Set green color component, in the range 0-1.
	void set_green_d(double value) { set_green((unsigned int) (value*255)); }

	//: Set blue color component, in the range 0-1.
	void set_blue_d(double value) { set_blue((unsigned int) (value*255)); }

	//: Set color based on rgba color components in the range 0-255.
	void set_color(unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha = 255)
	{ color = (alpha<<24) | (red<<16) | (green<<8) | blue; }

	//: Set color based on rgba color components in the range 0-1.
	void set_color_d(double red, double green, double blue, double alpha = 1.0)
	{
		color = 
			(((unsigned int) (alpha*255))<<24) |
			(((unsigned int) (red*255))<<16) |
			(((unsigned int) (green*255))<<8) |
			((unsigned int) (blue*255));
	}

	//: Converts the color to a given pixel format.
	unsigned int to_pixelformat(const CL_PixelFormat &pf) const;

	//: Converts a raw pixel in a given pixel format to a color.
	static CL_Color from_pixelformat(unsigned int raw_color, const CL_PixelFormat &pf);
};

//: Floating point color description class.
//- !group=Display/Display!
//- !header=display.h!
class CL_Colord
{
//! Construction:
public:
	//: Constructs a color.
	//- <p>Color components are specified in the range 0 to 255.</p>
	//- <p>An alpha value of 0 means complete transparency, while 255 means completely opaque (solid).</p>
	//param red: Red color component.
	//param green: Green color component.
	//param blue: Blue color component.
	//param alpha: Alpha (transparency) color component.
	//param hexstr: The colors rgba components as a hexadecimal string of the format "#rrggbbaa", where the '#' and "aa" parts are optional. 
	CL_Colord() : r(0.0), g(0.0), b(0.0), a(0.0)
	{
	}

	CL_Colord(double r, double g, double b, double a = 1.0)
		: r(r), g(g), b(b), a(a)
	{
	}

	CL_Colord(unsigned char r, unsigned char g, unsigned char b, unsigned char a=255)
		: r(r/255.0),
		  g(g/255.0),
		  b(b/255.0),
		  a(a/255.0)
	{
	}

	explicit CL_Colord(const CL_Color& color)
		: r(color.get_red()/255.0), 
		  g(color.get_green()/255.0), 
		  b(color.get_blue()/255.0), 
		  a(color.get_alpha()/255.0)
	{
	}

	CL_Colord(const CL_StringRef &hexstr)
	{
		*this = (CL_Colord)CL_Color::find_color(hexstr);
	}


//! Attributes:
public:
	double r, g, b, a;

	double get_red() const { return r; }
	double get_green() const { return g; }
	double get_blue() const { return b; }
	double get_alpha() const { return a; }

//! Operations:
public:
	//: Normalize the color by ensuring that all color values lie inbetween (0.0, 1.0)
	void normalize() 
	{
		r = (r < 0.0) ? 0.0 : ((r > 1.0) ? 1.0 : r);
		g = (g < 0.0) ? 0.0 : ((g > 1.0) ? 1.0 : g);
		b = (b < 0.0) ? 0.0 : ((b > 1.0) ? 1.0 : b);
		a = (a < 0.0) ? 0.0 : ((a > 1.0) ? 1.0 : a);
	}

	//: Set alpha color component, in the range 0-1.
	void set_alpha(double value) { a = value; }

	//: Set red color component, in the range 0-1.
	void set_red(double value) {  r = value; }

	//: Set green color component, in the range 0-1.
	void set_green(double value) { g= value; }

	//: Set blue color component, in the range 0-1.
	void set_blue(double value) { b = value; }


	//: Color == Color operator (deep compare)
	bool operator==(const CL_Colord &c) const
	{
		return (r == c.r) && (g == c.g) && (b == c.b) && (a == c.a);
	}

	//: Color != Color operator (deep compare)
	bool operator!=(const CL_Colord &c) const
	{
		return (r != c.r) || (g != c.g) || (b != c.b) || (a != c.a);
	}

	//: Type conversion operator.
	operator CL_Color() const
	{
		return CL_Color(*this);
	}

//! Statics:
public:
	//: <img src="../images/aliceblue-chip.png" width=16 height=16 /> rgb(240, 248, 255).
	static CL_Colord aliceblue;

	//: <img src="../images/antiquewhite-chip.png" width=16 height=16 /> rgb(250, 235, 215).
	static CL_Colord antiquewhite;

	//: <img src="../images/aqua-chip.png" width=16 height=16 /> rgb( 0, 255, 255).
	static CL_Colord aqua;

	//: <img src="../images/aquamarine-chip.png" width=16 height=16 /> rgb(127, 255, 212).
	static CL_Colord aquamarine;

	//: <img src="../images/azure-chip.png" width=16 height=16 /> rgb(240, 255, 255).
	static CL_Colord azure;

	//: <img src="../images/beige-chip.png" width=16 height=16 /> rgb(245, 245, 220).
	static CL_Colord beige;

	//: <img src="../images/bisque-chip.png" width=16 height=16 /> rgb(255, 228, 196).
	static CL_Colord bisque;

	//: <img src="../images/black-chip.png" width=16 height=16 /> rgb( 0, 0, 0).
	static CL_Colord black;

	//: <img src="../images/blanchedalmond-chip.png" width=16 height=16 /> rgb(255, 235, 205).
	static CL_Colord blanchedalmond;

	//: <img src="../images/blue-chip.png" width=16 height=16 /> rgb( 0, 0, 255).
	static CL_Colord blue;

	//: <img src="../images/blueviolet-chip.png" width=16 height=16 /> rgb(138, 43, 226).
	static CL_Colord blueviolet;

	//: <img src="../images/brown-chip.png" width=16 height=16 /> rgb(165, 42, 42).
	static CL_Colord brown;

	//: <img src="../images/burlywood-chip.png" width=16 height=16 /> rgb(222, 184, 135).
	static CL_Colord burlywood;

	//: <img src="../images/cadetblue-chip.png" width=16 height=16 /> rgb( 95, 158, 160).
	static CL_Colord cadetblue;

	//: <img src="../images/chartreuse-chip.png" width=16 height=16 /> rgb(127, 255, 0).
	static CL_Colord chartreuse;

	//: <img src="../images/chocolate-chip.png" width=16 height=16 /> rgb(210, 105, 30).
	static CL_Colord chocolate;

	//: <img src="../images/coral-chip.png" width=16 height=16 /> rgb(255, 127, 80).
	static CL_Colord coral;

	//: <img src="../images/cornflowerblue-chip.png" width=16 height=16 /> rgb(100, 149, 237).
	static CL_Colord cornflowerblue;

	//: <img src="../images/cornsilk-chip.png" width=16 height=16 /> rgb(255, 248, 220).
	static CL_Colord cornsilk;

	//: <img src="../images/crimson-chip.png" width=16 height=16 /> rgb(220, 20, 60).
	static CL_Colord crimson;

	//: <img src="../images/cyan-chip.png" width=16 height=16 /> rgb( 0, 255, 255).
	static CL_Colord cyan;

	//: <img src="../images/darkblue-chip.png" width=16 height=16 /> rgb( 0, 0, 139).
	static CL_Colord darkblue;

	//: <img src="../images/darkcyan-chip.png" width=16 height=16 /> rgb( 0, 139, 139).
	static CL_Colord darkcyan;

	//: <img src="../images/darkgoldenrod-chip.png" width=16 height=16 /> rgb(184, 134, 11).
	static CL_Colord darkgoldenrod;

	//: <img src="../images/darkgray-chip.png" width=16 height=16 /> rgb(169, 169, 169).
	static CL_Colord darkgray;

	//: <img src="../images/darkgreen-chip.png" width=16 height=16 /> rgb( 0, 100, 0).
	static CL_Colord darkgreen;

	//: <img src="../images/darkgrey-chip.png" width=16 height=16 /> rgb(169, 169, 169).
	static CL_Colord darkgrey;

	//: <img src="../images/darkkhaki-chip.png" width=16 height=16 /> rgb(189, 183, 107).
	static CL_Colord darkkhaki;

	//: <img src="../images/darkmagenta-chip.png" width=16 height=16 /> rgb(139, 0, 139).
	static CL_Colord darkmagenta;

	//: <img src="../images/darkolivegreen-chip.png" width=16 height=16 /> rgb( 85, 107, 47).
	static CL_Colord darkolivegreen;

	//: <img src="../images/darkorange-chip.png" width=16 height=16 /> rgb(255, 140, 0).
	static CL_Colord darkorange;

	//: <img src="../images/darkorchid-chip.png" width=16 height=16 /> rgb(153, 50, 204).
	static CL_Colord darkorchid;

	//: <img src="../images/darkred-chip.png" width=16 height=16 /> rgb(139, 0, 0).
	static CL_Colord darkred;

	//: <img src="../images/darksalmon-chip.png" width=16 height=16 /> rgb(233, 150, 122).
	static CL_Colord darksalmon;

	//: <img src="../images/darkseagreen-chip.png" width=16 height=16 /> rgb(143, 188, 143).
	static CL_Colord darkseagreen;

	//: <img src="../images/darkslateblue-chip.png" width=16 height=16 /> rgb( 72, 61, 139).
	static CL_Colord darkslateblue;

	//: <img src="../images/darkslategray-chip.png" width=16 height=16 /> rgb( 47, 79, 79).
	static CL_Colord darkslategray;

	//: <img src="../images/darkslategrey-chip.png" width=16 height=16 /> rgb( 47, 79, 79).
	static CL_Colord darkslategrey;

	//: <img src="../images/darkturquoise-chip.png" width=16 height=16 /> rgb( 0, 206, 209).
	static CL_Colord darkturquoise;

	//: <img src="../images/darkviolet-chip.png" width=16 height=16 /> rgb(148, 0, 211).
	static CL_Colord darkviolet;

	//: <img src="../images/deeppink-chip.png" width=16 height=16 /> rgb(255, 20, 147).
	static CL_Colord deeppink;

	//: <img src="../images/deepskyblue-chip.png" width=16 height=16 /> rgb( 0, 191, 255).
	static CL_Colord deepskyblue;

	//: <img src="../images/dimgray-chip.png" width=16 height=16 /> rgb(105, 105, 105).
	static CL_Colord dimgray;

	//: <img src="../images/dimgrey-chip.png" width=16 height=16 /> rgb(105, 105, 105).
	static CL_Colord dimgrey;

	//: <img src="../images/dodgerblue-chip.png" width=16 height=16 /> rgb( 30, 144, 255).
	static CL_Colord dodgerblue;

	//: <img src="../images/firebrick-chip.png" width=16 height=16 /> rgb(178, 34, 34).
	static CL_Colord firebrick;

	//: <img src="../images/floralwhite-chip.png" width=16 height=16 /> rgb(255, 250, 240).
	static CL_Colord floralwhite;

	//: <img src="../images/forestgreen-chip.png" width=16 height=16 /> rgb( 34, 139, 34).
	static CL_Colord forestgreen;

	//: <img src="../images/fuchsia-chip.png" width=16 height=16 /> rgb(255, 0, 255).
	static CL_Colord fuchsia;

	//: <img src="../images/gainsboro-chip.png" width=16 height=16 /> rgb(220, 220, 220).
	static CL_Colord gainsboro;

	//: <img src="../images/ghostwhite-chip.png" width=16 height=16 /> rgb(248, 248, 255).
	static CL_Colord ghostwhite;

	//: <img src="../images/gold-chip.png" width=16 height=16 /> rgb(255, 215, 0).
	static CL_Colord gold;

	//: <img src="../images/goldenrod-chip.png" width=16 height=16 /> rgb(218, 165, 32).
	static CL_Colord goldenrod;

	//: <img src="../images/gray-chip.png" width=16 height=16 /> rgb(128, 128, 128).
	static CL_Colord gray;

	//: <img src="../images/grey-chip.png" width=16 height=16 /> rgb(128, 128, 128).
	static CL_Colord grey;

	//: <img src="../images/green-chip.png" width=16 height=16 /> rgb( 0, 128, 0).
	static CL_Colord green;

	//: <img src="../images/greenyellow-chip.png" width=16 height=16 /> rgb(173, 255, 47).
	static CL_Colord greenyellow;

	//: <img src="../images/honeydew-chip.png" width=16 height=16 /> rgb(240, 255, 240).
	static CL_Colord honeydew;

	//: <img src="../images/hotpink-chip.png" width=16 height=16 /> rgb(255, 105, 180).
	static CL_Colord hotpink;

	//: <img src="../images/indianred-chip.png" width=16 height=16 /> rgb(205, 92, 92).
	static CL_Colord indianred;

	//: <img src="../images/indigo-chip.png" width=16 height=16 /> rgb( 75, 0, 130).
	static CL_Colord indigo;

	//: <img src="../images/ivory-chip.png" width=16 height=16 /> rgb(255, 255, 240).
	static CL_Colord ivory;

	//: <img src="../images/khaki-chip.png" width=16 height=16 /> rgb(240, 230, 140).
	static CL_Colord khaki;

	//: <img src="../images/lavender-chip.png" width=16 height=16 /> rgb(230, 230, 250).
	static CL_Colord lavender;

	//: <img src="../images/lavenderblush-chip.png" width=16 height=16 /> rgb(255, 240, 245).
	static CL_Colord lavenderblush;

	//: <img src="../images/lawngreen-chip.png" width=16 height=16 /> rgb(124, 252, 0).
	static CL_Colord lawngreen;

	//: <img src="../images/lemonchiffon-chip.png" width=16 height=16 /> rgb(255, 250, 205).
	static CL_Colord lemonchiffon;

	//: <img src="../images/lightblue-chip.png" width=16 height=16 /> rgb(173, 216, 230).
	static CL_Colord lightblue;

	//: <img src="../images/lightcoral-chip.png" width=16 height=16 /> rgb(240, 128, 128).
	static CL_Colord lightcoral;

	//: <img src="../images/lightcyan-chip.png" width=16 height=16 /> rgb(224, 255, 255).
	static CL_Colord lightcyan;

	//: <img src="../images/lightgoldenrodyellow-chip.png" width=16 height=16 /> rgb(250, 250, 210).
	static CL_Colord lightgoldenrodyellow;

	//: <img src="../images/lightgray-chip.png" width=16 height=16 /> rgb(211, 211, 211).
	static CL_Colord lightgray;

	//: <img src="../images/lightgreen-chip.png" width=16 height=16 /> rgb(144, 238, 144).
	static CL_Colord lightgreen;

	//: <img src="../images/lightgrey-chip.png" width=16 height=16 /> rgb(211, 211, 211).
	static CL_Colord lightgrey;

	//: <img src="../images/lightpink-chip.png" width=16 height=16 /> rgb(255, 182, 193).
	static CL_Colord lightpink;

	//: <img src="../images/lightsalmon-chip.png" width=16 height=16 /> rgb(255, 160, 122).
	static CL_Colord lightsalmon;

	//: <img src="../images/lightseagreen-chip.png" width=16 height=16 /> rgb( 32, 178, 170).
	static CL_Colord lightseagreen;

	//: <img src="../images/lightskyblue-chip.png" width=16 height=16 /> rgb(135, 206, 250).
	static CL_Colord lightskyblue;

	//: <img src="../images/lightslategray-chip.png" width=16 height=16 /> rgb(119, 136, 153).
	static CL_Colord lightslategray;

	//: <img src="../images/lightslategrey-chip.png" width=16 height=16 /> rgb(119, 136, 153).
	static CL_Colord lightslategrey;

	//: <img src="../images/lightsteelblue-chip.png" width=16 height=16 /> rgb(176, 196, 222).
	static CL_Colord lightsteelblue;

	//: <img src="../images/lightyellow-chip.png" width=16 height=16 /> rgb(255, 255, 224).
	static CL_Colord lightyellow;

	//: <img src="../images/lime-chip.png" width=16 height=16 /> rgb( 0, 255, 0).
	static CL_Colord lime;

	//: <img src="../images/limegreen-chip.png" width=16 height=16 /> rgb( 50, 205, 50).
	static CL_Colord limegreen;

	//: <img src="../images/linen-chip.png" width=16 height=16 /> rgb(250, 240, 230).
	static CL_Colord linen;

	//: <img src="../images/magenta-chip.png" width=16 height=16 /> rgb(255, 0, 255).
	static CL_Colord magenta;

	//: <img src="../images/maroon-chip.png" width=16 height=16 /> rgb(128, 0, 0).
	static CL_Colord maroon;

	//: <img src="../images/mediumaquamarine-chip.png" width=16 height=16 /> rgb(102, 205, 170).
	static CL_Colord mediumaquamarine;

	//: <img src="../images/mediumblue-chip.png" width=16 height=16 /> rgb( 0, 0, 205).
	static CL_Colord mediumblue;

	//: <img src="../images/mediumorchid-chip.png" width=16 height=16 /> rgb(186, 85, 211).
	static CL_Colord mediumorchid;

	//: <img src="../images/mediumpurple-chip.png" width=16 height=16 /> rgb(147, 112, 219).
	static CL_Colord mediumpurple;

	//: <img src="../images/mediumseagreen-chip.png" width=16 height=16 /> rgb( 60, 179, 113).
	static CL_Colord mediumseagreen;

	//: <img src="../images/mediumslateblue-chip.png" width=16 height=16 /> rgb(123, 104, 238).
	static CL_Colord mediumslateblue;

	//: <img src="../images/mediumspringgreen-chip.png" width=16 height=16 /> rgb( 0, 250, 154).
	static CL_Colord mediumspringgreen;

	//: <img src="../images/mediumturquoise-chip.png" width=16 height=16 /> rgb( 72, 209, 204).
	static CL_Colord mediumturquoise;

	//: <img src="../images/mediumvioletred-chip.png" width=16 height=16 /> rgb(199, 21, 133).
	static CL_Colord mediumvioletred;

	//: <img src="../images/midnightblue-chip.png" width=16 height=16 /> rgb( 25, 25, 112).
	static CL_Colord midnightblue;

	//: <img src="../images/mintcream-chip.png" width=16 height=16 /> rgb(245, 255, 250).
	static CL_Colord mintcream;

	//: <img src="../images/mistyrose-chip.png" width=16 height=16 /> rgb(255, 228, 225).
	static CL_Colord mistyrose;

	//: <img src="../images/moccasin-chip.png" width=16 height=16 /> rgb(255, 228, 181).
	static CL_Colord moccasin;

	//: <img src="../images/navajowhite-chip.png" width=16 height=16 /> rgb(255, 222, 173).
	static CL_Colord navajowhite;

	//: <img src="../images/navy-chip.png" width=16 height=16 /> rgb( 0, 0, 128).
	static CL_Colord navy;

	//: <img src="../images/oldlace-chip.png" width=16 height=16 /> rgb(253, 245, 230).
	static CL_Colord oldlace;

	//: <img src="../images/olive-chip.png" width=16 height=16 /> rgb(128, 128, 0).
	static CL_Colord olive;

	//: <img src="../images/olivedrab-chip.png" width=16 height=16 /> rgb(107, 142, 35).
	static CL_Colord olivedrab;

	//: <img src="../images/orange-chip.png" width=16 height=16 /> rgb(255, 165, 0).
	static CL_Colord orange;

	//: <img src="../images/orangered-chip.png" width=16 height=16 /> rgb(255, 69, 0).
	static CL_Colord orangered;

	//: <img src="../images/orchid-chip.png" width=16 height=16 /> rgb(218, 112, 214).
	static CL_Colord orchid;

	//: <img src="../images/palegoldenrod-chip.png" width=16 height=16 /> rgb(238, 232, 170).
	static CL_Colord palegoldenrod;

	//: <img src="../images/palegreen-chip.png" width=16 height=16 /> rgb(152, 251, 152).
	static CL_Colord palegreen;

	//: <img src="../images/paleturquoise-chip.png" width=16 height=16 /> rgb(175, 238, 238).
	static CL_Colord paleturquoise;

	//: <img src="../images/palevioletred-chip.png" width=16 height=16 /> rgb(219, 112, 147).
	static CL_Colord palevioletred;

	//: <img src="../images/papayawhip-chip.png" width=16 height=16 /> rgb(255, 239, 213).
	static CL_Colord papayawhip;

	//: <img src="../images/peachpuff-chip.png" width=16 height=16 /> rgb(255, 218, 185).
	static CL_Colord peachpuff;

	//: <img src="../images/peru-chip.png" width=16 height=16 /> rgb(205, 133, 63).
	static CL_Colord peru;

	//: <img src="../images/pink-chip.png" width=16 height=16 /> rgb(255, 192, 203).
	static CL_Colord pink;

	//: <img src="../images/plum-chip.png" width=16 height=16 /> rgb(221, 160, 221).
	static CL_Colord plum;

	//: <img src="../images/powderblue-chip.png" width=16 height=16 /> rgb(176, 224, 230).
	static CL_Colord powderblue;

	//: <img src="../images/purple-chip.png" width=16 height=16 /> rgb(128, 0, 128).
	static CL_Colord purple;

	//: <img src="../images/red-chip.png" width=16 height=16 /> rgb(255, 0, 0).
	static CL_Colord red;

	//: <img src="../images/rosybrown-chip.png" width=16 height=16 /> rgb(188, 143, 143).
	static CL_Colord rosybrown;

	//: <img src="../images/royalblue-chip.png" width=16 height=16 /> rgb( 65, 105, 225).
	static CL_Colord royalblue;

	//: <img src="../images/saddlebrown-chip.png" width=16 height=16 /> rgb(139, 69, 19).
	static CL_Colord saddlebrown;

	//: <img src="../images/salmon-chip.png" width=16 height=16 /> rgb(250, 128, 114).
	static CL_Colord salmon;

	//: <img src="../images/sandybrown-chip.png" width=16 height=16 /> rgb(244, 164, 96).
	static CL_Colord sandybrown;

	//: <img src="../images/seagreen-chip.png" width=16 height=16 /> rgb( 46, 139, 87).
	static CL_Colord seagreen;

	//: <img src="../images/seashell-chip.png" width=16 height=16 /> rgb(255, 245, 238).
	static CL_Colord seashell;

	//: <img src="../images/sienna-chip.png" width=16 height=16 /> rgb(160, 82, 45).
	static CL_Colord sienna;

	//: <img src="../images/silver-chip.png" width=16 height=16 /> rgb(192, 192, 192).
	static CL_Colord silver;

	//: <img src="../images/skyblue-chip.png" width=16 height=16 /> rgb(135, 206, 235).
	static CL_Colord skyblue;

	//: <img src="../images/slateblue-chip.png" width=16 height=16 /> rgb(106, 90, 205).
	static CL_Colord slateblue;

	//: <img src="../images/slategray-chip.png" width=16 height=16 /> rgb(112, 128, 144).
	static CL_Colord slategray;

	//: <img src="../images/slategrey-chip.png" width=16 height=16 /> rgb(112, 128, 144).
	static CL_Colord slategrey;

	//: <img src="../images/snow-chip.png" width=16 height=16 /> rgb(255, 250, 250).
	static CL_Colord snow;

	//: <img src="../images/springgreen-chip.png" width=16 height=16 /> rgb( 0, 255, 127).
	static CL_Colord springgreen;

	//: <img src="../images/steelblue-chip.png" width=16 height=16 /> rgb( 70, 130, 180).
	static CL_Colord steelblue;

	//: <img src="../images/tan-chip.png" width=16 height=16 /> rgb(210, 180, 140).
	static CL_Colord tan;

	//: <img src="../images/teal-chip.png" width=16 height=16 /> rgb( 0, 128, 128).
	static CL_Colord teal;

	//: <img src="../images/thistle-chip.png" width=16 height=16 /> rgb(216, 191, 216).
	static CL_Colord thistle;

	//: <img src="../images/tomato-chip.png" width=16 height=16 /> rgb(255, 99, 71).
	static CL_Colord tomato;

	//: <img src="../images/turquoise-chip.png" width=16 height=16 /> rgb( 64, 224, 208).
	static CL_Colord turquoise;

	//: <img src="../images/violet-chip.png" width=16 height=16 /> rgb(238, 130, 238).
	static CL_Colord violet;

	//: <img src="../images/wheat-chip.png" width=16 height=16 /> rgb(245, 222, 179).
	static CL_Colord wheat;

	//: <img src="../images/white-chip.png" width=16 height=16 /> rgb(255, 255, 255).
	static CL_Colord white;

	//: <img src="../images/whitesmoke-chip.png" width=16 height=16 /> rgb(245, 245, 245).
	static CL_Colord whitesmoke;

	//: <img src="../images/yellow-chip.png" width=16 height=16 /> rgb(255, 255, 0).
	static CL_Colord yellow;

	//: <img src="../images/yellowgreen-chip.png" width=16 height=16 /> rgb(154, 205, 50).
	static CL_Colord yellowgreen;

	//: rgba(0, 0, 0, 0).
	static CL_Colord transparent;

};

#endif
