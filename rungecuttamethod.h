#ifndef RUNGECUTTAMETHOD_H
#define RUNGECUTTAMETHOD_H

#include "idifferentialmethod.h"

class RungeCuttaMethod : public IDifferentialMethod
{
public:
    RungeCuttaMethod();
    virtual DataVector *differentiate(const DiffSettings &settings);
};

#endif // RUNGECUTTAMETHOD_H
