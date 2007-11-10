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

//! clanCore="Resources"
//! header=core.h

#ifndef header_resource_manager
#define header_resource_manager

#include "../api_core.h"
#include "../Resources/resource.h"
#include "../System/weakptr.h"
#include "../IOData/virtual_directory.h"
#include <vector>

class CL_IODevice;
class CL_Resource;
class CL_VirtualDirectory;
class CL_ResourceManager_Impl;

//: Resource Manager.
//- !group=Core/Resources!
//- !header=core.h!
class CL_API_CORE CL_ResourceManager
{
//! Construction:
public:
	//: Construct a resource manager.
	CL_ResourceManager();

	CL_ResourceManager(const CL_String &filename);

	CL_ResourceManager(const CL_String &filename, CL_VirtualDirectory directory);

	CL_ResourceManager(CL_IODevice file, CL_VirtualDirectory directory = CL_VirtualDirectory());

	CL_ResourceManager(const CL_ResourceManager &other);

	~CL_ResourceManager();

//! Attributes:
public:
	//: Returns true if a resource exists.
	bool resource_exists(const CL_String &resource_id) const;

	//: Returns all the resource sections available.
	std::vector<CL_String> get_section_names() const;

	//: Returns a list of all resources available.
	//- <p>The returned resources are in the form "section/subsection/.../resourcename".</p>
	std::vector<CL_String> get_resource_names() const;

	std::vector<CL_String> get_resource_names(const CL_String &section) const;

	//:  Returns a list of all resources available matching a given type.
	//- <p>The returned resources are in the form "section/subsection/.../resourcename".</p>
	std::vector<CL_String> get_resource_names_of_type(const CL_String &type) const;

	std::vector<CL_String> get_resource_names_of_type(
		const CL_String &type,
		const CL_String &section) const;

	//: Returns CL_Resource representing the given resource.
	CL_Resource get_resource(
		const CL_String &resource_id,
		bool resolve_alias = true,
		int reserved = 0);

	//: Returns the directory to load resource data from.
	CL_VirtualDirectory get_directory(const CL_Resource &resource) const;

	//: Returns the value of a boolean resource.
	bool get_boolean_resource(
		const CL_String &resource_id,
		bool default_value);

	//: Returns the value of an integer resource.
	int get_integer_resource(
		const CL_String &resource_id,
		int default_value);

//! Operations:
public:
	CL_ResourceManager &operator =(const CL_ResourceManager &copy);

	bool operator ==(const CL_ResourceManager &manager) const;

	//: Set the resource data directory.
	void set_directory(const CL_VirtualDirectory &directory);

	//: Add resources from an other resource manager.
	//- <p>This function only makes the resource manager search other managers, it
	//- does not copy the resources into this manager.</p>
	void add_resources(const CL_ResourceManager& additional_resources);

	//: Remove resources from an other resource manager.
	void remove_resources(const CL_ResourceManager& additional_resources);

	//: Construct a new resource object.
	CL_Resource create_resource(const CL_String &resource_id, const CL_String &type);

	//: Destroy resource object.
	void destroy_resource(const CL_String &resource_id);

	//: Save resource XML tree to file.
	void save(const CL_String &filename);

	void save(const CL_String &filename, CL_VirtualDirectory directory = CL_VirtualDirectory());

	void save(CL_IODevice file);

	//: Load resource XML tree from file.
	void load(const CL_String &filename);

	void load(const CL_String &filename, CL_VirtualDirectory directory);

	void load(CL_IODevice file, CL_VirtualDirectory directory = CL_VirtualDirectory());

//! Implementation:
private:
	CL_ResourceManager(CL_WeakPtr<CL_ResourceManager_Impl> &impl);

	CL_SharedPtr<CL_ResourceManager_Impl> impl;

	friend class CL_Resource;
};

#endif
