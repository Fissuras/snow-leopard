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

//! clanCore="Signals"
//! header=core.h

#ifndef header_signal_v3
#define header_signal_v3

#if _MSC_VER > 1000
#pragma once
#endif

#include "slot.h"
#include "signals_impl.h"

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <class Param1, class Param2, class Param3>
class CL_SlotCallback_v3 : public CL_SlotCallback
{
public:
	virtual void invoke(Param1 param1, Param2 param2, Param3 param3) = 0;
};

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <class Param1, class Param2, class Param3>
class CL_SlotCallback_v3_static : public CL_SlotCallback_v3<Param1, Param2, Param3>
{
public:
	CL_SlotCallback_v3_static(void (*static_func)(Param1, Param2, Param3))
	: static_func(static_func) { return; }
	void invoke(Param1 param1, Param2 param2, Param3 param3) { static_func(param1, param2, param3); }
	void (*static_func)(Param1, Param2, Param3);
};

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <class Param1, class Param2, class Param3, class UserData>
class CL_SlotCallback_v3_static_user : public CL_SlotCallback_v3<Param1, Param2, Param3>
{
public:
	CL_SlotCallback_v3_static_user(void (*static_func)(Param1, Param2, Param3, UserData), const UserData &user_data)
	: static_func(static_func), user_data(user_data) { return; }
	void invoke(Param1 param1, Param2 param2, Param3 param3) { static_func(param1, param2, param3, user_data); }
	void (*static_func)(Param1, Param2, Param3, UserData);
	UserData user_data;
};

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <class Param1, class Param2, class Param3, class InstanceClass>
class CL_SlotCallback_v3_member : public CL_SlotCallback_v3<Param1, Param2, Param3>
{
public:
	CL_SlotCallback_v3_member(InstanceClass *instance, void (InstanceClass::*member_func)(Param1, Param2, Param3))
	: instance(instance), member_func(member_func) { return; }
	void invoke(Param1 param1, Param2 param2, Param3 param3) { (instance->*member_func)(param1, param2, param3); }
	InstanceClass *instance;
	void (InstanceClass::*member_func)(Param1, Param2, Param3);
};

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <class Param1, class Param2, class Param3, class InstanceClass, class UserData>
class CL_SlotCallback_v3_member_user : public CL_SlotCallback_v3<Param1, Param2, Param3>
{
public:
	CL_SlotCallback_v3_member_user(InstanceClass *instance, void (InstanceClass::*member_func)(Param1, Param2, Param3, UserData), const UserData &user_data)
	: instance(instance), member_func(member_func), user_data(user_data) { return; }
	void invoke(Param1 param1, Param2 param2, Param3 param3) { (instance->*member_func)(param1, param2, param3, user_data); }
	InstanceClass *instance;
	void (InstanceClass::*member_func)(Param1, Param2, Param3, UserData);
	UserData user_data;
};

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <class Param1, class Param2, class Param3, class Functor>
class CL_SlotCallback_v3_functor : public CL_SlotCallback_v3<Param1, Param2, Param3>
{
public:
	CL_SlotCallback_v3_functor(const Functor &functor)
	: functor(functor) { return; }
	void invoke(Param1 param1, Param2 param2, Param3 param3) { functor(param1, param2, param3); }
	Functor functor;
};

//- !group=Core/Signals!
//- !header=core.h!
template <class Param1, class Param2, class Param3>
class CL_Signal_v3
{
//! Construction:
public:
	CL_Signal_v3()
	: impl(new CL_Signal_Impl) { return; }

	CL_Signal_v3(const CL_Signal_v3<Param1, Param2, Param3> &copy)
	: impl(copy.impl) { return; }

//! Operations:
public:
	CL_Slot connect(void (*function)(Param1, Param2, Param3))
	{
		clean_up();
		CL_SharedPtr<CL_SlotCallback> callback(
			new CL_SlotCallback_v3_static<Param1, Param2, Param3>(function));
		impl->connected_slots.push_back(callback);
		return CL_Slot(callback);
	}

	template<class UserData>
	CL_Slot connect(void (*function)(Param1, Param2, Param3, UserData), const UserData &user_data)
	{
		clean_up();
		CL_SharedPtr<CL_SlotCallback> callback(
			new CL_SlotCallback_v3_static_user<Param1, Param2, Param3, UserData>(function, user_data));
		impl->connected_slots.push_back(callback);
		return CL_Slot(callback);
	}
	
	template<class InstanceClass>
	CL_Slot connect(InstanceClass *instance, void (InstanceClass::*function)(Param1, Param2, Param3))
	{
		clean_up();
		CL_SharedPtr<CL_SlotCallback> callback(
			new CL_SlotCallback_v3_member<Param1, Param2, Param3, InstanceClass>(instance, function));
		impl->connected_slots.push_back(callback);
		return CL_Slot(callback);
	}

	template<class InstanceClass, class UserData>
	CL_Slot connect(InstanceClass *instance, void (InstanceClass::*function)(Param1, Param2, Param3, UserData), const UserData &user_data)
	{
		clean_up();
		CL_SharedPtr<CL_SlotCallback> callback(
			new CL_SlotCallback_v3_member_user<Param1, Param2, Param3, InstanceClass, UserData>(instance, function, user_data));
		impl->connected_slots.push_back(callback);
		return CL_Slot(callback);
	}
	
	template<class Functor>
	CL_Slot connect_functor(const Functor &functor)
	{
		clean_up();
		CL_SharedPtr<CL_SlotCallback> callback(
			new CL_SlotCallback_v3_functor<Param1, Param2, Param3, Functor>(functor));
		impl->connected_slots.push_back(callback);
		return CL_Slot(callback);
	}
	
	void invoke(Param1 param1, Param2 param2, Param3 param3) const
	{
		std::vector< CL_SharedPtr<CL_SlotCallback> > callbacks = impl->connected_slots;
		std::vector< CL_SharedPtr<CL_SlotCallback> >::size_type i, size;
		size = callbacks.size();
		for (i = 0; i < size; i++)
			if (callbacks[i]->valid && callbacks[i]->enabled)
				((CL_SlotCallback_v3<Param1, Param2, Param3> *) callbacks[i].get())->invoke(param1, param2, param3);
	}

//! Implementation:
private:
	void clean_up()
	{
		std::vector< CL_SharedPtr<CL_SlotCallback> >::size_type i, size;
		size = impl->connected_slots.size();
		for (i = 0; i < size; i++)
		{
			if (!impl->connected_slots[i]->valid)
			{
				impl->connected_slots.erase(impl->connected_slots.begin()+i);
				i--;
				size--;
			}
		}
	}

	CL_SharedPtr<CL_Signal_Impl> impl;
};

#endif