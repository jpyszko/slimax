//
// Created by jpyszko on 20.08.2021.
//

#include "plantscombobox.h"
#include "../model/Plant.h"

PlantsCombobox::PlantsCombobox(QObject *parent) : TableCombobox(parent) {

}

QWidget *
PlantsCombobox::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    auto * comboBox = new QComboBox(parent);
    comboBox->addItem(QString::fromStdString(Plant::typeToString(PlantType::LETTUCE)));
    comboBox->addItem(QString::fromStdString(Plant::typeToString(PlantType::GRASS)));
    comboBox->addItem(QString::fromStdString(Plant::typeToString(PlantType::CARROT)));
    return comboBox;
}
