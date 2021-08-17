//
// Created by jpyszko on 17.08.2021.
//

#ifndef SLIMAX_WORKER_H
#define SLIMAX_WORKER_H


#include <QObject>
#include <QTableWidget>

class Worker : public QObject {
Q_OBJECT
public:
    Worker(QTableWidget *snailsTable, QTableWidget *plantsTable);

    ~Worker();

public slots:

    void process();

signals:

    void finished();

    void error(QString err);

private:
    QTableWidget* snailsTable;
    QTableWidget* plantsTable;
};


#endif //SLIMAX_WORKER_H
