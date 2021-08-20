//
// Created by yaspe on 19.08.2021.
//

#ifndef SLIMAX_TABLECOMBOBOX_H
#define SLIMAX_TABLECOMBOBOX_H


#include <QStyledItemDelegate>

class TableCombobox : public QStyledItemDelegate {

    Q_OBJECT

public:
    TableCombobox(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

};


#endif //SLIMAX_TABLECOMBOBOX_H
