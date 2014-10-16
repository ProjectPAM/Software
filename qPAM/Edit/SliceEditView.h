/*
 *  SliceEditView.h
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

#ifndef SLICEEDITVIEW_H
#define SLICEEDITVIEW_H
#include <QtGui/QMainWindow>
#include "ui_SliceEditView.h"
#include "DrawingContext.h"
#include "Edit.h"
#include "CrushBitmap.h"
#include <QImage>
#include <QColor>
#include <QTimer>
class B9Edit;

class SliceEditView : public QMainWindow
{
	Q_OBJECT
public:
    SliceEditView(QWidget *parent = 0, Qt::WFlags flags = Qt::Window);
	~SliceEditView();

	Ui::SliceEditViewClass ui;
	CrushedPrintJob* pCPJ;// a pointer to the builder's print job.
    B9Edit* pBuilder;
	bool modified;
	bool supportMode;	
	int currSlice;
	QString GetEditMode();

    DrawingContext* pDrawingContext; // a pointer to the drawing widget
public slots:
	void TogSupportMode();
	void GoToSlice(int slicenumber); //Begins the proccess of displaying the next slice..
	void DeCompressIntoContext();
	void ReCompress();
	void RefreshContext(bool alreadywhite);			//Refreshes
	void UpdateWidgets(); //updates the window title, slider, etc...
	void RefreshWithGreen();
	//base
	void PromptBaseOptions(); //displays the base/fills dialog...
	void PrepareBase(int baselayers, int filledlayers);


	//supports
	void AddSupport(QPoint pos, int size, SupportType type, int fastmode); //creates a new support by startin
	void DeleteAllSupports();

	//undo
	void ClearUndoBuffer();
	void SaveToUndoBuffer();
	void Undo();
	void Redo();

	//clipboard (Only available in image mode!)
	void CopyToClipboard();//copyies the current image into the clipboard.
	void PasteFromClipboard();//pastes from the clipboard, replacing the current slice with the new one, also handling recompression etc..



	//tools
	void SelectPenColor();
    void SelectPenWidth();
	void SetDrawTool(QString tool);
	void SetSupportTool(QString tool);

	//navigation
	void NextSlice();
	void PrevSlice();
	void PgUpSlice(int increment);
	void PgDownSlice(int increment);
	void BaseSlice();
	void TopSlice();

	//Toolbar
	void PopDrawButtons();//uncheckes all drawing buttons
	void SetDrawButtonsEnabled(bool enabled);//set enabled for all drawing buttons
	void ShowDrawButtons(bool show);//hide/shows all drawing buttons
	
	void PopSupportButtons();//uncheckes all support buttons
	void SetSupportButtonsEnabled(bool enabled);//set enabled for all support buttons.
	void ShowSupportButtons(bool show);//hide/shows all support buttons
	
	//widget callbacks
	void on_actionFlood_Fill_activated();
	void on_actionFlood_Void_activated();
	void on_actionWhite_Pen_activated();
	void on_actionBlack_Pen_activated();
	
	void on_actionCircle_activated();
	void on_actionSquare_activated();
	void on_actionTriangle_2_activated();
	void on_actionDiamond_activated();


signals:
	void sliceDirtied(QImage* pNewImg, int slicenumber); //signal to the parent that a image has been edited, sending a pointer to the new image, and the pointer
																//to the CrushedBitmap that needs to be replaced!
protected:
	void keyPressEvent(QKeyEvent * pEvent);		// Handle key Press events
	void keyReleaseEvent(QKeyEvent * pEvent);		// Handle key Release events
	void mouseReleaseEvent(QMouseEvent * pEvent);	// Handle mouse button released events

	

	
	bool bGrid;				// if true, grid is to be drawn
	int m_xOffset, m_yOffset;
	
private:
	
	QImage topImg;
	QImage botImg;

	QTimer greenTimer;

	QList<QImage> imgBackup;//list of images for undo, redo
	int backupIndx;
};

#endif // SliceEditView_H
