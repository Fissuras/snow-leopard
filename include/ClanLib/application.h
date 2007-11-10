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
**    (if your name is missing here, please add it)
*/

//: <p>Application bootstrapping library. When booting your application,
//: you can either use the low level, platform dependent approach in clanCore,
//: or you can use the CL_ClanApplication interface in clanApp.</p>
//! Global=App

#ifndef header_application
#define header_application

#if _MSC_VER > 1000
#pragma once
#endif

#include "Application/clanapp.h"

#if defined (_MSC_VER)
	#if !defined (UNICODE)
		#if defined (CL_DLL)
			#if !defined (_DEBUG)
				#pragma comment(lib, "clanApplication-dll.lib")
			#else
				#pragma comment(lib, "clanApplication-dll-debug.lib")
			#endif
		#elif defined (CL_STATIC_MTDLL)
			#if !defined (_DEBUG)
				#pragma comment(lib, "clanApplication-static-mtdll.lib")
			#else
				#pragma comment(lib, "clanApplication-static-mtdll-debug.lib")
			#endif
		#else
			#if !defined (_DEBUG)
				#pragma comment(lib, "clanApplication-static-mt.lib")
			#else
				#pragma comment(lib, "clanApplication-static-mt-debug.lib")
			#endif
		#endif
	#else
		#if defined (CL_DLL)
			#if !defined (_DEBUG)
				#pragma comment(lib, "clanApplication-dll-uc.lib")
			#else
				#pragma comment(lib, "clanApplication-dll-uc-debug.lib")
			#endif
		#elif defined (CL_STATIC_MTDLL)
			#if !defined (_DEBUG)
				#pragma comment(lib, "clanApplication-static-mtdll-uc.lib")
			#else
				#pragma comment(lib, "clanApplication-static-mtdll-uc-debug.lib")
			#endif
		#else
			#if !defined (_DEBUG)
				#pragma comment(lib, "clanApplication-static-mt-uc.lib")
			#else
				#pragma comment(lib, "clanApplication-static-mt-uc-debug.lib")
			#endif
		#endif
	#endif
#endif

#endif
