#ifndef IDIFFERENTIALMETHOD_H
#define IDIFFERENTIALMETHOD_H

#include <QVector>
#include <QDebug>

///
/// \brief The DiffSingleData struct
/// Структура для хранения единицы данных после дифференциации
struct DiffSingleData
{
    double   t;  // Текущее время
    double   x;  // Количество людей на текущий момент времени
    double   y;  // Количество хищников на текущий момент времени
};

///
/// \brief The DiffSettings struct
/// Структура для хранения настроек дифференциирования
struct DiffSettings
{
    double   startHumansCount;
    double   startPredatorsCount;

    double   startTime;
    double   endTime;
    double   step;

    double   birthRateOfPeople;
    double   killRatio;
    double   birthRateOfPredators;
    double   predatorsLossRate;
};

typedef QVector<DiffSingleData> DataVector;

class IDifferentialMethod
{
public:
    IDifferentialMethod() {}
    virtual DataVector* differentiate(const DiffSettings &settings) = 0;
protected:
    DataVector data;
};

#endif // IDIFFERENTIALMETHOD_H
