#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    diff    = new Diffulusion(&eulersMethod, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_radioEulers_clicked()
{
    diff->changeMethod(&eulersMethod);
}

void MainWindow::on_radioRungeCutta_clicked()
{
    diff->changeMethod(&rungeCuttaMethod);
}

void MainWindow::on_spinHumans_editingFinished()
{
    this->diffSettings.startHumansCount = ui->spinHumans->value();
}

void MainWindow::on_spinPredators_editingFinished()
{
    this->diffSettings.startPredatorsCount = ui->spinPredators->value();
}

void MainWindow::on_spinEndOfTime_editingFinished()
{
    this->diffSettings.endTime = ui->spinEndOfTime->value();
}

void MainWindow::on_spinStep_editingFinished()
{
    this->diffSettings.step = ui->spinStep->value();
}

void MainWindow::on_pushSolve_clicked()
{

    updateCoefs();

    DataVector* vec = this->diff->getSolve(this->diffSettings);
    ui->plot->draw(vec);
    this->showEndData(vec->last());
}

void MainWindow::showEndData(const DiffSingleData &lastElement)
{
    QString text(QString("На конец времени[%1]: <br>"
                         "<font color='blue'>Люди: %2</font><br>"
                         "<font color='green'>Хищники: %3</font>")
                 .arg(QString::number(lastElement.t))
                 .arg(QString::number((int) lastElement.x))
                 .arg(QString::number((int) lastElement.y)));
    ui->labelResult->setText(text);
}

void MainWindow::updateCoefs()
{
    this->diffSettings.birthRateOfPeople    = coefDlg.getHumanBirthRate();
    this->diffSettings.birthRateOfPredators = coefDlg.getPredatorBirthRate();
    this->diffSettings.killRatio            = coefDlg.getKillRatio();
    this->diffSettings.predatorsLossRate    = coefDlg.getPredatorsLoss();

    this->diffSettings.endTime = ui->spinEndOfTime->value();
    this->diffSettings.step = ui->spinStep->value();
    this->diffSettings.startPredatorsCount = ui->spinPredators->value();
    this->diffSettings.startHumansCount = ui->spinHumans->value();
    this->diffSettings.startTime = 0.0;
}

void MainWindow::on_pushKoefs_clicked()
{
    if (this->coefDlg.exec() == CoefDialog::Accepted)
    {
        updateCoefs();
    }
}
