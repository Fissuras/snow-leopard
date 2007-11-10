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

#ifndef header_callback_0
#define header_callback_0

#if _MSC_VER > 1000
#pragma once
#endif

#include "../System/exception.h"
#include "../System/sharedptr.h"

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <typename RetVal>
class CL_Callback_Impl_0
{
public:
	virtual ~CL_Callback_Impl_0()
	{
	}
	
	virtual RetVal invoke() = 0;
};

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <typename RetVal>
class CL_Callback_Impl_0_static : public CL_Callback_Impl_0<RetVal>
{
public:
	CL_Callback_Impl_0_static(RetVal (*static_func)())
	: static_func(static_func)
	{
	}
	
	RetVal invoke()
	{
		return static_func();
	}
	
	RetVal (*static_func)();
};

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <typename RetVal, typename UserData>
class CL_Callback_Impl_0_static_user : public CL_Callback_Impl_0<RetVal>
{
public:
	CL_Callback_Impl_0_static_user(
		RetVal (*static_func)(UserData), const UserData &user_data)
	: static_func(static_func), user_data(user_data)
	{
	}
	
	RetVal invoke()
	{
		return static_func(user_data);
	}
	
	RetVal (*static_func)(UserData);
	
	UserData user_data;
};

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <typename RetVal, typename InstanceClass>
class CL_Callback_Impl_0_member : public CL_Callback_Impl_0<RetVal>
{
public:
	CL_Callback_Impl_0_member(InstanceClass *instance,
		RetVal (InstanceClass::*member_func)())
	: instance(instance), member_func(member_func)
	{
	}
	
	RetVal invoke()
	{
		return (instance->*member_func)();
	}
	
	InstanceClass *instance;
	
	RetVal (InstanceClass::*member_func)();
};

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <typename RetVal, typename InstanceClass, typename UserData>
class CL_Callback_Impl_0_member_user : public CL_Callback_Impl_0<RetVal>
{
public:
	CL_Callback_Impl_0_member_user(InstanceClass *instance,
		RetVal (InstanceClass::*member_func)(UserData), const UserData &user_data)
	: instance(instance), member_func(member_func), user_data(user_data)
	{
	}

	RetVal invoke()
	{
		return (instance->*member_func)(user_data);
	}
	
	InstanceClass *instance;
	
	RetVal (InstanceClass::*member_func)(UserData);
	
	UserData user_data;
};

//- !group=Core/Signals!
//- !header=core.h!
//- !hide!
template <typename RetVal, class Functor>
class CL_Callback_Impl_0_functor : public CL_Callback_Impl_0<RetVal>
{
public:
	CL_Callback_Impl_0_functor(Functor functor)
	: functor(functor)
	{
	}
	
	RetVal invoke()
	{
		return functor();
	}

	Functor functor;
};

//- !group=Core/Signals!
//- !header=core.h!
template <typename RetVal>
class CL_Callback_0
{
public:
	CL_Callback_0()
	{
	}
	
	CL_Callback_0(const CL_Callback_0 &copy)
	: impl(copy.impl)
	{
	}
	
	CL_Callback_0(CL_Callback_Impl_0<RetVal> *impl)
	: impl(impl)
	{
	}
	
	CL_Callback_0(RetVal (*function)())
	: impl(new CL_Callback_Impl_0_static<RetVal>(function))
	{
	}
	
	template<typename UserData>
	CL_Callback_0(RetVal (*function)(UserData), const UserData &user_data)
	: impl(new CL_Callback_Impl_0_static_user<RetVal, UserData>(function, user_data))
	{
	}

	template<class InstanceClass>
	CL_Callback_0(InstanceClass *instance, RetVal (InstanceClass::*function)())
	: impl(new CL_Callback_Impl_0_member<RetVal, InstanceClass>(instance, function))
	{
	}

	template<class InstanceClass, typename UserData>
	CL_Callback_0(InstanceClass *instance, RetVal (InstanceClass::*function)(UserData), const UserData &user_data)
	: impl(new CL_Callback_Impl_0_member_user<RetVal, InstanceClass, UserData>(instance, function, user_data))
	{
	}

	void set(RetVal (*function)())
	{
		impl = CL_SharedPtr< CL_Callback_Impl_0<RetVal> >(new CL_Callback_Impl_0_static<RetVal>(function));
	}
	
	template<typename UserData>
	void set(RetVal (*function)(UserData), const UserData &user_data)
	{
		impl = CL_SharedPtr< CL_Callback_Impl_0<RetVal> >(new CL_Callback_Impl_0_static_user<RetVal, UserData>(function, user_data));
	}

	template<class InstanceClass>
	void set(InstanceClass *instance, RetVal (InstanceClass::*function)())
	{
		impl = CL_SharedPtr< CL_Callback_Impl_0<RetVal> >(new CL_Callback_Impl_0_member<RetVal, InstanceClass>(instance, function));
	}

	template<class InstanceClass, typename UserData>
	void set(InstanceClass *instance, RetVal (InstanceClass::*function)(UserData), const UserData &user_data)
	{
		impl = CL_SharedPtr< CL_Callback_Impl_0<RetVal> >(new CL_Callback_Impl_0_member_user<RetVal, InstanceClass, UserData>(instance, function, user_data));
	}

	void clear()
	{
		impl = CL_SharedPtr< CL_Callback_Impl_0<RetVal> >();
	}

	RetVal invoke()
	{
		return impl->invoke();
	}
	
	bool is_null() const
	{
		return impl.is_null();
	}
	
private:
	CL_SharedPtr< CL_Callback_Impl_0<RetVal> > impl;
};

//- !group=Core/Signals!
//- !header=core.h!
template <typename RetVal>
class CL_Callback_0_functor : public CL_Callback_0<RetVal>
{
public:
	CL_Callback_0_functor()
	{
	}

	CL_Callback_0_functor(const CL_Callback_0_functor &copy)
	: CL_Callback_0<RetVal>(copy)
	{
	}
	
	template<class Functor>
	CL_Callback_0_functor(Functor functor)
	: CL_Callback_0<RetVal>(new CL_Callback_Impl_0_functor<RetVal, Functor>(functor))
	{
	}
	
};

#endif
