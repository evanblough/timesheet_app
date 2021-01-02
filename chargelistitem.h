#ifndef CHARGELISTITEM_H
#define CHARGELISTITEM_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class ChargeListItem;
}

class ChargeListItem : public QWidget
{
    Q_OBJECT

public:
    explicit ChargeListItem(QString charge_name);
    ~ChargeListItem();
    QPushButton* remove_button;
    QString charge_name;

    QString getCharge_name() const;

private:
    Ui::ChargeListItem *ui;
};

#endif // CHARGELISTITEM_H
