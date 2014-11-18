/*
 *  MainWindow.cpp
 *
 *  Copyright 2014 Daniel Olsen
 *
 *  This file is part of LibreCAM
 *
 *    LibreCAM is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    LibreCAM is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with LibreCAM.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setWindowTitle(tr("LibreCAM"));

    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    setupUi();
}

MainWindow::~MainWindow()
{

}

void MainWindow::openActionSlot()
{

}

void MainWindow::newActionSlot()
{

}

void MainWindow::runActionSlot()
{

}

void MainWindow::pauseActionSlot()
{

}

void MainWindow::stopActionSlot()
{

}

void MainWindow::setupUi()
{
    this->resize(748, 586);

    centralWidget = new QWidget(this);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    centralWidget->setCursor(QCursor(Qt::ArrowCursor));
    this->setCentralWidget(centralWidget);

}

void MainWindow::createActions()
{
    openAction = new QAction(tr("&Open"), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Need to fill this in"));

    QIcon icon;
    QString iconThemeName = QStringLiteral("document-open");

    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon = QIcon::fromTheme(iconThemeName);
    } else {
        icon.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
    }

    openAction->setIcon(icon);
    connect(openAction, SIGNAL(triggered()), this, SLOT(openActionSlot()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Need to fill this in"));

    QIcon icon1;
    iconThemeName = QStringLiteral("document-save");

    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon1 = QIcon::fromTheme(iconThemeName);
    } else {
        icon1.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
    }

    saveAction->setIcon(icon1);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveActionSlot()));

    newAction = new QAction(tr("&New"), this);
    newAction->setShortcuts(QKeySequence::New);
    newAction->setStatusTip(tr("Need to fill this in"));

    QIcon icon2;
    iconThemeName = QStringLiteral("document-new");

    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon2 = QIcon::fromTheme(iconThemeName);
    } else {
        icon2.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
    }

    newAction->setIcon(icon2);
    connect(newAction, SIGNAL(triggered()), this, SLOT(newActionSlot()));

    runAction = new QAction(tr("&Run"), this);
    //runAction->setShortcuts(QKeySequence::Open);
    runAction->setStatusTip(tr("Need to fill this in"));

    QIcon icon3;
    iconThemeName = QStringLiteral("media-playback-start");

    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon3 = QIcon::fromTheme(iconThemeName);
    } else {
        icon3.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
    }

    runAction->setIcon(icon3);
    connect(runAction, SIGNAL(triggered()), this, SLOT(runActionSlot()));

    pauseAction = new QAction(tr("&Pause"), this);
    //pauseAction->setShortcuts(QKeySequence::Open);
    pauseAction->setStatusTip(tr("Need to fill this in"));

    QIcon icon4;
    iconThemeName = QStringLiteral("media-playback-pause");

    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon4 = QIcon::fromTheme(iconThemeName);
    } else {
        icon4.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
    }

    pauseAction->setIcon(icon4);
    connect(pauseAction, SIGNAL(triggered()), this, SLOT(pauseActionSlot()));

    stopAction = new QAction(tr("&Stop"), this);
    //stopAction->setShortcuts(QKeySequence::stop);
    stopAction->setStatusTip(tr("Need to fill this in"));

    QIcon icon5;
    iconThemeName = QStringLiteral("media-playback-stop");

    if (QIcon::hasThemeIcon(iconThemeName)) {
        icon5 = QIcon::fromTheme(iconThemeName);
    } else {
        icon5.addFile(QStringLiteral(""), QSize(), QIcon::Normal, QIcon::Off);
    }

    stopAction->setIcon(icon5);
    connect(stopAction, SIGNAL(triggered()), this, SLOT(stopActionSlot()));

}

void MainWindow::createMenus()
{
    fileMenu = this->menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();

    runMenu = this->menuBar()->addMenu(tr("&Run"));
    runMenu->addAction(runAction);
    runMenu->addAction(pauseAction);
    runMenu->addAction(stopAction);
    runMenu->addSeparator();

}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    runToolBar = addToolBar(tr("Run"));
    runToolBar->addAction(runAction);
    runToolBar->addAction(pauseAction);
    runToolBar->addAction(stopAction);

}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createDockWindows()
{

}
