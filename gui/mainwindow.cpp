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
#include <QFileDialog>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->runSimulation->setEnabled(false);
    ui->action_Modyfikuj->setEnabled(false);
    ui->action_Zapisz->setEnabled(false);
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

void MainWindow::on_action_Nowa_triggered() {
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
    ui->action_Zapisz->setEnabled(true);
}

void MainWindow::on_action_Zapisz_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Zapisz Symulację", "",
                                                    "Symulacja (*.sim);;Wszystkie pliki (*)");
    if (fileName.isEmpty()) {
        return;
    } else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_6_0);
        SimulationBuilder &builder = *simulation;
        out << builder;
    }
}

void MainWindow::on_action_Otworz_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Otwórz Symulację", "",
                                                    "Symulacja (*.sim);;All Files (*)");
    if (fileName.isEmpty())
    {
        return;
    }
    else {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, "Unable to open file",
                                     file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_6_0);
        simulation = make_shared<SimulationBuilder>();
        SimulationBuilder &builder = *simulation;
        in >> builder;
        loadSimulation(simulation);
    }
}
