//
// Created by jpyszko on 16.08.2021.
//

#ifndef SLIMAX_MAINWINDOW_H
#define SLIMAX_MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;


};


#endif //SLIMAX_MAINWINDOW_H
