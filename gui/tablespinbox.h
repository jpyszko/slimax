//
// Created by jpyszko on 20.08.2021.
//

#ifndef SLIMAX_TABLESPINBOX_H
#define SLIMAX_TABLESPINBOX_H


#include <QStyledItemDelegate>

/*!
 * Klasa używana jako edytor dla zajmowanej powierzchni smilaka i rośliny (rozmaru) w tabelach sluzących do ich edycji.
 */
class TableSpinbox : public QStyledItemDelegate {

    Q_OBJECT

public:

    /*!
     * Konstruktor tworzący edytor
     * @param parent - obiekt Qt będący rodzicem edytora (tabeli) w którym ma on się wyświetlić.
     */
    TableSpinbox(QObject *parent = nullptr);

    /*!
     * Przeciązona metoda QStyledItemDelegate odpowiedzalna za tworzenie nowych instancji Spinbox dla odpowiednich
     * komórek tabeli
     * @param parent - obiekt tabeli w którym będą tworzone widgety Spinbox
     * @param option - dodatkowe opcje możliwe do wykorzystania podczas tworzenia widgetu (nieużywane)
     * @param index - indeks pozwalajacy określić stan komórki tabeli (nieużywane)
     * @return obiekt utworzonego edytora dla komórki tabeli
     */
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    /*!
     * Przeciązona metoda QStyledItemDelegate odpowiedzalna za pobieranie danych z modelu tabeli i prawidłowe
     * wyświetalnie ich w widgecie Spinbox
     * @param editor - obiekt edytora wyświetlanego w konretnej komórce
     * @param index - indeks pozwalający określić stan komórki, w tym aktualne dane do wyświetlenia
     */
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    /*!
     * Przeciązona metoda QStyledItemDelegate odpowiedzalna za pobieranie danych z widgetu Spinbox
     * i zapisywanie ich w modelu tabeli
     * @param editor - obiekt edytora wyświetlanego w konretnej komórce
     * @param model - model w którym zapisywane są pobrane z widgetu dane
     * @param  - index pozwalający określić stan komórki
     */
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

};


#endif //SLIMAX_TABLESPINBOX_H
