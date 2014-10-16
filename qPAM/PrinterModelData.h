/*
 *  PrinterModelData.h
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

#ifndef B9PRINTERMODELDATA_H
#define B9PRINTERMODELDATA_H

#include <QObject>
#include <QVector>
#include <QList>
#include "Material.h"

class QString;

class b9PrinterModelData
{
public:
    b9PrinterModelData();
    b9PrinterModelData(QString modelName);
    ~b9PrinterModelData();

    QString GetName() const;
    void AddXYPixelSize(double size){m_dXYPixelSizes.append(size);}
    void SetZStepSizeMicrons(double stepSize){m_dStepSizeMicrons = stepSize;}
    void SetMaxSteps(int maxSteps){m_iMaxSteps = maxSteps;}


    void ClearMaterials();
    void AddMaterial(B9Material mat);
    QVector<B9Material>* GetMaterials();//just returns pointers to the actual materials.
    B9Material* FindMaterialByLabel(QString label);
    double GetXYSizeByIndex(int index);

private:
    QList<double> m_dXYPixelSizes;
    double m_dStepSizeMicrons;
    int m_iMaxSteps;
    QString m_sModelName;//name such as B9C1
    QVector<B9Material> m_Materials;//materials accociated with this printer.

};





#endif // B9PRINTERMODELDATA_H
