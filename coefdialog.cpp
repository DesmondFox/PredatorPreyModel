#include "coefdialog.h"
#include "ui_coefdialog.h"

CoefDialog::CoefDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CoefDialog)
{
    ui->setupUi(this);
}

CoefDialog::~CoefDialog()
{
    delete ui;
}

double CoefDialog::getHumanBirthRate() const
{
    return ui->spinHumanBirthRate->value();
}

double CoefDialog::getPredatorBirthRate() const
{
    return ui->spinPredatorsBirthRate->value();
}

double CoefDialog::getKillRatio() const
{
    return ui->spinKillRatio->value();
}

double CoefDialog::getPredatorsLoss() const
{
    return ui->spinLossPredatorsRate->value();
}
