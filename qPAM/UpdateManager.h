/*
 *  UpdateManager.h
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

#ifndef B9UPDATEMANAGER_H
#define B9UPDATEMANAGER_H

///NOTE - Dont use https - windows 8 doesnt like it for some reason.
//Instead use http
//WE ARE USING THE FIRST MANIFEST!
#define REMOTE_MANIFEST_FILENAME "Manifest_v2.txt"
#define REMOTE_MANIFEST_PATH "http://www.b9creator.com/B9CreatorUpdates/"

#define UPDATE_TIMOUT 10000

#include <QObject>
#include <QMap>
#include <QString>
#include "QtNetwork"
#include "QtNetwork/qnetworkaccessmanager.h"
#include "LoadingBar.h"
#include "UpdateEntry.h"

class B9UpdateManager : public QObject
{
    Q_OBJECT
public:
    explicit B9UpdateManager(QObject *parent = 0);
    ~B9UpdateManager();
    void PromptDoUpdates(bool showCheckingBar = true, bool promptLocalLocation = false);
    void TransitionFromPreviousVersions();
    static int GetLocalFileVersion(QString filename);

signals:
    void NotifyUpdateFinished();
    
public slots:
    void AutoCheckForUpdates(){PromptDoUpdates(false);}

private:
    QList<B9UpdateEntry> remoteEntries;
    QList<B9UpdateEntry> localEntries;
    QList<B9UpdateEntry> updateEntries;
    unsigned int currentUpdateIndx;//the index of updateEntries that we are currently expecting

    QNetworkAccessManager* netManager;
    QNetworkReply* currentReply;//pointer that represents the current download
    LoadingBar * waitingbar;
    QTimer timeoutTimer;

    QString downloadState;//are we downloading fileverions.txt or some other file or idle
    bool ignoreReplies;

    bool silentUpdateChecking;//if true - the updator will not pop up any dialogs or progress
                              //bars unless an update is acutally neededd.

    QString RemoteManifestPath;//the root folder that contains all manifests
    QString RemoteManifestFileName;//the name of the manifest (manifest1.txt, manifest2.txt, etc)

private slots:

    void StartNewDownload(QNetworkRequest request);
    void OnRecievedReply(QNetworkReply *reply);
    bool OnDownloadDone();
    void OnCancelUpdate();
    void OnDownloadTimeout();
    void ResetEverything();

    void CopyInRemoteEntries();
    void CopyInLocalEntries();
    void CalculateUpdateEntries();

    bool CopyFromTemp();//copies all downloaded file from temp into actuall locations.
    bool UpdateLocalFileVersionList();

    bool NeedsUpdated(B9UpdateEntry &candidate, B9UpdateEntry &remote);
};

#endif // B9UPDATEMANAGER_H
