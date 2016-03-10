#ifndef BOARD_H_
#define BOARD_H_

#include "NumberGroup.h"

#include <QMap>

class Board
{
public:
    enum NumberGroupType
    {
        GROUP,
        COLUMN,
        ROW
    };
    
    Board();
    void addNumberGroup(NumberGroupType type, int number, const QList<int> &);

private:
    QMap<int, NumberGroup> m_groupsNumberGroups;
    QMap<int, NumberGroup> m_columnsNumberGroups;
    QMap<int, NumberGroup> m_rowsNumberGroup;   
    
};

#endif /* BOARD_H_ */
