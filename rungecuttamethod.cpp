#include "rungecuttamethod.h"

RungeCuttaMethod::RungeCuttaMethod()
{

}

DataVector *RungeCuttaMethod::differentiate(const DiffSettings &settings)
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
    double K[4];
    for (int j = 1; j <= stepCount; j++)
    {
        // Решаем X
        K[0] = (alp-beta*y_prev) * x_prev;
        K[1] = (alp-beta*(y_prev + h*K[0]/2.0))  * (x_prev + h*K[0]/2.0);
        K[2] = (alp-beta*(y_prev + h*K[1]/2.0))  * (x_prev + h*K[1]/2.0);
        K[3] = (alp-beta*(y_prev + h*K[2]))    * (x_prev + h*K[2]);
        x   = x_prev + h*(K[0] + 2.0*K[1] + 2.0*K[2] + K[3])/6.0;

        // Решаем Y
        K[0] = (-gamma*y_prev  + delta*x_prev*y_prev);
        K[1] = (-gamma*(y_prev + h*K[0]/2.0) + delta*(x_prev + h*K[0]/2.0)   * (y_prev + h*K[0]/2.0));
        K[2] = (-gamma*(y_prev + h*K[1]/2.0) + delta*(x_prev + h*K[1]/2.0)   * (y_prev + h*K[1]/2.0));
        K[3] = (-gamma*(y_prev + h*K[2]/2.0) + delta*(x_prev + h*K[2])     * (y_prev + h*K[2]));
        y   = y_prev + h*(K[0] + 2.0*K[1] + 2.0*K[2] + K[3])/6.0;


        DiffSingleData currentValues;
        currentValues.x = x;
        currentValues.y = y;
        currentValues.t = currentTime;
        this->data.push_back(currentValues);

        x_prev = x;
        y_prev = y;

        currentTime += h;
    }


    return &this->data;
}
