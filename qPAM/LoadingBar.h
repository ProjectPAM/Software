/*
 *  LoadingBar.h
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

#ifndef LOADINGBAR_H
#define LOADINGBAR_H

#include <QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>


class LoadingBar : public QDialog
{
	Q_OBJECT

public:
    LoadingBar();
    LoadingBar(int min, int max, bool autoshow = true);
	~LoadingBar();

public slots:
	void setMax(int max);
	void setMin(int min);
	void setValue(int val);
	void setDescription(QString str);
    void setProgress(qint64 fraction, qint64 total);
    void useCancelButton(bool use);
	int GetValue();

private:
    void SetupUI(bool autoshow);
	void SetupConnections();
	QHBoxLayout* horizontalLayout;
	QProgressBar* progressBar;
	QPushButton* cancelButton;
};
#endif
