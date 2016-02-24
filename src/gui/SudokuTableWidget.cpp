#include "SudokuTableWidget.h"

#include <QHeaderView>
#include <QPainter>

#include <stdio.h>

SudokuTableWidget::SudokuTableWidget(QWidget *parent)
    : QTableWidget(parent)
{
    m_drawLines = false;
    for (int row = 0; row < 9; row++)
    {
        insertRow(row);
        setRowHeight(row, 30);
    }

    for (int column = 0; column < 9; column++)
    {
        insertColumn(column);
        setColumnWidth(column, 30);
    }

    horizontalHeader()->hide();
    verticalHeader()->hide();
    m_drawLines = true;
    viewport()->update();
}


void SudokuTableWidget::setupBoard(const QMap<QPair<int, int>, int> &values)
{
    QFont bold;
    bold.setBold(true);
    QMapIterator<QPair<int, int>, int> it(values);
    while (it.hasNext())
    {
        it.next();
        QPair<int, int> loc(it.key());
        int value = it.value();
        QTableWidgetItem *defaultItem = new QTableWidgetItem();
        defaultItem->setText(QString("%1").arg(value));
        defaultItem->setBackground(QColor("grey"));
        defaultItem->setFont(bold);
        defaultItem->setTextAlignment(Qt::AlignCenter);
        defaultItem->setFlags(Qt::ItemIsEnabled);
        setItem(loc.first, loc.second, defaultItem);
    }
}


void SudokuTableWidget::paintEvent(QPaintEvent *e)
{
    QTableWidget::paintEvent(e);
    if (m_drawLines)
    {
        printf("lines\n");
        QPainter painter;
        painter.begin(viewport());
        painter.setPen(QPen(Qt::black, 3));
        painter.drawLine(QLine(visualItemRect(item(2,0)).bottomLeft(),visualItemRect(item(2,8)).bottomRight()));
        painter.end();
        m_drawLines = false;
    }
}
