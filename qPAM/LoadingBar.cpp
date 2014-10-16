/*
 *  LoadingBar.cpp
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

#include "LoadingBar.h"

////////////////////////////////////////
//Public
/////////////////////////////////////
LoadingBar::LoadingBar() : QDialog(NULL)
{
    SetupUI(true);
	SetupConnections();
}
LoadingBar::LoadingBar(int min, int max, bool autoshow) : QDialog(NULL)
{
    SetupUI(autoshow);
	setMax(max);
	setMin(min);
	SetupConnections();
}
LoadingBar::~LoadingBar()
{
}
///////////////////////////////////////
//Public Slots
//////////////////////////////////////
void LoadingBar::setProgress(qint64 fraction, qint64 total)
{
    progressBar->setMaximum(total);
    progressBar->setValue(fraction);
}

void LoadingBar::setMax(int max)
{
	progressBar->setMaximum(max);
}
void LoadingBar::setMin(int min)
{
	progressBar->setMinimum(min);
}
void LoadingBar::setValue(int val)
{
	progressBar->setValue(val);
}
void LoadingBar::setDescription(QString str)
{
	this->setWindowTitle(str);
}
void LoadingBar::useCancelButton(bool use)
{
    if(!use)
    {
        //if(horizontalLayout->findChild<QPushButton *>("pushButton"))
            horizontalLayout->removeWidget(cancelButton);
            cancelButton->hide();
    }
    else
    {
        //if(!horizontalLayout->findChild<QPushButton *>("pushButton"))
            horizontalLayout->addWidget(cancelButton);
            cancelButton->show();
    }
}

int LoadingBar::GetValue()
{
	return progressBar->value();
}

///////////////////////////////////
//Private
////////////////////////////////////
void LoadingBar::SetupUI(bool autoshow)
{
    setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint);
	resize(364, 41);
	this->setMaximumHeight(41);
	 
	horizontalLayout = new QHBoxLayout(this);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    progressBar = new QProgressBar(this);
    progressBar->setObjectName(QString::fromUtf8("progressBar"));
    progressBar->setValue(24);

    horizontalLayout->addWidget(progressBar);

    cancelButton = new QPushButton(this);
    cancelButton->setObjectName(QString::fromUtf8("pushButton"));
	cancelButton->setText("Cancel");

    horizontalLayout->addWidget(cancelButton);


	setModal(true);
    if(autoshow)
        show();//auto show when created!
}
	

void LoadingBar::SetupConnections()
{
	QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}
