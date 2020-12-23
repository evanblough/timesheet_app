#ifndef TIMESHEETCELL_H
#define TIMESHEETCELL_H

#include<QString>

class TimeSheetCell
{

public:
    explicit TimeSheetCell(QString Charge, QString Description);
    QString Description, Charge;
};

#endif // TIMESHEETCELL_H
