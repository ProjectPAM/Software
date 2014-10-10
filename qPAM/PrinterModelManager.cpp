/*
 *  PrinterModelManager.cpp
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

#include "PrinterModelManager.h"
#include "PrinterModelData.h"

#include <QDebug>
#include <QSettings>

b9PrinterModelManager::b9PrinterModelManager(QObject *parent) :
    QObject(parent)
{
    this->SetCurrentOperatingPrinter(NULL);
}

b9PrinterModelManager::~b9PrinterModelManager()
{

}
b9PrinterModelData* b9PrinterModelManager::GetCurrentOperatingPrinter()
{
    return m_CurrentOperatingPrinter;
}

std::vector<b9PrinterModelData*> b9PrinterModelManager::GetPrinterModels()
{
    return m_PrinterDataList;
}

bool b9PrinterModelManager::SetCurrentOperatingPrinter(b9PrinterModelData* modelDataPtr)
{
    if(modelDataPtr == NULL) return false;

    m_CurrentOperatingPrinter = modelDataPtr;

    return true;
}

bool b9PrinterModelManager::SetCurrentOperatingPrinter(QString modelName)
{
    QSettings appSettings;

    if(FindPrinterDataByName(modelName) != NULL)
    {
        appSettings.beginGroup("PRINTER_DATA_MANAGER");
            appSettings.setValue("LATEST_OPERATING_PRINTER_NAME",modelName);
        appSettings.endGroup();
        return true;
    }
    else
    {
        qDebug() << "b9PrinterModelManager-SetCurrentOperatingPrinter: Unable To Find Printer By Name Of: " << modelName;
        return false;
    }
}

b9PrinterModelData* b9PrinterModelManager::FindPrinterDataByName(QString modelName)
{
    for(unsigned int i = 0; i < m_PrinterDataList.size(); i++)
    {
        if(m_PrinterDataList.at(i)->GetName() == modelName)
            return m_PrinterDataList[i];
    }

    return NULL;
}

b9PrinterModelData* b9PrinterModelManager::AddPrinterData(QString modelName)
{
   if(FindPrinterDataByName(modelName) != NULL)
        return NULL;

   b9PrinterModelData* newPrinterData = new b9PrinterModelData(modelName);
   m_PrinterDataList.push_back(newPrinterData);

   return m_PrinterDataList[m_PrinterDataList.size()-1];
}

void b9PrinterModelManager::ImportDefinitions(QString defFilePath)
{

}





