//
// Created by jpyszko on 19.08.2021.
//
#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include <QTableWidget>

namespace Ui {
class EditWindow;
}

class EditWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditWindow(QWidget *parent = nullptr);
    ~EditWindow();

private slots:
    void on_addSnailButton_clicked();

    void on_removeSnailButton_clicked();

    void on_addPlantButton_clicked();

    void on_removePlantButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::EditWindow *ui;

    void initTable(QTableWidget *table);
};

#endif // EDITWINDOW_H
