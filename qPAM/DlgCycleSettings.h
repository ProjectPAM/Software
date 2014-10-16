/*
 *  DlgCycleSettings.h
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

#ifndef DLGCYCLESETTINGS_H
#define DLGCYCLESETTINGS_H

#include <QDialog>

#include "Terminal.h"

namespace Ui {
    class DlgCycleSettings;
}

class DlgCycleSettings : public QDialog {
    Q_OBJECT
private:
    Ui::DlgCycleSettings *ui;
    PCycleSettings* m_pSettings;
    void updateDialog();
    void stuffSettings();
    
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_pushButtonRestoreDefaults_clicked();

public:
    explicit DlgCycleSettings(PCycleSettings *pSettings, QWidget *parent = 0);
    ~DlgCycleSettings();

};

#endif // DLGCYCLESETTINGS_H
