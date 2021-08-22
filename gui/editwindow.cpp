//
// Created by jpyszko on 19.08.2021.
//

#include <QMessageBox>
#include "editwindow.h"
#include "ui_editwindow.h"
#include "../model/Snail.h"
#include "snailscombobox.h"
#include "plantscombobox.h"
#include "tablespinbox.h"
#include "../engine/SimulationBuilder.h"
#include "../engine/ValidationException.h"

EditWindow::EditWindow(QWidget *parent) : QDialog(parent), ui(new Ui::EditWindow) {
    ui->setupUi(this);
    ui->snailsButtonsLayout->setAlignment(Qt::AlignTop);
    ui->plantsButtonsLayout->setAlignment(Qt::AlignTop);
    initTable(ui->snailsTable);
    initTable(ui->plantsTable);
    auto snailCombobox = new SnailsCombobox(ui->snailsTable);
    ui->snailsTable->setItemDelegateForColumn(1, snailCombobox);
    auto plantsCombobox = new PlantsCombobox(ui->plantsTable);
    ui->plantsTable->setItemDelegateForColumn(1, plantsCombobox);
    ui->removeSnailButton->setEnabled(false);
    ui->removePlantButton->setEnabled(false);

}

EditWindow::EditWindow(shared_ptr<SimulationBuilder> simulation, QWidget *parent) : EditWindow(parent) {
    ui->durationValue->setValue(simulation->getDuration());
    ui->aquariumWeightValue->setValue(simulation->getAquariumWeight());
    ui->aquariumLengthValue->setValue(simulation->getAquariumLength());
    for (auto snail: simulation->getSnails()){
        int currentRow = ui->snailsTable->rowCount();
        ui->snailsTable->setRowCount(currentRow + 1);

        ui->snailsTable->setItem(currentRow, 0, new QTableWidgetItem(QString::fromStdString(snail->getName())));
        ui->snailsTable->setItem(currentRow, 1, new QTableWidgetItem(QString::fromStdString(Snail::typeToString(snail->getType()))));
        ui->snailsTable->setItem(currentRow, 2, new QTableWidgetItem(QString::number(snail->getSize())));
    }
    for (auto plant: simulation->getPlants()){
        int currentRow = ui->plantsTable->rowCount();
        ui->plantsTable->setRowCount(currentRow + 1);

        ui->plantsTable->setItem(currentRow, 0, new QTableWidgetItem(QString::fromStdString(plant->getName())));
        ui->plantsTable->setItem(currentRow, 1, new QTableWidgetItem(QString::fromStdString(Plant::typeToString(plant->getType()))));
        ui->plantsTable->setItem(currentRow, 2, new QTableWidgetItem(QString::number(plant->getSize())));
    }
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
    auto initSizeSpinbox = new TableSpinbox(table);
    table->setItemDelegateForColumn(2, initSizeSpinbox);
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
    try{
        shared_ptr<SimulationBuilder> builder = make_unique<SimulationBuilder>();
        builder->simulation(ui->durationValue->value(), ui->aquariumWeightValue->value(), ui->aquariumLengthValue->value());
        for(int rowNumber = 0 ; rowNumber<ui->snailsTable->rowCount();rowNumber++){
            const QString &name = getNullableString(ui->snailsTable->item(rowNumber, 0));
            const QString &type = getNullableString(ui->snailsTable->item(rowNumber, 1));
            int size = getNullableSize(ui->snailsTable->item(rowNumber,2));
            builder->addSnail(name.toStdString(), Snail::stringToType(type.toStdString()), size);
        }
        for(int rowNumber = 0 ; rowNumber<ui->plantsTable->rowCount();rowNumber++){
            const QString &name = getNullableString(ui->plantsTable->item(rowNumber, 0));
            const QString &type = getNullableString(ui->plantsTable->item(rowNumber, 1));
            int size = getNullableSize(ui->plantsTable->item(rowNumber,2));
            builder->addPlant(name.toStdString(), Plant::stringToType(type.toStdString()), size);
        }
        emit loadSimulation(builder);
        emit accept();
    } catch (ValidationException exception){
        QMessageBox msgBox;
        msgBox.setStyleSheet("QLabel{min-width: 200px;}");
        msgBox.setText(QString::fromStdString(exception.what()));
        msgBox.exec();
    }


}

QString EditWindow::getNullableString(QTableWidgetItem* item) {
    if(item){
        return item->text();
    }

    return {};
}

int EditWindow::getNullableSize(QTableWidgetItem *item) {
    if(item){
        return item->data(Qt::EditRole).toInt();
    }

    return 0;
}
