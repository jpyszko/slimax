//
// Created by jpyszko on 17.08.2021.
//

#include "worker.h"
#include "../engine/SimulationBuilder.h"
#include "../engine/Notificator.h"
#include "guinotificator.h"
#include "../engine/SimulationRunner.h"

Worker::Worker(SimulationRunner *runner, shared_ptr<SimulationBuilder> simulation, Ui::MainWindow *mainWindow)
        : runner(runner), simulation(simulation), window(mainWindow) {}

void Worker::process() {
    runner->load(*simulation);
    SimulationResult result = runner->run();
    emit showResult(result);
    emit finished();
}
