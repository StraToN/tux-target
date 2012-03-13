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
#include "background_task.h"
#include "resource_manager2.h"


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
	
void CBackgroundTask::init()
{
	string res;
	res = CResourceManager::getInstance().get("intro_background.tga");
	Background = C3DTask::getInstance().driver().createTextureFile (res);
	nlassert(Background);
	res = CResourceManager::getInstance().get("intro_target.tga");
	Target = C3DTask::getInstance().driver().createTextureFile (res);
	nlassert(Target);
	res = CResourceManager::getInstance().get("intro_logo.tga");
	Logo = C3DTask::getInstance().driver().createTextureFile (res);
	nlassert(Logo);
// when we add particle, it becomes very slow and bad placement
//	res = CResourceManager::getInstance().get("logo.ps");
//	LogoParticle = C3DTask::getInstance().scene().createInstance(res);
//	nlassert(LogoParticle);
//	LogoParticle->setTransformMode (UTransformable::DirectMatrix);
	LogoParticle = 0;

	_dx1 = 0;
	_dy1 = 0;
	_dx2 = 0;
	_dy2 = 0;
}


void CBackgroundTask::update()
{
	double t = CTimeTask::getInstance().time();
	
	_dx1 = (float)(70.0f * cos(sin(t*1.2f+0.5f))) - 128.0f;
	_dy1 = (float)(60.0f * cos(cos(t*0.9f+3.0f))) - 128.0f;
	_dx2 = (float)(200.0f * cos(t*0.512345f+0.57733584f)*sin(t*0.71874f+0.1248721f)) - 128.0f;
	_dy2 = (float)(150.0f * cos(t*0.189713f+0.48754118f)*cos(t*0.91871f+3.6873738f)) - 128.0f;
}

void CBackgroundTask::render()
{
	const float LogoScale = 1.5f;
	const float BackSize = 64.0f;

	C3DTask::getInstance().driver().setMatrixMode2D11 ();
	C3DTask::getInstance().driver().setMatrixMode2D (CFrustum(0,640,0,480,-1,1,false));

	for (uint32 j=0;j<10;j++)
	{
		float y = -0.5f + j * BackSize + _dy1;
		for (uint32 i=0;i<15;i++)
		{
			float x = -0.5f + i * BackSize + _dx1;
			C3DTask::getInstance().driver().drawBitmap (x, y, BackSize, BackSize, *(UTexture*)Background);
		}
	}
	
	C3DTask::getInstance().driver().drawBitmap (20+250+_dx2,480-206+_dy2-20, LogoScale*256.0f, LogoScale*256.0f, *(UTexture*)Target, true, CRGBA(0,0,0,100));
	C3DTask::getInstance().driver().drawBitmap (250+_dx2,480-206+_dy2, LogoScale*256.0f, LogoScale*256.0f, *(UTexture*)Target);
	C3DTask::getInstance().driver().drawBitmap (20+150, 480-300-20, LogoScale*256, LogoScale*256, *(UTexture*)Logo, true, CRGBA(0,0,0,100));
	C3DTask::getInstance().driver().drawBitmap (150, 480-300, LogoScale*256, LogoScale*256, *(UTexture*)Logo, true, CRGBA(255,255,255,230));

	C3DTask::getInstance().driver().drawBitmap (0, 0, 1, 1, *(UTexture*)Background);//FAKE drawbitmap (no alpha in texture)to restore soem flag on gfx card (ati bug)
}

void CBackgroundTask::release()
{
	if(Background)
	{
		C3DTask::getInstance().driver().deleteTextureFile(Background);
		Background = 0;
	}
	if(Target)
	{
		C3DTask::getInstance().driver().deleteTextureFile(Target);
		Target = 0;
	}
	if(Logo)
	{
		C3DTask::getInstance().driver().deleteTextureFile(Logo);
		Logo = 0;
	}
	if(!LogoParticle.empty())
	{
		C3DTask::getInstance().scene().deleteInstance(LogoParticle);
	}
}
