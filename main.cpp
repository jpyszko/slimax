#include <iostream>
#include <QApplication>
#include "engine/SimulationBuilder.h"
#include "engine/SimulationRunner.h"
#include "console/ConsoleNotificator.h"
#include "gui/mainwindow.h"
#include "gui/editwindow.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
