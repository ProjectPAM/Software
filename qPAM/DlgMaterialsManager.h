/*
 *  DlgMaterialsManager.h
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

#ifndef DLGMATERIALSMANAGER_H
#define DLGMATERIALSMANAGER_H

#include <QDialog>
#include <QStyledItemDelegate>
#include "MatCat.h"


class MaterialsTableItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    MaterialsTableItemDelegate(QObject *parent = 0);
    ~MaterialsTableItemDelegate();

    virtual QWidget *createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const;
    virtual void setModelData ( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const;
};


namespace Ui {
    class DlgMaterialsManager;
}

class DlgMaterialsManager : public QDialog
{
    Q_OBJECT

public:
    explicit DlgMaterialsManager(B9MatCat *pCatalog, QWidget *parent = 0);
    ~DlgMaterialsManager();

public slots:

    void setXY(int iXY){fillData(m_pCatalog->getCurMatIndex(),iXY);}

private slots:

    void on_comboBoxMaterial_currentIndexChanged(int index);

    void on_comboBoxXY_currentIndexChanged(int index);

    void on_pushButtonDelete_clicked();

    void on_pushButtonAdd_clicked();

    void on_buttonBoxSaveCancel_accepted();

    void on_pushButtonDuplicate_clicked();

    void on_buttonBoxSaveCancel_rejected();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_spinBoxNumberOfAttachLayers_valueChanged(int arg1);

private:
    Ui::DlgMaterialsManager *ui;
    void setUp();
    void fillData(int iMatIndex, int iXYIndex);
    void stuffData();
    void updateEnabledStates();
    void addMaterial(int iMatIndex);
    void removeMaterial(int iMatIndex);
    B9MatCat* m_pCatalog;
    bool m_bLoading;
};

#endif // DLGMATERIALSMANAGER_H
