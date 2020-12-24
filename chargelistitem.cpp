#include "chargelistitem.h"
#include "ui_chargelistitem.h"

ChargeListItem::ChargeListItem(QString charge_name) :
    charge_name(charge_name),
    ui(new Ui::ChargeListItem)
{
    ui->setupUi(this);
    ui->charge_name_label->setText(charge_name);
    remove_button = ui->remove_charge_button;
}

ChargeListItem::~ChargeListItem()
{
    delete ui;
}
