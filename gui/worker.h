//
// Created by jpyszko on 17.08.2021.
//

#ifndef SLIMAX_WORKER_H
#define SLIMAX_WORKER_H


#include <QObject>
#include "../engine/simulationrunner.h"
#include "ui_mainwindow.h"

/*!
 * Wrapper dla kodu biznesowego symulacji. Aby zapewnić responsywność GUI aplikacji podczas wykonywania symulacji,
 * symulacja uruchamiana jest w osobnym wątku. Poniższa klasa stanowi wrapper dla tego kodu i jest zarządzana przez Qt.
 */
class Worker : public QObject {

    Q_OBJECT

public:
    /*!
     * Konstruktor klasy wrappera
     * @param runner - obiekt klasy zawierającej logikę biznesową
     * @param simulation - obiekt SimulationBuilder, w którym zapisane są dane symulacji do wykonania
     * @param mainWindow - obiekt okna Qt, którego elementy będą odswieżane podczas symulacji
     */
    explicit Worker(SimulationRunner *runner, shared_ptr<SimulationBuilder> simulation, Ui::MainWindow *mainWindow);

public slots:

    /*!
     * Metoda uruchamiana przez Qt jako głowna metoda wątku. Po załądowaniu wszystkich
     * w konstruktorze wykonywana jest w niej symlacja.
     */
    void process();

signals:

    /*!
     * Sygnał Qt emitowany po zakończeniu wykonywania metody process.
     */
    void finished();

    /*!
     * Sygnał Qt emitowany po zakończeniu symulacji wewnątrz klasy Worker. Pozwala na przekazanie wyniku
     * symulacji na zewnątrz wątku.
     * @param result - wynik symulacji przekazywany na zewnątrz
     */
    void showResult(SimulationResult result);

private:
    Ui::MainWindow *window;
    SimulationRunner *runner;
    shared_ptr<SimulationBuilder> simulation;
};


#endif //SLIMAX_WORKER_H
