//
// Created by jpyszo on 17.08.2021.
//

#ifndef SLIMAX_GUINOTIFICATOR_H
#define SLIMAX_GUINOTIFICATOR_H

#include "../engine/Notificator.h"
#include "ui_mainwindow.h"

class GuiNotificator : public Notificator{

private:
    Ui::MainWindow *window;

public:
    explicit GuiNotificator(Ui::MainWindow *mainWindow);

    void notify(int remainingTime, RandomSet<shared_ptr<Snail>> &snails, RandomSet<shared_ptr<Plant>> &plants) override;

private slots:
    void on_action_O_programie_triggered();
};


#endif //SLIMAX_GUINOTIFICATOR_H
