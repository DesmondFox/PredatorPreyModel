#ifndef WIDGETPLOT_H
#define WIDGETPLOT_H

#include <QWidget>
#include <QChartView>
#include <QChart>
#include <QSplineSeries>
#include <QHBoxLayout>

#include "idifferentialmethod.h"

using namespace QtCharts;

class WidgetPlot : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetPlot(QWidget *parent = nullptr);

    void draw(const DataVector* vector);

private:
    QChartView *chartView;
    QChart *chart;
    QSplineSeries *humans;
    QSplineSeries *predators;
signals:

public slots:
};

#endif // WIDGETPLOT_H
