#include "alarmnotification.h"
#include "ui_alarmnotification.h"

void clearLayout(QLayout *layout);

AlarmNotification::AlarmNotification(QList<TimeSheetCell>* timesheet_cells, QList<ChargeListItem*>* charge_list_items, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmNotification)
{
    ui->setupUi(this);
    this->timesheet_cells = timesheet_cells;
    this->charge_list_items = charge_list_items;
    QWidget* widget =  new QWidget();
    widget->setLayout(&charge_list_item_layout);
    ui->scrollArea->setWidget(widget);
    QObject::connect(ui->clone_button, &QPushButton::clicked, this, &AlarmNotification::clone_button);
    QObject::connect(ui->skip_button, &QPushButton::clicked, this, &AlarmNotification::skip_button);
    widget->show();
}

AlarmNotification::~AlarmNotification()
{
    delete ui;
}

void AlarmNotification::update_charge_buttons()
{
    clearLayout(&charge_list_item_layout);
    for (auto charge_list_item : *charge_list_items){
        QPushButton* charge_button = new QPushButton(charge_list_item->getCharge_name());
        charge_list_item_layout.addWidget(charge_button);
        charge_buttons.append(charge_button);
        QObject::connect(charge_button, &QPushButton::clicked, this, &AlarmNotification::hide_window);
    }
    QWidget* widget = new QWidget();
    widget->setLayout(&charge_list_item_layout);
    ui->scrollArea->setWidget(widget);
}

void AlarmNotification::hide_window(bool checked)
{
    //Grab Metadata
    for(QPushButton* charge_button : charge_buttons){
        if(charge_button == QObject::sender()){
            TimeSheetCell t(charge_button->text() , ui->plainTextEdit_2->toPlainText());
            timesheet_cells->append(t);
        }
    }
    //Store Metadata in Table Class
    this->hide();
}

void AlarmNotification::skip_button(bool checked)
{
    this->hide();
}

void AlarmNotification::clone_button(bool checked)
{
    TimeSheetCell t(timesheet_cells->last().Charge, timesheet_cells->last().Description);
    timesheet_cells->append(t);
    this->hide();
}

void clearLayout(QLayout *layout) {
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }
}
