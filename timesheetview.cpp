#include "timesheetview.h"
#include "ui_timesheetview.h"


const float time_sheet_quantum = 0.2;

enum timesheet_columns {
    charge_name_column,
    charge_total_column
};

TimeSheetView::TimeSheetView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeSheetView)
{
    ui->setupUi(this);
    timesheet_layout.setSpacing(0);
    timesheet_layout.setContentsMargins(0,0,0,0);
}

TimeSheetView::~TimeSheetView()
{
    delete ui;
}

void TimeSheetView::setTimesheet_cells(QList<TimeSheetCell> *value)
{
    timesheet_cells = value;
}

void TimeSheetView::setupDisplay()
{
    //Init iterators
    QList<QString> charge_nums;
    QVector<float> charge_totals;
    int i = -1;
    //Calculate Hours
    for(TimeSheetCell timesheet_cell : *timesheet_cells) {
        if(charge_nums.contains(timesheet_cell.Charge)){
            charge_totals[i] += time_sheet_quantum;
        }
        else{
            charge_nums.append(timesheet_cell.Charge);
            charge_totals.append(time_sheet_quantum);
            i++;
        }
    }
    i =0;
    //Add timesheet entries to container
    for(QString charge_num : charge_nums){
        //Generate Labels
        QLabel *charge_num_label = new QLabel(charge_num);
        QLabel *charge_total_label = new QLabel(QString::number(charge_totals[i]));
        //Format Labels
        format_timesheet_cell(charge_num_label);
        format_timesheet_cell(charge_total_label);
        //Add Labels
        timesheet_layout.addWidget(charge_num_label,i,charge_name_column);
        timesheet_layout.addWidget(charge_total_label,i,charge_total_column);
        timesheet_layout.setAlignment(charge_num_label, Qt::AlignTop);
        timesheet_layout.setAlignment(charge_total_label, Qt::AlignTop);
        i++;
    }
    //Add Container to scroll area and display
    QWidget *holder = new QWidget();
    holder->setLayout(&timesheet_layout);
    ui->scrollArea->setWidget(holder);
    this->show();
}

void TimeSheetView::format_timesheet_cell(QLabel* label){
   label->setFrameStyle(QFrame::Box | QFrame::Shadow::Plain);
   label->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
   label->setFixedHeight(cell_height);
   label->setAlignment(Qt::AlignLeft);
}

