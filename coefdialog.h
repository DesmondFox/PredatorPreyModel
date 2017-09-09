#ifndef COEFDIALOG_H
#define COEFDIALOG_H

#include <QDialog>

namespace Ui {
class CoefDialog;
}



class CoefDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CoefDialog(QWidget *parent = 0);
    ~CoefDialog();

    double getHumanBirthRate() const;
    double getPredatorBirthRate() const;
    double getKillRatio() const;
    double getPredatorsLoss() const;

private:
    Ui::CoefDialog *ui;
};

#endif // COEFDIALOG_H
