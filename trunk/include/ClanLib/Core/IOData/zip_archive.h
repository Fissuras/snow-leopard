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
**    Harry Storbacka
*/

//! clanCore="I/O Data"
//! header=core.h

#ifndef header_zip_archive
#define header_zip_archive

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"
#include "../System/sharedptr.h"
#include "zip_file_entry.h"
#include <vector>

class CL_IODevice;
class CL_Zip_Archive_Impl;

//: Zip archive.
//- !group=Core/IO Data!
//- !header=core.h!
class CL_API_CORE CL_Zip_Archive
{
//! Construction:
public:
	//: Constructs or loads a ZIP archive.
	//param filename: .zip archive to load.
	CL_Zip_Archive();

	CL_Zip_Archive(CL_IODevice &input);

	CL_Zip_Archive(const CL_StringRef &filename);
	
	CL_Zip_Archive(const CL_Zip_Archive &copy);
	
	~CL_Zip_Archive();

//! Attributes:
public:
	//: List of file entries in archive.
	std::vector<CL_Zip_FileEntry> get_file_list();

//! Operations:
public:
	//: Opens a file in the archive.
	CL_IODevice open_file(const CL_StringRef &filename);
	
	//: Get full path to source:
	CL_String get_pathname(const CL_StringRef &filename);

	//: Creates a new file entry
	CL_IODevice create_file(const CL_StringRef &filename, bool compress = true);

	//: Adds a file to zip archive.
	//- <p>File is not added to zip file until it save() is called.</p>
	//param filename: Filename of file.
	void add_file(const CL_StringRef &filename, bool compress = true);

	//: Saves zip archive.
	//param filename: Filename of zip archive. Must not be used to save to the same as loaded from.
	//- <p>If no filename parameter was passed, it will modify the zip
	//- archive loaded at construction time. It does this by creating a
	//- temporary file, saving the new archive, deletes the old one and
	//- renames the temp file to the original archive filename.</p>
	//-
	//- <p>If the archive was created instead of loaded, a filename must
	//- be specify a filename. Likewise, if saving to same archive as
	//- loaded from, a filename must not be specified. Doing so will
	//- cause the save operation to fail.</p>
	void save();

	void save(const CL_StringRef &filename);

	void save(CL_IODevice iodev);

	//: Loads the zip archive from a input device (done automatically at construction).
	void load(CL_IODevice &input);

//! Implementation:
private:
	CL_SharedPtr<CL_Zip_Archive_Impl> impl;
};

#endif
