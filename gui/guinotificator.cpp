//
// Created by jpyszko on 17.08.2021.
//

#include "guinotificator.h"

GuiNotificator::GuiNotificator(QTableWidget *snailsTable, QTableWidget *plantsTable)
        : snailsTable(snailsTable), plantsTable(plantsTable) {}

void
GuiNotificator::notify(int remainingTime, RandomSet<shared_ptr<Snail>> &snails, RandomSet<shared_ptr<Plant>> &plants) {
    int currentRow = 0;
    for(const auto& elem: snails){
        snailsTable->setRowCount(currentRow + 1);

        snailsTable->setItem(currentRow, 0, new QTableWidgetItem(QString::fromStdString(elem->getName())));
        snailsTable->setItem(currentRow, 1, new QTableWidgetItem(QString::number(elem->getType())));
        snailsTable->setItem(currentRow, 2, new QTableWidgetItem(QString::number(elem->getSize())));
        ++currentRow;
    }
    currentRow = 0;
    for(const auto& elem: plants){
        plantsTable->setRowCount(currentRow + 1);

        plantsTable->setItem(currentRow, 0, new QTableWidgetItem(QString::fromStdString(elem->getName())));
        plantsTable->setItem(currentRow, 1, new QTableWidgetItem(QString::number(elem->getType())));
        plantsTable->setItem(currentRow, 2, new QTableWidgetItem(QString::number(elem->getSize())));
        ++currentRow;
    }
}
