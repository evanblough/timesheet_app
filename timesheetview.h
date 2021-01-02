#ifndef TIMESHEETVIEW_H
#define TIMESHEETVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <timesheetcell.h>
#include <QLabel>

namespace Ui {
class TimeSheetView;
}

class TimeSheetView : public QWidget
{
    Q_OBJECT

public:
    explicit TimeSheetView(QWidget *parent = nullptr);
    ~TimeSheetView();
    void setTimesheet_cells(QList<TimeSheetCell> *value);
    void setupDisplay();

private:
    Ui::TimeSheetView *ui;
    QList<TimeSheetCell>* timesheet_cells;
    QGridLayout timesheet_layout;
    void format_timesheet_cell(QLabel* label);
    const int cell_height = 60;

};

#endif // TIMESHEETVIEW_H
