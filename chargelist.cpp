#include "chargelist.h"
#include "ui_chargelist.h"

ChargeList::ChargeList(QList<ChargeListItem*>* charge_list_items, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChargeList)
{
    ui->setupUi(this);
    this->charge_list_items = charge_list_items;
    charge_list_config_file = new QFile(charge_list_path);
    load_charges();
    connect(ui->add_charge_button, &QPushButton::clicked, this, &ChargeList::add_a_new_charge);
    QObject::connect(ui->exit_button, &QPushButton::clicked, this,  &QWidget::hide);
}

ChargeList::~ChargeList()
{
    delete ui;
}

void ChargeList::add_a_new_charge(bool checked)
{
    //Add charge to config file
    if(!file_parsed_charge){
        charge_list_config_file->open(QFile::Append);
        QTextStream out(charge_list_config_file);
        out << ui->charge_name_text_edit->toPlainText().append('\n');
        charge_list_config_file->close();
    }
    //Add charge to widget
    ChargeListItem* new_charge;
    if(file_parsed_charge) new_charge = new ChargeListItem(file_parsed_charge->remove('\n'));
    else new_charge = new ChargeListItem(ui->charge_name_text_edit->toPlainText());
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
    QString *removed_charge;
    //Remove from widget
    for (auto charge : *charge_list_items) {
        if(charge->remove_button == QObject::sender()){
            removed_charge = new QString(charge->charge_name);
            delete charge;
        }
    }
    //Remove from config file
    charge_list_config_file->open(QFile::ReadWrite);
    QTextStream out(charge_list_config_file);
    QString charge_name;
    QString charge_file_without_charge;
    while(out.readLineInto(&charge_name)){
        if(charge_name != removed_charge){
            charge_file_without_charge.append(charge_name.append('\n'));
        }
    }
    //Erase File
    charge_list_config_file->resize(0);
    //Rewrite new config without deleted charge
    out << charge_file_without_charge;
    charge_list_config_file->close();
    if(removed_charge != nullptr) delete removed_charge;
}

void ChargeList::load_charges()
{
    charge_list_config_file->open(QFile::ReadWrite);
    QTextStream out(charge_list_config_file);
    QString charge_name;
    while(out.readLineInto(&charge_name)){
        if(charge_name != "\n" && charge_name != " "){
            file_parsed_charge = &charge_name;
            add_a_new_charge(false);
        }
    }
    file_parsed_charge = nullptr;
    charge_list_config_file->close();
}
