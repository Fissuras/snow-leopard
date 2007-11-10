/*
**  ClanLib SDK
**  Copyright (c) 1997-2007 The ClanLib Team
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
**    Harry Storbacka
*/

//! clanCore="Text"
//! header=core.h

#ifndef header_basic_string
#define header_basic_string

#include "../api_core.h"
#include "../System/memory_pool.h"
#include <cstring>
#include <wchar.h>

class CL_MemoryPool;
class CL_CharacterSet;

//: Holds size_type and npos for CL_BasicString template.
//- !group=Core/Text!
//- !header=core.h!
//- !hide!
//- <p>This class is needed to workaround various static variable template
//- issues with some compilers.</p>
class CL_API_CORE CL_BasicStringTypes
{
//! Attributes:
public:
	typedef unsigned int size_type;

	static const size_type npos;
};

//: Generic string reference template class.
//- !group=Core/Text!
//- !header=core.h!
template<typename CharType, typename CharTraits, typename std_string>
class CL_BasicStringRef : public CL_BasicStringTypes
{
public:
	typedef CharTraits CharacterTraits;
	typedef CharType CharacterType;
	typedef CharType *iterator;
	typedef const CharType *const_iterator;
	
	CL_BasicStringRef()
	: charset(0), _data(0), _length(0), _null_terminated(false), _temporary(false)
	{
	}

	CL_BasicStringRef(const CL_BasicStringRef &source)
	: charset(0), _data(source._data), _length(source._length), _null_terminated(source._null_terminated), _temporary(false)
	{
	}

	CL_BasicStringRef(const CharType *str, CL_CharacterSet *char_set = 0)
	: charset(char_set), _data((CharType *) str), _length(CharacterTraits::length(str)), _null_terminated(true), _temporary(false)
	{
	}

	CL_BasicStringRef(const CharType *str, size_type length, bool null_terminated, CL_CharacterSet *char_set = 0)
	: charset(char_set), _data((CharType *) str), _length(length), _null_terminated(null_terminated), _temporary(false)
	{
	}

	~CL_BasicStringRef()
	{
		if (_temporary)
			CL_MemoryPool::get_temp_pool()->free(_data);
	}

	CL_BasicStringRef &operator =(const CL_BasicStringRef &source)
	{
		if (_temporary)
			CL_MemoryPool::get_temp_pool()->free(_data);
		_temporary = false;
		charset = source.charset;
		_data = source._data;
		_length = source._length;
		_null_terminated = source._null_terminated;
		return *this;
	}

	CL_BasicStringRef &operator =(const CharType *str)
	{
		if (_temporary)
			CL_MemoryPool::get_temp_pool()->free(_data);
		_temporary = false;
		_data = str;
		_length = CharacterTraits::length(str);
		_null_terminated = true;
		return *this;
	}

	const CharType *data() const
	{
		return _data;
	}

	const CharType *c_str() const
	{
		if (!_null_terminated)
		{
			CharacterType *temp_str = (CharacterType *) CL_MemoryPool::get_temp_pool()->alloc(sizeof(CharacterType) * (_length + 1));
			memcpy(temp_str, _data, sizeof(CharacterType) * _length);
			temp_str[_length] = 0;
			if (_temporary)
				CL_MemoryPool::get_temp_pool()->free(_data);
			_data = temp_str;
			_null_terminated = true;
			_temporary = true;
		}
		return _data;
	}

	operator std_string() const
	{
		return std_string(_data, _length);
	}

	iterator begin() { return (iterator) _data; }
	iterator end() { return begin() + _length; }
	const_iterator begin() const { return (const_iterator) _data; }
	const_iterator end() const { return begin() + _length; }

//	reverse_iterator rbegin();
//	reverse_iterator rend();
//	const_reverse_iterator rbegin() const;
//	const_reverse_iterator rend() const;

	const CharType &operator[](size_type n) const { return *(_data + n); }
	size_type size() const { return _length; }
	size_type length() const { return _length; }
	bool empty() const { return _length == 0; }
	
	size_type find(const CL_BasicStringRef &s, size_type pos = 0) const
	{
		return find(s.data(), pos, s.length());
	}
	
	size_type find(const CharType *s, size_type pos, size_type n) const
	{
		size_type len = _length;
		if (pos == npos || pos == len || n == 0)
			return npos;
		const CharType *d = _data;
		size_type cur_char = 0;
		size_type cur_start = 0;
		for (size_type i = pos; i < len; i++)
		{
			if (cur_char == 0)
			{
				if (d[i] == s[cur_char])
				{
					cur_start = i;
					cur_char++;
					if (cur_char == n)
						return cur_start;
				}
			}
			else
			{
				if (d[i] != s[cur_char])
				{
					cur_char = 0;
					i = cur_start;
				}
				else
				{
					cur_char++;
					if (cur_char == n)
						return cur_start;
				}
			}
		}
		return npos;
	}

	size_type find(const CharType *s, size_type pos = 0) const
	{
		size_type len = 0;
		while (s[len] != 0)
			len++;
		return find(s, pos, len);
	}

	size_type find(CharType c, size_type pos = 0) const
	{
		size_type len = _length;
		if (pos == npos || pos == len)
			return npos;
		const CharType *d = (const CharType *) _data;
		for (size_type i = pos; i < len; i++)
			if (d[i] == c)
				return i;
		return npos;
	}

	size_type rfind(const CL_BasicStringRef &s, size_type pos = npos) const
	{
		return rfind(s.data(), pos, s.length());
	}
	
	size_type rfind(const CharType *s, size_type pos, size_type n) const
	{
		size_type len = _length;
		if (pos == npos)
			pos = len;
		if (len == 0 || n == 0)
			return npos;
		const CharType *d = _data;
		size_type cur_char = n;
		size_type cur_start = 0;
		while (true)
		{
			if (cur_char == n)
			{
				if (d[pos] == s[cur_char-1])
				{
					cur_start = pos;
					cur_char--;
					if (cur_char == 0)
						return pos;
				}
			}
			else
			{
				if (d[pos] != s[cur_char-1])
				{
					cur_char = n;
					pos = cur_start;
				}
				else
				{
					cur_char--;
					if (cur_char == 0)
						return pos;
				}
			}
			if (pos == 0)
				break;
			pos--;
		}
		return npos;
	}

	size_type rfind(const CharType *s, size_type pos = npos) const
	{
		size_type len = 0;
		while (s[len] != 0)
			len++;
		return rfind(s, pos, len);
	}

	size_type rfind(CharType c, size_type pos = npos) const
	{
		size_type len = _length;
		if (pos == npos)
			pos = len;
		if (len == 0)
			return npos;
		if (pos >= len)
			pos = len - 1;
		const CharType *d = _data;
		while (true)
		{
			if (d[pos] == c)
				return pos;
			if (pos == 0)
				break;
			pos--;
		}
		return npos;
	}

	size_type find_first_of(const CL_BasicStringRef &s, size_type pos = 0) const
	{
		return find_first_of(s.data(), pos, s.length());
	}
	
	size_type find_first_of(const CharType *s, size_type pos, size_type n) const
	{
		size_type len = _length;
		if (pos == npos || pos == len)
			return npos;
		const CharType *d = _data;
		for (size_type i = pos; i < len; i++)
		{
			for (size_type j = 0; j < n; j++)
				if (d[i] == s[j])
					return i;
		}
		return npos;
	}

	size_type find_first_of(const CharType *s, size_type pos = 0) const
	{
		size_type len = 0;
		while (s[len] != 0)
			len++;
		return find_first_of(s, pos, len);
	}

	size_type find_first_of(CharType c, size_type pos = 0) const
	{
		size_type len = _length;
		if (pos == npos || pos == len)
			return npos;
		const CharType *d = (const CharType *) _data;
		for (size_type i = pos; i < len; i++)
			if (d[i] == c)
				return i;
		return npos;
	}

	size_type find_first_not_of(const CL_BasicStringRef &s, size_type pos = 0) const
	{
		return find_first_not_of(s.data(), pos, s.length());
	}
	
	size_type find_first_not_of(const CharType *s, size_type pos, size_type n) const
	{
		size_type len = _length;
		if (pos == npos || pos == len)
			return npos;
		const CharType *d = _data;
		for (size_type i = pos; i < len; i++)
		{
			bool found = false;
			for (size_type j = 0; j < n; j++)
				if (d[i] == s[j])
					found = true;
			if (!found)
				return i;
		}
		return npos;
	}

	size_type find_first_not_of(const CharType *s, size_type pos = 0) const
	{
		size_type len = 0;
		while (s[len] != 0)
			len++;
		return find_first_not_of(s, pos, len);
	}

	size_type find_first_not_of(CharType c, size_type pos = 0) const
	{
		size_type len = _length;
		if (pos == npos || pos == len)
			return npos;
		const CharType *d = _data;
		for (size_type i = pos; i < len; i++)
			if (d[i] != c)
				return i;
		return npos;
	}

	size_type find_last_of(const CL_BasicStringRef &s, size_type pos = npos) const
	{
		return find_last_of(s.data(), pos, s.length());
	}
	
	size_type find_last_of(const CharType *s, size_type pos, size_type n) const
	{
		size_type len = _length;
		if (pos > len)
			pos = len;
		const CharType *d = _data;
		for (size_type i = pos; i != 0; i--)
		{
			for (size_type j = 0; j < n; j++)
				if (d[i-1] == s[j])
					return i-1;
		}

		return npos;
	}

	size_type find_last_of(const CharType *s, size_type pos = npos) const
	{
		size_type len = 0;
		while (s[len] != 0)
			len++;
		return find_last_of(s, pos, len);
	}

	size_type find_last_of(CharType c, size_type pos = npos) const
	{
		size_type len = _length;
		if (pos > len)
			pos = len;
		const CharType *d = _data;
		for (size_type i = pos; i != 0; i--)
			if (d[i-1] == c)
				return i-1;
		return npos;
	}

	size_type find_last_not_of(const CL_BasicStringRef &s, size_type pos = npos) const
	{
		return find_last_not_of(s.data(), pos, s.length());
	}
	
	size_type find_last_not_of(const CharType *s, size_type pos, size_type n) const
	{
		size_type len = _length;
		if (pos > len)
			pos = len;
		const CharType *d = _data;
		for (size_type i = pos; i != 0; i--)
		{
			bool found = false;
			for (size_type j = 0; j < n; j++)
				if (d[i-1] == s[j])
					found = true;
			if (!found)
				return i-1;
		}
		return npos;
	}

	size_type find_last_not_of(const CharType *s, size_type pos = npos) const
	{
		size_type len = 0;
		while (s[len] != 0)
			len++;
		return find_last_not_of(s, pos, len);
	}

	size_type find_last_not_of(CharType c, size_type pos = npos) const
	{
		size_type len = _length;
		if (pos > len)
			pos = len;
		const CharType *d = _data;
		for (size_type i = pos; i != 0; i--)
		{
			bool found = false;
			if (d[i-1] != c)
				return i-1;
		}
		return npos;
	}
	
	CL_BasicStringRef substr(size_type pos = 0, size_type n = npos) const
	{
		const CharType *d = _data;
		if (pos == npos || pos > _length)
			return CL_BasicStringRef(d + _length, 0, false, charset);
		if (n == npos || pos + n > _length)
			n = _length - pos;
		return CL_BasicStringRef(d + pos, n, false, charset);
	}

	int compare(const CL_BasicStringRef &s) const
	{
		const CharType *d1 = _data;
		const CharType *d2 = s._data;
		size_type l1 = _length;
		size_type l2 = s._length;
		size_type l = (l1 < l2) ? l1 : l2;
		for (size_type i = 0; i < l; i++)
			if (d1[i] != d2[i])
				return (int) (((unsigned int) d1[i]) - ((unsigned int) d2[i]));
		return l1-l2;
	}

	int compare(size_type pos, size_type n, const CL_BasicStringRef &s) const
	{
		const CharType *d1 = _data;
		const CharType *d2 = s._data;
		size_type l1 = _length;
		size_type l2 = s._length;

		if (pos > l1)
			pos = l1;
		d1 += pos;
		l1 -= pos;
		if (n < l1)
			l1 = n;

		size_type l = (l1 < l2) ? l1 : l2;
		for (size_type i = 0; i < l; i++)
			if (d1[i] != d2[i])
				return (int) (((unsigned int) d1[i]) - ((unsigned int) d2[i]));
		return l1-l2;
	}

	int compare(size_type pos, size_type n, const CL_BasicStringRef &s, size_type pos1, size_type n1) const
	{
		const CharType *d1 = _data;
		const CharType *d2 = s._data;
		size_type l1 = _length;
		size_type l2 = s._length;

		if (pos > l1)
			pos = l1;
		d1 += pos;
		l1 -= pos;
		if (n < l1)
			l1 = n;

		if (pos1 > l2)
			pos1 = l2;
		d2 += pos1;
		l2 -= pos1;
		if (n1 < l2)
			l2 = n1;

		size_type l = (l1 < l2) ? l1 : l2;
		for (size_type i = 0; i < l; i++)
			if (d1[i] != d2[i])
				return (int) (((unsigned int) d1[i]) - ((unsigned int) d2[i]));
		return l1-l2;
	}

	int compare(const CharType *s) const
	{
		const CharType *d1 = _data;
		const CharType *d2 = s;
		size_type l1 = _length;
		size_type l2 = 0;
		while (s[l2] != 0) { l2++; }

		size_type l = (l1 < l2) ? l1 : l2;
		for (size_type i = 0; i < l; i++)
			if (d1[i] != d2[i])
				return (int) (((unsigned int) d1[i]) - ((unsigned int) d2[i]));
		return l1-l2;
	}

	int compare(size_type pos, size_type n, const CharType *s, size_type len = npos) const
	{
		const CharType *d1 = _data;
		const CharType *d2 = s;
		size_type l1 = _length;
		size_type l2 = 0;
		while (s[l2] != 0) { l2++; }
		if (len != npos && l2 > len)
			l2 = len;

		if (pos > l1)
			pos = l1;
		d1 += pos;
		l1 -= pos;
		if (n != npos && n < l1)
			l1 = n;

		size_type l = (l1 < l2) ? l1 : l2;
		for (size_type i = 0; i < l; i++)
			if (d1[i] != d2[i])
				return (int) (((unsigned int) d1[i]) - ((unsigned int) d2[i]));
		return l1-l2;
	}

	CharacterType *data() { return _data; }
	CharacterType &operator[](size_type n) { return *(_data + n); }

	void resize(size_type n)
	{
		if (n >= _length)
			return;
		_length = n;
		_null_terminated = false;
	}

	CL_CharacterSet *charset;
	
protected:
	mutable CharacterType *_data;
	mutable size_type _length;
	mutable bool _null_terminated;
	mutable bool _temporary;
};

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator==(const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s1, const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s2)
{
	return s1.compare(s2) == 0;
}

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator==(const CharType *s1, const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s2)
{
	return s2.compare(s1) == 0;
}

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator==(const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s1, const CharType *s2)
{
	return s1.compare(s2) == 0;
}

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator!=(const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s1, const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s2)
{
	return s1.compare(s2) != 0;
}

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator!=(const CharType *s1, const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s2)
{
	return s2.compare(s1) != 0;
}

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator!=(const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s1, const CharType *s2)
{
	return s1.compare(s2) != 0;
}

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator<(const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s1, const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s2)
{
	return s1.compare(s2) < 0;
}

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator<(const CharType *s1, const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s2)
{
	return s2.compare(s1) > 0;
}

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator<(const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s1, const CharType *s2)
{
	return s1.compare(s2) < 0;
}

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator>(const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s1, const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s2)
{
	return s1.compare(s2) > 0;
}

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator>(const CharType *s1, const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s2)
{
	return s2.compare(s1) < 0;
}

template <typename CharType, typename CharacterTraits, typename std_string>
bool operator>(const CL_BasicStringRef<CharType, CharacterTraits, std_string> &s1, const CharType *s2)
{
	return s1.compare(s2) > 0;
}

#endif
