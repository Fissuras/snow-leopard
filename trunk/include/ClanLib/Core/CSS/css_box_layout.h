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

//! clanCore="CSS"
//! header=core.h

#ifndef header_css_box_layout
#define header_css_box_layout

#if _MSC_VER > 1000
#pragma once
#endif

#include "../api_core.h"
#include "../System/sharedptr.h"

class CL_CSSBox;
class CL_CSSInlineTextBox;
class CL_CSSInlineObjectBox;
class CL_DomElement;
class CL_CSSBoxLayout_Impl;

//- !hide!
class CL_API_CORE CL_CSSBoxLayout
{
//! Construction:
public:
	//: CSS Box Layout constructor
	CL_CSSBoxLayout();

	CL_CSSBoxLayout(CL_SharedPtr<CL_CSSBoxLayout_Impl> impl);

	//: CSS Box Layout destructor
	~CL_CSSBoxLayout();

//! Attributes:
public:
	CL_CSSBox get_body_box();

//! Operations:
public:
	CL_CSSBox create_inline_box();

	CL_CSSInlineTextBox create_inline_text_box(const CL_StringRef &text);

	CL_CSSInlineObjectBox create_inline_object_box(const CL_DomElement &element);

	CL_CSSBox create_block_box();

	CL_CSSBox create_list_item_box();

	CL_CSSBox create_run_in_box();

	CL_CSSBox create_compact_box();

	CL_CSSBox create_marker_box();

	CL_CSSBox create_table_box();

	CL_CSSBox create_inline_table_box();

	CL_CSSBox create_table_row_group_box();

	CL_CSSBox create_table_header_group_box();

	CL_CSSBox create_table_footer_group_box();

	CL_CSSBox create_table_row_box();

	CL_CSSBox create_table_column_group_box();

	CL_CSSBox create_table_column_box();

	CL_CSSBox create_table_cell_box();

	CL_CSSBox create_table_caption_box();

//! Implementation:
private:
	CL_SharedPtr<CL_CSSBoxLayout_Impl> impl;
};

class CL_CSSBox_Impl;

//- !hide!
class CL_API_CORE CL_CSSBox
{
//! Construction:
public:
	CL_CSSBox();

	CL_CSSBox(CL_SharedPtr<CL_CSSBox_Impl> impl);

	~CL_CSSBox();

//! Attributes:
public:
	CL_CSSBoxLayout get_box_layout();

	enum Type
	{
		NULL_BOX,
		INLINE_BOX,
		INLINE_TEXT_BOX,
		INLINE_OBJECT_BOX,
		BLOCK_BOX,
		LIST_ITEM_BOX,
		RUN_IN_BOX,
		COMPACT_BOX,
		MARKER_BOX,
		TABLE_BOX,
		INLINE_TABLE_BOX,
		TABLE_ROW_GROUP_BOX,
		TABLE_HEADER_GROUP_BOX,
		TABLE_FOOTER_GROUP_BOX,
		TABLE_ROW_BOX,
		TABLE_COLUMN_GROUP_BOX,
		TABLE_COLUMN_BOX,
		TABLE_CELL_BOX,
		TABLE_CAPTION_BOX
	};

	Type get_type() const;

	//: Returns the parent of this box.
	//- <p>If there is no such box, this returns a null box.</p>
	CL_CSSBox get_parent_box() const;

	//: The first child of this box.
	//- <p>If there is no such box, this returns a null box.</p>
	CL_CSSBox get_first_child() const;
	
	//: The last child of this box.
	//- <p>If there is no such box, this returns a null box.</p>
	CL_CSSBox get_last_child() const;
	
	//: The box immediately preceding this box.
	//- <p>If there is no such box, this returns a null box.</p>
	CL_CSSBox get_previous_sibling() const;
	
	//: The box immediately following this box.
	//- <p>If there is no such box, this returns a null box.</p>
	CL_CSSBox get_next_sibling() const;

	//: Returns true if this is a null box.
	bool is_null() const;

	//: Returns true if this is an anonymous (generated) box.
	bool is_anonymous() const;

	//: Returns true if this is an inline box.
	bool is_inline_box() const;

	//: Returns true if this is an inline text box.
	bool is_inline_text_box() const;

	//: Returns true if this is an inline object box.
	bool is_inline_object_box() const;

	//: Returns true if this is a block box.
	bool is_block_box() const;

	//: Returns true if this is a list item box.
	bool is_list_item_box() const;

	//: Returns true if this is a run-in box.
	bool is_run_in_box() const;

	//: Returns true if this is a compact box.
	bool is_compact_box() const;

	//: Returns true if this is a marker box.
	bool is_marker_box() const;

	//: Returns true if this is a table box.
	bool is_table_box() const;

	//: Returns true if this is an inline-table box.
	bool is_inline_table_box() const;

	//: Returns true if this is a table row group box.
	bool is_table_row_group_box() const;

	//: Returns true if this is a table header group box.
	bool is_table_header_group_box() const;

	//: Returns true if this is a table footer group box.
	bool is_table_footer_group_box() const;

	//: Returns true if this is a table row box.
	bool is_table_row_box() const;

	//: Returns true if this is a table column group box.
	bool is_table_column_group_box() const;

	//: Returns true if this is a table column box.
	bool is_table_column_box() const;

	//: Returns true if this is a table cell box.
	bool is_table_cell_box() const;

	//: Returns true if this is a table caption box.
	bool is_table_caption_box() const;

//! Operations:
public:
	CL_CSSInlineTextBox to_inline_text_box() const;

	CL_CSSInlineObjectBox to_inline_object_box() const;

	//: Adds the box new_box to the end of the list of children of this box.
	//- <p>If any anonymous boxes are required to make the layout valid, they
	//- are automatically generated when the child is appended.  For example,
	//- if a table cell box is appended to a table box, a table row box is
	//- automatically generated and inserted in between the table and the
	//- cell.</p>
	//- <p>If new_box is already in the tree, it is first removed.</p>
	CL_CSSBox append_child(CL_CSSBox new_child);

	//: Removes the box from the list of children of this box.
	CL_CSSBox remove_child(CL_CSSBox child);

//! Implementation:
protected:
	CL_SharedPtr<CL_CSSBox_Impl> impl;
};

//- !hide!
class CL_API_CORE CL_CSSInlineTextBox : CL_CSSBox
{
//! Construction:
public:
	CL_CSSInlineTextBox();

	CL_CSSInlineTextBox(CL_SharedPtr<CL_CSSBox_Impl> impl);

	~CL_CSSInlineTextBox();

//! Attributes:
public:
	CL_StringRef get_text() const;
};

//- !hide!
class CL_API_CORE CL_CSSInlineObjectBox : CL_CSSBox
{
//! Construction:
public:
	CL_CSSInlineObjectBox();

	CL_CSSInlineObjectBox(CL_SharedPtr<CL_CSSBox_Impl> impl);

	~CL_CSSInlineObjectBox();

//! Attributes:
public:
	CL_DomElement get_object_element() const;
};

#endif
