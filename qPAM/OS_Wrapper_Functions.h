/*
 *  OS_Wrapper_Functions.h
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

//This Header is for application wide convenience functions.

#ifndef OS_WRAPPER_FUNCTIONS_H
#define OS_WRAPPER_FUNCTIONS_H

#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QWidget>
#include "UpdateEntry.h"

//OPERATING SYSTEM COMPATIBILITY HELPER FUNCTIONS::
//dialog compatibility
QString CROSS_OS_GetSaveFileName(QWidget * parent = 0,
                                 const QString & caption = QString(),
                                 const QString & directory = QString(),
                                 const QString & filter = QString(),
                                 const QStringList &saveAbleExtensions = QStringList() );
//File Location Compatibility
QString CROSS_OS_GetDirectoryFromLocationTag(QString locationtag);

//Screen Saver Disabling
bool CROSS_OS_DisableSleeps(bool disable = 1);


//FILE HANDING HELPER FUNCTIONS
//streams in "some random text with spaces" from the opened text file.
QString StreamInTextQuotes(QTextStream &stream);

//Cursor waiting
void Enable_User_Waiting_Cursor();
void Disable_User_Waiting_Cursor();

#endif // OS_FILEDIALOG_WRAPPER_H
