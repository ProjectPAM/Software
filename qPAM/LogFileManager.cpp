/*
 *  LogFileManager.cpp
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

#include "LogFileManager.h"
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QUrl>
#include <QDebug>
#include <QApplication>
#include <QDesktopServices>
#include "OS_Wrapper_Functions.h"

bool bGlobalPrinting;

QString sLogFileName;
void messageHandler(QtMsgType type, const char *msg)
{
    QFile outFile(sLogFileName);
    QTextStream ts;
    QString txt;
    txt = QDateTime::currentDateTime().toString("yy.MM.dd hh:mm:ss.zzz");
    switch (type) {
    case QtDebugMsg:
        if(!bGlobalPrinting){
            fprintf(stderr, "Debug: %s\n", msg);
            txt += QString("  : %1").arg(msg);
            outFile.open(QIODevice::WriteOnly | QIODevice::Append);
            ts.setDevice(&outFile);
            ts << txt << "\r" << endl;
            outFile.close();
        }
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s\n", msg);
    break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s\n", msg);
    break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s\n", msg);
    }
    if(type== QtFatalMsg)
        abort();
}

LogFileManager::LogFileManager(QString sLogFile, QString sHeader)
{
    bGlobalPrinting = false;
    QFile::remove(sLogFile);
    sLogFileName = sLogFile;

    QFile outFile(sLogFile);
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << sHeader << "\r\n\r" << endl;
    outFile.close();
    qInstallMsgHandler(messageHandler);
}

LogFileManager::~LogFileManager()
{
    qInstallMsgHandler(0);
}

void LogFileManager::setPrinting(bool bPrinting)
{
    bGlobalPrinting = bPrinting;
}

void LogFileManager::openLogFileInFolder()
{
    QString path = CROSS_OS_GetDirectoryFromLocationTag("DOCUMENTS_DIR");
    path += "/" + sLogFileName;
    qDebug() << "Log File Location "+path;
    path = "file:///" + path;
    QDesktopServices::openUrl(QUrl(path));
}

