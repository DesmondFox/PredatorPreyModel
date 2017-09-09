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

    double  x, y;
    double  x_prev = beginData.x,
            y_prev = beginData.y;
    double K[4];
    for (int j = 1; j <= stepCount; j++)
    {
        // Решаем X
        K[0] = (2.0-0.02*y_prev) * x_prev;
        K[1] = (2.0-0.02*(y_prev + h*K[0]/2.0))  * (x_prev + h*K[0]/2.0);
        K[2] = (2.0-0.02*(y_prev + h*K[1]/2.0))  * (x_prev + h*K[1]/2.0);
        K[3] = (2.0-0.02*(y_prev + h*K[2]))    * (x_prev + h*K[2]);
        x   = x_prev + h*(K[0] + 2.0*K[1] + 2.0*K[2] + K[3])/6.0;

        // Решаем Y
        K[0] = (-1.0*y_prev  + 0.01*x_prev*y_prev);
        K[1] = (-1.0*(y_prev + h*K[0]/2.0) + 0.01*(x_prev + h*K[0]/2.0)   * (y_prev + h*K[0]/2.0));
        K[2] = (-1.0*(y_prev + h*K[1]/2.0) + 0.01*(x_prev + h*K[1]/2.0)   * (y_prev + h*K[1]/2.0));
        K[3] = (-1.0*(y_prev + h*K[2]/2.0) + 0.01*(x_prev + h*K[2])     * (y_prev + h*K[2]));
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
