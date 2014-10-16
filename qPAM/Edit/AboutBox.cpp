/*
 *  AboutBox.cpp
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

#include "AboutBox.h"
#include "ui_AboutBox.h"

aboutbox::aboutbox(QWidget *parent, Qt::WFlags flags) :
    QWidget(parent, flags),
    ui(new Ui::aboutbox)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog| Qt::WindowTitleHint);


}

aboutbox::~aboutbox()
{
    delete ui;
}




void aboutbox::setText(QString content)
{

    ui->textBrowser->setText(content);

}
