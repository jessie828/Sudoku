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

    connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), SLOT(slotValidateInput(QTableWidgetItem*)));

    horizontalHeader()->hide();
    verticalHeader()->hide();
    viewport()->update();
}

#include <stdlib.h>
void SudokuTableWidget::setupBoard(bool newBoard)
{
    clear(newBoard);
    QFont bold;
    bold.setBold(true);
    if (newBoard)
    {
        m_ignoredItems.clear();
        int value = rand() % 9 + 1;
        QTableWidgetItem *defaultItem = new QTableWidgetItem();
        defaultItem->setText(QString("%1").arg(value));
        defaultItem->setBackground(QColor("grey"));
        defaultItem->setFont(bold);
        defaultItem->setTextAlignment(Qt::AlignCenter);
        defaultItem->setFlags(Qt::ItemIsEnabled);
        delete item(0,1);
        setItem(0, 1, defaultItem);
        m_ignoredItems.append(defaultItem);
    }
}


void SudokuTableWidget::slotValidateInput(QTableWidgetItem *item)
{
    if (item != 0)
    {
        bool ok = false;
        int value = item->text().toInt(&ok);
        if (!ok || value > 10 || value < 0)
        {
            item->setText("");
        }
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


void SudokuTableWidget::clear(bool newBoard)
{
    for (int row = 0; row < rowCount(); row++)
    {
        for (int col = 0; col < columnCount(); col++)
        {
            QTableWidgetItem *it = item(row, col);
            if (it != 0)
            {
                if (!m_ignoredItems.contains(it))
                {
                    it->setText("");
                }
            }
        }
    }
}
