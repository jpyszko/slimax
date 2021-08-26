//
// Created by jpyszko on 19.08.2021.
//

#ifndef SLIMAX_TABLECOMBOBOX_H
#define SLIMAX_TABLECOMBOBOX_H


#include <QStyledItemDelegate>
#include <QComboBox>

/*!
 * Klasa abstrakcyjna używana jako podstawa do utworzenia comboboxa d owyboru typu ślimaka i rośliny
 * w tabelach sluzących do ich edycji.
 */
class TableCombobox : public QStyledItemDelegate {

    Q_OBJECT

public:

    /*!
     * Konstruktor tworzący edytor
     * @param parent - obiekt Qt będący rodzicem edytora (tabeli) w którym ma on się wyświetlić.
     */
    TableCombobox(QObject *parent = nullptr);

    /*!
     * Przeciązona metoda QStyledItemDelegate odpowiedzalna za pobieranie danych z modelu tabeli i ustawienie
     * odpowiedniej wartości w combobox
     * @param editor - obiekt edytora wyświetlanego w konretnej komórce
     * @param index - indeks pozwalający określić stan komórki, w tym aktualne dane do wyświetlenia
     */
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    /*!
     * Przeciązona metoda QStyledItemDelegate odpowiedzalna za pobieranie ustawionej wartości z combobox
     * i zapisywanie jej w modelu tabeli
     * @param editor - obiekt edytora wyświetlanego w konretnej komórce
     * @param model - model w którym zapisywane są pobrane z widgetu dane
     * @param  - index pozwalający określić stan komórki
     * */
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    /*!
     * Wirtualny destruktor klasy bazowej uruchamiany przez klasy potomne
     */
    virtual ~TableCombobox() = 0;

};


#endif //SLIMAX_TABLECOMBOBOX_H
