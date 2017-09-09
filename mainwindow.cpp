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
    // temp
    this->diffSettings.birthRateOfPeople = 2.0;
    this->diffSettings.killRatio = 0.02;
    this->diffSettings.birthRateOfPredators = 0.01;
    this->diffSettings.predatorsLossRate = 1.0;

    this->diffSettings.endTime = ui->spinEndOfTime->value();
    this->diffSettings.step = ui->spinStep->value();
    this->diffSettings.startPredatorsCount = ui->spinPredators->value();
    this->diffSettings.startHumansCount = ui->spinHumans->value();
    this->diffSettings.startTime = 0.0;

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
