/*
 *  ModelData.h
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

#ifndef MODELDATA_H
#define MODELDATA_H

#include <QString>
#include "Layout.h"
#include "Triangle3d.h"

#include "ModelInstance.h"


#include <vector>
class B9Layout;
class aiScene;
class ModelData {

    friend class B9ModelInstance;

public:
    ModelData(B9Layout* main, bool bypassDisplayLists = false);
	~ModelData();
	
	QString GetFilePath();
	QString GetFileName();
	
	//data loading
	bool LoadIn(QString filepath); //returns success
	
	//instance
	B9ModelInstance* AddInstance();
	int loadedcount;


	//render
    // the model can potentially own
    // multiply display lists, allowing
    // the graphics driver to better allocate
    // the memory needed for very large models.
    // these flipped  lists are generated when needed.
    // -Form functions are recursive
    std::vector<unsigned int> normDispLists;
    std::vector<unsigned int> flippedDispLists;

    bool FormFlippedDisplayLists();
    bool FormNormalDisplayLists();

    //geometry
    std::vector<Triangle3D> triList;
	QVector3D maxbound;
	QVector3D minbound;

	std::vector<B9ModelInstance*> instList;
    B9Layout* pMain;
private:
	
	
	
	QString filepath;//physical filepath
	QString filename;//filename (larry.stl)

	//utility
	void CenterModel();//called by loadin to adjust the model to have a center at 0,0,0
	
	const aiScene* pScene;

	//render

    int displaySkipping; //how many triangles to skip when rendering huge objects.
    bool bypassDispLists;
	
    int GetGLError();

};
#endif
