//
// Created by jpyszko on 09.03.2021.
//

#include <QApplication>
#include "gui/mainwindow.h"

/*!
 * Głowna funkcja (startowa) programu
 * @param argc - liczba parametrów podanych podczas uruchomienia programu
 * @param argv - tablica wartośći parametrów podanych podczas uruchomienia programu
 * @return wartosc 0 w przypadku prawidlowego wykonania programu, w przeciwnym wypadku kod blędu
 */
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
