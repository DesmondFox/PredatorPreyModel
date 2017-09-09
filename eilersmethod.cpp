#include "eilersmethod.h"

EulersMethod::EulersMethod()
{

}

DataVector *EulersMethod::differentiate(const DiffSettings &settings)
{
    this->data.clear();

    DiffSingleData beginData;
    beginData.t = settings.startTime;
    beginData.x = settings.startHumansCount;
    beginData.y = settings.startPredatorsCount;
    this->data.push_back(beginData);

    double  a = settings.startTime,
            b = settings.endTime,
            h = settings.step;

    int stepCount = (b / h) + 1;
    double currentTime = a + h;

    double  x, y;
    double  x_prev = beginData.x,
            y_prev = beginData.y;
    for (int j = 1; j <= stepCount; j++)
    {
        x = x_prev + h*((2.0-0.02*y_prev)*x_prev);
        y = y_prev + h*(-1.0*y_prev + 0.01*x_prev*y_prev);

        DiffSingleData currentValues;
        currentValues.x = x;
        currentValues.y = y;
        currentValues.t = currentTime;
        this->data.push_back(currentValues);

        x_prev = x;
        y_prev = y;

        currentTime += h;
    }


    return &(this->data);
}
