//
// Created by jpyszko on 19.08.2021.
//

#include "tablecombobox.h"

TableCombobox::TableCombobox(QObject *parent) : QStyledItemDelegate(parent) {

}

void TableCombobox::setEditorData(QWidget *editor, const QModelIndex &index) const {
    auto *comboBox = dynamic_cast<QComboBox*>(editor);
    const QString currentText = index.data(Qt::EditRole).toString();
    const int cbIndex = comboBox->findText(currentText);
    if (cbIndex >= 0){
        comboBox->setCurrentIndex(cbIndex);
    }
}

void TableCombobox::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    model->setData(index, comboBox->currentText(), Qt::EditRole);
}

TableCombobox::~TableCombobox(){

}
