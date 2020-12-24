#include "settingspane.h"
#include "ui_settingspane.h"

SettingsPane::SettingsPane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsPane)
{
    ui->setupUi(this);
}

SettingsPane::~SettingsPane()
{
    delete ui;
}
