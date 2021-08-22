//
// Created by jpyszko on 16.08.2021.
//
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "guinotificator.h"
#include "worker.h"
#include "editwindow.h"
#include <QIdentityProxyModel>
#include <QThread>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->runSimulation->setEnabled(false);
    ui->action_Modyfikuj->setEnabled(false);
    initTable(ui->snailsTable);
    initTable(ui->plantsTable);
    notificator = make_shared<GuiNotificator>(ui);
    runner = new SimulationRunner(notificator);

}

MainWindow::~MainWindow() {
    delete ui;
    delete runner;
}

void MainWindow::on_runSimulation_clicked() {

    QThread *thread = new QThread(this);
    Worker *worker = new Worker(runner, simulation, ui);
    worker->moveToThread(thread);
    connect(thread, &QThread::started, worker, &Worker::process);
    connect(worker, &Worker::finished, thread, &QThread::quit);
    connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    connect(worker, &Worker::showResult, this, &MainWindow::showResult);
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

void MainWindow::showResult(SimulationResult result) {

    QMessageBox msgBox;
    msgBox.setStyleSheet("QLabel{min-width: 200px;}");
    msgBox.setText(QString::fromStdString("<p align='center'>" + translateResult(result) + "</p> "));
    msgBox.exec();
}

std::string MainWindow::translateResult(SimulationResult result) {
    switch (result) {
        case SNAILS_WINS:
            return "Slimaki wygrywają!";
        case PLANTS_WINS:
            return "Rośliny wygrywają!";
        case DRAW:
            return "Remis!";
        default:
            return "Nie ustalono wyniku";
    }
}

void MainWindow::on_action_Nowa_triggered()
{
    EditWindow *edit = new EditWindow(this);
    connect(edit, &EditWindow::loadSimulation, this, &MainWindow::loadSimulation);
    edit->open();
}

void MainWindow::on_action_Modyfikuj_triggered() {

    EditWindow *edit = new EditWindow(simulation, this);
    connect(edit, &EditWindow::loadSimulation, this, &MainWindow::loadSimulation);
    edit->open();
}

void MainWindow::loadSimulation(shared_ptr<SimulationBuilder> builder) {

    runner->load(*builder);
    notificator->notify(builder->getDuration(), builder->getSnails(), builder->getPlants());
    ui->aquariumValue->setText(QString::number(builder->getAquariumLength() * builder->getAquariumWeight()));
    simulation = builder;
    ui->runSimulation->setEnabled(true);
    ui->action_Modyfikuj->setEnabled(true);
}
