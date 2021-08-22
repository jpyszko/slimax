//
// Created by jpyszko on 17.08.2021.
//

#include "guinotificator.h"
#include "../engine/EngineUtils.h"

GuiNotificator::GuiNotificator(Ui::MainWindow *mainWindow) : window(mainWindow) {}

void
GuiNotificator::notify(int remainingTime, RandomSet<shared_ptr<Snail>> &snails, RandomSet<shared_ptr<Plant>> &plants) {
    window->remainingTimeValue->setText(QString::number(remainingTime));
    window->totalSnailsValue->setText(QString::number(EngineUtils::countSnailsArea(snails)));
    window->totalPlantsValue->setText(QString::number(EngineUtils::countPlantsArea(plants)));
    int currentRow = 0;
    for (const auto &elem: snails) {
        window->snailsTable->setRowCount(currentRow + 1);

        window->snailsTable->setItem(currentRow, 0, new QTableWidgetItem(QString::fromStdString(elem->getName())));
        window->snailsTable->setItem(currentRow, 1, new QTableWidgetItem(QString::fromStdString(Snail::typeToString(elem->getType()))));
        window->snailsTable->setItem(currentRow, 2, new QTableWidgetItem(QString::number(elem->getSize())));
        ++currentRow;
    }
    currentRow = 0;
    for (const auto &elem: plants) {
        window->plantsTable->setRowCount(currentRow + 1);

        window->plantsTable->setItem(currentRow, 0, new QTableWidgetItem(QString::fromStdString(elem->getName())));
        window->plantsTable->setItem(currentRow, 1, new QTableWidgetItem(QString::fromStdString(Plant::typeToString(elem->getType()))));
        window->plantsTable->setItem(currentRow, 2, new QTableWidgetItem(QString::number(elem->getSize())));
        ++currentRow;
    }
}