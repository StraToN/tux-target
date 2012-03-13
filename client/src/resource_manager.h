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
// This class manages the loading of a level
//

#ifndef MTPT_RESOURCE_MANAGER
#define MTPT_RESOURCE_MANAGER

//
// Includes
//

#include <nel/misc/mem_stream.h>
#include <nel/misc/singleton.h>
#include <nel/misc/types_nl.h>
#include <nel/misc/sha1.h>


//
// Classes
//

typedef std::map<std::string, double> filename2LastCRCCheckTime;

class CResourceManagerLan : public NLMISC::CSingleton<CResourceManagerLan>, public ITask
{
public:

	virtual void init();
	virtual void update() { };
	virtual void render() { };
	virtual void release() { };
	
	virtual std::string name() const { return "CResourceManagerLan"; }
	
	// return empty string it a problem occurs or the full path of the file
	std::string get(const std::string &filename);
	
	// ok is true if the file is found, false is not
	std::string get(const std::string &filename, bool &ok);

	void refresh(const  std::string &filename);
		
	bool waitNetworkMessage(bool stopFlag,bool &received, bool displayBackground=true);

	void receivedCRC(std::string &fn);
	
	// called only by cbRequestDownload()
	void receivedBlock(const std::string &res, const std::vector<uint8> &buf, bool eof, uint32 fileSize, bool receivedError);
	void clearCrcCheckTimes(){CRCCheckTimes.clear();};
private:
	filename2LastCRCCheckTime CRCCheckTimes;
	
	void loadChildren(const std::string &filename);

	std::string			Reason;
	bool				CRCUpToDate;
	bool				ReceivedError;
	std::vector<uint8>	Buffer;
	bool				Eof;
	uint32				FileSize;
	std::string			ReceivedFilename;
	volatile bool		Received;
	volatile bool		CRCReceived;
	CHashKey			ReceivedHashKey;
	
	std::string			CacheDirectory;
};

#endif
