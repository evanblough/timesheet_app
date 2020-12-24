#ifndef ALARMNOTIFICATION_H
#define ALARMNOTIFICATION_H

#include <QWidget>
#include <QVBoxLayout>
#include <timesheetcell.h>
#include <chargelistitem.h>

namespace Ui {
class AlarmNotification;
}

class AlarmNotification : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmNotification(QList<TimeSheetCell>* timesheet_cells, QWidget *parent = nullptr);
    ~AlarmNotification();
public slots:
    void hide_window(bool checked);

private:
    Ui::AlarmNotification *ui;
    QList<TimeSheetCell>* timesheet_cells;
    QList<ChargeListItem>* charge_list_items;
    QVBoxLayout charge_list_item_layout;
};

#endif // ALARMNOTIFICATION_H
