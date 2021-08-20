//
// Created by yaspe on 19.08.2021.
//

#include <QComboBox>
#include "tablecombobox.h"
#include "../model/Snail.h"


TableCombobox::TableCombobox(QObject *parent)  : QStyledItemDelegate(parent) {

}

QWidget *
TableCombobox::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    auto *editor = new QComboBox(parent);
    editor->addItem(QString::fromStdString(Snail::typeToString(SnailType::ROMAN_SNAIL)));
    editor->addItem(QString::fromStdString(Snail::typeToString(SnailType::TURKISH_SNAIL)));
    editor->addItem(QString::fromStdString(Snail::typeToString(SnailType::GARDEN_SNAIL)));

    return editor;
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
