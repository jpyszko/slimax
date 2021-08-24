//
// Created by jpyszko on 16.08.2021.
//
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "../engine/SimulationRunner.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_runSimulation_clicked();

    void showResult(SimulationResult result);

    void on_action_Nowa_triggered();

    void on_action_Modyfikuj_triggered();

    void loadSimulation(shared_ptr<SimulationBuilder> builder);

    void on_action_Zapisz_triggered();

    void on_action_Otworz_triggered();

private:
    Ui::MainWindow *ui;

    SimulationRunner *runner;

    shared_ptr<Notificator> notificator;

    shared_ptr<SimulationBuilder> simulation;

    void initTable(QTableWidget *table);

    std::string translateResult(SimulationResult result);
};

#endif // MAINWINDOW_H
