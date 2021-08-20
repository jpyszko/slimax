//
// Created by jpyszko on 20.08.2021.
//

#include "snailscombobox.h"
#include "../model/Snail.h"

SnailsCombobox::SnailsCombobox(QObject *parent) : TableCombobox(parent) {

}

QWidget *
SnailsCombobox::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    auto *comboBox = new QComboBox(parent);
    comboBox->addItem(QString::fromStdString(Snail::typeToString(SnailType::ROMAN_SNAIL)));
    comboBox->addItem(QString::fromStdString(Snail::typeToString(SnailType::TURKISH_SNAIL)));
    comboBox->addItem(QString::fromStdString(Snail::typeToString(SnailType::GARDEN_SNAIL)));
    return comboBox;
}
