/*
 *  Material.h
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

#ifndef B9MATERIAL_H
#define B9MATERIAL_H

#include <QString>
#include <QVector>

struct XYData
{
    double size;
    int attachmentLayers;
    double attachmentLayersCureTime;
    QVector<double> cure_times;
    QVector<double> over_cure_times;
};

class B9Material
{
public:
    B9Material();
    ~B9Material();
    QString getLabel();
    void SetLabel(QString newLabel){m_sMaterialLabel = newLabel;}
    QString GetDescription(){return m_sMaterialDescription;}
    void SetDescription(QString newDesc){m_sMaterialDescription = newDesc;}
    void AddXYSize(double xySize);
    void SetXYAttachmentCureTime(double xySize, double time_s);
    void SetXYAttachmentLayers(double xySize,  int numberOfLayers);

    double GetXYAttachmentCureTime(double xySize);

    bool isFactoryEntry();

private:

    QString m_sMaterialLabel, m_sMaterialDescription;
    QVector<XYData> XYSizes;

    XYData* FindXYData(double xySize);
};
#endif // B9MATERIAL_H
