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
**    (if your name is missing here, please add it)
*/

//! clanCore="I/O Data"
//! header=core.h

#ifndef header_directory
#define header_directory

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"

//: Directory utility class
//- !group=Core/IO Data!
//- !header=core.h!
class CL_API_CORE CL_Directory
{
//! Operations:
public:
	//: Create directory.
	//- <p>return true on success or false on error.</p>
	//param dir_name: Directory name for create.
	static bool create(const CL_String &dir_name);

	//: Remove directory.
	//- <p>Return true on success or false on error.</p>
	//param dir_name: Directory name for delete.
	//param delete_files: If true, function will delete files.
	//param delete_sub_directoies: If true, function will delete
	//param delete_sub_directoies: sub directoies too.
	static bool remove(
		const CL_String &dir_name,
		bool delete_files = false,
		bool delete_sub_directories = false);

	//: Change current directory.
	//- <p>Return true on success or false on error.</p>
	//param path: Directory name to change to.
	static bool set_current(const CL_String &path);

	//: Get current directory.
	//- <p>Returns the current directory path.</p>
	static CL_String get_current();

	//: Returns the current user's roaming application data directory.
	//- <p>In Windows, this functions returns special folder directory CSIDL_APPDATA
	//- appended with the application_name string. A typical path would be
	//- "C:\Documents and Settings\username\Application Data\company_name\application_name\version\".</p>
	//- <p>In OS X, this function returns the directory "~/Library/application_name/".</p>
	//- <p>In Linux, this function returns the directory "~/.appdata/application_name/".</p>
	static CL_String get_appdata(const CL_StringRef &company_name, const CL_StringRef &application_name, const CL_StringRef &version, bool create_dirs_if_missing = true);

	//: Returns the current user's local (nonroaming) application data directory.
	//- <p>In Windows, this functions returns special folder directory CSIDL_LOCAL_APPDATA
	//- appended with the application_name string. A typical path would be
	//- "C:\Documents and Settings\username\Local Settings\Application Data\company_name\application_name\version\".</p>
	//- <p>In OS X, this function returns the directory "~/Library/application_name/".</p>
	//- <p>In Linux, this function returns the directory "~/.local_appdata/application_name/".</p>
	static CL_String get_local_appdata(const CL_StringRef &company_name, const CL_StringRef &application_name, const CL_StringRef &version, bool create_dirs_if_missing = true);

	//: Returns the application resource data directory.
	//- <p>In Windows, this function returns a "Resources" subdirectory located at the
	//- executable.  If the executable path is "C:\Program Files\My Application\MyApp.exe",
	//- then it will return the path "C:\Progam Files\My Application\Resources\".</p>
	//- <p>In OS X, this function returns the Resources inside the application bundle.
	//- For example, if the application executable path is
	//- "/Applications/MyApplication.app/Contents/MacOS/MyApplication", then it will return
	//- "/Applications/MyApplication.app/Contents/Resources/".  If the executable is not in
	//- an application bundle, it will use the same behavior as in Windows; that is, it will
	//- return a "Resources" subdirectory next to the executable.</p>
	//- <p>In Linux, this function will return the directory "../share/application_name/"
	//- relative to the executable, so if it is located in "/usr/bin" it will return
	//- "/usr/share/application_name/".
	static CL_String get_resourcedata(const CL_StringRef &application_name);
};

#endif
