/*
 *  GeometricFunctions.h
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

#ifndef GEOMETRICFUNCTIONS_H
#define GEOMETRICFUNCTIONS_H

#include "math.h"
#include "qmath.h"
#include <QVector2D>
#include <QVector3D>


#define TO_RAD 0.01745329251994329
#define SIMPLIFY_THRESH 0.001

class QVector2D;
class QVector3D;
class Segment;

//Utility Prototypes
bool IsZero(double number, double tolerance);
bool PointsShare(QVector2D point1, QVector2D point2, double tolerance);
int PointLineCompare(QVector2D pointm, QVector2D dir, QVector2D quarrypoint);//return -1,0,1 for one side of line, one line, and other side of line.
double Distance2D(QVector2D point1, QVector2D point2);
double Distance3D(QVector3D point1, QVector3D point2);
inline void RotateVector(QVector3D &vec, double angledeg, QVector3D axis)//choose 1 axis of rotation at a time..
{
    double prevx;
    double prevy;
    double prevz;
    double cosval = qCos( angledeg * TO_RAD );
    double sinval = qSin( angledeg * TO_RAD );

    if(axis.x())
    {
        prevx = vec.x();
        prevy = vec.y();
        prevz = vec.z();
        vec.setY( prevy * cosval - prevz * sinval);
        vec.setZ( prevy * sinval + prevz * cosval);
    }

    if(axis.y())
    {
        prevx = vec.x();
        prevy = vec.y();
        prevz = vec.z();
        vec.setZ( prevz * cosval - prevx * sinval);
        vec.setX( prevz * sinval + prevx * cosval);
    }

    if(axis.z())
    {
        prevx = vec.x();
        prevy = vec.y();
        prevz = vec.z();
        vec.setX( prevx * cosval - prevy * sinval);
        vec.setY( prevx * sinval + prevy * cosval);
    }
}
bool VectorComponentsEqual(QVector3D &vec);
double VectorMaxComponentLength(QVector3D vec);
bool SegmentIntersection(QVector2D &result, QVector2D seg11, QVector2D seg12, QVector2D seg21, QVector2D seg22) ;
bool SegmentsAffiliated(Segment* seg1, Segment* seg2, double epsilon);
double MinAngleBetweenVectors(QVector3D a, QVector3D b);
#endif
