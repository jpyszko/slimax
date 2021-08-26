//
// Created by jpyszko on 20.08.2021.
//

#ifndef SLIMAX_SNAILSCOMBOBOX_H
#define SLIMAX_SNAILSCOMBOBOX_H


#include "tablecombobox.h"

/*!
 * Klasa konretna edytora listy wyboru (combobox) słuzącej do wyboru typu ślimaka w tabeli edycji slimaków
 */
class SnailsCombobox : public TableCombobox{

    Q_OBJECT

public:
    /*!
     * Konstruktor tworzący edytor
     * @param parent - obiekt Qt będący rodzicem edytora (tabeli) w którym ma on się wyświetlić.
     */
    SnailsCombobox(QObject *parent = nullptr);

    /*!
     * Przeciązona metoda QStyledItemDelegate odpowiedzalna za tworzenie nowych instancji listy wyboru typów ślimaków (combobox)
     * wyświetlanych w tabeli
     * @param parent - obiekt tabeli w którym będą tworzone widgety combobox
     * @param option - dodatkowe opcje możliwe do wykorzystania podczas tworzenia widgetu (nieużywane)
     * @param index - indeks pozwalajacy określić stan komórki tabeli (nieużywane)
     * @return obiekt utworzonego edytora (combobox) dla komórki tabeli
     */
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};


#endif //SLIMAX_SNAILSCOMBOBOX_H
