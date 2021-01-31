#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtAndroidExtras/QAndroidJniObject>

MainWindow::MainWindow(QList<TimeSheetCell>* timesheet_cells, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    charge_list = new ChargeList(&charge_list_items);
    timesheet_view = new TimeSheetView();
    alarm = new AlarmNotification(timesheet_cells, &charge_list_items);
    timesheet_view->setTimesheet_cells(timesheet_cells);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::show_popup);
    connect(ui->clock_in_button, &QPushButton::clicked, &qt_java_interface, &QtJavaInterface::updateAndroidNotification);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::show_timesheet);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::show_charges);
    test_write_metadata();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_popup(bool checked){
    alarm->update_charge_buttons();
    alarm->show();
    alarm->raise();
}

void MainWindow::show_timesheet(bool checked)
{
    timesheet_view->raise();
    timesheet_view->setupDisplay();
}

void MainWindow::show_charges(bool checked)
{
    charge_list->raise();
    charge_list->show();
}

void MainWindow::test_write_metadata()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString file_name = QDate::currentDate().toString("MMM-dd-yyyy.txt").prepend('/');
    QFile testFile(path.append(file_name));
    qDebug() << path;
    testFile.open(QFile::WriteOnly);
    QTextStream out(&testFile);
    out << "howdy\n";
    testFile.close();
}


