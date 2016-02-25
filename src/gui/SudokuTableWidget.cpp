#include "SudokuTableWidget.h"

#include <QHeaderView>
#include <QPainter>

#include <stdio.h>

SudokuTableWidget::SudokuTableWidget(QWidget *parent)
    : QTableWidget(parent)
{
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

    for (int col = 0; col < columnCount(); col++)
    {
        for (int row = 0; row < columnCount(); row++)
        {
            QTableWidgetItem *emptytItem = new QTableWidgetItem();
            emptytItem->setTextAlignment(Qt::AlignCenter);
            emptytItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsEditable);
            emptytItem->setText("");
            setItem(row, col, emptytItem);
        }
    }

    horizontalHeader()->hide();
    verticalHeader()->hide();
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
        delete item(loc.first, loc.second);
        setItem(loc.first, loc.second, defaultItem);
    }
}


void SudokuTableWidget::paintEvent(QPaintEvent *e)
{
    QTableWidget::paintEvent(e);
    QPainter painter;
    painter.begin(viewport());
    painter.setPen(QPen(Qt::black, 3));
    painter.drawLine(QLine(visualItemRect(item(2,0)).bottomLeft(),visualItemRect(item(2,8)).bottomRight()));
    painter.drawLine(QLine(visualItemRect(item(5,0)).bottomLeft(),visualItemRect(item(5,8)).bottomRight()));
    painter.drawLine(QLine(visualItemRect(item(0,2)).topRight(),visualItemRect(item(8,2)).bottomRight()));
    painter.drawLine(QLine(visualItemRect(item(0,5)).topRight(),visualItemRect(item(8,5)).bottomRight()));
    painter.end();
}
