//
// Created by jpyszo on 17.08.2021.
//

#ifndef SLIMAX_GUINOTIFICATOR_H
#define SLIMAX_GUINOTIFICATOR_H


#include <QTableWidget>
#include "../engine/Notificator.h"

class GuiNotificator : public Notificator{

private:
    QTableWidget* snailsTable;
    QTableWidget* plantsTable;

public:
    GuiNotificator(QTableWidget *snailsTable, QTableWidget *plantsTable);

    void notify(int remainingTime, RandomSet<shared_ptr<Snail>> &snails, RandomSet<shared_ptr<Plant>> &plants) override;

};


#endif //SLIMAX_GUINOTIFICATOR_H
