//
// Created by jpyszko on 19.08.2021.
//
#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <QComboBox>
#include "tablecombobox.h"
#include "../engine/SimulationBuilder.h"

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr);
    explicit EditWindow(shared_ptr<SimulationBuilder> simulation, QWidget *parent = nullptr);
    ~EditWindow();

private slots:
    void on_addSnailButton_clicked();

    void on_removeSnailButton_clicked();

    void on_addPlantButton_clicked();

    void on_removePlantButton_clicked();

    void on_buttonBox_accepted();

    signals:

    void loadSimulation(shared_ptr<SimulationBuilder> builder);

private:
    Ui::EditWindow *ui;

    void initTable(QTableWidget *table);

    QString getNullableString(QTableWidgetItem* item);

    int getNullableSize(QTableWidgetItem* item);

};

#endif // EDITWINDOW_H
