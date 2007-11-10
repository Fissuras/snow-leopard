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
**    Kenneth Gangstoe
*/

//! clanDisplay="Sprites"
//! header=display.h

#ifndef header_sprite_description
#define header_sprite_description

#include "api_display.h"
#include "../Core/Text/string_types.h"
#include "graphic_context.h"
#include "pixel_buffer.h"
#include "texture.h"
#include <list>

class CL_SpriteDescription_Impl;
class CL_Rect;
class CL_ResourceManager;

//: This class describes a single frame in a sprite description.
//- !group=Display/Sprites!
//- !header=display.h!
class CL_SpriteDescriptionFrame
{
public:
	enum FrameType
	{
		type_pixelbuffer,
		type_texture
	};

public:
	CL_SpriteDescriptionFrame(CL_PixelBuffer pixelbuffer, CL_Rect rect) : pixelbuffer(pixelbuffer), rect(rect), type(type_pixelbuffer) {};
	CL_SpriteDescriptionFrame(CL_Texture texture, CL_Rect rect) : texture(texture), rect(rect), type(type_texture) {};

	CL_PixelBuffer pixelbuffer;
	CL_Texture texture;
	CL_Rect rect;
	FrameType type;
};

//: This class contains everything to construct a sprite - its data, default settings etc.
//- !group=Display/Sprites!
//- !header=display.h!
//- <p>CL_SpriteDescription is used by CL_Sprite to construct itself based
//- on the description. The description class give a big flexibility
//- creating a sprite, individual frames can come from different image
//- sources, or be cut out from an image source using various different
//- techniques.</p>
class CL_API_DISPLAY CL_SpriteDescription
{ 
//! Construction:
public:
	//: Constructs a sprite description.
	//param resource_id: Resource name of a sprite description resource.
	//param resources: Resource manager used to load resource.
	CL_SpriteDescription();

	CL_SpriteDescription(const CL_StringRef &resource_id, CL_ResourceManager *resources, CL_GraphicContext gc);

	CL_SpriteDescription(const CL_SpriteDescription &copy);

	~CL_SpriteDescription();

//! Attributes:
public:
	//: Returns a list over all available frames.
	const std::list<CL_SpriteDescriptionFrame> &get_frames() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_SpriteDescription &operator =(const CL_SpriteDescription &copy);

	//: Adds a single image.
	//param pixelbuffer: Image source.
	//param filename: Filename of image.
	//param vfs: Virtual File System to load image from.
	void add_frame(const CL_PixelBuffer &pixelbuffer);

	void add_frame(const CL_Texture &texture);

	void add_frame(const CL_StringRef &filename, CL_VirtualDirectory dir = CL_VirtualDirectory());

	void add_frames(const CL_Texture &texture, CL_Rect *frames, int num_frames);

	//: Adds images formed in a grid.
	//- <p>This function will cut out a grid of frames from one image.</p>
	//param pixelbuffer: Image source.
	//param texture: Image source.
	//param xpos, ypos: Position of where image grid starts.
	//param width, height: Size of a frame in the grid.
	//param xarray, yarray: Number of columns and rows in grid.
	//param array_skipframes: Number of frames to skip at last gridline.
	//param xspacing, yspacing: Pixel interspacing between grid frames.
	void add_gridclipped_frames(
		const CL_PixelBuffer &pixelbuffer, 
		int xpos, int ypos, 
		int width, int height, 
		int xarray = 1, int yarray = 1, 
		int array_skipframes = 0, 
		int xspacing = 0, int yspacing = 0);

	void add_gridclipped_frames(
		const CL_Texture &texture, 
		int xpos, int ypos, 
		int width, int height, 
		int xarray = 1, int yarray = 1, 
		int array_skipframes = 0, 
		int xspacing = 0, int yspacing = 0);

	//: Adds images separated with pure alpha (within trans_limit).
	//- <p>The alpha clipper will cut out frames from an image based on
	//- the transparency in the picture. It first determines the height
	//- of a row by searching for the first line that it considers
	//- completely transparent. Then it finds the width of each frame on
	//- this line by looking for columns that are completely transparency.</p>
	//param pixelbuffer: Image source.
	//param xpos, ypos: Upper left position where alpha cutting should begin.
	//param trans_limit: Amount of non-transparent alpha allowed before a pixel is not considered transparent.
	void add_alphaclipped_frames(
		const CL_PixelBuffer &pixelbuffer, 
		int xpos = 0, int ypos = 0, 
		double trans_limit = 0.05f);

	//: Adds images separated with pure alpha (within trans_limit).
	//- <p>The alpha clipper will cut out frames from an image based on
	//- the transparency in the picture. It scans the lines horizontally
	//- from top to bottom. As soon as a non-transarent pixel is discovered,
	//- the clipper finds the bounding box for that region and then moves on.</p>
	//param pixelbuffer: Image source.
	//param xpos, ypos: Upper left position where alpha cutting should begin.
	//param trans_limit: Amount of non-transparent alpha allowed before a pixel is not considered transparent.
	void add_alphaclipped_frames_free(
		const CL_PixelBuffer &pixelbuffer, 
		int xpos = 0, int ypos = 0, 
		double trans_limit = 0.05f);

	//: Adds images separated with palette-colours defining the boundaries.
	//param pixelbuffer: Image source.
	//param xpos, ypos: Upper left position where cutting should begin.
	void add_paletteclipped_frames(
		const CL_PixelBuffer &pixelbuffer, 
		int xpos = 0, int ypos = 0);
	
//! Implementation:
private:
	//: SpriteDescription implementation.
	CL_SharedPtr<CL_SpriteDescription_Impl> impl;
};

#endif
