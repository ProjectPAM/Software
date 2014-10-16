/*
 *  b9slice.h
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

#ifndef B9SLICE_H
#define B9SLICE_H

#include <QMainWindow>
#include <QHideEvent>
#include "Layout/Layout.h"

namespace Ui {
class B9Slice;
}

class B9Slice : public QMainWindow
{
    Q_OBJECT

public:
    explicit B9Slice(QWidget *parent = 0, B9Layout* Main = 0);
    ~B9Slice();


signals:
    void eventHiding();


public slots:
    void LoadLayout();
    void Slice();


private:
    void hideEvent(QHideEvent *event);
    void showEvent(QHideEvent *event);
    Ui::B9Slice *ui;
    B9Layout* pMain;

    QString currentLayout;
};

#endif // B9SLICE_H
