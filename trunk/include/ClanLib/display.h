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

//: <p>ClanLib display and input library.</p>
//! Global=Display

#ifndef header_display_include
#define header_display_include

#if _MSC_VER > 1000
#pragma once
#endif

#include "Display/blend_mode.h"
#include "Display/buffer_control.h"
#include "Display/color.h"
#include "Display/display.h"
#include "Display/display_message_queue.h"
#include "Display/display_message_queue_provider.h"
#include "Display/display_target.h"
#include "Display/display_target_provider.h"
#include "Display/display_window.h"
#include "Display/display_window_description.h"
#include "Display/display_window_provider.h"
#include "Display/display_window_message.h"
#include "Display/draw.h"
#include "Display/font.h"
#include "Display/font_provider.h"
#include "Display/font_metrics.h"
#include "Display/frame_buffer.h"
#include "Display/frame_buffer_provider.h"
#include "Display/render_buffer.h"
#include "Display/render_buffer_provider.h"
#include "Display/gradient.h"
#include "Display/graphic_context.h"
#include "Display/graphic_context_provider.h"
#include "Display/input_context.h"
#include "Display/input_device.h"
#include "Display/input_device_provider.h"
#include "Display/input_event.h"
#include "Display/input_state.h"
#include "Display/keyboard.h"
#include "Display/mouse.h"
#include "Display/keys.h"
#include "Display/light_model.h"
#include "Display/light_source.h"
#include "Display/material.h"
#include "Display/palette.h"
#include "Display/pen.h"
#include "Display/pixel_buffer.h"
#include "Display/pixel_format.h"
#include "Display/pixel_format_type.h"
#include "Display/polygon_rasterizer.h"
#include "Display/primitives_array.h"
#include "Display/program_attribute.h"
#include "Display/program_object.h"
#include "Display/program_uniform.h"
#include "Display/rounded_rect.h"
#include "Display/setup_display.h"
#include "Display/shader_object.h"
#include "Display/sprite.h"
#include "Display/sprite_description.h"
#include "Display/subtexture.h"
#include "Display/texture.h"
#include "Display/texture_group.h"
#include "Display/texture_provider.h"
#include "Display/texture_unit.h"
#include "Display/vector_font.h"
#include "Display/vertex_array_buffer.h"
#include "Display/vertex_array_buffer_provider.h"
#include "Display/element_array_buffer.h"
#include "Display/element_array_buffer_provider.h"
#include "Display/ImageProviders/jpeg_provider.h"
#include "Display/ImageProviders/pcx_provider.h"
#include "Display/ImageProviders/png_provider.h"
#include "Display/ImageProviders/provider_factory.h"
#include "Display/ImageProviders/provider_type.h"
#include "Display/ImageProviders/provider_type_register.h"
#include "Display/ImageProviders/targa_provider.h"
#include "Display/Collision/collision_outline.h"
#include "Display/Collision/contour.h"
#include "Display/Collision/outline_accuracy.h"
#include "Display/Collision/outline_circle.h"
#include "Display/Collision/outline_math.h"
#include "Display/Collision/outline_provider.h"
#include "Display/Collision/outline_provider_bitmap.h"
#include "Display/Collision/outline_provider_file.h"

#if defined (_MSC_VER)
	#if !defined (UNICODE)
		#if defined (CL_DLL)
			#if !defined (_DEBUG)
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-dll.lib")
				#else
					#pragma comment(lib, "clanDisplay-dll.lib")
				#endif
			#else
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-dll-debug.lib")
				#else
					#pragma comment(lib, "clanDisplay-dll-debug.lib")
				#endif
			#endif
		#elif defined (CL_STATIC_MTDLL)
			#if !defined (_DEBUG)
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-static-mtdll.lib")
					#pragma comment(lib, "libjpeg-x64-static-mtdll.lib")
					#pragma comment(lib, "libpng-x64-static-mtdll.lib")
					#pragma comment(lib, "freetype-x64-static-mtdll.lib")
				#else
					#pragma comment(lib, "clanDisplay-static-mtdll.lib")
					#pragma comment(lib, "libjpeg-static-mtdll.lib")
					#pragma comment(lib, "libpng-static-mtdll.lib")
					#pragma comment(lib, "freetype-static-mtdll.lib")
				#endif
			#else
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-static-mtdll-debug.lib")
					#pragma comment(lib, "libjpeg-x64-static-mtdll-debug.lib")
					#pragma comment(lib, "libpng-x64-static-mtdll-debug.lib")
					#pragma comment(lib, "freetype-x64-static-mtdll-debug.lib")
				#else
					#pragma comment(lib, "clanDisplay-static-mtdll-debug.lib")
					#pragma comment(lib, "libjpeg-static-mtdll-debug.lib")
					#pragma comment(lib, "libpng-static-mtdll-debug.lib")
					#pragma comment(lib, "freetype-static-mtdll-debug.lib")
				#endif
			#endif
			#pragma comment(lib, "winmm.lib")
			#pragma comment(lib, "dinput.lib")
			#pragma comment(lib, "dxguid.lib")
		#else
			#if !defined (_DEBUG)
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-static-mt.lib")
					#pragma comment(lib, "libjpeg-x64-static-mt.lib")
					#pragma comment(lib, "libpng-x64-static-mt.lib")
					#pragma comment(lib, "freetype-x64-static-mt.lib")
				#else
					#pragma comment(lib, "clanDisplay-static-mt.lib")
					#pragma comment(lib, "libjpeg-static-mt.lib")
					#pragma comment(lib, "libpng-static-mt.lib")
					#pragma comment(lib, "freetype-static-mt.lib")
				#endif
			#else
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-static-mt-debug.lib")
					#pragma comment(lib, "libjpeg-x64-static-mt-debug.lib")
					#pragma comment(lib, "libpng-x64-static-mt-debug.lib")
					#pragma comment(lib, "freetype-x64-static-mt-debug.lib")
				#else
					#pragma comment(lib, "clanDisplay-static-mt-debug.lib")
					#pragma comment(lib, "libjpeg-static-mt-debug.lib")
					#pragma comment(lib, "libpng-static-mt-debug.lib")
					#pragma comment(lib, "freetype-static-mt-debug.lib")
				#endif
			#endif
			#pragma comment(lib, "winmm.lib")
			#pragma comment(lib, "dinput.lib")
			#pragma comment(lib, "dxguid.lib")
		#endif
	#else
		#if defined (CL_DLL)
			#if !defined (_DEBUG)
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-dll-uc.lib")
				#else
					#pragma comment(lib, "clanDisplay-dll-uc.lib")
				#endif
			#else
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-dll-uc-debug.lib")
				#else
					#pragma comment(lib, "clanDisplay-dll-uc-debug.lib")
				#endif
			#endif
		#elif defined (CL_STATIC_MTDLL)
			#if !defined (_DEBUG)
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-static-mtdll-uc.lib")
					#pragma comment(lib, "libjpeg-x64-static-mtdll.lib")
					#pragma comment(lib, "libpng-x64-static-mtdll.lib")
					#pragma comment(lib, "freetype-x64-static-mtdll.lib")
				#else
					#pragma comment(lib, "clanDisplay-static-mtdll-uc.lib")
					#pragma comment(lib, "libjpeg-static-mtdll.lib")
					#pragma comment(lib, "libpng-static-mtdll.lib")
					#pragma comment(lib, "freetype-static-mtdll.lib")
				#endif
			#else
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-static-mtdll-uc-debug.lib")
					#pragma comment(lib, "libjpeg-x64-static-mtdll-debug.lib")
					#pragma comment(lib, "libpng-x64-static-mtdll-debug.lib")
					#pragma comment(lib, "freetype-x64-static-mtdll-debug.lib")
				#else
					#pragma comment(lib, "clanDisplay-static-mtdll-uc-debug.lib")
					#pragma comment(lib, "libjpeg-static-mtdll-debug.lib")
					#pragma comment(lib, "libpng-static-mtdll-debug.lib")
					#pragma comment(lib, "freetype-static-mtdll-debug.lib")
				#endif
			#endif
			#pragma comment(lib, "winmm.lib")
			#pragma comment(lib, "dinput.lib")
			#pragma comment(lib, "dxguid.lib")
		#else
			#if !defined (_DEBUG)
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-static-mt-uc.lib")
					#pragma comment(lib, "libjpeg-x64-static-mt.lib")
					#pragma comment(lib, "libpng-x64-static-mt.lib")
					#pragma comment(lib, "freetype-x64-static-mt.lib")
				#else
					#pragma comment(lib, "clanDisplay-static-mt-uc.lib")
					#pragma comment(lib, "libjpeg-static-mt.lib")
					#pragma comment(lib, "libpng-static-mt.lib")
					#pragma comment(lib, "freetype-static-mt.lib")
				#endif
			#else
				#if defined(_M_X64)
					#pragma comment(lib, "clanDisplay-x64-static-mt-uc-debug.lib")
					#pragma comment(lib, "libjpeg-x64-static-mt-debug.lib")
					#pragma comment(lib, "libpng-x64-static-mt-debug.lib")
					#pragma comment(lib, "freetype-x64-static-mt-debug.lib")
				#else
					#pragma comment(lib, "clanDisplay-static-mt-uc-debug.lib")
					#pragma comment(lib, "libjpeg-static-mt-debug.lib")
					#pragma comment(lib, "libpng-static-mt-debug.lib")
					#pragma comment(lib, "freetype-static-mt-debug.lib")
				#endif
			#endif
			#pragma comment(lib, "winmm.lib")
			#pragma comment(lib, "dinput.lib")
			#pragma comment(lib, "dxguid.lib")
		#endif
	#endif
#endif

#endif
