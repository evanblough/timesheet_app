#ifndef CHARGELIST_H
#define CHARGELIST_H

#include <QWidget>
#include <QVBoxLayout>
#include "chargelistitem.h"

namespace Ui {
class ChargeList;
}

const int max_number_charges = 20;

class ChargeList : public QWidget
{
    Q_OBJECT

public:
    ChargeList(QList<ChargeListItem*>* charge_list_items, QWidget *parent = nullptr);
    ~ChargeList();

public slots:
    void add_a_new_charge(bool checked);
    void remove_a_charge(bool checked);

private:
    int charge_index;
    Ui::ChargeList *ui;
    QList<ChargeListItem*>* charge_list_items;
    QVBoxLayout charge_item_layout;
};

#endif // CHARGELIST_H
