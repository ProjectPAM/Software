/*
 *  NativeApp.cpp
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

#include <QWidget>
#include "NativeApp.h"

// It's safe to call this function on any platform.
// It will only have an effect on the Mac.
void B9NativeApp::set_smaller_text_osx(QWidget *w)
{
    return; //not using the small fonts right now...
    if(w==0)return;

    // By default, none of these size attributes are set.
    // If any has been set explicitly, we'll leave the widget alone.
    if (!w->testAttribute(Qt::WA_MacMiniSize) &&
        !w->testAttribute(Qt::WA_MacSmallSize) &&
        !w->testAttribute(Qt::WA_MacNormalSize) &&
        !w->testAttribute(Qt::WA_MacVariableSize))
    {
        // Is the widget is one of a number of types whose default
        // text size is too large?
        if (w->inherits("QLabel") ||
            w->inherits("QLineEdit") ||
            w->inherits("QTextEdit") ||
            w->inherits("QComboBox") ||
            w->inherits("QCheckBox") ||
            w->inherits("QRadioButton") ||
            w->inherits("QAbstractItemView"))
            // Others could be added here...
        {
            // make the text the 'normal' size
            w->setAttribute(Qt::WA_MacMiniSize);
        }
        else if( w->inherits("QPushButton") )
            // Others could be added here...
        {
            // make the text the 'normal' size
            w->setAttribute(Qt::WA_MacMiniSize);
        }
    }
}

bool B9NativeApp::event(QEvent* event)
{
    if( event->type() == QEvent::FileOpen)
    {
        //TODO Use this for Mac-Os File associations.
        //pMain->openJob(static_cast<QFileOpenEvent*>(event)->file());
        return true;
    }
    return QApplication::event(event);
}

