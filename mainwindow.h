#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <alarmnotification.h>
#include <timesheetcell.h>
#include <timesheetview.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QList<TimeSheetCell>* timesheet_cells, QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void show_popup(bool checked);
    void show_timesheet(bool checked);

private:
    Ui::MainWindow *ui;
    AlarmNotification* alarm;
    TimeSheetView* timesheet_view;
    QList<TimeSheetCell> timesheet_cells;

};
#endif // MAINWINDOW_H
