#ifndef DIFFULUSION_H
#define DIFFULUSION_H

#include <QObject>

#include "idifferentialmethod.h"


class Diffulusion : public QObject
{
    Q_OBJECT
public:
    explicit Diffulusion(IDifferentialMethod *method,
                         QObject *parent = nullptr);
    void    changeMethod(IDifferentialMethod *method);
    DataVector *getSolve(const DiffSettings& sett) const;
private:
    IDifferentialMethod *m_method;

signals:

public slots:
};

#endif // DIFFULUSION_H
