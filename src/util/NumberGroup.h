#ifndef NUMBERGROUP_H_
#define NUMBERGROUP_H_

#include <QList>

class NumberGroup
{
public:
    NumberGroup(const QList<int> &defaultValues);
    bool isValid(int newValue);
    void addValue(int newValue);

private:
    QList<int> m_numbers;
};

#endif /* NUMBERGROUP_H_ */
