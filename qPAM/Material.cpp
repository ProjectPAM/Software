/*
 *  Material.cpp
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
#include "Material.h"
#include "qstring.h"

B9Material::B9Material()
{
    m_sMaterialLabel = "Default Material Name";
    m_sMaterialDescription = "Defualt Material Description";
    AddXYSize(100);
}

B9Material::~B9Material()
{
}

bool B9Material::isFactoryEntry()
{
    return m_sMaterialLabel.left(2)=="!@";
}

QString B9Material::getLabel()
{
    if(isFactoryEntry())return m_sMaterialLabel.right(m_sMaterialLabel.count()-2);
    return m_sMaterialLabel;
}

XYData* B9Material::FindXYData(double xySize)
{
    int i;
    for(i = 0; i < XYSizes.size(); i++)
    {
        if(XYSizes.at(i).size == xySize)
        {
            return &XYSizes[i];
        }
    }
    return NULL;
}


void B9Material::AddXYSize(double xySize)
{
    XYData newData;
    newData.size = xySize;
    newData.attachmentLayers = 0;
    newData.attachmentLayersCureTime = 0;

    XYSizes.append(newData);
}
void B9Material::SetXYAttachmentCureTime(double xySize, double time_s)
{
    XYData* d = FindXYData(xySize);
    if(d==NULL) return;
    d->attachmentLayersCureTime = time_s;
}

void B9Material::SetXYAttachmentLayers(double xySize,  int numberOfLayers)
{
    XYData* d = FindXYData(xySize);
    if(d==NULL) return;
    d->attachmentLayers = numberOfLayers;
}

double B9Material::GetXYAttachmentCureTime(double xySize)
{
    XYData* d = FindXYData(xySize);
    if(d==NULL) return -1;
    else
        return d->attachmentLayersCureTime;
}
