//
// Created by jpyszko on 17.08.2021.
//

#ifndef SLIMAX_WORKER_H
#define SLIMAX_WORKER_H


#include <QObject>
#include "../engine/SimulationRunner.h"
#include "ui_mainwindow.h"

class Worker : public QObject {
Q_OBJECT
public:
    explicit Worker(Ui::MainWindow *mainWindow);

public slots:

    void process();

signals:

    void finished();

    void showResult(SimulationResult result);

private:
    Ui::MainWindow *window;;
};


#endif //SLIMAX_WORKER_H
