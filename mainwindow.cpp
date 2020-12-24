#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QList<TimeSheetCell>* timesheet_cells, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timesheet_view = new TimeSheetView();
    alarm = new AlarmNotification(timesheet_cells);
    timesheet_view->setTimesheet_cells(timesheet_cells);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::show_popup);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::show_timesheet);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::show_charges);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_popup(bool checked){
    alarm->show();
}

void MainWindow::show_timesheet(bool checked)
{
    timesheet_view->setupDisplay();
}

void MainWindow::show_charges(bool checked)
{
    charge_list.show();
}

