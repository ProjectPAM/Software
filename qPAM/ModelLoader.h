/*
 *  ModelLoader.h
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

#ifndef B9MODELLOADER_H
#define B9MODELLOADER_H

#include <QObject>
#include <QFile>
#include <QTextStream>


//simple structure to read triangles into
//TODO assuming floats are 32bits on the compiling platform
struct STLTri
{
    float nx,ny,nz;
    //by stl definition,
    //the model is supposed to be in positive cordinates only
    //but were using unsigned anyway...
    float x0,y0,z0;
    float x1,y1,z1;
    float x2,y2,z2;
};


class B9ModelLoader : public QObject
{
    Q_OBJECT
public:
    explicit B9ModelLoader( QString filename, bool &readyRead, QObject *parent = 0);
    ~B9ModelLoader();

    bool LoadNextTri(STLTri *&tri, bool &errorFlag);
    float GetPercentDone();
    QString GetError(){return lastError;}//returns any errors that happened in the loading process.


signals:
    void PercentCompletedUpdate(qint64 frac, qint64 total);
    
public slots:

private:

    QString fileType;// "BIN_STL", "ASCII_STL", "UNCOMPRESSED_AMF"......
    QFile asciifile;
    QTextStream asciiStream;
    QFile binfile;

    quint32 triCount;
    unsigned long int byteCount;

    QString lastError;

    float lastpercent;
    QString DetermineFileType(QString filename, bool &readyRead);
    void PrepareSTLForReading(QString filename, bool &readyRead);
    void PrepareAMFForReading(){}
    bool ReadBinHeader();
    bool ReadAsciiHeader();
    bool CheckBinFileValidity();
};

#endif // B9MODELLOADER_H
