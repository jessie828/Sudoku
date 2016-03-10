#include "NumberGroup.h"

NumberGroup::NumberGroup(const QList<int> &defaultValues)
{
    m_numbers = defaultValues;
}


bool NumberGroup::isValid(int newValue)
{
    return m_numbers.contains(newValue);
}


void NumberGroup::addValue(int newValue)
{
    m_numbers.append(newValue);
}

