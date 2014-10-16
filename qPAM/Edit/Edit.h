/*
 *  Edit.h
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

#ifndef B9EDIT_H
#define B9EDIT_H

#include <QtGui/QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include "ui_Edit.h"
#include "CrushBitmap.h"
#include "SliceEditView.h"
#include "AboutBox.h"
#include <QCloseEvent>


class B9Edit : public QMainWindow
{
	Q_OBJECT

public:
    B9Edit(QWidget *parent = 0, Qt::WFlags flags = 0, QString inputfile = "");
    ~B9Edit();

public slots:
	//file
	void newJob();
    void openJob(QString infile = "");
	void saveJob();
	void saveJobAs();
	//import
	void importSlices();//button access , branches to firstfile() or loadsvg()
	void importSlicesFromFirstFile(QString firstfile);
    void importSlicesFromSvg(QString file,double pixelsizemicrons = -1.0);
    void importSlicesFromSlc(QString file,double pixelsizemicrons = -1.0);
	void CancelLoading(); //when a progress bar is cancelled prematurelly, this is called.
	 
	//export
	void ExportToFolder();

	//persistent directory
	void SetDir(QString dir);
	QString GetDir();
	
	void updateName(QString s){sName=s; cPJ.setName(s); dirtied = true; updateWindowTitle();}
	void updateDescription(QString s){sDescription=s; cPJ.setDescription(s); dirtied = true; updateWindowTitle();}
	void updateXY(QString s){XYPixel=s; cPJ.setXYPixel(s); dirtied = true; updateWindowTitle();}
    void updateZ(QString s){ZLayer=s; cPJ.setZLayer(QString::number(s.toDouble()/1000.0,'f',6)); dirtied = true; updateWindowTitle();}
	void updateSliceIndicator();
	void updateWindowTitle();
	
	 //sliceeditview
	void ShowSliceWindow();
	void HideSliceWindow();

	void PatchJobData(QImage* pNewImg, int slicenumber); //called by the edit view, indicating an image has been modified and needs to be recompressed into the data structure
	void SetDirty();

signals:
    void eventHiding();
    void selectedDirChanged(QString s);
	void setVersion(QString s);	
	void setName(QString s);
	void setDescription(QString s);
	void setXYPixel(QString s);
	void setZLayer(QString s);
	void setSliceIndicator(QString s);

protected:
	void closeEvent(QCloseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
    void hideEvent(QHideEvent *event);
    Ui::B9EditClass ui;

	//pointer to the SliceEditView
	SliceEditView* pEditView;

    //pointer to the aboutbox
    aboutbox* pAboutBox;

	QString sVersion;
	QString sName;
	QString sDescription;
	QString XYPixel;
	QString ZLayer;
	QString sDirPath;

	bool dirtied;
	bool continueLoading;
	QString currJobFile;

	CrushedPrintJob cPJ;

	int PromptSaveOnQuit();

};

#endif // B9EDIT_H







