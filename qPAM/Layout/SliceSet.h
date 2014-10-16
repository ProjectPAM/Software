/*
 *  SliceSet.h
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

#ifndef SLICESET_H
#define SLICESET_H
#include <vector>
#include <list>
#include <queue>
#include <QDebug>
#include <QFuture>
#include <QImage>

class Slice;
class B9ModelInstance;
class CrushedPrintJob;
class SliceContext;


struct SliceRequest
{
    double altitude;
    int layerIndx;
};


class SliceSet
{
public:
    SliceSet(B9ModelInstance* pParentInstance);
	~SliceSet();

	//pointer to the "parent" modelclone
    B9ModelInstance* pInstance;

    std::queue<SliceRequest> SliceRequests;
    std::queue<Slice*> SlicedSlices;
    std::queue<Slice*> RasturizedSlices;
    std::queue<Slice*> CompressedSlices;

    std::vector< QFuture<void> > workerThreads;

    SliceContext* raster;

    void QueNewSlice(double realAltitude, int layerIndx);
    void SetSingleModelCompressHint(bool hint);
    Slice* ParallelCreateSlices(bool &slicesInTransit,CrushedPrintJob* toJob);




    void ComputeSlice(Slice* slice);
    void RasterizeSlice(Slice* slice);
    void SubtractVoidFromFill(QImage *img);
    void AddSliceToJob(Slice *rasSlice, CrushedPrintJob* job);



private:
    void SetupFutureWorkers();
    void SetupRasturizer();

    QMutex mutex;
    bool singleModelCompression;


};

#endif
