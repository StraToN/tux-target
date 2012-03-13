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

#ifndef MTPT_GUI_PROGRESS_BAR_H
#define MTPT_GUI_PROGRESS_BAR_H


//
// Includes
//
#include "gui_bin.h"


//
// Classes
//

class CGuiProgressBar : public CGuiBin
{
public:
	CGuiProgressBar();
	virtual ~CGuiProgressBar();

	virtual void _render(const NLMISC::CVector &pos, NLMISC::CVector &maxSize);
	
	virtual float borderWidth() {return 16;};
	virtual float borderHeight() {return 16;};

	float percent();
	void percent(float percent);
	void ptrValue(float *ptrValue);
	
	
	static void XmlRegister();
	static CGuiObject *Create();
	virtual void init(CGuiXml *xml,xmlNodePtr node);
private:
	float _percent;
	float *_ptrValue;
};

class CGuiProgressBarManager : public NLMISC::CSingleton<CGuiProgressBarManager>
{
public:
	virtual void init();
	virtual void update() { }
	virtual void render();
	virtual void release();

	friend class CGuiProgressBar;
protected:
	NL3D::UTextureFile	*_textureProgress;
	NL3D::UMaterial _materialProgress;
	NL3D::UTextureFile	*_textureProgressBar;
	NL3D::UMaterial _materialProgressBar;
	
};


#endif
