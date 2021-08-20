//
// Created by jpyszko on 20.08.2021.
//

#ifndef SLIMAX_TABLESPINBOX_H
#define SLIMAX_TABLESPINBOX_H


#include <QStyledItemDelegate>

class TableSpinbox : public QStyledItemDelegate {

    Q_OBJECT

public:

    TableSpinbox(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

};


#endif //SLIMAX_TABLESPINBOX_H
