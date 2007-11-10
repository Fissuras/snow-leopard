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

#ifndef header_datetime
#define header_datetime

#include "../api_core.h"
#include <time.h>
#include "mutex.h"

//: Date/Time class.
//- !group=Core/System!
//- !header=core.h!
class CL_API_CORE CL_DateTime
{
//! Construction:
public:
	//: Constructs a date/time object.
	CL_DateTime();

	CL_DateTime(time_t unix_time);
	
	CL_DateTime(const CL_DateTime &other);

	~CL_DateTime();

	//: Get current system time.
	static CL_DateTime get_system_time();

//! Attributes:
public:
	//: Seconds since 00:00:00 on January 1, 1970 in Coordinated Universal Time (UTC)
	time_t get_unix_time() const;

	//: Seconds in local time zone
	int get_seconds_local() const;
	
	//: Seconds in UTC
	int get_seconds_utc() const;
	
	//: Minutes in local time zone
	int get_minutes_local() const;
	
	//: Minutes in UTC
	int get_minutes_utc() const;
	
	//: Hours in local time zone
	int get_hours_local() const;
	
	//: Hours in UTC
	int get_hours_utc() const;
	
	//: Day of the month in local time zone
	int get_month_day_local() const;

	//: Day of the month in UTC
	int get_month_day_utc() const;

	//: Month in local time zone
	int get_month_local() const;
	
	//: Month in UTC
	int get_month_utc() const;
	
	//: Year in local time zone
	int get_year_local() const;
	
	//: Year in UTC
	int get_year_utc() const;
	
	//: Day of the week
	int get_week_day_local() const;

	//: Day of the week
	int get_week_day_utc() const;

	//: Day in the year in local time zone
	int get_year_day_local() const;
	
	//: Day in the year in UTC
	int get_year_day_utc() const;
	
	//: Daylight saving time
	//- <p>The value is positive if daylight saving time is in effect,
	//- zero if it is not, and negative if the information is not
	//- available.</p>
	int get_daylight_saving_time_local() const;

	//: Local time zone abbreviation
	CL_String get_zone_abbreviation() const;

//! Operations:
public:
	//: Seconds since 00:00:00 on January 1, 1970 in Coordinated Universal Time (UTC)
	void set_unix_time(time_t t);

	//: Seconds in local time zone
	void set_seconds_local(int seconds);
	
	//: Minutes in local time zone
	void set_minutes_local(int minutes);
	
	//: Hours in local time zone
	void set_hours_local(int hours);
	
	//: Day of the month in local time zone
	void set_month_day_local(int day);

	//: Month in local time zone
	void set_month_local(int month);
	
	//: Year in local time zone
	void set_year_local(int year);

	//: Save broken-down time to unix time.
	void save_local();

	CL_DateTime &operator =(const CL_DateTime &other);

	bool operator <(const CL_DateTime &other) const;

	bool operator <=(const CL_DateTime &other) const;
	
	bool operator >(const CL_DateTime &other) const;

	bool operator >=(const CL_DateTime &other) const;
	
	bool operator ==(const CL_DateTime &other) const;

	bool operator !=(const CL_DateTime &other) const;
	
//! Implementation:
private:
	void load_local() const;
	
	void load_utc() const;
	
	time_t unix_time;

	mutable struct tm *tm_local;
	
	mutable struct tm *tm_utc;

#ifdef WIN32
#ifndef _CRT_INSECURE_DEPRECATE
	static CL_Mutex mutex;
#endif
#endif
};

#endif
