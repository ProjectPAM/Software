/*
 *  MainWindow.h
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openActionSlot();
    void newActionSlot();
    void runActionSlot();
    void pauseActionSlot();
    void stopActionSlot();

private:
    QAction *openAction;
    QAction *saveAction;
    QAction *newAction;
    QAction *runAction;
    QAction *pauseAction;
    QAction *stopAction;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *runMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;

    QToolBar *fileToolBar;
    QToolBar *runToolBar;

    QWidget *centralWidget;

    void setupUi();

    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void createDockWindows();

};

#endif // MAINWINDOW_H
