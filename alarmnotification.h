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
    explicit AlarmNotification(QList<TimeSheetCell>* timesheet_cells, QList<ChargeListItem*>* charge_list_items, QWidget *parent = nullptr);
    ~AlarmNotification();
    void update_charge_buttons();
public slots:
    void hide_window(bool checked);
    void skip_button(bool checked);
    void clone_button(bool checked);

private:
    Ui::AlarmNotification *ui;
    QList<TimeSheetCell>* timesheet_cells;
    QList<ChargeListItem*>* charge_list_items;
    QVBoxLayout charge_list_item_layout;
    QList<QPushButton*> charge_buttons;
};

#endif // ALARMNOTIFICATION_H
