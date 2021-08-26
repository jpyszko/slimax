//
// Created by jpyszko on 19.08.2021.
//
#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <QComboBox>
#include "tablecombobox.h"
#include "../engine/simulationbuilder.h"
#include "../engine/validationexception.h"

namespace Ui {
class EditWindow;
}

/*!
 * Klasa określająca zachowanie okna dodawania nowej i edycji symulacji
 */
class EditWindow : public QDialog
{
    Q_OBJECT

public:

    /*!
     * Konstruktor tworzący klasę z pustym modelem symulacji. Wykorzystywany do utorzenia okna dodawania nowej symulacji.
     * @param parent - obiekt rodzica wzgledem okna dodawania nowej symulacji
     */
    explicit EditWindow(QWidget *parent = nullptr);

    /*!
     * Konstruktor tworzący klasę z modelem symulacji przekazanym w parametrze. Wykorzystywany
     * do utworzenia okna edycji.
     * @param simulation - symulacja do edycji
     * @param parent - obiekt rodzica wzgledem okna edycji
     */
    explicit EditWindow(shared_ptr<SimulationBuilder> simulation, QWidget *parent = nullptr);

    /*!
     * Destrkutor klasy
     */
    ~EditWindow();

private slots:
    /*!
     * Slot Qt reagujacy na wcisnięcie przycisku "Dodaj" obok tabeli ślimaków.
     * Dodaje nowy wiersz do wypelnienia danych ślimaka.
     */
    void on_addSnailButton_clicked();

    /*!
     * Slot Qt reagujący na wciśnięcie przycisku "Usuń" obok tabeli ślimaków.
     * Usuwa zanaczonego ślimaka z tabeli.
     */
    void on_removeSnailButton_clicked();

    /*!
     * Slot Qt reagujący na wciśnięcie przycisku "Dodaj" obok tabeli roślin.
     * Dodaje nowy wiersz do wypelnienia danych nowej rośliny.
     */
    void on_addPlantButton_clicked();

    /*!
     * Slot Qt reagujący na wciśnięcie przycisku "Usuń" obok tabeli roślin.
     * Usuwa zanaczoną roślinę z tabeli.
     */
    void on_removePlantButton_clicked();

    /*!
     * Slot Qt reagujący na wciśniecie przycisku OK. Odpowiedzialny za zebranie danych z elementów graficznych,
     * umieszczenie ich w obiekcie SimulationBuilder i wysłanie do głownego okna aplikacji. Odpowiedzialny również
     * za tłumaczenie blędów walidacji zgłaszanych przez SimulationBuilder.
     */
    void on_buttonBox_accepted();

signals:

    /*!
     * Sygnał Qt emitowany w celu przekazania danych symulacji do głownego okna.
     * @param builder - przekazywany obiekt budowniczego z danymi symulacji
     */
    void loadSimulation(shared_ptr<SimulationBuilder> builder);

private:

    Ui::EditWindow *ui;

    void initTable(QTableWidget *table);

    QString getNullableString(QTableWidgetItem* item);

    int getNullableSize(QTableWidgetItem* item);

    QString getErrorContent(ExceptionType type);

};

#endif // EDITWINDOW_H
