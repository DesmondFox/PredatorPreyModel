#ifndef EILERSMETHOD_H
#define EILERSMETHOD_H

#include "idifferentialmethod.h"
#include <QDebug>

class EulersMethod : public IDifferentialMethod
{
public:
    EulersMethod();
    virtual DataVector *differentiate(const DiffSettings &settings);
};

#endif // EILERSMETHOD_H
