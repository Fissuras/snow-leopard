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

#ifndef header_graphic_context
#define header_graphic_context

#include "api_display.h"
#include "color.h"
#include "../Core/System/sharedptr.h"
#include "../Core/Math/rect.h"
#include "primitives_array.h"

class CL_BufferControl;
class CL_PolygonRasterizer;
class CL_Pen;
class CL_BlendMode;
class CL_Texture;
class CL_FrameBuffer;
class CL_TextureUnit;
class CL_Size;
class CL_PixelBuffer;
class CL_LightModel;
class CL_Material;
class CL_LightSource;
class CL_PrimitivesArray;
class CL_Matrix4x4;
class CL_Font;
class CL_FontMetrics;
class CL_FontPixelBuffer;
class CL_GraphicContextProvider;
class CL_GraphicContext_Impl;
class CL_ProgramObject;
class CL_ElementArrayBuffer;

//: Primitive types.
//- !group=Display/Display!
//- !header=display.h!
enum CL_PrimitivesType
{
	cl_points,
	cl_line_strip,
	cl_line_loop,
	cl_lines,
	cl_triangle_strip,
	cl_triangle_fan,
	cl_triangles,
	cl_quad_strip,
	cl_quads,
	cl_polygon
};

//: Mapping modes.
//- !group=Display/Display!
//- !header=display.h!
enum CL_MapMode
{
	cl_map_2d_upper_left,
	cl_map_2d_lower_left,
	cl_user_projection
};

//: Vertex color material destinations.
//- !group=Display/Display!
//- !header=display.h!
enum CL_ColorMaterial
{
	cl_color_material_emission,
	cl_color_material_ambient,
	cl_color_material_diffuse,
	cl_color_material_specular,
	cl_color_material_ambient_and_diffuse
};

//: Interface to drawing graphics.
//- !group=Display/Display!
//- !header=display.h!
class CL_API_DISPLAY CL_GraphicContext
{
//! Construction:
public:
	//: Constructs a graphic context.
	CL_GraphicContext();

	CL_GraphicContext(CL_GraphicContextProvider *provider);
	
	~CL_GraphicContext();

//! Attributes:
public:
	//: Returns the texture unit description for the specified unit.
	CL_TextureUnit get_texture_unit(int unit);

	//: Returns the amount of texture units available.
	int get_texture_unit_count();

	//: Returns the currently selected texture for the specified unit.
	CL_Texture get_texture(int unit);
	
	//: Returns the light source description for the given light source.
	CL_LightSource get_light(int light);
	
	//: Returns the amount of light sources available.
	int get_light_count();

	//: Returns the blending mode description.
	CL_BlendMode get_blend_mode();

	//: Returns the buffer control description.
	CL_BufferControl get_buffer_control();

	//: Returns the polygon rasterizer setup.
	CL_PolygonRasterizer get_polygon_rasterizer();

	//: Returns the currently selected pen.
	CL_Pen get_pen();

	//: Returns the currently selected font.
	CL_Font get_font();

	//: Retrieves font metrics description for the selected font.
	CL_FontMetrics get_font_metrics();

	//: Returns the current width of the context.
	int get_width() const;

	//: Returns the current height of the context.
	int get_height() const;

	//: Returns the current clipping rectangle used on the graphic context.
	CL_Rect get_cliprect() const;

	//: Returns the current effective modelview matrix.
	const CL_Matrix4x4 &get_modelview() const;

	//: Returns the maximum size of a texture this graphic context supports.
	//- <p>It returns CL_Size(0,0) if there is no known limitation to the max
	//- texture size.</p>
	CL_Size get_max_texture_size() const;

	//: Returns the provider for this graphic context.
	CL_GraphicContextProvider *get_provider();

	const CL_GraphicContextProvider * const get_provider() const;

//! Operations:
public:
	//: Creates a new additional graphic context.
	//- <p>This function creates a new graphic context which shares objects
	//- with the current graphic context.  Since a GC cannot be safely accessed
	//- from multiple threads simultaneously, this function allows the
	//- application to create a graphic context for the worker threads.</p>
	CL_GraphicContext create_worker_gc();

	//: Return the content of the draw buffer into a pixel buffer.
	CL_PixelBuffer get_pixeldata(const CL_Rect& rect = CL_Rect(0,0,0,0)) const;

	//: Sets the current frame buffer.
	void set_frame_buffer(const CL_FrameBuffer &frame_buffer);

	//: Resets the current frame buffer to be the initial frame buffer.
	void reset_frame_buffer();

	//: Setup texture unit.
	void set_texture_unit(int unit_index, const CL_TextureUnit &unit);

	//: Returns texture unit to default state.
	void reset_texture_unit(int unit_index);

	//: Select texture into unit.
	void set_texture(int unit_index, const CL_Texture &texture);

	//: Remove texture from unit.
	void reset_texture(int unit_index);

	//: Push current texture matrix onto the texture matrix of the specified unit.
	void push_texture_matrix(int unit_index);

	//: Set the texture matrix of the specified unit.
	void set_texture_matrix(int unit_index, const CL_Matrix4x4 &matrix);

	//: Pop current texture matrix from the texture matrix of the specified unit.
	void pop_texture_matrix(int unit_index);

	//: Set active program object.
	void set_program_object(const CL_ProgramObject &program);

	//: Remove active program object.
	void reset_program_object();

	//: Sets the active lighting model.
	void set_light_model(const CL_LightModel &light_model);

	//: Disables lighting.
	void reset_light_model();

	//: Sets both front and back materials.
	void set_material(const CL_Material &material);

	//: Sets only the front material.
	void set_front_material(const CL_Material &material);

	//: Sets only the back material.
	void set_back_material(const CL_Material &material);

	//: Resets the front material to the default material.
	void reset_front_material();

	//: Resets the back material to the default material.
	void reset_back_material();

	//: Resets both front and back materials to the default.
	void reset_material();

	//: Sets the material property which vertex colors describe.
	void set_color_material(CL_ColorMaterial color);

	//: Sets the front material's property which vertex colors describe.
	void set_color_material_front(CL_ColorMaterial color);

	//: Sets the back material's property which vertex colors describe.
	void set_color_material_back(CL_ColorMaterial color);

	//: Disables material coloring from vertex colors.
	void reset_color_material();

	//: Set light source.
	void set_light(int light_index, const CL_LightSource &light);

	//: Remove light source.
	void reset_light(int light_index);

	//: Set blending modes.
	void set_blend_mode(const CL_BlendMode &blend_mode);

	//: Reset blending to the default.
	void reset_blend_mode();

	//: Set buffer control states.
	void set_buffer_control(const CL_BufferControl &buffer_control);

	//: Set default buffer control states.
	void reset_buffer_control();

	//: Select pen.
	void set_pen(const CL_Pen &pen);

	//: Reset pen settings to defaults.
	void reset_pen();

	//: Set polygon rasterizer settings.
	void set_polygon_rasterizer(const CL_PolygonRasterizer &raster);

	//: Reset polygon rasterizer settings to defaults.
	void reset_polygon_rasterizer();

	//: Select font.
	void set_font(const CL_Font &font);

	//: Set a font glyph to use a specified font pixel buffer
	void set_font_glyph(CL_Font &font, CL_FontPixelBuffer pixelbuffer);

	//: Draw primitives on gc.
	void draw_primitives(CL_PrimitivesType type, int num_vertices, const CL_PrimitivesArray &array);

	//: Set the primitives array on the gc.
	void set_primitives_array(const CL_PrimitivesArray &array);

	//: Draws primitives from the current assigned primitives array.
	void draw_primitives_array(CL_PrimitivesType type, int num_vertices);

	void draw_primitives_array(CL_PrimitivesType type, int offset, int num_vertices);

	void draw_primitives_elements(CL_PrimitivesType type, int count, unsigned int *indices);

	void draw_primitives_elements(CL_PrimitivesType type, int count, unsigned short *indices);

	void draw_primitives_elements(CL_PrimitivesType type, int count, unsigned char *indices);

	void draw_primitives_elements(CL_PrimitivesType type, int count, CL_ElementArrayBuffer &element_array, CL_VertexAttributeDataType indices_type, void *offset = 0);

	//: Reset the primitives arrays.
	void reset_primitives_array();

	//: Draw pixel buffer on gc.
	void draw_pixels(double x, double y, const CL_PixelBuffer &pixel_buffer, const CL_Colord &color = CL_Colord::white);

	void draw_pixels(double x, double y, double zoom_x, double zoom_y, const CL_PixelBuffer &pixel_buffer, const CL_Colord &color = CL_Colord::white);

	//: Print text on gc.
	void draw_text(int x, int y, const CL_StringRef &text, const CL_Colord &color = CL_Colord::white);

	//: Retrieves the pixel buffer using the current selected font
	CL_FontPixelBuffer get_font_glyph(int glyph, bool anti_alias = true, const CL_Colord &color = CL_Colord::white);

	//: Calculate size of text string.
	//- Note: The height also includes whitespace (to give the maximum font height), so "." and "X" returns the same height.
	//- The width is the pixel width
	CL_Size get_text_size(const CL_StringRef &text);

	//: Clears the whole context using the specified color.
	void clear(const CL_Colord &color = CL_Colord::black);

	//: Clear the stencil buffer
	//param value: value to clear to.
	void clear_stencil(int value = 0);

	//: Clear the depth buffer
	//param value: value to clear to. Range: 0.0 - 1.0.
	void clear_depth(double value = 0);

	//: Set the current clipping rectangle.
	void set_cliprect(const CL_Rect &rect);

	//: Push current clipping rectangle to stack.
	//- <p>If a rectangle is passed, it afterwards sets clipping
	//- rectangle to the union of the current rectangle and the passed
	//- rectangle.</p>
	void push_cliprect(const CL_Rect &rect);

	void push_cliprect();

	//: Pop current clipping rectangle from the stack.
	void pop_cliprect();

	//: Removes the set clipping rectangle and empties the cliprect stack. 
	void reset_cliprect();

	//: Set the projection mapping mode.
	void set_map_mode(CL_MapMode mode);

	//: Set the viewport to be used in user projection map mode.
	void set_viewport(const CL_Rectf &viewport);

	//: Set the projection matrix to be used in user projection map mode.
	void set_projection(const CL_Matrix4x4 &matrix);

	//: Sets the model view matrix to a new matrix.
	void set_modelview(const CL_Matrix4x4 &matrix);

	//: Multiplies the passed matrix onto the model view matrix.
	void add_modelview(const CL_Matrix4x4 &matrix);

	//: Pushes current model view matrix onto the model view stack.
	void push_modelview();

	//: Sets a translate offset matrix, ignoring any earlier model view settings.
	//- <p> This offset will affect any subsequent display operations on the current
	//- displaycard, by translating the position of the display operation with the offset.</p>
	void set_translate(double x, double y, double z = 0.0);

	//: Adds the translate offset.
	//- <p> This offset will affect any subsequent display operations on the current
	//- displaycard, by translating the position of the display operation with the offset.
	//- The offset will be offset by any previous offsets pushed onto the stack,
	//- eg. it inherits the previous offset. </p>
	void add_translate(double x, double y, double z = 0.0);
	
	//: Push translation offset onto model view stack.
	//- <p>This function is a convenience function for calling push_modelview, then add_translate.</p>
	//- <p> This offset will affect any subsequent display operations on the current
	//- displaycard, by translating the position of the display operation with the offset.
	//- The offset will be offset by any previous offsets pushed onto the stack,
	//- eg. it inherits the previous offset. </p>
	void push_translate(double x, double y, double z = 0.0);

	//: Sets a rotation matrix, ignoring any earlier model view settings.
	void set_rotate(double angle, double x = 0.0, double y = 0.0, double z = 1.0, bool normalize = true);

	//: Adds a rotation matrix to existing model view.
	void add_rotate(double angle, double x = 0.0, double y = 0.0, double z = 1.0, bool normalize = true);

	//: Pushes a rotation matrix onto model view stack.
	void push_rotate(double angle, double x = 0.0, double y = 0.0, double z = 1.0);

	//: Sets a scale matrix, ignoring any earlier model view settings.
	void set_scale(double x, double y, double z = 1.0);

	//: Adds a scale matrix to existing model view.
	void add_scale(double x, double y, double z = 1.0);

	//: Pushes a scale matrix onto model view stack.
	void push_scale(double x, double y, double z = 1.0);

	//: Pops last pushed model view matrix off the stack and makes it the active one.
	void pop_modelview();

//! Implementation:
private:
	CL_SharedPtr<CL_GraphicContext_Impl> impl;

	friend class CL_PrimitivesArray;
};

#endif
