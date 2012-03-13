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
// Includes
//

#include "stdpch.h"

#include "3d_task.h"
#include "time_task.h"
#include "resource_manager2.h"
#include "gui_spacer.h"


//
// Namespaces
//

using namespace std;
using namespace NL3D;
using namespace NLMISC;


//
// Variables
//


//
// Functions
//
void CGuiSpacerManager::init()
{
	CGuiSpacer::XmlRegister();
}

void CGuiSpacerManager::render()
{
}

void CGuiSpacerManager::release()
{
}


//
//
//
CGuiSpacer::CGuiSpacer()
{
}

CGuiSpacer::~CGuiSpacer()
{
	
}

void CGuiSpacer::XmlRegister()
{
	CGuiObjectManager::getInstance().registerClass("CGuiSpacer",CGuiSpacer::Create);
}

CGuiObject *CGuiSpacer::Create()
{
	CGuiObject *res = new CGuiSpacer;
	
	return res;	
}


void CGuiSpacer::init(CGuiXml *xml,xmlNodePtr node)
{
	CGuiObject::init(xml,node);
}

