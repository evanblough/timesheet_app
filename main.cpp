#include "mainwindow.h"

#include <QApplication>
#include <timesheetcell.h>

int main(int argc, char *argv[])
{
    QApplication::setStyle("Fusion");
    QApplication a(argc, argv);
    QList<TimeSheetCell>* timesheet_cells = new QList<TimeSheetCell>();
    MainWindow w(timesheet_cells);
    w.show();
    return a.exec();
}
