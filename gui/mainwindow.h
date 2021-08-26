//
// Created by jpyszko on 16.08.2021.
//
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "../engine/simulationrunner.h"

namespace Ui {
    class MainWindow;
}

/*!
 * Klasa określająca zachowanie głownego okna aplikacji widocznego po jej uruchomieniu.
 */
class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    /*!
     * Konstruktor tworzący klasę
     * @param parent - obiekt rodzica dla klasy okna, w przypadku okna głownego brak rodziców
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /*!
     * Destruktor klasy głownego okna
     */
    ~MainWindow();

private slots:

    /*!
     * Slot Qt uruchamiany po nacisnięciu przycisku uruchomienia symulacji. W ramach uruchomienia tworzony
     * jest nowy wątek a kod symulacji uruchamiany w wraperze Worker
     */
    void on_runSimulation_clicked();

    /*!
     * Slot Qt połaczony z sygnałem klasy Worker. Odpowiedzialny jest za wyświetlenie rezultatu symulacji
     * odebranego z klasy Worker wykonywanej w wątku.
     * @param result - przekazany rezultat symulacji do wyświetlenia
     */
    void showResult(SimulationResult result);

    /*!
     * Slot Qt uruchamiany po wybraniu z menu Symulacja->Nowa. Odpowiedzialny za przygotowanie
     * i wyświetlenie okna dodawania nowej symulacji.
     */
    void on_action_Nowa_triggered();

    /*!
     * Slot Qt uruchamiany po wybraniu z menu Symulacja->Modyfikuj. Odpowiedzialny za przygotowanie
     * i wyświetlenie okna edycji aktualnej symulacji.
     */
    void on_action_Modyfikuj_triggered();

    /*!
     * Slot QT uruchamiany przez okno dodawania nowej symulacji i edycji symlacji (klasa EditWindow).
     * Odpowiedzialny jest za ustawienie przechowywanej wartości oraz wyświetlenie danych w głownym oknie aplikacji.
     * @param builder - obiekt buildera zawierjący początkowe dane symulacji.
     */
    void loadSimulation(shared_ptr<SimulationBuilder> builder);

    /*!
     * Slot Qt uruchamiany po wybraniu z menu Symulacja->Zapis. Odpowiedzialny za zapisanie aktualnych inicjalnych
     * danych symluacji do pliku.
     */
    void on_action_Zapisz_triggered();

    /*!
     * Slot Qt uruchamiany po wybraniu z menu Symulacja->Otworz. Odpowiedzialny za odczyt aktualnych inicjalnych
     * danych symluacji z pliku.
     */
    void on_action_Otworz_triggered();

    /*!
     * Slot Qt uruchamiany po wybraniu z menu Pomoc->O programie. Odpowiedzialny za wyświetlenie
     * komunikatu z podstawowymi informacjami o programie.
     */
    void on_action_O_programie_triggered();

private:
    Ui::MainWindow *ui;
    SimulationRunner *runner;
    shared_ptr<Notificator> notificator;
    shared_ptr<SimulationBuilder> simulation;

    void initTable(QTableWidget *table);

    std::string translateResult(SimulationResult result);
};

#endif // MAINWINDOW_H
