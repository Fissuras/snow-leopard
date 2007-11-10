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

#ifndef header_sprite
#define header_sprite

#include "api_display.h"
#include "../Core/Text/string_types.h"
#include "../Core/System/sharedptr.h"
#include "../Core/Math/origin.h"
#include "../Core/Math/rect.h"
#include "../Core/Signals/signal_v0.h"
#include "../Core/IOData/virtual_directory.h"
#include "../Core/Resources/resource_data_session.h"
#include "graphic_context.h"
#include "color.h"
#include "blend_mode.h"

class CL_ResourceManager;
class CL_SpriteDescription;
class CL_Sprite_Impl;

//: Sprite class.
//- !group=Display/Sprites!
//- !header=display.h!
class CL_API_DISPLAY CL_Sprite
{
//! Enums:
public:
	enum ShowOnFinish
	{
		show_blank, show_last_frame, show_first_frame
	};

//! Construction:
public:
	//: Constructs a sprite.
	//param resource_id: Resource name of a sprite resource.
	//param manager: Resource manager used to load resource.
	//param sprite_description: Sprite description used to construct sprite.
	//param gc: Graphic context to use.
	CL_Sprite();

	CL_Sprite(const CL_StringRef &filename, CL_GraphicContext gc);

	CL_Sprite(const CL_StringRef &filename, CL_VirtualDirectory dir, CL_GraphicContext gc);

	CL_Sprite(const CL_StringRef &resource_id, CL_ResourceManager *resources, CL_GraphicContext gc);

	CL_Sprite(const CL_SpriteDescription &description, CL_GraphicContext gc);

	CL_Sprite(const CL_Sprite &copy);

	virtual ~CL_Sprite();

//! Attributes:
public:
	//: returns true if the sprite is not properly constructed.
	bool is_null() const;

	//: Returns current angle in degrees.
	double get_angle() const;

	//: Returns the base angle in degrees - angle added to any rotation set with set_rotate() or rotate().
	double get_base_angle() const;

	//: Returns scale for x and y.
	//- <p> 1.0f is normal scale, 2.0f is twice the size, etc. </p>
	void get_scale(double &x, double &y) const;

	//: Returns current alpha.
	//- <p> Alpha 0.0f is full transparency, and 1.0f is full visibility (solid). </p>
	double get_alpha() const;

	//: Returns current color.
	//- <p> Alpha 0.0f is full transparency, and 1.0f is full visibility (solid). </p>
	void get_color(double &red, double &green, double &blue, double &alpha) const;
	CL_Color get_color() const {double r,g,b,a; get_color(r,g,b,a); return CL_Color(int(r*255.0),int(g*255.0),int(b*255.0),int(a*255.0));}

	//: Returns blending functions.
	CL_BlendMode get_blend_mode() const;

	//: Returns translation hot-spot.
	void get_alignment(CL_Origin &origin, int &x, int &y) const;

	//: Returns rotation hot-spot.
	void get_rotation_hotspot(CL_Origin &origin, int &x, int &y) const;

	//: Returns current frame in animation. 0 is first frame.
	int get_current_frame() const;

	//: Returns number of frames in animation.
	int get_frame_count() const;

	//: Returns the delay of a frame. 0 is first frame.
	double get_frame_delay(int frame) const;

	//: Returns the translation offset of a frame. 0 is first frame.
	CL_Point get_frame_offset(int frame) const;
	
	//: Returns the size of a frame. 0 is first frame.
	CL_Size get_frame_size(int frame) const;

	//: Return the width of the current frame, shortcut for
	//: 'get_frame_size(get_current_frame()).width'
	int get_width() const;

	//: Return the height of the current frame, shortcut for
	//: 'get_frame_size(get_current_frame()).height'
	int get_height() const;

	//: Returns the attached id (if exists).
	int get_id() const;
		
	//: Returns true if animation is played in loop (more than once).
	bool is_play_loop() const;

	//: Returns true if animation is played in from right to left (starts at end).
	bool is_play_backward() const;

	//: Returns true if animation is played in ping-pong mode.
	bool is_play_pingpong() const;

	//: Returns an enum for what is shown when the animation is finished.
	//- <p> If show_blank is returned, nothing is shown when animation is done. </p>
	ShowOnFinish get_show_on_finish() const;

	//: Returns true if animation is finished.
	//- <p> When an animation is finished, it will no longer show, unless ShowLastFrame is set
	//- to anything other than show_blank </p>
	bool is_finished() const;

//! Operations:
public:
	//: Copy assignment operator.
	CL_Sprite &operator =(const CL_Sprite &copy);

	//: Sets the image data from another sprite.
	//- Use this to change the look of your sprite.
	void set_image_data(const CL_Sprite &image_source);
	
	//: Draw sprite on graphic context.
	//param x, y: Anchor position of where to render sprite. Actual rendering position depends on the anchor and the alignment mode.
	//param gc: Graphic context on which to render upon. If null, will use CL_Display's current graphic context.
	//param src: Source rectangle to draw. Use this is draw only part of the sprite.
	//param dest: Rectangle to draw sprite in.
	void draw(
		CL_GraphicContext gc,
		double x,
		double y);

	void draw(
		CL_GraphicContext gc,
		const CL_Rectd &src,
		const CL_Rectd &dest);

	void draw(
		CL_GraphicContext gc,
		const CL_Rectd &dest);

	//: Call this function to update the animation.
	//- Returns the time elapsed parameter, the automatic calculated one if you used 0.
	//param time_elapsed: milliseconds since last update. Use 0 for automatic time calculation.
	double update(double time_elapsed = 0);

	//: Set absolute rotation angle in degrees.
	void set_angle(double angle);
	
	//: Set absolute rotation pitch angle in degrees.
	void set_angle_pitch(double angle);
	
	//: Set absolute rotation yaw angle in degrees.
	void set_angle_yaw(double angle);

	//: Add angle in degrees to current angle.
	void rotate(double angle);
	
	//: Add angle in degrees to current pitch angle.
	void rotate_pitch(double angle);
	
	//: Add angle in degrees to current yaw angle.
	void rotate_yaw(double angle);

	//: Sets the base angle in degrees - angle added to any rotation set with set_rotate() or rotate().
	void set_base_angle(double angle);

	//: Set scale for x and y directions individually.
	//- <p> 1.0f is normal scale, 2.0f is twice the size, etc. </p>
	void set_scale(double x, double y);

	//: Sets transparency.
	//- <p> Alpha 0.0f is full transparency, and 1.0f is full visibility (solid). </p>
	void set_alpha(double alpha);

	//: Sets the color.
	//- <p> Alpha 0.0f is full transparency, and 1.0f is full visibility (solid). </p>
	void set_color(double r, double g, double b, double a = 1.0);
	void set_color(const CL_Color& c) {set_color(c.get_red_d(), c.get_green_d(), c.get_blue_d(), c.get_alpha_d());}

	//: Sets blending functions.
	void set_blend_mode(const CL_BlendMode &blend_mode);

	//: Sets translation hotspot.
	void set_alignment(CL_Origin origin, int x = 0, int y = 0);

	//: Sets rotation hotspot.
	void set_rotation_hotspot(CL_Origin origin, int x = 0, int y = 0);

	//: Sets current animation frame. 0 is first frame.
	//: It will cap to available range.
	void set_frame(unsigned int frame);

	//: Sets the delay for all frames.
	void set_delay(double delay);

	//: Sets the delay of a specific frame. 0 is first frame.
	void set_frame_delay(int frame, double delay);

	//: Sets the translate offset of a specific frame. 0 is first frame.
	void set_frame_offset(int frame, CL_Point offset);
	
	//: Sets an attached id.
	void set_id(int id);
	
	//: Finish animation.
	//- <p> When an animation is finished, it will no longer show, unless ShowLastFrame is set to anything
	//- other than show_blank </p>
	void finish();

	//: Restart animation.
	void restart();

	//: Set to true if animation should loop, false otherwise.
	void set_play_loop(bool loop = true);

	//: Set to true if animation should loop, false otherwise.
	void set_play_pingpong(bool pingpong = true);

	//: Set to true if animation should go backward (start at end).
	void set_play_backward(bool backward = true);

	//: Set what is shown when the animation is finished.
	void set_show_on_finish(CL_Sprite::ShowOnFinish show_on_finish);

//! Signals:
public:
	CL_Signal_v0 &sig_animation_finished();

//! Implementation:
private:
	CL_SharedPtr<CL_Sprite_Impl> impl;

	CL_ResourceDataSession resource_data_session;
};

#endif
