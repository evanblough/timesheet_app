#ifndef ALARMNOTIFICATION_H
#define ALARMNOTIFICATION_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFile>
#include <QDate>
#include <QTextStream>
//#include <QBloodyStream>
#include <QStandardPaths>
#include <timesheetcell.h>
#include <chargelistitem.h>

namespace Ui {
class AlarmNotification;
}

const QString timesheet_container_path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation).append("/Timesheet/");

class AlarmNotification : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmNotification(QList<TimeSheetCell>* timesheet_cells, QList<ChargeListItem*>* charge_list_items, QWidget *parent = nullptr);
    ~AlarmNotification();
    void update_charge_buttons();
public slots:
    void hide_window(bool checked);
    void skip_button(bool checked);
    void clone_button(bool checked);
    void load_timesheet_cells();

private:
    Ui::AlarmNotification *ui;
    QList<TimeSheetCell>* timesheet_cells;
    QList<ChargeListItem*>* charge_list_items;
    QVBoxLayout charge_list_item_layout;
    QList<QPushButton*> charge_buttons;
    QFile* timesheet_file;
};

#endif // ALARMNOTIFICATION_H
