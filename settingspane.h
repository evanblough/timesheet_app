#ifndef SETTINGSPANE_H
#define SETTINGSPANE_H

#include <QWidget>

namespace Ui {
class SettingsPane;
}

class SettingsPane : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsPane(QWidget *parent = nullptr);
    ~SettingsPane();

private:
    Ui::SettingsPane *ui;
};

#endif // SETTINGSPANE_H
