#include "widgetplot.h"

WidgetPlot::WidgetPlot(QWidget *parent)
    : QWidget(parent)
{
    chart   = new QChart();
    chartView   = new QChartView(chart, this);
    chartView->setRenderHint(QPainter::Antialiasing);

    QHBoxLayout *pHBLayout = new QHBoxLayout(this);
    pHBLayout->addWidget(chartView);
    this->setLayout(pHBLayout);

//    chart->setTitle("Численность населения");
    chart->createDefaultAxes();
    chart->setAnimationOptions(QChart::SeriesAnimations);
}

void WidgetPlot::draw(const DataVector *vector)
{
    if (!chart->series().isEmpty())
        chart->removeAllSeries();


    humans      = new QSplineSeries();
    predators   = new QSplineSeries();
    predators->setName("Хищники");
    humans->setName("Жертвы");
    for (DiffSingleData dt : *vector)
    {
        if (dt.x > 100000 || dt.y > 100000)
        {
            qDebug() << "Terminate! Variable > 100 000";
            break;
        }
        humans->append(dt.t, dt.x);
        predators->append(dt.t, dt.y);

    }

    chart->addSeries(humans);
    chart->addSeries(predators);
    chart->createDefaultAxes();

}

