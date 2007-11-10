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

//! clanCore="System"
//! header=core.h

#ifndef header_system
#define header_system

#include "../api_core.h"
#include "../Text/string_types.h"

//- !group=Core/System!
//- !header=core.h!
//- !hide!
struct CL_API_CORE CL_PreallocatedMemory
{
	int dummy;
};

class CL_Mutex;

//: General system helper functions.
//- !group=Core/System!
//- !header=core.h!
class CL_API_CORE CL_System
{
//! Attributes:
public:
	//: Get the current time (since system boot), in milliseconds.
	static unsigned int get_time();
	
	//: Returns true if MMX technology is available on this CPU.
	static bool detect_mmx();
	
	//: Returns true if 3DNow! technology is available on this CPU.
	static bool detect_3dnow();

	//: Returns true if extended 3DNow! is present on this CPU.
	static bool detect_ext_3dnow();

	//: Returns the mutex used by CL_SharedPtr.
	static CL_Mutex *get_sharedptr_mutex();

//! Operations:
public:
	//: Sleep for 'millis' milliseconds.
	static void sleep(int millis);

	//: Returns the full dirname of the executable that started this
	//: process (aka argv[0])
	//- <p>This is necessary since when programms are started from
	//- the PATH there is no clean and simple way to figure out
	//- the location of the data files, thus information is read
	//- from <tt>/proc/self/exe</tt> under GNU/Linux and from
	//- GetModuleFileName() on Win32.</p>
	//return: full dirname of the executable, trailing slash is included
	static CL_String get_exe_path();

	//: Calls the constructor of a class.
	template<typename T>
	static void call_constructor(T *memory)
	{
		new ((CL_PreallocatedMemory *) memory) T;
	}

	template<typename T, typename P1>
	static void call_constructor(T *memory, P1 p1)
	{
		new ((CL_PreallocatedMemory *) memory) T(p1);
	}

	template<typename T, typename P1, typename P2>
	static void call_constructor(T *memory, P1 p1, P2 p2)
	{
		new ((CL_PreallocatedMemory *) memory) T(p1, p2);
	}

	template<typename T, typename P1, typename P2, typename P3>
	static void call_constructor(T *memory, P1 p1, P2 p2, P3 p3)
	{
		new ((CL_PreallocatedMemory *) memory) T(p1, p2, p3);
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4>
	static void call_constructor(T *memory, P1 p1, P2 p2, P3 p3, P4 p4)
	{
		new ((CL_PreallocatedMemory *) memory) T(p1, p2, p3, p4);
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5>
	static void call_constructor(T *memory, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
	{
		new ((CL_PreallocatedMemory *) memory) T(p1, p2, p3, p4, p5);
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
	static void call_constructor(T *memory, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6)
	{
		new ((CL_PreallocatedMemory *) memory) T(p1, p2, p3, p4, p5, p6);
	}

	template<typename T, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
	static void call_constructor(T *memory, P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7)
	{
		new ((CL_PreallocatedMemory *) memory) T(p1, p2, p3, p4, p5, p6, p7);
	}

	//: Calls the destructor of a class.
	template<typename T>
	static void call_destructor(T *memory)
	{
		memory->~T();
	}

	static void alloc_thread_temp_pool();

	static void free_thread_temp_pool();

//! Implementation:
private:
};

#endif
