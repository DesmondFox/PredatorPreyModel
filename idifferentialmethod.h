#ifndef IDIFFERENTIALMETHOD_H
#define IDIFFERENTIALMETHOD_H

#include <QVector>
#include <QDebug>

///
/// \brief The DiffSingleData struct
/// Структура для хранения единицы данных после дифференциации
struct DiffSingleData
{
    qreal   t;  // Текущее время
    qreal   x;  // Количество людей на текущий момент времени
    qreal   y;  // Количество хищников на текущий момент времени
};

///
/// \brief The DiffSettings struct
/// Структура для хранения настроек дифференциирования
struct DiffSettings
{
    qreal   startHumansCount;
    qreal   startPredatorsCount;

    qreal   startTime;
    qreal   endTime;
    qreal   step;

    qreal   birthRateOfPeople;
    qreal   killRatio;
    qreal   birthRateOfPredators;
    qreal   predatorsLossRate;
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
