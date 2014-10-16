/*
 *  Triangle3D.h
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

#ifndef TRIANGLE3D_H
#define TRIANGLE3D_H

#include <QVector3D>

class Triangle3D
{
public:
	QVector3D normal;
	QVector3D vertex[3];

	//specs
	QVector3D maxBound;
	QVector3D minBound;

	Triangle3D();
    ~Triangle3D();

	void UpdateBounds();
    void UpdateNormalFromGeom();//recomputes normal from vertex's
	bool IsBad(); //returns true if the triangle has no "area" or no bounds.
	bool ParallelXYPlane();
	bool IntersectsXYPlane(double realAltitude);

    static bool GreaterTopAltitude(Triangle3D* t1, Triangle3D* t2)
    {
        return (t1->maxBound.z() < t2->maxBound.z());
    }

    static bool GreaterBottomAltitude(Triangle3D* t1, Triangle3D* t2)
    {
        return (t1->minBound.z() < t2->minBound.z());
    }
};

#endif
