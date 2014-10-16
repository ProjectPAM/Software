/*
 *  ScreenSaverWaker.h
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

#ifndef SCREENSAVERWAKER_H
#define SCREENSAVERWAKER_H

#include <QObject>
#include <QTimer>

//for use in systems where the application must be "waken" on a routine basis
class ScreenSaverWaker: public QObject
{
    Q_OBJECT

public:
    ScreenSaverWaker(QObject *parent);
    ~ScreenSaverWaker();

    void StartWaking();
    void StopWaking();

private slots:
    void Wake();

private:
    QTimer timer;

};


#endif // SCREENSAVERWAKER_H
