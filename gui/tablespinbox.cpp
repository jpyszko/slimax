//
// Created by jpyszko on 20.08.2021.
//

#include <QSpinBox>
#include "tablespinbox.h"

TableSpinbox::TableSpinbox(QObject *parent) : QStyledItemDelegate(parent) {

}

QWidget *
TableSpinbox::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    auto *editor = new QSpinBox(parent);
    editor->setFrame(false);
    editor->setMinimum(0);
    editor->setMaximum(1000000000);

    return editor;
}

void TableSpinbox::setEditorData(QWidget *editor, const QModelIndex &index) const {
    int value = index.model()->data(index, Qt::EditRole).toInt();
    auto *spinBox = dynamic_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

void TableSpinbox::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    auto *spinBox = dynamic_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData(index, value, Qt::EditRole);
}
