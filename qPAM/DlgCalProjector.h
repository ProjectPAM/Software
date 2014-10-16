/*
 *  DlgCalProjector.h
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

#ifndef DLGCALPROJECTOR_H
#define DLGCALPROJECTOR_H

#include <QDialog>
#include "Terminal.h"

namespace Ui {
class dlgCalProjector;
}

class dlgCalProjector : public QDialog
{
    Q_OBJECT
    
public:
    explicit dlgCalProjector(B9Terminal* pTerminal, QWidget *parent = 0);
    ~dlgCalProjector();
    
private:
    Ui::dlgCalProjector *ui;
    B9Terminal* m_pTerminal;

public slots:
    void findHome();
    void done();
    void onResetComplete();
    void onProjectorIsOn();
    void on_updateProjectorOutput(QString sText);
    void onStep1(bool checked);
    void onStep2(bool checked);
    void onStep3();
    void onStep4(bool checked);
    void onStep5(bool checked);
    void onStep6();

private slots:
    void on_comboBoxXPPixelSize_currentIndexChanged(int index);

protected:
    void closeEvent ( QCloseEvent * event );
};

#endif // DLGCALPROJECTOR_H
