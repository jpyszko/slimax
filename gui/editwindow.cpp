//
// Created by jpyszko on 19.08.2021.
//

#include <QComboBox>
#include "editwindow.h"
#include "ui_editwindow.h"
#include "tablecombobox.h"

EditWindow::EditWindow(QWidget *parent) : QDialog(parent), ui(new Ui::EditWindow) {
    ui->setupUi(this);
    ui->snailsButtonsLayout->setAlignment(Qt::AlignTop);
    ui->plantsButtonsLayout->setAlignment(Qt::AlignTop);
    initTable(ui->snailsTable);
    initTable(ui->plantsTable);
    ui->removeSnailButton->setEnabled(false);
    ui->removePlantButton->setEnabled(false);

}

EditWindow::~EditWindow() {
    delete ui;
}

void EditWindow::initTable(QTableWidget *table) {
    table->setColumnCount(3);
    table->setShowGrid(true);
    table->horizontalHeader()->resizeSection(0, 250);
    table->horizontalHeader()->resizeSection(1, 130);
    table->horizontalHeader()->setStretchLastSection(true);
    QStringList labels = {"Nazwa", "Typ", "Aktualny rozmar"};
    table->setHorizontalHeaderLabels(labels);
    TableCombobox* tableCombobox = new TableCombobox();
    table->setItemDelegateForColumn(1,tableCombobox);
}

void EditWindow::on_addSnailButton_clicked() {
    ui->snailsTable->insertRow(ui->snailsTable->rowCount());
    if (!ui->removeSnailButton->isEnabled()) {
        ui->removeSnailButton->setEnabled(true);
    }
}

void EditWindow::on_removeSnailButton_clicked() {
    ui->snailsTable->removeRow(ui->snailsTable->currentRow());
    if (ui->snailsTable->rowCount() < 1) {
        ui->removeSnailButton->setEnabled(false);
    }

}

void EditWindow::on_addPlantButton_clicked() {
    ui->plantsTable->insertRow(ui->plantsTable->rowCount());
    if (!ui->removePlantButton->isEnabled()) {
        ui->removePlantButton->setEnabled(true);
    }

}

void EditWindow::on_removePlantButton_clicked() {
    ui->plantsTable->removeRow(ui->plantsTable->currentRow());
    if (ui->plantsTable->rowCount() < 1) {
        ui->removePlantButton->setEnabled(false);
    }
}

void EditWindow::on_buttonBox_accepted()
{
    for(int rowNumber = 0 ; rowNumber<ui->snailsTable->rowCount();rowNumber++){
        QTableWidgetItem *pItem1 = ui->snailsTable->item(rowNumber, 0);
//        const QString &string = pItem1->data(Qt::EditRole).toString();
        QTableWidgetItem *pItem2 = ui->snailsTable->item(rowNumber, 1);
        int i = pItem2->data(Qt::EditRole).toInt();
        QTableWidgetItem *pItem3 = ui->snailsTable->item(rowNumber, 2);

    }
}
