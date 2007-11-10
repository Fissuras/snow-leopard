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

#ifndef header_mutex
#define header_mutex

#include "../api_core.h"

#ifdef WIN32
#include <windows.h>
#else
#ifndef __USE_UNIX98
#define __USE_UNIX98
#endif
#include <pthread.h>
#endif

//: Mutex class.
//- !group=Core/System!
//- !header=core.h!
class CL_API_CORE CL_Mutex
{
//! Construction:
public:
	//: Constructs a mutex object.
	CL_Mutex();

	~CL_Mutex();

//! Attributes:
public:

//! Operations:
public:
	//: Lock mutex.
	void lock();

	//: Attempt to lock mutex.
	bool try_lock();

	//: Unlock mutex.
	void unlock();

//! Implementation:
private:
#ifdef WIN32
	CRITICAL_SECTION critical_section;
#else
	pthread_mutex_t handle;
#endif
};

//: Mutex locking helper.
//- !group=Core/System!
//- !header=core.h!
class CL_API_CORE CL_MutexSection
{
//! Construction:
public:
	//: Constructs a mutex section.
	CL_MutexSection(CL_Mutex *mutex, bool lock_mutex = true)
	: mutex(mutex), lock_count(0)
	{
		if (lock_mutex)
			lock();
	}

	~CL_MutexSection()
	{
		if (lock_count > 0 && mutex)
			mutex->unlock();
		lock_count = 0;
	}

//! Attributes:
public:
	//: Returns the amounts of recursive mutex locks performed by this section.
	int get_lock_count() const
	{
		return lock_count;
	}

//! Operations:
public:
	//: Lock the mutex.
	void lock()
	{
		if (mutex)
			mutex->lock();
		lock_count++;
	}

	//: Attempt to lock mutex.
	bool try_lock()
	{
		if (mutex == 0 || mutex->try_lock())
		{
			lock_count++;
			return true;
		}
		return false;
	}

	//: Unlock mutex.
	void unlock()
	{
		if (lock_count <= 0)
			return;

		if (mutex)
			mutex->unlock();
		lock_count--;
	}

//! Implementation:
private:
	CL_Mutex *mutex;

	int lock_count;
};

#endif
