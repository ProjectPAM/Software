/*
 *  SliceContext.h
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

#ifndef SLICECONTEXT_H
#define SLICECONTEXT_H

#include <QGLWidget>
#include "Layout.h"
#include "Slice.h"
class SliceData;
class SliceContext : public QGLWidget
{
	Q_OBJECT

public:
    SliceContext(QWidget *parent, B9LayoutProjectData* pmain);
     ~SliceContext();

	void SetSlice(Slice* slice);
void paintGL();

private:
	void initializeGL();

	
	
	
    B9LayoutProjectData* projectData;
	Slice* pSlice;


};

#endif
