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

//! clanCore="I/O Data"
//! header=core.h

#ifndef header_file
#define header_file

#include "../api_core.h"
#include "iodevice.h"

class CL_SecurityDescriptor;

//: File I/O device.
//- !group=Core/IO Data!
//- !header=core.h!
class CL_API_CORE CL_File : public CL_IODevice
{
//! Enumerations:
public:
	//: Access flags.
	//- <p>File access types available.</p>
	enum AccessFlags
	{
		//: Generic read access.
		access_read  = 1,

		//: Generic write access.
		access_write = 2
	};
	
	//: File sharing flags.
	enum ShareFlags
	{
		//: Allow others to open the file for reading.
		share_read   = 1,

		//: Allow others to open the file for writing.
		share_write  = 2,

		//: Allow others to delete the file.
		share_delete = 4,

		//: All other sharing flags combined.
		share_all    = share_read + share_write + share_delete
	};

	//: File opening modes.
	enum OpenMode
	{
		//: Open file or create it if it does not exist.
		open_always,

		//: Open existing file.  Fails if it does not exist.
		open_existing,

		//: Open existing file and truncate it.
		open_existing_truncate,

		//: Create file, even if it already exists.
		create_always,

		//: Create a new file.  Fails if it already exists.
		create_new
	};

	//: Optimization Flags.
	enum Flags
	{
		flag_write_through   = 1,
		flag_no_buffering    = 2,
		flag_random_access   = 4,
		flag_sequential_scan = 8
	};

//! Construction:
public:
	//: Constructs a file object.
	CL_File();
	
	//: Constructs a file object.
	//- CL_PathHelp::normalize(filename, CL_PathHelp::path_type_file) is called
	CL_File(
		const CL_String &filename,
		OpenMode mode = open_existing,
		unsigned int access = access_read | access_write,
		unsigned int share = share_all,
		unsigned int flags = 0);

	//: Constructs a file object.
	//- CL_PathHelp::normalize(filename, CL_PathHelp::path_type_file) is called
	CL_File(
		const CL_String &filename,
		OpenMode mode,
		const CL_SecurityDescriptor &permissions,
		unsigned int access = access_read | access_write,
		unsigned int share = share_all,
		unsigned int flags = 0);

	~CL_File();

//! Attributes:
public:
	//: Returns the file permissions.
	CL_SecurityDescriptor get_permissions() const;

//! Operations:
public:
	//: Opens a file.
	//- CL_PathHelp::normalize(filename, CL_PathHelp::path_type_file) is called
	bool open(
		const CL_String &filename,
		OpenMode mode = open_existing,
		unsigned int access = access_read | access_write,
		unsigned int share = share_all,
		unsigned int flags = 0);

	//: Opens a file.
	//- CL_PathHelp::normalize(filename, CL_PathHelp::path_type_file) is called
	bool open(
		const CL_String &filename,
		OpenMode mode,
		const CL_SecurityDescriptor &permissions,
		unsigned int access = access_read | access_write,
		unsigned int share = share_all,
		unsigned int flags = 0);

	//: Close file.
	void close();

	//: Change file permissions.
	bool set_permissions(const CL_SecurityDescriptor &permissions);
	
//! Implementation:
private:
};

#endif
