/*
 *  PrinterModelManager.h
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

#ifndef B9PRINTERMODELMANAGER_H
#define B9PRINTERMODELMANAGER_H

#include <QObject>
#include <QVector>
#include "PrinterModelData.h"

class QString;


class b9PrinterModelManager : public QObject
{
    Q_OBJECT
public:
    explicit b9PrinterModelManager(QObject *parent = 0);
    ~b9PrinterModelManager();

    void ImportDefinitions(QString defFilePath);//imports from given definition file

    b9PrinterModelData* GetCurrentOperatingPrinter();
    std::vector<b9PrinterModelData*> GetPrinterModels();
    bool SetCurrentOperatingPrinter(b9PrinterModelData* modelDataPtr);
    bool SetCurrentOperatingPrinter(QString modelName);
    b9PrinterModelData* FindPrinterDataByName(QString modelName);





signals:
    void FilesUpdated();
    
public slots:


private:
    //members
    std::vector<b9PrinterModelData*> m_PrinterDataList;
    b9PrinterModelData* m_CurrentOperatingPrinter;

    //functions
    b9PrinterModelData* AddPrinterData(QString modelName);





};

#endif // B9PRINTERMODELMANAGER_H
