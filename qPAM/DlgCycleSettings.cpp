/*
 *  DlgCycleSettings.cpp
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

#include <QMessageBox>
#include <QValidator>
#include "DlgCycleSettings.h"
#include "ui_DlgCycleSettings.h"

DlgCycleSettings::DlgCycleSettings(PCycleSettings* pSettings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgCycleSettings)
{
    ui->setupUi(this);
    m_pSettings = pSettings;
    m_pSettings->loadSettings(); // load from system
    updateDialog();
}

DlgCycleSettings::~DlgCycleSettings()
{
    delete ui;
}

void DlgCycleSettings::updateDialog()
{
    ui->spinBoxRaiseSpd1->setValue(m_pSettings->m_iRSpd1);
    ui->spinBoxLowerSpd1->setValue(m_pSettings->m_iLSpd1);
    ui->spinBoxCloseSpd1->setValue(m_pSettings->m_iCloseSpd1);
    ui->spinBoxOpenSpd1->setValue(m_pSettings->m_iOpenSpd1);

    ui->doubleSpinBoxOverlift1->setValue(m_pSettings->m_dOverLift1);
    ui->doubleSpinBoxBreathe1->setValue(m_pSettings->m_dBreatheClosed1);
    ui->doubleSpinBoxSettle1->setValue(m_pSettings->m_dSettleOpen1);

    ui->spinBoxRaiseSpd2->setValue(m_pSettings->m_iRSpd2);
    ui->spinBoxLowerSpd2->setValue(m_pSettings->m_iLSpd2);
    ui->spinBoxCloseSpd2->setValue(m_pSettings->m_iCloseSpd2);
    ui->spinBoxOpenSpd2->setValue(m_pSettings->m_iOpenSpd2);

    ui->doubleSpinBoxOverlift2->setValue(m_pSettings->m_dOverLift2);
    ui->doubleSpinBoxBreathe2->setValue(m_pSettings->m_dBreatheClosed2);
    ui->doubleSpinBoxSettle2->setValue(m_pSettings->m_dSettleOpen2);

    ui->doubleSpinBoxBTCutoff->setValue(m_pSettings->m_dBTClearInMM);

    ui->doubleSpinBoxHardZDown->setValue(m_pSettings->m_dHardZDownMM);
    ui->doubleSpinBoxZFlush->setValue(m_pSettings->m_dZFlushMM);
}

void DlgCycleSettings::stuffSettings()
{
    m_pSettings->m_iRSpd1 = ui->spinBoxRaiseSpd1->value();
    m_pSettings->m_iLSpd1 = ui->spinBoxLowerSpd1->value();
    m_pSettings->m_iCloseSpd1 = ui->spinBoxCloseSpd1->value();
    m_pSettings->m_iOpenSpd1  = ui->spinBoxOpenSpd1->value();
    m_pSettings->m_dOverLift1 = ui->doubleSpinBoxOverlift1->value();
    m_pSettings->m_dBreatheClosed1 = ui->doubleSpinBoxBreathe1->value();
    m_pSettings->m_dSettleOpen1 = ui->doubleSpinBoxSettle1->value();

    m_pSettings->m_iRSpd2 = ui->spinBoxRaiseSpd2->value();
    m_pSettings->m_iLSpd2 = ui->spinBoxLowerSpd2->value();
    m_pSettings->m_iCloseSpd2 = ui->spinBoxCloseSpd2->value();
    m_pSettings->m_iOpenSpd2  = ui->spinBoxOpenSpd2->value();
    m_pSettings->m_dOverLift2 = ui->doubleSpinBoxOverlift2->value();
    m_pSettings->m_dBreatheClosed2 = ui->doubleSpinBoxBreathe2->value();
    m_pSettings->m_dSettleOpen2 = ui->doubleSpinBoxSettle2->value();

    m_pSettings->m_dBTClearInMM = ui->doubleSpinBoxBTCutoff->value();

    m_pSettings->m_dHardZDownMM = ui->doubleSpinBoxHardZDown->value();
    m_pSettings->m_dZFlushMM = ui->doubleSpinBoxZFlush->value();
}

void DlgCycleSettings::on_buttonBox_accepted()
{
    stuffSettings();
    m_pSettings->saveSettings();
    close();
}

void DlgCycleSettings::on_buttonBox_rejected()
{
    close();
}

void DlgCycleSettings::on_pushButtonRestoreDefaults_clicked()
{
    m_pSettings->setFactorySettings();
    updateDialog();
}
