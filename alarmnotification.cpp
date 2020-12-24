#include "alarmnotification.h"
#include "ui_alarmnotification.h"

AlarmNotification::AlarmNotification(QList<TimeSheetCell>* timesheet_cells, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmNotification)
{
    ui->setupUi(this);
    this->timesheet_cells = timesheet_cells;
    connect(ui->pushButton, &QPushButton::clicked, this, &AlarmNotification::hide_window);
}

AlarmNotification::~AlarmNotification()
{
    delete ui;
}

void AlarmNotification::hide_window(bool checked)
{
    //Grab Metadata

    //Store Metadata in Table Class
    //TimeSheetCell t(ui->plainTextEdit->toPlainText(), ui->plainTextEdit_2->toPlainText());
    //timesheet_cells->append(t);
    //Reset window
    //ui->plainTextEdit->clear();
    ui->plainTextEdit_2->clear();
    this->hide();
}
