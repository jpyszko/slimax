//
// Created by jpyszo on 17.08.2021.
//

#ifndef SLIMAX_GUINOTIFICATOR_H
#define SLIMAX_GUINOTIFICATOR_H

#include "../engine/Notificator.h"
#include "ui_mainwindow.h"

/*!
 * Klasa subskrybenta dla GUI reagująca na zmiany w modelu danych symulacji. Odpowiedzialny za aktualizację
 * danych wyświetlanych w głownym oknie programu po odebraniu informacji o zmianie w modelu.
 */
class GuiNotificator : public Notificator{

public:
    /*!
     * Konstruktor tworzący klasę
     * @param mainWindow - głowne okno aplikacji które będzię uaktualniane przez GuiNotificator
     */
    explicit GuiNotificator(Ui::MainWindow *mainWindow);

    /*!
     * Metoda uruchamiana przez silnik symulacji w celu powiadomienia GuiNotyficator o dokonanych zmianach w modelu.
     * Odpowiedzialna za aktualizację danych głownego okna na podstawie otrzymanych parametrów
     * @param remainingTime - aktualny pozostały czas w sekundach
     * @param snails - aktualny zbiór slimaków
     * @param plants - aktualny zbiór roślin
     */
    void notify(int remainingTime, RandomSet<shared_ptr<Snail>> &snails, RandomSet<shared_ptr<Plant>> &plants) override;

private:
    Ui::MainWindow *window;
};


#endif //SLIMAX_GUINOTIFICATOR_H
