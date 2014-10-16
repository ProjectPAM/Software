/*
 *  ModelWriter.h
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

#ifndef B9MODELWRITER_H
#define B9MODELWRITER_H

#include <QObject>
#include <QFile>
#include <QDataStream>

//Usage: create a B9ModelWriter object with filename and if readyWrite is true,
//begin feeding triangles in using WriteNextTri();
//when finished use Finalize();

class Triangle3D;
class B9ModelWriter : public QObject
{
    Q_OBJECT
public:

    explicit B9ModelWriter(QString filename, bool &readyWrite, QObject *parent = 0);
    ~B9ModelWriter();


signals:

    //void PercentCompletedUpdate(qint64 frac, qint64 total);

public:
    void WriteNextTri(Triangle3D* pTri);
    void Finalize();//goes back to the begining of the file and writes tri count. etc

private:
    QFile binOUT;
    QDataStream binStream;
    unsigned long int triCount;

    void WriteHeader(quint32 triCount);


};

#endif // B9MODELWRITER_H
