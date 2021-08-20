//
// Created by jpyszko on 20.08.2021.
//

#ifndef SLIMAX_PLANTSCOMBOBOX_H
#define SLIMAX_PLANTSCOMBOBOX_H


#include "tablecombobox.h"
#include "../model/Plant.h"

class PlantsCombobox : public TableCombobox{

    Q_OBJECT

public:
    PlantsCombobox(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};


#endif //SLIMAX_PLANTSCOMBOBOX_H
