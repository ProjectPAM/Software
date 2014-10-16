/*
 *  main.cpp
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

#include <QtGui/QApplication>
#include <QSplashScreen>
#include "NativeApp.h"
#include <QDir>

int main(int argc, char *argv[])
{
    B9NativeApp a(argc, argv);

    QPixmap pixmap(CROSS_OS_GetDirectoryFromLocationTag("APPLICATION_DIR")+"/"+"splash.png");
    QSplashScreen splash(pixmap,Qt::WindowStaysOnTopHint);
    //processEvents();
    a.mainWindow->setSplash(&splash);
    a.mainWindow->show();
    a.mainWindow->showSplash();

    a.ProccessArguments();

    return a.exec();
}
