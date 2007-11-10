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
**    Harry Storbacka
*/

//! clanCore="Math"
//! header=core.h

#ifndef header_rect_lhusrhilug985t4thligp
#define header_rect_lhusrhilug985t4thligp

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"
#include "size.h"
#include "point.h"
#include "origin.h"

template<typename T> T cl_min(T a, T b) { if(a < b) return a; return b; }
template<typename T> T cl_max(T a, T b) { if(a > b) return a; return b; }

class CL_Rectf;
class CL_Rectd;

//: 2D (left,top,right,bottom) rectangle structure.
//- !group=Core/Math!
//- !header=core.h!
class CL_API_CORE CL_Rect
{
//! Construction:
public:
	//: Constructs an rectangle.
	//param left: Initial left position of rectangle.
	//param top: Initial top position of rectangle.
	//param right: Initial right position of rectangle.
	//param bottom: Initial bottom position of rectangle.
	//param point: Initial top-left position of rectangle.
	//param size: Initial size of rectangle.
	//param rect: Initial rectangle position and size.
	CL_Rect() { left = right = top = bottom = 0; }

	CL_Rect(const CL_Size &s) { left = 0; top = 0; right = s.width; bottom = s.height; }

	explicit CL_Rect(const CL_Sized &s) { left = 0; top = 0; right = int(s.width+0.5); bottom = int(s.height+0.5); }

	explicit CL_Rect(const CL_Rectf& rect);

	explicit CL_Rect(const CL_Rectd& rect);

	CL_Rect(int new_left, int new_top, int new_right, int new_bottom)
	{ left = new_left; top = new_top; right = new_right; bottom = new_bottom; }

	CL_Rect(const CL_Point &p, const CL_Size &size)
	{ left = p.x; top = p.y; right = left + size.width; bottom = top + size.height; }

	CL_Rect(const CL_Rect &rect)
	{ left = rect.left; top = rect.top; right = rect.right; bottom = rect.bottom; }

	//: Rect == Rect operator.
	bool operator==(const CL_Rect &r) const
	{ return (left == r.left && top == r.top && right == r.right && bottom == r.bottom); }

	//: Rect != Rect operator.
	bool operator!=(const CL_Rect &r) const
	{ return (left != r.left || top != r.top || right != r.right || bottom != r.bottom); }

//! Attributes:
public:
	//: X1-coordinate.
	int left;
	
	//: Y1-coordinate.
	int top;
	
	//: X2-coordinate.
	int right;
	
	//: Y2-coordinate.
	int bottom;
	
	//: Returns the width of the rectangle.
	int get_width() const { return right - left; }
	
	//: Returns the height of the rectangle.
	int get_height() const { return bottom - top; }

	//: Returns the size of the rectangle.
	CL_Size get_size() const { return CL_Size(right - left, bottom - top); }
	
	//: Returns true if point is inside the rectangle.
	bool is_inside(const CL_Point &p) const { return (p.x >= left && p.y >= top && p.x <= right && p.y <= bottom); }

	//: Returns true if rectangle passed is overlapping or inside this rectangle.
	bool is_overlapped(const CL_Rect &r) const 
	{
		return (r.left < right && r.right > left && r.top < bottom && r.bottom > top);
	}
	
	//: Returns another CL_Rect containing a rotated version of this one.
	//param hotspot: Point to rotate around.
	//param origin: Determines the hotspot point within the rectangle
	//param x, y: Offsets applied negatively to the hotspot point
	//param angle: Angle to rotate in degrees.
	CL_Rect get_rot_bounds(const CL_Point &hotspot, float angle) const;
	CL_Rect get_rot_bounds(CL_Origin origin, int x, int y, float angle) const;

	//: Returns the center point of the rectangle.
	CL_Point get_center() const
	{
		return CL_Point( int(double(left + right)/2.0+0.5), int(double(top + bottom)/2.0+0.5) );
	}

//! Operations:
public:
	//: Shrink the rectangle
	CL_Rect shrink(const CL_Rect &r)
	{
		left += r.left; top += r.top; right -= r.right; bottom -= r.bottom; return *this;
	};

	//: Expand the rectangle
	CL_Rect expand(const CL_Rect &r)
	{
		left -= r.left; top -= r.top; right += r.right; bottom += r.bottom; return *this;
	};

	//: Translate the rect
	CL_Rect translate(const CL_Point &p)
	{
		left += p.x; top += p.y; right += p.x; bottom += p.y; return *this;
	};

	//: Translate the rect
	CL_Rect translate(int x, int y)
	{
		left += x; top += y; right += x; bottom += y; return *this;
	};

	//: Sets the size of the rectangle, maintaining top/left position.
	void set_size(const CL_Size &size)
	{
		right = left + size.width;
		bottom = top + size.height;
	}

	//: Calculates and returns the union of two rectangles.
	CL_Rect calc_overlap(const CL_Rect &rect) const
	{
		CL_Rect result;
		result.left   = cl_max(left, rect.left);
		result.right  = cl_min(right, rect.right);
		result.top    = cl_max(top, rect.top);
		result.bottom = cl_min(bottom, rect.bottom);
		return result;
	}

	//: Calculates and returns the bounding rectangle of the rectangles.
	CL_Rect calc_bounding_rect(const CL_Rect &rect) const
	{
		CL_Rect result;
		result.left   = cl_min(left, rect.left);
		result.right  = cl_max(right, rect.right);
		result.top    = cl_min(top, rect.top);
		result.bottom = cl_max(bottom, rect.bottom);
		return result;
	}

	//: Normalize rectangle. Ensures that left is less than right and top is less than bottom.
	void normalize()
	{
		if (left > right)
		{
			int temp = right;
			right = left;
			left = temp;
		}

		if (top > bottom)
		{
			int temp = bottom;
			bottom = top;
			top = temp;
		}
	}
	
	//: Applies an origin and offset pair to this rectangle
	//param origin: The new origin to adjust to from default upper-left position
	//param x, y: Offsets applied negatively to each corner of the rectangle
	void apply_alignment(CL_Origin origin, int x, int y)
	{
		CL_Point offset = calc_origin(origin, get_size());
		offset.x -= x;
		offset.y -= y;
		
		left += offset.x;
		top += offset.y;
		right += offset.x;
		bottom += offset.y;
	}

	//: Clip according to the specified clip rectangle.
	void clip(const CL_Rect &cr)
	{
		top = cl_max(top, cr.top);
		left = cl_max(left, cr.left);
		right = cl_min(right, cr.right);
		bottom = cl_min(bottom, cr.bottom);
		top = cl_min(top, bottom);
		left = cl_min(left, right);
	}
};

//: 2D (left,top,right,bottom) floating point rectangle structure.
//- !group=Core/Math!
//- !header=core.h!
class CL_Rectf
{
//! Construction:
public:
	//: Constructs an rectangle.
	//param left: Initial left position of rectangle.
	//param top: Initial top position of rectangle.
	//param right: Initial right position of rectangle.
	//param bottom: Initial bottom position of rectangle.
	//param point: Initial top-left position of rectangle.
	//param size: Initial size of rectangle.
	//param rect: Initial rectangle position and size.
	CL_Rectf() { left = right = top = bottom = 0.0f; }

	CL_Rectf(const CL_Rect& rect)
		: left((float) rect.left), 
		  top((float) rect.top), 
		  right((float) rect.right), 
		  bottom((float) rect.bottom)
	{}

	explicit CL_Rectf(const CL_Rectd& R);

	explicit CL_Rectf(const CL_Sizef &s) { left = 0; top = 0; right = s.width; bottom = s.height; }

	CL_Rectf(float new_left, float new_top, float new_right, float new_bottom)
	{ left = new_left; top = new_top; right = new_right; bottom = new_bottom; }

	CL_Rectf(const CL_Pointf &p, const CL_Sizef &size)
	{ left = p.x; top = p.y; right = left + size.width; bottom = top + size.height; }

	CL_Rectf(const CL_Rectf &rect)
	{ left = rect.left; top = rect.top; right = rect.right; bottom = rect.bottom; }

	//: Rect == Rect operator.
	bool operator==(const CL_Rectf &r) const
	{ return (left == r.left && top == r.top && right == r.right && bottom == r.bottom); }

	//: Rect != Rect operator.
	bool operator!=(const CL_Rectf &r) const
	{ return (left != r.left || top != r.top || right != r.right || bottom != r.bottom); }

//! Attributes:
public:
	//: X1-coordinate.
	float left;
	
	//: Y1-coordinate.
	float top;
	
	//: X2-coordinate.
	float right;
	
	//: Y2-coordinate.
	float bottom;
	
	//: Returns the width of the rectangle.
	float get_width() const { return right - left; }
	
	//: Returns the height of the rectangle.
	float get_height() const { return bottom - top; }

	//: Returns the size of the rectangle.
	CL_Sizef get_size() const { return CL_Sizef(right - left, bottom - top); }
	
	//: Returns true if point is inside the rectangle.
	bool is_inside(const CL_Pointf &p) const { return (p.x >= left && p.y >= top && p.x <= right && p.y <= bottom); }
	
	//: Returns true if rectangle passed is overlapping or inside this rectangle.
	bool is_overlapped(const CL_Rectf &r) const 
	{
		return (r.left < right && r.right > left && r.top < bottom && r.bottom > top);
	}

	//: Returns another CL_Rectf containing a rotated version of this one.
	//param hotspot: Point to rotate around.
	//param origin: Determines the hotspot point within the rectangle
	//param x, y: Offsets applied negatively to the hotspot point
	//param angle: Angle to rotate in degrees.
	CL_Rectf get_rot_bounds(const CL_Pointf &hotspot, float angle) const;
	CL_Rectf get_rot_bounds(CL_Origin origin, float x, float y, float angle) const;

	//: Returns the center point of the rectangle.
	CL_Pointd get_center() const
	{
		return CL_Pointd( (left + right)/2.0, (top + bottom)/2.0 );
	}

//! Operations:
public:
	//: Shrink the rectangle
	CL_Rectf shrink(const CL_Rectf &r)
	{
		left += r.left; top += r.top; right -= r.right; bottom -= r.bottom; return *this;
	};

	//: Expand the rectangle
	CL_Rectf expand(const CL_Rectf &r)
	{
		left -= r.left; top -= r.top; right += r.right; bottom += r.bottom; return *this;
	};

	//: Translate the rect.
	CL_Rectf translate(const CL_Pointf &p)
	{
		left += p.x; top += p.y; right += p.x; bottom += p.y; return *this;
	};

	//: Translate the rect.
	CL_Rectf translate(float x, float y)
	{
		left += x; top += y; right += x; bottom += y; return *this;
	};

	//: Sets the size of the rectangle, maintaining top/left position.
	void set_size(const CL_Sizef &size)
	{
		right = left + size.width;
		bottom = top + size.height;
	}

	//: Calculates and returns the union of two rectangles.
	CL_Rectf calc_overlap(const CL_Rectf &rect) const
	{
		CL_Rectf result;
		result.left   = cl_max(left, rect.left);
		result.right  = cl_min(right, rect.right);
		result.top    = cl_max(top, rect.top);
		result.bottom = cl_min(bottom, rect.bottom);
		return result;
	}

	//: Calculates and returns the bounding rectangle of the rectangles.
	CL_Rectf calc_bounding_rect(const CL_Rectf &rect) const
	{
		CL_Rectf result;
		result.left   = cl_min(left, rect.left);
		result.right  = cl_max(right, rect.right);
		result.top    = cl_min(top, rect.top);
		result.bottom = cl_max(bottom, rect.bottom);
		return result;
	}

	//: Normalize rectangle. Ensures that left<right and top<bottom.
	void normalize()
	{
		if (left > right)
		{
			float temp = right;
			right = left;
			left = temp;
		}

		if (top > bottom)
		{
			float temp = bottom;
			bottom = top;
			top = temp;
		}
	}
	
	//: Applies an origin and offset pair to this rectangle
	//param origin: The new origin to adjust to from default upper-left position
	//param x, y: Offsets applied negatively to each corner of the rectangle
	void apply_alignment(CL_Origin origin, float x, float y)
	{
		CL_Pointd offset = calc_origin(origin, get_size());
		offset.x -= x;
		offset.y -= y;
		
		left += (float)offset.x;
		top += (float)offset.y;
		right += (float)offset.x;
		bottom += (float)offset.y;
	}
};

//: 2D (left,top,right,bottom) double floating point rectangle structure.
//- !group=Core/Math!
//- !header=core.h!
class CL_Rectd
{
//! Construction:
public:
	//: Constructs an rectangle.
	//param left: Initial left position of rectangle.
	//param top: Initial top position of rectangle.
	//param right: Initial right position of rectangle.
	//param bottom: Initial bottom position of rectangle.
	//param point: Initial top-left position of rectangle.
	//param size: Initial size of rectangle.
	//param rect: Initial rectangle position and size.
	CL_Rectd() { left = right = top = bottom = 0.0; }

	CL_Rectd(const CL_Rect& rect)
		: left((double) rect.left), 
		  top((double) rect.top), 
		  right((double) rect.right), 
		  bottom((double) rect.bottom)
	{}

	CL_Rectd(const CL_Sized &s) { left = top = 0; right = s.width; bottom = s.height; }

	CL_Rectd(double new_left, double new_top, double new_right, double new_bottom)
	{ left = new_left; top = new_top; right = new_right; bottom = new_bottom; }

	CL_Rectd(const CL_Pointd &p, const CL_Sized &size)
	{ left = p.x; top = p.y; right = left + size.width; bottom = top + size.height; }

	CL_Rectd(const CL_Rectd &rect)
	{ left = rect.left; top = rect.top; right = rect.right; bottom = rect.bottom; }

	//: Rect != Rect operator.
	bool operator!=(const CL_Rectd &r) const
	{ return (left != r.left || top != r.top || right != r.right || bottom != r.bottom); }

//! Attributes:
public:
	//: X1-coordinate.
	double left;
	
	//: Y1-coordinate.
	double top;
	
	//: X2-coordinate.
	double right;
	
	//: Y2-coordinate.
	double bottom;
	
	//: Returns the width of the rectangle.
	double get_width() const { return right - left; }
	
	//: Returns the height of the rectangle.
	double get_height() const { return bottom - top; }

	//: Returns the size of the rectangle.
	CL_Sized get_size() const { return CL_Sized(right - left, bottom - top); }
	
	//: Returns true if point is inside the rectangle.
	bool is_inside(const CL_Pointd &p) const { return (p.x >= left && p.y >= top && p.x <= right && p.y <= bottom); }
	
	//: Returns true if rectangle passed is overlapping or inside this rectangle.
	bool is_overlapped(const CL_Rectd &r) const 
	{
		return (r.left < right && r.right > left && r.top < bottom && r.bottom > top);
	}

	//: Returns the center point of the rectangle.
	CL_Pointd get_center() const
	{
		return CL_Pointd( (left + right)/2.0, (top + bottom)/2.0 );
	}

	//: Returns another CL_Rectd containing a rotated version of this one.
	//param hotspot: Point to rotate around.
	//param origin: Determines the hotspot point within the rectangle
	//param x, y: Offsets applied negatively to the hotspot point
	//param angle: Angle to rotate in degrees.
	CL_Rectd get_rot_bounds(const CL_Pointd &hotspot, float angle) const;
	CL_Rectd get_rot_bounds(CL_Origin origin, double x, double y, float angle) const;
	
//! Operations:
public:
	//: Shrink the rectangle
	CL_Rectd shrink(const CL_Rectd &r)
	{
		left += r.left; top += r.top; right -= r.right; bottom -= r.bottom; return *this;
	};

	//: Expand the rectangle
	CL_Rectd expand(const CL_Rectd &r)
	{
		left -= r.left; top -= r.top; right += r.right; bottom += r.bottom; return *this;
	};

	//: Translate the rect.
	CL_Rectd translate(const CL_Pointd &p)
	{
		left += p.x; top += p.y; right += p.x; bottom += p.y; return *this;
	};

	//: Translate the rect.
	CL_Rectd translate(double x, double y)
	{
		left += x; top += y; right += x; bottom += y; return *this;
	};

	//: Sets the size of the rectangle, maintaining top/left position.
	void set_size(const CL_Sized &size)
	{
		right = left + size.width;
		bottom = top + size.height;
	}

	//: Returns the overlapping area of the two rectangles.
	CL_Rectd calc_overlap(const CL_Rectd &rect)
	{
		CL_Rectd result;
		result.left   = cl_max(left, rect.left);
		result.right  = cl_min(right, rect.right);
		result.top    = cl_max(top, rect.top);
		result.bottom = cl_min(bottom, rect.bottom);
		return result;
	}

	CL_Rectd calc_bounding_rect(const CL_Rectd &rect) const
	{
		CL_Rectd result;
		result.left   = cl_min(left, rect.left);
		result.right  = cl_max(right, rect.right);
		result.top    = cl_min(top, rect.top);
		result.bottom = cl_max(bottom, rect.bottom);
		return result;
	}

	//: Normalize rectangle. Ensures that left<right and top<bottom.
	void normalize()
	{
		if (left > right)
		{
			double temp = right;
			right = left;
			left = temp;
		}

		if (top > bottom)
		{
			double temp = bottom;
			bottom = top;
			top = temp;
		}
	}
	
	//: Applies an origin and offset pair to this rectangle
	//param origin: The new origin to adjust to from default upper-left position
	//param x, y: Offsets applied negatively to each corner of the rectangle
	void apply_alignment(CL_Origin origin, double x, double y)
	{
		CL_Pointd offset = calc_origin(origin, get_size());
		offset.x -= x;
		offset.y -= y;
		
		left += offset.x;
		top += offset.y;
		right += offset.x;
		bottom += offset.y;
	}
};

inline CL_Rect CL_RectPS(int x, int y, int width, int height)
{
	return CL_Rect(x, y, x+width, y+height);
}

inline CL_Rectf CL_RectfPS(float x, float y, float width, float height)
{
	return CL_Rectf(x, y, x+width, y+height);
}

inline CL_Rectd CL_RectdPS(double x, double y, double width, double height)
{
	return CL_Rectd(x, y, x+width, y+height);
}

#endif
