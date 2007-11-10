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

#ifndef header_string16
#define header_string16

#include "../api_core.h"
#include "string_ref16.h"
#include "string_ref8.h"

// IMPORTANT: If you change this file, make sure they are done in string16.h too!
//            Compilers are still too primitive to just create a template. :/

//: 16 bit memory pool string class.
//- !group=Core/Text!
//- !header=core.h!
class CL_API_CORE CL_PoolString16 : public CL_StringRef16
{
public:
	CL_PoolString16()
	: _capacity(0), _pool(0)
	{
	}

	CL_PoolString16(CL_MemoryPool *pool)
	: _capacity(0), _pool(pool)
	{
	}

	CL_PoolString16(const CL_StringRef16 &source)
	: _capacity(0), _pool(0)
	{
		assign(source);
	}

	explicit CL_PoolString16(const CL_PoolString16 &source)
	: _capacity(0), _pool(0)
	{
		assign(source);
	}

	CL_PoolString16(const CL_PoolString16 &source, CL_MemoryPool *pool)
	: _capacity(0), _pool(pool)
	{
		assign(source);
	}

	CL_PoolString16(const CharacterType *str, CL_CharacterSet *char_set = 0, CL_MemoryPool *pool = 0)
	: _capacity(0), _pool(pool)
	{
		charset = char_set;
		assign(str);
	}

	CL_PoolString16(const CharacterType *str, size_type length, CL_CharacterSet *char_set = 0, CL_MemoryPool *pool = 0)
	: _capacity(0), _pool(pool)
	{
		charset = char_set;
		assign(str, length);
	}

	CL_PoolString16(size_type n, CharacterType c, CL_CharacterSet *char_set = 0, CL_MemoryPool *pool = 0)
	: _capacity(0), _pool(pool)
	{
		charset = char_set;
		assign(n, c);
	}

	CL_PoolString16(const CL_StringRef8::CharacterType *str, CL_CharacterSet *char_set = 0, CL_MemoryPool *pool = 0);

	~CL_PoolString16()
	{
		if (_temporary)
			CL_MemoryPool::get_temp_pool()->free(_data);
		else if (_pool)
			_pool->free(_data);
		else
			delete[] _data;
		_temporary = false;
	}

	size_type max_size() const { return (size_type) -1; }
	size_type capacity() const { return _capacity; }
	
//	void swap(CL_PoolString16 &other);
//	static inline swap(CL_PoolString16 &s1, CL_PoolString16 &s2);

	void clear()
	{
		resize(0);
	}

	void reserve(size_type size)
	{
		if (_capacity >= size)
			return;

		CharacterType *old_data = _data;

		if (_pool)
			_data = (CharacterType *) _pool->alloc((size + 1) * sizeof(CharacterType));
		else
			_data = new CharacterType[size+1];

		memcpy(_data, old_data, _length * sizeof(CharacterType));
		_data[_length] = 0;
		_null_terminated = true;
		_capacity = size;

		if (_temporary)
			CL_MemoryPool::get_temp_pool()->free(old_data);
		else if (_pool)
			_pool->free(old_data);
		else
			delete[] old_data;
	}

	void resize(size_type n)
	{
		if (n > _capacity)
			reserve(n);
		_length = n;
		if (_null_terminated)
			_data[_length] = 0;
	}

	void resize(size_type n, CharacterType c)
	{
		size_type last_length = _length;
		resize(n);
		for (size_type i = last_length; i < n; i++)
			_data[i] = c;
	}

//	template <class InputIterator>
//	CL_PoolString16 &assign(InputIterator first, InputIterator last);

	CL_PoolString16 &assign(const CL_StringRef16 &s)
	{
		resize(s.length());
		memcpy(_data, s.data(), sizeof(CharacterType) * _length);
		return *this;
	}

	CL_PoolString16 &assign(const CL_StringRef16 &s, size_type pos, size_type n)
	{
		assign(s.substr(pos, n));
		return *this;
	}

	CL_PoolString16 &assign(const CharacterType *s, size_type n)
	{
		resize(n);
		memcpy(_data, s, sizeof(CharacterType) * _length);
		return *this;
	}

	CL_PoolString16 &assign(const CharacterType *s)
	{
		resize(CharacterTraits::length(s));
		memcpy(_data, s, sizeof(CharacterType) * _length);
		return *this;
	}

	CL_PoolString16 &assign(size_type n, CharacterType c)
	{
		resize(n);
		for (size_type i = 0; i < n; i++)
			_data[i] = c;
		return *this;
	}

	iterator insert(iterator pos, const CharacterType &item)
	{
		size_type insert_pos = (size_type) (pos - begin());
		size_type n = length();
		if (insert_pos > n)
			insert_pos = n;
		resize(n + 1);
		CharacterType *d = data();
		d[insert_pos] = item;
		for (size_type i = insert_pos + 1; i < n; i++)
			d[i] = d[i+1];
		return begin() + insert_pos;
	}

	void insert(iterator pos, size_type num_copies, const CharacterType &item)
	{
		if (num_copies == 0)
			return;
		size_type insert_pos = (size_type) (pos - begin());
		size_type n = length();
		if (insert_pos > n)
			insert_pos = n;
		resize(n + num_copies);
		CharacterType *d = data();
		for (size_type j = 0; j < num_copies; j++)
			d[insert_pos + j] = item;
		for (size_type i = insert_pos + num_copies; i < n + num_copies - 1; i++)
			d[i] = d[i+1];
	}

	CL_PoolString16 &insert(size_type pos, const CL_StringRef16 &s)
	{
		return insert(pos, s.data(), s.length());
	}
	
	CL_PoolString16 &insert(size_type pos, const CL_StringRef16 &s, size_type pos1, size_type length)
	{
		return insert(pos, s.data() + pos1, length);
	}
	
	CL_PoolString16 &insert(size_type pos, const CharacterType *s)
	{
		return insert(pos, s, CharacterTraits::length(s));
	}

	CL_PoolString16 &insert(size_type pos, const CharacterType *s, size_type s_length)
	{
		size_type old_len = length();
		if (pos == npos || pos > old_len)
			pos = old_len;
		resize(old_len + s_length);
		CharacterType *d = data();
		size_type i;
		for (i = length(); i > pos + s_length; i--)
			d[i-1] = d[i-1-s_length];
		for (i = pos; i < pos + s_length; i++)
			d[i] = s[i-pos];
		return *this;
	}

	CL_PoolString16 &insert(size_type pos, size_type n, CharacterType c)
	{
		size_type old_len = length();
		if (pos == npos || pos > old_len)
			pos = old_len;
		resize(old_len + n);
		CharacterType *d = data();
		size_type i;
		for (i = length(); i > pos + n; i--)
			d[i-1] = d[i-1-n];
		for (i = pos; i < pos + n; i++)
			d[i] = c;
		return *this;
	}

	CL_PoolString16 &append(const CL_StringRef16 &s)
	{
		return insert(length(), s);
	}
	
	CL_PoolString16 &append(const CL_StringRef16 &s, size_type pos, size_type n)
	{
		return insert(length(), s, pos, n);
	}
	
	CL_PoolString16 &append(const CharacterType *s)
	{
		return insert(length(), s);
	}

	CL_PoolString16 &append(const CharacterType *s, size_type n)
	{
		return insert(length(), s, n);
	}

	CL_PoolString16 &append(size_type n, CharacterType c)
	{
		return insert(length(), n, c);
	}

	void push_back(CharacterType c)
	{
		resize(length()+1, c);
	}

	iterator erase(iterator p)
	{
		iterator e = end();
		if (p == e)
			return e;
		return erase(p, p+1);
	}
	
	iterator erase(iterator first, iterator last)
	{
		size_type pos = (size_type) (first - begin());
		iterator e = end();
		iterator p1 = first;
		iterator p2 = last;
		while (p2 != e)
		{
			*p1 = *p2;
			p1++;
			p2++;
		}
		size_type new_size = (size_type) (p1 - begin());
		resize(new_size);
		return begin() + pos;
	}
	
	CL_PoolString16 &erase(size_type pos = 0, size_type n = npos)
	{
		if (pos > length())
			return *this;
		size_type left = length() - pos;
		if (n == npos || n > left)
			n = left;
		erase(begin() + pos, begin() + pos + n);
		return *this;
	}

	CL_PoolString16 &replace(size_type pos, size_type n, const CL_StringRef16 &s)
	{
		return replace(pos, n, s.data(), s.length());
	}
	
	CL_PoolString16 &replace(size_type pos, size_type n, const CL_StringRef16 &s, size_type pos1, size_type n1)
	{
		if (pos1 == npos || pos1 > s.length())
			return *this;
		if (pos1 + n1 > s.length())
			n1 = s.length() - pos1;
		return replace(pos, n, s.data() + pos1, n1);
	}
	
	CL_PoolString16 &replace(size_type pos, size_type n, const CharacterType *s, size_type n1)
	{
		if (pos == npos || pos > length())
			pos = length();
		if (n == npos || pos + n > length())
			n = length() - pos;
		if (n1 == n)
		{
			memcpy(data() + pos, s, n * sizeof(CharacterType));
		}
		else if (n1 > n)
		{
			size_type rest_of_string = length() - pos - n;
			resize(length() + n1 - n);
			memmove(data() + pos + n1, data() + pos + n, rest_of_string * sizeof(CharacterType));
			memcpy(data() + pos, s, n1 * sizeof(CharacterType));
		}
		else
		{
			size_type rest_of_string = length() - pos - n;
			memcpy(data() + pos, s, n1 * sizeof(CharacterType));
			memcpy(data() + pos + n1, data() + pos + n, rest_of_string * sizeof(CharacterType));
			resize(length() + n1 - n);
		}
		return *this;
	}

	CL_PoolString16 &replace(size_type pos, size_type n, const CharacterType *s)
	{
		return replace(pos, n, s, CharacterTraits::length(s));
	}

	CL_PoolString16 &replace(size_type pos, size_type n, size_type n1, CharacterType c)
	{
		if (pos == npos || pos > length())
			pos = length();
		if (n == npos || pos + n > length())
			n = length() - pos;
		if (n1 == n)
		{
			CharacterType *d = data() + pos;
			for (size_type i = 0; i < n1; i++)
				d[i] = c;
		}
		else if (n1 > n)
		{
			size_type rest_of_string = length() - pos - n;
			resize(length() + n1 - n);
			memmove(data() + pos + n1, data() + pos + n, rest_of_string * sizeof(CharacterType));
			CharacterType *d = data() + pos;
			for (size_type i = 0; i < n1; i++)
				d[i] = c;
		}
		else
		{
			size_type rest_of_string = length() - pos - n;
			CharacterType *d = data() + pos;
			for (size_type i = 0; i < n1; i++)
				d[i] = c;
			memcpy(data() + pos + n1, data() + pos + n, rest_of_string * sizeof(CharacterType));
			resize(length() + n1 - n);
		}
		return *this;
	}

	CL_PoolString16 &replace(iterator first, iterator last, const CL_StringRef16 &s)
	{
		return replace((size_type) (first - begin()), (size_type) (last-first), s);
	}
	
	CL_PoolString16 &replace(iterator first, iterator last, const CharacterType *s, size_type n)
	{
		return replace((size_type) (first - begin()), (size_type) (last-first), s, n);
	}

	CL_PoolString16 &replace(iterator first, iterator last, const CharacterType *s)
	{
		return replace((size_type) (first - begin()), (size_type) (last-first), s);
	}

	CL_PoolString16 &replace(iterator first, iterator last, size_type n, CharacterType c)
	{
		return replace((size_type) (first - begin()), (size_type) (last-first), n, c);
	}

	size_type copy(CharacterType *buf, size_type n, size_type pos = 0) const
	{
		if (pos == npos || pos > length())
			return 0;
		if (pos + n > length())
			n = length() - pos;
		memcpy(buf, data(), n * sizeof(CharacterType));
		return n;
	}

	CL_PoolString16 &operator =(const CL_StringRef16 &source)
	{
		return assign(source);
	}

	CL_PoolString16 &operator =(const CL_PoolString16 &source)
	{
		return assign(source);
	}

	CL_PoolString16 &operator =(const CharacterType *str)
	{
		return assign(str);
	}

	CL_PoolString16 &operator +=(const CL_StringRef16 &s)
	{
		return append(s);
	}

	CL_PoolString16 &operator +=(const CharacterType *s)
	{
		return append(s);
	}

	CL_PoolString16 &operator +=(CharacterType c)
	{
		return append(1, c);
	}
	
protected:
	mutable size_type _capacity;
	CL_MemoryPool *_pool;
};

//: 16 bit temporary string class.
//- !group=Core/Text!
//- !header=core.h!
class CL_API_CORE CL_TempString16 : public CL_PoolString16
{
public:
	CL_TempString16()
	{
		_pool = CL_MemoryPool::get_temp_pool();
	}

	CL_TempString16(const CL_StringRef16 &source)
	{
		_pool = CL_MemoryPool::get_temp_pool();
		assign(source);
	}

	explicit CL_TempString16(const CL_TempString16 &source)
	{
		_pool = CL_MemoryPool::get_temp_pool();
		assign(source);
	}

	CL_TempString16(const CharacterType *str, CL_CharacterSet *char_set = 0)
	{
		_pool = CL_MemoryPool::get_temp_pool();
		charset = char_set;
		assign(str);
	}

	CL_TempString16(const CharacterType *str, size_type length, CL_CharacterSet *char_set = 0)
	{
		_pool = CL_MemoryPool::get_temp_pool();
		charset = char_set;
		assign(str, length);
	}

	CL_TempString16(size_type n, CharacterType c, CL_CharacterSet *char_set = 0)
	{
		_pool = CL_MemoryPool::get_temp_pool();
		charset = char_set;
		assign(n, c);
	}

	CL_TempString16 &operator =(const CL_TempString16 &source)
	{
		assign(source);
		return *this;
	}
};

//: 16 bit string class.
//- !group=Core/Text!
//- !header=core.h!
template<int _fixed_size>
class CL_API_CORE CL_FixedString16 : public CL_PoolString16
{
public:
	CL_FixedString16()
	{
		_pool = &fixed_pool;
		reserve(fixed_size - 1);
	}

	CL_FixedString16(const CL_StringRef16 &source)
	{
		_pool = &fixed_pool;
		reserve(fixed_size - 1);
		assign(source);
	}

	explicit CL_FixedString16(const CL_FixedString16 &source)
	{
		_pool = &fixed_pool;
		reserve(fixed_size - 1);
		assign(source);
	}

	CL_FixedString16(const CharacterType *str, CL_CharacterSet *char_set = 0)
	{
		_pool = &fixed_pool;
		charset = char_set;
		reserve(fixed_size - 1);
		assign(str);
	}

	CL_FixedString16(const CharacterType *str, size_type length, CL_CharacterSet *char_set = 0)
	{
		_pool = &fixed_pool;
		charset = char_set;
		reserve(fixed_size - 1);
		assign(str, length);
	}

	CL_FixedString16(size_type n, CharacterType c, CL_CharacterSet *char_set = 0)
	{
		_pool = &fixed_pool;
		charset = char_set;
		reserve(fixed_size - 1);
		assign(n, c);
	}

	~CL_FixedString16()
	{
		// We have to free the data here since the pool is destroyed when parent destructor is called.
		if (!_temporary && _pool)
		{
			_pool->free(_data);
			_data = 0;
			_length = 0;
			_capacity = 0;
			_pool = 0;
		}
	}

	CL_FixedString16 &operator =(const CL_FixedString16 &source)
	{
		assign(source);
		return *this;
	}

private:
	enum
	{
		fixed_size = _fixed_size,
		fixed_size_bytes = _fixed_size * sizeof(CharacterType)
	};

	CL_FixedMemoryPool<fixed_size_bytes> fixed_pool;
};

typedef CL_FixedString16<64> CL_String16;

//- !group=Core/Text!
//- !header=core.h!
//- !hide!
inline CL_TempString16 operator+(const CL_StringRef16 &s1, const CL_StringRef16 &s2)
{
	CL_TempString16 result;
	result.reserve(s1.length() + s2.length());
	result.append(s1);
	result.append(s2);
	return result;
}

//- !group=Core/Text!
//- !header=core.h!
//- !hide!
inline CL_TempString16 operator+(const CL_StringRef16::CharacterType *s1, const CL_StringRef16 &s2)
{
	CL_TempString16 result;
	result.reserve(CL_StringRef16::CharacterTraits::length(s1) + s2.length());
	result.append(s1);
	result.append(s2);
	return result;
}

//- !group=Core/Text!
//- !header=core.h!
//- !hide!
inline CL_TempString16 operator+(const CL_StringRef16 &s1, const CL_StringRef16::CharacterType *s2)
{
	CL_TempString16 result;
	result.reserve(CL_StringRef16::CharacterTraits::length(s2) + s1.length());
	result.append(s1);
	result.append(s2);
	return result;
}

//- !group=Core/Text!
//- !header=core.h!
//- !hide!
inline CL_TempString16 operator+(CL_StringRef16::CharacterType c, const CL_StringRef16 &s2)
{
	CL_TempString16 result;
	result.reserve(1 + s2.length());
	result.push_back(c);
	result.append(s2);
	return result;
}

//- !group=Core/Text!
//- !header=core.h!
//- !hide!
inline CL_TempString16 operator+(const CL_StringRef16 &s1, CL_StringRef16::CharacterType c)
{
	CL_TempString16 result;
	result.reserve(1 + s1.length());
	result.append(s1);
	result.push_back(c);
	return result;
}

#endif
