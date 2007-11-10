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

#ifndef header_texture
#define header_texture

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/Text/string_types.h"
#include "../Core/IOData/virtual_directory.h"
#include "../Core/Resources/resource_data_session.h"
#include "../GL/opengl_wrap.h"
#include "graphic_context.h"
#include "compare_function.h"

class CL_Color;
class CL_Rect;
class CL_Point;
class CL_PixelBuffer;
class CL_PixelFormat;
class CL_TextureProvider;
class CL_DataBuffer;
class CL_Texture_Impl;

//: Texture coordinate wrapping modes.
//- !group=Display/Display!
//- !header=display.h!
enum CL_TextureWrapMode
{
	cl_wrap_clamp,
	cl_wrap_clamp_to_edge,
	cl_wrap_clamp_to_border,
	cl_wrap_repeat,
	cl_wrap_mirrored_repeat
};

//: Texture filters.
//- !group=Display/Display!
//- !header=display.h!
enum CL_TextureFilter
{
	cl_filter_nearest,
	cl_filter_linear,
	cl_filter_nearest_mipmap_nearest,
	cl_filter_nearest_mipmap_linear,
	cl_filter_linear_mipmap_nearest,
	cl_filter_linear_mipmap_linear
};

//: Texture depth modes.
//- !group=Display/Display!
//- !header=display.h!
enum CL_TextureDepthMode
{
	cl_depthmode_luminance,
	cl_depthmode_intensity,
	cl_depthmode_alpha
};

//: Texture compare modes.
//- !group=Display/Display!
//- !header=display.h!
enum CL_TextureCompareMode
{
	cl_comparemode_none,
	cl_comparemode_compare_r_to_texture
};

//: Texture dimensions.
//- !group=Display/Display!
//- !header=display.h!
enum CL_TextureDimensions
{
	cl_texture_1d,
	cl_texture_2d,
	cl_texture_3d,
	cl_texture_cube_map
};

//: Texture format.
//- !group=Display/Display!
//- !header=display.h!
// to do: change this to an enum or a description class instead of using OpenGL constants.
typedef CLenum CL_TextureFormat;

//: Texture object class.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_Texture
{
//! Construction:
public:
	//: Constructs a texture.
	CL_Texture();

	CL_Texture(CL_GraphicContext context, CL_TextureDimensions texture_dimensions);

	CL_Texture(CL_GraphicContext context, int width, int height, CL_TextureFormat internal_format = CL_RGBA);

	CL_Texture(
		CL_GraphicContext context,
		const CL_StringRef &filename,
		const CL_VirtualDirectory &directory = CL_VirtualDirectory(),
		bool make_texture_nearest_power_of_two = true);

	CL_Texture(
		const CL_StringRef &resource_id,
		CL_ResourceManager *resources,
		CL_GraphicContext gc);

	virtual ~CL_Texture();

//! Attributes:
public:
	//: Returns true if this is a null texture.
	bool is_null() const;

	//: Get the texture width.
	//param level: Mipmap level to get width for.
	int get_width(int level = 0) const;

	//: Get the texture height.
	//param level: Mipmap level to get height for.
	int get_height(int level = 0) const;

	//: Get the texture size.
	CL_Size get_size() const;

	//: Get the texture depth.
	int get_depth() const;

	//: Retrieve image data from texture.
	CL_PixelBuffer get_pixeldata(int level = 0);

	CL_PixelBuffer get_pixeldata(CL_PixelFormat &format, int level = 0);

	//: Get the minimum level of detail.
	double get_min_lod() const;

	//: Get the maximum level of detail.
	double get_max_lod() const;

	//: Get the level of detail bias constant.
	double get_lod_bias() const;

	//: Get the texture base level.
	int get_base_level() const;

	//: Get the texture max level.
	int get_max_level() const;

	//: Get if automatic mipmap generation is enabled.
	bool get_generate_mipmap() const;

	//: Get the texture wrap mode for the s coordinate.
	CL_TextureWrapMode get_wrap_mode_s() const;

	//: Get the texture wrap mode for the t coordinate.
	CL_TextureWrapMode get_wrap_mode_t() const;

	//: Get the texture wrap mode for the r coordinate.
	CL_TextureWrapMode get_wrap_mode_r() const;

	//: Get the texture minification filter.
	CL_TextureFilter get_min_filter() const;

	//: Get the texture magnification filter.
	CL_TextureFilter get_mag_filter() const;

	//: Get the texture border color.
	CL_Colord get_border_color() const;

	//: Get the texture priority.
	double get_priority() const;
	
	//: Returns true if texture is resident in texture memory.
	bool is_resident() const;

	//: Get the texture depth mode.
	CL_TextureDepthMode get_depth_mode() const;

	//: Get the texture compare mode.
	CL_TextureCompareMode get_compare_mode() const;

	//: Get the texture compare function.
	CL_CompareFunction get_compare_function() const;

	CL_TextureProvider *get_provider() const;

//! Operations:
public:
	//: Upload image to texture.
	//param image: Image to upload.
	//param level: Mipmap level-of-detail number.
	//param border: Border width of texture.
	//param format: Internal texture format of texture.
	void set_image(
		CL_PixelBuffer &image,
		int level = 0,
		int border = 0,
		int format = CL_RGBA);

	//: Upload cube map.
	void set_cube_map(
		CL_PixelBuffer &cube_map_positive_x,
		CL_PixelBuffer &cube_map_negative_x,
		CL_PixelBuffer &cube_map_positive_y,
		CL_PixelBuffer &cube_map_negative_y,
		CL_PixelBuffer &cube_map_positive_z,
		CL_PixelBuffer &cube_map_negative_z,
		int level = 0,
		int border = 0,
		int format = CL_RGBA);

	void set_compressed_image(
		int level,
		int format,
		int width,
		int height,
		CL_DataBuffer &image);

	//: Upload image to sub texture.
	//param image: Image to upload.
	//param level: Mipmap level-of-detail number.
	void set_subimage(
		int x,
		int y,
		CL_PixelBuffer &image,
		int level = 0);

	void set_subimage(
		const CL_Point &point,
		CL_PixelBuffer &image,
		int level = 0);

	//: Copy image data from a graphic context.
	void copy_image_from(
		int level,
		int border = 0,
		int format = CL_RGBA,
		CL_GraphicContext *gc = 0);

	void copy_image_from(
		int x,
		int y,
		int width,
		int height,
		int level = 0,
		int border = 0,
		int format = CL_RGBA,
		CL_GraphicContext *gc = 0);
	
	void copy_image_from(
		const CL_Rect &pos,
		int level = 0,
		int border = 0,
		int format = CL_RGBA,
		CL_GraphicContext *gc = 0);

	//: Copy sub image data from a graphic context.
	void copy_subimage_from(
		int offset_x,
		int offset_y,
		int x,
		int y,
		int width,
		int height,
		int level = 0,
		CL_GraphicContext *gc = 0);
	
	void copy_subimage_from(
		const CL_Point &offset,
		const CL_Rect &pos,
		int level = 0,
		CL_GraphicContext *gc = 0);

	//: Set the minimum level of detail texture parameter.
	void set_min_lod(double min_lod);

	//: Set the maximum level of detail texture parameter.
	void set_max_lod(double max_lod);

	//: Sets the level of detail bias constant.
	void set_lod_bias(double lod_bias);

	//: Sets the texture base level texture parameter.
	void set_base_level(int base_level);

	//: Sets the texture max level texture parameter.
	void set_max_level(int max_level);

	//: Enables or disables automatic mipmap generation when uploading image data.
	void set_generate_mipmap(bool generate_mipmap = true);

	//: Set the texture wrapping mode.
	void set_wrap_mode(
		CL_TextureWrapMode wrap_s,
		CL_TextureWrapMode wrap_t,
		CL_TextureWrapMode wrap_r);
	
	void set_wrap_mode(
		CL_TextureWrapMode wrap_s,
		CL_TextureWrapMode wrap_t);

	void set_wrap_mode(
		CL_TextureWrapMode wrap_s);

	//: Set the minification filter.
	void set_min_filter(CL_TextureFilter filter);

	//: Set the magnification filter.
	void set_mag_filter(CL_TextureFilter filter);

	//: Set texture border color.
	void set_border_color(double red, double green, double blue, double alpha);

	void set_border_color(const CL_Colord &color);

	//: Set texture priority.
	void set_priority(double priority);

	//: Set the depth texture mode parameter.
	void set_depth_mode(CL_TextureDepthMode depth_mode);

	//: Sets the texture compare mode and compare function texture parameters.
	void set_texture_compare(CL_TextureCompareMode mode, CL_CompareFunction func);

//! Implementation:
private:
	CL_SharedPtr<CL_Texture_Impl> impl;

	CL_ResourceDataSession resource_data_session;
};

#endif
