#ifndef CHARGELIST_H
#define CHARGELIST_H

#include <QWidget>
#include <QVBoxLayout>
#include <QStandardPaths>
#include <QFile>
#include <QDebug>
#include <QDate>
#include <QTextStream>
#include "chargelistitem.h"

namespace Ui {
class ChargeList;
}

const int max_number_charges = 20;
const QString charge_list_filename = "ChargeListFile.txt";
const QString charge_list_path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation).append("/Timesheet/").append(charge_list_filename);


class ChargeList : public QWidget
{
    Q_OBJECT

public:
    ChargeList(QList<ChargeListItem*>* charge_list_items, QWidget *parent = nullptr);
    ~ChargeList();

public slots:
    void add_a_new_charge(bool checked);
    void remove_a_charge(bool checked);
    void load_charges();

private:
    int charge_index;
    Ui::ChargeList *ui;
    QList<ChargeListItem*>* charge_list_items;
    QVBoxLayout charge_item_layout;
    QFile* charge_list_config_file;
    QString* file_parsed_charge = nullptr;
};

#endif // CHARGELIST_H
