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

#ifndef MTPT_EDITOR_TASK_H
#define MTPT_EDITOR_TASK_H

#include "gui.h"
#include "module.h"

//
// Includes
//


//
// Classes
//

class CEditorTask : public NLMISC::CSingleton<CEditorTask>, public ITask
{
public:

	virtual void init();
	virtual void update();
	virtual void render();
	virtual void release();

	virtual std::string name() const { return "CEditorTask"; }

	void enable(bool e);
	bool enable();
	void reset();
	
	
	CEditableElementCommon *selectedElement() {return _selectedElement;}
	
private:

	void _mouseSelectModule();
		
	bool _enable;
	guiSPG<CGuiFrame> _testFrame;
	CEditableElementCommon *_selectedElement;
	float	_mouseX;
	float	_mouseY;
	double  _lastUpdateTime;
};

#endif
