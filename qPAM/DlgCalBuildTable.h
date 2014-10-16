/*
 *  DlgCalBuildTable.h
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

#ifndef DLGCALBUILDTABLE_H
#define DLGCALBUILDTABLE_H

#include <QDialog>
#include "Terminal.h"

namespace Ui {
class dlgCalBuildTable;
}

class dlgCalBuildTable : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgCalBuildTable(B9Terminal* pTerminal, QWidget *parent = 0);
    ~dlgCalBuildTable();
    
public slots:
    void findHome();
    void goZero();
    void raiseUp();
    void done();
    void onResetComplete();
    void onMotionComplete();

    void on_Step1(bool checked);
    void on_Step2(bool checked);
    void on_Step3();
    void on_Step4();
    void on_Step5(bool checked);
    void on_Step6(bool checked);
    void on_Step7();
    void on_Step8(bool checked);

private:
    Ui::dlgCalBuildTable *ui;
    B9Terminal* m_pTerminal;
    bool bFindingHome;

protected:
    void closeEvent ( QCloseEvent * e );
};

#endif // DLGCALBUILDTABLE_H
