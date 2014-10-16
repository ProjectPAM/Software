/*
 *  VerticalTriContainer.h
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

#ifndef B9VERTICALTRICONTAINER_H
#define B9VERTICALTRICONTAINER_H

#include <vector>
#include "Triangle3d.h"

#define TRICONTAINER_PLAY 0.001

class B9VerticalTriContainer
{
public:
    B9VerticalTriContainer();

    double maxZ;
    double minZ;

    B9VerticalTriContainer* upContainer;
    B9VerticalTriContainer* downContainer;

    std::vector<Triangle3D*> tris;


    bool TriangleFits(Triangle3D* tri)
    {
        //test if the triangle has any part in the container.
        if((tri->maxBound.z() >= (minZ - TRICONTAINER_PLAY))
          &&
          (tri->minBound.z() <= (maxZ + TRICONTAINER_PLAY)))

           return true;

        return false;
    }

};

#endif // B9VERTICALTRICONTAINER_H
