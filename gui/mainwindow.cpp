//
// Created by jpyszko on 16.08.2021.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "guinotificator.h"
#include "worker.h"
#include <QIdentityProxyModel>
#include <QThread>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    initTable(ui->snailsTable);
    initTable(ui->plantsTable);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_runSimulation_clicked() {

    QThread *thread = new QThread();
    Worker *worker = new Worker(ui->snailsTable, ui->plantsTable);
    worker->moveToThread(thread);
    connect(thread, &QThread::started, worker, &Worker::process);
    connect(worker, &Worker::finished, thread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    thread->start();
}

void MainWindow::initTable(QTableWidget *table) {
    table->setColumnCount(3);
    table->setShowGrid(true);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->horizontalHeader()->resizeSection(0, 130);
    table->horizontalHeader()->resizeSection(1, 130);
    table->horizontalHeader()->setStretchLastSection(true);
    QStringList labels = {"Nazwa", "Typ", "Aktualny rozmar"};
    table->setHorizontalHeaderLabels(labels);
}
