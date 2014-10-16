/*
 *  Loop.h
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

#ifndef LOOP_H
#define LOOP_H

#include <vector>
#include <QtOpenGL>
#include "OS_GL_Wrapper.h"

class Segment;
class Slice;

class Loop
{
public:
	Loop(Segment* startingSeg, Slice* parentSlice);
	~Loop();
	Slice* pSlice;

	std::vector<Segment*> segListp;
	Segment* pOriginSeg;//the segment that the loop starts with
	int numSegs;
	
	
    std::vector<QVector2D> polygonStrip;
    std::vector<QVector2D> triangleStrip;//ordered list of vertexes to be rendered, created by the triangulator

	bool isfill;

	//Debug Flags
	bool isComplete;//indicates if the loop is sealed off completely.
	bool isPatched;
	double totalAngle;//total angular change around the loop
	

	void ResetOrigin();
	
	int Grow();
	
	void AttachSegment(Segment* seg);

	bool SealHole(Segment* pLastSeg);
	
	void Simplify();//removes the smallest segment from the loop and seals up the gap.
	
	bool ThrowoutSmallestSegment();

	int NudgeSharedPoints();//finds "self touching" segment points and nudges them out of the way.
	
    int DetermineTypeBySides();

	void formPolygon();
	
    bool formTriStrip();

	void Destroy();//dissacosiates all segments from loop.

	void RenderTriangles();//opengl rendering code

	int CorrectDoubleBacks();

	bool AttemptSplitUp(Slice* pslice);

private:

};













#endif
