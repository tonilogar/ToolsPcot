//    ToolsPcot
//    Copyright (C) {2014}  {Antonio López García}
//    tologar@gmail.com

//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "signopasadadelegate.h"

SignoPasadaDelegate::SignoPasadaDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

QWidget *SignoPasadaDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    QComboBox *editor=new QComboBox(parent);
    editor->addItem(tr("No seleccionado")); //Ocupa el indice 0
    editor->addItem(tr("Negativa"));        //Ocupa el indice 1
    editor->addItem(tr("Positiva"));        //Ocupa el indice 2

    return editor;
}

void SignoPasadaDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox=static_cast<QComboBox*>(editor);

    uint valor=index.data(Qt::EditRole).toUInt();

    comboBox->setCurrentIndex(valor);
}

void SignoPasadaDelegate::setModelData(QWidget *editor,QAbstractItemModel *model,
                                       const QModelIndex &index) const
{
    QComboBox *comboBox=static_cast<QComboBox*>(editor);
    model->setData(index,comboBox->currentIndex(),Qt::EditRole);
}

void SignoPasadaDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option,const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
    QComboBox *comboBox=static_cast<QComboBox*>(editor);
    comboBox->showPopup();
}
