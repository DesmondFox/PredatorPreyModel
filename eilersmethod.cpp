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

    double  alp     = settings.birthRateOfPeople,
            beta    = settings.killRatio,
            gamma   = settings.predatorsLossRate,
            delta   = settings.birthRateOfPredators;


    double  x, y;
    double  x_prev = beginData.x,
            y_prev = beginData.y;
    for (int j = 1; j <= stepCount; j++)
    {
        x = x_prev + h*((alp-beta*y_prev)*x_prev);
        y = y_prev + h*(-gamma*y_prev + delta*x_prev*y_prev);

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
