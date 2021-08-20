//
// Created by jpyszko on 19.08.2021.
//

#ifndef SLIMAX_TABLECOMBOBOX_H
#define SLIMAX_TABLECOMBOBOX_H


#include <QStyledItemDelegate>
#include <QComboBox>

class TableCombobox : public QStyledItemDelegate {

    Q_OBJECT

public:
    TableCombobox(QObject *parent = nullptr);

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    virtual ~TableCombobox() = 0;

};


#endif //SLIMAX_TABLECOMBOBOX_H
