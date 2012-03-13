/* Copyright, 2010 Tux Target
 * Copyright, 2003 Melting Pot
 *
 * This file is part of Tux Target.
 * Tux Target is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.

 * Tux Target is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Tux Target; see the file COPYING. If not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
 * MA 02111-1307, USA.
 */


//
// This is the main class that manages all other classes
//

#ifndef MTPT_GUI_LISTVIEW_H
#define MTPT_GUI_LISTVIEW_H


//
// Includes
//
#include <nel/3d/u_material.h>

#include "gui_stretched_quad.h"
#include "gui_container.h"
#include "gui_box.h"



//
// Classes
//

class CGuiListViewEventBehaviour : public CGuiEventBehaviour
{
public:
	CGuiListViewEventBehaviour();
	virtual ~CGuiListViewEventBehaviour();
	
	virtual void onPressed(int rowId);
};


class CGuiListView : public CGuiContainer
{
public:
	
	CGuiListView(lua_State *luaSession) {};
	CGuiListView();
	virtual ~CGuiListView();

	virtual CGuiObject::TGuiAlignment alignment();
	virtual void alignment(int alignment);
	
	float spacing();
	void spacing(float spacing);

	int selectedRow() {return _selectedRow-1;};
	
	virtual void _render(const NLMISC::CVector &pos, NLMISC::CVector &maxSize);	
	
	virtual float _width();
	virtual float _height();
	
	static void XmlRegister();
	static CGuiObject *Create();
	virtual void init(CGuiXml *xml,xmlNodePtr node);
	

	std::list<guiSPG<CGuiHBox> > rows;		
	guiSPG<CGuiListViewEventBehaviour> eventBehaviour;

	
	virtual void luaPush(lua_State *L);
	static const char className[];	
	static Lunar<CGuiListView>::RegType methods[];	
	int getElement(lua_State *luaSession);
	int getCount(lua_State *luaSession);
	int removeElement(lua_State *luaSession);
	int getName(lua_State *luaSession);
	int getSelected(lua_State *luaSession);
	int pushBack(lua_State *luaSession);
private:	
	float _spacing;
	CGuiStretchedQuad quad;
	uint _selectedRow;
};

class CGuiListViewManager : public NLMISC::CSingleton<CGuiListViewManager>
{
public:
	virtual void init();
	virtual void update() { }
	virtual void render();
	virtual void release();
	
	NL3D::UTextureFile	*headerTexture();
	NL3D::UMaterial headerMaterial();
	NL3D::UTextureFile	*rowTexture();
	NL3D::UMaterial rowMaterial();
	NL3D::UTextureFile	*selectedRowTexture();
	NL3D::UMaterial selectedRowMaterial();
	
private:
	NL3D::UTextureFile	*_headerTexture;
	NL3D::UMaterial _headerMaterial;
	NL3D::UTextureFile	*_rowTexture;
	NL3D::UMaterial _rowMaterial;
	NL3D::UTextureFile	*_selectedRowTexture;
	NL3D::UMaterial _selectedRowMaterial;
};

#endif
