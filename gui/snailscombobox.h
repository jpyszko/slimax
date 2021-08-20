//
// Created by jpyszko on 20.08.2021.
//

#ifndef SLIMAX_SNAILSCOMBOBOX_H
#define SLIMAX_SNAILSCOMBOBOX_H


#include "tablecombobox.h"

class SnailsCombobox : public TableCombobox{

    Q_OBJECT

public:
    SnailsCombobox(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};


#endif //SLIMAX_SNAILSCOMBOBOX_H
