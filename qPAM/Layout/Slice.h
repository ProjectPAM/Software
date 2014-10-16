/*
 *  Slice.h
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

#ifndef SLICE_H
#define SLICE_H

#include "ModelInstance.h"
#include "Segment.h"
#include "Loop.h"
#include "SliceExporter.h"
#include <vector>

class Triangle3D;
class Loop;

class Slice
{

public:
	

    Slice(double alt, int layerIndx);
	~Slice();

	void AddSegment(Segment* pSeg);
	
	int GenerateSegments(B9ModelInstance* inputInstance);//returns number of initial segments

    void SortSegmentsByX();

	void ConnectSegmentNeighbors(); //returns the number of nudges
	
	int GenerateLoops();

    void Render();//OpenGL rendering code - renders the whole slice.
    void RenderOutlines();
	void DebugRender(bool normals = true, bool connections = true, bool fills = true, bool outlines = true);//renders with visible debug information


	//export helpers
	void WriteToSlc(SlcExporter* pslc);


	std::vector<Segment*> segmentList;//list of segments
	
	std::vector<Loop> loopList;
	int numLoops;

	double realAltitude;//in mm;
    int layerIndx;//index in the progression of layers in a job (or similar construct)
    bool inProccessing;//for multithreading help...
    QImage* pImg;//for rasturing help..
private:
	bool TestIntersection(QVector2D &vec,Segment* seg1, Segment* seg2);
    void GetTrianglesAroundZ(std::vector<Triangle3D*> &outList, double z);
    void GetSegmentsAroundX(std::vector<Segment*> &outList, double x);

};


#endif
