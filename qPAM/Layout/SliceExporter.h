/*
 *  SliceExporter.h
 *
 *  Copyright 2014 Daniel Olsen
 *  Copyright 2011-2012 B9Creations, LLC
 *
 *  This file is part of qPAM
 *
 *    qPAM is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    qPAM is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with qPAM.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef SLCEXPORTER
#define SLCEXPORTER
#include <fstream>

#include <string>

//using namespace std;

class SlcExporter
{
public:
	SlcExporter(std::string filename);
	~SlcExporter(void);
	bool SuccessOpen(){return opened;}

	void WriteHeader(bool unitsINCH = false, bool unitsMM = true, std::string headerstring = "");
	void WriteReservedSpace();
	void WriteSampleTableSize(char ntables);
	void WriteSampleTable(float minz, float layerthick, float linewidthcomp, float reserved = 0.0);
	void WriteNewSlice(float zaltitude, unsigned int numboundries);
	void WriteBoundryHeader(unsigned int numvertices, unsigned int numgaps);
	void WriteBoundryVert(float xcord, float ycord);

private:

	std::string filename;
	std::ofstream outfile;
	bool opened;

};

#endif
