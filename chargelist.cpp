#include "chargelist.h"
#include "ui_chargelist.h"

ChargeList::ChargeList(QList<ChargeListItem*>* charge_list_items, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChargeList)
{
    ui->setupUi(this);
    this->charge_list_items = charge_list_items;
    connect(ui->add_charge_button, &QPushButton::clicked, this, &ChargeList::add_a_new_charge);
}

ChargeList::~ChargeList()
{
    delete ui;
}

void ChargeList::add_a_new_charge(bool checked)
{
    ChargeListItem* new_charge = new ChargeListItem(ui->charge_name_text_edit->toPlainText());
    charge_list_items->append(new_charge);
    charge_item_layout.addWidget(new_charge);
    connect(new_charge->remove_button, &QPushButton::clicked, this, &ChargeList::remove_a_charge);
    QWidget* charge_list = new QWidget();
    charge_list->setLayout(&charge_item_layout);
    ui->scrollArea->setWidget(charge_list);
    charge_list->show();
}

void ChargeList::remove_a_charge(bool checked)
{
    for (auto charge : *charge_list_items) {
        if(charge->remove_button == QObject::sender()){
            delete charge;
        }
    }
}
