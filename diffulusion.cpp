#include "diffulusion.h"

Diffulusion::Diffulusion(IDifferentialMethod *method,
                         QObject *parent)
    : QObject(parent),
      m_method(method)
{

}

void Diffulusion::changeMethod(IDifferentialMethod *method)
{
    this->m_method = method;
}

DataVector *Diffulusion::getSolve(const DiffSettings &sett) const
{
    return this->m_method->differentiate(sett);
}
