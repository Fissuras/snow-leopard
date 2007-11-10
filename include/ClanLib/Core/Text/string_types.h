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
*/

//! clanCore="Text"
//! header=core.h

#ifndef header_string_types
#define header_string_types

#include "../api_core.h"
#include "character_set.h"
#include "string_ref8.h"
#include "string_ref16.h"
#include "string8.h"
#include "string16.h"

#ifdef UNICODE
typedef CL_StringRef16 CL_StringRef;
typedef CL_String16 CL_String;
typedef CL_TempString16 CL_TempString;
#define CL_FixedString CL_FixedString16
#define cl_text(a) L##a
#else
typedef CL_StringRef8 CL_StringRef;
typedef CL_String8 CL_String;
typedef CL_TempString8 CL_TempString;
#define CL_FixedString CL_FixedString8
#define cl_text(a) a
#endif

#endif
