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
