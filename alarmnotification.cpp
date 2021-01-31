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
    QString file_name = QDate::currentDate().toString("MMM-dd-yyyy.txt").prepend('/');
    timesheet_file = new QFile(file_name.prepend(timesheet_container_path));
    load_timesheet_cells();
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
            //Add to list
            TimeSheetCell t(charge_button->text() , ui->plainTextEdit_2->toPlainText());
            timesheet_cells->append(t);
            //Add to file
            timesheet_file->open(QFile::Append);
            QTextStream out(timesheet_file);
            out << t.Charge << "\n";
            out << t.Description.remove('\n') << "\n";
            timesheet_file->close();
        }
    }
    qt_java_interface->updateAndroidNotification();
    //Store Metadata in Table Class
    this->hide();
}

void AlarmNotification::skip_button(bool checked)
{
    qt_java_interface->updateAndroidNotification();
    this->hide();
}

void AlarmNotification::clone_button(bool checked)
{
    TimeSheetCell t(timesheet_cells->last().Charge, timesheet_cells->last().Description);
    timesheet_cells->append(t);
    timesheet_file->open(QFile::Append);
    QTextStream out(timesheet_file);
    out << t.Charge << "\n";
    out << t.Description.remove('\n') << "\n";
    timesheet_file->close();
    qt_java_interface->updateAndroidNotification();
    this->hide();
}

void AlarmNotification::load_timesheet_cells()
{
    timesheet_cells->clear();
    timesheet_file->open(QFile::ReadWrite);
    QTextStream out(timesheet_file);
    QString timesheet_cell_charge;
    QString timesheet_cell_desc;
    while(out.readLineInto(&timesheet_cell_charge)){
        out.readLineInto(&timesheet_cell_desc);
        TimeSheetCell t(timesheet_cell_charge , timesheet_cell_desc);
        timesheet_cells->append(t);
    }
    timesheet_file->close();
}

void AlarmNotification::setQt_java_interface(QtJavaInterface *value)
{
    qt_java_interface = value;
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
