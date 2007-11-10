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

#ifndef header_graphic_context_provider
#define header_graphic_context_provider

#include "api_display.h"
#include "../Core/System/sharedptr.h"
#include "../Core/Text/string_types.h"
#include "graphic_context.h"
#include "primitives_array.h"
#include "texture.h"

class CL_Size;
class CL_TextureUnit;
class CL_Texture;
class CL_LightSource;
class CL_Stencil;
class CL_Matrix4x4;
class CL_TextureProvider;
class CL_FontProvider;
class CL_BlendMode;
class CL_PolygonRasterizer;
class CL_Font;
class CL_OcclusionQueryProvider;
class CL_ProgramObjectProvider;
class CL_ShaderObjectProvider;
class CL_FrameBufferProvider;
class CL_RenderBufferProvider;
class CL_VertexArrayBufferProvider;
class CL_ElementArrayBufferProvider;

//: Primitives array data supplied to clanDisplay provider objects.
//- !group=Display/Display Target Interface!
//- !header=display.h!
class CL_PrimitivesArrayData
{
public:
	struct VertexData
	{
		int size;
		CL_VertexAttributeDataType type;
		int stride;
		CL_VertexArrayBufferProvider *array_provider;
		bool single_value;
		union
		{
			void *data;
			unsigned char value_ubyte[4];
			char value_byte[4];
			unsigned short value_ushort[4];
			short value_short[4];
			unsigned int value_uint[4];
			int value_int[4];
			float value_float[4];
			double value_double[4];
			bool value_boolean;
		};
	};

	VertexData position;
	VertexData normal;
	VertexData primary_color;
	VertexData secondary_color;
	VertexData edge_flag;
	VertexData fog_coord;

	int num_tex_coords;
	int *tex_coord_indexes;
	VertexData *tex_coords;

	int num_attributes;
	int *attribute_indexes;
	VertexData *attributes;
	bool *normalize_attributes;
};

//: Interface for implementing a CL_GraphicContext target.
//- !group=Display/Display Target Interface!
//- !header=display.h!
class CL_API_DISPLAY CL_GraphicContextProvider
{
//! Construction:
public:
	virtual ~CL_GraphicContextProvider() { return; }

//! Attributes:
public:
	//: Returns the current font.
	virtual CL_Font get_font() const = 0;

	//: Returns information about the current font.
	virtual CL_FontMetrics get_font_metrics() = 0;

	//: Returns the amount of texture coordinates available.
	virtual int get_max_texture_coords() = 0;

	//: Returns the maximum amount of attributes available.
	virtual int get_max_attributes() = 0;

	//: Returns the amount of light sources available.
	virtual int get_light_count() = 0;

	//: Returns the maximum size of a texture this graphic context supports.
	//- <p>It returns CL_Size(0,0) if there is no known limitation to the max
	//- texture size.</p>
	virtual CL_Size get_max_texture_size() const = 0;

	//: Returns the current width of the context.
	virtual int get_width() const = 0;

	//: Returns the current height of the context.
	virtual int get_height() const = 0;

//! Operations:
public:
	//: Destroys graphic context provider.
	virtual void destroy() = 0;

	//: Creates a new additional graphic context for the window.
	virtual CL_GraphicContext create_worker_gc() = 0;

	//: Return the content of the draw buffer into a pixel buffer.
	virtual CL_PixelBuffer get_pixeldata(const CL_Rect& rect) = 0;

	//: Allocate texture provider for this gc.
	virtual CL_TextureProvider *alloc_texture(CL_TextureDimensions texture_dimensions) = 0;

	//: Allocate font for this gc.
	virtual CL_FontProvider *alloc_font() = 0;

	//: Allocate occlusion query provider of this gc.
	virtual CL_OcclusionQueryProvider *alloc_occlusion_query() = 0;

	//: Allocate program object provider of this gc.
	virtual CL_ProgramObjectProvider *alloc_program_object() = 0;

	//: Allocate shader object provider of this gc.
	virtual CL_ShaderObjectProvider *alloc_shader_object() = 0;

	//: Allocate frame buffer provider for this gc.
	virtual CL_FrameBufferProvider *alloc_frame_buffer() = 0;

	//: Allocate render buffer provider for this gc.
	virtual CL_RenderBufferProvider *alloc_render_buffer() = 0;

	//: Allocate vertex array buffer provider for this gc.
	virtual CL_VertexArrayBufferProvider *alloc_vertex_array_buffer() = 0;

	//: Allocate element array buffer provider for this gc.
	virtual CL_ElementArrayBufferProvider *alloc_element_array_buffer() = 0;

	//: Set active program object.
	virtual void set_program_object(const CL_ProgramObject &program) = 0;

	//: Remove active program object.
	virtual void reset_program_object() = 0;

	//: Setup texture unit.
	virtual void set_texture_unit(int unit_index, const CL_TextureUnit &unit) = 0;

	//: Select texture into unit.
	virtual void set_texture(int unit_index, const CL_Texture &texture) = 0;

	//: Remove texture from unit.
	virtual void reset_texture(int unit_index) = 0;

	//: Push current texture matrix onto the texture matrix of the specified unit.
	virtual void push_texture_matrix(int unit_index) = 0;

	//: Set the texture matrix of the specified unit.
	virtual void set_texture_matrix(int unit_index, const CL_Matrix4x4 &matrix) = 0;

	//: Pop current texture matrix from the texture matrix of the specified unit.
	virtual void pop_texture_matrix(int unit_index) = 0;

	//: Set a frame buffer for off-screen rendering.
	virtual void set_frame_buffer(const CL_FrameBuffer &buffer) = 0;

	//: Set the rendering buffer back to the screen.
	virtual void reset_frame_buffer() = 0;

	//: Sets the active lighting model.
	virtual void set_light_model(const CL_LightModel &light_model) = 0;

	//: Disables lighting.
	virtual void reset_light_model() = 0;

	//: Sets both front and back materials.
	virtual void set_material(const CL_Material &material) = 0;

	//: Sets only the front material.
	virtual void set_front_material(const CL_Material &material) = 0;

	//: Sets only the back material.
	virtual void set_back_material(const CL_Material &material) = 0;

	//: Resets the front material to the default material.
	virtual void reset_front_material() = 0;

	//: Resets the back material to the default material.
	virtual void reset_back_material() = 0;

	//: Resets both front and back materials to the default.
	virtual void reset_material() = 0;

	//: Sets the material property which vertex colors describe.
	virtual void set_color_material(CL_ColorMaterial color) = 0;

	//: Sets the front material's property which vertex colors describe.
	virtual void set_color_material_front(CL_ColorMaterial color) = 0;

	//: Sets the back material's property which vertex colors describe.
	virtual void set_color_material_back(CL_ColorMaterial color) = 0;

	//: Disables material coloring from vertex colors.
	virtual void reset_color_material() = 0;

	//: Set light source.
	virtual void set_light(int light_index, const CL_LightSource &light) = 0;

	//: Remove light source.
	virtual void reset_light(int light_index) = 0;

	//: Set blending modes.
	virtual void set_blend_mode(const CL_BlendMode &blendmode) = 0;

	//: Set buffer control states.
	virtual void set_buffer_control(const CL_BufferControl &buffer_control) = 0;

	//: Select pen.
	virtual void set_pen(const CL_Pen &pen) = 0;

	//: Set polygon rasterizer settings.
	virtual void set_polygon_rasterizer(const CL_PolygonRasterizer &raster) = 0;

	//: Select font.
	virtual void set_font(const CL_Font &font) = 0;

	//: Set a font glyph to use a specified font pixel buffer
	virtual void set_font_glyph(CL_Font &font, CL_FontPixelBuffer pixelbuffer) = 0;

	//: Draw primitives on gc.
	virtual void draw_primitives(CL_PrimitivesType type, int num_vertices, const CL_PrimitivesArrayData * const prim_array) = 0;

	//: Set the primitives array on the gc.
	virtual void set_primitives_array(const CL_PrimitivesArrayData * const prim_array) = 0;

	//: Draws primitives from the current assigned primitives array.
	virtual void draw_primitives_array(CL_PrimitivesType type, int offset, int num_vertices) = 0;

	virtual void draw_primitives_elements(CL_PrimitivesType type, int count, unsigned int *indices) = 0;

	virtual void draw_primitives_elements(CL_PrimitivesType type, int count, unsigned short *indices) = 0;

	virtual void draw_primitives_elements(CL_PrimitivesType type, int count, unsigned char *indices) = 0;

	virtual void draw_primitives_elements(CL_PrimitivesType type, int count, CL_ElementArrayBufferProvider *array_provider, CL_VertexAttributeDataType indices_type, void *offset) = 0;

	//: Reset the primitives arrays.
	virtual void reset_primitives_array() = 0;

	//: Draw pixel buffer on gc.
	virtual void draw_pixels(double x, double y, double zoom_x, double zoom_y, const CL_PixelBuffer &pixel_buffer, const CL_Colord &color) = 0;

	//: Retrieves the pixel buffer using the current selected font
	virtual CL_FontPixelBuffer get_font_glyph(int glyph, bool anti_alias = true, const CL_Colord &color = CL_Colord::white) = 0;

	//: Print text on gc.
	virtual void draw_text(int x, int y, const CL_StringRef &text, const CL_Colord &color) = 0;

	//: Calculate size of text string.
	virtual CL_Size get_text_size(const CL_StringRef &text) = 0;

	//: Set clip rect.
	virtual void set_clip_rect(const CL_Rect &rect) = 0;

	//: Reset clip rect.
	virtual void reset_clip_rect() = 0;

	//: Clears the whole context using the specified color.
	virtual void clear(double red, double green, double blue, double alpha) = 0;

	//: Clear the depth buffer
	//param value: value to clear to. Range: 0.0 - 1.0.
	virtual void clear_depth(double value) = 0;

	//: Clear the stencil buffer
	//param value: value to clear to.
	virtual void clear_stencil(int value) = 0;

	//: Set the projection mapping mode.
	virtual void set_map_mode(CL_MapMode mode) = 0;

	//: Set the viewport to be used in user projection map mode.
	virtual void set_viewport(const CL_Rectf &viewport) = 0;

	//: Set the projection matrix to be used in user projection map mode.
	virtual void set_projection(const CL_Matrix4x4 &matrix) = 0;

	//: Sets the model view matrix to a new matrix.
	virtual void set_modelview(const CL_Matrix4x4 &matrix) = 0;

//! Implementation:
private:
};

#endif