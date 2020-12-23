#ifndef ALARMNOTIFICATION_H
#define ALARMNOTIFICATION_H

#include <QWidget>
#include <timesheetcell.h>

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
};

#endif // ALARMNOTIFICATION_H
