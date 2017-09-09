#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "diffulusion.h"
#include "eilersmethod.h"
#include "rungecuttamethod.h"
#include "coefdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_radioEulers_clicked();

    void on_radioRungeCutta_clicked();

    void on_spinHumans_editingFinished();

    void on_spinPredators_editingFinished();

    void on_spinEndOfTime_editingFinished();

    void on_spinStep_editingFinished();

    void on_pushSolve_clicked();

    void on_pushKoefs_clicked();

private:
    Ui::MainWindow *ui;
    Diffulusion *diff;
    EulersMethod eulersMethod;
    RungeCuttaMethod rungeCuttaMethod;
    DiffSettings diffSettings;

    CoefDialog coefDlg;
    // Для показа результата на последний момент времени
    void showEndData(const DiffSingleData &lastElement);
    // Заполнить структуру коэффициентами
    void updateCoefs();
};

#endif // MAINWINDOW_H
