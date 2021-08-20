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

private:
    Ui::MainWindow *ui;

    void initTable(QTableWidget *table);

    std::string translateResult(SimulationResult result);
};

#endif // MAINWINDOW_H
